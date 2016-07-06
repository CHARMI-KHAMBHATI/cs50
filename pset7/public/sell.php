<?php

    // configuration
    require("../includes/config.php");

     if ($_SERVER["REQUEST_METHOD"] == "GET"){
        
        render("sell_form.php", ["title" => "Sell"]);
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
          
          $check=CS50::query("SELECT * FROM  `portfolios` WHERE  username = '?' AND  `symbol` =  ? AND  `shares` >=? ", $_POST["username"], $_POST["symbol"], $nos);
           
          if($check==FALSE){
              
              apologize(" Request could not be processed");
          }
          
          else
           {
           
                for($i=1;$i<=$nos;$i++){
                CS50::query("UPDATE users SET cash = cash + ? WHERE userid = ?", $amt, $_SESSION["id"]);
            }
            
            CS50::query("UPDATE portfolios SET shares= shares- ?", $nos);
            
            print("Your shares were successfully sold!");
               
           }
        }
    }

?>