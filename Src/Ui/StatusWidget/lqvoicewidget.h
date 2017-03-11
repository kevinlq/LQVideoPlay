#ifndef LQVOICEWIDGET_H
#define LQVOICEWIDGET_H

#include <QWidget>

class QSlider;
class QHBoxLayout;
class LQPushButton;

class LQVoiceWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LQVoiceWidget(QWidget *parent = 0);
    ~LQVoiceWidget();

private:
    void init();
    void initForm();
    void initLayout();
    void initConnect();

Q_SIGNALS:
    void signalVoiceValueChange(int);
    void signalSendNoVoice();

private Q_SLOTS:
    void slotNoVoice();

private:
    QWidget      *m_pBackWidget;
    LQPushButton *m_pVoiceButton;
    QSlider      *m_pVoiceSlider;

    QHBoxLayout  *m_pMainLayout;

    bool m_isNoVoice;
};

#endif // QLVOICEWIDGET_H
