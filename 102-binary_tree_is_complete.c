#include "binary_trees.h"
#include <stdlib.h>

/**
 * new_node - Creates a new node in a linked list
 * @node: Pointer to the node to be created
 * Return: The new node created
 */
link_t *new_node(binary_tree_t *node)
{
	link_t *new = malloc(sizeof(link_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;
	return (new);
}

/**
 * free_q - Frees the nodes in the linked list
 * @head: Pointer to the head node of the linked list
 */
void free_q(link_t *head)
{
	link_t *temp_node;

	while (head)
	{
		temp_node = head->next;
		free(head);
		head = temp_node;
	}
}

/**
 * _push - Pushes a node into the stack
 * @node: Pointer to the node to be pushed
 * @head: Pointer to the head node of the stack
 * @tail: Pointer to the tail node of the stack
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
	link_t *new = new_node(node);
	if (new == NULL)
	{
		free_q(head);
		exit(1);
	}

	(*tail)->next = new;
	*tail = new;
}

/**
 * _pop - Pops a node from the stack
 * @head: Pointer to the head node of the stack
 */
void _pop(link_t **head)
{
	link_t *temp_node = (*head)->next;
	free(*head);
	*head = temp_node;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *head, *tail;
	int flag = 0;

	if (!tree)
		return (0);

	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->left, head, &tail);
		}
		else
			flag = 1;

		if (head->node->right)
		{
			if (flag == 1)
			{
				free_q(head);
				return (0);
			}
			_push(head->node->right, head, &tail);
		}
		else
			flag = 1;

		_pop(&head);
	}
	return (1);
}
