#ifndef BANKING_H
#define BANKING_H

#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<fstream>
#include<cstdint>
#include<algorithm>
#include<limits>
#include<iomanip>

using namespace std;

enum class TransactionType{DEPOSIT, WITHDRAW, TRANSFER};

struct Transaction
{
    uint32_t id;
    time_t timestamp;
    TransactionType type;
    double amount;
    string description;
};

struct Account 
{
    uint32_t number;
    string name;
    double balance;
    vector<Transaction> transactions;
    string contact;
};

class BankManager
{
private:
    vector<Account> accounts;
    string dataFile="bank_data.dat";

    uint32_t generateAccountNumber();
    uint32_t generateTransactionId();
    void addTransaction(Account& account, TransactionType type, double amount, const string& desc="");
    Account* findAccount(uint32_t accountNumber);
    const Account* findAccount(uint32_t accountNumber) const;

public:
    BankManager();
    ~BankManager();

    void createAccount();
    void deposit();
    void withdraw();
    void transfer();
    void displayBalance() const;
    void displayTransactionHistory() const;
    void displayAllAccounts() const;
    void searchAccount() const;
    void saveToFile();
    void loadFromFile();
};

#endif
