/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:55:54 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/10 13:19:18 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *s)
{
	int res;
	int i;
	
	res = 0;
	i = 0;
	while (s[i])
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res);
}

int	is_prime(int n)
{
	int	i;

	i = 2;
	if (n <= 1)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void put_nbr(int n)
{
	char	digit;

	if (n >= 10)
		put_nbr(n / 10);
	digit = n % 10 + '0';	 
	write (1, &digit, 1);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	int	sum;
	int num;
	
	num = 0;
	sum = 0;
	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		while (num > 0)
		{
			if (is_prime(num))
				sum += num;
			num--;
		}
		put_nbr(sum);
	}
	else
		put_nbr(0);
	write (1, "\n", 1);
	return (0);
}
