/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:41:27 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/09 20:52:13 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	*str;

	if (ac == 2)
	{
		str = av[1];
		i = ft_strlen(str) - 1;
		while (i >= 0)
		{
			if (is_space(str[i]))
			{
				j = i + 1;
				while (str[j] && !is_space(str[j]))
				{
					write(1, &str[j], 1);
					j++;
				}
				write(1, " ", 1);
			}
			i--;
		}
		i = 0;
		while (str[i] && !is_space(str[i]))
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
