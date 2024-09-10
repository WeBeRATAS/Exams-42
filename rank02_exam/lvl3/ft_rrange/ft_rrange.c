/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:37:27 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/09 20:22:24 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int	i;
	int	len_se;
	int	len_es;
	int	*res;
	
	if (start > end)
	{
		len_se = start - end + 1;
		res = malloc(sizeof(int) * len_se);
		i = 0;
		while (i < len_se)
		{
			res[i] = end;
			end--;
			i++;		
		}
	}
	else
	{
		len_es = end - start + 1;
		res = malloc(sizeof(int) * len_es);
		i = 0;
		while (i < len_es)
		{
			res[i] = end;
			end--;
			i++;
		}
	}
	return (res);
}
/*
int	main()
{
	printf("%d\n", *ft_rrange(1, 3));
	return (0);
}*/
