#include "officer.h"

Officer::Officer(std::string rank)
    : Soldier(rank)
{
}

std::string Officer::ExecuteCommand(Command c) {
    if (c == Command::AT_EASE) {

        return "[" + m_rank + " - Officer] Ignoruje rozkaz 'Spocznij'. Dowódca pozostaje na stanowisku.";
    }


    return Soldier::ExecuteCommand(c);
}