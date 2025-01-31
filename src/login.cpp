#include "login.h"
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include <sstream>

using namespace std;

// Hashing utility placeholder (for better security)
string hashPassword(const string& password) {
    // Replace this with bcrypt or other library later
    return password;
}

bool registerUser(Database& db, const string& username, const string& password, const string& role, const string& email) {
    stringstream query;
    query << "INSERT INTO Users (username, password, role, email) VALUES ('"
          << username << "', '" << hashPassword(password) << "', '" << role << "', '" << email << "');";
    
    if (mysql_query(db.getConnection(), query.str().c_str())) {
        cerr << "Error registering user: " << mysql_error(db.getConnection()) << endl;
        return false;
    }

    cout << "Registration successful!" << endl;
    return true;
}

// Modify loginUser to return the role and studentId of the logged-in user
bool loginUser(Database& db, const string& username, const string& password, string& role, int& studentId) {
    stringstream query;
    query << "SELECT password, role, id FROM Users WHERE username = '" << username << "';";

    if (mysql_query(db.getConnection(), query.str().c_str())) {
        cerr << "Error fetching user: " << mysql_error(db.getConnection()) << endl;
        return false;
    }

    MYSQL_RES* result = mysql_store_result(db.getConnection());
    MYSQL_ROW row;

    if ((row = mysql_fetch_row(result))) {
        string storedPassword = row[0];
        role = row[1];  // Get the role

        if (storedPassword == hashPassword(password)) {
            if (role == "student") {
                studentId = stoi(row[2]);  // Set the studentId for students
            }
            cout << "Login successful! Welcome, " << role << " user." << endl;
            mysql_free_result(result);
            return true;
        } else {
            cerr << "Invalid password!" << endl;
        }
    } else {
        cerr << "User not found!" << endl;
    }

    mysql_free_result(result);
    return false;
}