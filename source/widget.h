#ifndef WIDGET_H
#define WIDGET_H
#include "engine.h"


#include <QWidget>
#include <string>
#include <QWheelEvent>
#include <QElapsedTimer>

//QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
//QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void simStep();
    void avgPrint();

protected:
    void wheelEvent(QWheelEvent* event) override;

private slots:
    void on_zoomOutButton_clicked();

    void on_zoomInButton_clicked();

    void on_setIntervalButton_clicked();

    void on_pauseButton_clicked();

    void on_setWeatherButton_clicked();

private:
    Ui::Widget *ui;
    CityFlow::Engine* eng;
    long long stepCount;
    bool doStep;
    QTimer* simTimer;
};
#endif // WIDGET_H
