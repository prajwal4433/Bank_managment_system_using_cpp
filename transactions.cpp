#include "banking.h"

void BankManager::deposit()
{
    uint32_t accountNumber;
    double amount;

    cout<<"Enter account number: ";
    cin>>accountNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* account=findAccount(accountNumber);
    if(!account)
    {
        cout<<"Account not found!\n";
        return;
    }

    cout<<"Enter amount to deposit: ";
    cin>>amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(amount<=0)
    {
        cout<<"Invalid amount!\n";
        return;
    }

    account->balance+=amount;
    addTransaction(*account, TransactionType::DEPOSIT, amount, "Deposit");
    cout << "Deposit successful. New balance: " << account->balance << "\n";
}

void BankManager::withdraw()
{
    uint32_t accountNumber;
    double amount;

    cout<<"Enter account number: ";
    cin>>accountNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* account=findAccount(accountNumber);
    if(!account) 
    {
        cout<<"Account not found!\n";
        return;
    }

    cout<<"Enter amount to withdraw: ";
    cin>>amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(amount<=0)
    {
        cout<<"Invalid amount!\n";
        return;
    }

    if(amount>account->balance) 
    {
        cout<<"Insufficient funds!\n";
        return;
    }

    account->balance-=amount;
    addTransaction(*account, TransactionType::WITHDRAW, amount, "Withdrawal");
    cout << "Withdrawal successful. New balance: " << account->balance << "\n";
}

void BankManager::transfer()
{
    uint32_t fromAccount, toAccount;
    double amount;

    cout<<"Enter source account number: ";
    cin>>fromAccount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* from=findAccount(fromAccount);
    if(!from)
    {
        cout<<"Source account not found!\n";
        return;
    }

    cout<<"Enter destination account number: ";
    cin>>toAccount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account* to=findAccount(toAccount);
    if(!to) 
    {
        cout<<"Destination account not found!\n";
        return;
    }

    cout<<"Enter amount to transfer: ";
    cin>>amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if(amount<=0)
    {
        cout<<"Invalid amount!\n";
        return;
    }

    if(amount>from->balance)
    {
        cout<<"Insufficient funds!\n";
        return;
    }

    from->balance-=amount;
    to->balance+=amount;

    addTransaction(*from, TransactionType::TRANSFER, amount, "Transfer to " + to_string(toAccount));
    addTransaction(*to, TransactionType::TRANSFER, amount, "Transfer from " + to_string(fromAccount));

    cout<<"Transfer successful.\n";
    cout<<"Source account new balance: "<<from->balance<<"\n";
    cout<<"Destination account new balance: "<<to->balance<<"\n";
}

void BankManager::displayBalance() const 
{
    uint32_t accountNumber;
    cout<<"Enter account number: ";
    cin>>accountNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    const Account* account=findAccount(accountNumber);
    if(!account) 
    {
        cout<<"Account not found!\n";
        return;
    }

    cout<<"Account Balance: "<<account->balance<<"\n";
}

void BankManager::displayTransactionHistory() const 
{
    uint32_t accountNumber;
    cout<<"Enter account number: ";
    cin>>accountNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    const Account* account=findAccount(accountNumber);
    if(!account) 
    {
        cout<<"Account not found!\n";
        return;
    }

    cout<<"\nTransaction History for Account "<<accountNumber<<":\n";
    int count=0;
    for(auto it=account->transactions.rbegin(); it!=account->transactions.rend() && count<5; ++it, ++count)
    {
        string typeStr;
        switch(it->type)
	{
            case TransactionType::DEPOSIT: typeStr="Deposit"; 
					   break;
            case TransactionType::WITHDRAW: typeStr="Withdraw"; 
					    break;
            case TransactionType::TRANSFER: typeStr="Transfer"; 
					    break;
        }
        cout<<"ID: "<<it->id<<" | "
             <<"Type: "<<typeStr<<" | "
             <<"Amount: "<<it->amount<<" | "
             <<"Description: "<<it->description<<" | "
             <<"Time: "<<ctime(&it->timestamp);
    }
}
