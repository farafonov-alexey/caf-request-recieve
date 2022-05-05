#include "about_dialog.h"
#include "library/interface.h"
#include "ui_about_dialog.h"

About::About(QWidget *parent) : QDialog(parent), ui(new Ui::About) {
  ui->setupUi(this);
  this->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
  connect(ui->apply_pb, SIGNAL(clicked()), this, SLOT(close_about()));
}

About::~About() { delete ui; }
void About::close_about() {
  lib_create();
  for (int i = 0; i < 50; i++) {
    lib_do_stuff(1, 2);
  }
  lib_destroy();
  // this->close();
}
