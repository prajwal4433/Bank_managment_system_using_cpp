#include "banking.h"

uint32_t BankManager::generateAccountNumber()
{
    static uint32_t nextAccountNumber=1000;
    while(true)
    {
        bool exists=false;
        for(const auto& acc:accounts)
	{
            if(acc.number==nextAccountNumber)
	    {
                exists=true;
                break;
            }
        }
        if(!exists) 
		return nextAccountNumber;
        nextAccountNumber++;
    }
}

uint32_t BankManager::generateTransactionId()
{
    static uint32_t nextTransactionId=1;
    return nextTransactionId++;
}

void BankManager::addTransaction(Account& account, TransactionType type, double amount, const string& desc)
{
    Transaction txn;
    txn.id=generateTransactionId();
    txn.timestamp=time(nullptr);
    txn.type=type;
    txn.amount=amount;
    txn.description=desc;
    account.transactions.push_back(txn);
}

Account* BankManager::findAccount(uint32_t accountNumber)
{
    for(auto& acc:accounts)
    {
        if(acc.number==accountNumber) 
	{
            return &acc;
        }
    }
    return nullptr;
}

const Account* BankManager::findAccount(uint32_t accountNumber) const
{
    for(const auto& acc:accounts)
    {
        if(acc.number==accountNumber)
	{
            return &acc;
        }
    }
    return nullptr;
}

BankManager::BankManager()
{
    loadFromFile();
}

BankManager::~BankManager()
{
    saveToFile();
}

void BankManager::createAccount()
{
    Account newAccount;
    string name, contact;

    cout<<"\nEnter account holder name: ";
    getline(cin, name);

    cout<<"Enter contact number: ";
    getline(cin, contact);

    newAccount.number=generateAccountNumber();
    newAccount.name=name;
    newAccount.balance=0.0;
    newAccount.contact=contact;

    accounts.push_back(newAccount);

    cout<<"\nAccount created successfully!\n";
    cout<<"Account Number: "<<newAccount.number<<"\n";
}
