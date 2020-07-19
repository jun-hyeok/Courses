from data_processing import *
from decision import *
def info_today():
    print("\nWeather:{} ({}℃)\nNote:{}".format(curWthr,curTemp,note))
    print("Detail:일 최저기온{}℃, 일 최고기온{}℃, 체감온도{}℃".format(minTemp,maxTemp,appTemp))
    print("\nLocation:{}/Updated time:{}\n".format(loctn,updtTime))

def life_idx():
    print("\nFine dust: {}({})".format(fin_dst,d_fd(float(fin_dst[:-3]))))
    print("Ultra-fine dust: {}({})".format(Ulf_dst,d_Ufd(float(Ulf_dst[:-3]))))
    print("Ozone index: {}({})".format(ozn_idx,d_ozn(float(ozn_idx[:-3]))))
    if uv_idx!=None:
        print("UV index: {}({})".format(uv_idx,d_uv(float(uv_idx))))
    else:
        pass
    if rainfall!=None:
        print("Rainfall per hour: {}mm".format(rainfall))
    else:
        pass
    print("\nLocation:{}/Updated time:{}\n".format(loctn,updtTime))
    
def forecast():
    print("\nTomorrow(AM/PM): {}/{}".format(tmrWthr_am,tmrWthr_pm))
    print("내일 오전에는 {}℃로 {}고,오후에는 {}℃로 {}을 것으로 예상됩니다.".format(tmrTemp_am,lowORhigh(tmrTemp_am,curTemp),tmrTemp_pm,lowORhigh(tmrTemp_pm,curTemp)))
    print("\nDay after tomorrow(AM/PM): {}/{}".format(dftWthr_am,dftWthr_pm))     
    print("모레 오전에는 {}℃로 {}고,오후에는 {}℃로 {}을 것으로 예상됩니다.".format(dftTemp_am,lowORhigh(dftTemp_am,curTemp),dftTemp_pm,lowORhigh(dftTemp_pm,curTemp)))
    print("\nLocation:{}/Updated time:{}\n".format(loctn,updtTime))
    
while True:
    choose=input("\n알고싶은 정보는?\n1:오늘날씨 2:생활지수 3:기상예보 0:종료(해당 숫자를 입력하세요.):")
    while True:
        if choose not in ['1','2','3','0']:
            choose=input("\n다시입력하세요.\n1:오늘날씨 2:생활지수 3:기상예보 0:종료(해당 숫자를 입력하세요.)")
        else:
            break
    if choose=='1':
        info_today()
        print("-"*60)
    elif choose=='2':
        life_idx()
        print("-"*60)
    elif choose=='3':
        forecast()
        print("-"*60)
    else:
        print("\n프로그램을 종료합니다.")
        break
   

