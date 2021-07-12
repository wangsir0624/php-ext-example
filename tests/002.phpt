--TEST--
extsample_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('extsample')) {
	echo 'skip';
}
?>
--FILE--
<?php
$ret = extsample_test1();

var_dump($ret);
?>
--EXPECT--
The extension extsample is loaded and working!
NULL
