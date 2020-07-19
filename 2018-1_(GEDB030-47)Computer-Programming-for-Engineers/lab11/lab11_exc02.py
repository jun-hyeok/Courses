def countAllLetters(string):
    lis=[]
    dic={}
    for letter in string:
       if letter.isalpha()==True:
           lis.append(letter.lower())
    for letter in lis:
        num=lis.count(letter)
        dic["{}".format(letter)]=num
    return dic

get_string=input("Enter the string:")
print(countAllLetters(get_string))
