#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    msg_ = new QMessageBox(this);

    bd_ = new DBPlants();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bd_;
}


void MainWindow::on_pB_Action_clicked()
{
    bd_->AddDataBase("PSQL", "PlantDB");


    bool connected = bd_->ConnectToDataBase(bd_->ConnectionInfo());

    if(connected)
    {
        ui->statusbar->showMessage(bd_->databaseName());
    }
    else
    {
        bd_->DisconnectDataBase();
        msg_->setIcon(QMessageBox::Critical);
        msg_->setText(bd_->GetLastError().text());
        msg_->exec();
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->statusbar->clearMessage();
}

