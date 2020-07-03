#include "decrypttab.h"
#include "ui_decrypttab.h"

DecryptTab::DecryptTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DecryptTab)
{
    ui->setupUi(this);
}

DecryptTab::~DecryptTab()
{
    delete ui;
}

void DecryptTab::on_decrypt_clicked()
{
    QByteArray byteimage = image.toByteArray();
    QBitArray bitimage = bytesToBits(byteimage);
    QBitArray bitmessage = image.destego(image.getExtension(), byteimage, bitimage);
    QByteArray resultmessage = bitsToBytes(bitmessage);
    QString message = QString(resultmessage);
    ui->textEdit->setText(message);
}

void DecryptTab::on_loadImage_clicked()
{
    QString FileName=QFileDialog::getOpenFileName(this, "Load Image");
    QFileInfo fi(FileName);
    image = Image(QImage(FileName), fi.completeSuffix());
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->addPixmap(QPixmap::fromImage(image.getPicture()));
    ui->graphicsView->setScene(scene);
}
