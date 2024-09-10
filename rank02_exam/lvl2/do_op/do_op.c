/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:52:09 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/08/29 15:46:25 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		if (av[2][0] == '+')
			printf ("%d", (atoi(av[1]) + atoi(av[3])));
		if (av[2][0] == '-')
			printf ("%d", (atoi(av[1]) - atoi(av[3])));
		if (av[2][0] == '*')
			printf ("%d", (atoi(av[1]) * atoi(av[3])));
		if (av[2][0] == '/')
			printf ("%d", (atoi(av[1]) / atoi(av[3])));
		if (av[2][0] == '%')
			printf ("%d", (atoi(av[1]) % atoi(av[3])));
	}
	printf("\n");
	return (0);
}
