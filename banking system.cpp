#include<iostream>
#include<fstream>
//#include<process>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<windows.h>

using namespace std;

class Menus
{
public:
    void showmenu();
private:
    void closemenu();
};

class dispRecords
{
public:
    int AccountNumber;
    char name[50], address[50];
    float intBalance;
    void addDetails();
    void displayCustomers();
    void deleteAccount();
    void updateBalance();
    void updateCustomer();
    int lastAccount();
    int accountExists(int retrieve_AccNo);
    char *getName(int retrieve_AccNo);
    char *getAddress(int retrieve_AccNo);
    float getBalance(int retrieve_AccNo);
    int getRecord(int retrieve_AccNo);
    void display(int retrieve_AccNo);
    void displayList();
};

class accountTransactions
{
public:
    int AccountNumber;
    char trantype[10];
    int dday, mmonth, yyear;
    char transactions;
    float intInterest, intAmount, intBalance;
    static float calcInterest;
    void showInterest();
    void new_account();
    void closeAccount();
    void display_account();
    void transaction();
    void addDetails();
    void deleteAccount();
    int dateDiffer();
    float getInterest();
    void display();
    void showAccount();
};

void Menus :: showmenu()
{
    char choice;
    while (1)
    {
        //clrscr();
        cout<< "\n --Welcome to Banking System Application-- \n" << endl;
        cout<< "***********************************************" << endl;
        cout<< "        choose from options\n" << endl;
        cout<< "        1:Open an Account" << endl;
        cout<< "        2:View an Account" << endl;
        cout<< "        3:Show all Accounts" << endl;
        cout<< "        4:Make a transaction" << endl;
        cout<< "        5:Calculate Interest" << endl;
        cout<< "        6:Close an Account" << endl;
        cout<< "        7:Exit" << endl;
        cout<< "        Please select a choice :" << choice <<endl;
        if (choice == '1')
        {
            accountTransactions objat;
            objat.new_account();
        }
        else if (choice == '2')
        {
            accountTransactions objat;
            objat.display_account();
        }
        else if (choice == '3')
        {
            dispRecords newRec;
            newRec.displayCustomers();
        }
        else if (choice == '4')
        {
            accountTransactions objat;
            objat.transaction();
        }
        else if (choice == '5')
        {
            accountTransactions objat;
            objat.showInterest();
        }
        else if (choice == '6')
        {
            closemenu();
        }
        else if (choice == '7')
        {
            cout<< "        Thanks for using this application. Please press any key to exit" << endl;
            getchar();
            break;
        }
    }
}

void Menus :: closemenu()
{
    char choice;
    while (1)
    {
        //clrscr();
        cout<< "\t -Close Menu" << endl;
        cout<< "\t ******************" << endl;
        cout<< "\t 1:Close/Delete an account" << endl;
        cout<< "\t 0:Exit from this menu" << endl;
        cout<< "\t Select a choice" << choice << endl;
        if (choice == '1')
        {
            accountTransactions bt;
            bt.closeAccount();
            break;
        }
        else if (choice == '0')
        {
            cout<< "\n You have entered 0 to go back to the previous Menu." << endl;
            getchar();
            break;
        }
    }
}

int dispRecords :: lastAccount()
{
    fstream filename;
    filename.open("newrecords.dat", ios::in);
    filename.seekg(0,ios::beg);
    int count=0;
    while (filename.read((char *)this,sizeof(dispRecords)))
    {
        count = AccountNumber;
    }
    filename.close();
    return count;
}

int dispRecords :: getRecord(int retrieve_AccNo)
{
    fstream filename;
    filename.open("newrecords.dat", ios::in);
    filename.seekg(0, ios::beg);
    int count=0;
    while (filename.read((char *)this,sizeof(dispRecords)))
    {
        count++;
        if (retrieve_AccNo == AccountNumber)
            break;
    }
    filename.close();
    return count;
}

