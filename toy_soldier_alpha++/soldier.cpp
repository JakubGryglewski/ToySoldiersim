#include "soldier.h"

Soldier::Soldier(std::string rank)
    : m_rank(rank), m_state(State::IDLE)
{
}

std::string Soldier::ExecuteCommand(Command c) {
    if (c == Command::MARCH) {
        m_state = State::MARCHING;
        return "[" + m_rank + "] Marching forward!";
    }
    else if (c == Command::HALT) {
        m_state = State::IDLE;
        return "[" + m_rank + "] Halting!";
    }
    else if (c == Command::ATTENTION) {
        m_state = State::AT_ATTENTION;
        return "[" + m_rank + "] Standing at attention!";
    }
    else if (c == Command::AT_EASE) {
        m_state = State::IDLE;
        return "[" + m_rank + "] At ease.";
    }

    else if (c == Command::LEFT_FACE) {
        if (m_direction == Direction::RIGHT) m_direction = Direction::UP;
        else if (m_direction == Direction::UP)    m_direction = Direction::LEFT;
        else if (m_direction == Direction::LEFT)  m_direction = Direction::DOWN;
        else if (m_direction == Direction::DOWN)  m_direction = Direction::RIGHT;

        return "[" + m_rank + "] Turned left.";
    }
    else if (c == Command::RIGHT_FACE) {
        if (m_direction == Direction::RIGHT) m_direction = Direction::DOWN;
        else if (m_direction == Direction::DOWN)  m_direction = Direction::LEFT;
        else if (m_direction == Direction::LEFT)  m_direction = Direction::UP;
        else if (m_direction == Direction::UP)    m_direction = Direction::RIGHT;

        return "[" + m_rank + "] Turned right.";
    }

    return "[" + m_rank + "] Unknown command.";
}

State Soldier::GetState() const {
    return m_state;
}

std::string Soldier::GetRank() const {
    return m_rank;
}

