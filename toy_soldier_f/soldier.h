#ifndef SOLDIER_H
#define SOLDIER_H

#include <string>
#include "isoldier.h"

/**
 * @file soldier.h
 * @brief Deklaracja podstawowej klasy Soldier.
 */

/**
 * @class Soldier
 * @brief Klasa bazowa implementujaca interfejs ISoldier.
 */
class Soldier : public ISoldier
{
public:
    /**
     * @brief Konstruktor zolnierza.
     * @param rank Stopien wojskowy zolnierza.
     */
    Soldier(std::string rank);

    std::string ExecuteCommand(Command c) override;
    State GetState() const override;
    std::string GetRank() const override;
    int GetX() const override { return m_x; }
    int GetY() const override { return m_y; }
    Direction GetDirection() const override { return m_direction; }
    void SetPosition(int x, int y) override { m_x = x; m_y = y; }

    /**
     * @brief Aktualizuje pozycje zolnierza bazujac na jego stanie i kierunku.
     */
    void UpdatePosition() override {
        if (m_state == State::MARCHING) {
            switch (m_direction) {
            case Direction::RIGHT: m_x += 10; break;
            case Direction::LEFT:  m_x -= 10; break;
            case Direction::DOWN:  m_y += 10; break;
            case Direction::UP:    m_y -= 10; break;
            }

            if (m_x < 30) m_x = 30;
            if (m_x > 1650) m_x = 1650;

            if (m_y < 30) m_y = 30;
            if (m_y > 950) m_y = 950;
        }
    }

protected:
    std::string m_rank; ///< Stopien wojskowy.

    void setState(State state) { m_state = state; }
    void setDirection(Direction dir) { m_direction = dir; }
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }

private:
    State m_state;
    int m_x = 0;
    int m_y = 0;
    Direction m_direction = Direction::RIGHT;
};

#endif // SOLDIER_H
