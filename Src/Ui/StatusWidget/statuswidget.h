#ifndef STATUSWIDGET_H
#define STATUSWIDGET_H

#include <QWidget>

class QLabel;
class LQPushButton;
class LQVoiceWidget;
class QHBoxLayout;

class StatusWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StatusWidget(QWidget *parent = 0);
    ~StatusWidget();
    
private:
    void init();
    void initForm();
    void initLayout();
    void initConnect();

Q_SIGNALS:
    void signalOpenVideoFile();
    void signalPreVideo();
    void signalPlayOrStopVideo(bool);
    void signalNextVideo();
    void signalStopVideo();

private Q_SLOTS:
    void slotPlayOrPose();

private:
    QWidget      *m_pBackWidget;
    LQPushButton *m_pPrePbn;
    LQPushButton *m_pPlayPbn;
    LQPushButton *m_pNextPbn;
    LQPushButton *m_pStopPbn;

    LQVoiceWidget *m_pVoiceWidget;

    LQPushButton *m_pOpenFilePbn;

    QHBoxLayout *m_pMainLayout;

    bool m_isPlay;
};

#endif // STATUSWIDGET_H
