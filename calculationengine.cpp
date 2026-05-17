#include "calculationengine.h"
#include <iostream>

CalculationEngine::CalculationEngine(Squad* squad)
    : m_squad(squad), m_status(SimulationStatus::STOPPED), m_simulationStep(0)
{
}

void CalculationEngine::Initialize() {
    m_status = SimulationStatus::RUNNING;
    m_simulationStep = 0;
    std::cout << "--- Calculation Engine Active ---\n";
}


void CalculationEngine::DoSimulationStep(Command c) {

    if (m_status != SimulationStatus::RUNNING || m_squad == nullptr) {
        return;
    }

    m_simulationStep++;
    std::cout << "\n[Step " << m_simulationStep << "] Engine processing command...\n";


    m_squad->BroadcastCommand(c);
}

void CalculationEngine::Stop() {
    m_status = SimulationStatus::STOPPED;
    std::cout << "\n--- Calculation Engine Offline ---\n";
}

SimulationStatus CalculationEngine::GetStatus() const {
    return m_status;
}
long CalculationEngine::GetCurrentStep() const {
    return m_simulationStep;
}