#include "test.h"
#include "assertions.h"

int add(int, int);
int sub(int, int);

int add(int num1, int num2)
{
  return num1 + num2;
}

int sub(int num1, int num2)
{
  return num1 - num2;
}

Test_ptr test_add()
{
  Test_ptr test = create_test("should add numbers");

  assert_int_equal(add(0,2), 2, test);
  assert_int_equal(add(1,2), 3, test);

  return test;
}

Test_ptr test_sub()
{
  Test_ptr test = create_test("should sub numbers");

  assert_int_equal(sub(0,2), -2, test);
  assert_int_equal(sub(2,1), 1, test);

  return test;
}

int main(void)
{
  Test_Func tests[] = {test_add, test_sub};

  Report_ptr report =  run_tests(tests, 2);

  display_report(report);

  return 0;
}
