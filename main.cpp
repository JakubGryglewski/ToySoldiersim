#include <iostream>
#include <memory>
#include "squad.h"
#include "soldier.h"
#include "marksman.h"
#include "medic.h"

int main() {
    std::cout << "=== MILITARY SIMULATION START ===\n\n";

    // 1.  kontener-zarządca (Oddział Alfa)
    Squad alphaSquad("Alpha Strike Team");

    // podstawowi żołnierze (Soldier)
    alphaSquad.AddSoldier(std::make_unique<Soldier>("Private"));
    alphaSquad.AddSoldier(std::make_unique<Soldier>("Sergeant"));

    // 3.  Strzelcy Wyborowi (Marksman) - 2 sztuki amunicji
    alphaSquad.AddSoldier(std::make_unique<Marksman>("Private", 2));
    alphaSquad.AddSoldier(std::make_unique<Marksman>("Corporal", 2));

    // 4.  Medyk (Medic) -  2 apteczki
    alphaSquad.AddSoldier(std::make_unique<Medic>("Private", 2));
    alphaSquad.AddSoldier(std::make_unique<Medic>("Lieutenant", 2));

    // TEST 1: Zestawienie logistyczne kontenera (Nasza mapa w akcji - zliczanie rang)
    alphaSquad.PrintLogisticsReport();

    // TEST 2: Rozkaz dla całego oddziału (Wszyscy idą do szeregu, potem maszerują)
    alphaSquad.BroadcastCommand(Command::FALL_IN);
    alphaSquad.BroadcastCommand(Command::MARCH);

    // TEST 3: Polimorfizm przy zwrotach (Snajperzy celują z lunety, reszta zwykle się obraca)
    alphaSquad.BroadcastCommand(Command::LEFT_FACE);

    // TEST 4: Kolejny zwrot (Snajperom skończy się amunicja, więc wyciągają broń boczną)
    alphaSquad.BroadcastCommand(Command::RIGHT_FACE);

    // TEST 5: Filtracja rangi (Rozkaz "Spocznij" trafia TYLKO do rangi "Private")
    // Zwykły szeregowy odpocznie, snajper odpocznie, a Medyk-Private zacznie leczyć!
    // Porucznik i kapral zignorują ten rozkaz, bo ranga się nie zgadza.
    alphaSquad.IssueCommandToRank(Command::AT_EASE, "Private");

    std::cout << "\n=== MILITARY SIMULATION END ===\n";
    return 0;
}