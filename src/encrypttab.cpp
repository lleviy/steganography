#include "encrypttab.h"
#include "ui_encrypttab.h"
#include <QResizeEvent>

EncryptTab::EncryptTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EncryptTab)
{
    ui->setupUi(this);
}

EncryptTab::~EncryptTab()
{
    delete ui;
}

void EncryptTab::on_loadImage_clicked()
{
    QString FileName=QFileDialog::getOpenFileName(this, "Load Image");
    QFileInfo fi(FileName);
    image = Image(QImage(FileName), fi.completeSuffix());
    scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(image.getPicture()));
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0, 0, image.getPicture().width(), image.getPicture().height());
}



void EncryptTab::on_encrypt_clicked()
{
    QByteArray byteimage = image.toByteArray();
    QBitArray bitimage = bytesToBits(byteimage);
    QString message = ui->textEdit->toPlainText();
    QByteArray bytemessage = message.toUtf8();
    QBitArray bitmessage = bytesToBits(bytemessage);

    if (bitmessage.size() > (bitimage.size() / 4)) {
        QMessageBox::warning(this, "Внимание","Невозможно зашифровать сообщение в данном изображении. "
                                              "\nЗагрузите более большое изображение или введите меньше текста.");
        return;
    }


    QBitArray bitresult = image.stego(image.getExtension(), byteimage, bitimage, bitmessage);
    QByteArray byteresult = bitsToBytes(bitresult);
    image2 = Image(QImage::fromData(byteresult), image.getExtension());
    QGraphicsScene *scene2 = new QGraphicsScene(this);
    scene2->addPixmap(QPixmap::fromImage(image2.getPicture()));
    ui->resultGraphicsView->setScene(scene2);
}

void EncryptTab::on_saveImage_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"),
                                                    QString(),
                                                    tr("Images (*.bmp)"));
    if (!fileName.isEmpty())
    {
      image2.getPicture().save(fileName);
    }
}
