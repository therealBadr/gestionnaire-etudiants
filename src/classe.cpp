#include "classe.h"
#include "etudiant.h"  // Include the full definition of Etudiant

Classe::Classe(const string& nomClasse) 
    : nomClasse(nomClasse), delegue(nullptr) {}

void Classe::addEtudiant(Etudiant* etudiant) {
    etudiants.push_back(etudiant);
}

void Classe::setDelegue(Etudiant* etudiant) {
    delegue = etudiant;
}

void Classe::displayClasse() const {
    cout << "Class Name: " << nomClasse << endl;
    if (delegue) {
        cout << "Delegue: " << delegue->getNom() << " " << delegue->getPrenom() << endl;
    } else {
        cout << "Delegue: None" << endl;
    }
    cout << "Students: " << etudiants.size() << endl;
}

string Classe::getNomClasse() const {
    return nomClasse;
}

void Classe::setNomClasse(const string& nomClasse) {
    this->nomClasse = nomClasse;
}