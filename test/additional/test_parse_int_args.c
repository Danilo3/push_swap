//
// Created by Aletha Yellin on 27/02/2020.
//

#include "minunit.h"
#include "libft.h"
#include <stdlib.h>

typedef struct s_test
{
	char	*str;
	int 	value;
	int 	result;
}				t_test;

static char * assert_test(t_test *test, char *str, int value, int result)
{
	if (test->str && str)
		mu_assert_str("str wrong [test] [good]", test->str, str);
	if (result  != -1)
		mu_assert_i("value wrong [test] [good]", test->value, value);
	mu_assert_i("result wrong [test] [good]", test->result, result);
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

#define exec_test(test, str, value, result) do {char *msg; if((msg = assert_test(test, str, value, result))) {return (msg);}} while(0)

static char*	more_test()
{
	t_test		test;
	char		*tmp;

	test.str = strdup("1 2 3 4 5");
	tmp = test.str;
	test.result = ft_parse_int_str(&test.str, &test.value);
	exec_test(&test, " 2 3 4 5", 1, 1);
	test.result = ft_parse_int_str(&test.str, &test.value);
	exec_test(&test, " 3 4 5", 2, 1);
	test.result = ft_parse_int_str(&test.str, &test.value);
	exec_test(&test, " 4 5", 3, 1);
	test.result = ft_parse_int_str(&test.str, &test.value);
	exec_test(&test, " 5", 4, 1);
	test.result = ft_parse_int_str(&test.str, &test.value);
	exec_test(&test, NULL, 5, 1);
	free(tmp);
	return (0);
}

#define WRONG_TESTS 6

static char *wrong_tests()
{
	t_test	arr_test[WRONG_TESTS] = {
			{ "a2 1 3", 0, -1},
			{ "2a 1 3", 0, -1},
			{"a b c", 0, -1},
			{ "2a2 1 3", 0, -1},
			{ "   2a 1 3", 0, -1},
			{"2a", 0, -1}

	};
	for (int i = 0; i < WRONG_TESTS; ++i) {
		t_test test;
		test.str = ft_strdup(arr_test[i].str);
		test.result = ft_parse_int_str(&test.str, &test.value);
		mu_assert_i("test.result", test.result, -1);
	}
	return (0);
}

int main()
{
	test_all("PARSE INT SUITE", 3, test_simple, more_test, wrong_tests);
}