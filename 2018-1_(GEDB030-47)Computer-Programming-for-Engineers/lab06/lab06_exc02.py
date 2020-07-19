a=input("Enter the first integer:")
b=input("Enter the second integer:")
if int(a)%2==0 and int(b)%2==0:
    print("Both a and b are even numbers")
elif int(a)%2!=0 and int(b)%2!=0:
    print("Both a and b are odd numbers")
else:
    print("Either a or b is an even number")
