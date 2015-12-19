#########################################################
# File Name: baidu-download-picture.py
# Author: jhl
# email: 719864045@qq.com
# Create time: Sat 05 Dec 2015 08:55:58 AM EST
#######################################################
#!/usr/bin/python

# usage: python download.py website_url dir_name

import urllib2
import re
import sys
import os

class BDDP():
    def __init__(self, website_url, dir_name):
        # baidu tieba the first url = website_url + '?pn='
        self.website_url = website_url + '?pn='
        self.dir_name = dir_name

    # get the tiezi page num
    def get_page_num(self):
        req = urllib2.urlopen(website_url)
        buf = req.read()
        result = re.search(r'<span class="red">.+?</span>', buf)
        resultlist = re.split(r'<|>', result.group())
        page_num = int(resultlist[2]) # warning it's int type
        return page_num 

    # make directory 
    def make_dir(self):
        try:
            os.mkdir(dir_name)
        except OSError, e:
            print 'directory already exits!'
            sys.exit()

    def download(self):
        pnnum = 1
        filenum = 0
        page_num = self.get_page_num()
        self.make_dir()
        while True:
            if (pnnum > page_num):
                break
            url = self.website_url + str(pnnum)
            print url
            req = urllib2.urlopen(url)
            buf = req.read()
            # get images url list
            urllist = re.findall(r'http://imgsrc.baidu.com/forum/w%3D580/.+?.jpg', buf)
            for url in urllist:
                f = open(dir_name + '/' +  str(filenum)+'.jpg', 'w')
                req = urllib2.urlopen(url)
                buf = req.read()
                f.write(buf)
                f.close()
                filenum = filenum + 1
            pnnum = pnnum + 1

if __name__=='__main__':
    website_url = sys.argv[1]
    dir_name = sys.argv[2]
    bddp = BDDP(website_url, dir_name)
    bddp.download()
    
