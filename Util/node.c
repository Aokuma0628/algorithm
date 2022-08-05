#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK  1
#define NG -1


typedef struct _node {
  char *key;
  void *data;
  struct _node *left;
  struct _node *right;
} NODE;

NODE *g_root = NULL;  /* root of node */

/*node function*/
int   insert_node(NODE *node);
NODE *serch_node(char *key);
void  free_node(NODE *node);

int getHeight(
  NODE *root
)
{
  if (!root) {
    return -1;
  }

  int rightDepth  = getHeight(root->right);
  int leftDepth   = getHeight(root->left);

  return (rightDepth > leftDepth ? rightDepth : leftDepth) + 1;
}


NODE *search_node(
  char *key
)
{
  NODE *pos    = g_root;
  int   result = 0;

  while (pos) {
    result = strcmp(key, pos->key);
    if (result == 0) {
      return pos;
    }
    else if (result < 0) {
      pos = pos->left;
    }
    else {
      pos = pos->right;
    }
  }

  return NULL;
}

int insert_node(
  NODE *node
)
{
  NODE *pos = g_root;
  NODE *pre  = NULL;

  if (!node) {
    return NG;
  }

  if (!pos) {
    g_root = node;
    return OK;
  }

  while (pos) {
    pre = pos;
    if (strcmp(node->key, pos->key) < 0) {
      pos = pos->left;
      if (!pos) {
        pre->left = node;
      }
    }
    else {
      pos = pos->right;
      if (!pos) {
        pre->right = node;
      }
    }
  }
  return OK;
}


void free_node (
  NODE *node
)
{
  if (!node) {
    node = g_root;
  }

  if (!node) {
    return ;
  }

  if (node->left) {
    free_node(node->left);
  }
  if (node->right) {
    free_node(node->right);
  }

  free(node);
  return ;

}
