/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:22:45 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/09 20:39:47 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	n;
	int	i;

	if (ac == 2)
	{
		n = atoi(av[1]);
		i = 2;
		while (i <= n)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				if (i == n)
					break ;
				printf("*");
				n /= i;
				i = 2;
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
