#ifndef ENCODER_H
#define ENCODER_H


#include <QDataStream>
#include <QTextStream>
#include <QFile>
#include "edReaderImage.h"

class edEncoder
{
private:

protected:

public:
    edEncoder();
    QString STRING;
    bool NEWCODE;
    void LZW(const QChar &);
    void outCODE(QTextStream &);
    void outCODE(QFile &);
    void outLASTCODE(QFile &);
    QHash<QString, unsigned short> TABLE;
    QByteArray CODE;
    int compressedSize = 0;
};


#endif // ENCODER_H
