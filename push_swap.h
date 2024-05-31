#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MALLOC_ERR 1

typedef struct s_stack
{
	int				data;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pivot
{
	int	pivot1;
	int	pivot2;
	int	pivot3;
}	t_pivot;

int			stack_count(t_stack *stack);
int			pivot_in_stack(int start, int end, t_stack *stack);
t_pivot		*get_pivot(int size);
int			get_last_value(t_stack *stack);
void		three_input(char const *argv[]);

int			biggest_data(t_stack *stack);
int			smallest_data(t_stack *stack);
void		last_change(t_stack **a_stack, int size);

long long	ft_atoi(const char *str);
int			print_error(void);

void		argc_check(int argc);
int			argv_check(char const *argv[]);
void		exception_check1(int argc, char const *argv[]);

int			split_word_count(char **split);
void		split_free(char ***split);
int			split_check(char const *argv[]);
void		exception_check2(int word_count, char ***split);
void		exception_check3(int argc, char const *argv[]);

int			sorted_check(int argc, char const *argv[]);

int			*input_temp(char const *argv[], int size);
void		list_value_change(int **list, int size);

void		clean_list(t_stack **stack);
t_stack		*create_list(int *int_temp, int size);

void		push(t_stack **top1, t_stack **top2);
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);

void		pa(t_stack **a_stack, t_stack **b_stack);
void		pb(t_stack **a_stack, t_stack **b_stack);
void		sa(t_stack **stack);
void		sb(t_stack **stack);

void		ra(t_stack **stack);
void		rb(t_stack **stack);
void		rra(t_stack **stack);
void		rrb(t_stack **stack);

void		three_data_sort(t_stack **a_stack);

void		push_top(t_stack **a_stack, t_stack **b_stack, int cost, int is_a);
void		push_bottom(t_stack **a, t_stack **b, int cost, int is_a);

int			go_to_top_cost(t_stack *stack);
int			go_to_bottom_cost(t_stack *stack);
int			top_or_bottom(t_stack *stack);
int			top_or_bottom2(t_stack *stack);

void		print_ra(void);
void		print_sa(void);
void		print_rra(void);

void		a_to_b(int start, int end, t_stack **a_stack, t_stack **b_stack);

int			biggest_data_input_cost(t_stack *a_stack);
int			smallest_data_input_cost(t_stack *a_stack);
void		b_to_a(int start, int end, t_stack **a_stack, t_stack **b_stack);

char		**ft_split(char const *s1, char c);

#endif
