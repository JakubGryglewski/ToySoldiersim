#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "soldier.h"
#include "marksman.h"
#include "medic.h"
#include "officer.h"
#include "soldieritem.h"
#include <QMessageBox>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // - INICJALIZACJA SCENY GRAFICZNEJ
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 800, 600);
    ui->simulationBoard->setScene(scene);

    // SILNIK
    m_engine.CreateSquad("Alpha Strike Team");
    m_engine.AddSoldierToSquad(std::make_unique<Soldier>("Private"));
    m_engine.AddSoldierToSquad(std::make_unique<Soldier>("Sergeant"));
    m_engine.AddSoldierToSquad(std::make_unique<Marksman>("Private", 2));
    m_engine.AddSoldierToSquad(std::make_unique<Officer>("Lieutenant"));
    m_engine.AddSoldierToSquad(std::make_unique<Medic>("Corporal", 3));

    Squad* mySquad = m_engine.GetSquad();

    if (mySquad) {
        const auto& soldiers = mySquad->GetSoldiers();
        for (const auto& soldierPtr : soldiers) {
            SoldierItem* item = new SoldierItem(soldierPtr.get());
            scene->addItem(item);
        }
    }

    simulationTimer = new QTimer(this);


    connect(simulationTimer, &QTimer::timeout, this, [this]() {
        if (m_engine.GetStatus() == SimulationStatus::RUNNING) {
            m_engine.UpdateSimulation();
            updateInterface();
        }
    });

    connect(ui->comboFormation, &QComboBox::currentTextChanged, this, &MainWindow::onFormationChanged);


    connect(ui->comboCommands, &QComboBox::currentTextChanged, this, &MainWindow::onCommandChanged);

    applyFormation();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked() {
    m_engine.Start();
    simulationTimer->start(100);
    updateInterface();
}

void MainWindow::on_btnPause_clicked() {
    m_engine.Pause();
    simulationTimer->stop();
    updateInterface();
}

void MainWindow::on_btnStop_clicked() {
    m_engine.Stop();
    simulationTimer->stop();
    updateInterface();
}


void MainWindow::on_btnStep_clicked() {
    if (m_engine.GetStatus() != SimulationStatus::RUNNING) {
        QMessageBox::warning(this, "Warning", "Simulation is not running! Click the Start (Play) button first.");
        return;
    }

    onCommandChanged();
}

void MainWindow::onCommandChanged() {
    if (m_engine.GetStatus() != SimulationStatus::RUNNING) {
        return;
    }

    QString cmdStr = ui->comboCommands->currentText();
    Command c = Command::ATTENTION;

    if(cmdStr == "Attention") c = Command::ATTENTION;
    else if(cmdStr == "March") c = Command::MARCH;
    else if(cmdStr == "Halt") c = Command::HALT;
    else if(cmdStr == "At Ease") c = Command::AT_EASE;
    else if(cmdStr == "Left Face") c = Command::LEFT_FACE;
    else if(cmdStr == "Right Face") c = Command::RIGHT_FACE;


    std::vector<std::string> logs = m_engine.ExecuteBroadcastCommand(c);


    QStringList msgList;
    for (const auto& log : logs) {
        msgList << QString::fromStdString(log);
    }
    QMessageBox::information(this, "Raport Logów", msgList.join("\n"));

    updateInterface();
}

void MainWindow::updateInterface() {
    QString statusStr;
    switch(m_engine.GetStatus()) {
    case SimulationStatus::RUNNING: statusStr = "RUNNING"; break;
    case SimulationStatus::PAUSED: statusStr = "PAUSED"; break;
    case SimulationStatus::STOPPED: statusStr = "STOPPED"; break;
    }

    QString stats = "Status: " + statusStr + "\n" + QString::fromStdString(m_engine.GetLogisticsReport());
    ui->lblStats->setText(stats);

    // SYNCHRONIZACJA GRAFIKI Z LOGIKĄ
    for (QGraphicsItem* item : scene->items()) {
        SoldierItem* soldierItem = dynamic_cast<SoldierItem*>(item);
        if (soldierItem) {
            soldierItem->syncPosition();
        }
    }

    scene->update();
}

void MainWindow::applyFormation() {
    Squad* mySquad = m_engine.GetSquad();
    if (!mySquad) return;

    const auto& soldiers = mySquad->GetSoldiers();
    if (soldiers.empty()) return;

    QString currentFormation = ui->comboFormation->currentText();


    int startX = soldiers[0]->GetX();
    int startY = soldiers[0]->GetY();

    int i = 0;

    for (const auto& soldierPtr : soldiers) {

        if (currentFormation == "Line") {
            soldierPtr->SetPosition(startX + (i * 80), startY);
        }
        else if (currentFormation == "Column") {
            soldierPtr->SetPosition(startX, startY + (i * 60));
        }
        else if (currentFormation == "Wedge") {
            if (i == 0) {
                soldierPtr->SetPosition(startX, startY);
            }
            else {
                int row = (i + 1) / 2;
                int side = (i % 2 == 0) ? 1 : -1;


                int xOffset = startX + (side * row * 60);
                int yOffset = startY + (row * 50);

                soldierPtr->SetPosition(xOffset, yOffset);
            }
        }

        i++;
    }

    updateInterface();
}

void MainWindow::onFormationChanged() {
    applyFormation();
}

void MainWindow::on_btnReset_clicked() {

    simulationTimer->stop();


    m_engine.Stop();


    Squad* mySquad = m_engine.GetSquad();
    if (mySquad && !mySquad->GetSoldiers().empty()) {
        mySquad->GetSoldiers()[0]->SetPosition(150, 150);
    }


    ui->comboFormation->setCurrentText("Line");


    applyFormation();
}
