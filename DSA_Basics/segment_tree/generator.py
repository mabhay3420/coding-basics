#Generates sample input

import random
f = open("input.txt", "w")
t = 10
f.write(str(t)+"\n")
for i in range(t):
    n = 15
    m = 15
    f.write(str(n) + " ")
    f.write(str(m) + "\n")
    for j in range(n):
        p = random.randint(0, 1)
        if p is 0:
            f.write("+")
        else:
            f.write("-")
    f.write("\n")
    for i in range(m):
        l = random.randint(1,n)
        r = random.randint(1,n)
        if(l>r):
            l,r = r,l #swap the values
        f.write(str(l)+" ")
        f.write(str(r)+"\n")
    f.write("\n")
f.close()
