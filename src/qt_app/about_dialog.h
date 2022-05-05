#pragma once
#include <QDialog>

namespace Ui {
class About;
}
class About : public QDialog {
  Q_OBJECT

public:
  explicit About(QWidget* parent = nullptr);
  ~About();
private slots:
  void close_about();

private:
  Ui::About* ui;
};