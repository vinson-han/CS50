from cs50 import get_string
import re



#Coleman-Liau index is computed as 0.0588 * L - 0.296 * S -15.8
#L average number of letters per 100 words in text
#S average number of sentences per 100 words in text

string = get_string('Text: ')
string = string.split()

total_word = len(string)
total_sentence = 0
total_letter = 0

for x in string:
    if(re.search("[.!?]",x)):
        total_sentence +=1
    for y in x :
        if(y.isalpha()):
            total_letter+=1
            print(total_letter,y)
        

L = (100 * total_letter / total_word)
S = (100 *total_sentence/ total_word)


cli = round(0.0588 * L - 0.296 * S -15.8)


if cli < 1:
    print("Before grade1")
elif cli >=16:
    print("Grade 16+")
else:
    print("Grade {}".format(cli))
