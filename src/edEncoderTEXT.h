#ifndef EDTEXTENCODER_H
#define EDTEXTENCODER_H


#include "edEncoder.h"

class edTextEncoder : public edEncoder
{
private:

public:
    edTextEncoder();
    void encode(const QString &INPUT, QFile &OUTPUT);
};


#endif // EDTEXTENCODER_H
