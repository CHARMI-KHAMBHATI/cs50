<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Register"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // TODO
        // validate submission
        if (empty($_POST["symbol"]))
        {
            apologize("You must provide a symbol.");
        }
        
        $stock = lookup($_POST["symbol"]);
       // $format_number = number_format($stock, 2, '.', ',');
        
         if ($stock==FALSE)
        {
            apologize("Unable to find the symbol.");
        }
       
       else {
           
          // $_POST["price"]=$stock;
          print("Price: ".$stock["price"]);
       }
        
    }

?>