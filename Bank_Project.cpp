#include<iostream>
#include<string>

#define MAX_BRANCH 3
#define MAX_MANAGER 1
#define MAX_ACCOUNTANT 2
#define MAX_ACCOUNT_HOLDER 30

using namespace std;

class  Account_Holder_Info{
    private:
        string name;
        unsigned int ac_number;
        float balance;
        static unsigned int count;
    public:
        Account_Holder_Info():balance(500){
            count++;
            ac_number=count;
        }

        Account_Holder_Info(float bl):balance(bl){
        }

        ~Account_Holder_Info(){
        }
        void get_ac_name();
        void get_ac_balance();
        int access_A_H_count() const;
        void withdraw_info();
        void deposit_info();
        string access_account_holder_name() const;
        int access_account_holder_ac_num() const;
        float search(Account_Holder_Info ac[], string);
        float search(Account_Holder_Info ac[], int);
        float access_account_holder_balance() const;
        void show_ac_number_balance_with_name() const;
        void show_ac_balance() const;
        void interest();
        float operator*(float i){
            return balance*i;
        }
};

class Employee_Info{
    protected:
        float bonus;
    public:
        void calculate_bonus(Account_Holder_Info ac[], int, int);
        void show_employee_bonus() const;
};

class Accountant:public Employee_Info{
};

class Manager:public Employee_Info{
    public:
        void calculate_bonus(Account_Holder_Info ac[], int, int);
};

class Branch{
    private:
        Manager manager[MAX_MANAGER];
        Accountant accountant[MAX_ACCOUNTANT];
    public:
        void create_manager(Account_Holder_Info account_holder[]);
        void create_accountant(Account_Holder_Info account_holder[]);
        void show_manager();
        void show_accountant();
};

unsigned int Account_Holder_Info::count=100;

int Account_Holder_Info::access_A_H_count() const{
    return count;
}

void Account_Holder_Info::get_ac_name(){
    cout<<"Please enter the name: ";
    cin>>name;
}

void Account_Holder_Info::get_ac_balance(){
    cout<<"Please enter balance: ";
    cin>>balance;
}

void Account_Holder_Info::withdraw_info(){
    float withdraw;
    cout<<endl;
    cout<<"Enter Withdraw: ";
    cin>>withdraw;
    if(balance>=withdraw){
        balance=balance-withdraw;
        cout<<ac_number<<" account number's balance is "<<balance<<"tk";
        cout<<endl;
    }
    else{
        cout<<"Sorry "<<ac_number<<" account number can't withdraw money";
        cout<<endl;
    }
}

void Account_Holder_Info::deposit_info(){
    float deposit;
    cout<<endl;
    cout<<"Enter deposit: ";
    cin>>deposit;
    balance=balance+deposit;
    cout<<ac_number<<" account number's balance is "<<balance<<"tk";
    cout<<endl;
}

string Account_Holder_Info::access_account_holder_name() const{
    return name;
}

int Account_Holder_Info::access_account_holder_ac_num() const{
    return ac_number;
}

float Account_Holder_Info::search(Account_Holder_Info ac_name[MAX_ACCOUNT_HOLDER], string name){
    int i;
    for(i=0; i<MAX_ACCOUNT_HOLDER; i++){
        if(name==ac_name[i].access_account_holder_name()){
            return ac_name[i].access_account_holder_balance();
        }
    }
}

float Account_Holder_Info::search(Account_Holder_Info ac_num[MAX_ACCOUNT_HOLDER], int num){
    int i;
    for(i=0; i<MAX_ACCOUNT_HOLDER; i++){
        if(num==ac_num[i].access_account_holder_ac_num()){
            return ac_num[i].access_account_holder_balance();
        }
    }
}

float Account_Holder_Info::access_account_holder_balance() const{
    return balance;
}

void Account_Holder_Info::interest(){
    balance=balance+balance*2.5/100;
}

void Account_Holder_Info::show_ac_number_balance_with_name() const{
    cout<<name<<"'s & "<<ac_number<<" account number's balance is "<<balance<<"tk";
    cout<<endl<<endl;
}

void Account_Holder_Info::show_ac_balance() const{
    cout<<"Your balance is: "<<balance;
    cout<<endl;
}

