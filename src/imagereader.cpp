#include <QTextStream>
#include <QImage>
#include <QImageReader>
#include <QColor>

bool readimage(QTextStream& out, QString path)
{
    QImage img(path);
    if (img.isNull()!=true)
    {
        out << "Width: " << img.width() << endl;
        out << "Height: " << img.height() << endl;
        out << "Depth: " << img.bitPlaneCount() << endl;
        out << "Bytes per line: " << img.bytesPerLine() << endl;

        for (int i = 0; i < img.height(); i++)
        {
            QRgb *rowData = (QRgb *) img.scanLine(i);
            for (int j = 0; j < img.width(); j++)
            {
                QRgb pixelData = rowData[j];
                int red = qRed(pixelData),
                    green = qGreen(pixelData),
                    blue = qBlue(pixelData);
                out << i*img.width()+j+1 << " " << "pixel data: " << "R" << red << "G" << green << "B" << blue << endl;
            }
        }
     } else return false;
}
