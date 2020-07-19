num=1
ans="y"
suf="st"
with open("class.txt",'w') as f:
        f.write("{0:<8s}{1:<8s}{2:<8s}{3:<8s}\n".format("Name","English","Math","Science"))
while ans=="y":
    name=input("Input the name of {}{} student:".format(num,suf))
    M_score=input("Input the math score of {}{} student:".format(num,suf))
    E_score=input("Input the English score of {}{} student:".format(num,suf))
    S_score=input("Input the science score of {}{} student:".format(num,suf))
    with open("class.txt",'a') as f:
        f.write("{}\t{}\t{}\t{}\n".format(name,E_score,M_score,S_score)) 
    num+=1
    ans=""
    if str(num)[-1]=='1' and num//10!=1:
        suf="st"
    elif str(num)[-1]=='2'and num//10!=1:
        suf="nd"
    elif str(num)[-1]=='3'and num//10!=1:
        suf="rd"
    else:
        suf="th"
    while ans not in ["y","n"]:
        ans=input("\nKeep moving?(y/n):")
