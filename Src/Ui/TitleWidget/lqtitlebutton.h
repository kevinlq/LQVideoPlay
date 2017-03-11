#ifndef LQTITLEBUTTON_H
#define LQTITLEBUTTON_H

#include <QPushButton>

class LQTitleButton : public QPushButton
{
    Q_OBJECT
public:
    explicit LQTitleButton(QWidget *parent = 0);
    ~LQTitleButton();

private:
    void initForm();
    
};

#endif // LQTITLEBUTTON_H
