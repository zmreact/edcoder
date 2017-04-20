#include <QCommandLineOption>
#include <QCommandLineParser>

void setup_parser(QCommandLineParser &parser)
{
    QCommandLineOption encode(QStringList() << "e" << "encode",
            "Encode <image file to encode>",
            "path");
    QCommandLineOption decode(QStringList() << "d" << "decode",
            "Decode <image file to decode>",
            "path");
    QCommandLineOption help(QStringList() << "h" << "help",
            "Shows this help");
    parser.addOption(encode);
    parser.addOption(decode);
    parser.addOption(help);
}
