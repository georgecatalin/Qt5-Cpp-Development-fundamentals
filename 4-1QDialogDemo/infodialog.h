#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

    QString getPosition() const;

    QString getFavouriteOS() const;

private slots:
    void on_okPushButton_clicked();

    void on_cancelPushButton_clicked();

private:

    Ui::InfoDialog *ui;

    QString position;
    QString favouriteOS;
};

#endif // INFODIALOG_H
