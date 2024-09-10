# include <unistd.h>

int	ft_atoi(const char *s)
{
	int i;
	int res;
	int sign;

	i = 0;
	res = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num >= 10)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

int	main(int ac, char **av)
{
	int i;
	int num;

	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		i = 1;
		while (i < 10)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(num);
			write(1, " = ", 3);
			ft_putnbr(i * num);
			write(1, "\n", 1);
			i++;
		}
	}
	else 
		write(1, "\n", 1);
	return (0);
}
