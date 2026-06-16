#include <QtTest/QtTest>
#include "soldier.h"


class ToyTests : public QObject {
    Q_OBJECT
private slots:
    // Test 1: Sprawdzenie pozycji żołnierza
    void testBasePosition() {
        Soldier soldier("Private");
        soldier.SetPosition(100, 200);
        QCOMPARE(soldier.GetX(), 100);
        QCOMPARE(soldier.GetY(), 200);
    }



};

int main(int argc, char *argv[]) {
    int status = 0;

    // 1. Testy żołnierzy, medyków
    {
        ToyTests testObj;
        status |= QTest::qExec(&testObj, argc, argv);
    }

    // 2. Testy oddziałów (Squad)
    {
        extern void runSquadTests(int argc, char *argv[], int &status);
        runSquadTests(argc, argv, status);
    }

    // 3. Testy oficerów (Officer)
    {
        extern void runOfficerTests(int argc, char *argv[], int &status);
        runOfficerTests(argc, argv, status);
    }

    // 4. Testy strzelców (Marksman)
    {
        extern void runMarksmanTests(int argc, char *argv[], int &status);
        runMarksmanTests(argc, argv, status);
    }

    // 5. Testy silnika symulacji (Engine)
    {
        extern void runEngineTests(int argc, char *argv[], int &status);
        runEngineTests(argc, argv, status);
    }

    // 6. Testy medyków (Medic)
    {
        extern void runMedicTests(int argc, char *argv[], int &status);
        runMedicTests(argc, argv, status);
    }

    // 7. Testy ruchu (Movement)
    {
        extern void runMovementTests(int argc, char *argv[], int &status);
        runMovementTests(argc, argv, status);
    }

    return status;
}

#include "test_soldier.moc"