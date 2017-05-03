#ifndef EDTEXTENCODER_H
#define EDTEXTENCODER_H


#include "edEncoder.h"

class edEncoderText
{
private:

public:
    edEncoderText();
    void encode(const QString &INPUT, QFile &OUTPUT);
};


#endif // EDTEXTENCODER_H
