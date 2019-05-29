#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void cuentafrecuancia(int *fecuencia, FILE *fp, char *filename);
void cuentafreciuencia(int *frecuencia, FILE *fp, char *filename)
{
  fp= fopen(filename, "rb");
  int ch;
  while((ch=fgetc(fp))!=EOF){
    ++frecuencia[ch];
  }
   fclose(fp);
}
  // long size = fsize(fp, filename);
  // file = (char *)malloc((size + 1) * sizeof(char));
  // fread(file, size, (size_t)1, fp);
  // fclose(fp);
  // printf("%d", file[0]);


