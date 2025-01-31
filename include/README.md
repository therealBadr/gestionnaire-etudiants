# Documentation du Système de Gestion des Étudiants

Cette documentation décrit les classes et les méthodes du système de gestion des étudiants. Elle explique comment les classes sont connectées et comment elles fonctionnent ensemble.

---

## **1. Classe `Personne`**
La classe `Personne` est une classe de base qui représente une personne avec des attributs communs tels que le nom, le prénom et l'email.

### **Attributs :**
- `nom` : Le nom de la personne.
- `prenom` : Le prénom de la personne.
- `email` : L'adresse email de la personne.

### **Méthodes :**
- **`Personne(const string& nom, const string& prenom, const string& email)`**  
  Constructeur qui initialise une personne avec un nom, un prénom et un email.

- **`void displayInfo() const`**  
  Affiche les informations de la personne (nom, prénom, email).

- **`string getNom() const`**  
  Retourne le nom de la personne.

- **`string getPrenom() const`**  
  Retourne le prénom de la personne.

- **`string getEmail() const`**  
  Retourne l'email de la personne.

---

## **2. Classe `Etudiant` (Hérite de `Personne`)**
La classe `Etudiant` représente un étudiant. Elle hérite de la classe `Personne` et ajoute des attributs spécifiques à un étudiant, tels que l'ID, la classe, la filière, le groupe, les matières et les notes.

### **Attributs :**
- `id` : L'identifiant unique de l'étudiant.
- `classe` : Un pointeur vers un objet `Classe` représentant la classe de l'étudiant.
- `filiere` : La filière de l'étudiant.
- `groupe` : Le groupe de l'étudiant.
- `matieres` : Une liste des matières suivies par l'étudiant.
- `notes` : Une liste des notes obtenues par l'étudiant.

### **Méthodes :**
- **`Etudiant(int id, const string& nom, const string& prenom, const string& email, Classe* classe, const string& filiere, const string& groupe)`**  
  Constructeur qui initialise un étudiant avec un ID, un nom, un prénom, un email, une classe, une filière et un groupe.

- **`void addNote(const Note& note)`**  
  Ajoute une note à la liste des notes de l'étudiant.

- **`void assignMatiere(const Matiere& matiere)`**  
  Ajoute une matière à la liste des matières de l'étudiant.

- **`void displayInfo() const`**  
  Affiche les informations de l'étudiant (nom, prénom, email, ID, classe, filière, groupe).

- **`int getId() const`**  
  Retourne l'ID de l'étudiant.

- **`Classe* getClasse() const`**  
  Retourne un pointeur vers la classe de l'étudiant.

- **`string getFiliere() const`**  
  Retourne la filière de l'étudiant.

- **`string getGroupe() const`**  
  Retourne le groupe de l'étudiant.

- **`void setNom(const string& nom)`**  
  Modifie le nom de l'étudiant.

- **`void setPrenom(const string& prenom)`**  
  Modifie le prénom de l'étudiant.

- **`void setEmail(const string& email)`**  
  Modifie l'email de l'étudiant.

- **`void setFiliere(const string& filiere)`**  
  Modifie la filière de l'étudiant.

- **`void setGroupe(const string& groupe)`**  
  Modifie le groupe de l'étudiant.

- **`const vector<Note>& getNotes() const`**  
  Retourne la liste des notes de l'étudiant.

- **`const vector<Matiere>& getMatieres() const`**  
  Retourne la liste des matières de l'étudiant.

- **`void displayMatieres() const`**  
  Affiche la liste des matières de l'étudiant.

- **`void displayNotes() const`**  
  Affiche la liste des notes de l'étudiant.

---

## **3. Classe `Classe`**
La classe `Classe` représente une classe d'étudiants. Elle contient une liste d'étudiants et un délégué.

### **Attributs :**
- `nomClasse` : Le nom de la classe.
- `etudiants` : Une liste des étudiants appartenant à la classe.
- `delegue` : Un pointeur vers l'étudiant délégué de la classe.

### **Méthodes :**
- **`Classe(const string& nomClasse)`**  
  Constructeur qui initialise une classe avec un nom.

- **`void addEtudiant(Etudiant* etudiant)`**  
  Ajoute un étudiant à la classe.

- **`void setDelegue(Etudiant* etudiant)`**  
  Définit l'étudiant délégué de la classe.

