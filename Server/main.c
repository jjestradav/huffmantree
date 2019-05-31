#include "splitfile.c"
#include <pthread.h>
#include <string.h>
int cantmaquinas;
char *filename;
//split -n 3 piolin.jpg
void *splitf(void *p)
{
    char src[100], dest[100];
    char cant[10];
    sprintf(cant, "%d  ", cantmaquinas);
    strcpy(src, cant);
    strcpy(dest, filename);
    strcat(src, dest);
    char dest1[100];
    strcpy(dest1, "split -n ");
    strcat(dest1, src);
    system(dest1);
}
pthread_t splitfile;
int main(int argc, char **argv)
{
    FILE *file;
    filename = argv[1];
    cantmaquinas = atoi(argv[2]);
    pthread_create(&splitfile, NULL, splitf, NULL);
    pthread_join(splitfile, NULL);
    printf("termino la otra vara pero el programa no. AMEN");
    printf("\n");
    
    return 0;
}
