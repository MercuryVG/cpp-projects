#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "permissions.h"
#include "file.h"

class FileWindow : public QWidget
{
    Q_OBJECT

public:
    FileWindow();
    ~FileWindow();

private:
    void setup_file_window();

private slots:
    void on_generate_button_clicked();
    void on_reset_button_clicked();
    void on_role_combobox_changed(int index);
    void on_permissions_combobox_changed(int index);
    void on_exit_button_clicked();

private:
    QHBoxLayout* initial_layout;
    QVBoxLayout* left_layout;
    QVBoxLayout* right_layout;
    QHBoxLayout* internal_left_layout;
    QLabel* filename_label;
    QLabel* role_label;
    QLabel* permission_label;
    QLineEdit* filename_field;
    QPushButton* generate_button;
    QPushButton* reset_button;
    QPushButton* exit_button;
    QComboBox* role_combobox;
    QComboBox* permissions_combobox;
    File* working_file;
};

#endif // FILEWINDOW_H
