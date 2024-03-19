#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *input_file;
    FILE *output_file;
    char line[100];
    int line_number = 0;


    input_file = fopen("main3.c", "r");
    if (input_file == NULL) {
        perror("Error opening file");
        return 1;
    }


    while (fgets(line, sizeof(line), input_file)) {
        line_number++;
        if (strstr(line, "int main()")) {

            output_file = fopen("main3.txt", "w");
            if (output_file == NULL) {
                perror("Error opening output file");
                return 1;
            }

            fprintf(output_file, "%d\n", line_number);
            fclose(output_file);
            break;
        }
    }

    fclose(input_file);

    return 0;
}
