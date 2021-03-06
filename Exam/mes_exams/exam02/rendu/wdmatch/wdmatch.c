#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_replace(char *dest, char a, char b)
{
	int i=0;
	while (dest[i] != '\0')
	{
		if (dest[i] == a)
			ft_putchar(b);
		else
			ft_putchar(dest[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		if (!(argv[3][1] != '\0' || argv[2][1] != '\0' ))
			ft_replace(argv[1], argv[2][0], argv[3][0]);
	}
	ft_putchar('\n');
	return (0);
}

