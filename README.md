# :page_facing_up: Hotel Management System

A hotel management system developed in C offers a robust solution for automating several essential operations, from room reservation to financial tracking. By using the C language, it is possible to efficiently implement algorithms for controlling room availability, processing financial transactions and managing reservations.

**Programmers:** Iago Roberto e Francinaldo Barbosa

## :link: Development environment
1. Regarding GCC
```
gcc.exe (tdm64-1) 10.3.0
Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```
2. And about the Visual Studio Code
```
1.89.1
```

## :link: Project description

**Final grade:** 10/10

This is a project developed as part of the 3rd evaluation of the Algorithms and Programming II discipline, taught by Professor Alan Rafael Ferreira dos Santos at the Federal University of Piauí - Campus Senador Helvídio Nunes de Barros, in the Bachelor's degree in Information Systems.

## :link: Project's goal
The objective of this project is to create a management system for a small hotel. The system must be implemented in C language and meet the established essential requirements, providing efficient control of reservations, customers and payments.

## :link: Required functions
> Rooms

- Consult room

- Edit room

- Delete room

- FrontEndBedroom

- DbQuarto

> Customer Control

- Register customer

- Consult customer

- Edit client

- Delete customer

- FrontEndClient

- DbCliente

> Financial Management

- Make reservation

- Delete booking

- Check in

- Make payment

- Check reservations

- Amounts received

- FrontEndFinance

- DbFinanca

## :link: Function behavior
**Make reservation:** Allows you to reserve rooms, checking availability and recording data such as customer name, room number, dates, payment status and total reservation amount.

**See reservation:** Allows you to list reservations for a specific customer using a reservation code or the customer's name.

**Delete Reservation:** Allows you to delete a reservation that has already been made.

**Perform check-in:** Enables the registration of additional data in the room and reservation files, changing the room status to occupied and recording the date and time of the customer's arrival.

**Make payment:** Displays the amount to be paid by the customer, updating the room status and recording the amount paid in the financial control file.

**Received values:** Allows querying of all values ​​received during a user-defined time interval.
