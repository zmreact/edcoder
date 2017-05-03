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