void Branch::create_manager(Account_Holder_Info account_holder[]){
    int start, stop, i;

    start=0;
    stop=MAX_ACCOUNT_HOLDER/(MAX_BRANCH*MAX_MANAGER);
    for(i=0; i<(MAX_BRANCH*MAX_MANAGER); i++){
        manager[i].calculate_bonus(account_holder, start, stop);
        start=stop;
        stop+=10;
    }
    cout<<endl<<endl;
}

void Branch::create_accountant(Account_Holder_Info account_holder[]){
    int start, stop, i;

    start=0;
    stop=MAX_ACCOUNT_HOLDER/(MAX_BRANCH*MAX_ACCOUNTANT);
    for(i=0; i<(MAX_BRANCH*MAX_ACCOUNTANT); i++){
        accountant[i].calculate_bonus(account_holder, start, stop);
        start=stop;
        stop+=5;
    }
    cout<<endl<<endl;
}

void Branch::show_manager(){
    int i;
    for(i=0; i<(MAX_BRANCH*MAX_MANAGER); i++){
        manager[i].show_employee_bonus();
    }
    cout<<endl<<endl;
}

void Branch::show_accountant(){
    int i;
    for(i=0; i<(MAX_BRANCH*MAX_ACCOUNTANT); i++){
        accountant[i].show_employee_bonus();
    }
    cout<<endl<<endl;
}

void Employee_Info::show_employee_bonus() const{
    cout<<"Employee's bonus is: "<<bonus;
    cout<<endl;
}

void Employee_Info::calculate_bonus(Account_Holder_Info ac[], int i, int j){
    int k;
    for(k=i; k<j; k++){
        bonus=bonus+ac[k]*0.02;
    }
}

void Manager::calculate_bonus(Account_Holder_Info ac[], int i, int j){
    int k;
    for(k=i; k<j; k++){
        bonus=bonus+ac[k]*0.03;
    }
}

int main(){
    Account_Holder_Info account_holder[MAX_ACCOUNT_HOLDER];
    Branch branch[MAX_BRANCH];
    string name;
    float balance;
    int i, j, k, start, stop, num;
    int user;

    for(i=0; i<MAX_ACCOUNT_HOLDER; i++){
        cout<<"If user wants to input balance then press 1 otherwise 0: ";
        cin>>user;
        cout<<endl<<endl<<endl;
        if(user==1){
            account_holder[i].get_ac_balance();
        }
        else if(user==0){
            account_holder[i];
        }
        cout<<endl;
    }

    for(i=0; i<MAX_ACCOUNT_HOLDER; i++){
        account_holder[i].get_ac_name();
    }

    cout<<endl<<endl;

    for(i=0; i<MAX_ACCOUNT_HOLDER; i++){
        account_holder[i].show_ac_number_balance_with_name();
    }

    cout<<endl<<endl;

    for(i=0; i<MAX_ACCOUNT_HOLDER; i++){
        account_holder[i].withdraw_info();
    }

    cout<<endl<<endl;

    for(i=0; i<MAX_ACCOUNT_HOLDER; i++){
        account_holder[i].deposit_info();
    }

    cout<<endl<<endl;

    for(i=0; i<MAX_BRANCH; i++){
        branch[i].create_manager(account_holder);
        branch[i].create_accountant(account_holder);
    }

    for(i=0; i<MAX_BRANCH; i++){
        branch[i].show_manager();
        branch[i].show_accountant();
    }

    cout<<endl<<endl;

    for(i=0; i<MAX_ACCOUNT_HOLDER; i++){
        account_holder[i].interest();
    }

    cout<<endl<<endl;

    for(i=0; i<MAX_ACCOUNT_HOLDER; i++){
        account_holder[i].show_ac_number_balance_with_name();
        account_holder[i].access_A_H_count();
    }

    for(i=0; i<MAX_ACCOUNT_HOLDER; i++){
        cout<<"If user wants to check name input 1 or input 0: ";
        cin>>user;
        if(user==1){
            cin>>name;
            cout<<"Balance: "<<account_holder[i].search(account_holder, name);
            cout<<endl<<endl;
        }
        else if(user==0){
            cin>>num;
            cout<<"Balance: "<<account_holder[i].search(account_holder, num);
            cout<<endl<<endl;
        }
    }

    return 0;
}

