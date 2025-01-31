#include "include/database.h"
#include "include/login.h"
#include <regex>
#include "include/classe.h"
#include "include/etudiant.h"
#include <iostream>

using namespace std;

// Function to add a student (already implemented)
void addStudent(Database& db);

// Function to edit a student's details
void editStudent(Database& db) {
    int id;
    cout << "\n=== Edit Student ===\n";
    cout << "Enter Student ID to edit: ";
    cin >> id;
    cin.ignore();

    if (!db.checkStudentExists(id)) {
        cerr << "Error: Student ID " << id << " does not exist.\n";
        return;
    }

    // Fetch the student's current details
    Etudiant* student = db.getStudentById(id);
    if (!student) {
        cerr << "Error: Failed to fetch student details.\n";
        return;
    }

    // Display current details
    cout << "\nCurrent Student Details:\n";
    student->displayInfo();

    // Prompt for new details
    string nom, prenom, email, nomClasse, filiere, groupe;
    cout << "\nEnter new First Name (leave blank to keep current): ";
    getline(cin, nom);
    if (!nom.empty()) student->setNom(nom);

    cout << "Enter new Last Name (leave blank to keep current): ";
    getline(cin, prenom);
    if (!prenom.empty()) student->setPrenom(prenom);

    cout << "Enter new Email (leave blank to keep current): ";
    getline(cin, email);
    if (!email.empty()) student->setEmail(email);

    cout << "Enter new Class Name (leave blank to keep current): ";
    getline(cin, nomClasse);
    if (!nomClasse.empty()) student->getClasse()->setNomClasse(nomClasse);

    cout << "Enter new Filiere (leave blank to keep current): ";
    getline(cin, filiere);
    if (!filiere.empty()) student->setFiliere(filiere);

    cout << "Enter new Group (leave blank to keep current): ";
    getline(cin, groupe);
    if (!groupe.empty()) student->setGroupe(groupe);

    // Update the student in the database
    if (db.updateStudent(*student)) {
        cout << "\nStudent updated successfully!\n";
    } else {
        cerr << "\nFailed to update student in the database.\n";
    }

    delete student;  // Clean up dynamically allocated memory
}

// Function to delete a student
void deleteStudent(Database& db) {
    int id;
    cout << "\n=== Delete Student ===\n";
    cout << "Enter Student ID to delete: ";
    cin >> id;
    cin.ignore();

    if (!db.checkStudentExists(id)) {
        cerr << "Error: Student ID " << id << " does not exist.\n";
        return;
    }

    if (db.deleteStudent(id)) {
        cout << "\nStudent deleted successfully!\n";
    } else {
        cerr << "\nFailed to delete student from the database.\n";
    }
}

// Function to view reports (grades and courses)
void viewReports(Database& db) {
    cout << "\n=== View Reports ===\n";
    db.displayAllStudents();
}

// Function to manage classes
void manageClasses(Database& db) {
    int choice;
    do {
        cout << "\n=== Manage Classes ===\n";
        cout << "1. Add Class\n";
        cout << "2. Edit Class\n";
        cout << "3. Delete Class\n";
        cout << "4. View All Classes\n";
        cout << "5. Back to Admin Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        string nomClasse;
        switch (choice) {
            case 1:
                cout << "Enter Class Name to add: ";
                getline(cin, nomClasse);
                if (db.insertClass(nomClasse)) {
                    cout << "Class added successfully!\n";
                } else {
                    cerr << "Failed to add class.\n";
                }
                break;
            case 2:
                cout << "Enter Class Name to edit: ";
                getline(cin, nomClasse);
                if (db.editClass(nomClasse)) {
                    cout << "Class edited successfully!\n";
                } else {
                    cerr << "Failed to edit class.\n";
                }
                break;
            case 3:
                cout << "Enter Class Name to delete: ";
                getline(cin, nomClasse);
                if (db.deleteClass(nomClasse)) {
                    cout << "Class deleted successfully!\n";
                } else {
                    cerr << "Failed to delete class.\n";
                }
                break;
            case 4:
                db.displayAllClasses();
                break;
            case 5:
                return;  // Return to admin menu
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

// Function to view a student's profile
void viewProfile(Database& db, int studentId) {
    Etudiant* student = db.getStudentById(studentId);
    if (student) {
        cout << "\n=== Student Profile ===\n";
        student->displayInfo();
        delete student;  // Clean up dynamically allocated memory
    } else {
        cerr << "Error: Failed to fetch student profile.\n";
    }
}

// Function to view a student's courses and grades
void viewCoursesAndGrades(Database& db, int studentId) {
    Etudiant* student = db.getStudentById(studentId);
    if (student) {
        cout << "\n=== Courses and Grades ===\n";
        student->displayMatieres();
        student->displayNotes();
        delete student;  // Clean up dynamically allocated memory
    } else {
        cerr << "Error: Failed to fetch student courses and grades.\n";
    }
}

// Function to update a student's email
void updateEmail(Database& db, int studentId) {
    string newEmail;
    cout << "\n=== Update Email ===\n";
    cout << "Enter new email: ";
    getline(cin, newEmail);

    if (db.updateStudentEmail(studentId, newEmail)) {
        cout << "Email updated successfully!\n";
    } else {
        cerr << "Failed to update email.\n";
    }
}

// Admin menu (already implemented)
void adminMenu(Database& db);

// Student menu
void studentMenu(Database& db, int studentId) {
    int choice;
    do {
        cout << "\n=== Student Menu ===\n";
        cout << "1. View Profile\n";
        cout << "2. View Courses and Grades\n";
        cout << "3. Update Email\n";
        cout << "4. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                viewProfile(db, studentId);
                break;
            case 2:
                viewCoursesAndGrades(db, studentId);
                break;
            case 3:
                updateEmail(db, studentId);
                break;
            case 4:
                cout << "Logging out...\n";
                return;  // Exit the student menu and log out
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

int main() {
    Database db;

    string host = "localhost";
    string user = "root";
    string password = "";
    string dbname = "student_manager";
    string socket = "/opt/lampp/var/mysql/mysql.sock";
    unsigned int port = 3306;

    if (db.connect(host, user, password, dbname, port, socket))
        cout << "You are now connected to the database!" << endl;
    else
        cerr << "Failed to connect to the database!" << endl;

    int choice;
    do {
        cout << "\n=== Welcome to Student Manager ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        string username, password, role, email;
        int studentId;

        switch (choice) {
            case 1:
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);
                cout << "Enter role (admin/student): ";
                getline(cin, role);
                cout << "Enter email: ";
                getline(cin, email);
                if (registerUser(db, username, password, role, email)) {
                    cout << "Registration completed.\n";
                }
                break;

            case 2:
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter password: ";
                getline(cin, password);

                if (loginUser(db, username, password, role, studentId)) {
                    if (role == "admin") {
                        adminMenu(db);
                    } else if (role == "student") {
                        studentMenu(db, studentId);
                    }
                }
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    db.close();
    return 0;
}