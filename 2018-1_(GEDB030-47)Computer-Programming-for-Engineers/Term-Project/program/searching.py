##searching

#승효
from urllib.request import urlopen, quote
from bs4 import BeautifulSoup
print("프로그램을 시작합니다.\n")
loctn=input("날씨를 확인할 지역을 입력하세요. ")
search=quote(loctn+"날씨")
html=urlopen("https://search.naver.com/search.naver?where=nexearch&sm=top_hty&fbm=1&ie=utf8&query={}".format(search))
soup= BeautifulSoup(html,"html.parser")

#날씨기준지역 승효+준혁
while True:
    loctn=soup.find("span",{"class":"btn_select"},{"role":"button"})
    if loctn==None:
        loctn=input("\n정보가 제공되지 않는 지역이거나 중복된 지역명일 수 있습니다.\n자세한 지역명으로 다시 입력하세요:")
        search=quote(loctn+"날씨")
        html=urlopen("https://search.naver.com/search.naver?where=nexearch&sm=top_hty&fbm=1&ie=utf8&query={}".format(search))
        soup= BeautifulSoup(html,"html.parser")
    else:
        loctn=loctn.text
        break

