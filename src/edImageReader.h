#ifndef IMAGEREADER_H
#define IMAGEREADER_H


#include <QTextStream>
#include <QImage>

class edImageReader
{
private:
    QRgb pixelData;
    int red, green, blue;
public:
    QImage img;
    void pixel_data(QTextStream &);
    void image_info(QTextStream &);
    void read_pixel(int, int);
    edImageReader(QString);
    bool read_image_ok = false;
};


#endif // IMAGEREADER_H
