#ifndef IMAGEREADER_H
#define IMAGEREADER_H


#include <QTextStream>
#include <QImage>

class edImageReader
{
private:
    QImage img;
    QRgb pixelData;
    int red, green, blue;
    bool read_image_ok = false;
public:
    void pixel_data(QTextStream &);
    void image_info(QTextStream &);
    void read_pixel(int, int);
    edImageReader(QString path);
};


#endif // IMAGEREADER_H
