#include "audioplayer.h"

audioPlayer::audioPlayer() {

    player->setAudioOutput(audioOutput);
    audioOutput->setVolume(volume);

}

audioPlayer::~audioPlayer() {
    delete player;
    delete audioOutput;
}

void audioPlayer::getMetadata() {

    QMediaMetaData var = player->metaData();

    qDebug() << var.keys();
    qDebug() << var.stringValue(QMediaMetaData::Title);
    qDebug() << var.value(QMediaMetaData::Author).toStringList();
    qDebug() << var.stringValue(QMediaMetaData::LeadPerformer);
    qDebug() << var.value(QMediaMetaData::ContributingArtist).toStringList();
    qDebug() << var.stringValue(QMediaMetaData::MediaType);
    qDebug() << var.stringValue(QMediaMetaData::Duration);
    qDebug() << var.stringValue(QMediaMetaData::AudioCodec);
    qDebug() << var.stringValue(QMediaMetaData::AudioBitRate);
    qDebug() << var.stringValue(QMediaMetaData::FileFormat);

    qDebug() << "Duration from player is: " << player->duration();

}

void audioPlayer::play() {
    player->play();
}

void audioPlayer::pause() {
    player->pause();
}

void audioPlayer::stop() {
    player->stop();
}

void audioPlayer::setSong(QUrl input) {
    songUrl = input;
    player->setSource(songUrl);
}

void audioPlayer::setTempUrl(QString input) {
    tempUrl = input;
}

void audioPlayer::setSpeed(int input) {
    playbackRate = input*1.0;
    double speed = playbackRate / 100;
    player->setPlaybackRate(speed);
}

void audioPlayer::setVolume(int input) {
    volume = input*1.0 / 100;
    audioOutput->setVolume(volume);
}

QUrl audioPlayer::getSong() {
    return this->songUrl;
}

QString audioPlayer:: getTempUrl() {
    return this->tempUrl;
}

// Sox Methods

void audioPlayer::setSoxVol(QString input) {
    this->soxVol = input;
}

void audioPlayer::setSoxPitch(QString input) {
    this->soxPitch = input;
}

void audioPlayer::setSoxSpeed(QString input) {
    this->soxSpeed = input;
}

void audioPlayer::setSoxReverb(QString input) {
    this->soxReverb = input;
}

void audioPlayer::setSoxBass(QString input) {
    this->soxBass = input;
}

QStringList audioPlayer::getSoxEffects() {
    QStringList result;
    result << "pitch" << soxPitch << "speed" << soxSpeed << "bass" << soxBass << "100" << "1" << "reverb"
           << soxReverb << soxReverb << "100" << "100" << "0" << "0" << "vol" << soxVol;

    return result;
}































