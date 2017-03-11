#include "titlewidget.h"
#include "lqtitlebutton.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>

TitleWidget::TitleWidget(QWidget *parent) :
    QWidget(parent)
{
    initForm();
    initLayout();
    initConnect();
}

TitleWidget::~TitleWidget()
{
}

void TitleWidget::setTitleText(const QString &text)
{
    if (!text.isEmpty())
        m_pTitleLabel->setText(text);
}

void TitleWidget::initForm()
{
    this->setMaximumHeight(34);
    m_pBackWidget = new QWidget(this);
    m_pBackWidget->setObjectName(QString::fromLocal8Bit("widget_title"));

    m_pTitleLabel = new QLabel(m_pBackWidget);
    m_pTitleLabel->setObjectName(QString::fromLocal8Bit("white_label"));

    m_pLoginPbn = new LQTitleButton(m_pBackWidget);
    m_pLoginPbn->setObjectName(QString::fromLocal8Bit("btn_login"));
    m_pLoginPbn->setToolTip(tr("login"));

    m_pMinPbn = new LQTitleButton(m_pBackWidget);
    m_pMinPbn->setObjectName(QString::fromLocal8Bit("btn_min"));
    m_pMinPbn->setToolTip(tr("min"));

    m_pMaxPbn = new LQTitleButton(m_pBackWidget);
    m_pMaxPbn->setObjectName(QString::fromLocal8Bit("btn_max"));
    m_pMaxPbn->setToolTip(tr("max"));

    m_pClosePbn = new LQTitleButton(m_pBackWidget);
    m_pClosePbn->setObjectName(QString::fromLocal8Bit("btn_close"));
    m_pClosePbn->setToolTip(tr("close"));

}

void TitleWidget::initLayout()
{
    m_pMainLayout = new QHBoxLayout(this);

    QHBoxLayout *layout = new QHBoxLayout(m_pBackWidget);

    layout->addSpacing(6);
    layout->addWidget(m_pTitleLabel);
    layout->addStretch();
    layout->addWidget(m_pLoginPbn);
    layout->addWidget(m_pMinPbn);
    layout->addWidget(m_pMaxPbn);
    layout->addWidget(m_pClosePbn);
    layout->addSpacing(4);
    layout->setContentsMargins(1,1,2,2);

    m_pMainLayout->addWidget(m_pBackWidget);
    m_pMainLayout->setSpacing(1);
    m_pMainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(m_pMainLayout);
}

void TitleWidget::initConnect()
{
    connect(m_pMinPbn,SIGNAL(clicked()),
            this,SIGNAL(signalShowMin()));
    connect(m_pMaxPbn,SIGNAL(clicked()),
            this,SIGNAL(signalShowMax()));
    connect(m_pClosePbn,SIGNAL(clicked()),
            this,SIGNAL(signalClose()));
    connect(m_pLoginPbn,SIGNAL(clicked()),
            this,SIGNAL(signalLogin()));
}



void TitleWidget::slotMax(bool flag)
{
    QString style = "QPushButton#btn_max{border-image: url(:/Images/titleMenu/";
    if (flag){
        style += "max_restore.png)}";
    }else{
        style += "max.png)}";
    }
    m_pMaxPbn->setStyleSheet(style);
}
