# get_data-dictionary
r_datas=[]
for rawdata in soup.find_all("span",{"class":"num"}):
    rawdata=" ".join(rawdata.text.split())
    r_datas.append(rawdata)
    
datas=[]
for i in range(0,7):
    datas.append(r_datas[i])

    
def category(lis):
    dic={"minTemp":lis[0],"maxTemp":lis[1],"appTemp":lis[2],"uv_idx":lis[3],"fin_dst":lis[4],"Ulf_dst":lis[5],"ozn_idx":lis[6]}
    return(dic)

info=category(datas)
