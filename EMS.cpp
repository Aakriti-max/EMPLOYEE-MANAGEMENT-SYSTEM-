#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <fstream>
using namespace std;

class Employee_management//for Data Administrator
{
private:
    char designation[10];
    int age, salary, experience;

public:
	char name[30], id[5];
    virtual void menu();
    void insert();
    void display();
    void search();
    void deleted();
    void addadmin();
    void waitForEnter();
    void modify();
};

class Employee :public Employee_management// for the Employee
{
public:
	virtual void menu();
	void leave();
	void holiday();
	void Tax();
	void policy();
    void modify();
};

void Employee_management::menu() //administrator Menu
{
    int password_user(int); //login declaration
    password_user(1);
    //login screen
    while (true)
    {
        int choice;
        char x; // Options to choose an action
        system("cls");
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t>> EMPLOYE MANAGEMENT SYSTEM <<" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t\t\t 6. Add an Administrator" << endl;
        cout << "\t\t\t\t\t 7. Exit" << endl;
        cout << " Enter Your Choice: "; // Taking the action input
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 1:
            do
            {
                insert();
                cout << "\n\n\t\t\t Add Another Employe Record Press (Y, N) : ";
                cin >> x;
            } while (x == 'y' || x == 'Y');
            waitForEnter();
            break;
        case 2:
            display();
            break;
        case 3:
            modify();
            break;
        case 4:
            search();
            break;
        case 5:
            deleted();
            break;
        case 6:
        	addadmin();
        	break;
        case 7:
            system("cls");
            cout << "\n\t\t\t>> EMPLOYE MANAGEMENT SYSTEM  <<\n\n";
            cout<<"\n\t\tThank You\nThe system will now terminate.";
            Sleep(12);
            exit(0);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
		getch();
    }
}

void Employee::menu()//employee menu
{
	int password_user(int); //login declaration
    password_user(2);
    while (true)
    {
        int choice;
        char x,id[5]; // Options to choose an action
        system("cls");
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t>> EMPLOYE MANAGEMENT SYSTEM <<" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1. Display My Record" << endl;
        cout << "\t\t\t\t\t 2. View Holidays List" << endl;
        cout << "\t\t\t\t\t 3. Leave Application" << endl;
        cout << "\t\t\t\t\t 4. View Company Policy" << endl;
        cout << "\t\t\t\t\t 5. Exit" << endl;
        cout << " Enter Your Choice: "; // Taking the action input
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 1:
            search();
            break;
        case 2:
           	holiday();
            break;
        case 3:
            leave();
            break;
        case 4:
        	policy();
        	break;
        case 5:
            system("cls");
            cout << "\n\t\t\t>> EMPLOYE MANAGEMENT SYSTEM  <<\n\n";
            cout<<"\n\t\tThank You\nThe system will now terminate.";
            Sleep(12);
            exit(0);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
        getch();
    }
}

void Employee_management::insert() // add data of employe
{
    system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Insert Employee Data -------------------------------------------" << endl;
    cout << "\n Enter Name of Employee:-\t";
    cin >> name;
    cout << "\n Enter Employee ID [max 4 digits]:-\t";
    cin >> id;
    while(1){
    fstream file;
	char i[5];
	int x=0;
	file.open("Ep_data.txt",ios::app|ios::out);
	try{
		while(!file.eof()){
			file>>i;
			if(strcmp(id,i)==0)
				throw(x);
		}
	}
	catch(int x){
		cout<<"\n This id has already been used before.";
		cout << "\n Enter Employee ID [max 4 digits]:-\t";
		cin >> id;
	}
	break;
	};
	cout << "\n Enter Designation:-\t";
    cin >> designation;
    cout << "\n Enter Employee Age:-\t";
    cin >> age;
    cout << "\n Enter Employee Salary:-\t";
    cin >> salary;
    cout << "\n Enter Employee Experience:-\t";
    cin >> experience;
    file.open("Employee_Record.txt", ios::app | ios::out);
    file << "" << name << "\t" << id << "\t" << designation << "\t" << age << "\t" << salary << "\t" << experience << "\n";
    file.close();
    file.open("Ep_data.txt", ios::app | ios::out);
    file<<name<<" "<<id<<"\n";
    waitForEnter();
}

