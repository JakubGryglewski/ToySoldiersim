#include "officer.h"

Officer::Officer(std::string rank)
    : Soldier(rank)
{
}

std::string Officer::ExecuteCommand(Command c) {
    if (c == Command::AT_EASE) {

       return "[" + m_rank + " - Officer] Ignores the 'At Ease' command. The commander remains at his post.";
    }


    return Soldier::ExecuteCommand(c);
}