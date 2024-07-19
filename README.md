# EMPLOYEE-MANAGEMENT-SYSTEM-
USING CPP AND OOPS
The provided C++ code implements an Employee Management System with functionalities for both administrators and employees. This system allows administrators to manage employee records (add, display, modify, search, and delete), while employees can view and apply for leave.

Key Features
Admin and Employee Login:
The system prompts users to log in as either an administrator or an employee. It verifies credentials from stored files.

Administrator Functionalities:
Add Employee: Allows the admin to add new employee records.
Display Employee: Displays all employee records.
Modify Employee: Modifies the details of an existing employee.
Search Employee: Searches for an employee by their ID.
Delete Employee: Deletes an employee record.
Add Admin: Allows adding new administrators to the system.

Employee Functionalities:
Leave Application: Allows employees to view or apply for leave.

**Object-Oriented Programming (OOP) Concepts Used**
Classes and Objects:
The code defines two main classes: Employee and Employee_management. Instances of these classes (objects) manage different functionalities.

class Employee
{
    // Employee class code
};

class Employee_management : public Employee
{
    // Employee_management class code
};

Inheritance:
The Employee_management class inherits from the Employee class. This enables Employee_management to use and extend the functionalities of the Employee class.

class Employee_management : public Employee

Encapsulation:
Data members (such as name, id, designation, age, salary, and experience) are encapsulated within classes. Member functions provide access and modification capabilities, ensuring controlled interaction with the data.

Abstraction:
The system hides complex implementation details and exposes only necessary functionalities. For example, add(), display(), modify(), search(), and deleted() functions abstract the file handling details from the user.

Polymorphism:
The concept of polymorphism can be inferred from the use of member functions that operate differently based on the context (admin or employee). Though not directly implemented using virtual functions, the structure allows for easy extension where functions could behave differently for different derived classes.

File Handling:
The code uses file handling extensively to store and retrieve data, ensuring persistence across sessions. The files Employee_Record.txt, admin.txt, and leave_app.txt store employee records, admin credentials, and leave applications, respectively.

Detailed Code Description
Login Functionality:
The password_user() function handles user login, differentiating between admin and employee based on user input. It reads credentials from the respective files and verifies them.

Admin Functionalities:
add(): Adds a new employee record to Employee_Record.txt.
display(): Displays all employee records.
modify(): Modifies an existing employee's details.
search(): Searches for an employee by ID and displays their details.
deleted(): Deletes an employee record by ID.
addadmin(): Adds a new admin by storing their credentials in admin.txt.

Employee Functionalities:
leave(): Handles leave applications. Employees can view existing leave applications or apply for new leave.

Utility Functions:
waitForEnter(): Pauses the execution and waits for the user to press enter.

Administrator Login and Actions:
Admin logs in using their credentials.
Admin can add, display, modify, search, and delete employee records.
Admin can also add new administrators.

Employee Login and Actions:
Employee logs in using their credentials.
Employee can view and apply for leave.
This structured and modular approach makes the Employee Management System efficient, easy to understand, and maintainable. The use of OOP principles ensures that the system can be easily extended with additional functionalities in the future.






