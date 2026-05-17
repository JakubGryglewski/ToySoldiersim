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

    void BroadcastCommand(Command c);

    void IssueCommandToRank(Command c, const std::string& targetRank);


    //size_t GetSize() const;


    void PrintLogisticsReport() const;

private:
    std::string m_name;

    std::vector<std::unique_ptr<ISoldier>> m_soldiers;

};

#endif // SQUAD_H
