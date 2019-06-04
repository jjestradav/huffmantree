#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct frecuencia{
int frecuencia;
int valor;
}freq;
void cuentafrecuancia(int *fecuencia, FILE *fp, char *filename, freq *est);
void cuentafreciuencia(int *frecuencia, FILE *fp, char *filename, freq*est)
{
  fp= fopen(filename, "rb");
  int ch;
  int fr;
  while((ch=fgetc(fp))!=EOF){
    fr=++frecuencia[ch];
    est->frecuencia=fr;
    est->valor=ch;
  }
   fclose(fp);
}
  // long size = fsize(fp, filename);
  // file = (char *)malloc((size + 1) * sizeof(char));
  // fread(file, size, (size_t)1, fp);
  // fclose(fp);
  // printf("%d", file[0]);


