/****************************************************************************
**
** Date    		: 2017-01-24
** Author  		: KevinLi
** E-Mail  		: kevinlq0912@163.com
** QQ      		: 2313828706
** Version 		: V1.0
** Description	:this file show video play progress
** If you have any questions , please contact me
** http://blog.csdn.net/u013704336
** https://github.com/kevinlq
** https://git.oschina.net/kevinlq0912
**
****************************************************************************/
#include "playprogress.h"

#include <QSlider>
#include <QProgressBar>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

PlayProgress::PlayProgress(QWidget *parent) :
    QWidget(parent)
{
    initForm();
    initConnect();
}

PlayProgress::~PlayProgress()
{
}

void PlayProgress::initForm()
{
    m_pBackWidget = new QWidget(this);
    QWidget *proWidget = new QWidget(this);
    m_pBackWidget->setObjectName(QString::fromLocal8Bit("widget_progress"));
    proWidget->setObjectName(QString::fromLocal8Bit("widget_progress"));

    m_pProgress = new QSlider(proWidget);
    m_pProgress->setOrientation(Qt::Horizontal);
    m_pProgress->setCursor(QCursor(Qt::PointingHandCursor));

    m_pCurPlayTimeLabel = new QLabel(m_pBackWidget);
    m_pCurPlayTimeLabel->setObjectName(QString::fromLocal8Bit("white_label"));
    m_pCurPlayTimeLabel->setText("00:00");

    m_pTotalPlayTileLabel = new QLabel(m_pBackWidget);
    m_pTotalPlayTileLabel->setObjectName(QString::fromLocal8Bit("white_label"));
    m_pTotalPlayTileLabel->setText("00:00");

    QLabel *tipLabel = new QLabel(m_pBackWidget);
    tipLabel->setObjectName(QString::fromLocal8Bit("white_label"));
    tipLabel->setText("/");

    m_pLabelLayout = new QHBoxLayout(m_pBackWidget);
    m_pLabelLayout->addSpacing(4);
    m_pLabelLayout->addWidget(m_pCurPlayTimeLabel);
    m_pLabelLayout->addSpacing(2);
    m_pLabelLayout->addWidget(tipLabel);
    m_pLabelLayout->addWidget(m_pTotalPlayTileLabel);
    m_pLabelLayout->addStretch();
    m_pLabelLayout->setContentsMargins(1,0,4,0);

    QHBoxLayout *proLayout = new QHBoxLayout(proWidget);
    proLayout->addWidget(m_pProgress);

    m_pMainLayout = new QVBoxLayout(this);
    m_pMainLayout->addWidget(m_pBackWidget);
    m_pMainLayout->addWidget(proWidget);
    m_pMainLayout->setSpacing(0);
    m_pMainLayout->setContentsMargins(0,0,0,0);
    m_pMainLayout->setSpacing(0);
    setLayout(m_pMainLayout);

}

void PlayProgress::initConnect()
{
    connect(m_pProgress,SIGNAL(sliderMoved(int)),
            this,SIGNAL(signalProgressValueChange(int)));
}

void PlayProgress::slotUpdatePlayProgress(quint64 curTime, quint64 TotalTime)
{
    if ( (curTime != 0) && (TotalTime != 0))
    {
        m_pCurPlayTimeLabel->setText(QString::number(curTime));
        m_pTotalPlayTileLabel->setText(QString::number(TotalTime ));
        m_pProgress->setRange(0,TotalTime);
        m_pProgress->setValue(curTime);
    }
}

