#include <stdio.h>
#include <stdlib.h>

#define MAX_LOTTO_NUM 69
#define NUM_PER_GROUP 7

void generateLottoNumbers(int numGroups) {
    FILE *outfile;
    outfile = fopen("lotto.txt", "w");

    if (outfile == NULL) {
        exit(1);
    }

    srand(1); 

    fprintf(outfile, "========= lotto649 =========\n");


    for (int i = 0; i < numGroups; i++) {
        fprintf(outfile, "[%d]: ", i + 1);
        for (int j = 0; j < NUM_PER_GROUP; j++) {
            fprintf(outfile, "%02d ", rand() % MAX_LOTTO_NUM + 1);
        }
        fprintf(outfile, "\n");
    }

    for (int i = numGroups + 1; i <= 5; i++) {
        fprintf(outfile, "[%d]: __ __ __ __ __ __ __\n", i);
    }
    fprintf(outfile, "========= csie@CGU =========\n");

    fclose(outfile);
}

int main() {
    int N;

    scanf("%d", &N);

    if (N < 1 || N > 5) {
        return 1;
    }

    generateLottoNumbers(N);


    return 0;
}
