#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_INPUT 32

int main() {
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);

    mvprintw(2, 2, "Welcome to Wacky's funky terminal!");
    printw("\nType help to get a list of commands or enter q to close the terminal");

    char input[MAX_INPUT];
    int row = 5;

    echo();

    while (1) {
        attron(COLOR_PAIR(1));
        mvprintw(row++, 2, "> ");
        attroff(COLOR_PAIR(1));
        move(row - 1, 4);
        getnstr(input, MAX_INPUT);

        if (strcmp(input, "help") == 0) {
            attron(COLOR_PAIR(1));
            mvprintw(row++, 4, "List of commands:");
            mvprintw(row++, 6, "- help");
            mvprintw(row++, 6, "- q");
            mvprintw(row++, 6, "- randomnum");
            mvprintw(row++, 6, "- clear");
            mvprintw(row++, 6, "- time");
            mvprintw(row++, 6, "- run <command>");
            attroff(COLOR_PAIR(1));

        } else if (strcmp(input, "q") == 0) {
            break;

        } else if (strcmp(input, "randomnum") == 0) {
            char max_num[MAX_INPUT];
            mvprintw(row++, 6, "Enter maximum number amount: ");
            move(row - 1, 38);
            getnstr(max_num, MAX_INPUT);

            char *endptr;
            long max = strtol(max_num, &endptr, 10);

            if (*endptr != '\0' || max <= 0) {
                attron(COLOR_PAIR(2));
                mvprintw(row++, 6, "Invalid number, using default (10000)");
                attroff(COLOR_PAIR(2));
                max = 10000;
            }

            int random_number = rand() % max;
            mvprintw(row++, 6, "Random number: %d", random_number);

        } else if (strcmp(input, "clear") == 0) {
            clear();
            row = 5;
            mvprintw(2, 2, "Welcome to Wacky's funky terminal!");
            printw("\nType help to get a list of commands or enter q to close the terminal");

        } else if (strcmp(input, "time") == 0) {
            time_t now = time(NULL);
            mvprintw(row++, 6, "Current time: %s", ctime(&now));

        } else if (strncmp(input, "run ", 4) == 0) {
	     endwin();
    	     system(input + 4);  
	     printf("\nPress Enter to return to WackyTerminal...");
	     getchar();       
	     initscr();
	     noecho();
	     cbreak();
	     keypad(stdscr, TRUE);
	     start_color();
	     init_pair(1, COLOR_GREEN, COLOR_BLACK);
	     init_pair(2, COLOR_RED, COLOR_BLACK);
 	     row += 2;
	     mvprintw(row++, 2, "(Returned from shell command)");
             echo();
        } else if (strcmp(input, "run") == 0) {
            mvprintw(row++, 4, "Usage: run <command>");

        } else {
            attron(COLOR_PAIR(2));
            mvprintw(row++, 4, "Unknown command: %s", input);
            attroff(COLOR_PAIR(2));
        }
    }

    endwin();
    return 0;
}

