#include "command/command.hpp"
#include <ncurses.h>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(int argc, char *argv[]) {
	vector<vector<char> > c_args;
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
	vector<string> s_args;
	for (int i = 1; i < argc; i++) {
		string temp = argv[i];
		s_args.push_back(temp);
	}
	
	for (int x = 0; x < s_args.size(); x++) {
		int arg_size = s_args[x].size();
		char temp_c_arg [arg_size];
		for (int y = 0; y < s_args[x].size(); y++) {
			temp_c_arg[y] = s_args[x].at(y);
		}
		c_args.push_back(temp_c_arg);
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
