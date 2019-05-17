#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
void cuentafrecuancia(int *tam, char* file, FILE* fp, char*filename);
int fsize(FILE *fp);
int fsize(FILE *fp){
    int prev=ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int sz=ftell(fp);
    fseek(fp,prev,SEEK_SET); //go back to where we were
    return sz;
}
void cuentafreciuencia(int *tam, char* file,FILE* fp, char*filename){
fp=fopen(filename, "r");
int size=fsize(fp); 
for(int i=0; i< size; i++){
    
}

}