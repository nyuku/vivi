/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c 	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:13:27 by angela            #+#    #+#             */
/*   Updated: 2023/06/25 16:40:16 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int find_index(t_node *head, int target_index)
{
	int i = 0;
	t_node *current = head;

	while (current != NULL)
	{
		if (current->index == target_index)
			return i;  // Index trouvé, renvoie le nombre de nœuds parcourus
		current = current->next;
		i++;
	}

	return -1; // Index non trouvé dans la liste
}

//
//int choose_small(t_node *node)
//{
//	int i = 1;
//	int data_min = 0;
//	t_node *temp;
//
//	temp = node;
//	data_min = node->data;
//	while (node != NULL)
//	{
//		temp = temp->next;// on a deja stocké le 1er, on passe au suivant
//		if (temp->data < data_min)
//			data_min =
//	}
//}

int	is_already__sorted(t_node **stack)// retourn 1 si c'est dans l'ordere
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp && tmp->data)
	{
		if (tmp->index > tmp->next->index)
		{
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int is_in_upper_half(t_node *head, int index_position)
{
	int size = list_size(head);
	//int index_to_find = size / 2; // Index de la moitié de la liste

	if (index_position == -1)
	{
		// L'index de la moitié n'a pas été trouvé, ce qui est inhabituel.
		// Vous pouvez gérer cette situation comme vous le souhaitez.
		return -1;
	}

	if (index_position < size / 2)
	{
		// Nous sommes dans la moitié supérieure de la liste.
		return 1;
	}
	else
	{
		// Nous sommes dans la moitié inférieure de la liste.
		return 0;
	}
}

int    list_size(t_node *node) // op -push
{
	int i;

	i = 0;
	while(node != NULL)
	{
		i++;
		node = node->next;
	}
	return(i);

}

//fonction pour aller a la fin, retourne le dernier node
t_node	*last_node(t_node *head)
{
	if (!head)//secu si existe pas
		return (NULL);
	while (head->next != NULL) // tant que le pointeur du prochain n'est pas null, donc pas fin
		head = head->next; // passe au prochain
	return (head); //retourne l'adresse du node et pas du pointeur
}

void    print_nodes(t_node **node, char c)// print la liste, t_pushswap *ps
//imprime mm les node(0)
{
    //int i;
    t_node *current_node;

    current_node = *node;
    //i = 0;
	printf("Liste %c\n",c);
	if (current_node == NULL)
		ft_printf("c'est vide\n");
    while (current_node!= NULL)//ici changer , avant current_node ->next
    {

		printf("node(%d)->data = %d\n",current_node->index , current_node->data);
        //printf ("adresse du node %p\n", current_node->next);
        current_node = current_node->next;
        //i++;
    }
}

long	ft_atol(const char *nptr)
{
	long		i;
	long		res;
	char		*str;
	long		signe;

	i = 0;
	str = (char *)nptr;
	res = 0;
	signe = 1;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (('0' <= str[i] && str[i] <= '9') && str[i])
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (signe * res);
}

int p_error()
{
	write(2, "Error\n", 6);
	return (ERROR);
}
