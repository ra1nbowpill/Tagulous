#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(""
                    "QListView {"
                    "   background-color: transparent;"
                    "   border: 0;"
                    "   font: 16pt;"
                    "}"
                    "QListView:item:hover {"
                    "   background: rgb(200, 200, 200, 100);"
                    "}"
                    "QListView:item:selected {"
                    "   background: rgb(200, 200, 200, 150);"
                    "   color: rgb(0, 0, 0);"
                    "}"
                    "QLineEdit#searchLineEdit {"
                    "   margin: 5 10 5 10;"
                    "}");
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setAttribute(Qt::AA_DontShowIconsInMenus);
    a.setAttribute(Qt::AA_EnableHighDpiScaling);

    MainWindow w;
    // Resizing the window for the toolbar not to be splitted
    w.setMinimumWidth(285);
    w.setMinimumHeight(300);
#ifdef Q_OS_MAC
    w.setGeometry(0, 0, 280, 500);
#else
    w.setGeometry(0, 31, 280, 500);
#endif /* Q_OS_MAC */
    w.show();

    return a.exec();
}
