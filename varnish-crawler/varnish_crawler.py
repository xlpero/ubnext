#!/usr/bin/python

#TODO: Crawl also images etc? That would be nice, check out 

from __future__ import print_function
import gevent
import signal
# from gevent import monkey; monkey.patch_socket()
from gevent import monkey; monkey.patch_all()
from gevent.pool import Pool
import requests
import sqlite3
import itertools
from xml.etree import ElementTree
from sets import Set
import pprint
import datetime
import json

pp = pprint.PrettyPrinter(indent=4)

# Kills potential gevent zombies on termination signal
gevent.signal(signal.SIGQUIT, gevent.kill)

conn = sqlite3.connect('storage.db')
c = conn.cursor()
crawl_date = datetime.datetime.now()
c.execute('''CREATE TABLE IF NOT EXISTS request_log(
    crawl_date datetime,
    date datetime,
    url text,
    response_code integer,
    response_varnish_cache text,
    response_varnish_hits integer,
    duration integer,
    request_headers text,
    response_headers text
)''')

# TODO: Create settings/variable table, persistant key/value storage
# def variable_get(key, default_value)
# def variable_set(key, value)
# Implement varnish state page, ubn_varnish?

# TODO: settings file
xml_sitemap_urls = ['http://drupal7.ubnvm.dev/en/sitemap.xml']

# TODO: Brainfuck, check order

def xml_sitemap_locs(url):
    sitemap_locs = []
    urlset_locs = []
    r = requests.get(url)
    sitemap_root = ElementTree.fromstring(r.text)
    ns = {'sm' : 'http://www.sitemaps.org/schemas/sitemap/0.9'}
    if sitemap_root.tag == '{http://www.sitemaps.org/schemas/sitemap/0.9}sitemapindex':
        # TODO: Concurrent requests setting
        request_pool = Pool(5)
        for sitemap in sitemap_root.findall('sm:sitemap', ns):
            sitemap_locs.append(sitemap.find('sm:loc', ns).text)
        print("Downloaded sitemap, calling recursively")
        return itertools.chain.from_iterable(
            request_pool.imap_unordered(xml_sitemap_locs, sitemap_locs)
        )
    elif sitemap_root.tag == '{http://www.sitemaps.org/schemas/sitemap/0.9}urlset':
        for urlset in sitemap_root.findall('sm:url', ns):
            urlset_locs.append(urlset.find('sm:loc', ns).text)
        print("Returning locs")
        return urlset_locs
    else:
        print('invalid format')
        return []


# Temporary fix to prevent crawling url more than once
# since xmlsitemap generates duplicate urls

call_limit = 10
fetched_urls = Set()
def fetch_url(url):
    global call_limit
    call_limit -= 1
    #if call_limit == 0:
        #exit()
    print("Fetching url")
    if not url in fetched_urls:
        r = requests.get(url, cookies={'has_js' : '1'})
        #pp.pprint(r.headers)
        request_headers = json.dumps(dict(r.request.headers), indent=4) if not r.status_code == 200 else ''
        response_headers = json.dumps(dict(r.headers), indent=4) if not r.status_code == 200 else ''

        c.execute("""
            INSERT INTO request_log(
                crawl_date,
                date,
                url,
                response_code,
                response_varnish_cache,
                response_varnish_hits,
                duration,
                request_headers,
                response_headers
            )
            VALUES(?,?,?,?,?,?,?,?,?)
            """,
            (
                crawl_date,
                datetime.datetime.now(),
                r.url, #Original url also? is_redirect?
                r.status_code,
                r.headers['X-Varnish-Cache'],
                r.headers['X-Varnish-Hits'],
                int(round(r.elapsed.total_seconds() * 1000)),
                request_headers,
                response_headers
            )
        )
        fetched_urls.add(url)
        return r.status_code
    else:
        print("Already fetched!")
        print(url)
        return None


# Possible to use same, global, request pool?
# Implications?
request_pool = Pool(5)
urlset_locs = itertools.chain.from_iterable(
    request_pool.imap_unordered(xml_sitemap_locs, xml_sitemap_urls)
)

status_codes = request_pool.imap_unordered(fetch_url, urlset_locs)
print(list(status_codes))

# TODO: Check if performance can be improved by other commit strategy 
conn.commit()
conn.close()
