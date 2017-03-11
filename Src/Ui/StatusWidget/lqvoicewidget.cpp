#include "lqvoicewidget.h"

#include <QSlider>
#include <QHBoxLayout>

/*custom pushbutton*/
#include "lqpushbutton.h"

LQVoiceWidget::LQVoiceWidget(QWidget *parent) :
    QWidget(parent)
{
    init();
}

LQVoiceWidget::~LQVoiceWidget()
{
}

void LQVoiceWidget::init()
{
    initForm();
    initLayout();
    initConnect();
}

void LQVoiceWidget::initForm()
{
    m_pBackWidget = new QWidget(this);
    m_pVoiceButton = new LQPushButton(m_pBackWidget);
    m_pVoiceButton->setObjectName(QString::fromLocal8Bit("btn_voice"));
    m_pVoiceButton->setToolTip("NoVoice");

    m_pVoiceSlider = new QSlider(m_pBackWidget);
    m_pVoiceSlider->setOrientation(Qt::Horizontal);
    m_pVoiceSlider->setObjectName(QString::fromLocal8Bit("voice_slider"));
    m_pVoiceSlider->setToolTip("volume");
    m_pVoiceSlider->setCursor(QCursor(Qt::PointingHandCursor));

    /**
     *set the default value.
     *actually should read from configuration file
    */
    m_isNoVoice = false;
    m_pVoiceSlider->setRange(0,100);
    m_pVoiceSlider->setValue(60);
}

void LQVoiceWidget::initLayout()
{
    m_pMainLayout = new QHBoxLayout(this);
    QHBoxLayout *layout = new QHBoxLayout(m_pBackWidget);
    layout->addWidget(m_pVoiceButton);
    layout->addSpacing(1);
    layout->addWidget(m_pVoiceSlider);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    m_pMainLayout->addWidget(m_pBackWidget);
    m_pMainLayout->setContentsMargins(0,0,0,0);
    setLayout(m_pMainLayout);
}

void LQVoiceWidget::initConnect()
{
    connect(m_pVoiceButton,SIGNAL(clicked()),
            this,SLOT(slotNoVoice()));
    connect(m_pVoiceSlider,SIGNAL(valueChanged(int)),
            this,SIGNAL(signalVoiceValueChange(int)));
}


void LQVoiceWidget::slotNoVoice()
{
    if (!m_isNoVoice){
        m_pVoiceSlider->setValue(0);
        emit signalSendNoVoice();
    }else{
        m_pVoiceSlider->setValue(40);
    }

    m_isNoVoice = !m_isNoVoice;
}
