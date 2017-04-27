#ifndef ENCODER_H
#define ENCODER_H


#include <QTextStream>
#include <QFile>
#include "edImageReader.h"

class edEncoder
{
private:

protected:
    QString STRING;
    bool NEWCODE;
    void LZW(const QChar &);
    void outCODE(QTextStream &);
    void outCODE(QFile &);
    void outLASTCODE(QFile &);
    QHash<QString, unsigned short> TABLE;
    QByteArray CODE;
    int compressedSize;
public:
    edEncoder();
    float compressionRate;
};


class edImageEncoder : public edEncoder
{
private:

public:
    edImageEncoder();
    void encode(edImageReader &imgreader, QFile &OUTPUT);
};


class edTextEncoder : public edEncoder
{
private:

public:
    edTextEncoder();
    void encode(const QString &INPUT, QFile &OUTPUT);
};


#endif // ENCODER_H
