import csv
from sys import argv,exit
import re
#1 open csv file and dna sequence, read content into mem
#2 for each str, compoute the longest run of concescutive in the DNa
#3compare str count against each row in the csv file


#if len(argv) != 3:
#   print("Usage: python {} data.csv sequence.txt".format(argv[0]))
 #   exit(1)

#filename = argv[1]
#sequence = argv[2]

filename = "databases/small.csv"
sequence = "sequences/1.txt"
d = dict()
l = list()
dnaSeq = list()
dnatext = list()
with open(filename,newline = '') as csvfile: 
    reader = csv.DictReader(csvfile)
    for x in (reader):
        l.append(dict(x))

for x in l[0]:
    if(x == 'name'):
        continue
    dnaSeq.append(x)

print(dnaSeq)


with open(sequence,newline = '') as file: 
    reader = file.read()
