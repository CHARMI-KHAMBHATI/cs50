<?php

    // configuration
    require("../includes/config.php");

     if ($_SERVER["REQUEST_METHOD"] == "GET"){
        
        render("buy_form.php", ["title" => "Buy"]);
     }
       
        // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol.");
        }
        
        else if(empty($_POST["amount"]))
        {
            apologize("You must enter a distinct amount.");
             
        }
        
        else{
         
          $id = $_SESSION["id"];
              
           $nos=$_POST["amount"];
           $amt=lookup($_POST["symbol"]);
          
          
           {
           
                for($i=1;$i<=$nos;$i++){
                CS50::query("UPDATE users SET cash = cash - ? WHERE userid = ?", $amt, $_SESSION["id"]);
            }
            
            CS50::query("UPDATE portfolios SET shares= shares+ ?", $nos);
            
            print("Your shares were successfully bought!");
               
           }
        }
    }

?>