#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include <memory>
#include <vector>
#include <string>
#include "squad.h"
#include "isoldier.h"

enum class SimulationStatus { STOPPED, RUNNING, PAUSED };

class simulationengine
{
public:
    simulationengine();

    // Zarządzanie stanem symulacji
    void Start();
    void Stop();
    void Pause();
    SimulationStatus GetStatus() const;

    // Zarządzanie oddziałem
    void CreateSquad(const std::string& name);
    void AddSoldierToSquad(std::unique_ptr<ISoldier> soldier);

    // Wydawanie rozkazów i raportów
    std::vector<std::string> ExecuteBroadcastCommand(Command c);
    std::vector<std::string> ExecuteCommandForRank(Command c, const std::string& targetRank);
    std::string GetLogisticsReport() const;

private:
    SimulationStatus m_status;
    std::unique_ptr<Squad> m_squad;
};

#endif // SIMULATIONENGINE_H
