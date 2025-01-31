#include "note.h"

Note::Note(int idNote, float controleContinue, float examenFinal)
    : idNote(idNote), controleContinue(controleContinue), examenFinal(examenFinal) {
    noteFinale = calculateFinalNote();
}

int Note::getIdNote() const {
    return idNote;
}

float Note::getControleContinue() const {
    return controleContinue;
}

float Note::getExamenFinal() const {
    return examenFinal;
}

float Note::calculateFinalNote() const {
    return (controleContinue * 0.3) + (examenFinal * 0.7);
}

void Note::displayNote() const {
    cout << "Note ID: " << idNote << ", Controle Continue: " << controleContinue
         << ", Examen Final: " << examenFinal << ", Note Finale: " << noteFinale << endl;
}