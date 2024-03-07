#include <stdio.h>

int main()
{
    FILE* fp;
    int a[] = {0, 1, 2};
    char b[] = "ABC";
    float c[] = {1.1, 1.2, 1.3};

    fp = fopen("a.bin", "wb");

    fwrite(a, sizeof(int), sizeof(a) / sizeof(int), fp);
    
    fwrite(b, sizeof(char), sizeof(b), fp);
    
    fwrite(c, sizeof(float), sizeof(c) / sizeof(float), fp);


    fclose(fp);


    fp = fopen("a.bin", "rb");


    
    fread(a, sizeof(int), sizeof(a) / sizeof(int), fp);
    
    fread(b, sizeof(char), sizeof(b), fp);
    
    fread(c, sizeof(float), sizeof(c) / sizeof(float), fp);

    
    fclose(fp);

    
    printf("%d %d %d\n", a[0], a[1], a[2]);
    printf("%c %c %c\n", b[0], b[1], b[2]);
    printf("%f %f %f\n", c[0], c[1], c[2]);

    return 0;
}
