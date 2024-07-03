#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <QMediaPlayer>
#include <QAudioOutput>
#include "audioplayer.h"
#include <QMediaMetaData>

#include <QFileDialog>
#include <QDebug>
#include <QProcess>
#include <QMessageBox>
#include <QDir>


audioPlayer* audio = new audioPlayer();
audioPlayer* audioTwo = new audioPlayer();
QString globalOutputFile;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug() << QFile::remove(audio->getTempUrl());
}

bool playClicked = false;
bool playClickedTwo = false;

// Play Button
void MainWindow::on_playButton_clicked()
{
    audio->play();
    playClicked = !playClicked;
    std::cout << "Play Clicked" << std::endl;
    audio->getMetadata();
}

// File upload button
void MainWindow::on_fileUpload_3_clicked()
{

    QUrl fileName = QFileDialog::getOpenFileName(this);

    QString tempDir = QDir(QCoreApplication::applicationDirPath()).filePath("temp/");
    QString tempFilePath = tempDir + QFileInfo(fileName.toString()).fileName();
    if (QFile::copy(fileName.toString(), tempFilePath)) {
        qDebug() << "File copied successfully.";
    } else {
        qDebug() << "Failed to copy file:";
    }
    audio->setTempUrl(tempFilePath);
    audio->setSong(QUrl::fromLocalFile(tempFilePath));
}


void MainWindow::on_speedSlider_3_sliderMoved(int position)
{
    double speed = position*1.0 / 100;
    ui->speedLabel_3->setText("Playback Speed: " + QString::number(speed));
    audio->setSoxSpeed(QString::number(speed));
}

void MainWindow::on_volumeSlider_3_sliderMoved(int position)
{
    double volume = (position*3.0) / 50.0; // in dB
    ui->volumeLabel_3->setText("Volume: " + QString::number(position));
    audio->setSoxVol(QString::number(volume));
}

void MainWindow::on_pitchSlider_3_sliderMoved(int position)
{
    int pitch = position*100;
    ui->pitchLabel_3->setText("Pitch: " + QString::number(position) + " Semitone(s)");
    audio->setSoxPitch(QString::number(pitch));
}

void MainWindow::on_reverbSlider_3_sliderMoved(int position)
{
    ui->reverbLabel_3->setText("Reverb: " + QString::number(position));
    audio->setSoxReverb(QString::number(position));
}

void MainWindow::on_bassSlider_3_sliderMoved(int position)
{
    double boost = (position*6.0) / 50.0; // in dB
    ui->bassLabel_3->setText("Bass Boost: " + QString::number(boost)  + " dB");
    audio->setSoxBass(QString::number(boost));
}


// Effects Loader
void MainWindow::on_pushButton_20_clicked()
{
    QString rootDir = QDir(QCoreApplication::applicationDirPath()).filePath("sox/");
    QString soxPath = rootDir + "sox.exe";

    QString inputFile = audio->getTempUrl();

    QString tempDir = QDir(QCoreApplication::applicationDirPath()).filePath("temp/");
    QString outputFile = tempDir + "output.wav";
    globalOutputFile = outputFile;
    // qDebug() << "Output file is: " << outputFile;

    QStringList arguments;
    arguments << inputFile << outputFile << audio->getSoxEffects();
    qDebug() << arguments;

    QProcess* process = new QProcess(this);
    process->start(soxPath, arguments);
    process->waitForFinished(-1);

    audio->setSong(QUrl::fromLocalFile(outputFile));
    qDebug() << "SoX process finished with exit code:" << process->exitCode();
}

// Tab 2 Methods

void MainWindow::on_volumeSlider_4_sliderMoved(int position)
{
    audioTwo->setVolume(position);
    ui->volumeLabel_4->setText("Volume: " + QString::number(position));
}


void MainWindow::on_speedSlider_4_sliderMoved(int position)
{
    audioTwo->setSpeed(position);
    double displayValue = position*1.0 / 100;
    ui->speedLabel_4->setText("Playback Speed: " + QString::number(displayValue));
    // std::cout << "The new song speed is: " << position << std::endl;
}

void MainWindow::on_playButton_2_clicked()
{
    audioTwo->play();
    playClickedTwo = !playClickedTwo;
    std::cout << "Play Two Clicked" << std::endl;
    audioTwo->getMetadata();
}


void MainWindow::on_fileUpload_4_clicked()
{
    QUrl fileName = QFileDialog::getOpenFileName(this);
    audioTwo->setSong(fileName);

}







