str=input("생년월일과 요일을 입력하세요 :")
year=str[:4]
month=str[4:6]
date=str[6:8]
day=str[-1]
week="월화수목금토일"
print("나는 {}년 {}월 {}일 일주일의 {}번째 날에 태어났습니다.".format(year,month,date,week.index(day)+1))
