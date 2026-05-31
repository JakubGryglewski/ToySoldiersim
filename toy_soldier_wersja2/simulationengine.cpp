#include "simulationengine.h"

simulationengine::simulationengine()
    : m_status(SimulationStatus::STOPPED), m_squad(nullptr)
{
}

void simulationengine::Start() {
    m_status = SimulationStatus::RUNNING;
}

void simulationengine::Stop() {
    m_status = SimulationStatus::STOPPED;
}

void simulationengine::Pause() {
    if (m_status == SimulationStatus::RUNNING) {
        m_status = SimulationStatus::PAUSED;
    }
}

SimulationStatus simulationengine::GetStatus() const {
    return m_status;
}

void simulationengine::CreateSquad(const std::string& name) {
    m_squad = std::make_unique<Squad>(name);
}

void simulationengine::AddSoldierToSquad(std::unique_ptr<ISoldier> soldier) {
    if (m_squad) {
        m_squad->AddSoldier(std::move(soldier));
    }
}

std::vector<std::string> simulationengine::ExecuteBroadcastCommand(Command c) {
    if (m_status != SimulationStatus::RUNNING) {
        return {"[SYSTEM] Symulacja wstrzymana lub zatrzymana. Rozkaz zignorowany."};
    }
    if (!m_squad) {
        return {"[SYSTEM] Brak aktywnego oddziału."};
    }

    return m_squad->BroadcastCommand(c);
}

std::vector<std::string> simulationengine::ExecuteCommandForRank(Command c, const std::string& targetRank) {
    if (m_status != SimulationStatus::RUNNING) {
        return {"[SYSTEM] Symulacja wstrzymana lub zatrzymana. Rozkaz zignorowany."};
    }
    if (!m_squad) {
        return {"[SYSTEM] Brak aktywnego oddziału."};
    }

    return m_squad->IssueCommandToRank(c, targetRank);
}

std::string simulationengine::GetLogisticsReport() const {
    if (!m_squad) {
        return "[SYSTEM] Brak aktywnego oddziału do zaraportowania.\n";
    }
    return m_squad->GenerateLogisticsReport();
}
