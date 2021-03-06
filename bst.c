#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

struct node *bst_create_node(int value) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));

  if (!newNode) return NULL;

  newNode->value = value;
  newNode->left = newNode->right = NULL;

  return newNode;
}

void bst_destroy(struct node *root) {
  if (!root) return;

  bst_destroy(root->left);
  bst_destroy(root->right);

  free(root);
}

struct node *bst_insert(struct node *root, int value) {
  if (!root) return bst_create_node(value);

  if (value > root->value)
    root->right = bst_insert(root->right, value);
  else if (value < root->value)
    root->left = bst_insert(root->left, value);

  return root;
}

struct node *bst_remove(struct node *root, int value) {
  if (!root) return NULL;

  if (root->value == value)
    if (!root->left && !root->right) {
      free(root);
      return NULL;
    } else {
      struct node *tmp;
      if (root->right) {
        tmp = bst_min(root->right);
        root->value = tmp->value;
        root->right = bst_remove(root->right, tmp->value);
      } else {
        tmp = bst_max(root->left);
        root->value = tmp->value;
        root->left = bst_remove(root->left, tmp->value);
      }
    }
  else if (value > root->value)
    root->right =  bst_remove(root->right, value);
  else if (value < root->value)
    root->left = bst_remove(root->left, value);

  return root;
}

struct node *bst_left(struct node *node) {
  return (node->left) ? node->left : NULL;
}

struct node *bst_right(struct node *node) {
  return (node->right) ? node->right : NULL;
}

struct node *bst_find(struct node *root, int value) {
  while (root) {
    if (root->value == value) break;

    root = (value > root->value) ? root->right : root->left;
  }

  return root;
}

struct node *bst_max(struct node *root) {
  if (!root) return NULL;

  while (root->right) {
    root = root->right;
  }

  return root;
}

struct node *bst_min(struct node *root) {
  if (!root) return NULL;

  while (root->left) {
    root = root->left;
  }

  return root;
}

void bst_inorder_print(struct node *root) {
  if (!root) return;

  bst_inorder_print(root->left);

  printf("%d, ", root->value);

  bst_inorder_print(root->right);
}

void bst_indented_print(struct node *root, int level) {
  if (!root) return;

  printf("%d\n", root->value);

  level++;

  if (root->left) {
    for (int i = 0; i < level; i++) printf("  ");
    bst_indented_print(root->left, level);
  }

  if (root->right) {
    for (int i = 0; i < level; i++) printf("  ");
    bst_indented_print(root->right, level);
  }
}