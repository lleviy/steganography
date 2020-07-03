#include "image.h"

Image::Image()
{

}

Image::Image(QImage pic, QString ext)
{
    picture = pic;
    extension = ext;
}

QImage Image::getPicture(){
    return picture;
}

QString Image::getExtension(){
    return extension;
}

QByteArray Image::toByteArray(){
    QByteArray bytearr;
    QBuffer buffer(&bytearr);
    buffer.open(QIODevice::WriteOnly);
    if (extension == "bmp") picture.save(&buffer, "BMP");
    return bytearr;
}

QBitArray Image::stego(QString extension, QByteArray byteimg, QBitArray bitimg, QBitArray bitmessage){
    if (extension == "bmp"){
        int start = byteimg[10] * 8;
        for (int i = 0; i < bitmessage.size() - 1; i+=2){
            bitimg[start] = bitmessage[i];
            bitimg[start+1] = bitmessage[i+1];
            start += 8;
            }
    }
    return bitimg;
}

QBitArray Image::destego(QString extension, QByteArray byteimg, QBitArray bitimg){
    int start = byteimg[10] * 8;
    QBitArray bitmessage((bitimg.size() - start) / 4);
    for (int i = 0; i < bitmessage.size(); i+=2){
        bitmessage[i] = bitimg[start];
        bitmessage[i+1] = bitimg[start+1];
        start += 8;
    }
    return bitmessage;
}
