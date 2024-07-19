Purpose:

For managers and employees to manage and access employee information using C++ and OOP principles.
Key Features
Manager Functionalities:

Add Employee: Add new employee records.
View Employees: Display all employee information.
Modify Employee: Update details of an existing employee.
Search Employee: Find employees by ID.
Delete Employee: Remove employee records.
Add Administrator: Add new admins to the system.
Employee Functionalities:

View Leave: Check existing leave requests.
Request Leave: Apply for new leave.
OOP Concepts Used
Classes and Objects:

Two main classes: Employee and Employee_management.
Objects manage various functions.
Inheritance:

Employee_management inherits from Employee.
Allows Employee_management to extend Employee functionalities.
Encapsulation:

Data members like name, id, designation, etc., are encapsulated.
Accessed and modified through member functions.
Abstraction:

Functions like add(), display(), modify(), search(), and delete() hide file handling details.
File Handling:

Data stored in Employee_Record.txt, admin.txt, and Leave_app.txt for session persistence.
Function Descriptions
Manager Functions:

add(): Add new employee records.
display(): Show all employee information.
modify(): Update employee details.
search(): Find employees by ID.
deleted(): Remove employee records by ID.
addadmin(): Add new admin credentials to admin.txt.
Employee Functions:

leave(): View or apply for leave.
Usage Summary
Managers:

Log in with admin credentials.
Manage employee records: add, view, modify, search, delete.
Add new administrators.
Employees:

Log in with employee credentials.
View and request leave.
Benefits
Structured and Modular: Easy to understand and maintain.
OOP Principles: Ensures extendibility and controlled data access.
Persistent Data: Data stored in files for future sessions.
This approach makes personnel management efficient, intuitive, and scalable.






