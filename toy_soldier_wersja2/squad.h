#ifndef SQUAD_H
#define SQUAD_H

#include <vector>
#include <memory>
#include <string>
#include "isoldier.h"

class Squad
{
public:
    Squad(std::string name);

    void AddSoldier(std::unique_ptr<ISoldier> soldier);

    std::vector<std::string> BroadcastCommand(Command c);
    std::vector<std::string> IssueCommandToRank(Command c, const std::string& targetRank);

    std::string GenerateLogisticsReport() const;

private:
    std::string m_name;
    std::vector<std::unique_ptr<ISoldier>> m_soldiers;
};

#endif // SQUAD_H
