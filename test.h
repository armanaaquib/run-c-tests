#ifndef __TEST_H_
#define __TEST_H_

#define PASS "✅"
#define FAIL "❌"

typedef enum
{
  False,
  True
} Bool;

typedef char *Char_ptr;

typedef struct
{
  Char_ptr name;
  Bool status;
  Char_ptr error;
} Test;

typedef Test *Test_ptr;

typedef struct
{
  unsigned total;
  unsigned passed;
  unsigned failed;
} Report;

typedef Report *Report_ptr;

typedef Test_ptr (*Test_Func)(void);

Test_ptr create_test(Char_ptr);

Report_ptr run_tests(Test_Func [], unsigned);
void display_report(Report_ptr);

#endif
