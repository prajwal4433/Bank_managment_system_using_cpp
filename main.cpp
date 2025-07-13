#include "banking.h"

void displayMenu()
{
    cout<<"\n------------------MENU--------------------------\n"
         <<"c/C: Create account.\n"
         <<"h/H: Transaction history (last 5).\n"
         <<"w/W: Withdraw amount.\n"
         <<"d/D: Deposit amount.\n"
         <<"b/B: Balance enquiry.\n"
         <<"t/T: Transfer money.\n"
         <<"e/E: Display all accounts details.\n"
         <<"s/S: Save the accounts info in file.\n"
         <<"f/F: Find specific account.\n"
         <<"q/Q: Quit from app\n"
         <<"Enter your choice: ";
}

int main()
{
    BankManager bank;
    char choice;

    do
    {
        displayMenu();
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(tolower(choice))
       	{
            case 'c': bank.createAccount();
		      break;
            case 'h': bank.displayTransactionHistory(); 
		      break;
            case 'w': bank.withdraw(); 
		      break;
            case 'd': bank.deposit(); 
		      break;
            case 'b': bank.displayBalance(); 
		      break;
            case 't': bank.transfer();
		      break;
            case 'e': bank.displayAllAccounts();
		      break;
            case 's': bank.saveToFile(); 
		      break;
            case 'f': bank.searchAccount(); 
		      break;
            case 'q': cout<<"Exiting...\n"; 
		      break;
            default: cout<<"Invalid choice!\n";
        }
    }while(tolower(choice)!='q');

    return 0;
}
