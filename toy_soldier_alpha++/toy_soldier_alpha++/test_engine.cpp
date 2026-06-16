#include <QtTest/QtTest>
#include "simulationengine.h"

class EngineTests : public QObject {
    Q_OBJECT

private slots:
    // Test 1: Kompleksowe sprawdzenie zmiany stanów silnika
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