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
    <title>Fill your Info</title>

    <style>

        form {
            margin: 7%;
            padding: 5% 20% 5% 20%;
            border: 5px dotted rgb(44, 114, 114);
        }

        .form-control, textarea{
            border: 2px solid darkcyan;
        }

        .btn {
            background-color: darkcyan;
        }

        .cancel {
            background-color: red;
            border: none;
            margin-top: 20px;
        }

        .sbmt {
            background-color: green;
            border: none;
            margin-top: 20px;
            margin-left: 10px;
        }

        .label {
            font-weight: bolder;
        }

        .area {
            height: 100px;
            text-align: start;
        }

        
    </style>
</head>

<body>

    <form action="response.php" method="post" enctype="multipart/form-data">

        <div class="form-row">
            <div class="form-group col-md-6">
                <label for="fname">First Name</label>
                <input type="text" name="fname" class="form-control" id="fname" placeholder="Abdul" required>
            </div>
            <div class="form-group col-md-6">
                <label for="lname">Last Name</label>
                <input type="text" name="lname" class="form-control" id="lname" placeholder="Ahad" required>
            </div>
        </div>

        <div class="form-row">
            <div class="form-group col-md-12">
                <label for="inputEmail4">Email</label>
                <input type="email" name="email" class="form-control" id="inputEmail4" placeholder="abc123@gmail.com" required>
            </div>
        </div>

        <div class="form-group">
            <label for="inputAddress">Address</label>
            <br>
            <textarea rows="4" cols="58" name="address" required></textarea>
        </div>

        <br>
        <div class="form-group">
            <label for="image">Photo &nbsp; &nbsp;</label>
            <input type="file" class="image" name='image' required>
        </div>

        <button type="reset" class="cancel btn btn-primary">Cancel</button>
        <input type="submit" value="Submit" class="sbmt btn btn-primary">

    </form>

</body>

</html>