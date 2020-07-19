def star(a):
    if a%2==0:
        for i in range(1,a//2+1):
            print("*"*i)
        for j in range(a//2,0,-1):
            print("*"*j)
    else:
        for i in range(1,a//2+1):
            print("*"*i)
        for j in range(a//2+1,0,-1):
            print("*"*j)
      
num=int(input("Enter a number:"))
star(num)
