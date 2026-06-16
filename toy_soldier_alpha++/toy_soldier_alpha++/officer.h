#ifndef OFFICER_H
#define OFFICER_H

#include "soldier.h"

class Officer : public Soldier {
public:
    Officer(std::string rank);

    std::string ExecuteCommand(Command c) override;
};

#endif // OFFICER_H