#ifndef WHEELEVENTFILTER_H
#define WHEELEVENTFILTER_H

#include <QObject>
#include <QEvent>
#include <QWheelEvent>

class wheelEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit wheelEventFilter(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

};

#endif // WHEELEVENTFILTER_H
