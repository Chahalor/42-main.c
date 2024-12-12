/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nduvoid <nduvoid@42mulhouse.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:15:59 by nduvoid           #+#    #+#             */
/*   Updated: 2024/12/06 13:45:07 by nduvoid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

/* ----- Includes -----*/

# include <stdlib.h>
# include <unistd.h>
# include "../libft/get_next_line.h"

/* ----- Defines -----*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

/* ----- Structures -----*/
// ...

/* ----- Typedefs -----*/

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum e_output
{
	OK,
	KO,
	ERROR,
	MALLOC_ERROR,
	NON_NUMERIC_VALUE
}	t_output;

/* ----- Prototypes -----*/

int			*read_stack(int argc, char *argv[]);
char		**ft_realloc(char **ptr, size_t size);
void		test(int *stack_a, int *stack_b, char **commands);
int			is_sorted(int *stack);

void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*get_next_line(int fd);

// Commands

void		sa(int *stack);
void		sb(int *stack);
void		ss(int *stack_a, int *stack_b);
void		pa(int *stack_a, int *stack_b);
void		pb(int *stack_a, int *stack_b);
void		ra(int *stack);
void		rb(int *stack);
void		rr(int *stack_a, int *stack_b);
void		rra(int *stack);
void		rrb(int *stack);
void		rrr(int *stack_a, int *stack_b);

#endif
