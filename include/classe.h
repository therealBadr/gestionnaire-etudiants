#ifndef CLASSE_H
#define CLASSE_H

#include <string>
#include <vector>

// Forward declaration to break circular dependency
class Etudiant;

using namespace std;

class Classe {
public:
    Classe(const string& nomClasse);

    void addEtudiant(Etudiant* etudiant);
    void setDelegue(Etudiant* etudiant);
    void displayClasse() const;

    string getNomClasse() const;
    void setNomClasse(const string& nomClasse);  // Add this method

private:
    string nomClasse;
    vector<Etudiant*> etudiants;
    Etudiant* delegue;
};

#endif // CLASSE_H