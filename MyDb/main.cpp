#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <mysqld_error.h>

using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "shwet@trip@thi1100!!))";
const char* DB = "mydb";

// Function to set text color in the console
void SetColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Function to clear the console screen
void ClearScreen() {
    system("cls"); // Clears the console screen (Windows-specific)
}

// Function to display a banner or header
void ShowBanner() {
    SetColor(14); // Yellow text
    cout << "=============================" << endl;
    cout << "   C++ CRUD Application      " << endl;
    cout << "=============================" << endl;
    SetColor(7); // Reset to default color
}

// Function to display a loading animation
void LoadingAnimation() {
    string loading = "Loading";
    for (int i = 0; i < 5; i++) {
        cout << loading;
        for (int j = 0; j < 3; j++) {
            cout << ".";
            Sleep(300); // Pause for 300 milliseconds
        }
        cout << "\r"; // Return the cursor to the beginning of the line
        cout.flush();
    }
    cout << endl;
}

// Function to get the user's menu choice
int GetMenuChoice() {
    int choice;
    SetColor(11); // Light blue text for input prompt
    cout << "Choose an option: ";
    SetColor(7); // Reset to default color
    cin >> choice;
    return choice;
}

int main() {
    MYSQL* conn; // Connection
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, HOST, USER, PW, DB, 3306, NULL, 0)) {
        SetColor(4); // Red text for errors
        cout << endl << endl;
        cout << "\t\t ERROR: " << mysql_error(conn) << endl;
    } else {
        SetColor(10); // Green text for success
        cout << endl << endl;
        cout << "\t\t Logged in!!" << endl; // Connection established
    }
    Sleep(3000); // Pause for 3 seconds

    bool exit = false;
    while (!exit) { // Main loop
        ClearScreen(); // Clear the console for fresh output
        ShowBanner(); // Display the banner

        // Display the menu
        SetColor(7); // Default text color
        cout << "\t\t 1. Insert Data" << endl;
        cout << "\t\t 2. Delete Data" << endl;
        cout << "\t\t 3. Update Data" << endl;
        cout << "\t\t 4. Get/Read Data" << endl;
        cout << "\t\t 0. Exit" << endl;

        int val = GetMenuChoice(); // Get the user's choice

        if (val == 1) {
            ClearScreen();
            string id, name, grade;
            SetColor(11); // Light blue for input prompts
            cout << endl << endl;
            cout << "\t\t Enter Id: ";
            cin >> id;
            cout << "\t\t Enter Name: ";
            cin >> name;
            cout << "\t\t Enter Grade: ";
            cin >> grade;

            string ins = "INSERT INTO student(ID, Name, Grade) VALUES('" + id + "','" + name + "','" + grade + "')"; // SQL insert query
            if (mysql_query(conn, ins.c_str())) {
                SetColor(4); // Red text for errors
                cout << endl << endl;
                cout << "\t\t Error: " << mysql_error(conn) << endl;
            } else {
                SetColor(10); // Green text for success
                cout << endl << endl;
                cout << "\t\t Data Inserted Successfully!!" << endl;
            }
            Sleep(3000);

        } else if (val == 2) {
            ClearScreen();
            string id;
            SetColor(11); // Light blue for input prompts
            cout << endl << endl;
            cout << "\t\t Enter Id: ";
            cin >> id;

            string del = "DELETE FROM student WHERE ID='" + id + "'"; // SQL delete query
            if (mysql_query(conn, del.c_str())) {
                SetColor(4); // Red text for errors
                cout << endl << endl;
                cout << "\t\t ERROR: " << mysql_error(conn) << endl;
            } else {
                SetColor(10); // Green text for success
                cout << endl << endl;
                cout << "\t\t Data Deleted Successfully" << endl;
            }
            Sleep(3000);

        } else if (val == 3) {
            ClearScreen();
            string id, grade;
            SetColor(11); // Light blue for input prompts
            cout << endl << endl;
            cout << "\t\t Enter Id: ";
            cin >> id;
            cout << "\t\t Enter New Grade: ";
            cin >> grade;

            string update = "UPDATE student SET Grade ='" + grade + "' WHERE ID='" + id + "'"; // SQL update query
            if (mysql_query(conn, update.c_str())) {
                SetColor(4); // Red text for errors
                cout << endl << endl;
                cout << "\t\t ERROR: " << mysql_error(conn) << endl;
            } else {
                SetColor(10); // Green text for success
                cout << endl << endl;
                cout << "\t\t Data Updated Successfully" << endl;
            }
            Sleep(3000);

        } else if (val == 4) {
            ClearScreen();
            string get = "SELECT * FROM student"; // SQL select query
            if (mysql_query(conn, get.c_str())) {
                SetColor(4); // Red text for errors
                cout << endl << endl;
                cout << "\t\t ERROR: " << mysql_error(conn) << endl;
            } else {
                MYSQL_RES* result = mysql_store_result(conn); // Store the result
                if (result) {
                    int num = mysql_num_fields(result); // Get the number of columns
                    MYSQL_ROW row;
                    SetColor(11); // Light blue for table headers
                    cout << endl << endl;
                    cout << "\t\t ID\t\tName\t\tGrade" << endl;
                    cout << "\t\t--\t\t----\t\t-----" << endl;
                    SetColor(7); // Default text color for table content
                    while ((row = mysql_fetch_row(result))) { // Fetch each row
                        for (int i = 0; i < num; i++) {
                            cout << "\t\t" << row[i];
                        }
                        cout << endl;
                    }
                    mysql_free_result(result); // Free the result object
                }
            }
            Sleep(10000);

        } else if (val == 0) {
            ClearScreen();
            exit = true;
            SetColor(10); // Green text for exit message
            cout << endl << endl;
            cout << "\t\t BYE!!" << endl;
            Sleep(3000);
        } else {
            SetColor(4); // Red text for errors
            cout << endl << endl;
            cout << "\t\t Invalid Input" << endl;
            Sleep(3000);
        }
    }

    mysql_close(conn); // Close the connection

    return 0;
}

