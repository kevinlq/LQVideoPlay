#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

class TitleWidget;
class ContentWidget;
class StatusWidget;
class PlayProgress;

class QHBoxLayout;
class QVBoxLayout;

class EPlayControl;

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
    
private:
    void init();
    void initForm();
    void initLayout();
    void initConnect();

protected:
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseMoveEvent(QMouseEvent *);

Q_SIGNALS:
    void signalMax(bool);
    void signalSendFileInfo(const QStringList &path);


private Q_SLOTS:
    void slotShowMin();
    void slotShowMax();
    void slotCloseWidget();

    void slotOpenVideoFile();
    void slotShowFullScree();

private:
    TitleWidget     *m_pTitleWidget;
    ContentWidget   *m_pContentWidget;
    StatusWidget    *m_pStatusWidget;
    PlayProgress    *m_pPlayProgress;

    QVBoxLayout     *m_pMainLayout;

    /*Mouse move about*/
    bool m_mousePress;      //is move
    QPoint m_movePoint;     //move distence

    bool m_isFullScreen;    //is full screen
    bool m_isMax;           //is max

    EPlayControl *m_pEplay;
};

#endif // MAINWIDGET_H
