/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 17:27:29 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/09/09 17:30:35 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (reject[i])
	{
		while (s[j])
		{
			if (s[j] == reject[i])
			{
				return (j);
			}
			j++;
		}
		i++;
	}
	return (j);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	char	str[] = "hala mundo";
	char	r[] = "mudo";
	printf("%zu\n", ft_strcspn(str, r));
	printf("%zu\n", strcspn(str, r));
	return (0);
}*/
