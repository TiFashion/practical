#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"
#include "scene.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    QBrush back(Qt::lightGray);
    ui->graphicsView->setBackgroundBrush(back);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(-40,40,80,80);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(scene->points.size()<4)
    {
        QMessageBox::critical(this, "Ошибка","Поставьте все точки!");
    }
    else
    {
        SecondWindow window;
        window.setModal(true);
        QString cross;
        if(scene->c==nullptr)
            cross = "Не пересекаются";
        else
            cross = QString::number(ceil(scene->cross.x())) + ";  " +  QString::number(ceil(scene->cross.y()));
        window.setValues(cross,
                QString::number(scene->ElliplesVector[0]->pos().x()) + ";  " + QString::number(scene->ElliplesVector[0]->pos().y()),
                QString::number(scene->ElliplesVector[1]->pos().x()) + ";  " + QString::number(scene->ElliplesVector[1]->pos().y()),
                QString::number(scene->ElliplesVector[2]->pos().x()) + ";  " + QString::number(scene->ElliplesVector[2]->pos().y()),
                QString::number(scene->ElliplesVector[3]->pos().x()) + ";  " + QString::number(scene->ElliplesVector[3]->pos().y()));
        window.exec();
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    scene->c=nullptr;
    scene->clear();
    scene->points.clear();
    scene->ElliplesVector.clear();
    scene->Lines.clear();
}

