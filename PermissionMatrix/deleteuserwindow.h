#ifndef DELETEUSERWINDOW_H
#define DELETEUSERWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QVector>
#include <QList>
#include "User.h"

class DeleteUserWindow : public QWidget
{
    Q_OBJECT

public:
    DeleteUserWindow();
    ~DeleteUserWindow();

    void set_up_window();

private slots:
    void on_exit_button_clicked();
    void on_delete_button_clicked();

private:
    QPushButton* exit_button;
    QPushButton* delete_button;
    QLabel* label;
    QLineEdit* user_field;
    QVBoxLayout* layout;
};

#endif // DELETEUSERWINDOW_H
