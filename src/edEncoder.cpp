#include "edEncoder.h"

edEncoder::edEncoder()
{
    for (unsigned short i = 0; i < 256; i++) {
        TABLE.insert((QChar) i, i);
    }
}

void edEncoder::LZW(const QChar &CHAR)
{
    QHash<QString, unsigned short>::const_iterator TABLEiterator = TABLE.find(STRING + CHAR);
    if (TABLEiterator == TABLE.end()) {
        NEWCODE = true;
        TABLE.insert(STRING + CHAR, TABLE.size());
        QDataStream STREAM(&CODE,QIODevice::WriteOnly);
        STREAM << TABLE.find(STRING).value();
        STRING = CHAR;
        compressedSize += CODE.size();
    } else {
        NEWCODE = false;
        STRING += CHAR;
    }
}

void edEncoder::outCODE(QTextStream &out)
{
    if (NEWCODE) out << CODE << endl;
}

void edEncoder::outCODE(QFile &file)
{
    if (NEWCODE) file.write(CODE);
}









edImageEncoder::edImageEncoder()
{
}

void edImageEncoder::encode(edImageReader &imgreader, QFile &OUTPUT)
{
    OUTPUT.open(QIODevice::ReadWrite | QIODevice::Append);

    imgreader.read_pixel(0,0);
    STRING = imgreader.red;
    for (int i = 1; i < imgreader.img.height()*imgreader.img.width(); i++) {
        imgreader.read_pixel();
        LZW(imgreader.red);
        outCODE(OUTPUT);
    }
    QDataStream STREAM1(&CODE,QIODevice::WriteOnly);
    STREAM1 << TABLE.find(STRING).value();
    compressedSize += CODE.size();

    imgreader.read_pixel(0,0);
    STRING = imgreader.green;
    for (int i = 1; i < imgreader.img.height()*imgreader.img.width(); i++) {
        imgreader.read_pixel();
        LZW(imgreader.green);
        outCODE(OUTPUT);
    }
    QDataStream STREAM2(&CODE,QIODevice::WriteOnly);
    STREAM2 << TABLE.find(STRING).value();
    compressedSize += CODE.size();

    imgreader.read_pixel(0,0);
    STRING = imgreader.blue;
    for (int i = 1; i < imgreader.img.height()*imgreader.img.width(); i++) {
        imgreader.read_pixel();
        LZW(imgreader.blue);
        outCODE(OUTPUT);
    }
    QDataStream STREAM3(&CODE,QIODevice::WriteOnly);
    STREAM3 << TABLE.find(STRING).value();
    compressedSize += CODE.size();

    OUTPUT.close();
    compressionRate = (float) compressedSize / ((float) imgreader.img.byteCount() * 3/4);
}











edTextEncoder::edTextEncoder()
{

}

void edTextEncoder::encode(const QString &INPUT, QFile &OUTPUT)
{
    STRING = INPUT[0];
    for (int i = 1; i < INPUT.length(); i++) {
        LZW(INPUT[i]);
        outCODE(OUTPUT);
    }
    QDataStream STREAM(&CODE,QIODevice::WriteOnly);
    STREAM << TABLE.find(STRING).value();
    compressedSize += CODE.size();
    outCODE(OUTPUT);
}
