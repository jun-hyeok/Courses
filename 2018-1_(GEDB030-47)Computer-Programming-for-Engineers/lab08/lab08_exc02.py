print("Make a list named 'sample' and use functions max_func(sample) or min_func(sample)")

def max_func(sample):
    max_val=sample[0]
    for i in sample:
        if max_val<i:
            max_val=i
    return max_val

def min_func(sample):
    min_val=sample[0]
    for i in sample:
        if min_val>i:
            min_val=i
    return min_val
