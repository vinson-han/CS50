#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>




int main(int argc, string argv[])
{
    int key;
    string s;
    //Check if arguement count is inputed correctly or return error statement
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else //Since string is an array of character check invidual character if noit digit return error
    {  
        for (int i = 0, n = strlen(argv[1]); i < n; ++i)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        key = atoi(argv[1]); // convert argv[1] from string to int
    }
    
     
    //get user input
    s = get_string("Plain Text: ");
    //loop through string
    for (int i = 0, n = strlen(s); i < n; ++i) //check if ascia value of a-z ot A-Z
    {  
        if ((s[i] > 96 && s[i] < 123) || (s[i] > 40 && s[i] <  91))
        {
            //if uppercase use proper asic values for Casear Cipher Formula
            if (isupper(s[i]))
            {
                int cypher = (s[i] - 65 + key) % 26;
                printf("%c", cypher + 65);
            }
            else
            {
                int cypher = (s[i] - 97 + key) % 26;
                printf("%c", cypher + 97);
            }
        }// print chatracter if not alphabet
        else
        {
            printf("%c", s[i]);
        }
    }

    printf("\n");
    return 0;
}

   

