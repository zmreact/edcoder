#ifndef EDIMAGEENCODER_H
#define EDIMAGEENCODER_H


#include "edEncoder.h"

class edImageEncoder
{
private:

public:
    edImageEncoder();
    void encode(edImageReader &imgreader, QFile &OUTPUT, QTextStream &out);
    void progressbar(const int &i, const int &bytecount, QTextStream &out);
    float compressionRatio = 1;
};


#endif // EDIMAGEENCODER_H
