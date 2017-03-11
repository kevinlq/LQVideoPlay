#include "ewidgetcontrol.h"

EWidgetControl::EWidgetControl(QObject *parent) :
    QObject(parent)
{
    initAll();
}

EWidgetControl::~EWidgetControl()
{
}

void EWidgetControl::initAll()
{
    initForm();
    initConnect();
}

void EWidgetControl::initForm()
{
}

void EWidgetControl::initConnect()
{
}
