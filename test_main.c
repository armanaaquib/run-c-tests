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

Test_ptr should_add_two_pos_nums()
{
  Test_ptr test = create_test("should add two positive numbers");

  assert_int_equal(add(1,2), 3, test);
  assert_int_equal(add(0,2), 2, test);

  return test;
}

Test_ptr should_add_two_neg_nums()
{
  Test_ptr test = create_test("should add two negative numbers");

  assert_int_equal(add(-1,-2), -3, test);
  assert_int_equal(add(-0,-2), -2, test);

  return test;
}

Test_ptr should_add_pos_and_neg_num()
{
  Test_ptr test = create_test("should add positive and negative number");

  assert_int_equal(add(-1,2), 1, test);
  assert_int_equal(add(-2,0), -2, test);

  return test;
}

Report_ptr test_add(Report_ptr report)
{
  Test_Func tests[] = {
    should_add_two_pos_nums, 
    should_add_two_neg_nums,
    should_add_pos_and_neg_num
  };

 return run_tests("add()", tests, 3, report);
}

Test_ptr should_sub_two_pos_nums()
{
  Test_ptr test = create_test("should sub two positive numbers");

  assert_int_equal(sub(2,1), 1, test);
  assert_int_equal(sub(2,0), 2, test);

  return test;
}

Test_ptr should_sub_two_neg_nums()
{
  Test_ptr test = create_test("should sub two negative numbers");

  assert_int_equal(sub(-1,-2), 1, test);
  assert_int_equal(sub(-3,-2), -1, test);

  return test;
}

Test_ptr should_sub_pos_and_neg_num()
{
  Test_ptr test = create_test("should sub positive and negative number");

  assert_int_equal(sub(-1,2), -3, test);
  assert_int_equal(sub(-2,0), -2, test);

  return test;
}

Report_ptr test_sub(Report_ptr report)
{
  Test_Func tests[] = {
    should_sub_two_pos_nums, 
    should_sub_two_neg_nums,
    should_sub_pos_and_neg_num
  };

 return run_tests("sub()", tests, 3, report);
}

int main(void)
{
  TestSuite_Func test_suites[] = {test_add, test_sub};

  Report_ptr report = runt_test_suite(test_suites, 2);
  display_report(report);

  return 0;
}
