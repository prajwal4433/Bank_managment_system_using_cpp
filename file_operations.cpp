#include "banking.h"

void BankManager::saveToFile()
{
    ofstream outFile(dataFile, ios::binary);
    if(!outFile)
    {
        cerr<<"Error opening file for writing!\n";
        return;
    }

    size_t numAccounts=accounts.size();
    outFile.write(reinterpret_cast<const char*>(&numAccounts), sizeof(numAccounts));

    for(const auto& account : accounts)
    {
        outFile.write(reinterpret_cast<const char*>(&account.number), sizeof(account.number));
        
        size_t nameSize=account.name.size();
        outFile.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
        outFile.write(account.name.c_str(), nameSize);
        
        outFile.write(reinterpret_cast<const char*>(&account.balance), sizeof(account.balance));
        
        size_t contactSize=account.contact.size();
        outFile.write(reinterpret_cast<const char*>(&contactSize), sizeof(contactSize));
        outFile.write(account.contact.c_str(), contactSize);

        size_t txnCount=account.transactions.size();
        outFile.write(reinterpret_cast<const char*>(&txnCount), sizeof(txnCount));
        
        for(const auto& txn : account.transactions)
	{
            outFile.write(reinterpret_cast<const char*>(&txn.id), sizeof(txn.id));
            outFile.write(reinterpret_cast<const char*>(&txn.timestamp), sizeof(txn.timestamp));
            outFile.write(reinterpret_cast<const char*>(&txn.type), sizeof(txn.type));
            outFile.write(reinterpret_cast<const char*>(&txn.amount), sizeof(txn.amount));
            
            size_t descSize = txn.description.size();
            outFile.write(reinterpret_cast<const char*>(&descSize), sizeof(descSize));
            outFile.write(txn.description.c_str(), descSize);
        }
    }

    cout<<"Data saved successfully!\n";
}

void BankManager::loadFromFile()
{
    ifstream inFile(dataFile, ios::binary);
    if(!inFile)
    {
        cerr<<"No existing data file found. Starting with empty database.\n";
        return;
    }

    accounts.clear();

    size_t numAccounts;
    inFile.read(reinterpret_cast<char*>(&numAccounts), sizeof(numAccounts));

    for(size_t i=0; i<numAccounts; ++i) 
    {
        Account account;
        
        inFile.read(reinterpret_cast<char*>(&account.number), sizeof(account.number));
        
        size_t nameSize;
        inFile.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
        account.name.resize(nameSize);
        inFile.read(&account.name[0], nameSize);
        
        inFile.read(reinterpret_cast<char*>(&account.balance), sizeof(account.balance));
        
        size_t contactSize;
        inFile.read(reinterpret_cast<char*>(&contactSize), sizeof(contactSize));
        account.contact.resize(contactSize);
        inFile.read(&account.contact[0], contactSize);

        size_t txnCount;
        inFile.read(reinterpret_cast<char*>(&txnCount), sizeof(txnCount));
        account.transactions.resize(txnCount);
        
        for(auto& txn : account.transactions) 
	{
            inFile.read(reinterpret_cast<char*>(&txn.id), sizeof(txn.id));
            inFile.read(reinterpret_cast<char*>(&txn.timestamp), sizeof(txn.timestamp));
            inFile.read(reinterpret_cast<char*>(&txn.type), sizeof(txn.type));
            inFile.read(reinterpret_cast<char*>(&txn.amount), sizeof(txn.amount));
            
            size_t descSize;
            inFile.read(reinterpret_cast<char*>(&descSize), sizeof(descSize));
            txn.description.resize(descSize);
            inFile.read(&txn.description[0], descSize);
        }

        accounts.push_back(account);
    }

    cout<<"Data loaded successfully! Loaded "<<accounts.size()<<" accounts.\n";
}
