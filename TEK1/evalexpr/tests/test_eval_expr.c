#include <criterion/criterion.h>
#include <criterion/redirect.h>
int my_cat(int ac, char **av);

void redirect_all_stdout(void)
{
  cr_redirect_stdout();
}

Test(eval_expr, test_simple_parenthesis_expr, .init=redirect_all_stdout)
{
    int res;

    res = eval_expr("(3*-20)+60");
    cr_assert_eq(res, 0);
}
