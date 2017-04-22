#ifndef ENCODER_H
#define ENCODER_H


#include <QTextStream>
#include "edImageReader.h"

class edEncoder
{
private:
    QString STRING;
    bool NEWCODE;
public:
    edEncoder(QChar);
    void LZW(QChar);
    void outCODE(QTextStream &);
    QHash<QString, int> TABLE;
    int CODE;
};



#endif // ENCODER_H
