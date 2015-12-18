#########################################################
# File Name: spider_main.py
# Author: jhl
# email: 719864045@qq.com
# Create time: Fri 18 Dec 2015 03:11:40 PM CST
#######################################################
#!/usr/bin/python

import test.url_manager, test.html_downloader, test.html_parser, test.html_outputer

class SpiderMain(object):
    def __init__(self):
        self.urls = test.url_manager.UrlManager()
        self.downloader = test.html_downloader.HtmlDownloader()
        self.parser = test.html_parser.HtmlParser()
        self.outputer = test.html_outputer.HtmlOutputer()
        
    def craw(self, root_url):
        count = 1
        self.urls.add_new_url(root_url)
        while self.urls.has_new_url():
            try:
                new_url = self.urls.get_new_url()
                print 'craw %d: %s' % (count, new_url)
                html_cont = self.downloader.download(new_url)
                new_urls, new_data = self.parser.parse(new_url, html_cont)
                self.urls.add_new_urls(new_urls)
                self.outputer.collect_data(new_data)
                
                if count >= 100:
                    break
                count = count + 1
            except:
                print 'craw fail' 
                count = count + 1
        self.outputer.output_html()

if __name__=='__main__':
    root_url = 'http://baike.baidu.com/view/125370.htm'
    obj_spider = SpiderMain()
    obj_spider.craw(root_url)
