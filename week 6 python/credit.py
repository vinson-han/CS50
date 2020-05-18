import re
from cs50 import get_string

while (True):
    number = get_string('Number:')
    number = number[::-1]
    if(number.isdigit()):
        break

total = 0
count = 0
for x in number:
    count+=1
    num = int(x)
    if count % 2 == 0:
        if num*2 > 9:
            total+=(int(num*2/10))
            total+=(num*2%10)
        else:
            total+=(num*2)
    else:
        total+= num



if(re.search("^5[1-5]",x)):
    print("yes")

if(total%10 == 0):
    if(re.search("73$|43$",number) and len(number) == 15):
        print("American Express")
    elif(re.search("[1-5][5]$",number) and len(number) == 16):
        print("Master Card")
    elif(re.search("4$",number) and (len(number) == 13 or len(number) == 16)):
        print("Visa")
else:
    print("Invalid")
    
