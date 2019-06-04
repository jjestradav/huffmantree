#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    //crear un socket basico para el cliente 
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);
    //especificar un direccion para el socket
    struct sockaddr_in server_address;
    server_address.sin_family=AF_INET;
    server_address.sin_port= htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    //ya se puede proceder a connectar 
    int connection_stat = connect(network_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    if(connection_stat==-1){
        printf("ocurrio un error en la conexion \n");
    }
    //recibiendo data del server
    char sever_response[256]; 
    recv(network_socket, &sever_response, sizeof(sever_response), 0);
    // imprimir lo  que el server envio
    printf("el server envio %s\t", sever_response);

    close(network_socket);

    return 0;
}
