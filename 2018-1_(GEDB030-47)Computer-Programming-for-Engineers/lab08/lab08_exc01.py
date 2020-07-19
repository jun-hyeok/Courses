def check(num):
    if num>100:
        return 'over'
    else:
        return num
list=[]
while True:
    num=int(input("Enter a number:"))
    if num<0:
        print("\nExit")
        break
    else:
        list.append(check(num))
        print(list,"\n")
        
            
