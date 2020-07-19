apart=[[101,102,103,104],[201,202,203,204],[301,302,303,304],[401,402,403,404]]
arrears=[101,203,301,404]
for i in range(4):
    for j in range(4):
        if  apart[i][j] not in arrears:
            print("Newspaper delivery:{}".format(apart[i][j]))
