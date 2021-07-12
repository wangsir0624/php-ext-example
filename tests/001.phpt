--TEST--
Check if extsample is loaded
--SKIPIF--
<?php
if (!extension_loaded('extsample')) {
	echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "extsample" is available';
?>
--EXPECT--
The extension "extsample" is available
