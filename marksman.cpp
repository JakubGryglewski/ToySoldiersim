#include "marksman.h"
#include <iostream>

Marksman::Marksman(std::string rank, int ammo)
: Soldier(rank), m_ammo(ammo) {
}

void Marksman::ExecuteCommand(Command c) {

    if (c == Command::LEFT_FACE || c == Command::RIGHT_FACE) {
        if (m_ammo > 0) {
            m_ammo--;
            std::cout << "[" << m_rank << " - Marksman] Aiming through scope! Ammo left: " << m_ammo << "\n"; // "Celuje przez optyke! Pozostala amunicja: "
            m_state = State::AT_ATTENTION;
        } else {
            std::cout << "[" << m_rank << " - Marksman] Out of ammo! Switching to sidearm.\n"; // "Brak amunicji! Przechodze na bron boczna."
            m_state = State::AT_ATTENTION;
        }
    }

    else {
        Soldier::ExecuteCommand(c);
    }
}