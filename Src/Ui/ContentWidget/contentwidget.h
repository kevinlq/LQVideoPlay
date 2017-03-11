#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include <QWidget>

class QLabel;
class PlayListWodget;
class QHBoxLayout;
class QTimer;

class LQvlcPlayer;

class ContentWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ContentWidget(QWidget *parent = 0);
    ~ContentWidget();
    
private:
    void initForm();
    void initLayout();

    void playOrPause();

protected:
    bool eventFilter(QObject *, QEvent *);

Q_SIGNALS:
    void signalShowFullScree();

    void signalPlayOrPause();

    void signalSendPlayTime(quint64 curTime,quint64 totalTime);

private Q_SLOTS:

    void slotPlayVideo(const QString &video);

    void slotGeVideoLenght();

    void slotSetPlayProgress(int);

    void slotUpdatePlayTime();

    void slotBackward();

    void slotSetPlayOrPose(bool);

    void slotForward();

private:
    QLabel *m_pVideoLabel;

    PlayListWodget *m_pPlayList;
    QHBoxLayout *m_pMainLayot;

    LQvlcPlayer *m_pVlc;
    bool m_isPress;

    QTimer *m_pGetPlayTime;
    
};

#endif // CONTENTWIDGET_H
