n1=input("Input first number:")
n2=input("Input second number:")
n3=input("Input last number:")
n1=int(n1)
n2=int(n2)
n3=int(n3)
if n1>=n2 and n1>=n3:
    nl=n1
elif n2>=n3:
    nl=n2
else:
    nl=n3

if n1<=n2 and n1<=n3:
    ns=n1
elif n2<=n3:
    ns=n2
else:
    ns=n3

print(nl,ns)


