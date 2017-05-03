#include "edEncoderImage.h"

edEncoderImage::edEncoderImage()
{

}

void edEncoderImage::encode(edReaderImage &imgreader, QFile &OUTPUT, QTextStream &out)
{
    edEncoder rEncoder;
    edEncoder gEncoder;
    edEncoder bEncoder;

    OUTPUT.open(QIODevice::ReadWrite | QIODevice::Append);

    imgreader.read_pixel(0,0);
    rEncoder.STRING = imgreader.red;
    gEncoder.STRING = imgreader.green;
    bEncoder.STRING = imgreader.blue;
    for (int i = 1; i < imgreader.img.height()*imgreader.img.width(); i++) {
        imgreader.read_pixel();
        rEncoder.LZW(imgreader.red);
        gEncoder.LZW(imgreader.green);
        bEncoder.LZW(imgreader.blue);
        rEncoder.outCODE(OUTPUT);
        gEncoder.outCODE(OUTPUT);
        bEncoder.outCODE(OUTPUT);
        progressbar(i, imgreader.img.height()*imgreader.img.width(), out);
    }

    OUTPUT.close();

    compressionRatio = ((float) (rEncoder.compressedSize + gEncoder.compressedSize + bEncoder.compressedSize)) / ((float) imgreader.img.byteCount() * 3/4);
}

void edEncoderImage::progressbar(const int &byteindex, const int &bytecount, QTextStream &out)
{
    static int p = 1;
    if (byteindex >= p*bytecount/10) {
        out << p * 10 << "%" << " " << "completed" << endl;
        p++;
    }
}
