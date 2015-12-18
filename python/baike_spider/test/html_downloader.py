#########################################################
# File Name: html_downloader.py
# Author: jhl
# email: 719864045@qq.com
# Create time: Fri 18 Dec 2015 03:36:05 PM CST
#######################################################
#!/usr/bin/python

import urllib2
class HtmlDownloader(object):
    
    def download(self, url):
        if url is None:
            return None

        response = urllib2.urlopen(url)

        if response.getcode() != 200:
            return None

        return response.read()
