# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>

char	*ft_strdup(char *src)
{
	int i;
	char *new;

	i = 0;
	while (src[i])
		i++;
	new = malloc(sizeof(*new) * (i +1));
	if (new)
	{
		i = 0;
		while (src[i])
		{
			new[i] = src[i];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
/*
int main(int ac, char **av)
{
	if (ac == 2)
	{
		printf(" La nueva cadena es: %s \n", ft_strdup(av[1]));
	}
	return (0);
}*/
