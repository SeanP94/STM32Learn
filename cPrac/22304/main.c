#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

static char * const DATA_TEXT = "../srcfiles/data.txt";

/* A function that appends a row to the data file*/
void inputRow(char* row) {
    // printf("hh");
    FILE *fp;
    fp = fopen(DATA_TEXT, "a");
    fputs(row, fp);

    fclose(fp);
}

/* function to print the append file.*/
void printRows() {
    FILE *fp;
    int BUFFER_MAX = 255;
    char buffer[255];

    fp = fopen(DATA_TEXT, "r");
    
    while (fgets(buffer, BUFFER_MAX, fp)) {
        printf("%s", buffer);
    }
    fclose(fp);
}

int main() {
    char *x = "Henry is a guy on a podcast.\n";
    getenv("ASD");
    inputRow(x);
    printRows();
    
    return EXIT_SUCCESS;
}