void Employee_management::display() // Display data of employe
{
    system("cls");
    int total = 1;
    char choice;
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- View Employee Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> salary >> experience;
        cout << "\n -------------------------------------------------------------------------------------------------";
        cout << "\n||	NAME	||	ID	||	DESIGNATION	||	AGE	||	SALARY	||	EXPERIENCE	||";
        cout << "\n -------------------------------------------------------------------------------------------------";
        while (!file.eof())
        {
            cout << "\n";
            cout << total++ << ") " << name << "\t  " << id << "\t\t  " << designation << "\t\t   " << age << "\t\t  " << salary << "\t\t" << experience;
            file >> name >> id >> designation >> age >> salary >> experience;
        }
    }
    /*
	cout<<"Do you want to have this data exported into a text file as well?(Y/N):-\t";
	cin>>choice;
	if(choice=='Y'||choice=='y')
	{
	ithe aayega code to output content. into another file "exported_data.txt"
	}
	*/
    file.close();
    waitForEnter();
}

void Employee_management::modify() // Modify data of employe
{
    system("cls");
    char checkId[5];
    int found = 0;
    fstream file, file1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Modify Employee Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter employee id: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n Enter Name of Employee: ";
                cin >> name;
                cout << "\n Enter Employee ID [max 4 digits]: ";
                cin >> id;
                cout << "\n Enter Designation: ";
                cin >> designation;
                cout << "\n Enter Employee Age: ";
                cin >> age;
                cout << "\n Enter Employee Salary: ";
                cin >> salary;
                cout << "\n Enter Employee Experience: ";
                cin >> experience;
                cout << "\n\nSuccessfully Modify Details Of Employee";
                file1 << "" << name << "\t" << id << "\t" << designation << "\t" << age << "\t" << salary << "\t" << experience << "\n";
                found++;
            }
            else
            {
                file1 << "" << name << "\t" << id << "\t" << designation << "\t" << age << "\t" << salary << "\t" << experience << "\n";
            }
            file >> name >> id >> designation >> age >> salary >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again...";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
    }
    waitForEnter();
}

void Employee_management::search() // Search data of employe
{                                  //Displays all details according to Employee's id
    system("cls");
    fstream file;
    char checkId[5];
    int counter=0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Search Employee Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    cout << "\n\n Enter Employee ID :-\t";
    cin >> checkId;
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present...";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n---------------------\n";
                cout << "Employee Name:-\t" << name;
                cout << "\nEmployee ID.:-\t" << id;
                cout << "\nEmployee Designation:-\t" << designation;
                cout << "\nEmployee Age:-\t" << age;
                cout << "\nEmployee Salary:-\t" << salary;
                cout << "\nEmployee Experience:-\t" << experience;
                cout << "\n---------------------\n";
                counter++;
            }
            file >> name >> id >> designation >> age >> salary >> experience;
        }if(counter==0)
        	cout<<"No employee with such ID is found...";
    }
    file.close();
    waitForEnter();
}

void Employee_management::deleted() // Delete data of employe
{
    system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Data -------------------------------------------" << endl;
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee Id To Remove Data: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> salary >> experience;
        while (!file.eof())
        {
            if (strcmp(checkId, id) != 0)
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << salary << " " << experience << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> id >> designation >> age >> salary >> experience;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
        remove("Employee_Record.txt");
        rename("record.txt", "Employee_Record.txt");
        
        file.open("Ep_data.txt", ios::in);
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id;
        while (!file.eof())
        {
            if (strcmp(checkId, id) != 0)
            {
                file1 << " " << name << " " << id<<"\n";
            }
		}
		file1.close();
        file.close();
        remove("Ep_data.txt");
        rename("record.txt", "Ep_data.txt");
        waitForEnter();
    }
}

void Employee_management::addadmin() //	Admin can assign admin role to others
{
	char name[100];
	int i;
	fstream file;
	system("cls");
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Assigning another Admin -------------------------------------------" << endl;
    cout << "\n Enter Name of Employee:-\t";
    cin >> name;
    cout << "\n Enter Employee ID [max 4 digits]:-\t";
    cin >> id;
	file.open("Adm_data.txt", ios::app | ios::out);
	file<<name<<" "<<id<<"\n";
    file.close();
    waitForEnter();
}

void Employee_management::waitForEnter()// For better flow of Programm
{
    cout << "\n\nPress enter to go back...";
    cin.get();
}

void Employee::holiday()// List of holidays for employee
{
	system("cls");
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- The Calender Holidays -------------------------------------------" << endl;
    cout<<"\n\nDear Employee, the holidays for this calender year are listed below:-\n\n";
	cout<<"1.Lohri\t\t13-Jan\n2.Republic Day\t26-Jan\n3.Holi\t\t28-Feb\n4.Vaisakhi\t13-Apr\n5.Independence Day 15-Aug\n6.Dusehra\t5-Oct\n7.Diwali\t25-Oct\n8.Gurpurab\t8-Nov\n9.Christmas\t25-Dec";;
	cout<<"\nData Administrator will keep updating this holidays list as per the guidelines.";
	cout<<"\nYou may press any key to return to the main menu";
	waitForEnter();
}

