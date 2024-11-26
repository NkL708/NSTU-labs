<?php
session_start();
?>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.2.0/jquery.min.js"></script>
	<script src="script.js"></script>
    <title>Ajax</title>
</head>
<body>
    <?php
    echo "Вы зашли под пользователем: <br>";
    echo "Имя: " . $_SESSION["username"] . "<br>";
	echo "Пароль: " . $_SESSION["password"] . "<br>";
    ?>
    <p>Найдите отечественные машины:</p>
    <select name="cars" id="cars1" size="6" onchange="ajax(1)">
        <option value="1">Nissan</option>
        <option value="2">Москвич</option>
        <option value="3">Toyota</option>
        <option value="4">BMW</option>
        <option value="5">Жигули</option>
        <option value="6">Wolksvagen</option>
        <option value="7">Skoda</option>
        <option value="8">Волга</option>
        <option value="9">Mercedes-Benz</option>
    </select>
</body>
</html>