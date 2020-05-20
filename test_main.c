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

void test_add(TestReport_ptr);
Test_ptr should_add_two_pos_nums(Test_ptr);
Test_ptr should_add_two_neg_nums(Test_ptr);
Test_ptr should_add_pos_and_neg_num(Test_ptr);
void test_sub(TestReport_ptr);
Test_ptr should_sub_two_pos_nums(Test_ptr);
Test_ptr should_sub_two_neg_nums(Test_ptr);
Test_ptr should_sub_pos_and_neg_num(Test_ptr);

Test_ptr should_add_two_pos_nums(Test_ptr test)
{
  test->name = "should add two positive numbers";

  assert_int_equal(add(1,2), 3, test);
  assert_int_equal(add(0,2), 2, test);

  return test;
}

Test_ptr should_add_two_neg_nums(Test_ptr test)
{
  test->name = "should add two negative numbers";

  assert_int_equal(add(-1,-2), -3, test);
  assert_int_equal(add(-0,-2), -2, test);

  return test;
}

Test_ptr should_add_pos_and_neg_num(Test_ptr test)
{
  test->name = "should add positive and negative number";

  assert_int_equal(add(-1,2), 1, test);
  assert_int_equal(add(-2,0), -2, test);

  return test;
}

void test_add(TestReport_ptr report)
{
  Test_Func tests[] = {
    should_add_two_pos_nums, 
    should_add_two_neg_nums,
    should_add_pos_and_neg_num
  };

  run_tests("add()", tests, 3, report);
}

Test_ptr should_sub_two_pos_nums(Test_ptr test)
{
  test->name = "should sub two positive numbers";

  assert_int_equal(sub(2,1), 1, test);
  assert_int_equal(sub(2,0), 2, test);

  return test;
}

Test_ptr should_sub_two_neg_nums(Test_ptr test)
{
  test->name = "should sub two negative numbers";

  assert_int_equal(sub(-1,-2), 1, test);
  assert_int_equal(sub(-3,-2), -1, test);

  return test;
}

Test_ptr should_sub_pos_and_neg_num(Test_ptr test)
{
  test->name = "should sub positive and negative number";

  assert_int_equal(sub(-1,2), -3, test);
  assert_int_equal(sub(-2,0), -2, test);

  return test;
}

void test_sub(TestReport_ptr report)
{
  Test_Func tests[] = {
    should_sub_two_pos_nums, 
    should_sub_two_neg_nums,
    should_sub_pos_and_neg_num
  };

 run_tests("sub()", tests, 3, report);
}

int main(void)
{
  TestSuite_Func test_suites[] = {test_add, test_sub};

  TestReport_ptr report = runt_test_suites(test_suites, 2);
  display_report(report);

  return 0;
}
