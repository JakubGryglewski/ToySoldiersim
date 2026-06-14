#ifndef SOLDIER_H
#define SOLDIER_H

#include <string>
#include "isoldier.h"

class Soldier : public ISoldier
{
public:
    Soldier(std::string rank);

    std::string ExecuteCommand(Command c) override;
    State GetState() const override;
    std::string GetRank() const override;
    int GetX() const override { return m_x; }
    int GetY() const override { return m_y; }
    Direction GetDirection() const override { return m_direction; }
    void SetPosition(int x, int y) override { m_x = x; m_y = y; }

    void UpdatePosition() override {
        if (m_state == State::MARCHING) {
            switch (m_direction) {
            case Direction::RIGHT: m_x += 10; break;
            case Direction::LEFT:  m_x -= 10; break;
            case Direction::DOWN:  m_y += 10; break;
            case Direction::UP:    m_y -= 10; break;
            }
        }
    }

protected:
    std::string m_rank;


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
