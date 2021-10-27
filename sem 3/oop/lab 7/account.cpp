//c++ program to implement inheritance
//cs20b1119
//Dheeraj kumar

#include <iostream>
using namespace std;

//account class (base class)
class ACCOUNT
{
    protected:
        double accountBalance;
        int accountNumber;
        
    public:
//parameterised constructor for initialising balance and account number
        ACCOUNT( int number , double AccBalance=0)        
        {
            accountNumber = number;
            if(AccBalance >=0)
            {
                this->accountBalance = AccBalance;
            }
            else        
            {
                this->accountBalance = 0;
                cout << "give initial balance greater than 0";
            }
        }
//function to credit money to the present balance
        void credit (double money)
        {
            this->accountBalance = this->accountBalance + money;
        }
//function to debit money from the account
        double debit (double money)
        {
            if(accountBalance >= money)
            {
                this->accountBalance = this->accountBalance - money;
                return this->accountBalance;
            }
            
            else       
            {
                cout << "Debit amount is greater than account balance.";
                return -1;
            }
        }
// function to return balance of the account.
        double getBalance()  		
        {
            return this->accountBalance;
        }
//function to return account number
        int getAccountNumber()
        {
            return accountNumber;
        }
};


// savings account class (derived class) under ACCOUNT class (base class)

class savingsAccount : public ACCOUNT
{
    private:
        double interestRate;
    public:
//parametrised constructor for intialising rate of interest
        
        savingsAccount (int number ,double AccBalance , double rate) : ACCOUNT(number , AccBalance)  
        { 
            this->interestRate = rate;
        }
//function to calculate interest on total amount
        double calculateInterest()
        {
            return (this->accountBalance)*(this->interestRate)/100;
        }
//function to return interest amount + account balance 
        double calculateInterest(double amount)
        {
            return this->accountBalance + amount;
        }
 //function to set the interest rate
        void setInterest(double rate)
        {
            this->interestRate = rate;
        }
};

// checking account class (derived class) under ACCOUNT class (base class)
class checkingAccount : public ACCOUNT
{
    private:
        double transactionFee;
    public:
//parameterized constructor to initialise transaction charge    
        checkingAccount(int number , double accBalance , double fee) : ACCOUNT(number, accBalance)      
        {
            this->transactionFee = fee;
        }
 //function to debit from checking account including member function from base class
        void transaction(double accBalance , double fee , double money)
        {
            double balance = debit (money);
            if (balance >transactionFee )        
            {
                this->accountBalance = balance - this->transactionFee;
            }
            else
            {
                cout << " transaction failure (insufficient money) ";
                this->accountBalance = balance + money ;        // setting back the withdraw amount to the account balance
            }
        }
 //function to set charging fee on transaction 
        void setCharge(double fee)
        {
            this->transactionFee = fee;
        }
        
 //function to return charging fee 
        double getCharge()
        {
            return this->transactionFee;
        }
        
};

//linked list to store the data of the savings accounts.
class nodeSA
{
    private:
        savingsAccount *var;
        nodeSA* next = nullptr ;
    public:
        nodeSA(savingsAccount *head)     //parameterized constructor header node of the list
        {
            var = head ;
            next = nullptr ;
        }
 // function to insert node 
        void getData(savingsAccount *head)
        {
            nodeSA* ptr;      //newnode to insert
            ptr=new nodeSA(head);
            ptr->var = head;
            ptr->next = NULL;
             
            this->next = ptr ;     //adding newNode to the list if list is empty
        }
 //returning next
        nodeSA* getNext()
        {
            return next;
        }
 // getting account number if present
        savingsAccount* getAcc(int accountNum)
        {
            nodeSA* temp = this;
            while(temp != nullptr)
            {
                if(temp->var->getAccountNumber() == accountNum){
                    return temp->getAccount();
                }
                temp=temp->next;
            }
            cout << "NOT FOUND!!!\n";
            return nullptr;
                
        }
 //returning account
        savingsAccount* getAccount()
        {
            return this->var ;
        }
};
//linked list to store the data of the checkings accounts.
class nodeCA
{
    private:
        checkingAccount *var;
        nodeCA* next = nullptr ;
    public:
//parameteized constructor and header node of the list
        nodeCA(checkingAccount* head)        
        {
            var = head ;
            next = nullptr ;
        }
 // function to insert node  
        void getData(checkingAccount *head)
        {
            nodeCA* ptr;      //newnode to insert
            ptr=new nodeCA(head);
            ptr->var = head;
            ptr->next = NULL;
           
            this->next = ptr ;     //adding newNode to the list  if the ist is empty
        }
 //returning next
        nodeCA* getNext()
        {
            return next;
        }
 // getting account
        checkingAccount* getAcc(int accountNum)
        {
            nodeCA* temp = this;
            while(temp)
            {
                if(temp->var->getAccountNumber() == accountNum){
                    return temp->getAccount();
                    break;
                }
                temp=temp ->next;
            }
            cout << "NOT FOUND!!!";
            return NULL;
        }
  //returning account
        checkingAccount* getAccount()
        {
            return this->var ;
        }
};

