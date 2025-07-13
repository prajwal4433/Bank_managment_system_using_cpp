#include "banking.h"

void BankManager::displayAllAccounts() const 
{
    if(accounts.empty()) 
    {
        cout<<"No accounts found!\n";
        return;
    }

    cout<<"\nAll Accounts:\n";
    cout<<setw(15)<<"Account Number"<<" | "
         <<setw(20)<<"Name"<<" | "
         <<setw(15)<<"Balance"<<" | "
         <<setw(15)<<"Contact"<<"\n";

    for(const auto& account:accounts) 
    {
        cout<<setw(15)<<account.number<<" | "
            <<setw(20)<<account.name<<" | "
            <<setw(15)<<account.balance<<" | "
            <<setw(15)<<account.contact<<"\n";
    }
}

void BankManager::searchAccount() const 
{
    uint32_t accountNumber;
    cout<<"Enter account number to search: ";
    cin>>accountNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    const Account* account=findAccount(accountNumber);
    if(!account)
    {
        cout<<"Account not found!\n";
        return;
    }

    cout<<"\nAccount Details:\n";
    cout<<"Account Number: "<<account->number<<"\n";
    cout<<"Account Holder: "<<account->name<<"\n";
    cout<<"Balance: "<<account->balance<<"\n";
    cout<<"Contact: "<<account->contact<<"\n";
    cout<<"Transaction Count: "<<account->transactions.size()<<"\n";
}
