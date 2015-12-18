#########################################################
# File Name: html_outputer.py
# Author: jhl
# email: 719864045@qq.com
# Create time: Fri 18 Dec 2015 03:36:22 PM CST
#######################################################
#!/usr/bin/python

class HtmlOutputer(object):
    
    def __init__(self):
        self.datas = []
   
    def collect_data(self, data):
        if data is None:
            return
        self.datas.append(data)
    
    def output_html(self):
        fout = open('output.html', 'w')
        fout.write("<html>")
        fout.write("<body>")
        fout.write("<table>")

        for data in self.datas:
            fout.write("<tr>")
            fout.write("<td>%s</td>" % data['url'])
            fout.write("<td>%s</td>" % data['title'].encode('utf-8'))
            fout.write("<td>%s</td>" % data['summary'].encode('utf-8'))

        fout.write("</table>")
        fout.write("</body>")
        fout.write("</html>")
    