#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *source_file, *output_file;
    char ch;


    source_file = fopen("main2.c", "r");
    if (source_file == NULL) {

        return 1;
    }


    output_file = fopen("main2.txt", "w");
    if (output_file == NULL) {

        fclose(source_file);
        return 1;
    }

    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, output_file);
    }

    fclose(source_file);
    fclose(output_file);


    return 0;
}
