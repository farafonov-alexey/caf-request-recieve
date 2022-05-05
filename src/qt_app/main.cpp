#include "about_dialog.h"
#include <QApplication>
#include <QFontDatabase>
#include <QStyleFactory>
#include <QtPlugin>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  About d;
  d.show();
  return a.exec();
}