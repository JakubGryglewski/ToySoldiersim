#ifndef SOLDIER_H
#define SOLDIER_H
#include <string>
#include "isoldier.h"



class Soldier: public ISoldier
{
public:
    Soldier(std::string rank);

    void ExecuteCommand(Command c) override;
    State GetState() const override;
    std::string GetRank() const override;

protected:
    std::string m_rank;
    State m_state;
};




#endif // SOLDIER_H
