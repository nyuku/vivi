/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:21:27 by angela            #+#    #+#             */
/*   Updated: 2023/09/03 17:43:56 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
//fonction pour ajouter un index à chaque node, on s'occupe que la liste A en debut de

void    find_biggest(t_pushswap *ps)
{
	t_node  *temp;

	ps->biggest = ps->head_a;
	// on stoke la valeur du 1er node comme le plus grand pour commencé
	//on va update a chaque tour
	//
	temp = ps->head_a;
	//pour naviguer
	while (temp != NULL)
	{
		if (temp->data > ps->biggest->data)// on compare le contenu des nodes
			ps->biggest = temp;// on sauvegarde
		temp = temp->next;
	}
}

void    index_node(t_pushswap *ps)
{
	t_node  *temp_big;
	t_node  *temp;// pour naviguer
	int i;

	i = ps->number_numbers;
	find_biggest(ps); // on lance pour avoir le plus grand
	ps->biggest->index = i;
	i--;
	while (i >= 1)
	{
		temp = ps->head_a; // on prend le 1er node pour naviguer
		temp_big = NULL;   // Initialise temp_big à NULL pour chaque itération
		while (temp != NULL)
		{
			if (temp->index < 1 && (temp_big == NULL || temp->data > temp_big->data))// pas indexé et au debut et plus grand
				temp_big = temp;
			temp = temp->next;
		}
		temp_big->index = i;// on a trouvé le plus grand, on lui donne un index
		i--;
	}
}

