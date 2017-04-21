#ifndef ENCODER_H
#define ENCODER_H


#include <QTextStream>
#include "edImageReader.h"

class edEncoder
{
private:
    QString STRING;
public:
    edEncoder(QChar);
    void LZW(QChar);
    QHash<QString, int> TABLE;
};



#endif // ENCODER_H
