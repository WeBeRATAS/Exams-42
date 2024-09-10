/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:13:16 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/09 19:17:05 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
	char	*str;

	if (ac == 2)
	{
		str = av[1];
		i = ft_strlen(str) - 1;
		while (i >= 0)
		{
			write(1, &str[i], 1);
			i--;
		}
	}
	write(1, "\n", 1);
	return (0);
}
