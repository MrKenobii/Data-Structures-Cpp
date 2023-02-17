#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Account{
  private:
	string name;
	string password;
	double balance;
  public:
	Account();
	Account(string, string);
	string get_name();
	string get_password();
	double get_balance();
	void set_name(string);
	void set_password(string);
	void set_balance(double);
};

class Bank{
  private:
	vector<Account> accounts;
  public:
	Bank();
	bool contains(string,string);
	bool create_account();
	bool deposit_money();
	bool withdraw_money();
	void print_account();
	int find_account(string,string);
    bool delete_account();
    bool get_the_balance(string,string);
};

Account::Account()
{
	name = "";
	password = "";
	balance = 0.0;
}

Account::Account(string acc_name, string acc_password)
{
	name = acc_name;
	password = acc_password;
	balance = 0.0;
}

string Account::get_name()
{
	return name;
}

string Account::get_password()
{
	return password;
}

double Account::get_balance()
{
	return balance;
}

void Account::set_name(string acc_name)
{
	name = acc_name;
}

void Account::set_password(string acc_password)
{
	password = acc_password;
}

void Account::set_balance(double acc_balance)
{
	balance = acc_balance;
}

Bank::Bank()
{
	accounts.reserve(1);
}

bool Bank::create_account()
{
	bool flag = false;
	string acc_name, acc_password;
	cout<<"Please enter your name and password"<<endl;
    cout<<"Name:";
	cin >> acc_name;
    cout<<"Password:";
    cin>>acc_password;
	if(contains(acc_name,acc_password))
	{
		cout << "This account has already exist!" << endl;
	}
	else
	{   cout<<"Please enter your password again"<<endl;
		cin >> acc_password;
		Account new_acc(acc_name,acc_password);
		accounts.push_back(new_acc);
		cout << "Acount has been added" << endl;
		flag = true;
	}
	return flag;
}

bool Bank::contains(string acc_name,string acc_pass)
{
	bool flag = false;
	for(int i = 0; i < accounts.size(); i++)
	{
		if(accounts[i].get_name() == acc_name && accounts[i].get_password()==acc_pass)
		{
			flag = true;
			break;
		}
	}
	return flag;
}

bool Bank::deposit_money()
{
	string acc_name,acc_pass;
    cout << "Please enter your name" << endl;
	cin >> acc_name;
    cout << "Please enter your password:"<<endl;
    cin >> acc_pass;
	if(contains(acc_name,acc_pass))
	{
		int index = find_account(acc_name,acc_pass);
		
		if(accounts[index].get_password() == acc_pass)
		{
			double amount;
			cout << "Please enter the amount of money" << endl;
			cin >> amount;
			accounts[index].set_balance(accounts[index].get_balance() + amount);
			return true;
		}
		else
		{
			cout << "Invalid password!" << endl;
			return false;
		}
	}
	else{
		cout << "Account has not been found" << endl;
		return false;
	}
}

bool Bank::withdraw_money()
{
	cout << "Please enter your name" << endl;
	string acc_name;
	cin >> acc_name;
    cout << "Please enter your password:"<<endl;
    string acc_pass;
    cin >> acc_pass;
	if(contains(acc_name,acc_pass))
	{
		int index = find_account(acc_name,acc_pass);
		
		if(accounts[index].get_password() == acc_pass)
		{
			double amount;
			cout << "Please enter the amount of money" << endl;
			cin >> amount;
			if(accounts[index].get_balance() >= amount)
			{
				accounts[index].set_balance(accounts[index].get_balance() - amount);
				return true;
			}
			else
			{
				cout << "The account does not have enough money" << endl;
				return false;
			}
		}
		else
		{
			cout << "Invalid password." << endl;
			return false;
		}
	}
	else{
		cout << "There is no accounts such that" << endl;
		return false;
	}
}

void Bank::print_account()
{
	int i = 0;
	for(i = 0; i < accounts.size(); i++)
	{
		cout << accounts[i].get_name() + " Money: " << accounts[i].get_balance() << endl;
	}
}

int Bank::find_account(string acc_name,string acc_pass)
{
	if(contains(acc_name,acc_pass))
	{
		int index;
		for(index = 0; index < accounts.size(); index++)
		{
			if(acc_name == accounts[index].get_name() && acc_pass==accounts[index].get_password())
			{
                cout<<"Name:"<<acc_name<<"\nPassword:"<<acc_pass<<endl;
				return index;
			}
		}
	}
	else return -1;
}	
bool Bank::get_the_balance(string acc_name,string acc_pass){
    bool flag=false;
    if(contains(acc_name,acc_pass)){
     int index;
     for(index=0; index<accounts.size();index++){
         if(acc_name==accounts[index].get_name() && acc_pass==accounts[index].get_password()){
             cout<<"Balance:"<<accounts[index].get_balance()<<endl;
             flag=true;
         }
     }
     if(!flag){
         cout<<"Account has not been found"<<endl;
     }
 }
 return flag;
}
bool Bank::delete_account(){
    bool flag=false;
    string acc_name,acc_pass;
    char type;
    cout<<"Please Enter your name"<<endl;
    cin>>acc_name;
    cout<<"Please enter your password"<<endl;
    cin>>acc_pass;
    if(contains(acc_name,acc_pass)){
        
        cout<<"Please type 'y' to delete account"<<endl;
        cin>>type;
        if(type=='y'){
            cout<<"Please enter your password again"<<endl;
            cin>>acc_pass;
            for(int index=0;index<accounts.size();index++){
                if(acc_name==accounts[index].get_name() && acc_pass==accounts[index].get_password()){
                    accounts.erase(accounts.begin()+index);
                }
            }
            cout<<"Account has been deleted correctly."<<endl;
            flag= true;
            }
        else if(type!='y'){
          cout<<"Please enter a valid letter"<<endl;
          
        }
    }
    else{
        cout<<"There is already no such a account!"<<endl;
    }
    return flag;
    
    
}

int main()
{
	bool cnt=true;
    int cse;
    string acc_name,acc_pass;
    Bank n_bank;
    cout<<"-----------Welcome to our ATM-----------"<<endl;
    while(cnt){
    cout<<"Type 1 to create account"<<endl;
    cout<<"Type 2 to find account"<<endl;
    cout<<"Type 3 to deposit money"<<endl;
    cout<<"Type 4 to withdraw money"<<endl;
    cout<<"Type 5 to delete account"<<endl;
    cout<<"Type 6 to print all accounts"<<endl;
    cout<<"Type 7 to get the balance"<<endl;
    cout<<"Type 8 to exit from system"<<endl;
    cout<<"Case:";
    cin>>cse;
    switch(cse){
        case 1:{
            n_bank.create_account();
            break;
        }
        case 2:{
            cout<<"Enter name and password"<<endl;
            cout<<"Name:";
            cin>>acc_name;
            cout<<"Password:";
            cin>>acc_pass;
            n_bank.find_account(acc_name,acc_pass);
            break;
        }
        case 3:{
            n_bank.deposit_money();
            break;
        }
        case 4:{
          n_bank.withdraw_money();
          break;
        }
        case 5:{
          n_bank.delete_account();
          break;
        }
        case 6:{
          n_bank.print_account();
          break;
        }
        case 7:{
          cout<<"Please enter your name and password"<<endl;
          cin>>acc_name>>acc_pass;
          n_bank.get_the_balance(acc_name,acc_pass);
          break;
        }
        case 8:{
            cout<<"Exiting from the atm\nHave a good day"<<endl;
            cnt=false;
            break;
        }
        default:
        cout<<"Please enter a valid integer"<<endl;
        break;
    }
    }
    return 0;
}