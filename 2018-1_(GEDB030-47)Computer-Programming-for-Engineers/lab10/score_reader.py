print("{0:<8s}{1:<8s}{2:<8s}".format("Name","Total","Average"))
with open("class.txt",'r') as f:
    lines=f.readlines()
    for line in lines[1:]:
        line=line.split()
        name=line[0]
        tot=sum(map(int,line[1:]))
        avg=tot/3
        print("{}\t{}\t{}".format(name,tot,avg))


            
        
        
            
