#include "lqpushbutton.h"

LQPushButton::LQPushButton(QWidget *parent)
    :QPushButton(parent)
{
    initForm();
}

LQPushButton::~LQPushButton()
{
}

void LQPushButton::initForm()
{
    this->setFixedSize(35,35);
    setStyleSheet(QString::fromLocal8Bit("QPushButton{color:#FFFFFF;}"));
    this->setFlat(true);
    this->setCursor(QCursor(Qt::PointingHandCursor));
}

