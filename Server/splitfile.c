#include <stdlib.h>
#include <unistd.h>
#include <math.h>
int file_size(char *filename);
void split(FILE *fp, char *filename, int maquinas);
void split(FILE *fp, char *filename, int maquinas)
{
    FILE *out;
    int resultado=0;
    int maxsize = file_size(filename);
    int size = sqrt((double)maxsize);
    if (filename != NULL && maxsize > 0)
    {
        fp = fopen(filename, "rb");
        if(fp!=NULL){
            out=NULL;
            while(!foef(fp)){
                if(out==NULL){

                }
            }
        }
    }
}
int file_size(char *filename)
{
    FILE *fp = fopen(filename, "rb"); //must be binary read to get bytes

    int size = -1;
    if (fp)
    {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp) + 1;
        fclose(fp);
    }
    return size;
}