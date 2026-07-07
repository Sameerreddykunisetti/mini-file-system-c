#include<stdio.h>
#include<string.h>

#include "filesystem.h"


File files[MAX_FILES];


void save()
{
    FILE *fp;

    fp=fopen("storage/disk.dat","wb");

    fwrite(files,sizeof(File),MAX_FILES,fp);

    fclose(fp);
}



void load()
{

    FILE *fp;

    fp=fopen("storage/disk.dat","rb");


    if(fp==NULL)
    {
        memset(files,0,sizeof(files));
        return;
    }


    fread(files,sizeof(File),MAX_FILES,fp);

    fclose(fp);

}



void initialize()
{
    load();
}



void createFile(char name[])
{

    for(int i=0;i<MAX_FILES;i++)
    {

        if(files[i].used==0)
        {

            strcpy(files[i].filename,name);

            files[i].used=1;

            files[i].size=0;


            save();


            printf("File created successfully\n");

            return;

        }

    }


    printf("Storage full\n");

}



void writeFile(char name[], char data[])
{

    for(int i=0;i<MAX_FILES;i++)
    {

        if(files[i].used &&
        strcmp(files[i].filename,name)==0)
        {


            strcpy(files[i].data,data);


            files[i].size=strlen(data);


            save();


            printf("Data written\n");

            return;

        }

    }


    printf("File not found\n");

}



void readFile(char name[])
{

    for(int i=0;i<MAX_FILES;i++)
    {


        if(files[i].used &&
        strcmp(files[i].filename,name)==0)
        {


            printf("\nFile Content:\n");

            printf("%s\n",
            files[i].data);


            return;

        }

    }


    printf("File not found\n");

}



void deleteFile(char name[])
{


    for(int i=0;i<MAX_FILES;i++)
    {


        if(files[i].used &&
        strcmp(files[i].filename,name)==0)
        {


            files[i].used=0;


            save();


            printf("File deleted\n");


            return;

        }

    }


    printf("File not found\n");

}




void listFiles()
{

    printf("\nFiles:\n");


    for(int i=0;i<MAX_FILES;i++)
    {


        if(files[i].used)
        {

            printf("%s (%d bytes)\n",
            files[i].filename,
            files[i].size);

        }

    }

}
