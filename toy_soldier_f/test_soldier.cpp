/**
 * @file test_soldier.cpp
 * @brief Glowny plik integrujacy uruchamianie poszczegolnych testow w calosc oraz sprawdzajacy bazowe wlasciwosci zolnierza.
 */
#include <QtTest/QtTest>
#include "soldier.h"

class ToyTests : public QObject {
    Q_OBJECT
private slots:
    /**
     * @brief Sprawdza mechanizm manipulacji pozycja bazowego zolnierza.
     * Weryfikuje poprawne dzialanie funkcji ustawiajacej (SetPosition) i pobierajacej (GetX, GetY) wspolrzedne.
     */
    void testBasePosition() {
        Soldier soldier("Private");
        soldier.SetPosition(100, 200);
        QCOMPARE(soldier.GetX(), 100);
        QCOMPARE(soldier.GetY(), 200);
    }
};

int main(int argc, char *argv[]) {
    int status = 0;

    {
        ToyTests testObj;
        status |= QTest::qExec(&testObj, argc, argv);
    }
    {
        extern void runSquadTests(int argc, char *argv[], int &status);
        runSquadTests(argc, argv, status);
    }
    {
        extern void runOfficerTests(int argc, char *argv[], int &status);
        runOfficerTests(argc, argv, status);
    }
    {
        extern void runMarksmanTests(int argc, char *argv[], int &status);
        runMarksmanTests(argc, argv, status);
    }
    {
        extern void runEngineTests(int argc, char *argv[], int &status);
        runEngineTests(argc, argv, status);
    }
    {
        extern void runMedicTests(int argc, char *argv[], int &status);
        runMedicTests(argc, argv, status);
    }
    {
        extern void runMovementTests(int argc, char *argv[], int &status);
        runMovementTests(argc, argv, status);
    }

    return status;
}

#include "test_soldier.moc"
