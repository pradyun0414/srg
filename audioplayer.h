#ifndef AUDIOPLAYER_H
#define AUDIOPLAYER_H

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMediaMetaData>

class audioPlayer
{

private:

    QMediaPlayer* player = new QMediaPlayer;
    QAudioOutput* audioOutput = new QAudioOutput;

    double volume = 0.5;
    double playbackRate = 100.0;
    QUrl songUrl;
    QString tempUrl;
    std::vector<QUrl> playlist;

    QString soxVol = "1.5";
    QString soxSpeed = "1";
    QString soxPitch ="0";
    QString soxReverb = "0";
    QString soxBass = "0";

    QString soxEffects;


public:
    audioPlayer();
    ~audioPlayer();
    void play();
    void pause();
    void stop();
    void setSong(QUrl);
    void setTempUrl(QString);
    void setSpeed(int);
    void setVolume(int);
    void addToPlaylist();
    void getMetadata();
    QUrl getSong();
    QString getTempUrl();

    void setSoxVol(QString);
    void setSoxSpeed(QString);
    void setSoxPitch(QString);
    void setSoxReverb(QString);
    void setSoxBass(QString);

    QStringList getSoxEffects();
};

#endif // AUDIOPLAYER_H