void Employee::leave()// Apply a leave 
{
	int no,date,id;
	fstream file;
	system("cls");
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Leave Application -------------------------------------------" << endl;
    cout<<"\n\nTo apply a leave application please fill out the following:-";
	cout<<"\nEnter your Employee ID:-\t";
	cin>>id;
	cout<<"\nLeave needed from(for eg. 1-jan-2021 to be written as 01012021):-\t";
	cin>>date;
	cout<<"Leave needed for how many days:-\t";
	cin>>no;
	file.open("leaves.txt", ios::app | ios::out);
    file <<"\n=> "<<id<<"\t"<<date<<"\t"<<no;
    file.close();
    waitForEnter();
}

void Employee::policy()// as an aknowladgement to the project
{
	system("cls");
	cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------- Company Policy -------------------------------------------" << endl;
	string s;
	fstream file;
    file.open("Company Policy.txt", ios::in);
    while (!file.eof()){
    	file>>s;
    	cout<<s<<" ";
	};
	waitForEnter();
};

int password_user(int i)// Authentication of the employee
{
    string login_password,login_username,stored_password,stored_username;
	fstream pull;
    system("cls");
    {
        cout << "\n\t\t\t\t\t--------------------";
        cout << "\n\t\t\t\t\t>> LOGIN REQUIRED <<";
        cout << "\n\t\t\t\t\t--------------------";
        if(i==1){
        	
			fstream pull("Adm_data.txt",ios::in);
			
		if (!pull) { 
    		cout<<"Sorry for inconvinence, File is not being loaded!"<<endl;
    		return -1; 
		}
		cout<<"\n\t\tPlease enter the Username:- ";
		cin>>login_username;
		while(login_username!=stored_username){ 
    		pull>>stored_username;
	    	if(pull.eof()){   //if it is the end of file
		    cout<<" Username does not exist. "<<endl;
		    break;}
		}
		pull>>stored_password; 
		cout<<"\n\t\tPlease enter the Password:- "; 
		cin>>login_password;
		while(stored_password!=login_password){
	    		cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
                for (int a = 1; a < 16; a++)
                {
                    Sleep(50);
                    cout << ".";
                }
                cout << "\n\n\t\tYou cannot access the system...\n\n";
                system("PAUSE");
                system("cls");
                password_user(i);
		}
		cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
        for (int a = 1; a <16; a++)
            {
                Sleep(50);
                cout << ".";
            }
        cout << "\n\n\t\tAccess is Granted...\n\n";
		}
        else if(i==2){
			fstream pull("Ep_data.txt",ios::in);
			
		if (!pull) { 
    		cout<<"Sorry for inconvinence, File is not being loaded!"<<endl;
    		return -1; 
		}
		cout<<"\n\t\tPlease enter the Username:- ";
		cin>>login_username;
		while(login_username!=stored_username){ 
    		pull>>stored_username;
	    	if(pull.eof()){   //if it is the end of file
		    cout<<" Username does not exist. "<<endl;
		    break;}
		}
		pull>>stored_password; 
		cout<<"\n\t\tPlease enter the Password:- "; 
		cin>>login_password;
		while(stored_password!=login_password){
	    		cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
                for (int a = 1; a < 16; a++)
                {
                    Sleep(50);
                    cout << ".";
                }
                cout << "\n\n\t\tYou cannot access the system...\n\n";
                system("PAUSE");
                system("cls");
                password_user(i);
		}
		cout << "\n\n\n\t\t\t\t\t| Verfiying EMPLOYEE |\n\t\t\t\t\t";
        for (int a = 1; a <16; a++)
            {
                Sleep(50);
                cout << ".";
            }
        cout << "\n\n\t\tAccess is Granted...\n\n";
        }
		system("PAUSE");
        system("cls");
		return 1;
	}
}

void start_menu()//Start menu 
{
	cout<<"\n\n"<<"\t\tWELCOME TO EMPLOYEE MANAGMENT SYSTEM\n"<<"\t\t===================================="<<endl;
	cout<<" 1) Data Administrator\n 2) Employee\n\nKindly select your designation in the system:-\t";
};

int main()
{
	Employee_management adm;
	Employee emp;
	start_menu();
	int sm;
	cin>>sm;
	switch(sm){
		case 1:
			adm.menu();
			break;
		case 2:
			emp.menu();
			break;
		default:
			cout<<"System found an error";
	};
	return 0;
}
