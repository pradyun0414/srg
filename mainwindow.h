#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playButton_clicked();
    // void mousePressEvent(QMouseEvent *event);
    void on_fileUpload_3_clicked();

    void on_speedSlider_3_sliderMoved(int position);

    void on_volumeSlider_3_sliderMoved(int position);

    void on_volumeSlider_4_sliderMoved(int position);

    void on_speedSlider_4_sliderMoved(int position);

    void on_playButton_2_clicked();

    void on_fileUpload_4_clicked();

    void on_pushButton_20_clicked();

    void on_pitchSlider_3_sliderMoved(int position);

    void on_reverbSlider_3_sliderMoved(int position);

    void on_bassSlider_3_sliderMoved(int position);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
