#include <QtTest/QtTest>
#include "medic.h"

class MedicTests : public QObject {
    Q_OBJECT

private slots:
    // Test 1: Sprawdzenie rangi medyka po utworzeniu
    void testMedicCreation() {
        Medic medic("Doc");
        QCOMPARE(medic.GetRank(), std::string("Doc"));
    }
};


void runMedicTests(int argc, char *argv[], int &status) {
    MedicTests testObj;
    status |= QTest::qExec(&testObj, argc, argv);
}

#include "test_medic.moc"