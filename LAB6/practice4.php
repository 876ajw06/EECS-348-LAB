<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>EECS 348 LAB 6</title>
    <style> /*style settings for the table*/
        table {
            border-collapse: collapse;
            margin-top: 20px;
        }
        td {
            padding: 10px;
            text-align: center;
        }
    </style>
</head>
<body>

    <form method="post">
        Size of the multiplication table: <input type="number" name="size" required>
        <br>
        <input type="submit" value="Submit">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $size = intval($_POST["size"]);

        if ($size > 0) {
            echo "<table border='1'>";
    
            echo "<tr><td class='index'>&times;</td>"; //creates the headers
            for ($col = 1; $col <= $size; $col++) {
                echo "<td class='index'>$col</td>";
            }
            echo "</tr>";

            // 2. Create the main table rows
            for ($row = 1; $row <= $size; $row++) {//creates the rows and columns
                echo "<tr>";
                
                
                echo "<td class='index'>$row</td>";

                for ($col = 1; $col <= $size; $col++) {//prints results into table
                    $result = $row * $col;
                    echo "<td>$result</td>";
                }

                echo "</tr>";
            }
            echo "</table>";
        } else {
            echo "<p style='color:red;'>Please enter a number greater than 0.</p>";
        }
    }
    ?>

</body>
</html>