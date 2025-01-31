#include "matiere.h"

Matiere::Matiere(int idMatiere, const string& nomMatiere, float coefficient, const string& professeur)
    : idMatiere(idMatiere), nomMatiere(nomMatiere), coefficient(coefficient), professeur(professeur) {}

int Matiere::getIdMatiere() const {
    return idMatiere;
}

string Matiere::getNomMatiere() const {
    return nomMatiere;
}

float Matiere::getCoefficient() const {
    return coefficient;
}

string Matiere::getProfesseur() const {
    return professeur;
}

void Matiere::displayMatiere() const {
    cout << "Matiere ID: " << idMatiere << ", Nom: " << nomMatiere << ", Coefficient: " << coefficient << ", Professeur: " << professeur << endl;
}