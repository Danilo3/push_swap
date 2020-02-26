/*
 * Mini unit testing framework based on
 * http://www.jera.com/techinfo/jtns/jtn002.html
 * and extended by @ayellin
*/

#ifndef LIBTEST_MINUNIT_H
#define LIBTEST_MINUNIT_H

#ifdef WIN32
	#define __FUNCTION_NAME__   __FUNCTION__
#else
	#define __FUNCTION_NAME__   __func__
#endif

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define MU_BUF_SIZE 1024

#define MU_TRUE	1
#define MU_FALSE 0
#define MU_NULL ((void*)0)

#include <string.h>
#include "capture.h"

extern int g_tests_run;
extern int g_tests_failed;

typedef char* (*test_func_ptr_t)(void);

typedef int (*print_func_ptr_t)(const char *fmt, ...);

typedef	struct	s_test_func
{
	test_func_ptr_t fp;
	int 			seconds;
	char			*result;
}				t_test_func;

void    test_all_suites(const char *dir);

void	test_all(const char *msg, int n, ...);

char	*get_printf_output(const char *fmt, ...);

char	*make_printf_msg(const char *func_name, const char *message, const char *fmt, const char *output);

char 	*mu_compare_printf_output(const char *ft_output, const char *st_output);

void	test_all_with_time(const char *test_suite, int n, ...);

void	test_all_with_certain_time(const char *test_suite, int seconds, int n, ...);

char	*test_program_and_file(const char *prog_name, const char *args, const char *file_name);

char 	*assert_files(const char *file1, const char *file2);

char	*test_program_return(const char *prog_name, int expected);

char	*make_full_msg(const char* msg, const char* msg2, const char* sep);

char	*make_str_msg(char* msg, const char* s1, const char* s2, const char* fname);

char	*make_int_msg(char* message, int  i1, int i2, const char* fname);

char	*make_flt_msg(char* message, double f1, double f2, const char* fname);

char 	*make_mem_msg(char *message, const void *m1, const void *m2, size_t size, const char *fname);

char	*make_ui_msg(char* message, unsigned f1, unsigned f2, const char* fname);

#define mu_assert(message, test) do {if (!(test)) {return make_full_msg(message, __FUNCTION_NAME__, " -> ");} } while (0)

#define mu_run_test(test) do { char* message = test(); g_tests_run++; if (message) {g_tests_failed++; print_error(message); } } while(0)

#define mu_run_test_timeout(timeout, test) do { char* message = test_timeout(timeout, test); g_tests_run++; if (message) {g_tests_failed++; print_error(message); } } while(0)

#define mu_assert_str(message, s1, s2) do {if (strcmp(s1, s2) != 0) {return make_str_msg(message, s1, s2, __FUNCTION_NAME__); } } while (0)

#define mu_assert_mem(message, m1, m2, n) do {if (memcmp(m1, m2, n) != 0) {return make_mem_msg(message, m1, m2, n, __FUNCTION_NAME__); } } while (0)

#define mu_assert_i(message, i1, i2) do {if (i1 != i2) { return make_int_msg(message, i1, i2, __FUNCTION_NAME__);} } while(0)

#define mu_assert_f(message, f1, f2) do {if (f1 != f2) { return make_flt_msg(message, f1, f2, __FUNCTION_NAME__);} } while(0)

#define mu_assert_str_is_null(message, s1) do {if (s1 != NULL) {return make_str_msg(message, s1, NULL, __FUNCTION_NAME__); } } while (0)

#define mu_assert_ui(message, f1, f2) do {if (f1 != f2) { return make_ui_msg(message, f1, f2, __FUNCTION_NAME__);} } while(0)

#define mu_assert_files(message, file1, file2) do {if (assert_files(file1, file2)) {return make_full_msg(message, __FUNCTION_NAME__, " -> ");} } while (0)

#define mu_assert_prf(message, program, args, file) do {if (test_program_and_file(program, args, file)) {return make_full_msg(message, __FUNCTION_NAME__, " -> ");} } while (0)

char 	*mu_compare_printf_return(int ft_ret, int st_ret);
int	get_printf_ret(const char *fmt, ...);


#define mu_assert_printf(message, ft_printf, fmt, args...) do { 		\
char *st_output;														\
char *ft_output;														\
char *result;															\
capture_stdout();														\
ft_printf(fmt, args);													\
ft_output = strdup(capture_stdout_get_buffer());						\
capture_stdout_destroy();												\
st_output = get_printf_output(fmt, args);								\
result = mu_compare_printf_output(ft_output, st_output);			    \
if (result)																\
	return (make_printf_msg(__FUNCTION_NAME__, message, fmt, result));	\
} while (0)																\

#define mu_assert_printf_return(message, ft_printf, fmt, args...) do { 	\
																		\
char *result;                                                           \
int st_ret = 0;															\
int ft_ret = 0;                                                          \
capture_stdout();														\
ft_ret = ft_printf(fmt, args);											\
capture_stdout_destroy();												\
st_ret = get_printf_ret(fmt, args);									\
result = mu_compare_printf_return(ft_ret, st_ret);			    		\
if (result)																\
	return (make_printf_msg(__FUNCTION_NAME__, message, fmt, result));	\
} while (0)																\

char* 	mu_check_two_stacks(t_stack *stack1, t_stack *stack2);

#endif
