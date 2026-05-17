#ifndef MARKSMAN_H
#define MARKSMAN_H

#include "soldier.h"


class Marksman : public Soldier{
public:

    Marksman(std::string rank, int ammo = 5);


    void ExecuteCommand(Command c) override;

private:
    int m_ammo;
};




#endif // MARKSMAN_H
