/* extsample extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_extsample.h"

/* For compatibility with older PHP versions */
#ifndef ZEND_PARSE_PARAMETERS_NONE
#define ZEND_PARSE_PARAMETERS_NONE() \
	ZEND_PARSE_PARAMETERS_START(0, 0) \
	ZEND_PARSE_PARAMETERS_END()
#endif

ZEND_DECLARE_MODULE_GLOBALS(extsample)

/* {{{ void extsample_test1()
 */
PHP_FUNCTION(extsample_test1)
{
	ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "extsample");
}
/* }}} */

/* {{{ string extsample_test2( [ string $var ] )
 */
PHP_FUNCTION(extsample_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s\r\n", var);

	RETURN_STR(retval);
}
/* }}}*/

PHP_MINIT_FUNCTION(extsample)
{
    printf("test minit\r\n");
    EXTSAMPLE_G(test_global) = 555;

    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(extsample)
{
    printf("test mshutdown\r\n");

    return SUCCESS;
}

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(extsample)
{
#if defined(ZTS) && defined(COMPILE_DL_EXTSAMPLE)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
    printf("test rinit\r\n");
    printf("test global: %d\r\n", EXTSAMPLE_G(test_global));

	return SUCCESS;
}
/* }}} */

PHP_RSHUTDOWN_FUNCTION(extsample)
{
    printf("test rshutdown\r\n");
}

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(extsample)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "extsample support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_extsample_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_extsample_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ extsample_functions[]
 */
static const zend_function_entry extsample_functions[] = {
	PHP_FE(extsample_test1,		arginfo_extsample_test1)
	PHP_FE(extsample_test2,		arginfo_extsample_test2)
	PHP_FE_END
};
/* }}} */

/* {{{ extsample_module_entry
 */
zend_module_entry extsample_module_entry = {
	STANDARD_MODULE_HEADER,
	"extsample",					/* Extension name */
	extsample_functions,			/* zend_function_entry */
	PHP_MINIT(extsample),							/* PHP_MINIT - Module initialization */
    PHP_MSHUTDOWN(extsample),							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(extsample),			/* PHP_RINIT - Request initialization */
    PHP_RSHUTDOWN(extsample),							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(extsample),			/* PHP_MINFO - Module info */
	PHP_EXTSAMPLE_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_EXTSAMPLE
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(extsample)
#endif
