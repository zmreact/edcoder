#include "edEncoderText.h"

edEncoderText::edEncoderText()
{

}

void edEncoderText::encode(const QString &INPUT, QFile &OUTPUT)
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
