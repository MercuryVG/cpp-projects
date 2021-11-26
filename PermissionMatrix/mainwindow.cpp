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
    this->setWindowTitle("PermissionMatrix");
    this->setFixedSize(1500, 600);
    //getting info from database about users
    extern QList<User*> USERS_LIST;
    QFile file("Users.txt");
    if(!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        return;
    }
    file.seek(0);
    QTextStream in(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList user_data = line.split(" ");
        User* user = new User(user_data[0], role_names(user_data[1].toInt()));
        USERS_LIST.append(user);
    }
    file.close();

    //getting info from database about files
    extern QList<File*> FILES_LIST;
    file.setFileName("Files.txt");
    if(!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        return;
    }
    file.seek(0);
    in.setDevice(&file);
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList file_data = line.split(" ");
        QString name;
        Permission_list permissions[7];
        int i = 0;
        for(auto &content : file_data)
        {
            if(i == 0)
            {
                name = content;
                i++;
                continue;
            }
            permissions[i - 1] = Permission_list((content.toInt()));
            i++;
        }
        File* file = new File(name, permissions);
        FILES_LIST.append(file);
    }
    file.close();
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
    if(ui->file_field->text().isEmpty())
    {
        show_error("File name filed is empty");
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
    QString file = ui->file_field->text();
    bool file_in_FILES_LIST = false;
    for(auto &i : FILES_LIST)
    {
        if(i->get_file_name() == file)
        {
            file_in_FILES_LIST = true;
            ui->mainwindow_text_browser->append("User: \"" + name + "\" have rights: \"" + permissions[i->get_permission_for_role(role)] + "\" for file: \"" + i->get_file_name() + "\"");
        }
    }
}

void MainWindow::on_show_users_button_clicked()
{
    ui->mainwindow_text_browser->clear();
    extern QList<User*> USERS_LIST;
    if(USERS_LIST.count() == 0)
    {
        ui->mainwindow_text_browser->append("No users in database");
        return;
    }
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

void MainWindow::on_show_files_button_clicked()
{
    ui->mainwindow_text_browser->clear();
    extern QList<File*> FILES_LIST;
    if(FILES_LIST.count() == 0)
    {
        ui->mainwindow_text_browser->append("No files in database");
        return;
    }
    for(auto &i : FILES_LIST)
    {
        ui->mainwindow_text_browser->append("File: \"" + i->get_file_name() + "\" have permissions: " + permissions[i->get_permission_for_role(0)] + " / " +
                permissions[i->get_permission_for_role(1)] + " / " +
                permissions[i->get_permission_for_role(2)] + " / " +
                permissions[i->get_permission_for_role(3)] + " / " +
                permissions[i->get_permission_for_role(4)] + " / " +
                permissions[i->get_permission_for_role(5)] + " / " +
                permissions[i->get_permission_for_role(6)]);
    }
}


void MainWindow::on_delete_file_button_clicked()
{
    DeleteFileWindow* delete_file_findow = new DeleteFileWindow;
}


void MainWindow::on_delete_user_button_clicked()
{
    DeleteUserWindow* delete_user_window = new DeleteUserWindow;
}

