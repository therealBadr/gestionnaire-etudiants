#include "etudiant.h"
#include "classe.h"  // Include the full definition of Classe

Etudiant::Etudiant(int id, const string& nom, const string& prenom, const string& email,
                   Classe* classe, const string& filiere, const string& groupe)
    : Personne(nom, prenom, email), id(id), classe(classe), filiere(filiere), groupe(groupe) {}

void Etudiant::addNote(const Note& note) {
    notes.push_back(note);
}

void Etudiant::assignMatiere(const Matiere& matiere) {
    matieres.push_back(matiere);
}

void Etudiant::displayInfo() const {
    Personne::displayInfo();
    cout << "ID: " << id << ", Classe: " << classe->getNomClasse() << ", Filiere: " << filiere << ", Groupe: " << groupe << endl;
}

int Etudiant::getId() const { return id; }
Classe* Etudiant::getClasse() const { return classe; }
string Etudiant::getFiliere() const { return filiere; }
string Etudiant::getGroupe() const { return groupe; }

void Etudiant::setNom(const string& nom) {
    this->nom = nom;
}

void Etudiant::setPrenom(const string& prenom) {
    this->prenom = prenom;
}

void Etudiant::setEmail(const string& email) {
    this->email = email;
}

void Etudiant::setFiliere(const string& filiere) {
    this->filiere = filiere;
}

void Etudiant::setGroupe(const string& groupe) {
    this->groupe = groupe;
}

const vector<Note>& Etudiant::getNotes() const {
    return notes;
}

const vector<Matiere>& Etudiant::getMatieres() const {
    return matieres;
}

void Etudiant::displayMatieres() const {
    cout << "Courses (Matieres):\n";
    for (const Matiere& matiere : matieres) {
        matiere.displayMatiere();
    }
}

void Etudiant::displayNotes() const {
    cout << "Grades (Notes):\n";
    for (const Note& note : notes) {
        note.displayNote();
    }
}