#include <stdio.h>
#include <stdint.h>


int main( int argc, char *argv[])
{
    FILE *file = fopen(argv[1],"r");
    char block[512];
    if (argc != 2)
    {
        printf("Usage Error%s\n",argv[1]);
        return 1;
    }
   
    if(file)
    {   
        while(fread(block,sizeof(char),512,file) != EOF)
        {
            for(int i = 0; i < 4; i++)
            {
                printf("%iblock[%i]%x\n",i,i,block[i]);
            }
        }
        
    }
    else
    {
        printf("File:%s Does not Exist in Directory\n",argv[1]);
    }

   

    return 0;
}
