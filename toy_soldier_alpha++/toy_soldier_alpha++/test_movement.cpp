#include <QtTest/QtTest>
#include "soldier.h"


class TestSoldier : public Soldier {
public:
    using Soldier::Soldier;


    void exposeState(State state) { setState(state); }
    void exposeDirection(Direction dir) { setDirection(dir); }
};

class MovementTests : public QObject {
    Q_OBJECT

private slots:
    // Test 1: Sprawdzenie marszu
    void testMarchingRight() {
        TestSoldier soldier("Private");
        soldier.SetPosition(100, 100);


        soldier.exposeState(State::MARCHING);
        soldier.exposeDirection(Direction::RIGHT);

        soldier.UpdatePosition();

        QCOMPARE(soldier.GetX(), 110);
    }

    // Test 2: Sprawdzenie blokady krawędzi mapy
    void testMapBoundsLeft() {
        TestSoldier soldier("Private");
        soldier.SetPosition(35, 100);

        soldier.exposeState(State::MARCHING);
        soldier.exposeDirection(Direction::LEFT);

        soldier.UpdatePosition();

        QCOMPARE(soldier.GetX(), 30);
    }
};

void runMovementTests(int argc, char *argv[], int &status) {
    MovementTests testObj;
    status |= QTest::qExec(&testObj, argc, argv);
}

#include "test_movement.moc"