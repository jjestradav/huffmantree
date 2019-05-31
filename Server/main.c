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
    // printf("%s", src);
    // printf("\n");
    
    char dest1[100];    
    strcpy(dest1, "split -n ");
    strcat(dest1, src);
    // printf("%s", dest1);
    //  printf("\n");
     char *argv[10];
     argv[0]=dest1;
    printf("%s", argv[0]);
    printf("\n");
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
    printf("%d", 5+5+5+5);
    printf("\n");
    // split(file,filename,5);

    return 0;
}

// FILE* file;
// char* filename;
// filename = argv[1];
// int val[256];
// char* text;
// cuentafreciuencia(val, text, file, filename);

// fseek(fp, 0, SEEK_END);                                                     // Jump to the end of the file
// size = ftell(fp);                                                           // Get the current byte offset in the file
// rewind(fp);                                                                 // Jump back to the beginning of the file
// buffer = (char *)malloc((size+1)*sizeof(char)); // Enough memory for file + \0
// fread(&buffer, size, 1, fp);

// FILE *fp;
//     char *buffer;
//     long size;
//     int val[256] = {0};

//     fp = fopen("/home/jose/Documents/Operativos/huffmantree/ezgif.com-gif-to-mp4.mp4", "rb"); // Open the file in binary mode
//     int ch;
//     while((ch=fgetc(fp))!=EOF){
//         ++val[ch];
//     }
//     fclose(fp);
//     for(int i=0; i<256; i++){
//    printf("%d",val[i]);
//    printf("\n");
//     }
//          // Read in the entire file