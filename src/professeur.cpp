#include "professeur.h"

Professeur::Professeur(int idProfesseur, const string& nom, const string& prenom, const string& email,
                       const string& specialite, const string& telephone)
    : Personne(nom, prenom, email), idProfesseur(idProfesseur), specialite(specialite), telephone(telephone) {}

void Professeur::displayInfo() const {
    Personne::displayInfo();
    cout << "ID: " << idProfesseur << ", Specialite: " << specialite << ", Telephone: " << telephone << endl;
}