#include "edReaderIMAGE"

edImageReader::edImageReader(QString path)
{
    img.load(path);
    if (img.isNull()) {
        read_image_ok = false;
    } else {
        read_image_ok = true;
    }
}

void edImageReader::read_pixel(int i, int j)
{
    curri = i; currj = j;
    QRgb *rowData = (QRgb *) img.scanLine(i);
    QRgb pixelData = rowData[j];
    red = qRed(pixelData);
    green = qGreen(pixelData);
    blue = qBlue(pixelData);
    currj++;
    if (currj == img.width()) currj = 0, curri++;
    if (curri == img.height()) curri = 0;
}

void edImageReader::read_pixel()
{
    QRgb *rowData = (QRgb *) img.scanLine(curri);
    QRgb pixelData = rowData[currj];
    red = qRed(pixelData);
    green = qGreen(pixelData);
    blue = qBlue(pixelData);
    currj++;
    if (currj == img.width()) currj = 0, curri++;
    if (curri == img.height()) curri = 0;
}


void edImageReader::image_info(QTextStream &out)
{
    if (read_image_ok) {
        out << "Image data" << endl;
        out << "Width: " << img.width() << endl;
        out << "Height: " << img.height() << endl;
        out << "Depth: " << img.bitPlaneCount() << endl;
        out << "Bytes per line: " << img.bytesPerLine() * 3/4 << endl;
    }
}

void edImageReader::pixel_data(QTextStream &out)
{
    if (read_image_ok) {
        for (int i = 0; i < img.height(); i++) {
            for (int j = 0; j < img.width(); j++) {
                read_pixel(i, j);
                out << i*img.width()+j+1 << " " << "pixel data: " << "R" << red.unicode() << "G" << green.unicode() << "B" << blue.unicode() << endl;
            }
        }
    }
}
