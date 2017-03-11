#ifndef EPLAYCONTROL_H
#define EPLAYCONTROL_H

#include <QObject>

class EPlayControl : public QObject
{
    Q_OBJECT
public:
    explicit EPlayControl(QObject *parent = 0);
    ~EPlayControl();
    
private:
    void initAll();
    void initForm();
    void initConnect();

    QString formatReplease(QString org);

    QString UnicodeToUTF8(const QString &strWide);

Q_SIGNALS:
    void signalSendPlayVideo(const QString &info);

private Q_SLOTS:
    void slotReadVidoeInfo(const QStringList &path);

private:
    
};

#endif // EPLAYCONTROL_H
