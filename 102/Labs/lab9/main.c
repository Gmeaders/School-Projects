#include <ncurses.h>
#include <pthread.h>
#include <string.h>
#include "chatui.h"
#include "chatnet.h"

int main()
{
	int input_row;
	int thread_flag;
	int msg_body_size, name_len;
	
	// strings
	char name[BUFFER_SIZE];
	char client[BUFFER_SIZE];
	char msg[BUFFER_SIZE];
	char *msg_body;
	char *name_prompt = "Enter your name: ";
	char *client_prompt = "Connect to: ";
	char *msg_prompt = "Send: ";
	
	pthread_mutex_init(&display_mutex, NULL);
	
	// initialize curses mode
	initscr(); 
	cbreak();
	nonl();
	echo();
	getmaxyx(stdscr, rows, cols);
	start_color();
	init_pair(HOST_MSG, COLOR_CYAN, COLOR_BLACK);
	init_pair(CLIENT_MSG, COLOR_MAGENTA, COLOR_BLACK);
	input_row = rows - 2;
	display_row = 0;
	last_display_row = rows - 5;
	
	// draw line
	mvhline(rows - 4, 0, '_', cols);
	
	// get user name
	mvaddstr(input_row, 0, name_prompt);
	scanw("%s", name);
	strcat(name, ": ");
	name_len = strlen(name);
	strcpy(msg, name);
	msg_body = msg + name_len;
	msg_body_size = BUFFER_SIZE - name_len;
	
	// get client name
	mvaddstr(input_row, 0, client_prompt);
	clrtoeol();
	scanw("%s", client);
	if (set_client(client))
	{
		endwin();
		fprintf(stderr, "Unknown client\n");
		return 1;
	}
	
	// start server
	pthread_t net_thread;
	if(pthread_create(&net_thread, NULL, init_server, &thread_flag)) {
		fprintf(stderr, "Error creating server thread\n");
		return 1;
	}
	
	pthread_detach(net_thread);
	
	// prepare to send messages
	move(input_row, 0);
	clrtoeol();
	addstr(msg_prompt);
	refresh();
	
	// disable echo
	noecho();
	
	// chat loop
	while (1)
	{
		// get the message to send
		read_str(input_row, strlen(msg_prompt), msg_body, msg_body_size);
		
		// if the user typed exit, then exit
		if (strncmp(msg_body, "exit", msg_body_size) == 0)
		{
			break;
		}
		// if the user typed nothing, just skip
		else if (msg_body[0] == '\0')
		{
			continue;
		}
		
		// if message sent successfully, then display it
		if (send_to_client(msg) == 0)
		{
			display_msg(HOST_MSG, msg);
		}
	}
	
	endwin(); // End curses mode

	return 0;
}
