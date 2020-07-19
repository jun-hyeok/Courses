while 1:
    num=input("Enter a number:")
    num=int(num)
    res=num
    if num==0:
        res=1
    else:
        while num>1:
            num-=1
            res*=num
    print(res)
    
    
    
 
