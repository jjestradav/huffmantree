#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
int cantmaquinas;
char *filename;
//split -n 3 piolin.jpg
void *connection_handler(void *client_socket);
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
    char server_message[256] = "Se ha conectado con el servidor";
    //definir el socket del servidor
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    //definir la direccion del server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //se llama a bind
    int bind_ss = bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if (bind_ss < 0)
    {
        printf("algo anda mal\n");
    }

    //poner a escuchar el server por los clientes
    listen(server_socket, cantmaquinas);
    int c = sizeof(struct sockaddr_in);
    puts("esperando conexion\n");
    c = sizeof(struct sockaddr_in);
    pthread_t thread_id;
    int client_socket;
    while ((client_socket = accept(server_socket, (struct sockaddr *)&client_socket, (socklen_t *)&c)))
    {
        puts("conexion aceptada");
        if (pthread_create(&thread_id, NULL, connection_handler, (void *)&client_socket) < 0)
        {
            printf("algo anda mal (pthread)\n");
            return 1;
        }
        puts("handler asignado\n");
    }
    if (client_socket < 0)
    {
        printf("fallo\n");
        return 1;
    }

    return 0;
}
void *connection_handler(void *client_socket)
{
    int socket = *(int *)client_socket;
    int read_size;
    char *message, client_message[2000];

    message = "ALV, si sirvio perro\n";
    write(socket, message, strlen(message));
    while ((read_size = recv(socket, client_message, 2000, 0)) > 0)
    {
        client_message[read_size] = '\0';
        write(socket, client_message, strlen(client_message));

        memset(client_message, 0, 2000);
    }
    if (read_size == 0)
    {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if (read_size == -1)
    {
        perror("recv failed");
    }

    return 0;
}