#ifndef ENCRYPTTAB_H
#define ENCRYPTTAB_H

#include <QBitArray>
#include <QWidget>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QMessageBox>
#include <algorithm.h>
#include <image.h>

namespace Ui {
class EncryptTab;
}

class EncryptTab : public QWidget
{
    Q_OBJECT

public:
    explicit EncryptTab(QWidget *parent = nullptr);
    ~EncryptTab();

private slots:
    void on_encrypt_clicked();

    void on_loadImage_clicked();

    void on_saveImage_clicked();

private:
    Ui::EncryptTab *ui;
    Image image;
    Image image2;
    QGraphicsScene *scene;
};

#endif // ENCRYPTTAB_H
