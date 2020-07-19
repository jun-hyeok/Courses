num=1
ans="y"

with open("class.txt",'w') as f:
        f.write("{0:<8s}{1:<8s}{2:<8s}{3:<8s}\n".format("Name","English","Math","Science"))
while ans=="y":
    name=input("Input the name of {}th student:".format(num))
    M_score=input("Input the math score of {}th student:".format(num))
    E_score=input("Input the English score of {}th student:".format(num))
    S_score=input("Input the science score of {}th student:".format(num))
    with open("class.txt",'a') as f:
        f.write("{}\t{}\t{}\t{}\n".format(name,E_score,M_score,S_score))
     
    num+=1
    ans=""
    while ans not in ["y","n"]:
        ans=input("\nKeep moving?(y/n):")
