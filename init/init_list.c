/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 22:18:53 by angela            #+#    #+#             */
/*   Updated: 2023/09/04 11:26:10 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*C'est une fonction qui initialise la liste chainée
Elles vont recevoir les arguments données en entrée.*/

t_node *node_init()// un node a la fois, utils
{
    t_node *node;
    
    node = malloc(sizeof(t_node)); // cree un node
    if (node == NULL)
        return (NULL);
    node->next = NULL;
	//node->index = NULL;//new
	//node->data = NULL;
    return (node);
}

void init_list(t_pushswap *ps)//madre, cree la liste
   {
        int i = 0;
        t_node *previous_node_a = NULL;
	    //t_node *previous_node_b = NULL;
        t_node *current_node_a;
        //t_node *current_node_b;// modifie en doublant tout


        while (i < ps->number_numbers)
        {
            current_node_a = node_init(); // Crée un nouveau nœud
	        //current_node_b = node_init();

            if (previous_node_a == NULL)// || previous_node_b == NULL)// si on est au 1er node
            {
                ps->head_a = current_node_a; // Enregistre l'adresse du premier nœud
	            //ps->head_b = current_node_b;// ca marche pour le while...?
            }
            else
            {
                previous_node_a->next = current_node_a;// Relie le nœud précédent au nouveau nœud
	            //previous_node_b->next = current_node_b;
            }

            previous_node_a = current_node_a; // Met à jour le nœud précédent, on avance
	        //previous_node_b = current_node_b;
	        i++;
        }
        //ps->tail = previous_node; // Enregistre l'adresse du dernier nœud
        //il faut libérer la str qui a contenu les infos
        if (ps->tab_args_number != NULL)
            ft_free_str(ps->tab_args_number);
    }




//on a une liste partant de 	
void	fill_list(t_pushswap *ps, char **av)//recupere le tableau de char et transforme en int->list
{
	t_node *current_node_a;
	int i;

	i = 0;
	current_node_a = ps->head_a;
    if (ps->multi_arg!= 0)
    {
        i = 1;
        while (current_node_a != NULL && i <= ps->number_numbers)// current_node_a -> next iciiiiiii
	    {
		current_node_a->data = ft_atoi(av[i]);
		current_node_a = current_node_a->next;
		i++;
	    }
    }
	while (current_node_a != NULL && i < ps->number_numbers)// current_node_a -> next iciiiiiii
	{
		current_node_a->data = ft_atoi(ps->tab_args_number[i]);
		current_node_a = current_node_a->next;
		i++;
	}
	
}

void    fill_test(t_node **node, t_pushswap *ps)
{
	t_node *current;
	int i= 0;
	int n = 10;
	current = *node;
	while (current != NULL && i < ps->number_numbers)// current_node_a -> next iciiiiiii
	{
		current->data = n;
		current = current->next;
		i++;
		n++;
	}

}


void	free_structure(t_pushswap *ps)
{
    int i;

    if (ps->tab_args_number == NULL)
        return;
    i = -1;
    while (++i < ps->number_numbers)
    {
        if (ps->tab_args_number[i] != NULL)
        {
            free(ps->tab_args_number[i]);
            ps->tab_args_number[i] = NULL;
        }
    }
    if (ps->tab_args_number != NULL)
        free(ps->tab_args_number);
}

//void    free_nodes(t_node **head)//fin di projet, llibere , avant : t_pushswap *ps
//{
//    t_node *tmp;
//
//    while ((*head)->next != NULL)
//    {
//        if (*head != NULL)
//        {
//            tmp = *head;
//            tmp = (*head)->next;
//            free(*head);
//	        *head = tmp;
//       }
//    }
//    free(tmp);
//    tmp = NULL;
//}
void free_nodes(t_node **head)
{
	t_node *current_node = *head;
	t_node *next_node;

	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	*head = NULL; // Mettre à NULL pour indiquer que la liste est maintenant vide
}
