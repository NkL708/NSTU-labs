<?php
session_start();
// Database redirect
$authorizedUser = false;
if (isset($_REQUEST['register'])) 
{
    $username = $_REQUEST['username'];
    $password = $_REQUEST['password'];
    $con = pg_connect("host=localhost port=5432 dbname=web_lab4 user=postgres password=hugelong123");
    if (!empty($username) && !empty($password)) 
    {
        pg_query($con,  "INSERT INTO users (username, password) 
                        VALUES('$username', '$password');");
    }
    $_SESSION["username"] = $username;
    $_SESSION["password"] = $password;
    header('Location: index.php');
    exit;
}
if (isset($_REQUEST['login'])) 
{
    $username = $_REQUEST['username'];
    $password = $_REQUEST['password'];
    $con = pg_connect("host=localhost port=5432 dbname=web_lab4 user=postgres password=hugelong123");
    $users = pg_query($con, "SELECT username, password
                            FROM users");
    while ($row = pg_fetch_row($users)) 
    {
        // If user in database
        if ($row[0] == $username && $row[1] == $password) 
        {
            $authorizedUser = true;
            $_SESSION["username"] = $username;
            $_SESSION["password"] = $password;
        }      
    }
    if ($authorizedUser)
        header('Location: auth.php');
    else
        header('Location: guest.html');
    exit;
}
// AJAX
if (isset($_REQUEST['ajax'])) 
{
    $carsIndex = $_REQUEST['ajax'];
    // 2, 5, 8 is correct
    if ($carsIndex == 2 || $carsIndex == 5 || $carsIndex == 8) 
    {
        echo true;
    }
    else 
        echo false;
    exit;
}