#include "soldier.h"

Soldier::Soldier(std::string rank)
    : m_rank(rank), m_state(State::IDLE)
{
}

std::string Soldier::ExecuteCommand(Command c) {
    switch(c) {
    case Command::ATTENTION:
        m_state = State::AT_ATTENTION;
        return "[" + m_rank + "] Standing at attention!";

    case Command::AT_EASE:
        m_state = State::IDLE;
        return "[" + m_rank + "] At ease.";

    case Command::MARCH:
        m_state = State::MARCHING;
        return "[" + m_rank + "] Marching forward!";

    case Command::HALT:
        m_state = State::IDLE;
        return "[" + m_rank + "] Halted.";

    case Command::LEFT_FACE:
        return "[" + m_rank + "] Facing left.";

    case Command::RIGHT_FACE:
        return "[" + m_rank + "] Facing right.";

    case Command::FALL_IN:
        m_state = State::AT_ATTENTION;
        return "[" + m_rank + "] Falls in line!";

    default:
        return "[" + m_rank + "] Command not recognized.";
    }
}

State Soldier::GetState() const {
    return m_state;
}

std::string Soldier::GetRank() const {
    return m_rank;
}

