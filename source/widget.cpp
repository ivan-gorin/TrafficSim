#include "widget.h"
#include "ui_widget.h"
#include "roaditem.h"
#include "wheeleventfilter.h"

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
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    wheelEventFilter* filter = new wheelEventFilter;
    ui->graphicsView->viewport()->installEventFilter(filter);
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
//        std::cout << eng->getVehicleCount() << std::endl;
        eng->nextStep();
        ++stepCount;
    }
}

void Widget::avgPrint()
{
    eng->printAverage();
}

void Widget::wheelEvent(QWheelEvent *event)
{
    QPoint pixels = event->pixelDelta();
    QPoint angle = event->angleDelta() / 8;
    if (!pixels.isNull()) {
        if (pixels.ry() > 0) {
            ui->graphicsView->scale(1.05, 1.05);
        } else if (pixels.ry() < 0) {
            ui->graphicsView->scale(0.95238095238095238, 0.95238095238095238);
        }
    } else if (!angle.isNull()) {
        if (angle.ry() > 0) {
            ui->graphicsView->scale(1.05, 1.05);
        } else if (angle.ry() < 0) {
            ui->graphicsView->scale(0.95238095238095238, 0.95238095238095238);
        }
    }
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
    eng->ChangeWeatherIntensity(ui->chooseIntensityBox->value());
    ui->weatherLabel->setText("Weather:\n" + ui->chooseWeatherBox->currentText());
}
