#include "lqvlcplayer.h"

#include <QDebug>

LQvlcPlayer::LQvlcPlayer(QObject *parent) :
    QObject(parent)
{
    m_pVlcInst = 0;
    m_pVlcMedia = 0;
    m_pVlcPlayer = 0;
    m_videoAddr = "";
}

LQvlcPlayer::~LQvlcPlayer()
{
}

void LQvlcPlayer::Open(QLabel *lab, QString videoAddr)
{
    this->lab = lab;
    this->m_videoAddr = videoAddr;

    if (videoAddr.right(4) == "h264") {
        const char *vlc_args[] = {"-I",
                                  "dummy",
                                  "--demux=h264",
                                  "--ignore-config",
                                  "--audio",
                                  "--no-video-on-top",
                                  "--no-video-title-show",
                                  "--no-snapshot-preview"
                                 };
        m_pVlcInst = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);
    } else {
        const char *vlc_args[] = {"-I",
                                  "dummy",
                                  "--ignore-config",
                                  "--audio",
                                  "--no-video-on-top",
                                  "--no-video-title-show",
                                  "--no-snapshot-preview",
                                 };
        m_pVlcInst = libvlc_new(sizeof(vlc_args) / sizeof(vlc_args[0]), vlc_args);
    }

    m_pVlcMedia = libvlc_media_new_path(m_pVlcInst, videoAddr.toLatin1().constData());

    if (m_pVlcInst != 0 && m_pVlcMedia != 0) {
        m_pVlcPlayer = libvlc_media_player_new_from_media(m_pVlcMedia);

        libvlc_release(m_pVlcInst);
        m_pVlcInst = 0;
        libvlc_media_release(m_pVlcMedia);
        m_pVlcMedia = 0;

#if defined(Q_OS_MAC)
        libvlc_media_player_set_nsobject(vlcPlayer, lab->winId());
#elif defined(Q_OS_UNIX)
        libvlc_media_player_set_xwindow(vlcPlayer, lab->winId());
#elif defined(Q_OS_WIN)
        libvlc_media_player_set_hwnd(m_pVlcPlayer, (void *)lab->winId());
#endif

        int width = lab->width();
        int height = lab->height();
        QString args = QString("%1:%2").arg(width).arg(height);
        QByteArray bay = args.toLatin1();
        const char *arg = bay.constData();

        if (m_pVlcPlayer != 0) {
            libvlc_video_set_aspect_ratio(m_pVlcPlayer, arg);
        }
    }
}

bool LQvlcPlayer::Play()
{
    if (m_pVlcPlayer != 0) {
        libvlc_media_player_play(m_pVlcPlayer);
        return true;
    }
    return false;
}

bool LQvlcPlayer::Pause()
{
    if (m_pVlcPlayer != 0) {
        libvlc_media_player_pause(m_pVlcPlayer);
        return true;
    }
    return false;
}

void LQvlcPlayer::Close()
{
    if (m_pVlcPlayer != 0) {
        libvlc_media_player_release(m_pVlcPlayer);
        m_pVlcPlayer = 0;
        qDebug() << "close video succeed:" << m_videoAddr;
    } else {
        qDebug() << "close video error:" << m_videoAddr;
    }
}

/**
 *get video length
*/
quint64 LQvlcPlayer::getVideoLength()
{
    if (m_pVlcPlayer){
        return libvlc_media_player_get_length(m_pVlcPlayer);
    }
    return 0;
}

quint64 LQvlcPlayer::getVideoTime()
{
    if (m_pVlcPlayer)
    {
        return libvlc_media_player_get_time(m_pVlcPlayer);
    }
    return 0;
}

quint64 LQvlcPlayer::getVideoVoice()
{
    if (m_pVlcPlayer)
    {
        return libvlc_audio_get_volume(m_pVlcPlayer);
    }
    return 0;
}

bool LQvlcPlayer::isPlaying()
{
    if (m_pVlcPlayer)
    {
        return libvlc_media_player_is_playing(m_pVlcPlayer);
    }
    return FALSE;
}

int LQvlcPlayer::getPlayStatue()
{
    if (m_pVlcInst)
    {
        return libvlc_media_player_get_state(m_pVlcPlayer);
    }
    return 0;
}

void LQvlcPlayer::setPlayProgress(int nPos)
{
    //    int pos = this->getPlayPos();

    //    this->seekTo(pos + 10);
    this->seekTo(nPos);
}

void LQvlcPlayer::setForward()
{
    int nPos = this->getPlayPos();

    this->seekTo(nPos + 5);
}

void LQvlcPlayer::setBackward()
{
    int nPos = this->getPlayPos();

    this->seekTo(nPos - 5);
}

int LQvlcPlayer::getPlayPos()
{
    if (m_pVlcPlayer)
    {
        return (int) (100 * libvlc_media_player_get_position(m_pVlcPlayer));
    }
    return 0;
}

void LQvlcPlayer::seekTo(int nPos)
{
    if (m_pVlcPlayer)
    {
        libvlc_media_player_set_position(m_pVlcPlayer, nPos/(float)100.0);
    }
}


