#ifndef USERWINDOW_H
#define USERWINDOW_H

#include "User.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>

class UserWindow : public QWidget
{
    Q_OBJECT

public:
    UserWindow();
    ~UserWindow();

private:
    void setup_user_window();


private:
    QPushButton* exit_button;
    QPushButton* generate_user_button;
    QLineEdit* user_name_field;
    QComboBox* user_role_field;
    QLabel* user_name_label;
    QLabel* user_role_label;
    QWidget* vertical_spacer;
    QVBoxLayout* layout;


private slots:
    void on_exit_button_clicked();
    void on_generate_button_clicked();
};

#endif // USERWINDOW_H
