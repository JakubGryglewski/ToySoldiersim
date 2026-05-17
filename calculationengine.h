#ifndef CALCULATIONENGINE_H
#define CALCULATIONENGINE_H

#include "squad.h"

enum class SimulationStatus { STOPPED, RUNNING, PAUSED };

class CalculationEngine
{
public:
    CalculationEngine(Squad* squad);

    void Initialize();
    void DoSimulationStep(Command c);
    void Stop();

    SimulationStatus GetStatus() const;
    long GetCurrentStep() const;

private:
    Squad* m_squad;
    SimulationStatus m_status;
    long m_simulationStep;

};

#endif // CALCULATIONENGINE_H
