# 学习一下Scrapy

## 概述

> Scrapy is a fast high-level [web crawling](https://en.wikipedia.org/wiki/Web_crawler) and [web scraping](https://en.wikipedia.org/wiki/Web_scraping) framework, used to crawl websites and extract structured data from their pages. It can be used for a wide range of purposes, from data mining to monitoring and automated testing.

> Scrapy，Python开发的一个快速、高层次的屏幕抓取和web抓取框架，用于抓取web站点并从页面中提取结构化的数据。Scrapy用途广泛，可以用于数据挖掘、监测和自动化测试.
>
> 其最初是为了页面抓取 (更确切来说, 网络抓取 )所设计的， 后台也应用在获取API所返回的数据(例如 Amazon Associates Web Services ) 或者通用的网络爬虫.
>
> Scrapy吸引人的地方在于它是一个框架，任何人都可以根据需求方便的修改。它也提供了多种类型爬虫的基类，如BaseSpider、sitemap爬虫等，最新版本又提供了web2.0爬虫的支持.

## 简单测试一下

Scrapy是一个应用程序框架，用于抓取网站和提取结构化数据，可用于各种有用的应用程序，如数据挖掘，信息处理或历史存档。

```python
import scrapy

class QuotesSpider(scrapy.Spider):
    name = 'quotes'
    start_urls = [
        'http://quotes.toscrape.com/tag/humor/',
    ]

    def parse(self, response):
        for quote in response.css('div.quote'):
            yield {
                'author': quote.xpath('span/small/text()').get(),
                'text': quote.css('span.text::text').get(),
            }

        next_page = response.css('li.next a::attr("href")').get()
        if next_page is not None:
            yield response.follow(next_page, self.parse)
```

运行命令

```powershell
scrapy runspider test.py -o quotes.jl
```

该脚本从网站中抓取名言然后分页，将其放在一个文本文件中，命名为quotes.jl
结果如图
![image-20220103010335021](C:\Users\LanT34m\AppData\Roaming\Typora\typora-user-images\image-20220103010335021.png)

### 发生了什么

当运行命令时，Scrapy在其中寻找一个蜘蛛定义，并通过它的爬虫引擎运行。

首先向定义的URL发送请求，并调用默认回调方法，将响应对象作为参数传递。在回调中，使用CSS选择器遍历元素，生成包含提取的引用文本和Python字典，查找指向下一页的链接。

> start_urls、parse

运行时命令行截图

![image-20220103011147510](C:\Users\LanT34m\AppData\Roaming\Typora\typora-user-images\image-20220103011147510.png)

## 整体架构图

![img](https://img-blog.csdnimg.cn/20200321114058862.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2NrNzg0MTAxNzc3,size_16,color_FFFFFF,t_70)

在调用下载器时，往往有一个下载器中间件，使下载速度提速。

官网架构图

![img](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9zczIuYmFpZHUuY29tLzZPTllzamlwMFFJWjh0eWhucS9pdC91PTE3NzI5Mjc2NjMsMjU1MjMyNjEyOCZmbT0xNzMmYXBwPTQ5JmY9SlBFRw?x-oss-process=image/format,png)

## 生成项目

```
scrapy startproject 项目名
cd 项目名
scrapy genspider 爬虫名 域名
scrapy crawl 爬虫名
```

 创建后目录为：![image-20220103013609897](C:\Users\LanT34m\AppData\Roaming\Typora\typora-user-images\image-20220103013609897.png)

爬虫名.py是自动生成的。

setting.py是项目的配置文件

> BOT_NAME：项目名
>
> USER_AGENT：默认是注释的，这个东西非常重要，如果不写很容易被判断为电脑，简单点写一个Mozilla/5.0即可
>
> ROBOTSTXT_OBEY：是否遵循机器人协议，默认是true，需要改为false，否则很多东西爬不了
>
>  CONCURRENT_REQUESTS：最大并发数，很好理解，就是同时允许开启多少个爬虫线程
>
> DOWNLOAD_DELAY：下载延迟时间，单位是秒，控制爬虫爬取的频率，根据你的项目调整，不要太快也不要太慢，默认是3秒，即爬一个停3秒，设置为1秒性价比较高，如果要爬取的文件较多，写零点几秒也行
>
> COOKIES_ENABLED：是否保存COOKIES，默认关闭，开机可以记录爬取过程中的COKIE，非常好用的一个参数
>
> DEFAULT_REQUEST_HEADERS：默认请求头，上面写了一个USER_AGENT，其实这个东西就是放在请求头里面的，这个东西可以根据你爬取的内容做相应设置。
>
> ITEM_PIPELINES：项目管道，300为优先级，越低越爬取的优先度越高

一般修改三个内容：

1. 不遵循机器人协议
2. 下载间隙
3. 请求头增加一个User-Agent
4. 打开一个管道



# 注意

## Scrapy爬虫解决延迟加载无信息问题

[Scrapy + Selenium 爬取简书网 - 简书 (jianshu.com)](https://www.jianshu.com/p/1875bb03001c)

## Scrapy爬虫解决无窗口爬虫

[(24条消息) 【Python+selenium】浏览器后台运行 隐藏窗口执行_丿灬安之若死-CSDN博客_selenium窗口隐藏](https://blog.csdn.net/mp624183768/article/details/86755892)

