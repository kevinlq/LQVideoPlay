#ifndef PLAYPROGRESS_H
#define PLAYPROGRESS_H

#include <QWidget>

class QSlider;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;

class PlayProgress : public QWidget
{
    Q_OBJECT
public:
    explicit PlayProgress(QWidget *parent = 0);

    ~PlayProgress();

private:
    void initForm();

    void initConnect();

Q_SIGNALS:
    void signalProgressValueChange(int value);
private Q_SLOTS:
    //update the video play progress
    void slotUpdatePlayProgress(quint64 curTime,quint64 TotalTime);

private:
    QWidget *m_pBackWidget;
    QSlider *m_pProgress;

    QLabel *m_pTotalPlayTileLabel;
    QLabel *m_pCurPlayTimeLabel;
    QHBoxLayout *m_pLabelLayout;

    QVBoxLayout *m_pMainLayout;
    
};

#endif // PLAYPROGRESS_H
