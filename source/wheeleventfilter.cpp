#include "wheeleventfilter.h"

wheelEventFilter::wheelEventFilter(QObject *parent) : QObject(parent)
{

}

bool wheelEventFilter::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::Wheel) {
        return true;
    }
    return QObject::eventFilter(watched, event);
}
