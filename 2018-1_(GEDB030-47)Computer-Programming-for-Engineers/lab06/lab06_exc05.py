while 1:
    num=input("Enter a integer:")
    i=2
    num=int(num)
    if num==1:
        print("no")
    else:
        while num%i!=0:
            i+=1
        if num==i:
            print("yes")
        else:
            print("no")
