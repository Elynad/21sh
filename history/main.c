#include "inc.h"

int				main(void)
{
	t_control	*history;

	history = NULL;
	core(history, 0);
	return (0);
}

void			core(t_control *history, int history_index)
{
	char			input[3];
	char			*command;
	t_lst			*tmp;
	int				a;
	int				b;

	if (!(glob = malloc(sizeof(t_glob))))
		exit(EXIT_FAILURE);
	init();
	if (!(command = (char *)malloc(sizeof(char) * 1024)))
		exit(EXIT_FAILURE);
	ft_bzero(command, (sizeof(char) * 1024));
	a = 0;
	b = 0;
	ft_strclr(input);
	ft_putstr("prompt_test $> ");
	while (read(0, &input, 3))
	{
	//	printf("[0] = %d | [1] = %d | [2] = %d\n", input[0], input[1], input[2]);
		if (input[0] >= 32 && input[0] <= 126)
		{
			ft_putchar(input[0]);
			command[a] = input[0];
			a++;
		}
		else if (input[0] == 10)
		{
			ft_putchar('\n');
			history = dll_add_new_elem_end(history, command);
			tmp = history->end;
			ft_putendl(command);
			ft_strclr(input);
			free(command);
			command = NULL;
			core(history, history_index);
		}
		else if (input[0] == 127)
		{
			ft_putchar('\n');
			dll_print_list(history, '\n');
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 65)	// UP ARROW //
		{
			if (history && history->length > 0)
			{
				if (history_index < history->length)
					history_index++;
				tmp = history->end;
				while (b + 1 < history_index)
				{
					tmp = tmp->prev;
					b++;
				}
				if (tmp)
				{
					ft_debug(tmp->name);
				}
				else
				{
					ft_putchar('\n');
				}
				core(history, history_index);
			}
		}
		else if (input[0] == 27 && input[1] == 91 && input[2] == 66)	// DOWN ARROW //
		{
			if (history && history->length > 0 && history_index > 0)
			{
				if (history_index > 0)
					history_index--;
				tmp = history->end;
				while (b < history_index)
				{
					tmp = tmp->prev;
					b++;
				}
				if (tmp)
				{
					ft_debug(tmp->name);
				}
				else
				{
					ft_putchar('\n');
				}
				core(history, history_index);
			}
		}
		else if (input[0] == 18 && input[1] == 0 && input[2] == 0)		// CTRL + R
		{
			ft_putstr("\nbck-i-search: _");
			char		input[3];
			int			c = 0;
			char		*search;
			if (!(search = (char *)malloc(sizeof(char) * 1024)))
				exit(EXIT_FAILURE);
			while (read(0, &input, 3))
			{
				if (input[0] >= 32 && input[0] <= 126)
				{
					search[c] = input[0];
					c++;
					ft_putstr(search_in_history(history, search));
					break;
				}
			}
			core(history, history_index);
		}
		ft_strclr(input);
	}
	ft_putendl(command);
}

char			*search_in_history(t_control *history, char *command)
{
	t_lst		*tmp;

	if (history && history->length > 0)
	{
		tmp = history->end;
		while (tmp != NULL)
		{
			if (ft_strncmp(command, tmp->name, ft_strlen(command)) == 0)
				return (tmp->name);
			tmp = tmp->prev;
		}
	}
	return (NULL);
}

void			init(void)
{
	if ((glob->term_name = getenv("TERM")) == NULL)
		exit(EXIT_FAILURE);
	if (tgetent(NULL, glob->term_name) == -1)
		exit(EXIT_FAILURE);
	if (tcgetattr(0, &glob->term) == -1)
		exit(EXIT_FAILURE);
	if (tcgetattr(0, &glob->default_term) == -1)
		exit(EXIT_FAILURE);
	glob->term.c_lflag &= ~(ICANON);
	glob->term.c_lflag &= ~(ECHO);
	glob->term.c_cc[VMIN] = 1;
	glob->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &glob->term) == -1)
		exit(EXIT_FAILURE);
}