#ifndef NOTE_H
#define NOTE_H

#include <iostream>

using namespace std;

class Note {
public:
    Note(int idNote, float controleContinue, float examenFinal);

    float calculateFinalNote() const;
    void displayNote() const;

    // Getters
    int getIdNote() const;
    float getControleContinue() const;
    float getExamenFinal() const;

private:
    int idNote;
    float controleContinue;
    float examenFinal;
    float noteFinale;
};

#endif // NOTE_H