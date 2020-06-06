#include <stdio.h>
#include "assertions.h"

void assert_int_equal(int actual, int expected, Test_ptr test)
{
  if (test->status == False)
    return;

  if (!(actual == expected))
  {
    test->status = False;
    sprintf(test->error, "Expected %d Actual %d\n", expected, actual);
  }
}

void assert_int_array_equal(int *array_1, int *array_2, int length, Test_ptr test)
{
  if (test->status == False)
    return;

  for (int i = 0; i < length; i++)
  {
    int actual = array_1[i];
    int expected = array_2[i];

    if (!(actual == expected))
    {
      test->status = False;
      sprintf(test->error, "Expected %d Actual %d\n", expected, actual);
      break;
    }
  }
}

void assert_element_equal(Element actual, Element expected, Matcher matcher, Test_ptr test)
{
  if (test->status == False)
    return;

  if (!(*matcher)(actual, expected))
  {
    test->status = False;
    sprintf(test->error, "Elements are not equal\n");
  }
}

void assert_element_null(Element el, Test_ptr test)
{
  if (test->status == False)
    return;

  if (el != NULL)
  {
    test->status = False;
    sprintf(test->error, "Element is not null\n");
  }
}

void assert_linked_list_equal(LinkedList_ptr ll_1, LinkedList_ptr ll_2, Matcher is_el_equal, Test_ptr test)
{
  if (test->status == False)
    return;

  Bool is_equal = (ll_1->length == ll_2->length);

  if (!is_equal)
  {
    test->status = False;
    sprintf(test->error, "Expected length %d Actual length %d\n", ll_2->length, ll_1->length);
    return;
  }

  Node_ptr p_walk_1 = ll_1->first;
  Node_ptr p_walk_2 = ll_2->first;

  while (p_walk_1 != NULL)
  {
    is_equal = (*is_el_equal)(p_walk_1->element, p_walk_2->element);

    if (!is_equal)
    {
      test->status = False;
      sprintf(test->error, "Elements are not equal");
      break;
    }

    p_walk_1 = p_walk_1->next;
    p_walk_2 = p_walk_2->next;
  }
}

void assert_value_equal(Value actual, Value expected, Matcher matcher, Test_ptr test)
{
  if (test->status == False)
    return;

  if (!((*matcher)(actual, expected) == 0))
  {
    test->status = False;
    sprintf(test->error, "Values are not equal\n");
  }
}

void assert_value_null(Value val, Test_ptr test)
{
  if (test->status == False)
    return;

  if (val != NULL)
  {
    test->status = False;
    sprintf(test->error, "Value is not null\n");
  }
}

void assert_tree_equal(TreeNode_ptr root_1, TreeNode_ptr root_2, Matcher matcher, Test_ptr test)
{
  if (test->status == False || (!root_1 && !root_2))
    return;

  if ((!root_1 && root_2) || (root_1 && !root_2))
  {
    test->status = False;
    sprintf(test->error, "size is not equal\n");
  }

  if ((*matcher)(root_1->value, root_2->value) != 0)
  {
    test->status = False;
    sprintf(test->error, "value is not equal\n");
  }

  assert_tree_equal(root_1->left, root_2->left, matcher, test);
  assert_tree_equal(root_1->right, root_2->right, matcher, test);
}
