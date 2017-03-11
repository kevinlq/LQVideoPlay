#ifndef PLAYLISTWODGET_H
#define PLAYLISTWODGET_H

#include <QListView>

class PlayListWodget : public QListView
{
    Q_OBJECT
public:
    PlayListWodget(QWidget *parent = 0);
    ~PlayListWodget();

private:
    void initForm();

Q_SIGNALS:
private Q_SLOTS:

private:
};

#endif // PLAYLISTWODGET_H
