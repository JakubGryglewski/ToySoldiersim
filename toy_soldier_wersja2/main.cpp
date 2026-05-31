#include <iostream>
#include <memory>
#include <vector>
#include "simulationengine.h"
#include "soldier.h"
#include "marksman.h"
#include "medic.h"

void PrintLogs(const std::vector<std::string>& logs) {
    for (const auto& log : logs) {
        std::cout << log << "\n";
    }
}

int main() {
    std::cout << "=== MILITARY SIMULATION ENGINE TEST ===\n\n";

    // Tworzenie głównego silnika (backend aplikacji)
    simulationengine engine;

    // Próba wydania rozkazu przed uruchomieniem symulacji (nie zadziała)
    PrintLogs(engine.ExecuteBroadcastCommand(Command::ATTENTION));

    // Inicjalizacja oddziału z poziomu silnika
    engine.CreateSquad("Alpha Strike Team");
    engine.AddSoldierToSquad(std::make_unique<Soldier>("Private"));
    engine.AddSoldierToSquad(std::make_unique<Soldier>("Sergeant"));
    engine.AddSoldierToSquad(std::make_unique<Marksman>("Private", 2));
    engine.AddSoldierToSquad(std::make_unique<Medic>("Lieutenant", 2));

    // Uruchamianie symulacji
    std::cout << "\n[SYSTEM] Uruchamiam symulacje...\n";
    engine.Start();

    // Testy poprawnego działania
    std::cout << engine.GetLogisticsReport() << "\n";
    PrintLogs(engine.ExecuteBroadcastCommand(Command::FALL_IN));

    // Zatrzymywanie symulacji
    std::cout << "\n[SYSTEM] Pauzuje symulacje...\n";
    engine.Pause();

    // Próba wydania rozkazu po spauzowaniu symulacji (nie zadziała)
    PrintLogs(engine.ExecuteBroadcastCommand(Command::MARCH));

    // Wznowienie syumlacji
    std::cout << "\n[SYSTEM] Wznawiam symulacje...\n";
    engine.Start();

    // Ten rozkaz zadziała
    PrintLogs(engine.ExecuteBroadcastCommand(Command::MARCH));

    // Zakończenie symulacji
    std::cout << "\n=== MILITARY SIMULATION ENGINE END ===\n";
    engine.Stop();

    // Próba wydania rozkazu po zakończeniu symulacji (nie zadziała)
    PrintLogs(engine.ExecuteBroadcastCommand(Command::MARCH));

    return 0;
}
