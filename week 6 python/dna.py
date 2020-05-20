    for x in (reader):
        l.append(dict(x))

for x in l[0]:
    if(x == 'name'):
        continue
    dnaSeq[x] = 0
    dnalist.append(x)


print(dnalist)

templist = list()
tempd = dict()
with open(sequence,newline = '') as file: 
    reader = file.read()

#remove after
rl = len(reader)
i = len(dnalist[0])



count = 0
temp = list()
tempd = dict()
for x in range(0,rl):
    if dnalist[0] == (reader[x:i+x]):
            count +=1
    reader[x] = 1
