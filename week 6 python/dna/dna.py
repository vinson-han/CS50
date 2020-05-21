import csv	
from sys import argv,exit	
import re	
#1 open csv file and dna sequence, read content into mem	
#2 for each str, compoute the longest run of concescutive in the DNa	
#3compare str count against each row in the csv file	


if len(argv) != 3:	
   print("Usage: python {} data.csv sequence.txt".format(argv[0]))	
   exit(1)	

filename = argv[1]	
sequence = argv[2]	

# filename = "databases/small.csv"	
# sequence = "sequences/1.txt"	
d = dict()	
l = list()	
dnaSeq = list()	
dnatext = list()	
with open(filename,newline = '') as csvfile: 	
    reader = csv.DictReader(csvfile)	
    for x in (reader):
        l.append(x)

for x in l[0]:
    if(x == 'name'):	    
        continue
    dnaSeq.append(x)
    d[x] = 0


file = open(sequence,'r')
temp = (file.readline())
lengthTemp = len(temp)


for n in range(0,len(dnaSeq)):
    count = 0
    maxt = 0
    lengthSeq = len(dnaSeq[n])
    for i in range(0,lengthTemp):
        if(temp[i:i+lengthSeq] == dnaSeq[n]):
            if count == 0:
                count = 1
            elif count > 0 and (temp[i-lengthSeq:i] == temp[i:i+lengthSeq]):
                count+=1
                
            elif count > 0 and (temp[i-lengthSeq:i] != temp[i:i+lengthSeq]):
                count=1
        if count > maxt:
            maxt = count

    d[dnaSeq[n]] = maxt


for y in range(0,len(l)):
    count = 0
    for x in range(0,len(dnaSeq)):
        if (str(d[dnaSeq[x]]) not in (l[y][dnaSeq[x]])):
            break
        else:
            count+=1
    if(count == len(dnaSeq)):
        print(l[y]['name'])
        file.close()
        exit()

print("No Match")



file.close()
