int main( int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage Error%s\n",argv[1]);
        return 1;
    }
    FILE * file = fopen(argv[1],"r");
    if(file)
    {   
        int block[] = malloc(512 *sizof(char)+1);
        fread(block,sizeof(char),512,File);


        fclose(file);
    }
    else
    {
        printf("File:%s Does not Exist in Directory\n",argv[1]);
    }

   

    return 0;
}
