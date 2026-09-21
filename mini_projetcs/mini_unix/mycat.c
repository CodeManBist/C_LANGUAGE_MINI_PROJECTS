#include <stdio.h>
#include <stdlib.h>

void mycat(const char *filename) {
    FILE *fp;
    fp = fopen(filename, "r");

    if(fp == NULL) {
        fprintf(stderr, "Error opening a file");
        exit(1);
    }

    printf("File opened successfully\n");

    int ch;
    while((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    mycat(argv[1]);
    return 0;
}