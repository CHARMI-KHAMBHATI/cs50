<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("change_form.php", ["title" => "Change Password"]);
    }
    
    // else if user reached page via POST (as by submitting a form via POST)        
    else if ($_SERVER["REQUEST_METHOD"] == "POST")  
    {
        // validate submission
        if (empty($_POST["username"]))
        {
            apologize("You must provide your username.");
        }
        else if (empty($_POST["old_password"]))
        {
            apologize("You must provide your password.");
        }
         else if (empty($_POST["new_password"]))
        {
            apologize("You must provide a new password.");
        }
        else if (empty($_POST["password_check"]))
        {
            apologize("Please confirm your password.");
        }
        
        else if($_POST["new_password"]!=$_POST["password_check"])
        {
            apologize("Please properly confirm your password.");
        }
        else
        {
            
        $result=CS50::query("SELECT* FROM users WHERE username= ?", $_POST["username"]);
        
        if($result==TRUE)
         { CS50::query("UPDATE users (username, hash) VALUES(?, ?)", $_POST["username"], password_hash($_POST["new_password"], PASSWORD_DEFAULT));
        
            print("Congratulations! Your password has been changed");
        
         }
         
         else
         {
             apologize("This username already exits! \n Please try another name. ");
         }
        
        }
    }

?>