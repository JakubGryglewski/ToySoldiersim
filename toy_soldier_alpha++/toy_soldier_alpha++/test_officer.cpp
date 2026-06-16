#include <QtTest/QtTest>
#include "officer.h"

class OfficerTests : public QObject {
    Q_OBJECT

private slots:
    // Test 1: Sprawdzenie rangi oficera po utworzeniu
    void testOfficerCreation() {
        Officer officer("Captain");

        QCOMPARE(officer.GetRank(), std::string("Captain"));
    }
};


void runOfficerTests(int argc, char *argv[], int &status) {
    OfficerTests testObj;
    status |= QTest::qExec(&testObj, argc, argv);
}

#include "test_officer.moc"