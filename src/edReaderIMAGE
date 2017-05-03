#ifndef IMAGEREADER_H
#define IMAGEREADER_H


#include <QTextStream>
#include <QImage>

class edImageReader
{
private:
    int curri = 0, currj = 0;
public:
    QImage img;
    void pixel_data(QTextStream &);
    void image_info(QTextStream &);
    void read_pixel(int, int);
    void read_pixel();
    edImageReader(QString);
    bool read_image_ok = false;
    QChar red, green, blue;
};


#endif // IMAGEREADER_H
