#ifndef LQPUSHBUTTON_H
#define LQPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>


class LQPushButton : public QPushButton
{
public:
    LQPushButton(QWidget *parent = 0);
    ~LQPushButton();

private:
    void initForm();

};

#endif // LQPUSHBUTTON_H
