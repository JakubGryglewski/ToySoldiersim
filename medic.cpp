#include "medic.h"
#include <iostream>


Medic::Medic(std::string rank, int medkits)
    : Soldier(rank), m_medkits(medkits) {
}

void Medic::ExecuteCommand(Command c) {

    if (c == Command::AT_EASE) {
        m_state = State::IDLE;

        if (m_medkits > 0) {
            m_medkits--;

            std::cout << "[" << m_rank << " - Medic] Healing squad members! Medkits left: " << m_medkits << "\n";
        } else {

            std::cout << "[" << m_rank << " - Medic] Out of medical supplies!\n";
        }
    }

    else {
        Soldier::ExecuteCommand(c);
    }
}
