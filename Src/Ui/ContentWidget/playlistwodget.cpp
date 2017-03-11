#include "playlistwodget.h"

PlayListWodget::PlayListWodget(QWidget *parent)
    :QListView(parent)
{
    initForm();
}

PlayListWodget::~PlayListWodget()
{
}

void PlayListWodget::initForm()
{
    setMaximumWidth(140);
}
