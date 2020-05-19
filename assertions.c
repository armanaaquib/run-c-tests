#include <stdio.h>
#include "assertions.h"

void assert_int_equal(int actual, int expected, Test_ptr test)
{
  if(test->status == False) return;

  if(!(actual == expected))
  {
    test->status = False;
    sprintf(test->error, "Expected %d Actual %d\n", expected, actual);
  }
}
