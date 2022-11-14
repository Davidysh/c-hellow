def calculate(*p):
    b = []
    for i in range (len(p)) : 
        average = sum(p)/len(p)
        if(p[i] > sum(p)/len(p)) :
            b.append(p[i])
    return ((sum(p)/len(p)),b)

a = calculate(1,2,3,4,5)
print(a)
