#ifndef edEncoderImage_H
#define edEncoderImage_H


#include "edEncoder.h"

class edEncoderImage
{
private:

public:
    edEncoderImage();
    void encode(edReaderImage &imgreader, QFile &OUTPUT, QTextStream &out);
    void progressbar(const int &i, const int &bytecount, QTextStream &out);
    float compressionRatio = 1;
};


#endif // edEncoderImage_H
