import requests
from bs4 import BeautifulSoup
 
url = 'https://www.geeksforgeeks.org/'
reqs = requests.get(url)
soup = BeautifulSoup(reqs.text, 'html.parser')
 
urls = []
errorList=[]
for link in soup.find_all('a'):
    urls.append(link.get('href'))
for i in urls:
    try:
        response = requests.get(i)
    except:
        errorList.append(i)

print("final list",errorList)