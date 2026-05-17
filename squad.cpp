#include "squad.h"
#include <iostream>
#include <map>

// Konstruktor
Squad::Squad(std::string name) : m_name(name) {
}


void Squad::AddSoldier(std::unique_ptr<ISoldier> soldier) {
    m_soldiers.push_back(std::move(soldier));
}


void Squad::BroadcastCommand(Command c) {
    std::cout << "\n--- SQUAD COMMANDER: Broadcast Command ---\n";
    for (const auto& soldier : m_soldiers) {
        soldier->ExecuteCommand(c);
    }
}


void Squad::IssueCommandToRank(Command c, const std::string& targetRank) {
    std::cout << "\n--- SQUAD COMMANDER: Command for rank [" << targetRank << "] ---\n";
    for (const auto& soldier : m_soldiers) {

        if (soldier->GetRank() == targetRank) {
            soldier->ExecuteCommand(c);
        }
    }
}

// Zestawienie logistyczne zliczające wojsko w kontenerze
void Squad::PrintLogisticsReport() const {
    std::map<std::string, int> rankCounts;


    for (const auto& soldier : m_soldiers) {
        rankCounts[soldier->GetRank()]++;
    }

    std::cout << "\n====================================\n";
    std::cout << " LOGISTICS REPORT: " << m_name << "\n";
    std::cout << "Total personnel: " << m_soldiers.size() << "\n";
    std::cout << "------------------------------------\n";
    for (const auto& pair : rankCounts) {
        std::cout << " - " << pair.first << ": " << pair.second << "\n";
    }
    std::cout << "====================================\n";
}