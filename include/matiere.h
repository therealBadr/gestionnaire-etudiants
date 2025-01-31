#ifndef MATIERE_H
#define MATIERE_H

#include <string>
#include <iostream>

using namespace std;

class Matiere {
public:
    Matiere(int idMatiere, const string& nomMatiere, float coefficient, const string& professeur);

    // Getters
    int getIdMatiere() const;
    string getNomMatiere() const;
    float getCoefficient() const;
    string getProfesseur() const;

    void displayMatiere() const;

private:
    int idMatiere;
    string nomMatiere;
    float coefficient;
    string professeur;
};

#endif // MATIERE_H