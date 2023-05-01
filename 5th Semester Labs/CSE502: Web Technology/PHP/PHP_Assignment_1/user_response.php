<?php

$fname = $lname = $email = $address = $imageName = $tmpName = $uploadLoc = "";

if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // get the data from the form
    $fname = validate($_POST['fname']);
    $lname = validate($_POST['lname']);
    $email = validate($_POST['email']);
    $address = validate($_POST['address']);

    $imageName = $_FILES['image']['name'];
    $tmpName = $_FILES['image']['tmp_name'];
    $uploadLoc = '../img/'.$imageName;

    echo $_FILES['image']['tmp_name'];

    move_uploaded_file($tmpName, $uploadLoc);
    
}

function validate($data)
{
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    
    return $data;
}

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
    <title>Your Info</title>

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
            height: 30vh;
            width: 50vw;
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
            width: 19rem;
            min-height: 12rem;
            /* background-color: aliceblue; */
            margin: 1rem;
            /* border: 2px solid blue; */
            float: left;
            display: flex;
            justify-content: center;
            align-items: center;
            border-radius: 50%;
        }

    </style>
</head>

<body>

    <div class="main">
        <div class="left-box">
            <div class="form-row">
                <span>Name &nbsp;&nbsp;</span>
                <p><?php echo $fname. ' '. $lname; ?></p>

            </div>
    
            <div class="form-row">
                <span>Email &nbsp;&nbsp;</span>
                <p><?php echo $email; ?></p>

            </div>
    
            <div class="form-row">
                <span>Address &nbsp;&nbsp;</span>
                <p><?php echo $address; ?></p>
            </div>
        </div>
    
        <div class="right-box">
            <img src="../img/<?php echo $imageName; ?>" alt="image" width="100%" height="100%" style='border-radius: 50%; width: 10rem; min-height: 10rem;'>
        </div>
    </div>

</body>

</html>