# Bank_managment_system_using_cpp
<pre>
Objective: Develop a menu-driven banking application to manage accounts with functionalities like account creation, deposits, withdrawals, transfers, balance inquiries, and transaction history tracking.

User Interface:
The program displays the following menu when executed:

------------------MENU--------------------------

c/C: Create account.
h/H: Transaction history (last 5).
w/W: Withdraw amount.
d/D: Deposit amount.
b/B: Balance enquiry.
t/T: Transfer money.
e/E: Display all accounts details.
s/S: Save accounts info to file.
f/F: Find specific account.
q/Q: Quit from app.
Enter your choice:
Account Structure Each account contains:

Account Number: Auto-generated (unique, starts from 1000).
Name: Account holder’s name.
Balance: Current account balance.
Transactions: List of transactions (deposit/withdraw/transfer) with:
- Unique transaction_id (auto-incremented).
- Timestamp, type, amount, and description.
Contact: Account holder’s contact number.
Key Requirements Implemented
No Duplicate Accounts:

generateAccountNumber() ensures unique account numbers by checking existing accounts.\
Example: Account numbers increment sequentially (1000, 1001, ...).
Data Persistence:

Binary File Handling:
saveToFile(): Serializes all accounts and transactions to bank_data.dat.
loadFromFile(): Deserializes data on program startup (called in BankManager constructor).
Automatic Save/Load:
Constructor (BankManager()) loads existing data.
Destructor (~BankManager()) saves data on exit.
Transaction Management:
addTransaction() logs every deposit/withdraw/transfer with:
- Unique ID (generateTransactionId()).
- Timestamp (time(nullptr)).
- Type (TransactionType enum: DEPOSIT, WITHDRAW, TRANSFER).
Modular Design:

Separate Files:
banking.h: Header with structures (Account, Transaction) and class declaration.
accounts.cpp: Account creation, number generation, and search.
file_operations.cpp: Binary I/O for persistence.
main.cpp: Menu-driven UI loop.
Deliverables

Source Files:
main.cpp, accounts.cpp, file_operations.cpp, banking.h.
Makefile:
Compiles the project using g++ with flags like -std=c++11.
README.txt:
Instructions to compile (make), run (./bank), and clean (make clean). Data File:
bank_data.dat: Stores all account data in binary format.
Advanced Features

Enum Usage: TransactionType enum class for clear transaction categorization.
Binary Serialization: Efficient storage of vector and nested vector.
RAII: Constructor/destructor automate file I/O (no manual save/load calls needed).
</pre>
