from sys import argv,exit
#1 open csv file and dna sequence, read content into mem
#2 for each str, compoute the longest run of concescutive in the DNa
#3compare str count against each row in the csv file


#if len(argv) != 3:
#   print("Usage: python {} data.csv sequence.txt".format(argv[0]))
 #   exit(1)

csv = argv[1]
sequence = argv[2]
    

csv = "databases/small.csv"

with open(csv) as f: 
    read_data = f.read()


print(read_data)