int main()
{
    int choices ,i=0 ,n=0, a;
    double amount, rate,charge,money , accNum ;
    nodeSA* savingList=NULL;                //savings list
    nodeCA* checkingList=NULL;              //checking list
    ACCOUNT * user=NULL;
    savingsAccount* user1=NULL;
    checkingAccount* user2=NULL;
    while(1)
    {
       cout<<"1. Open Account (Savings or Checking Account) \n2. Credit (Savings or Checking Account) \n3. Debit (Savings or Checking Account)\n4. Change/Update Interest rate (Savings Account)\n5. Calculate Interest (Savings Account - Print)\n6. Calculate and Update Interest (Savings Account - Credit)\n7. Change/Update Fee Amount (Checking Account\n8. Print Checking Fee (Checking Account)\n9. Transact and Update (Checking Account - Debit)\n10. Exit\n";
        cout << "Enter the choices : ";
        cin >> choices;
        switch(choices)
        {
            case 1:
            {
                
                cout << "\n 1. savings Account \n 2. checking list\n ";
                cin >> a;

                while(1)
                    {
                        cout << "Enter the Account Number : ";   //asking the user to give account number
                        cin >> accNum;
                        if(accNum > 0.0 )
                        {
                            break;
                        }
                        else
                        {
                            cout << "Account number should br unique and greater than 0 !!!\n";
                        }
                    }
                
                while(1)
                    {
                        cout << "Enter Account Balance : ";     //asking the userto give accoun to balance
                        cin >> amount;
                        if(amount >= 0.0 )
                        {
                            break;
                        }
                        else
                        {
                            cout << "Account Balance(initial) should not be negative !!!\n";
                        }
                    }

                if(a == 1){        //user decided to open savings account
                    while(1)                
                    {
                        cout << "Enter the interest rate : ";
                        cin >> rate;
                        
                        if(rate >= 0.0 && rate <= 100.0)
                        {
                            break;
                        }
                        else
                        {
                            cout << "interest rate  should be in the range of 1-100 !!!\n";
                        }
                    }
                    //creating first savings account
                    if(i==0)
                    {                   // header node of the savingsAccount
                        user1 = new savingsAccount(accNum, amount , rate);
                        savingList = new nodeSA(user1);     //adding node to the list
                        i++;
                    }
                    else
                    {                   
                        savingsAccount* node = new savingsAccount(accNum, amount , rate);
                        nodeSA* temp = savingList;
                        
                        while(temp->getNext()!=nullptr)     //loop until it reach the last node
                        {
                            temp = temp -> getNext();
                        }
                        
                        temp->getData(node);     //adding the node to the list
                    }
                }
                else if(a == 2){       //user decided to create a checking account.
                    while(1)
                    {
                        cout << "Enter the fee charge : ";
                        cin >> charge;
                        if(charge > 0.0)
                        {
                            break;
                        }
                        else
                        {
                            cout << "fee charge amount should be positive !!!\n";
                        }
                    }
                    if(n==0)
                    {
                        user2 = new checkingAccount(accNum, amount , charge);
                        checkingList = new nodeCA(user2);
                        n++;
                    }
                    else
                    {
                        checkingAccount* node = new checkingAccount(accNum, amount , rate);
                        nodeCA* temp = checkingList;
                        
                        while(temp->getNext()!=nullptr)         //loop until it reach the last node
                        {
                            temp = temp -> getNext();
                        }
                        temp->getData(node);         //adding the node to the list
                    }
                }
                break;
            }
            case 2:
            {
                
                cout << "\n 1. savings Account \n 2. checking list\n ";
                cin >> a;
                
                cout << "Enter the Account number to credit : ";     //asking for account number.
                cin >> accNum;
                while(1)                    
                {
                    cout << "Enter the money to credit : ";
                    cin >> money;
                    if(money >= 0.0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "credit amount should be positive !!!\n";
                    }
                }
                if(a==1)       //if the user type savings account
                {
                    savingsAccount* node = savingList->getAcc(accNum);
                    
                    if(node != nullptr)
                    {
                        node->credit(money);
                     }
                }
                else if(a==2)      //if the user type checkings account
                {
                    checkingAccount* node = checkingList->getAcc(accNum); 
                          
                    if(node != nullptr)
                    {
                        node->credit(money);
                     }
                }
                break;
            }
            case 3:
            {
                
                cout << "\n 1. savings Account \n 2. checking list \n";
                cin >> a;
                
                cout << "Enter the Account number  : ";
                cin >> accNum;
                while(1)        
                {
                    cout << "Enter the money to debit : ";
                    cin >> money;
                    if(money > 0.0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "debit amount should be positive !!!\n";
                        cin.clear();
                    }
                }
                if(a==1)       //if the user type savings account
                {
                    savingsAccount* node = savingList->getAcc(accNum); 
                         
                    if(node != nullptr)
                    {
                        node->debit(money);
                     }
                }
                else if(a==2)      //if the user type checkings account
                {
                    checkingAccount* node = checkingList->getAcc(accNum);  
                         
                    if(node != nullptr)
                    {
                        node->transaction(node->getBalance() , node->getCharge() , money);
                     }   
                }
                break;
            }
            case 4:
            {
                cout << "Enter the Account number   : ";
                cin >> accNum;
                while(1)            
                    {
                        cout << "Enter the interest rate : ";
                        cin >> rate;
                        if(rate > 0.0 && rate<100.0)
                        {
                            break;
                        }
                        else
                        {
                            cout << "interest rate  should be in the range of 1-100 !!!\n";
                        }
                    }
                savingsAccount* node = savingList->getAcc(accNum);      
                if(node != nullptr)
                {
                    node->setInterest(rate);            //setting the interest
                    }
                break;
            }
            case 5:
            {
                cout << "Enter the Account number   : ";
                cin >> accNum;
                savingsAccount* node = savingList->getAcc(accNum);     //getting the account
                
                if(node != nullptr)
                {
                    double sample = node->calculateInterest();          //calculating the interest
                    cout << "Interest of the account " << accNum << " is $" << sample<<endl;
                }
                break;
            }
            case 6:
            {
                cout << "Enter the Account number   : ";
                cin >> accNum;
                savingsAccount* node = savingList->getAcc(accNum);     //getting the account
                
                if(node != nullptr)
                {
                    double sample = node->calculateInterest();
                    cout << "Account balance + Interest of the account " << accNum << " is $" << node->calculateInterest(sample)<<endl;
                }
                break;
            }
            case 7:
            {
                cout << "Enter the Account number   : ";
                cin >> accNum;
                while(1)             
                    {
                        cout << "Enter the fee charge : ";
                        cin >> charge;
                        if(charge > 0.0)
                        {
                            break;
                        }
                        else
                        {
                            cout << "fee charge amount should be positive !!!\n";
                        }
                    }
                checkingAccount* node = checkingList->getAcc(accNum); 
                          
                if(node != nullptr)
                {
                    node->setCharge(charge);            //setting the charge
                    }
                break;
            }
            case 8:
            {
                cout << "Enter the Account number to check the fee charge : ";
                cin >> accNum;
                checkingAccount* node = checkingList->getAcc(accNum);
                
                if(node != nullptr)
                {
                    cout << "Fee charge of the account " << accNum << " is $" << node->getCharge();
                    }
                break;
            }
            case 9:
            {   
                cout << "Enter the Account number to  debit : ";
                cin >> accNum;
                while(1)                
                {
                    cout << "Enter the money to debit : ";
                    cin >> money;
                    if(money > 0.0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "debit amount should be positive !!!\n";
                    }
                }
                checkingAccount* node = checkingList->getAcc(accNum);          //getting the account
                
                    if(node != nullptr)
                    {
                        node->transaction(node->getBalance() , node->getCharge() , money);   //transacting the amount
                        }
                break;
            }
            case 10:
                exit (0);
            default:
                cout << "wrong choive ....TRY AGAIN !!!\insertDat";
        }
    }
    return 0;
}

