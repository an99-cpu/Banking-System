# Banking System

A secure console-based Banking System built in C++ with a companion web interface. Supports account creation, PIN authentication, deposits, withdrawals, and persistent file-based storage.

## Screenshots

![Banking UI](Banking%20Sys-screenshot/Banking%20UI.png)

## Features

- PIN-based user authentication with input validation
- Account creation and full transaction support (deposit, withdrawal, balance inquiry)
- Data persistence using C++ fstream — accounts survive program restarts
- Private access modifiers to protect sensitive account data (Encapsulation)
- Web interface built with HTML & CSS to simulate the banking workflow

## Tech Stack

| Layer | Technology |
|-------|-----------|
| Core Logic | C++ |
| OOP Concepts | Encapsulation, Classes |
| Storage | File Handling (fstream) |
| Web Interface | HTML, CSS |

## How to Run

### C++ Version
```bash
g++ -o banking "Cpp Version/main.cpp"
./banking
```

### Web Version
Open `Banking Sys-Web/index.html` in any browser.

## What I Learned

- Implementing secure authentication logic without external libraries
- Managing persistent storage using file I/O in C++
- Protecting sensitive data through encapsulation principles
