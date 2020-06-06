#include "test.h"

#ifndef __ASSERTIONS_H_
#define __ASSERTIONS_H_

void assert_int_equal(int, int, Test_ptr);
void assert_int_array_equal(int *, int *, int, Test_ptr);

///* if you have already made these typedefs in your actual program,
//simply comment it and include your program header file above
typedef void *Element;

typedef struct node
{
  Element element;
  struct node *prev;
  struct node *next;
} Node;

typedef Node *Node_ptr;

typedef struct
{
  Node_ptr first;
  Node_ptr last;
  int length;
} Linked_list;

typedef Linked_list *LinkedList_ptr;

typedef Bool (*Matcher)(Element, Element);
//*/

void assert_element_equal(Element, Element, Matcher, Test_ptr);
void assert_element_null(Element, Test_ptr);
void assert_linked_list_equal(LinkedList_ptr, LinkedList_ptr, Matcher, Test_ptr);

///* if you have already made these typedefs in your actual program,
//simply comment it and include your program header file above
typedef void *Value;

typedef struct tree_node
{
  Value value;
  struct tree_node *left;
  struct tree_node *right;
} Tree_node;

typedef Tree_node *TreeNode_ptr;
//*/

void assert_value_equal(Value, Value, Matcher, Test_ptr);
void assert_value_null(Value, Test_ptr);
void assert_tree_equal(TreeNode_ptr, TreeNode_ptr, Matcher, Test_ptr);

#endif
