#include <ncurses.h>
#include <pthread.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "chatui.h"

void print_color(int color, char *text)
{
	attron(color);
	printw("%s", text);
	attroff(color);
}

void read_str(int row, int col, char *str, int size)
{
	// enter critical section
	pthread_mutex_lock(&display_mutex);

	int ch = 0;
	int y, x;
	getyx(stdscr, y, x);
	size += col;
	
	move(row, col);
	clrtoeol();
	refresh();
	
	while (ch != 13 && x < size)
	{
		getyx(stdscr, y, x);
		pthread_mutex_unlock(&display_mutex);
		// leave critical section while we wait for input
		
		ch = getch();
		
		// re-enter critical section
		pthread_mutex_lock(&display_mutex);
		if (ch == 127) // backspace
		{
			if (x > col)
			{
				move(y, x - 1);
				clrtoeol();
			}
			else
			{
				move(y, x);
				clrtoeol();
			}
		}
		else
		{
			str[x - col] = (char)ch;
			addch(ch);
		}
	}
	
	str[x - col] = '\0';
	move(row, col);
	
	// leave critical section
	pthread_mutex_unlock(&display_mutex);
}

void display_msg(int msg_type, char *msg)
{
	// enter critical section
	pthread_mutex_lock(&display_mutex);
	
	char *msg_body;
	
	// store cursor location
	int x, y;
	getyx(stdscr, y, x);

	int i = 1;
	chtype *row_str = (chtype *)malloc(cols * sizeof(chtype));
	
	// if we're out of rows, then shift everything up
	if (display_row > last_display_row)
	{
		while (i <= last_display_row)
		{
			mvinchstr(i, 0, row_str);
			mvaddchstr(i - 1, 0, row_str);
			++i;
		}
		display_row = last_display_row;
	}
	
	free(row_str);
	
	// display the message
	move(display_row, 0);
	clrtoeol();
	
	msg_body = strchr(msg, ':');
	
	if (msg_type == HOST_MSG)
	{
		print_color(COLOR_PAIR(msg_type), "Me");
	}
	else
	{
		msg_body[0] = '\0';
		print_color(COLOR_PAIR(msg_type), msg);
		msg_body[0] = ':';
	}
	printw("%s", msg_body);
	
	// restore cursor location
	move(y, x);
	++display_row;
	refresh();
	
	// leave critical section
	pthread_mutex_unlock(&display_mutex);
}