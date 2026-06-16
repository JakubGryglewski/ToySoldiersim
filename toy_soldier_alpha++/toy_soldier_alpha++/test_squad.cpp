#include <QtTest/QtTest>
#include "squad.h"
#include "soldier.h"
#include <memory>

class SquadTests : public QObject {
    Q_OBJECT

private slots:
    // Test 1: Sprawdzenie, czy nowy oddział jest pusty
    void testSquadCreation() {
        Squad squad("Alpha Team");

        QCOMPARE(squad.GetSoldiers().size(), std::size_t(0));
    }

    // Test 2: Sprawdzenie dodawania żołnierza do oddziału
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