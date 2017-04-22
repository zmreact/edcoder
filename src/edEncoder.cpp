#include "edEncoder.h"

edEncoder::edEncoder(QChar FIRSTCHAR)
{
    STRING = FIRSTCHAR;
    for (int i = 0; i < 256; i++) {
        TABLE.insert((QChar) i, i);
    }
}

void edEncoder::LZW(QChar CHAR)
{
    QHash<QString, int>::const_iterator TABLEiterator = TABLE.find(STRING + CHAR);
    if (TABLEiterator == TABLE.end()) {
        NEWCODE = true;
        CODE = TABLE.find(STRING).value();
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
