/**
 * @file test_squad.cpp
 * @brief Testy kontenera logistycznego gromadzacego wewnetrzna grupe bitewna.
 */
#include <QtTest/QtTest>
#include "squad.h"
#include "soldier.h"
#include <memory>

class SquadTests : public QObject {
    Q_OBJECT

private slots:
    /**
     * @brief Testuje zachowanie oddzialu bezposrednio po utworzeniu.
     * Sprawdza, czy poczatkowo utworzona grupa zolnierzy jest pusta (rozmiar wektora rowny 0).
     */
    void testSquadCreation() {
        Squad squad("Alpha Team");
        QCOMPARE(squad.GetSoldiers().size(), std::size_t(0));
    }

    /**
     * @brief Weryfikuje mechanizm zarzadzania personelem oddzialu.
     * Sprawdza dodawanie zolnierza do grupy i upewnia sie, ze licznik zolnierzy wzrasta o jeden.
     */
    void testAddSoldier() {
        Squad squad("Bravo Team");
        auto soldier = std::make_unique<Soldier>("Private");
        squad.AddSoldier(std::move(soldier));
        QCOMPARE(squad.GetSoldiers().size(), std::size_t(1));
    }
};

void runSquadTests(int argc, char *argv[], int &status) {
    SquadTests testObj;
    status |= QTest::qExec(&testObj, argc, argv);
}

#include "test_squad.moc"
