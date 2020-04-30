#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[]){

    int key;
    string s;
    char letterA = 97;
    
    if(argc != 2){
        printf("Error My dude\n");
        return 1;
    }else{
        key = atoi(argv[1]);
    }
    
    s= get_string("Plain Text: ");
    
    for(int i =0, n=strlen(s); i<n;++i){

        if((s[i] > 96 && s[i] < 123) || (s[i] > 40 && s[i] <  91 )){
            
            if(isupper(s[i])){
                    int cypher = (s[i] - 65 + key) % 26;
                    printf("%c",cypher+65);
                    
            } else {

                int cypher = (s[i] - 97 + key) % 26;
                printf("%c",cypher+97);
            }
        }else
            printf("%c",s[i]);
    }
    return 0;
}
