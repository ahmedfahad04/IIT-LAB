<?php

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // get the data from the form
    $fname = validate($_POST['fname']);
    $lname = validate($_POST['lname']);
    $email = validate($_POST['email']);
    $address = validate($_POST['address']);

    $imageName = $_FILES['image']['name'];
    $tmpName = $_FILES['image']['tmp_name'];
    $uploadLoc = '../img/'.$imageName;

    // echo $imageName . '<br>'. $tmpName. '<br>'. $uploadLoc;

    // DB parameters
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "Users";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // MUST! insert quotes around the variables
    $sql = "INSERT INTO UserDetails (firstName, lastName, email, address, images)
    VALUES ('$fname', '$lname', '$email', '$address', '$imageName')";

    // confirm if the data is inserted
    if ($conn->query($sql) === TRUE) {
        echo "<br>";

        if (move_uploaded_file($tmpName, $uploadLoc)) {
            echo "File uploaded successfully";
        } else {
            echo "Failed to upload file";
        } 
        
        echo "<br>";
        echo "New record created successfully";
    } else {
        echo "Error: " . $sql . "<br>" . mysqli_error($con);
    }

} else {
    echo 'Failed to load...';
}

function validate($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    
    return $data;
}

?>

<?php
    $sql = "SELECT * FROM UserDetails ORDER BY id DESC";
    $data = mysqli_query($conn, $sql);
    $row = mysqli_fetch_assoc($data);
?>



<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <!--BOOTSTRAP JS-->
    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js"
        zcrossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"
        integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM"
        crossorigin="anonymous"></script>
    <!--BOOTSTRAP CSS-->
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"
        integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <title>Document</title>

    <style>

        body {
            display: flex;
            justify-content: center;
            align-items: center;
            font-family: 'Fira Code';
        }

        .main {
            margin: 7%;
            padding: 5% 5% 5% 5%;
            border: 5px dotted rgb(44, 114, 114);
            height: 40vh;
            width: 90vw;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        span {
            font-weight: bolder;
        }

        .left-box{
            width: 40vw;
            min-height: 10vh;
            margin: 1rem;
            float: left;
            padding: 10px;
            font-size: 1.2rem;
        }

        .right-box{
            display: block;
            width: 11vw;
            min-height: 12vh;
            background-color: aliceblue;
            margin: 1rem;
            border: 2px solid blue;
            float: left;
            display: flex;
            justify-content: center;
            align-items: center;
            border-radius: 20%;
        }

    </style>
</head>

<body>

    <div class="main">
        <div class="left-box">
            <div class="form-row">
                <span>Name &nbsp; &nbsp;&nbsp;:&nbsp;</span>
                <p><?php echo $row['firstName']. ' '. $row['lastName']; ?></p>
            </div>
    
            <div class="form-row">
                <span>Email &nbsp; &nbsp;:&nbsp; </span>
                <p><?php echo $row['email']; ?></p>
            </div>
    
            <div class="form-row">
                <span>Address &nbsp;:&nbsp;</span>
                <p><?php echo $row['address']; ?></p>
            </div>
        </div>
    
        <div class="right-box">
            <img src="../img/<?php echo $row['images']; ?>" alt="image" width="100%" height="100%" style='border-radius: 20%;'>
        </div>
    </div>

</body>

</html>