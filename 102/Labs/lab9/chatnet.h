#ifndef CHATNET_H
#define CHATNET_H

#include <arpa/inet.h>

char client_name[60];
struct in_addr client_address;

void *init_server(void *flag);
int set_client(char *hostname);
int send_to_client(char *msg);

#endif