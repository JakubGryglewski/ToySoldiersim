/**
 * @file test_engine.cpp
 * @brief Zestaw testow weryfikujacych zmiany statusu calej symulacji.
 */
#include <QtTest/QtTest>
#include "simulationengine.h"

class EngineTests : public QObject {
    Q_OBJECT

private slots:
    /**
     * @brief Weryfikuje kompleksowy cykl zycia silnika.
     * Sprawdza poprawne przejscie ze stanu zatrzymania (STOPPED) do dzialania (RUNNING).
     */
    void testEngineLifecycle() {
        simulationengine engine;
        QCOMPARE(engine.GetStatus(), SimulationStatus::STOPPED);
        engine.Start();
        QCOMPARE(engine.GetStatus(), SimulationStatus::RUNNING);
    }
};

void runEngineTests(int argc, char *argv[], int &status) {
    EngineTests testObj;
    status |= QTest::qExec(&testObj, argc, argv);
}

#include "test_engine.moc"
