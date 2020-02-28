//
// Created by Aletha Yellin on 27/02/2020.
//

#include "minunit.h"
#include "libft.h"

typedef struct s_test
{
	char	*str;
	int 	value;
	int 	result;
}				t_test;

static char * assert_test(t_test *test, char *str, int value, int result)
{
	mu_assert_str("str wrong", test->str, str);
	mu_assert_i("value wrong", test->value, value);
	mu_assert_i("result wrong", test->result, result);
	return (0);
}

static char *test_simple()
{
	t_test test;

	test.str = strdup("1 2 3 4 5");
	test.result = ft_parse_int_str(&test.str, &test.value);

	assert_test(&test, " 2 3 4 5", 1, 1);
	return (0);
}

int main()
{
	test_all("PARSE INT SUITE", 1, test_simple);
}