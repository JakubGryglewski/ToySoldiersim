#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "soldier.h"
#include "marksman.h"
#include "medic.h"
#include <QMessageBox>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_engine.CreateSquad("Alpha Strike Team");
    m_engine.AddSoldierToSquad(std::make_unique<Soldier>("Private"));
    m_engine.AddSoldierToSquad(std::make_unique<Soldier>("Sergeant"));
    m_engine.AddSoldierToSquad(std::make_unique<Marksman>("Private", 2));
    m_engine.AddSoldierToSquad(std::make_unique<Medic>("Lieutenant", 2));

    updateInterface();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStart_clicked() {
    m_engine.Start();
    updateInterface();
}

void MainWindow::on_btnPause_clicked() {
    m_engine.Pause();
    updateInterface();
}

void MainWindow::on_btnStop_clicked() {
    m_engine.Stop();
    updateInterface();
}

void MainWindow::on_btnStep_clicked() {
    if (m_engine.GetStatus() != SimulationStatus::RUNNING) {
        QMessageBox::warning(this, "Uwaga", "Symulacja nie jest uruchomiona!");
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
}
