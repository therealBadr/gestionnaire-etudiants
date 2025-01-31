#ifndef DATABASE_H
#define DATABASE_H

#include <mysql/mysql.h>
#include <string>
#include "etudiant.h"  // Include the Etudiant class header

using namespace std;


class Database {
public:
    Database();
    ~Database();

    bool connect(const string& host, const string& user, const string& password, const string& dbname, unsigned int port = 3306, const string& socket = "");
    void close();
    MYSQL* getConnection();

    bool executeQuery(const string& query);
    bool checkClassExists(const string& nomClasse);
    bool insertStudent(const Etudiant& student);
    bool checkStudentExists(int id);

    // New methods to add
    bool updateStudent(const Etudiant& student);
    bool deleteStudent(int id);
    void displayAllStudents();
    bool editClass(const string& nomClasse);
    bool deleteClass(const string& nomClasse);
    void displayAllClasses();
    bool updateStudentEmail(int studentId, const string& newEmail);
    Etudiant* getStudentById(int studentId);

    bool insertClass(const string& nomClasse);  // Add this method

private:
    MYSQL* conn;
};

#endif // DATABASE_H