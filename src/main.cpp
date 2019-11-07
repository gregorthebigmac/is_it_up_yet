#define _XOPEN_SOURCE_EXTENDED
#include "command/command.hpp"
#include <ncurses.h>
#include <unistd.h>

using std::cout;
using std::endl;
using std::vector;
using std::string;

command cmd;
int num_seconds = 0;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"");
	initscr();
	while (1) {
		clear();
		int cursor_y_pos = 0;
		mvprintw(cursor_y_pos , 0, "Running $ nmcli d wifi list: Iteration Counter: %i seconds", num_seconds);
		// this runs the command in a separate (hidden) bash shell, and stores the output in this vector of strings.
		vector<string> terminal_feedback, error_list;
		cmd.exec("nmcli d wifi list", terminal_feedback, error_list);
		// going through each string and adding each char to an array of chars for ncurses output (ncurses doesn't like strings!)
		for (int x = 0; x < terminal_feedback.size(); x++) {
			cursor_y_pos = x + 1;
			char output [terminal_feedback[x].size()];
			for (int y = 0; y < terminal_feedback[x].size(); y++) {
				output[y] = terminal_feedback[x].at(y);
			}
			mvprintw(cursor_y_pos, 0, output); // ncurses printing the result
		}
		cursor_y_pos++;
		// this is to erase erroneous chars that keep appearing here, and I have no idea why.
		mvprintw(cursor_y_pos, 0, "                      ");
		cursor_y_pos++;
		mvprintw(cursor_y_pos, 0, "Press CTRL+C to exit");
		refresh();
		usleep(1000000);
		num_seconds++;
	}
	endwin();
	return 0;
}
