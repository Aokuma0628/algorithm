#ifndef _NODE_H
#define _NODE_H


typedef struct _node {
  char *key;
  void *data;
  struct _node *left;
  struct _node *right;
} NODE;

int   insert_node(NODE *node);
NODE *search_node(char *key);
void  free_node(NODE *node);

#endif
