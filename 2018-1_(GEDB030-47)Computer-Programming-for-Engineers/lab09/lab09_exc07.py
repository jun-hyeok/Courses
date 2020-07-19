def cyc_func(num):
    if num%2==0:
       return int(num/2)
    else:
        return 3*num+1

lis=[]
M_len=1
count=1

S_num=int(input("Start number:"))
E_num=int(input("End number:"))

for i in range(S_num,E_num+1):
    num=i
    while num!=1:
      lis.append(num)
      count+=1
      num=cyc_func(num)
    lis.append(1)
    if M_len<=count:
        M_len=count
        N=i
        seq=lis
    lis=[]
    count=1
                
print("Maximum Cycle-length is",M_len)
print("The collatz conjecture number N:",N)
print("sequence:",seq)   
    
