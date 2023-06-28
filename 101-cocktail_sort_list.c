#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer tot the head of the doubly linked list
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */

void swap_nodes(listint_t **list, listint_t **node1, listint_t **node2)
{
        listint_t *prev1, *next1, *next2;

        prev1 = (*node1)->prev;
        next1 = (*node1)->next;
        next2 = (*node2)->next;

        if (prev1)
                prev1->next = *node2;
        else
                *list = *node2;
         if (next2)
                 next2->prev = *node1;

         (*node2)->prev = prev1;
         (*node2)->next = *node1;
         (*node1)->prev = *node2;
         (*node1)->next = next2;

         if (next1)
                 next1->prev = *node2;

         (*node1)->next = next2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integersnin ascending
 * order using Cocktail shaker sort algorithm
 * @list: Pointer to the head of the doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	 listint_t *tmp;

	  if (list == NULL || *list == NULL)
		  return;

	  do
	  {
		  swapped = 0;

		  for (tmp = *list; tmp->next != NULL; tmp = tmp->next)
		  {
			  if (tmp->n > tmp->next->n)
			  {
				  swap_nodes(list, &tmp, &(tmp->next));
				  print_list((const listint_t *)*list);
				  swapped = 1;
			  }
		  }

		  if (!swapped)
			  break;

		  swapped = 0;

		  for (; tmp->prev != NULL; tmp = tmp->prev)
		  {
			  if (tmp->n < tmp->prev->n)
			  {
				   swap_nodes(list, &(tmp->prev), &tmp);
				   print_list((const listint_t *)*list);
				   swapped = 1;
			  }
		  }
	  }

	   while (swapped);
}
