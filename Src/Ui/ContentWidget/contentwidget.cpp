#include "contentwidget.h"

#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>
#include <QEvent>
#include <QTimer>

#include "playlistwodget.h"

#include "lqvlcplayer.h"

ContentWidget::ContentWidget(QWidget *parent) :
    QWidget(parent)
{
    initForm();
    initLayout();
}

ContentWidget::~ContentWidget()
{
    /*Close vlc media source*/
    if (m_pVlc != NULL){
        m_pVlc->Close();
        delete m_pVlc;
        m_pVlc = NULL;
    }
}

void ContentWidget::initForm()
{
    m_isPress = false;

    m_pVideoLabel = new QLabel;
    m_pVideoLabel->setStyleSheet("border-image:url(:/Images/home/play.png)");
    m_pVideoLabel->installEventFilter(this);

    m_pPlayList = new PlayListWodget;

    m_pVlc = new LQvlcPlayer(this);
    m_pGetPlayTime = new QTimer(this);
    m_pGetPlayTime->setInterval(1000);
    connect(m_pGetPlayTime,SIGNAL(timeout()),
            this,SLOT(slotUpdatePlayTime()));
}

void ContentWidget::initLayout()
{
    m_pMainLayot = new QHBoxLayout(this);
    m_pMainLayot->addWidget(m_pPlayList);
    m_pMainLayot->addWidget(m_pVideoLabel,Qt::AlignCenter);
    m_pMainLayot->setSpacing(0);
    m_pMainLayot->setContentsMargins(0,0,0,0);

    this->setLayout(m_pMainLayot);
}

void ContentWidget::playOrPause()
{
    if (!m_isPress){
        m_pVlc->Pause();
    }else
    {
        m_pVlc->Play();
    }
    m_isPress = !m_isPress;
}

bool ContentWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == m_pVideoLabel){
        if (event->type() == QEvent::MouseButtonDblClick)
        {
            emit signalShowFullScree();
            return true;
        }else if (event->type() == QEvent::MouseButtonPress)
        {
            //emit signalPlayOrPause();
            playOrPause();
            return true;
        }else
            return false;
    }
    return ContentWidget::eventFilter(obj,event);
}

void ContentWidget::slotPlayVideo(const QString &video)
{
    if (m_pVlc->isPlaying()){
        m_pVlc->Close();
        m_pVlc->Open(m_pVideoLabel,video);
        m_pVlc->Play();
    }else{
        m_pVlc->Open(m_pVideoLabel,video);
        m_pVlc->Play();
    }
    m_pGetPlayTime->start();
}

void ContentWidget::slotGeVideoLenght()
{
    qDebug()<<"voice:"<<m_pVlc->getVideoVoice();
    qDebug()<<"lenght:"<<m_pVlc->getVideoLength();
    qDebug()<<"time:"<<m_pVlc->getVideoTime();
}

void ContentWidget::slotSetPlayProgress(int value)
{
    if (value > 0)
    {
        m_pVlc->setPlayProgress(value);
    }
}

void ContentWidget::slotUpdatePlayTime()
{
    emit signalSendPlayTime(m_pVlc->getVideoTime(),m_pVlc->getVideoLength());
}

void ContentWidget::slotBackward()
{
    m_pVlc->setBackward();
}

void ContentWidget::slotSetPlayOrPose(bool flag)
{
    if (flag){
        m_pVlc->Pause();
    }else{
        m_pVlc->Play();
    }
}

void ContentWidget::slotForward()
{
    m_pVlc->setForward();
}
