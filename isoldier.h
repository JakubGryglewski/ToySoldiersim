#ifndef ISOLDIER_H
#define ISOLDIER_H

#include <string>
enum class Command { ATTENTION, AT_EASE, LEFT_FACE, RIGHT_FACE, FALL_IN, MARCH, HALT };

enum class State { IDLE, AT_ATTENTION, MARCHING };


class ISoldier {
public:

    virtual ~ISoldier() = default;


    virtual void ExecuteCommand(Command c) = 0;
    virtual State GetState() const = 0;
    virtual std::string GetRank() const = 0;
};

#endif // ISOLDIER_H
