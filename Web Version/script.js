let account = null;
let loggedIn = false;

function createAccount() {
    let name = document.getElementById("name").value;
    let accNo = document.getElementById("accNo").value;
    let pin = document.getElementById("pin").value;
    let balance = parseFloat(document.getElementById("balance").value);

    if (!name || !accNo || !pin || isNaN(balance)) {
        alert("Fill all fields");
        return;
    }

    account = {
        name: name,
        accNo: accNo,
        pin: pin,
        balance: balance
    };

    document.getElementById("output").innerText = "Account Created!";
}

function login() {
    let pin = document.getElementById("loginPin").value;

    if (account && pin === account.pin) {
        loggedIn = true;
        document.getElementById("bankSection").style.display = "block";
        document.getElementById("output").innerText = "Login Successful!";
    } else {
        document.getElementById("output").innerText = "Wrong PIN!";
    }
}

function deposit() {
    let amount = parseFloat(document.getElementById("amount").value);

    if (amount > 0) {
        account.balance += amount;
        document.getElementById("output").innerText = "Deposit Successful!";
    } else {
        alert("Invalid amount");
    }
}

function withdraw() {
    let amount = parseFloat(document.getElementById("amount").value);

    if (amount <= 0) {
        alert("Invalid amount");
    } else if (amount > account.balance) {
        alert("Insufficient balance");
    } else {
        account.balance -= amount;
        document.getElementById("output").innerText = "Withdrawal Successful!";
    }
}

function showBalance() {
    document.getElementById("output").innerText =
        "Balance: $" + account.balance;
}