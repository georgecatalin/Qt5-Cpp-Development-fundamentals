#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include <QDebug>

namespace Ui {
class infodialog;
}

class infodialog : public QDialog
{
    Q_OBJECT

public:
    explicit infodialog(QWidget *parent = nullptr);
    ~infodialog();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::infodialog *ui;
};

#endif // INFODIALOG_H
