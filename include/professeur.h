#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "personne.h"
#include <string>

using namespace std;

class Professeur : public Personne {
public:
    Professeur(int idProfesseur, const string& nom, const string& prenom, const string& email,
               const string& specialite, const string& telephone);

    void displayInfo() const;

private:
    int idProfesseur;
    string specialite;
    string telephone;
};

#endif // PROFESSEUR_H