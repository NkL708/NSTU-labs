<?php
session_start();
?>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Лабораторная работа 4</title>
</head>
<body>
	<p>Регистрация</p>
	<form action="server.php" method="GET">
		<p><input type="text" name="username" placeholder="username"></p>
		<p><input type="password" name="password" placeholder="password"></p>
		<input type="submit" value="Зарегистрироваться" name="register">
	</form>
	<p>Авторизация</p>
	<form action="server.php" method="GET">
		<p>
			<input type="text" id="username" name="username" placeholder="username" value="<?php
			if (isset($_SESSION["username"]))
			{
				echo $_SESSION["username"];
			}?>">
		</p>
		<p>
			<input type="password" id="password" name="password" placeholder="password" value="<?php
			if (isset($_SESSION["password"]))
			{
				echo $_SESSION["password"]; 
			}?>">
		</p>
		<input type="submit" value="Войти" name="login">
	</form>
</body>
</html>