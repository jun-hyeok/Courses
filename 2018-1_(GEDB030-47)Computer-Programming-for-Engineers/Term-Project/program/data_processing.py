##data_processing

#승효
from searching import *

#날씨업데이트시각 재연
updtTime=soup.find("span",{"class":"update"}).text

# get_data_dictionary
#날씨정보 한슬

minTemp=soup.find('span',{'class':'min'}).find('span',{'class':'num'}).text
maxTemp=soup.find('span',{'class':'max'}).find('span',{'class':'num'}).text
appTemp=soup.find('span',{'class':'sensible'}).find('span',{'class':'num'}).text

uv_idx=soup.find('span',{'class':'indicator'}).find('span',{'class':'num'})
if uv_idx==None:
        pass
else:
        uv_idx=uv_idx.text
        
rainfall=soup.find('span',{'class':'rainfall'})
if rainfall==None:
        pass
else:
        rainfall=rainfall.find('span',{'class':'num'}).text

indctr=[]        
for i in soup.find('dl',{'class':'indicator'}).find_all("span",{"class":"num"}):
    i=" ".join(i.text.split())
    indctr.append(i)    
fin_dst=indctr[0]
Ulf_dst=indctr[1]
ozn_idx=indctr[2]




#날씨정보 준혁
temps=[]
for t in soup.findAll("span",{"class":"todaytemp"}):
 temps.append(int(t.text))
curTemp=temps[0]
tmrTemp_am=temps[1]
tmrTemp_pm=temps[2]
dftTemp_am=temps[3]
dftTemp_pm=temps[4]

wthrs=[]
for w in soup.findAll("p",{"class":"cast_txt"}):
    wthrs.append(w.text)
curWthr=wthrs[0].split(",")[0]
note=wthrs[0].split(",")[1]
tmrWthr_am=wthrs[1]
tmrWthr_pm=wthrs[2]
dftWthr_am=wthrs[3]
dftWthr_pm=wthrs[4]
