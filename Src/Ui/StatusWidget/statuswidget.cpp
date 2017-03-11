#include "statuswidget.h"

/*Qt file*/
#include <QLabel>
#include <QHBoxLayout>
#include <QDebug>

/*Custom pushbutton*/
#include "LQPushButton.h"
#include "lqvoicewidget.h"

StatusWidget::StatusWidget(QWidget *parent) :
    QWidget(parent)
{
    init();
}

StatusWidget::~StatusWidget()
{
}

void StatusWidget::init()
{
    initForm();
    initLayout();
    initConnect();
}

void StatusWidget::initForm()
{
    this->setMaximumHeight(60);
    this->setMinimumWidth(700);

    m_isPlay = false;

    m_pBackWidget = new QWidget(this);
    m_pBackWidget->setObjectName(QString::fromLocal8Bit("widget_status"));

    m_pPrePbn = new LQPushButton(m_pBackWidget);
    m_pPrePbn->setObjectName(QString::fromLocal8Bit("btn_pre"));
    m_pPrePbn->setToolTip(tr("pre"));

    m_pPlayPbn = new LQPushButton(m_pBackWidget);
    m_pPlayPbn->setObjectName(QString::fromLocal8Bit("btn_play"));
    m_pPlayPbn->setToolTip(tr("play"));

    m_pNextPbn = new LQPushButton(m_pBackWidget);
    m_pNextPbn->setObjectName(QString::fromLocal8Bit("btn_next"));
    m_pNextPbn->setToolTip(tr("next"));

    m_pStopPbn = new LQPushButton(m_pBackWidget);
    m_pStopPbn->setObjectName(QString::fromLocal8Bit("btn_stop"));
    m_pStopPbn->setToolTip(tr("stop"));

    m_pVoiceWidget = new LQVoiceWidget(m_pBackWidget);

    m_pOpenFilePbn = new LQPushButton(m_pBackWidget);
    m_pOpenFilePbn->setObjectName(QString::fromLocal8Bit("btn_open"));
    m_pOpenFilePbn->setToolTip(tr("open"));
}

void StatusWidget::initLayout()
{
    m_pMainLayout = new QHBoxLayout(this);
    m_pMainLayout->addSpacing(1);

    QHBoxLayout *PlayLayout = new QHBoxLayout(m_pBackWidget);
    PlayLayout->addStretch();
    PlayLayout->addWidget(m_pStopPbn);
    PlayLayout->addWidget(m_pPrePbn);
    PlayLayout->addWidget(m_pPlayPbn);
    PlayLayout->addWidget(m_pNextPbn);
    PlayLayout->addSpacing(6);
    PlayLayout->addWidget(m_pVoiceWidget);
    PlayLayout->addStretch();
    PlayLayout->addWidget(m_pOpenFilePbn);

    m_pMainLayout->addWidget(m_pBackWidget);
    m_pMainLayout->setSpacing(1);
    m_pMainLayout->setContentsMargins(0,0,0,0);

    this->setLayout(m_pMainLayout);
}

void StatusWidget::initConnect()
{
    connect(m_pOpenFilePbn,SIGNAL(clicked()),
            this,SIGNAL(signalOpenVideoFile()));
    connect(m_pPrePbn,SIGNAL(clicked()),
            this,SIGNAL(signalPreVideo()));
    connect(m_pPlayPbn,SIGNAL(clicked()),
            this,SLOT(slotPlayOrPose()));
    connect(m_pNextPbn,SIGNAL(clicked()),
            this,SIGNAL(signalNextVideo()));
    connect(m_pStopPbn,SIGNAL(clicked()),
            this,SIGNAL(signalStopVideo()));
}

void StatusWidget::slotPlayOrPose()
{
    if (m_isPlay){
        emit signalPlayOrStopVideo(true);
    }else{
        emit signalPlayOrStopVideo(false);
    }

    m_isPlay = !m_isPlay;
}
