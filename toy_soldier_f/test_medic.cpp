/**
 * @file test_medic.cpp
 * @brief Weryfikacja podstawowych operacji zwiazanych z medykiem.
 */
#include <QtTest/QtTest>
#include "medic.h"

class MedicTests : public QObject {
    Q_OBJECT

private slots:
    /**
     * @brief Weryfikuje poprawne tworzenie obiektu medyka.
     * Sprawdza, czy nowo utworzony medyk posiada wlasciwa range.
     */
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
