#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QMediaPlayer>     //������
#include <QMediaPlaylist>   //���Ŷ���
#include <QVideoWidget>     //��Ƶ��ʾ����

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openBtn_clicked();

    void on_playBtn_clicked();

    void on_pauseBtn_clicked();

    void on_stopBtn_clicked();

protected:
    void paintEvent(QPaintEvent* e);

private:
    Ui::MainWindow *ui;
    QMediaPlayer* pPlayer;
    QMediaPlaylist* pPlayerList;
    QVideoWidget* pVideoWidget;
};

#endif // MAINWINDOW_H
