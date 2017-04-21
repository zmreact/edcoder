#ifndef IMAGEREADER_H
#define IMAGEREADER_H


#include <QTextStream>
#include <QImage>

class edImageReader
{
private:
    QString path;
    QImage img;
    QRgb pixelData;
    bool read_image_ok;
    int red, green, blue;
public:
    void pixel_data(QTextStream &);
    void image_info(QTextStream &);
    void read_pixel(int, int);
    edImageReader(QString val);
};


#endif // IMAGEREADER_H
