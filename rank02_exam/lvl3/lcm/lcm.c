/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:34:19 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/09 18:00:10 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	res;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		res = a;
	else
		res = b;
	while (1)
	{
		if (res % a == 0 && res % b == 0)
			return (res);
		res++;
	}
	return (res);
}
/*
#include <stdio.h>
int	main()
{
	printf("%d\n", lcm(1, 2));
	return (0);
}*/
