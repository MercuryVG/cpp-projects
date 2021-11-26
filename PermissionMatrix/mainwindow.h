#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include "userwindow.h"
#include "filewindow.h"
#include "deleteuserwindow.h"
#include <deletefilewindow.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_create_user_button_clicked();
    void on_exit_button_clicked();
    void on_clear_button_clicked();
    void on_create_file_button_clicked();
    void on_show_permissions_button_clicked();
    void on_show_users_button_clicked();

    void on_show_files_button_clicked();

    void on_delete_file_button_clicked();

    void on_delete_user_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
