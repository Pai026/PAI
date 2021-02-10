# This package will contain the spiders of your Scrapy project
#
# Please refer to the documentation for information on how to create and manage
# your spiders.
import requests
from bs4 import BeautifulSoup
# import scrapy

# from scrapy.spidermiddlewares.httperror import HttpError
# from twisted.internet.error import DNSLookupError
# from twisted.internet.error import TimeoutError, TCPTimedOutError

# class CheckSpider(scrapy.Spider):
#     name = "checkSpider"
#     start_urls = [
#     ]
#     errorUrls=[]

#     def start_requests(self):
#         url = 'https://www.google.com/'
#         reqs = requests.get(url)
#         soup = BeautifulSoup(reqs.text, 'html.parser')
#         urls = []
#         for link in soup.find_all('a'):
#             urls.append(link.get('href'))
#         self.start_urls=urls
#         print("Start URLs\n",self.start_urls,"\n")
#         for u in self.start_urls:
#             yield scrapy.Request(u, callback=self.parse_httpbin,
#                                     errback=self.errback_httpbin,
#                                     dont_filter=True)
#         print("ERROR URLS\n",self.errorUrls,"\n")

#     def parse_httpbin(self, response):
#         self.logger.info('Got successful response from {}'.format(response.url))
#         # do something useful here...

#     def errback_httpbin(self, failure):
#         # log all failures
#         self.logger.error(repr(failure))
#         print("fail\n",failure)
#         quit()
#         self.errorUrls.append(failure.value.response.url)
#         # in case you want to do something special for some errors,
#         # you may need the failure's type:

#         if failure.check(HttpError):
#             # these exceptions come from HttpError spider middleware
#             # you can get the non-200 response
#             response = failure.value.response
#             self.logger.error('HttpError on %s', response.url)

#         elif failure.check(DNSLookupError):
#             # this is the original request
#             request = failure.request
#             self.logger.error('DNSLookupError on %s', request.url)

#         elif failure.check(TimeoutError, TCPTimedOutError):
#             request = failure.request
#             self.logger.error('TimeoutError on %s', request.url)

import scrapy

from scrapy.spidermiddlewares.httperror import HttpError
from twisted.internet.error import DNSLookupError
from twisted.internet.error import TimeoutError, TCPTimedOutError
errorList=[]

class ErrbackSpider(scrapy.Spider):
    name = "errback_example"
    start_urls = [
    ]

    def start_requests(self):
        url = 'https://www.github.com/'
        reqs = requests.get(url)
        soup = BeautifulSoup(reqs.text, 'html.parser')
        urls = []
        for link in soup.find_all('a'):
            urls.append(link.get('href'))
        self.start_urls=urls
        for u in self.start_urls:
            if(u.startswith('http')or(u.startswith('https'))):
                yield scrapy.Request(u, callback=self.parse_httpbin,
                                    errback=self.errback_httpbin,
                                    dont_filter=True)
            

    def parse_httpbin(self, response):
        self.logger.info('Got successful response from {}'.format(response.url))
        # do something useful here...

    def errback_httpbin(self, failure):
        # log all failures
        self.logger.error(repr(failure))
        print("errorList\n",errorList)
        # in case you want to do something special for some errors,
        # you may need the failure's type:

        if failure.check(HttpError):
            # these exceptions come from HttpError spider middleware
            # you can get the non-200 response
            response = failure.value.response
            errorList.append(response.url)
            self.logger.error('HttpError on %s', response.url)

        elif failure.check(DNSLookupError):
            # this is the original request
            request = failure.request
            errorList.append(request.url)
            self.logger.error('DNSLookupError on %s', request.url)

        elif failure.check(TimeoutError, TCPTimedOutError):
            request = failure.request
            errorList.append(request.url)
            self.logger.error('TimeoutError on %s', request.url)
        else:
            errorList.append(failure.request.url)



 
