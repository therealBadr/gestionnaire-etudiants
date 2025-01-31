#include "database.h"
#include "classe.h"
#include "etudiant.h"
#include "matiere.h"
#include "note.h"
#include <iostream>

Database::Database() : conn(nullptr) {}

Database::~Database() {
    close();
}

bool Database::connect(const string& host, const string& user, const string& password, const string& dbname, unsigned int port, const string& socket) {
    conn = mysql_init(nullptr);
    if (!conn) {
        cerr << "MySQL initialization failed!" << endl;
        return false;
    }
    conn = mysql_real_connect(conn, host.c_str(), user.c_str(), password.c_str(), dbname.c_str(), port, socket.c_str(), 0);
    if (!conn) {
        cerr << "Connection failed: " << mysql_error(conn) << endl;
        return false;
    }
    cout << "Connected to MySQL database successfully!" << endl;
    return true;
}

void Database::close() {
    if (conn) {
        mysql_close(conn);
        conn = nullptr;
        cout << "Connection closed." << endl;
    }
}

MYSQL* Database::getConnection() {
    return conn;
}

bool Database::executeQuery(const string& query) {
    if (mysql_query(conn, query.c_str())) {
        cerr << "Query execution failed: " << mysql_error(conn) << endl;
        return false;
    }
    return true;
}

bool Database::checkClassExists(const string& nomClasse) {
    string query = "SELECT COUNT(*) FROM classes WHERE nomClasse = '" + nomClasse + "';";
    if (mysql_query(conn, query.c_str())) {
        cerr << "Query execution failed: " << mysql_error(conn) << endl;
        return false;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (!result) {
        cerr << "Failed to fetch result: " << mysql_error(conn) << endl;
        return false;
    }

    MYSQL_ROW row = mysql_fetch_row(result);
    int count = row ? atoi(row[0]) : 0;

    mysql_free_result(result);

    return count > 0;
}

bool Database::insertStudent(const Etudiant& student) {
    string query = "INSERT INTO students (id, nom, prenom, email, classe, filiere, groupe) "
                   "VALUES ('" + to_string(student.getId()) + "', '" + student.getNom() + "', '" +
                   student.getPrenom() + "', '" + student.getEmail() + "', '" +
                   student.getClasse()->getNomClasse() + "', '" + student.getFiliere() + "', '" +
                   student.getGroupe() + "');";

    if (!executeQuery(query)) {
        cerr << "Error inserting student into the database." << endl;
        return false;
    }

    for (const Matiere& matiere : student.getMatieres()) {
        query = "INSERT INTO matieres (student_id, idMatiere, nomMatiere, coefficient, professeur) "
                "VALUES ('" + to_string(student.getId()) + "', '" + to_string(matiere.getIdMatiere()) + "', '" +
                matiere.getNomMatiere() + "', '" + to_string(matiere.getCoefficient()) + "', '" +
                matiere.getProfesseur() + "');";

        if (!executeQuery(query)) {
            cerr << "Error inserting matiere into the database." << endl;
            return false;
        }
    }

    for (const Note& note : student.getNotes()) {
        query = "INSERT INTO notes (student_id, idNote, controleContinue, examenFinal) "
                "VALUES ('" + to_string(student.getId()) + "', '" + to_string(note.getIdNote()) + "', '" +
                to_string(note.getControleContinue()) + "', '" + to_string(note.getExamenFinal()) + "');";

        if (!executeQuery(query)) {
            cerr << "Error inserting note into the database." << endl;
            return false;
        }
    }

    cout << "Student and associated data inserted successfully!" << endl;
    return true;
}

bool Database::checkStudentExists(int id) {
    string query = "SELECT COUNT(*) FROM students WHERE id = '" + to_string(id) + "';";
    if (mysql_query(conn, query.c_str())) {
        cerr << "Query execution failed: " << mysql_error(conn) << endl;
        return false;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (!result) {
        cerr << "Failed to fetch result: " << mysql_error(conn) << endl;
        return false;
    }

    MYSQL_ROW row = mysql_fetch_row(result);
    int count = row ? atoi(row[0]) : 0;

    mysql_free_result(result);

    return count > 0;
}

bool Database::updateStudent(const Etudiant& student) {
    string query = "UPDATE students SET nom = '" + student.getNom() + "', prenom = '" + student.getPrenom() + "', email = '" + student.getEmail() + "', classe = '" + student.getClasse()->getNomClasse() + "', filiere = '" + student.getFiliere() + "', groupe = '" + student.getGroupe() + "' WHERE id = " + to_string(student.getId()) + ";";
    return executeQuery(query);
}

bool Database::deleteStudent(int id) {
    string query = "DELETE FROM students WHERE id = " + to_string(id) + ";";
    return executeQuery(query);
}

void Database::displayAllStudents() {
    string query = "SELECT * FROM students;";
    if (mysql_query(conn, query.c_str())) {
        cerr << "Query execution failed: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (!result) {
        cerr << "Failed to fetch result: " << mysql_error(conn) << endl;
        return;
    }

    while (MYSQL_ROW row = mysql_fetch_row(result)) {
        cout << "ID: " << row[0] << ", Name: " << row[1] << " " << row[2] << ", Email: " << row[3] << ", Class: " << row[4] << ", Filiere: " << row[5] << ", Group: " << row[6] << endl;
    }

    mysql_free_result(result);
}

bool Database::editClass(const string& nomClasse) {
    string query = "UPDATE classes SET nomClasse = '" + nomClasse + "' WHERE nomClasse = '" + nomClasse + "';";
    return executeQuery(query);
}

bool Database::deleteClass(const string& nomClasse) {
    string query = "DELETE FROM classes WHERE nomClasse = '" + nomClasse + "';";
    return executeQuery(query);
}

void Database::displayAllClasses() {
    string query = "SELECT * FROM classes;";
    if (mysql_query(conn, query.c_str())) {
        cerr << "Query execution failed: " << mysql_error(conn) << endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (!result) {
        cerr << "Failed to fetch result: " << mysql_error(conn) << endl;
        return;
    }

    while (MYSQL_ROW row = mysql_fetch_row(result)) {
        cout << "Class Name: " << row[0] << endl;
    }

    mysql_free_result(result);
}

bool Database::updateStudentEmail(int studentId, const string& newEmail) {
    string query = "UPDATE students SET email = '" + newEmail + "' WHERE id = " + to_string(studentId) + ";";
    return executeQuery(query);
}

Etudiant* Database::getStudentById(int studentId) {
    string query = "SELECT * FROM students WHERE id = " + to_string(studentId) + ";";
    if (mysql_query(conn, query.c_str())) {
        cerr << "Query execution failed: " << mysql_error(conn) << endl;
        return nullptr;
    }

    MYSQL_RES* result = mysql_store_result(conn);
    if (!result) {
        cerr << "Failed to fetch result: " << mysql_error(conn) << endl;
        return nullptr;
    }

    MYSQL_ROW row = mysql_fetch_row(result);
    if (!row) {
        mysql_free_result(result);
        return nullptr;
    }

    int id = stoi(row[0]);
    string nom = row[1];
    string prenom = row[2];
    string email = row[3];
    string nomClasse = row[4];
    string filiere = row[5];
    string groupe = row[6];

    mysql_free_result(result);

    Classe* classe = new Classe(nomClasse);
    return new Etudiant(id, nom, prenom, email, classe, filiere, groupe);
}

bool Database::insertClass(const string& nomClasse) {
    string query = "INSERT INTO classes (nomClasse) VALUES ('" + nomClasse + "');";
    return executeQuery(query);
}