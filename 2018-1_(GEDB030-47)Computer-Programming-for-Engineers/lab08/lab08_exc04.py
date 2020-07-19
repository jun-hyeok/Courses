print("Use a function: count_func('put a string to be counted here','put a unit of the string here')")
      
def count_func(a,b):
    count_val=0
    for i in range(len(a)):
        if a[i:i+len(b)]==b:
            count_val+=1
            a=a.replace(b," "*len(b),1)
    return count_val
