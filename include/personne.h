#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <iostream>

using namespace std;

class Personne {
public:
    Personne(const string& nom, const string& prenom, const string& email);

    void displayInfo() const;

    // Getters
    string getNom() const;
    string getPrenom() const;
    string getEmail() const;

protected:
    string nom;
    string prenom;
    string email;
};

#endif // PERSONNE_H