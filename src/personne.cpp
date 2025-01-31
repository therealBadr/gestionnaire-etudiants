#include "personne.h"

Personne::Personne(const string& nom, const string& prenom, const string& email)
    : nom(nom), prenom(prenom), email(email) {}

void Personne::displayInfo() const {
    cout << "Nom: " << nom << ", Prenom: " << prenom << ", Email: " << email << endl;
}

string Personne::getNom() const { return nom; }
string Personne::getPrenom() const { return prenom; }
string Personne::getEmail() const { return email; }