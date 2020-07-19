print("Enter Numbers to add to the sum.\nEnter 0 to quit.")
sum=0
while 1:
    print("Current Sum:", sum)
    num=input("Number? ")
    num=int(num)
    sum+=num
    if num==0:
        break
print("Total sum =", sum)
