#ifndef SUREDIALOG_H
#define SUREDIALOG_H

#include <QDialog>

namespace Ui {
class sureDialog;
}

class sureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit sureDialog(QWidget *parent = nullptr);
    ~sureDialog();

private:
    Ui::sureDialog *ui;
};

#endif // SUREDIALOG_H
