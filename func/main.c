#include "libft.h"

char	*stc(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	main(int a, char **b)
{
	printf("Begin Testing ...\n\n");
	if (a == 1)
	{
		printf("Testing Auto ...\n\n");
		int	c;

		c = -200;
		while (c++ < 200)
		{
			if (ft_isalpha(c) != isalpha(c))
			{
				printf("isalpha\nA: %d\nE: %d\n\n", ft_isalpha(c), isalpha(c));
			}
			if (ft_isdigit(c) != isdigit(c))
			{
				printf("isdigit\nA: %d\nE: %d\n\n", ft_isdigit(c), isdigit(c));
			}
			if (ft_isalnum(c) != isalnum(c))
			{
				printf("isalnum\nA: %d\nE: %d\n\n", ft_isalnum(c), isalnum(c));
			}
			if (ft_isascii(c) != isascii(c))
			{
				printf("isascii\nA: %d\nE: %d\n\n", ft_isascii(c), isascii(c));
			}
			if (ft_isprint(c) != isprint(c))
			{
				printf("isprint\nA: %d\nE: %d\n\n", ft_isprint(c), isprint(c));
			}
		}
	}
	if (a == 2)
	{
		printf("Testing Arg1 ...\n\n");
		if (ft_strlen(b[1]) != strlen(b[1]))
		{
			printf("strlen - %s\nA: %lx\nE: %lx\n\n", b[1], ft_strlen(b[1]), strlen(b[1]));
		}
	}
	if (a == 3)
	{
		printf("Testing Arg2 ...\n\n");
		char *s1;
		char *s2;
		char *s3;
		char *s4;

		s1 = stc(malloc(sizeof(char) * ft_strlen(b[2])), b[2]);
		s2 = stc(malloc(sizeof(char) * ft_strlen(b[2])), b[2]);
		ft_memset(s1, 48, 3);
		memset(s2, 48, 3);
		if(s1 != s2)
		{
			printf("memset\nA: %s\nE: %s\n\n", s1, s2);
		}
		stc(s1, b[2]);
		stc(s2, b[2]);
		ft_bzero(s1, 3);
		bzero(s2, 3);
		if(s1 != s2)
		{
			printf("bzero\nA: %s\nE: %s\n\n", s1, s2);
		}
		stc(s1, b[2]);
		stc(s2, b[2]);
		s3 = malloc(sizeof(char) * 2);
		s4 = malloc(sizeof(char) * 2);
		ft_memcpy(s3, s1, 2);
		memcpy(s4, s2, 2);
		if(s3 != s4)
		{
			printf("memcpy1\nA: %s\nE: %s\n", s3, s4);
		}
		stc(s1, b[2]);
		stc(s2, b[2]);
		ft_memcpy(s1, s1, 2);
		memcpy(s2, s2, 2);
		if(s1 != s2)
		{
			printf("memcpy2\nA: %s\nE: %s\n\n", s1, s2);
		}
		stc(s1, b[2]);
		stc(s2, b[2]);
		s3 = malloc(sizeof(char) * 2);
		s4 = malloc(sizeof(char) * 2);
		ft_memmove(s3, s1, 2);
		memmove(s4, s2, 2);
		if(s3 != s4)
		{
			printf("memmove1\nA: %s\nE: %s\n", s3, s4);
		}
		stc(s1, b[2]);
		stc(s2, b[2]);
		ft_memmove(s1, s1, 2);
		memmove(s2, s2, 2);
		if(s1 != s2)
		{
			printf("memmove2\nA: %s\nE: %s\n\n", s1, s2);
		}
	}
	printf("Testing Completed\n");
}