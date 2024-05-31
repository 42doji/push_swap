#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	result;
	long long	sign;

	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

int	print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}
