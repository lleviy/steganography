#ifndef DECRYPTTAB_H
#define DECRYPTTAB_H

#include <QBitArray>
#include <QWidget>
#include <QFileDialog>
#include <QGraphicsScene>
#include <algorithm.h>
#include <image.h>

namespace Ui {
class DecryptTab;
}

class DecryptTab : public QWidget
{
    Q_OBJECT

public:
    explicit DecryptTab(QWidget *parent = nullptr);
    ~DecryptTab();

private slots:
    void on_decrypt_clicked();

    void on_loadImage_clicked();

private:
    Ui::DecryptTab *ui;
    Image image;
};

#endif // DECRYPTTAB_H
