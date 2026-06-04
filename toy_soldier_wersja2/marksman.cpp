#include "marksman.h"

Marksman::Marksman(std::string rank, int ammo)
    : Soldier(rank), m_ammo(ammo) {}

std::string Marksman::ExecuteCommand(Command c) {
    if (c == Command::LEFT_FACE) {
        return "[" + m_rank + " - Sniper] Aiming through scope.";
    }
    if (c == Command::RIGHT_FACE) {
        if (m_ammo > 0) {
            m_ammo--;
            return "[" + m_rank + " - Sniper] Firing weapon! Ammo left: " + std::to_string(m_ammo);
        } else {
            return "[" + m_rank + " - Sniper] Out of ammo! Drawing sidearm.";
        }
    }

    return Soldier::ExecuteCommand(c);
}
