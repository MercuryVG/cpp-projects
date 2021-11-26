#include "deleteuserwindow.h"

DeleteUserWindow::DeleteUserWindow()
{
    set_up_window();
    connect(exit_button, SIGNAL( clicked() ), this, SLOT(on_exit_button_clicked()));
    connect(delete_button, SIGNAL( clicked() ), this, SLOT(on_delete_button_clicked()));
}

DeleteUserWindow::~DeleteUserWindow()
{
    QLayoutItem* child;
    //deleting layout content
    while((child = layout->takeAt(0)) != 0)
    {
        delete child;
    }
    delete layout;
}

void DeleteUserWindow::set_up_window()
{
    //calling destructor on close
    this->setAttribute(Qt::WA_DeleteOnClose);

    //initial settings
    this->setFixedSize(350, 150);
    this->setWindowTitle("Delete user");

    exit_button = new QPushButton;
    delete_button = new QPushButton;
    label = new QLabel;
    layout = new QVBoxLayout(this);
    user_field = new QLineEdit;

    exit_button->setText("Exit");
    delete_button->setText("Delete user");
    label->setText("User to delete");

    layout->addWidget(label);
    layout->addWidget(user_field);
    layout->addSpacing(200);
    layout->addWidget(delete_button);
    layout->addWidget(exit_button);

    this->show();
}

void DeleteUserWindow::on_exit_button_clicked()
{
    this->close();
}

void DeleteUserWindow::on_delete_button_clicked()
{
    QString user_name = user_field->text();
    if(user_name.isEmpty())
    {
        QMessageBox error;
        error.setText("User field is empty");
        error.exec();
        return;
    }
    extern QList<User*> USERS_LIST;
    bool user_in_USERS_LIST = false;
    QList<User*>::iterator it = USERS_LIST.begin();
    while(it != USERS_LIST.end())
    {
        if((*it)->get_user_name() == user_name)
        {
            //deleting user from List
            delete (*it);
            it = USERS_LIST.erase(it);
            user_in_USERS_LIST = true;
        }
        else
        {
            ++it;
        }
    }
    user_field->clear();
    if(user_in_USERS_LIST)
    {
        QVector<QString> users;
        QFile file("Users.txt");
        if(!file.open(QIODevice::OpenModeFlag::ReadOnly))
        {
            return;
        }
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList user_data = line.split(" ");
            if(user_name == user_data[0])
            {
                continue;
            }
            users.append(line);
        }
        file.close();
        file.setFileName("Users.txt");
        if(!file.open(QIODevice::OpenModeFlag::WriteOnly))
        {
            return;
        }
        file.resize(0);
        file.seek(0);
        for(auto &i : users)
        {
            in << i << '\n';
        }
        file.close();
    }
    else
    {
        QMessageBox error;
        error.setText("No such user in database");
        error.exec();
    }
    user_field->clear();
}

