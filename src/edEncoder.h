#ifndef ENCODER_H
#define ENCODER_H


#include <QTextStream>
#include <QFile>
#include <bitset>
#include "edImageReader.h"

using namespace std;

class edEncoder
{
private:
    QString STRING;
    bool NEWCODE;
public:
    edEncoder(QChar);
    void LZW(QChar);
    void outCODE(QTextStream &);
    void outCODE(QFile &file);
    QHash<QString, int> TABLE;
    QByteArray CODE;
};


#endif // ENCODER_H
