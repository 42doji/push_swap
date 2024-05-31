#include "push_swap.h"

static int	word_count(char const *s1, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (*s1)
	{
		if (*s1 != c)
			flag = 1;
		else if (*s1 == c && flag == 1)
		{
			count++;
			flag = 0;
		}
		s1++;
	}
	if (flag == 1)
		count++;
	return (count);
}

static void	word_malloc(char const *s1, char c, char **result)
{
	int	flag;
	int	start_index;
	int	i;

	flag = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] != c && flag == 0)
		{
			start_index = i;
			flag = 1;
		}
		else if (s1[i] == c && flag == 1)
		{
			*result = (char *)malloc(sizeof(char) * (i - start_index + 1));
			flag = 0;
			result++;
		}
		i++;
	}
	if (flag == 1)
		*result = (char *)malloc(sizeof(char) * (i - start_index + 1));
}

static void	input_word(char const *s1, char c, char **result)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (*s1)
	{
		if (*s1 != c)
		{
			result[i][j++] = *s1;
			flag = 1;
		}
		else if (*s1 == c && flag == 1)
		{
			result[i++][j] = '\0';
			j = 0;
			flag = 0;
		}
		s1++;
	}
	if (flag == 1)
		result[i][j] = '\0';
}

char	**ft_split(char const *s1, char c)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (word_count(s1, c) + 1));
	if (!result)
		return (result);
	word_malloc(s1, c, result);
	input_word(s1, c, result);
	result[word_count(s1, c)] = NULL;
	return (result);
}
