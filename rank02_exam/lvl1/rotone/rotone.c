/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:48:23 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/09 16:59:49 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	*str;

	if (ac == 2)
	{
		i = 0;
		str = av[1];
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'y')
				str[i] += 1;
			else if (str[i] >= 'A' && str[i] <= 'Y')
				str[i] += 1;
			else if (str[i] == 'z' || str[i] == 'Z')
				str[i] -= 25;
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
