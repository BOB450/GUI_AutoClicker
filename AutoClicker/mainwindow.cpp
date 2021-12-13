#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QPushButton>
#include <QMessageBox>
#include <QLineEdit>
#include <iostream>
#include <Windows.h>
#include <thread>
#include <QThread>
#include <QEventLoop>
#include <QtConcurrent>
#include <QFuture>

bool click = false;
double b;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::pushButton);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void autoclick()
{
    while (true)
    {
        //qApp->processEvents();
        if (GetAsyncKeyState('X')) //if X is pressed click = true
        {
            click = true;
        }
        else if (GetAsyncKeyState('Z')) //if 'Z' is pressed click = false
        {
            click = false;
        }
        if (click == true) // if click = true it will press the mouse button down and up really fast
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(b);
        }
    }
}


void MainWindow::pushButton()
{

  QString  textvalue = ui->lineEdit->displayText();



    double b = textvalue.toDouble();
    QMessageBox msgBox;
    msgBox.setText("Set click intervel to: " +  textvalue);
    msgBox.exec();


    click = false; //sets click to false
   QFuture<void> fu = QtConcurrent::run(autoclick);
}

