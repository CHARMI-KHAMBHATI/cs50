<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("register_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["password"]))
        {
            apologize("You must provide your password.");
        }
        else if (empty($_POST["password_check"]))
        {
            apologize("Please confirm your password.");
        }
        
        else if($_POST["password"]!=$_POST["password_check"]){
            apologize("Please properly confirm your password.");
        }
        else
        {
            
        $result=CS50::query("SELECT* FROM users WHERE username= ?", $_POST["username"]);
        
        if($result==FALSE)
         { CS50::query("INSERT IGNORE INTO users (username, hash, cash) VALUES(?, ?, 10000.0000)", $_POST["username"], password_hash($_POST["password"], PASSWORD_DEFAULT));
        
            print("Congratulations! Your account has been generated");
        
         }
         
         else
         {
             apologize("This username already exits! \n Please try another name. ");
         }
        
        }
    }

?>