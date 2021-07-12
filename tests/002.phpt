--TEST--
test1() Basic test
--EXTENSIONS--
extsample
--FILE--
<?php
$ret = test1();

var_dump($ret);
?>
--EXPECT--
The extension extsample is loaded and working!
NULL
