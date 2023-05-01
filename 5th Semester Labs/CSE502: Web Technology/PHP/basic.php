<?php

# this is associative array
$bsse12 = array("Kabir"=>"3.88", "Hashem"=>"3.85", "Kuddus"=>3.80);
// $name = readline("Enter your name: ");
$name = "Kabir";
echo "GPA of ", $name,": ", $bsse12[$name]. PHP_EOL;

// =========================== JSON ENCODE/DECODE ===========================

# encode to json
$encoded = json_encode($bsse12);
echo $encoded. PHP_EOL;

# decode to json
$decoded = json_decode($encoded);
echo $decoded->Hashem. PHP_EOL;
var_dump($decoded);

# check type variable 
echo gettype($bsse12). PHP_EOL;

# loop through json object
foreach($decoded as $key => $value) {
  echo $key . " => " . $value . PHP_EOL;
}

// ======================== LOOPS ========================
// Using for loop
$keys = array_keys($bsse12);
$len = count($bsse12);


for ($i = 0; $i < $len; $i++) {
    $key = $keys[$i];
    $value = $bsse12[$key];
    echo "$key has GPA $value". PHP_EOL;
}

// Using foreach loop
foreach ($bsse12 as $key => $value) {
    echo "$key has GPA $value". PHP_EOL;
}



/*
 * Constant: define("PI", 3.1416);
 * Global: $GLOBALS['x'] = 8;
 * Array: array & associative array, len=count($array_name)
 * JSON: json_encode($array_name), json_decode($json_string)
 * Loop: for, foreach
 * Variable: Local, Global, Static (ei variable use korar poreo delete hoy na)
 * var_dump: structured information (type and value) about one or more expressions/variables
 * Form validation: https://tryphp.w3schools.com/showphp.php?filename=demo_form_validation_complete
 * Display output: echo vs print
 * 1. echo Statement
    * we can write echo statement with parenthesis like 'echo()' or without parenthesis 'echo'.
    * In the echo we can pass multiple variable in comma separated form to see the output like 'echo $a,$b,$c;'
    * echo doesn’t return any value
    * echo is faster then print

 * 2. Print Statement
    * we can write print statement with parenthesis like 'print()' or without parenthesis 'print'.
    * In the print we can not pass multiple variable in comma separated form like echo.
    * print statement always returns 1.
    * print is slower than echo
 
 */



?>