- **`void displayClasse() const`**  
  Affiche les informations de la classe (nom, délégué, nombre d'étudiants).

- **`string getNomClasse() const`**  
  Retourne le nom de la classe.

- **`void setNomClasse(const string& nomClasse)`**  
  Modifie le nom de la classe.

---

## **4. Classe `Matiere`**
La classe `Matiere` représente une matière suivie par un étudiant.

### **Attributs :**
- `idMatiere` : L'identifiant unique de la matière.
- `nomMatiere` : Le nom de la matière.
- `coefficient` : Le coefficient de la matière.
- `professeur` : Le nom du professeur enseignant la matière.

### **Méthodes :**
- **`Matiere(int idMatiere, const string& nomMatiere, float coefficient, const string& professeur)`**  
  Constructeur qui initialise une matière avec un ID, un nom, un coefficient et un professeur.

- **`int getIdMatiere() const`**  
  Retourne l'ID de la matière.

- **`string getNomMatiere() const`**  
  Retourne le nom de la matière.

- **`float getCoefficient() const`**  
  Retourne le coefficient de la matière.

- **`string getProfesseur() const`**  
  Retourne le nom du professeur.

- **`void displayMatiere() const`**  
  Affiche les informations de la matière (ID, nom, coefficient, professeur).

---

## **5. Classe `Note`**
La classe `Note` représente une note obtenue par un étudiant dans une matière.

### **Attributs :**
- `idNote` : L'identifiant unique de la note.
- `controleContinue` : La note du contrôle continu.
- `examenFinal` : La note de l'examen final.
- `noteFinale` : La note finale calculée.

### **Méthodes :**
- **`Note(int idNote, float controleContinue, float examenFinal)`**  
  Constructeur qui initialise une note avec un ID, une note de contrôle continu et une note d'examen final.

- **`float calculateFinalNote() const`**  
  Calcule et retourne la note finale (30% contrôle continu + 70% examen final).

- **`void displayNote() const`**  
  Affiche les informations de la note (ID, contrôle continu, examen final, note finale).

- **`int getIdNote() const`**  
  Retourne l'ID de la note.

- **`float getControleContinue() const`**  
  Retourne la note du contrôle continu.

- **`float getExamenFinal() const`**  
  Retourne la note de l'examen final.

---

## **6. Classe `Database`**
La classe `Database` gère la connexion à la base de données et les opérations CRUD (Create, Read, Update, Delete) sur les étudiants, les classes, les matières et les notes.

### **Attributs :**
- `conn` : Un pointeur vers la connexion MySQL.

### **Méthodes :**
- **`Database()`**  
  Constructeur qui initialise la connexion à la base de données.

- **`~Database()`**  
  Destructeur qui ferme la connexion à la base de données.

- **`bool connect(const string& host, const string& user, const string& password, const string& dbname, unsigned int port = 3306, const string& socket = "")`**  
  Établit une connexion à la base de données.

- **`void close()`**  
  Ferme la connexion à la base de données.

- **`MYSQL* getConnection()`**  
  Retourne la connexion MySQL.

- **`bool executeQuery(const string& query)`**  
  Exécute une requête SQL.

- **`bool checkClassExists(const string& nomClasse)`**  
  Vérifie si une classe existe dans la base de données.

- **`bool insertStudent(const Etudiant& student)`**  
  Insère un étudiant dans la base de données.

- **`bool checkStudentExists(int id)`**  
  Vérifie si un étudiant existe dans la base de données.

- **`bool updateStudent(const Etudiant& student)`**  
  Met à jour les informations d'un étudiant dans la base de données.

- **`bool deleteStudent(int id)`**  
  Supprime un étudiant de la base de données.

- **`void displayAllStudents()`**  
  Affiche tous les étudiants de la base de données.

- **`bool editClass(const string& nomClasse)`**  
  Modifie le nom d'une classe dans la base de données.

- **`bool deleteClass(const string& nomClasse)`**  
  Supprime une classe de la base de données.

- **`void displayAllClasses()`**  
  Affiche toutes les classes de la base de données.

- **`bool updateStudentEmail(int studentId, const string& newEmail)`**  
  Met à jour l'email d'un étudiant dans la base de données.

- **`Etudiant* getStudentById(int studentId)`**  
  Récupère un étudiant par son ID depuis la base de données.

- **`bool insertClass(const string& nomClasse)`**  
  Insère une nouvelle classe dans la base de données.

---

## **7. Classe `Professeur` (Hérite de `Personne`)**
La classe `Professeur` représente un professeur. Elle hérite de la classe `Personne` et ajoute des attributs spécifiques à un professeur, tels que l'ID, la spécialité et le téléphone.

### **Attributs :**
- `idProfesseur` : L'identifiant unique du professeur.
- `specialite` : La spécialité du professeur.
- `telephone` : Le numéro de téléphone du professeur.

### **Méthodes :**
- **`Professeur(int idProfesseur, const string& nom, const string& prenom, const string& email, const string& specialite, const string& telephone)`**  
  Constructeur qui initialise un professeur avec un ID, un nom, un prénom, un email, une spécialité et un téléphone.

- **`void displayInfo() const`**  
  Affiche les informations du professeur (nom, prénom, email, spécialité, téléphone).

---

## **8. Classe `Login`**
La classe `Login` gère l'authentification des utilisateurs (étudiants et administrateurs).

### **Méthodes :**
- **`bool registerUser(Database& db, const string& username, const string& password, const string& role, const string& email)`**  
  Enregistre un nouvel utilisateur dans la base de données.

- **`bool loginUser(Database& db, const string& username, const string& password, string& role, int& studentId)`**  
  Authentifie un utilisateur et retourne son rôle et son ID (pour les étudiants).

---

## **Conclusion**
Ce système de gestion des étudiants est structuré autour de plusieurs classes qui interagissent entre elles pour gérer les étudiants, les classes, les matières, les notes et les professeurs. La classe `Database` sert de pont entre l'application et la base de données MySQL, tandis que les classes `Etudiant`, `Classe`, `Matiere`, et `Note` représentent les entités principales du système. La classe `Login` gère l'authentification des utilisateurs.
