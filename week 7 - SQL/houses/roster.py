import csv
from sys import argv,exit
import cs50

if(len(argv) != 2):
    print("Usage Error:{}".format(argv[0]))
    exit(1)



db = cs50.SQL("sqlite:///students.db")
house = argv[1]
test = db.execute("Select * from students where house = ?",house)

for x in test:
    firstname = (x["first"])
    lastname = x["last"]
    year = x["birth"]
    if(x["mid"] is None):
        middlename = ''
    else:
        middlename = x["mid"]
    print("{} {} {}, born {}".format(firstname,middlename,lastname,year))
