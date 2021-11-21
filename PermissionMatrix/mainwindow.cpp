#include "mainwindow.h"
#include "ui_mainwindow.h"

void show_error(QString error);

QString permissions[] = {"none", "r", "w", "e", "rw", "re", "we", "rwe"};
QString roles[] = {"Admin", "Engineer", "Staff", "Head of department", "Director", "Standard user", "Guest"};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(QSize(800, 350));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_create_user_button_clicked()
{
    //creating user creation window (destructor do not needed)
    UserWindow* user_window = new UserWindow();
}

void MainWindow::on_exit_button_clicked()
{
    this->close();
}

void MainWindow::on_clear_button_clicked()
{
    ui->user_field->clear();
    ui->mainwindow_text_browser->clear();
}

void MainWindow::on_create_file_button_clicked()
{
    //creating file creation window (destructro do not needed)
    FileWindow* file_window = new FileWindow();
}

void MainWindow::on_show_permissions_button_clicked()
{
    ui->mainwindow_text_browser->clear();
    if(ui->user_field->text().isEmpty())
    {
        show_error("User name field is empty");
        return;
    }
    //extern global users list and check for existing names
    extern QList<User*> USERS_LIST;
    QString name = ui->user_field->text();
    bool user_in_USERS_LIST = false;
    //roles variable to use if user exist
    role_names role;
    for(auto &i : USERS_LIST)
    {
        if(i->get_user_name() == name)
        {
            user_in_USERS_LIST = true;
            role = i->get_user_role();
        }
    }
    if(!user_in_USERS_LIST)
    {
        show_error("User does not exist");
        return;
    }
    //extern global files list and output permissions for users role
    extern QList<File*> FILES_LIST;
    for(auto &i : FILES_LIST)
    {
        //forming output string and appending it in textbrowser
        QString output = "\"" + name + "\" permission for file \"" + i->get_file_name() + "\" = \"" + permissions[i->get_permission_for_role(role)] + "\"";
        ui->mainwindow_text_browser->append(output);
    }
}

void MainWindow::on_show_users_button_clicked()
{
    ui->mainwindow_text_browser->clear();
    extern QList<User*> USERS_LIST;
    for(auto &i : USERS_LIST)
    {
       //forming output string and appending it in textbrowser
       QString output = "User -> \"" + i->get_user_name() + "\" is in \"" + roles[i->get_user_role()] + "\" group";
       ui->mainwindow_text_browser->append(output);
    }
}

void show_error(QString error)
{
    QMessageBox empty_name_messagebox;
    empty_name_messagebox.setText(error);
    empty_name_messagebox.exec();
    return;
}
