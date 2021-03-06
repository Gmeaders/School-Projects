#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <ncurses.h>
#include "chatui.h"
#include "chatnet.h"

#define DGRAM_SIZE 1024

void *init_server(void *flag)
{
	// declare local variables
	int socket_fd, bytes_read;
   	struct sockaddr_in socket_address;
	char recv_buffer[DGRAM_SIZE];
	
	// clear the memory
	memset(&socket_address, '0', sizeof(socket_address));
   	memset(recv_buffer, '0', sizeof(recv_buffer));

	// 1. set up the socket address - use port 5005
	
	socket_address.sin_family = AF_INET;
    	socket_address.sin_addr.s_addr = htonl(INADDR_ANY);
    	socket_address.sin_port = htons(5005);
	
	// 2. create the UDP socket
	socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    
	// 3. bind a name (i.e., address) to the socket
    	if(bind(socket_fd, (struct sockaddr *)&socket_address,  sizeof(socket_address)) < 0)
	{
		return NULL;
	}

    while(1)
    {
		// 4. receive a message
		bytes_read = recvfrom(socket_fd, recv_buffer, DGRAM_SIZE, 0, (struct sockaddr *)NULL, NULL);	
		
		// if data was successfully received, display the message
		if (bytes_read > 0)
		{
			recv_buffer[bytes_read] = '\0';
			display_msg(CLIENT_MSG, recv_buffer);
		}
     }
	 
	 return NULL;
}

int set_client(char *hostname)
{
	// declare local variables
	struct hostent *host_entry;
    struct in_addr **address_list;
	char buffer[100] = "Connection established: ";
    int i;
	
	// copy the hostname into the global variable
	strcpy(client_name, hostname);
    
	// 1. Use the hostname to get the host entry
	//    (return 1 on failure)
	host_entry = gethostbyname(client_name); 

	if(host_entry == NULL)
	{
	return 1;
	}
    
 
	// 2. get the address list from the host entry
    	address_list = (struct in_addr **)host_entry->h_addr_list;
	
	// 3. if the first address pointer in the address list is NULL, return 1
   	if(address_list[0] == NULL)
	{
		return 1;
	}
	
	// store the client address
	client_address = *address_list[0];
	
	// display the client IP address
	strcat(buffer, inet_ntoa(client_address));
	display_msg(CLIENT_MSG, buffer);
	
	return 0;
}

int send_to_client(char *msg)
{
	// declare local variables
	int socket_fd;
    	struct sockaddr_in socket_address; 
	char send_buff[DGRAM_SIZE];   

	// clear the memory
   	memset(send_buff, '0',sizeof(send_buff));
	memset(&socket_address, '0', sizeof(socket_address));
	
	// 1. create the socket
    	socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

	// 2. set up the socket address - use port 5005
	
    	socket_address.sin_family = AF_INET;
	socket_address.sin_addr = client_address;
    	socket_address.sin_port = htons(5005);

	// 3. send the message to the socket address using the socket
	//     (return 1 on failure)
    	if(sendto(socket_fd, msg, DGRAM_SIZE, 0, (struct sockaddr *)&socket_address, sizeof(socket_address)) < 0)
	{
		return 1;
	}

	// 4. close the socket
	close(socket_fd);

    return 0;
}
