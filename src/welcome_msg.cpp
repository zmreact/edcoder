#include <QCommandLineParser>
#include <QTextStream>
#include <QImageReader>

void welcome_msg(QCommandLineParser &parser, QTextStream& out)
{
    QStringList helptextQSL;
    helptextQSL << parser.helpText().split("\n");
    helptextQSL.removeFirst();
    helptextQSL.removeFirst();
    helptextQSL.removeLast();
    QString helptext = (QString) helptextQSL.join("\n");

    QStringList WelcomeMessageQSL;
    WelcomeMessageQSL << "Moscow Technical University of Communication and Informatics" << "\n" << "Department of multimedia networks and communication services" << "\n" << "Course work on MSKvSPD" << "\n" << "Student group: BSU1401" << "\n"
                      << "Developers:" << " " << "Denis Petuhov" << "," << "\n"
                      << "            " << "Korotygin Aleksandr" << "," << "\n"
                      << "            " << "Kaledina Anastasija" << "," << "\n"
                      << "            " << "Gubankova Ekaterina" << "." << "\n"
                      << "\n"
                      << QCoreApplication::instance()->applicationName() << "." << " " << "Version" << " " << QCoreApplication::instance()->applicationVersion() << "\n"
                      << "\n"
                      << "Usage:" << " " << QCoreApplication::instance()->arguments()[0] << " " << "[-e image file to encode] [-d image file to encode]" << "\n"
                      << "Supported file image formats:" << " " << QImageReader::supportedImageFormats().join(", ") << "\n"
                      << "\n"
                      << helptext << "\n"
                      << "\n";
    QString WelcomeMessage = (QString) WelcomeMessageQSL.join("");
    out << WelcomeMessage;
}
