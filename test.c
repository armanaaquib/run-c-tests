#include <stdio.h>
#include <stdlib.h>
#include "test.h"

Report_ptr create_report(void);
void pass_message(Char_ptr);
void fail_message(Char_ptr);
void error_message(Char_ptr);

Test_ptr create_test(Char_ptr name)
{
  Test_ptr test = malloc(sizeof(Test));

  test->name = name;
  test->status = True;
  test->error = malloc(sizeof(char) * 50);

  return test;
}

void pass_message(Char_ptr test_name)
{
  printf("%s %s\n", PASS, test_name);
}

void fail_message(Char_ptr test_name)
{
  printf("%s %s\n", FAIL, test_name);
}

void error_message(Char_ptr error)
{
  printf("%s\n", error);
}

Report_ptr create_report(void)
{
  Report_ptr report = malloc(sizeof(Report));

  report->total = 0;
  report->passed = 0;
  report->failed = 0;

  return report;
}

Report_ptr run_tests(Test_Func tests[], unsigned length)
{
  Report_ptr report = create_report();

  for(unsigned i = 0; i < length; i++)
  {
    report->total++;

    Test_ptr test = (*tests[i])();

    if(test->status)
    {
      report->passed++;
      pass_message(test->name);
    }
    else
    {
      report->failed++;
      fail_message(test->name);
      error_message(test->error);
    }
  }

  return report;
}

void display_report(Report_ptr report)
{
  printf("\nTotal: %d\n", report->total);
  printf("Passed: %d, Failed: %d\n", report->passed, report->failed);
}
