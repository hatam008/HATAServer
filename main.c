//CopyRight : HATAM:)           Now You Can Say This is a CHEAT B****!
//Date Uploaded to QUERA : 2019/ 12/ 29
//Got Help From : StackOverFlow.com / GeeksForGeeks.com
#include <stdio.h>
#include <winsock2.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "HATA_JSON.h"

#define PORT 12345
#define SA struct sockaddr
void RGCH();
void RGMM();
int server_socket, client_socket;
struct sockaddr_in server, client;

int main()
{
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    int oprate;
    wVersionRequested = MAKEWORD(2, 2);
    char endprocess = 0;
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        // Tell the user that we could not find a usable Winsock DLL.
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

    // Create and verify socket------------------------------------
    server_socket = socket(AF_INET, SOCK_STREAM, 6);
	if (server_socket == INVALID_SOCKET)
        wprintf("socket function failed with error = %d\n", WSAGetLastError() );
    else
        printf("Socket successfully created..\n");
    // Assign IP and port-------------------------------------------
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);

    // Bind newly created socket to given IP and verify-------------
    if ((bind(server_socket, (SA *)&server, sizeof(server))) != 0)
    {
        printf("Socket binding failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully bound..\n");
    // Now server is ready to listen and verify
    if ((listen(server_socket, 5)) != 0)
    {
        printf("Listen failed...\n");
        exit(0);
    }
    else{
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        printf("Server Started [%4d/%02d/%02d][%02d:%02d:%02d]\n",tm.tm_year+1900,tm.tm_mon +1,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec);
    }
    //Registering Channels------------------------------------------
    RGCH();
    //Registering Members-------------------------------------------
    RGMM();
    printf("Listening Now...\n\n");
    while(1){
        // Accept the data packet from client and verify
        int len = sizeof(client);
        client_socket = accept(server_socket, (SA *)&client, &len);
        if (client_socket < 0)
        {
            printf("Server accceptance failed...\n");
        }
        readoprate();
    }
}
