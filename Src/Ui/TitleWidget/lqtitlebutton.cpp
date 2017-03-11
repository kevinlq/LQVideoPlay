#include "lqtitlebutton.h"

LQTitleButton::LQTitleButton(QWidget *parent) :
    QPushButton(parent)
{
    initForm();
}

LQTitleButton::~LQTitleButton()
{
}

void LQTitleButton::initForm()
{
    this->setFixedSize(30,30);
    setStyleSheet("QPushButton{color:#FFFFFF;}");
    this->setFlat(true);
    this->setCursor(QCursor(Qt::PointingHandCursor));
}
