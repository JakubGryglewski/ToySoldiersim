#include <QtTest/QtTest>
#include "marksman.h"

class MarksmanTests : public QObject {
    Q_OBJECT

private slots:
    // Test 1: Sprawdzenie rangi strzelca po utworzeniu
    void testMarksmanCreation() {
        Marksman marksman("Sniper");

        QCOMPARE(marksman.GetRank(), std::string("Sniper"));
    }
};


void runMarksmanTests(int argc, char *argv[], int &status) {
    MarksmanTests testObj;
    status |= QTest::qExec(&testObj, argc, argv);
}

#include "test_marksman.moc"