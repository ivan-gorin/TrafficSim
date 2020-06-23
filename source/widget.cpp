#include "widget.h"
#include "ui_widget.h"
#include "roaditem.h"

#include <QTimer>
#include <iostream>

#include <vector>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , doStep(false)
{
    ui->setupUi(this);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    eng = new CityFlow::Engine("config.json", 1, ui->graphicsView);
    QString wLabel = "Weather:\n";
    wLabel.append(eng->getWeather().c_str());
    ui->weatherLabel->setText(wLabel);
    QTimer* avgTimer = new QTimer(this);
    simTimer = new QTimer(this);
    connect(simTimer, &QTimer::timeout, this, &Widget::simStep);
    connect(avgTimer, &QTimer::timeout, this, &Widget::avgPrint);
    stepCount = 0;
    simTimer->start(16);
//    avgTimer->start(10000);
}

Widget::~Widget()
{
    delete ui;
    delete eng;
    delete simTimer;
}

void Widget::simStep()
{
//    std::cout << stepCount << std::endl;
    if (doStep) {
        eng->nextStep();
        ++stepCount;
    }
}

void Widget::avgPrint()
{
    eng->printAverage();
}

void Widget::on_zoomOutButton_clicked()
{
    ui->graphicsView->scale(0.5, 0.5);
}

void Widget::on_zoomInButton_clicked()
{
    ui->graphicsView->scale(2, 2);
}

void Widget::on_setIntervalButton_clicked()
{
    double new_int = (ui->chooseIntervalBox->value()) / 62.5;
    eng->setInterval(new_int);
}

void Widget::on_pauseButton_clicked()
{
    doStep = !doStep;
}

void Widget::on_setWeatherButton_clicked()
{
    eng->ChangeWeather(ui->chooseWeatherBox->currentText().toStdString());
    ui->weatherLabel->setText("Weather:\n" + ui->chooseWeatherBox->currentText());
}
