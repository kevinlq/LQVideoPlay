#ifndef LQVLCPLAYER_H
#define LQVLCPLAYER_H


#include <QObject>
#include <QLabel>
#include "vlc/vlc.h"

class LQvlcPlayer : public QObject
{
    Q_OBJECT
public:
    explicit LQvlcPlayer(QObject *parent = 0);
    ~LQvlcPlayer();
    
    void Open(QLabel *lab, QString videoAddr);
    bool Play();
    bool Pause();
    void Close();

    //get video length
    quint64 getVideoLength();

    //get vidoe current play time
    quint64 getVideoTime();

    //get video voice
    quint64 getVideoVoice();

    bool isOpen(){return m_pVlcPlayer;}
    bool isPlaying();
    int getPlayStatue();

    //set play progress
    void setPlayProgress(int nPos);
    void setForward();
    void setBackward();

private:
    int getPlayPos();
    void seekTo(int nPos);

private:
    libvlc_instance_t *m_pVlcInst;
    libvlc_media_t *m_pVlcMedia;
    libvlc_media_player_t *m_pVlcPlayer;

    QLabel *lab;
    QString m_videoAddr;
    quint64 m_videoLenght;
    quint64 m_videoVoice;
};
#endif // LQVLCPLAYER_H
