#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int cont_spaces;

	cont_spaces = 0;
	if (ac == 2)
	{
		i = 0;
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
				cont_spaces = 1;
			if (!(av[1][i] == ' ' || av[1][i] == '\t'))
			{
				if (cont_spaces)
					write (1, " ", 1);
				write (1, &(av[1][i]), 1);
				cont_spaces = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
