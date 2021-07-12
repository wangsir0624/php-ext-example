--TEST--
extsample_test2() Basic test
--EXTENSIONS--
extsample
--FILE--
<?php
var_dump(extsample_test2());
var_dump(extsample_test2('PHP'));
?>
--EXPECT--
string(11) "Hello World"
string(9) "Hello PHP"
