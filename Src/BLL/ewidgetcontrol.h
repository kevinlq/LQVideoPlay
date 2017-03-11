#ifndef EWIDGETCONTROL_H
#define EWIDGETCONTROL_H

#include <QObject>

class EWidgetControl : public QObject
{
    Q_OBJECT
public:
    explicit EWidgetControl(QObject *parent = 0);
    ~EWidgetControl();
    
private:
    void initAll();
    void initForm();
    void initConnect();

Q_SIGNALS:
    void signalClose();
private Q_SLOTS:

private:
    
};

#endif // EWIDGETCONTROL_H
