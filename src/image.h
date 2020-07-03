#ifndef IMAGE_H
#define IMAGE_H

#include <QBitArray>
#include <QImage>
#include <QBuffer>

class Image
{
public:
    Image();
    Image(QImage picture, QString extension);
    QImage getPicture();
    QString getExtension();
    QByteArray toByteArray();
    QBitArray stego(QString extension, QByteArray byteimg, QBitArray bitimg, QBitArray bitmessage);
    QBitArray destego(QString extension, QByteArray byteimg, QBitArray bitimg);
private:
    QImage picture;
    QString extension;
};

#endif // IMAGE_H
