import random

class Warrior:
    name=None
    hp=None
    power=None
    def __init__(self,name):
        self.name=name
        self.hp=random.randrange(100,201)
        self.power=random.randrange(10,51)
    
    def attack(self,enemy):
        self.enemy=enemy
        res=enemy.hp-self.power
        print("{} attacks! [{}'s hp :{} →{}]".format(self.name,enemy.name,enemy.hp,res))
        enemy.hp=res
        
    def isDead(self):
        if self.hp <= 0:
            print("{}'s Victory!".format(self.enemy.name))
        else:
            return "alive" #not None
                    
    def showInfo(self):
        print("Name: ",self.name)
        print("HP: ",self.hp)
        print("ATK: ",self.power)
        

name=input("Name of 1st warrior: ")
W1=Warrior(name)
W1.showInfo()

name=input("Name of 2nd warrior: ")
W2=Warrior(name)
W2.showInfo()

print("Fight!")

while True:
    W1.attack(W2)
    if W2.isDead()==None:
        break
    W2.attack(W1)
    if W1.isDead()==None:
        break
    
