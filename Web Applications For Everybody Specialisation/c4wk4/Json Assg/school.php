<?php
require_once "pdo.php";
$term = $_GET ['term'];
error_log("Looking up typeahead term =".$term);
$stmt = $pdo->prepare('SELECT name FROM Institution WHERE name LIKE :prefix');
$stmt->execute(array(':prefix'=>$term."%"));

$retval = array();
while($row = $stmt->fetch(PDO::FETCH_ASSOC))
{
  $retval[]=$row['name'];
}//pulls out names of schools from database
echo(json_encode($retval, JSON_PRETTY_PRINT)); //encode into json
