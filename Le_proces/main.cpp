#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QFontDatabase>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    // Initialisation du temps (pour la génération aléatoire)
    srand(time(0));

    QApplication a(argc, argv);
    MainWindow w;

    //Chargement des polices spécifiques
    QFontDatabase::addApplicationFont(":/Apparence/Xolonium-Regular.ttf");
    QFontDatabase::addApplicationFont(":/Apparence/Xolonium-Bold.ttf");


    //Chargement de la feuilel de style
    QFile styleFile( ":/Apparence/Style.qss" );
    styleFile.open( QFile::ReadOnly );
    a.setStyleSheet( QString::fromLatin1( styleFile.readAll() ) );
    styleFile.close();

    //QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_fr"), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);

    QTranslator qtBaseTranslator;
    translator.load(QString("qtbase_fr"), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);

    w.setWindowTitle("Le Procès");
    w.setWindowState(w.windowState() ^ Qt::WindowFullScreen);
    w.show();
    w.positionner_boutons();

    return a.exec();
}
