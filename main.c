#include "libft.h"

void	prnt(char **str, int i, char *t)
{
	if (i == -1)
	{
		while (*str && ++str)
		{
			i++;
			printf("%s%d:%s$\n", t, i, *(str - 1));
		}
		printf("\n");
	}
	else
	{
		while (*str && ++str)
				printf("%s%d:%s$\n", t, i, *(str - 1));
			printf("%s%d:%s$\n\n",t,  i, *str);
	}
}

void	prntp(char ***str)
{
	int	i = 0;

	while (*str)
	{
		prnt(*str, i, "str");
		str++;
		i++;
	}
}

void	wrt (char **str, char i, char *t)
{
	while (*str)
	{
		write(1, t, ft_strlen(t));
		write(1, &i, 1);
		write(1, ":", 1);
		write(1, *str, 32);
		write(1, "\n", 1);
		i++;
		str++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	char	*s[] = {"Hidden  shit-ola bonjour  hallo", "Hidden  shit\0ola bonjour  hallo", "Hidden  shit ola bonjour  hallo", NULL};
	char	*src[] = {&((*s)[13]), &((*(s + 1))[13]), &((*(s + 2))[13]), \
	" ola bonjour  hallo", "ola bonjour  hallo ", " ola bonjour  hallo ", "ola bonjour  hallo", NULL};
	char	**str[] = {ft_split(*src, 32), ft_split(*(src + 1), 32), ft_split(*(src + 2), 32), ft_split(*(src + 3), 32), \
	ft_split(*(src + 4), 32), ft_split(*(src + 5), 32), ft_split(*(src + 6), 32), NULL};

	wrt(s, 48, "og - src");
	prnt(src, -1, "&src");
	prntp(str);
}
