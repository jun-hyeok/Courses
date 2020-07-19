h=int(input("Type your height:"))

w=int(input("Type your weight:"))

BMI=w/((h/100)**2)

print("\nYour height is",h,"\nYour weight is",w,"\nYour BMI is",BMI)

a,b=input("\nType your Midterm scores (Math & Eng):").split(" ")
c,d=input("Type your Final scores (Math & Eng):").split(" ")

a=int(a)
b=int(b)
c=int(c)
d=int(d)

sum_m=float(a+c)
sum_e=float(b+d)
avg_m=sum_m/2
avg_e=sum_e/2

print("\nSubject\t Sum\t Avg")
print("Math\t",sum_m,"\t",avg_m)
print("English\t",sum_e,"\t",avg_e)
