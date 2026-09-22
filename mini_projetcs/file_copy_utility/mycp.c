#include <stdio.h>
#include <stdlib.h>

void copy(const char *filename1, const char *filename2)
{
    FILE *fp1, *fp2;

    fp1 = fopen(filename1, "r");

    if (fp1 == NULL) {
        fprintf(stderr, "Error opening the source file\n");
        exit(EXIT_FAILURE);
    }

    fp2 = fopen(filename2, "w");

    if (fp2 == NULL) {
        fprintf(stderr, "Error opening the destination file\n");
        fclose(fp1);
        exit(EXIT_FAILURE);
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp1)) != 0) {
        fwrite(buffer, 1, bytes_read, fp2);
    }

    fclose(fp1);
    fclose(fp2);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr,
                "Usage: %s <source_file> <destination_file>\n",
                argv[0]);
        return EXIT_FAILURE;
    }

    copy(argv[1], argv[2]);

    return EXIT_SUCCESS;
}