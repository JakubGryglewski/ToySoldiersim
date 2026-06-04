#ifndef MEDIC_H
#define MEDIC_H

#include "soldier.h"

class Medic : public Soldier
{
public:
    Medic(std::string rank, int medkits = 3);

    std::string ExecuteCommand(Command c) override;

private:
    int m_medkits;
};

#endif // MEDIC_H
