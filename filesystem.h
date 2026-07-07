#ifndef FILESYSTEM_H
#define FILESYSTEM_H


#define MAX_FILES 50
#define MAX_FILENAME 30
#define MAX_DATA 500


typedef struct
{
    char filename[MAX_FILENAME];
    char data[MAX_DATA];

    int size;
    int used;

} File;


void initialize();

void createFile(char name[]);

void writeFile(char name[], char data[]);

void readFile(char name[]);

void deleteFile(char name[]);

void listFiles();


#endif
