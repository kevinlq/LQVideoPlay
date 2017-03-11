#ifndef TITLEWIDGET_H
#define TITLEWIDGET_H

#include <QWidget>

class QLabel;
class LQTitleButton;
class QHBoxLayout;


class TitleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TitleWidget(QWidget *parent = 0);
    ~TitleWidget();

    void setTitleText(const QString &text);

private:
    void initForm();
    void initLayout();
    void initConnect();

Q_SIGNALS:
    void signalLogin();
    void signalShowMin();
    void signalShowMax();
    void signalClose();

private Q_SLOTS:
    void slotMax(bool);

private:
    QWidget         *m_pBackWidget;
    QLabel          *m_pTitleLabel;
    LQTitleButton   *m_pMinPbn;
    LQTitleButton   *m_pMaxPbn;
    LQTitleButton   *m_pClosePbn;
    LQTitleButton   *m_pLoginPbn;

    QHBoxLayout     *m_pMainLayout;

};

#endif // TITLEWIDGET_H
