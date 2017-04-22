#include "edEncoder.h"

edEncoder::edEncoder(unsigned char FIRSTCHAR)
{
    STRING = FIRSTCHAR;
    for (int i = 0; i < 256; i++) {
        TABLE.insert((QChar) i, i);
    }
}

void edEncoder::LZW(unsigned char CHAR)
{
    QHash<QString, int>::const_iterator TABLEiterator = TABLE.find(STRING + CHAR);
    if (TABLEiterator == TABLE.end()) {
        QDataStream STREAM(&CODE,QIODevice::WriteOnly);
        NEWCODE = true;
        STREAM << TABLE.find(STRING).value();
        TABLE.insert(STRING + CHAR, TABLE.size());
        STRING = CHAR;
    } else {
        NEWCODE = false;
        STRING += CHAR;
    }
}

void edEncoder::outCODE(QTextStream &out)
{
    if (NEWCODE) out << CODE << "\n";
}

void edEncoder::outCODE(QFile &file)
{
    if (NEWCODE && file.open(QIODevice::ReadWrite | QIODevice::Append)) {
        file.write(CODE);
        file.close();
    }
}
