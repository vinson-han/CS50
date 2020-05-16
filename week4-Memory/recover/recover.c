#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> 

const int BLOCK_SIZE = 512;

int main( int argc, char *argv[])
{
    FILE *file = fopen(argv[1],"r");
    if (argc != 2)
    {
        printf("Usage Error%s\n",argv[1]);
        return 1;
    }
   
    if(file)
    {   

        char *filename = malloc(sizeof(char));
        unsigned char *buffer = malloc(sizeof(char)* 512);
        FILE * img = NULL;
        int count = 0;

//        printf("%lu", sizeof(buffer)/sizeof(buffer[0]));
        while(1)
        {
            int x = fread(buffer,BLOCK_SIZE,1,file);
            if(x == 0)
            {
                break;
            }
            // /printf("%x",buffer[BLOCK_SIZE-1]);
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xF0) == 0xe0)
            {
                if(count > 1)
                {
                    fclose(img);
                } 
                sprintf(filename,"%03i.jpg",count);
                img = fopen(filename,"w");
                count++;


                if(img == NULL)
                {
                    printf("Error\n");
                    return 2;
                }
                
            }
            if(img != NULL)
                fwrite(buffer,BLOCK_SIZE,1,img);
               // printf("%i",count++);

            if(x == 0)
                break;
            
        }
        fclose(img);
        free(filename);
        free(buffer); 
 
    }
    else
    {
        printf("File:%s Does not Exist in Directory\n",argv[1]);
    }

    fclose(file);
    return 0;
}
