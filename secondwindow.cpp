#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "scene.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::setValues(QString v1, QString v2, QString v3, QString v4, QString v5)
{
    ui->kord->setText(v1);
    ui->kord2->setText(v2);
    ui->kord3->setText(v3);
    ui->kord4->setText(v4);
    ui->kord5->setText(v5);
}

void SecondWindow::on_pushButton_clicked()
{
}

