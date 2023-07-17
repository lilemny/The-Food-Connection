<?php

// Initialize variables
$int = 0;
$menu = array();

// Open connection to the database
$conn = mysqli_connect("localhost", "un", "pw", "dbname");

// Retrieve menu items from database
$result = mysqli_query($conn, "SELECT * FROM food_menu");

// Loop through the results and save them in an array
while($row = mysqli_fetch_assoc($result)) {
	array_push($menu, $row);
}

// Close connection to the database
mysqli_close($conn);

// Output HTML for the page
echo "<html>";
	echo "<head>";
		echo "<title>The Food Conection</title>";
	echo "</head>";
	echo "<body>";
		echo "<h1>Welcome to The Food Conection!</h1>";
		echo "<h2>Menu</h2>";
		echo "<ul>";
			// Loop through the previously retrieved menu items
			while ($int < count($menu)) {
				echo "<li>".$menu[$int]['food_name']." - $".$menu[$int]['price']."</li>";
				$int++;
			}
		echo "</ul>";
	echo "</body>";
echo "</html>";
?>