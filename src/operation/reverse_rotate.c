/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:25:21 by angela            #+#    #+#             */
/*   Updated: 2023/09/03 17:43:27 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

//void reverse_rotate(t_node **head) {
//    if (*head == NULL || (*head)->next == NULL) {
//        // La liste est vide ou a seulement un élément, aucune rotation à faire.
//        return;
//    }
//
//    t_node *prev_last = NULL; // Précédent de l'ancien dernier
//    t_node *new_last = *head; // Nouveau dernier élément
//    t_node *temp = *head;
//
//    // Parcours de la liste pour trouver le nouveau dernier et son précédent
//    while (temp->next != NULL) {
//        prev_last = temp;
//        temp = temp->next;
//    }
//
//    // Faire pointer l'avant-dernier vers NULL
//    prev_last->next = NULL;
//
//    // Faire pointer le dernier vers le premier
//    temp->next = *head;
//
//    // Mettre à jour la tête pour le nouveau dernier nœud
//    *head = temp;
//}





void    reverse_rotate(t_node **head,  t_pushswap *ps)
//on pousse vers le bas
// [node1] -> [node2] -> [node3] -> [node4] -> [node5] avant ---> push
// [node5] -> [node1] -> [node2] -> [node3] -> [node4] apres
// le 1er devient 2e
// le 4 eme ddvient dernier ,mettre pointrur a NULL
//node 5 ne pointe plus sur NULL mais sur node 1
{
    t_node *node_1;
    t_node *end;
    t_node *prev_last;
    t_node *temp;

    end = last_node(*head);
    temp = *head;
    while(temp->next != NULL)
    {
        prev_last = temp;
        temp = temp->next;
    }

    node_1 = *head;// stocke le temps que le 1er change et c'est le node en soit.

    *head = end; // move 1, on modifie directement la liste. 5nd ->1er
    (*head)->next = node_1; // move 2
    prev_last->next = NULL;
	ps->nombre_op++;
	ft_printf("reverse_rotate\n");


}

void double_reverse_rotate(t_node **node_a,t_node **node_b,t_pushswap *ps)
{
	reverse_rotate(node_a, ps);
	reverse_rotate(node_b, ps);
}




