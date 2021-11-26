#ifndef DELETEFILEWINDOW_H
#define DELETEFILEWINDOW_H

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
#include "file.h"
class DeleteFileWindow : public QWidget
{
    Q_OBJECT

public:
    DeleteFileWindow();
    ~DeleteFileWindow();

    void set_up_window();

private slots:
    void on_exit_button_clicked();
    void on_delete_button_clicked();

private:
    QPushButton* exit_button;
    QPushButton* delete_button;
    QLabel* label;
    QLineEdit* file_field;
    QVBoxLayout* layout;
};

#endif // DELETEFILEWINDOW_H
