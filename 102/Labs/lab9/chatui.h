#ifndef CHATUI_H
#define CHATUI_H

#include <pthread.h>

#define BUFFER_SIZE 60

#define HOST_MSG 1
#define CLIENT_MSG 2

int rows, cols, display_row, last_display_row;
pthread_mutex_t display_mutex;

void print_color(int color, char *text);
void read_str(int row, int col, char *str, int size);
void display_msg(int msg_type, char *msg);

#endif