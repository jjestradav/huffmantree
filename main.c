#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    FILE *fp;
    char *buffer;
    long size;
    int val[256] = {0};

    fp = fopen("/home/jose/Documents/huffmantree/ezgif.com-gif-to-mp4.mp4", "rb"); // Open the file in binary mode
    int ch;
    while((ch=fgetc(fp))!=EOF){
        ++val[ch];
    } 
    fclose(fp);
    for(int i=0; i<256; i++){
   printf("%d",val[i]);
   printf("\n");
    }
         // Read in the entire file
     
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