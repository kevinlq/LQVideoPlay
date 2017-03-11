/****************************************************************************
**
** Date    		: 2017-01-24
** Author  		: KevinLi
** E-Mail  		: kevinlq0912@163.com
** QQ      		: 2313828706
** Version 		: V1.0
** Description	:This file is main widget
** If you have any questions , please contact me
** http://blog.csdn.net/u013704336
** https://github.com/kevinlq
** https://git.oschina.net/kevinlq0912
**
****************************************************************************/
#include <QApplication>
#include <QFile>

#include "mainwidget.h"
#include "titlewidget.h"
#include "statuswidget.h"

int main (int argc,char *argv[])
{
    QApplication app(argc,argv);

    QFile file(":/Images/qss/style.css");
    file.open(QFile::ReadOnly);
    QString qss = QLatin1String(file.readAll());
    qApp->setStyleSheet(qss);

    MainWidget widget;
    widget.show();
    int ret = app.exec();

    return ret;
}
