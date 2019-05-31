#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
int file_size(char *filename);
void split(FILE *fp, char *filename, int maquinas);
void split(FILE *fp, char *filename, int maquinas)
{
    FILE *out;
    int max = file_size(filename);
    int tam = (max / maquinas) + 1 ;
    char buffer[tam];
    int result;
    int size;
    int read;
    int written;
    if ((filename != NULL) && (max > 0))
    {
        fp = fopen(filename, "rb");
        if (fp != NULL)
        {
            out = NULL;
            result = 1; 
            while (!feof(fp))
            {
                
                if (out == NULL)
                {
                    sprintf(buffer, "%s.%03d", filename, result);
                    out = fopen(buffer, "wb");
                    if (out == NULL)
                    {
                        result *= -1;
                        break;
                    }

                    size = 0;
                }

                
                read = tam;
                if ((size + read) > max)
                {
                    read = max - size;
                }

                
                read = fread(buffer, 1, read, fp);
                if (read == 0)
                {
                    result *= -1;
                    break;
                }

               
                written = fwrite(buffer, 1, read, out);
                if (written != read)
                {
                    result *= -1;
                    break;
                }

               
                size += written;
                if (size <= max) 
                {
                    fclose(out);
                    out = NULL;
                    result++;
                }
            }

            
            if (out != NULL)
            {
                fclose(out);
            }
            fclose(fp);
        }
    }
}
int file_size(char *filename)
{
    FILE *fp = fopen(filename, "rb"); 

    int size = -1;
    if (fp)
    {
        fseek(fp, 0, SEEK_END);
        size = ftell(fp) + 1;
        fclose(fp);
    }
    return size;
}

// int splitFile(char *fileIn, size_t maxSize)
// {
//     int result = 0;
//     FILE *fIn;
//     FILE *fOut;
//     char buffer[1024 * 16];
//     size_t size;
//     size_t read;
//     size_t written;

//     if ((fileIn != NULL) && (maxSize > 0))
//     {
//         fIn = fopen(fileIn, "rb");
//         if (fIn != NULL)
//         {
//             fOut = NULL;
//             result = 1;   /* we have at least one part */

//             while (!feof(fIn))
//             {
//                 /* initialize (next) output file if no output file opened */
//                 if (fOut == NULL)
//                 {
//                     sprintf(buffer, "%s.%03d", fileIn, result);
//                     fOut = fopen(buffer, "wb");
//                     if (fOut == NULL)
//                     {
//                         result *= -1;
//                         break;
//                     }

//                     size = 0;
//                 }

//                 /* calculate size of data to be read from input file in order to not exceed maxSize */
//                 read = sizeof(buffer);
//                 if ((size + read) > maxSize)
//                 {
//                     read = maxSize - size;
//                 }

//                 /* read data from input file */
//                 read = fread(buffer, 1, read, fIn);
//                 if (read == 0)
//                 {
//                     result *= -1;
//                     break;
//                 }

//                 /* write data to output file */
//                 written = fwrite(buffer, 1, read, fOut);
//                 if (written != read)
//                 {
//                     result *= -1;
//                     break;
//                 }

//                 /* update size counter of current output file */
//                 size += written;
//                 if (size >= maxSize)   /* next split? */
//                 {
//                     fclose(fOut);
//                     fOut = NULL;
//                     result++;
//                 }
//             }

//             /* clean up */
//             if (fOut != NULL)
//             {
//                 fclose(fOut);
//             }
//             fclose(fIn);
//         }
//     }

//     return (result);
// }