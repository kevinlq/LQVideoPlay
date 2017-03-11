/****************************************************************************
**
** Date    		: 2017-01-24
** Author  		: KevinLi
** E-Mail  		: kevinlq0912@163.com
** QQ      		: 2313828706
** Version 		: V1.0
** Description	:this file is play control logic
** If you have any questions , please contact me
** http://blog.csdn.net/u013704336
** https://github.com/kevinlq
** https://git.oschina.net/kevinlq0912
****************************************************************************/
#include "eplaycontrol.h"

#include <QStringList>
#include <QFileInfo>
#include <QDebug>
#include <QTextCodec>

EPlayControl::EPlayControl(QObject *parent) :
    QObject(parent)
{
    initAll();
}

EPlayControl::~EPlayControl()
{
}

void EPlayControl::initAll()
{
    initForm();
    initConnect();
}

void EPlayControl::initForm()
{
}

void EPlayControl::initConnect()
{
}

QString EPlayControl::formatReplease(QString org)
{
    QString destStr;
#if defined(Q_OS_WIN)
    destStr = org.replace("/","\\",Qt::CaseSensitive);
#elif defined(Q_OS_LINUX)
    destStr = org;
#endif
    //change path code
    destStr = UnicodeToUTF8(destStr);

    return destStr;
}

QString EPlayControl::UnicodeToUTF8(const QString &strWide)
{
    QString strUtf8;
    QStringList t;
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    for (int i = 0; i <strWide.length(); i+=4)
    {
        t.append(strWide.mid(i,4));
    }
    foreach (const QString &str, t) {
        strUtf8.append(str);
    }

    return codec->fromUnicode(strUtf8);
}

void EPlayControl::slotReadVidoeInfo(const QStringList &path)
{
    int length = path.length();
    if (length <= 0)
        return;
    QStringList videoList;
    QFileInfo fileInfo;
    //get video full path,and insert to playlist
    foreach (QString name,path)
    {
        fileInfo = QFileInfo(name);
        videoList << fileInfo.fileName();
    }

    emit signalSendPlayVideo(formatReplease(videoList.at(0)));
}
