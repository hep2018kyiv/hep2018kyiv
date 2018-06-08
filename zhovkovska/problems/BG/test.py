from random import *

f = open("INPUT.txt","w")

colMax = 1e3+7
n = 100000
f.write(str(n)+"\n")

for iAn in range(n):
    f.write( str(randint(1, colMax)))
    f.write(" ")

f.write("\n")

m = 200
f.write(str(m)+"\n")
for iSearch in range(m):
    f.write( str(randint(1, colMax)))
    f.write(" ")

f.close()