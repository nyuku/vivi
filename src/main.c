/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:19:08 by angela            #+#    #+#             */
/*   Updated: 2023/10/05 12:42:42 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include<stdio.h>

int	main(int ac, char **av)
{
	t_pushswap ps;

	if(ac <= 1)
		return (0);
	ps.nombre_op = 0;
	ps.multi_arg = 0;
	ps.mono_arg = 0;
	check_all_arg(av, ac, &ps);//mono arg et multi
    if (ps.mono_arg != 0 && ac == 2)
        ps.number_numbers = ps.mono_arg;
    else if (ac > 2)
        ps.number_numbers = ps.multi_arg;

    init_list(&ps);
	// ps.head_b = node_init();
	fill_list(&ps, av);
	if ((check_double(ps.head_a)) == 0)
	{
		ft_printf("error, doublon \n");
		return(1);
	}
	if ((check_double(ps.head_a)) == 0) // DOUBLE
	{
		free_nodes(&(ps.head_a));// diiiiiifff
		//free_nodes(&(ps.head_b));
		free_structure(&ps);

		return (0);

	}
	ps.head_b = node_init();
	fill_list(&ps, av);
	

	//fill_test(&(ps.head_b), &ps);
	index_node(&ps);
	// if (is_already__sorted(&(ps.head_a)) == 1)
	// {
	// 	free_nodes(&(ps.head_a));
	// 	//free_nodes(&(ps.head_b));
	// 	return (0);
	// }


	//print_nodes(&(ps.head_a), 'A');
	//printf("\n\n");
	//print_nodes(&(ps.head_b), 'B');
    //printf("\n-------After-----------\n");
//-------------  Test   ----------------------------
// 	swap(&(ps.head));
//	rotate_up(&(ps.head_a));
//  reverse_rotate(&(ps.head));
//	push(&(ps.head_b),&(ps.head_a));
//	double_rotate(&(ps.head_b),&(ps.head_a));
//	double_swap(&(ps.head_b),&(ps.head_a));
//	double_reverse_rotate(&(ps.head_b),&(ps.head_a));
//	threesome(&ps);
//	sorting_for(&ps);
//	sorting_five(&ps);
	//push_b_chunks(&ps, 20, 1);
//	sorting_push_b(&ps, 20);
	//sorting_in_b(&ps);

	if (ps.number_numbers > 5)
		big_sort(&ps);
	else
		small_sorting(&ps);

	// printf("\n\n");
    // print_nodes(&(ps.head_a),'A' );
	// printf("\n\n");
	// print_nodes(&(ps.head_b), 'B');

	free_nodes(&(ps.head_a));
	free_nodes(&(ps.head_b));// 2x a ici
	free_structure(&ps);
	// printf("\nNombre d'opération: %d\n",ps.nombre_op);
	// printf("🍕 Ciao Ciao Ciao Ciao Ciao Ciao Ciao Ciao 🍕 \n");
	return (0);
	
}
