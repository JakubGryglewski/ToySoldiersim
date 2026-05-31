#include "squad.h"
#include <map>

Squad::Squad(std::string name) : m_name(name) {}

void Squad::AddSoldier(std::unique_ptr<ISoldier> soldier) {
    m_soldiers.push_back(std::move(soldier));
}

std::vector<std::string> Squad::BroadcastCommand(Command c) {
    std::vector<std::string> report;
    report.push_back("--- SQUAD COMMANDER: Broadcast Command ---");
    for (const auto& soldier : m_soldiers) {
        report.push_back(soldier->ExecuteCommand(c));
    }
    return report;
}

std::vector<std::string> Squad::IssueCommandToRank(Command c, const std::string& targetRank) {
    std::vector<std::string> report;
    report.push_back("--- SQUAD COMMANDER: Command for rank [" + targetRank + "] ---");
    for (const auto& soldier : m_soldiers) {
        if (soldier->GetRank() == targetRank) {
            report.push_back(soldier->ExecuteCommand(c));
        }
    }
    return report;
}

std::string Squad::GenerateLogisticsReport() const {
    std::map<std::string, int> rankCounts;

    for (const auto& soldier : m_soldiers) {
        rankCounts[soldier->GetRank()]++;
    }

    std::string report = "\n====================================\n";
    report += " LOGISTICS REPORT: " + m_name + "\n";
    report += "Total personnel: " + std::to_string(m_soldiers.size()) + "\n";
    report += "------------------------------------\n";
    for (const auto& pair : rankCounts) {
        report += " - " + pair.first + ": " + std::to_string(pair.second) + "\n";
    }
    report += "====================================\n";

    return report;
}
