stu_info={}
stu_info["name"]=input("Enter a student's name:")
stu_info["homework"]=int(input("Enter the student's homework socre:"))
mid_score=int(input("Enter the student's mid-term score:"))
fin_score=int(input("Enter the student's final score:"))
stu_info["test"]=[mid_score,fin_score]

total=stu_info.get("homework")*0.2+stu_info.get("test")[0]*0.3+stu_info.get("test")[1]*0.5

if total>=90:
    grade="A"
elif total>=80:
    grade="B"
elif total>=70:
    grade="C"
elif total>=60:
    grade="D"
else:
    grade="F"
print("{}'s grade:{}".format(stu_info.get("name"),grade))

print("확인",stu_info)
