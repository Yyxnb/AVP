#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QMediaPlayer>     //������
#include <QMediaPlaylist>   //���Ŷ���
#include <QVideoWidget>     //��Ƶ��ʾ����
#include <QPaintEvent>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //���ñ���
    setWindowTitle("AV Player");

    pPlayer = new QMediaPlayer;
    pPlayerList = new QMediaPlaylist;
    pVideoWidget = new QVideoWidget(ui->label);

    pPlayer->setPlaylist(pPlayerList);
    pPlayer->setVideoOutput(pVideoWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
//�����򿪰�ť����Ƶ������Ƶ
void MainWindow::on_openBtn_clicked()
{
    //qDebug() << "openBtn has been pushed";
    //��һ���ļ����ҿ�
    QStringList filenames = QFileDialog::getOpenFileNames(this, "Let me look what vedios in you pc~", "D:/Users/Desktop",
                                                          "allfiles(*.*);;"
                                                          "WMV(*.wmv);;"
                                                          "WAV(*.wav);;"
                                                          );

    pPlayerList->clear();

    foreach (QString const &str, filenames)
    {
       //qDebug() << str << " ";
       QUrl url(str);
       pPlayerList->addMedia(url);
    }
}
// ����
void MainWindow::on_playBtn_clicked()
{
    pPlayer->play();
    pVideoWidget->resize(ui->label->size());
}
// ��ͣ
void MainWindow::on_pauseBtn_clicked()
{
    pPlayer->pause();
}
// ֹͣ
void MainWindow::on_stopBtn_clicked()
{
    pPlayer->stop();
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    pVideoWidget->resize(ui->label->size());
}
