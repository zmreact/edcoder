#include "edEncoder.h"

edEncoder::edEncoder(QChar FIRSTCHAR)
{
    STRING = FIRSTCHAR;
}

void edEncoder::LZW(QChar CHAR)
{
    QHash<QString, int>::const_iterator TABLEiterator = TABLE.find(STRING + CHAR);
    if (TABLEiterator == TABLE.end() || TABLEiterator.key() != STRING + CHAR) {
        TABLE.insert(STRING + CHAR, TABLE.size());
        STRING = CHAR;
    } else {
        STRING += CHAR;
    }
}
