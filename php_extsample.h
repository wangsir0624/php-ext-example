/* extsample extension for PHP */

#ifndef PHP_EXTSAMPLE_H
# define PHP_EXTSAMPLE_H

extern zend_module_entry extsample_module_entry;
# define phpext_extsample_ptr &extsample_module_entry

# define PHP_EXTSAMPLE_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_EXTSAMPLE)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

# define EXTSAMPLE_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(extsample, v)

ZEND_BEGIN_MODULE_GLOBALS(extsample)
    int test_global;
ZEND_END_MODULE_GLOBALS(extsample)

#endif	/* PHP_EXTSAMPLE_H */
