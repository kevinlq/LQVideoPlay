#include "mainwidget.h"

/*Custom widget*/
#include "titlewidget.h"
#include "contentwidget.h"
#include "statuswidget.h"
#include "playprogress.h"

#include "eplaycontrol.h"

/*Qt file*/
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <QMouseEvent>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    this->init();
}

MainWidget::~MainWidget(){

#if 0
    if (m_pTitleWidget != NULL){
        delete m_pTitleWidget;
        m_pTitleWidget = NULL;
    }
    if (m_pStatusWidget != NULL){
        delete m_pStatusWidget;
        m_pStatusWidget = NULL;
    }
    if (m_pContentWidget != NULL){
        delete m_pContentWidget;
        m_pContentWidget = NULL;
    }
    if (m_pMainLayout != NULL){
        delete m_pMainLayout;
        m_pMainLayout = NULL;
    }
#endif
}

void MainWidget::init()
{
    initForm();
    initLayout();
    initConnect();
}

void MainWidget::initForm()
{
    this->setMinimumSize(800,600);
    this->setMouseTracking(true);
    m_mousePress = false;
    m_isFullScreen = false;
    m_isMax = false;

    this->setWindowFlags(Qt::FramelessWindowHint |
                         Qt::WindowSystemMenuHint |
                         Qt::WindowMinMaxButtonsHint);

    m_pTitleWidget = new TitleWidget;
    m_pTitleWidget->setTitleText("LQVideoPlay(QQ2313828706)");

    m_pContentWidget = new ContentWidget;
    m_pStatusWidget = new StatusWidget;
    m_pPlayProgress = new PlayProgress;

    m_pEplay = new EPlayControl;
}

void MainWidget::initLayout()
{
    m_pMainLayout = new QVBoxLayout(this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_pTitleWidget);
    layout->addWidget(m_pContentWidget);
    layout->addWidget(m_pPlayProgress);
    layout->addWidget(m_pStatusWidget);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    m_pMainLayout->addLayout(layout);

    m_pMainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(m_pMainLayout);
}


/**
 *init the signal and slot
*/
void MainWidget::initConnect()
{
    /*title signal and slot*/
    connect(m_pTitleWidget,SIGNAL(signalShowMin()),
            this,SLOT(slotShowMin()));
    connect(m_pTitleWidget,SIGNAL(signalShowMax()),
            this,SLOT(slotShowMax()));
    connect(m_pTitleWidget,SIGNAL(signalClose()),
            this,SLOT(slotCloseWidget()));
    connect(this,SIGNAL(signalMax(bool)),
            m_pTitleWidget,SLOT(slotMax(bool)));

    /*Content signal and slot*/
    connect(m_pContentWidget,SIGNAL(signalShowFullScree()),
            this,SLOT(slotShowFullScree()));
    connect(m_pContentWidget,SIGNAL(signalSendPlayTime(quint64,quint64)),
            m_pPlayProgress,SLOT(slotUpdatePlayProgress(quint64,quint64)));

    /*status signal and slot*/
    connect(m_pStatusWidget,SIGNAL(signalOpenVideoFile()),
            this,SLOT(slotOpenVideoFile()));
    connect(m_pStatusWidget,SIGNAL(signalPreVideo()),
            m_pContentWidget,SLOT(slotBackward()));
    connect(m_pStatusWidget,SIGNAL(signalPlayOrStopVideo(bool)),
            m_pContentWidget,SLOT(slotSetPlayOrPose(bool)));
    connect(m_pStatusWidget,SIGNAL(signalNextVideo()),
            m_pContentWidget,SLOT(slotForward()));
    connect(m_pPlayProgress,SIGNAL(signalProgressValueChange(int)),
            m_pContentWidget,SLOT(slotSetPlayProgress(int)));

    connect(this,SIGNAL(signalSendFileInfo(QStringList)),
            m_pEplay,SLOT(slotReadVidoeInfo(QStringList)));
    connect(m_pEplay,SIGNAL(signalSendPlayVideo(QString)),
            m_pContentWidget,SLOT(slotPlayVideo(QString)));
}

void MainWidget::mousePressEvent(QMouseEvent *event)
{
    //this only mouse leftbutton pressed
    if (event->button() == Qt::LeftButton)
    {
        m_mousePress = true;
    }

    //remember move distence
    m_movePoint = event->globalPos() - pos();
}

void MainWidget::mouseReleaseEvent(QMouseEvent *event)
{
    m_mousePress = false;
}

void MainWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_mousePress)
    {
        QPoint movePos = event->globalPos();
        move(movePos - m_movePoint);
    }
}

void MainWidget::slotShowMin()
{
    this->showMinimized();
}

void MainWidget::slotShowMax()
{
    if (!m_isMax){
        this->showMaximized();
        emit signalMax(true);
    }else
    {
        this->showNormal();
        emit signalMax(false);
    }

    m_isMax = !m_isMax;
}

void MainWidget::slotCloseWidget()
{
    qApp->quit();
}

void MainWidget::slotOpenVideoFile()
{
    QFileDialog dialog(this);
    QStringList filters;
    filters << "Any files (*)";
    dialog.setFileMode(QFileDialog::ExistingFiles );
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setNameFilters(filters);
    if (dialog.exec()){

        emit signalSendFileInfo(dialog.selectedFiles());
    }
    //QStringList info;
    //info <<"E:\\QtControl\\LQVideoPlay\\bin\\debug\\shejiao.rmvb";
    //emit signalSendFileInfo(info);
}

void MainWidget::slotShowFullScree()
{
    if (!m_isFullScreen){
        this->showFullScreen();
        m_pTitleWidget->setVisible(false);
        m_pPlayProgress->setVisible(false);
        m_pStatusWidget->setVisible(false);
    }else{
        this->showNormal();
        m_pTitleWidget->setVisible(true);
        m_pPlayProgress->setVisible(true);
        m_pStatusWidget->setVisible(true);
    }
    m_isFullScreen = !m_isFullScreen;
}
