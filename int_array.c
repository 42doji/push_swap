#include "push_swap.h"

static void	compare_rank(int *list, int **ranks, int size)
{
	int	i;
	int	j;
	int	rank;

	i = 0;
	while (i < size)
	{
		j = 0;
		rank = 0;
		while (j < size)
		{
			if (list[i] > list[j])
				rank++;
			j++;
		}
		(*ranks)[i] = rank;
		i++;
	}
}

void	list_value_change(int **list, int size)
{
	int	*ranks;
	int	i;

	ranks = (int *)malloc(sizeof(int) * size);
	if (!ranks)
	{
		free(*list);
		*list = NULL;
		exit(MALLOC_ERR);
	}
	compare_rank(*list, &ranks, size);
	i = 0;
	while (i < size)
	{
		(*list)[i] = ranks[i];
		i++;
	}
	free(ranks);
	ranks = NULL;
}

int	*input_temp(char const *argv[], int size)
{
	int	*result;
	int	i;

	result = (int *)malloc(sizeof(int) * size);
	if (!result)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		result[i] = ft_atoi(argv[i]);
		i++;
	}
	return (result);
}
