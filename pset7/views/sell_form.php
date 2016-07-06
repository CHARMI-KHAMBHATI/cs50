<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            Enter the symbol of stock to be sold.
            <input autocomplete="off" autofocus class="form-control" name="symbol" placeholder="Stock Symbol" type="text"/>
        </div>
        <div class="form-group">
            Enter the number of stocks to be sold.
            <input autocomplete="off"  class="form-control" name="amount" placeholder="Stock amount" type="text"/>
        </div>
        
            <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Sell
            </button>
        </div>
    </fieldset>
</form>
<div>
    or <a href="login.php">log in</a> for an account
</div>
