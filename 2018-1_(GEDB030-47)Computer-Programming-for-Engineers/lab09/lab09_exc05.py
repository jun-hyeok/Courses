digits=[290,865,1169,1208,1243]
print("list=",digits)
digits.sort(key=lambda x:str(x)[-1],reverse=True)
print("\nSorted by last digit:\n",digits)
