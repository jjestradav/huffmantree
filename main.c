#include "ldf.c"
int main(int argc, char **argv){
FILE* file;
char* filename;
filename = argv[1];
int val[256];
char* text;
cuentafreciuencia(val, text, file, filename);
return 0; 
}