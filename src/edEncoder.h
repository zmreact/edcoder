#ifndef ENCODER_H
#define ENCODER_H


#include <QTextStream>
#include <QFile>
#include <bitset>
#include "edImageReader.h"

class edEncoder
{
private:
    QString STRING;
    bool NEWCODE;
public:
    edEncoder(unsigned char);
    void LZW(unsigned char);
    void outCODE(QTextStream &);
    void outCODE(QFile &file);
    QHash<QString, int> TABLE;
    QByteArray CODE;
};



#endif // ENCODER_H
