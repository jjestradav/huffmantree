#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define MAX 1024
void cuentafrecuancia(int *tam, char *file, FILE *fp, char *filename);
long fsize(FILE *fp, char *name);
long fsize(FILE *fp, char *name)
{
    fp = fopen(name, "rb"); //must be binary read to get bytes

    long size = -1;
    if (fp)
    {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp) + 1;
        fclose(fp);
    }
    return size;
}
void cuentafreciuencia(int *tam, char *file, FILE *fp, char *filename)
{

    long size = fsize(fp, filename);
    file = (char *)malloc((size + 1) * sizeof(char));
    fread(file, size, (size_t)1, fp);
    fclose(fp);
    printf("%d", file[0]);
}