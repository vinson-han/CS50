import csv
import cs50
from sys import argv,exit


print(argv[0])
if(len(argv) != 2):
    print("Usage Error:{}".format(argv[0]))
    exit(1)

csvf = argv[1]
open("students.db","w").close()
db = cs50.SQL("sqlite:///students.db")



db.execute("Create Table students(first char(20),mid char(20), last char(20), house char(20),birth YEAR)")

array = list()
with open(csvf,'r') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        l = (row["name"].split())
        if (len(l) is 2):
            firstname = l[0]
            middlename = None
            lastname = l[1] 
        elif(len(l) is 3):
            firstname = l[0]
            middlename = l[1]
            lastname = l[2]
        house = row["house"]
        year = int(row["birth"])  
        db.execute("Insert Into students(first,mid,last,house,birth) Values(?,?,?,?,?)",firstname,middlename,lastname,house,year)   
        

