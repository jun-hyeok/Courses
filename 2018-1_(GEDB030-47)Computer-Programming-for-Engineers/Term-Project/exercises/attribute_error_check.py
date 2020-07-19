from urllib.request import urlopen
from urllib.request import HTTPError
from bs4 import BeautifulSoup

html=urlopen("http://www.pythonscraping.com/pages/page1.html")
bsObj=BeautifulSoup(html.read(), "html.parser")

try:
    badContent=bsObj.nonExistingTag.anotherTag
except AttributeError as e:
    print("Tag was not found")
else:
    if badContent==None:
        print("Tag was not found")
    else:
        print(badContent)
