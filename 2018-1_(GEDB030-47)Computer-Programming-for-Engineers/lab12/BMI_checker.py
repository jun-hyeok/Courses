class Person:
    def __init__(self,name,gender,height,weight):
        self.name=name
        self.gender=gender
        self.height=height
        self.weight=weight
        
    def bmicheck(self):
        if self.gender=="male":
            res=(self.height-100)*0.9
        else:
            res=(self.height-100)*0.85
        print("BMI is {:.1f}".format(res)) #소숫점 첫째자리까지
    
    def info(self):
        print("Name is {}".format(self.name))
        print("Gender is {}".format(self.gender))
        print("Height is {}".format(self.height))
        print("Weight is {}".format(self.weight))
        
name=input("Name: ")
gender=input("Gender (male/female): ")
while True:
    if gender not in ("male","female"):
        gender=input("Gender (male/female): ")
    else:
        break
height=int(input("Height: "))
weight=int(input("Weight: "))
print()
Per=Person(name,gender,height,weight)
Per.info()
Per.bmicheck()
