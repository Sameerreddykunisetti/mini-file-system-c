#include<stdio.h>

#include "filesystem.h"



int main()
{


    initialize();


    int choice;

    char name[30];

    char data[500];



    while(1)
    {


        printf("\n====== MINI FILE SYSTEM ======\n");

        printf("1.Create File\n");

        printf("2.Write File\n");

        printf("3.Read File\n");

        printf("4.Delete File\n");

        printf("5.List Files\n");

        printf("6.Exit\n");


        printf("Enter choice:");

        scanf("%d",&choice);


        getchar();



        switch(choice)
        {


            case 1:

            printf("Filename:");

            fgets(name,30,stdin);

            name[strcspn(name,"\n")]=0;


            createFile(name);

            break;



            case 2:

            printf("Filename:");

            fgets(name,30,stdin);

            name[strcspn(name,"\n")]=0;


            printf("Data:");

            fgets(data,500,stdin);


            data[strcspn(data,"\n")]=0;


            writeFile(name,data);

            break;



            case 3:

            printf("Filename:");

            fgets(name,30,stdin);

            name[strcspn(name,"\n")]=0;


            readFile(name);

            break;



            case 4:

            printf("Filename:");

            fgets(name,30,stdin);

            name[strcspn(name,"\n")]=0;


            deleteFile(name);

            break;



            case 5:

            listFiles();

            break;



            case 6:

            return 0;



            default:

            printf("Invalid choice");

        }


    }


}
