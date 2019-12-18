int	_atoi(char *str)
{
	int	nb;

	nb = 0;
	if (str == 0)
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str) - '0';
		str++;
	}
	return (nb);
}
