#ifndef ETUDIANT_H
#define ETUDIANT_H

#include "personne.h"
#include "note.h"
#include "matiere.h"
#include <vector>

// Forward declaration to break circular dependency
class Classe;

using namespace std;

class Etudiant : public Personne {
public:
    Etudiant(int id, const string& nom, const string& prenom, const string& email,
             Classe* classe, const string& filiere, const string& groupe);

    void addNote(const Note& note);
    void assignMatiere(const Matiere& matiere);
    void displayInfo() const;

    // Getters
    int getId() const;
    Classe* getClasse() const;
    string getFiliere() const;
    string getGroupe() const;

    // Setters
    void setNom(const string& nom);
    void setPrenom(const string& prenom);
    void setEmail(const string& email);
    void setFiliere(const string& filiere);
    void setGroupe(const string& groupe);

    // Methods to access notes and matieres
    const vector<Note>& getNotes() const;
    const vector<Matiere>& getMatieres() const;

    // Display methods
    void displayMatieres() const;
    void displayNotes() const;

private:
    int id;
    Classe* classe;
    string filiere;
    string groupe;
    vector<Matiere> matieres;
    vector<Note> notes;
};

#endif // ETUDIANT_H