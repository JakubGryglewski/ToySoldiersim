#include "medic.h"

Medic::Medic(std::string rank, int medkits)
    : Soldier(rank), m_medkits(medkits) {}

std::string Medic::ExecuteCommand(Command c) {
    if (c == Command::AT_EASE) {
        if (m_medkits > 0) {
            m_medkits--;
            return "[" + m_rank + " - Medic] Healing squad members! Medkits left: " + std::to_string(m_medkits);
        } else {
            return "[" + m_rank + " - Medic] Out of medkits!";
        }
    }

    return Soldier::ExecuteCommand(c);
}
