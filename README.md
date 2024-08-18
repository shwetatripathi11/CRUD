
# CRUD
# C++ MySQL CRUD Application

## Project Overview
This project is a simple C++ console application that demonstrates CRUD (Create, Read, Update, Delete) operations using a MySQL database. The application allows users to interact with a MySQL database to manage student records, including adding new records, deleting existing records, updating records, and retrieving data.

## Features
- **Insert Data:** Add new student records to the database.
- **Delete Data:** Remove student records from the database using their ID.
- **Update Data:** Modify the grade of an existing student record.
- **Read Data:** Retrieve and display all student records from the database.

## UI/UX Enhancements
The console application includes several UI/UX improvements to enhance the user experience:
- **Color-coded text** to differentiate between prompts, errors, and success messages.
- **Simple loading animations** to indicate processing.
- **Interactive menus** with clear options.

## Requirements
- **C++ Compiler:** Dev-C++ (or any C++ compiler with Windows support).
- **MySQL Server:** A running MySQL instance with a database named `mydb`.

## Setup Instructions
1. **Install MySQL Server:** Ensure MySQL is installed and running on your machine.
2. **Create Database:**
   ```sql
   CREATE DATABASE mydb;
   USE mydb;
   CREATE TABLE student (
       ID INT PRIMARY KEY,
       Name VARCHAR(100),
       Grade CHAR(2)
   );
   ```

## How to Use
- Launch the application from the console.
- Follow the on-screen menu to perform CRUD operations:
  - Press `1` to insert a new record.
  - Press `2` to delete a record.
  - Press `3` to update a record.
  - Press `4` to read all records.
  - Press `0` to exit the application.

## Troubleshooting
- **Connection Errors:** Ensure the MySQL server is running and the credentials are correct.
- **Library Linking Errors:** Make sure the MySQL development libraries are linked in your project settings.

## Author
- **Shweta Tripathi**
