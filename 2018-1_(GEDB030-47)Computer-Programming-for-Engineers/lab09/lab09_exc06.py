def rev_str(a):
    return a[::-1]

def check_pal(a):
    if a==rev_str(a):
       return True
    else:
        return False
    
while True:
    a=input("Enter a string:")
    res=check_pal(a)
    if res==True:
        print("Palindrome\n")
        
    elif a=="EXIT":
        print("\nExit")
        break
    else:
        print("Not palindrome\n")
        
