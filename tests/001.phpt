--TEST--
Check if extsample is loaded
--EXTENSIONS--
extsample
--FILE--
<?php
echo 'The extension "extsample" is available';
?>
--EXPECT--
The extension "extsample" is available
