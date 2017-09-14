#ifndef INC_H

# define INC_H

# include "../libft/libft.h"
# include "../libdll/libdll.h"
# include "../libbt/libbt.h"
# include <termios.h>
# include <term.h>
# include <curses.h>

typedef struct          s_glob
{
		struct termios	term;
		struct termios	default_term;
		char			*term_name;
		char			**test;
}						t_glob;

struct s_glob			*glob;

void					init(void);
void					core(t_control *history, int history_index);
char					*search_in_history(t_control *history, char *command);

#endif