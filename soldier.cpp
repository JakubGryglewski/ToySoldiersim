#include "soldier.h"
#include <iostream>
// Konstruktor
Soldier::Soldier(std::string rank)
    : m_rank(rank), m_state(State::IDLE) // Na starcie każdy żołnierz jest w stanie SWOBODNY (IDLE)
{
}
void Soldier::ExecuteCommand(Command c) {
    switch(c) {
    case Command::ATTENTION:
        m_state = State::AT_ATTENTION;
        std::cout << "[" << m_rank << "] Standing at attention!\n"; // "Staje na bacznosc!"
        break;

    case Command::AT_EASE:
        m_state = State::IDLE;
        std::cout << "[" << m_rank << "] At ease.\n"; // "Spocznij."
        break;

    case Command::MARCH:
        m_state = State::MARCHING;
        std::cout << "[" << m_rank << "] Marching forward!\n"; // "Wymarsz!"
        break;

    case Command::HALT:
        m_state = State::IDLE;
        std::cout << "[" << m_rank << "] Halted.\n"; // "Zatrzymuje sie."
        break;

    case Command::LEFT_FACE:

        std::cout << "[" << m_rank << "] Facing left.\n"; // "W lewo patrz!"
        break;

    case Command::RIGHT_FACE:
        std::cout << "[" << m_rank << "] Facing right.\n"; // "W prawo patrz!"
        break;

    case Command::FALL_IN:
        m_state = State::AT_ATTENTION;
        std::cout << "[" << m_rank << "] Falls in line!\n"; //"Do szeregu!"
        break;

    default:
        std::cout << "[" << m_rank << "] Command not recognized.\n";
        break;
    }
}
State Soldier::GetState() const {
    return m_state;
}

std::string Soldier::GetRank() const {
    return m_rank;
}


