#include <criterion/criterion.h>
#include <criterion/redirect.h>
int do_op(int ac, char **av);

void redirect_all_stderr(void)
{
    cr_redirect_stderr();
}

Test(do_op, test_addition)
{
    int ac = 4;
    char *av[] = {"a.out", "123", "+", "987"};
    int result = 0;

    result = do_op(ac, av);
    cr_assert_eq(result, 1110);
}

Test(do_op, test_sub)
{
    int ac = 4;
    char *av[] = {"a.out", "123", "-", "987"};
    int result = 0;

    result = do_op(ac, av);
    cr_assert_eq(-864, result);
}

Test(do_op, test_prod)
{
    int ac = 4;
    char *av[] = {"a.out", "123", "*", "987"};
    int result = 0;

    result = do_op(ac, av);
    cr_assert_eq(121401, result);
}

Test(do_op, test_div)
{
    int ac = 4;
    char *av[] = {"a.out", "987", "/", "123"};
    int result = 0;

    result = do_op(ac, av);
    cr_assert_eq(8, result);
}

Test(do_op, test_mod)
{
    int ac = 4;
    char *av[] = {"a.out", "987", "%", "123"};
    int result = 0;
    
    result = do_op(ac, av);
    cr_assert_eq(3, result);
}

Test(do_op, test_err_div, .init=redirect_all_stderr)
{
    int ac = 4;
    char *av[] = {"a.out", "123456789123456789", "/", "0"};

    do_op(ac, av);
    cr_assert_stderr_eq_str("Stop : division by zero\n");
}

Test(do_op, test_err_mod, .init=redirect_all_stderr)
{
    int ac = 4;
    char *av[] = {"a.out", "123456789123456789", "%", "0"};

    do_op(ac, av);
    cr_assert_stderr_eq_str("Stop : modulo by zero\n");
}
