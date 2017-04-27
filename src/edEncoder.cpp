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
        compressedSize += CODE.size();
        STRING = CHAR;
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
    if (NEWCODE) {
        file.write(CODE);
    }
}

void edEncoder::outLASTCODE(QFile &file)
{
    QDataStream STREAM(&CODE,QIODevice::WriteOnly);
    STREAM << TABLE.find(STRING).value();
    compressedSize += CODE.size();
    outCODE(file);
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
    outLASTCODE(OUTPUT);
    imgreader.read_pixel(0,0);
    STRING = imgreader.green;
    for (int i = 1; i < imgreader.img.height()*imgreader.img.width(); i++) {
        imgreader.read_pixel();
        LZW(imgreader.green);
        outCODE(OUTPUT);
    }
    outLASTCODE(OUTPUT);
    imgreader.read_pixel(0,0);
    STRING = imgreader.blue;
    for (int i = 1; i < imgreader.img.height()*imgreader.img.width(); i++) {
        imgreader.read_pixel();
        LZW(imgreader.blue);
        outCODE(OUTPUT);
    }
    outLASTCODE(OUTPUT);
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
    outLASTCODE(OUTPUT);
}
