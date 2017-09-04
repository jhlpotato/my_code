### python 爬虫实践

本文主要是将文章的![链接](https://mp.weixin.qq.com/s/D5Q4Q6YcQDTOOlfwIytFJw)中的代码copy过来的

当然是自己理解以后的。

python这篇爬虫主要是将douban中某部电影的评论全部爬下来，然后生成词云的过程。

1. 首先使用了urllib库将网页爬下来
2. 然后使用了BeautifulSoup4库将爬下来的网页中解析，获得自己想要的数据
3. 使用正则表达式去掉标点符号
4. 使用结巴中文分词库进行分词
5. 使用stopword将‘的’，‘了’等无意义的字去掉
6. 使用numpy进行词频统计
7. 使用wordcloud和matplotlib库生成词云的照片
