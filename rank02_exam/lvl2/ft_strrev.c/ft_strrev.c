#include <stdio.h>
#include <unistd.h>

char *ft_strrev(char *str)
{
	int i = -1;
	int length = 0;
	char temporary;

	while (str[length])
		length++;
	while (++i < length / 2)
	{
		temporary = str[i];
		str[i] = str[length - 1 - i];
		str[length - 1 - i] = temporary;
	}
	return (str);
}

int main (int ac, char **av)
{
	int	i;
	char	*cadena;

	if (ac == 2)
	{
		i = 0;
		if (av[1])
		{
			cadena = ft_strrev(av[1]);
			printf("Cadena invertida con strrev es %s\n", cadena);
		}
	}
	write (1, "\n", 1);
	return (0);
}
