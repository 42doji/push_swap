#include "push_swap.h"

int	split_word_count(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

void	split_free(char ***split)
{
	int	i;

	i = 0;
	if (split && *split)
	{
		while ((*split)[i])
		{
			free((*split)[i]);
			(*split)[i] = NULL;
			i++;
		}
		free((*split));
		(*split) = NULL;
	}
}

int	split_check(char const *argv[])
{
	char	**split;
	int		word_count;

	split = ft_split(argv[0], ' ');
	if (!split)
		return (MALLOC_ERR);
	word_count = 0;
	while (split[word_count])
		word_count++;
	split_free(&split);
	if (word_count != 1)
		return (1);
	else
		return (0);
}

void	exception_check2(int word_count, char ***split)
{
	if (argv_check((const char **)*split) == 1)
	{
		split_free(split);
		exit(0);
	}
	if (sorted_check(word_count, (const char **)*split) == 1)
	{
		split_free(split);
		exit(0);
	}
	if (word_count == 3)
	{
		three_input((const char **)*split);
		split_free(split);
		exit(0);
	}
}

void	exception_check3(int argc, char const *argv[])
{
	if (argv_check(argv + 1) == 1)
		exit(0);
	if (sorted_check(argc - 1, argv + 1) == 1)
		exit(0);
	if (argc == 4)
	{
		three_input(argv + 1);
		exit(0);
	}
}
