#include "edImageReader.h"

edImageReader::edImageReader(QString val)
{
    path = val;
}

void edImageReader::read_pixel(int i, int j)
{
    img.load(path);
    if (img.isNull()) {
        read_image_ok = false;
    } else {
        QRgb *rowData = (QRgb *) img.scanLine(i);
        QRgb pixelData = rowData[j];
        red = qRed(pixelData);
        green = qGreen(pixelData);
        blue = qBlue(pixelData);
        read_image_ok = true;
    }
}

void edImageReader::image_info(QTextStream &out)
{
    if (read_image_ok) {
        out << "Image data" << endl;
        out << "Width: " << img.width() << endl;
        out << "Height: " << img.height() << endl;
        out << "Depth: " << img.bitPlaneCount() << endl;
        out << "Bytes per line: " << img.bytesPerLine() << endl;
    }
}

void edImageReader::pixel_data(QTextStream &out)
{
    img.load(path);
    if (img.isNull()) {
        read_image_ok = false;
    } else {
        for (int i = 0; i < img.height(); i++) {
            for (int j = 0; j < img.width(); j++) {
                read_pixel(i, j);
                out << i*img.width()+j+1 << " " << "pixel data: " << "R" << red << "G" << green << "B" << blue << endl;
            }
        }
        read_image_ok = true;
    }
}