void dispRecords :: display(int retrieve_AccNo)
{
    int record;
    record = getRecord(retrieve_AccNo);
    fstream filename;
    filename.open("newrecords.dat", ios::in);
    filename.seekg(0,ios::end);
    int location;
    location = (record) * sizeof(dispRecords);
    filename.seekp(location);
    while (filename.read((char *)this, sizeof(dispRecords)))
    {
        if (retrieve_AccNo == AccountNumber)
        {
            cout<< "\n  ACCOUNT NO. :" << AccountNumber << endl;
            cout<< "  Name :" << name << endl;
            cout<< "  Address :" << address<< endl;
            cout<< " Balance :" << intBalance<< endl;
        }
    }
    filename.close();
}

char *dispRecords :: getName(int retrieve_AccNo)
{
    fstream filename;
    filename.open("newrecords.dat", ios::in);
    filename.seekg(0, ios::beg);
    char retrieve_CustName[30];
    while (filename.read((char *)this,sizeof(dispRecords)))
    {
        if (AccountNumber == retrieve_AccNo)
            strcpy(retrieve_CustName,name);
    }
    filename.close();
    return retrieve_CustName;
}

char *dispRecords :: getAddress(int retrieve_AccNo)
{
    fstream filename;
    filename.open("newrecords.dat", ios::in);
    filename.seekg(0, ios::beg);
    char retrieve_Address[30];
    while (filename.read((char *)this,sizeof(dispRecords)))
    {
        if (AccountNumber == retrieve_AccNo)
            strcpy(retrieve_Address,address);
    }
    filename.close();
    return retrieve_Address;
}

float dispRecords :: getBalance(int retrieve_AccNo)
{
    fstream filename;
    filename.open("newrecords.dat", ios::in);
    filename.seekg(0, ios::beg);
    float iBalance;
    while (filename.read((char *)this,sizeof(dispRecords)))
    {
        if (AccountNumber == retrieve_AccNo)
            iBalance = intBalance;
    }
    filename.close();
    return iBalance;
}

int dispRecords :: accountExists(int retrieve_AccNo)
{
    fstream filename;
    filename.open("newrecords.dat", ios::in);
    filename.seekg(0, ios::beg);
    float count=0;
    while (filename.read((char *)this,sizeof(dispRecords)))
    {
        if (AccountNumber == retrieve_AccNo)
        {
            count=1;
            break;
        }
    }
    filename.close();
    return count;
}

void dispRecords :: displayList()
{
    cout << "\n" << endl;
    int day1, month1 , year1;
    struct date dateval;
    getdate(&dateval);
    day1 = dateval.da_day;
    month1 = dateval.da_mon;
    year1 = dateval.da_year;
    cout << "\n Date: " << day1 << "/" << month1 << "/" << year1 <<endl;
    cout << setw(80) <<"----------------------------------------\n";
    cout << setw(23) <<"ACCOUNT NO.";
    cout << setw(23) <<"NAME OF PERSON";
    cout << setw(23) <<"BALANCE\n";
    cout << setw(80) <<"----------------------------------------\n";
}

void dispRecords :: displayCustomers()
{
    int len1;
    int row=8, check;
    fstream filename;

    FILE * pFile;
    pFile = fopen("newrecords.dat", "r");
    if (pFile == NULL)
    {
        cout << "\n No.Account exists. Please go back to the previous menu. \n";
        getchar();
        return;
        //fclose (pFile);
    }
    else
    {
        displayList();
        filename.open("newrecords.dat",ios::in);
        filename.seekg(0,ios::beg);
        while (filename.read((char *)this,sizeof(dispRecords)))
        {
            check=0;

            cout.fill(' ');
            cout <<setw(20);
            cout.setf(ios::right,ios::adjustfield);
            cout<< AccountNumber;
            cout.fill(' ');
            cout << setw(25);
            cout.setf(ios::internal,ios::adjustfield);
            cout
        }
    }
}
