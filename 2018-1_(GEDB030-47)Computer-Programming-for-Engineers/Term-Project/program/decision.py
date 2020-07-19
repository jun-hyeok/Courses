#재연
def d_fd(a):
    if a<=30:
        b="좋음"
    elif a>=30 and a<=80:
        b="보통"
    elif a>=80 and a<=150:
        b="나쁨"
    elif a>=150:
        b="매우나쁨"
    else:
        b="-"
    return b
    

def d_Ufd(c):
    if c<=15:
        d="좋음"
    elif c>=15 and c<=35:
        d="보통"
    elif c>=35 and c<=75:
        d="나쁨"
    elif c>=75:
        d="매우나쁨"
    else:
        d="-"
    return d
    


def d_uv(e):
    if e<=2:
        f="낮음"
    elif e>2 and e<=5:
        f="보통"
    elif e>5 and e<=7:
        f="높음"
    elif e>7 and e<=10:
        f="매우높음"
    elif e>10:
        f="위험"
    else:
        f="-"
    return f
    

def d_ozn(j):
    if j<=0.030:
        k="좋음"
    elif j>0.030 and j<=0.090:
        k="보통"
    elif j>0.090 and j<=0.150:
        k="나쁨"
    elif j>0.150:
        k="매우나쁨"
    else:
        k="-"
    return k

#승효
def lowORhigh(a,b):
    if int(a)-int(b)>0:
        res="높"
        return "현재보다 {}℃{}". format(abs(int(a)-int(b)),res)
    elif int(a)-int(b)<0:
        res="낮"
        return "현재보다 {}℃{}". format(abs(int(a)-int(b)),res)
    else:
        return "현재와 같"
    

