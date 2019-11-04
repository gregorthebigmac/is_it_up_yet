#include "command/command.hpp"
#include <ncurses.h>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(int argc, char *argv[]) {
	initscr();
	if (argc < 2) {
		printw("USAGE: checkit [PROGRAM_NAME] [PROGRAM_ARGS]");
		mvprintw(1, 0, "Example:");
		mvprintw(2, 0, "$ checkit ls -la");
		mvprintw(3, 0, "Press any key to exit");
		getch();
		clear();
		endwin();
		return 1;
	}
	
	
	printw("argc = [");
	printw("%i", argc);
	printw("]");
	for (int i = 0; i < argc; i++) {
		mvprintw((i+1), 0, "argc[");
		printw("%i", i);
		printw("] = [");
		printw("%s", argv[i]);
		printw("]");
	}
	getch();
	clear();
	printw("Press any key to exit");
	getch();
	endwin();
	return 0;
}