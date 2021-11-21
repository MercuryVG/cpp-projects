#include "userwindow.h"

bool check_for_proper_user_name(QString name);
void show_user_error(QString error);

UserWindow::UserWindow()
{
    setup_user_window();

    //connecting buttons signal on clicked to functions
    connect(exit_button, SIGNAL( clicked() ), this, SLOT(on_exit_button_clicked()));
    connect(generate_user_button, SIGNAL( clicked() ), this, SLOT(on_generate_button_clicked()));
}

UserWindow::~UserWindow()
{
    //deleting all widgets in layout
    QLayoutItem* child;
    while((child = layout->takeAt(0)) != 0)
    {
        delete child;
    }
    //deleting layout
    delete layout;
}


void UserWindow::setup_user_window()
{
    //calling destructor on close
    this->setAttribute(Qt::WA_DeleteOnClose);

    //making initial window settings
    this->setFixedSize(350, 200);
    this->setWindowTitle("create user");

    //creating window widgets
    layout = new QVBoxLayout(this);
    user_name_label = new QLabel;
    user_name_field = new QLineEdit;
    user_role_label = new QLabel;
    user_role_field = new QComboBox;
    generate_user_button = new QPushButton;
    exit_button = new QPushButton;

    //setting names for widgets and variants for combobox
    user_name_label->setText("User name");
    user_role_label->setText("User role");
    user_role_field->addItem("Admin", 0);
    user_role_field->addItem("Engineer", 1);
    user_role_field->addItem("Staff", 2);
    user_role_field->addItem("Department head", 3);
    user_role_field->addItem("Director", 4);
    user_role_field->addItem("Standard user", 5);
    user_role_field->addItem("Guest", 6);
    generate_user_button->setText("Generate");
    exit_button->setText("Exit");

    //adding widgets to layout
    layout->addWidget(user_name_label);
    layout->addWidget(user_name_field);
    layout->addWidget(user_role_label);
    layout->addWidget(user_role_field);
    layout->addSpacing(55);
    layout->addWidget(generate_user_button);
    layout->addWidget(exit_button);

    this->show();
}

void UserWindow::on_exit_button_clicked()
{
    this->close();
}

void UserWindow::on_generate_button_clicked()
{
    QString name = user_name_field->text();
    if(name.isEmpty())
    {
        show_user_error("Name can not be less than 1 letter");
        return;
    }
    if(check_for_proper_user_name(name))
    {
        show_user_error("User already exist");
        return;
    }
    role_names role;
    role = role_names(user_role_field->itemData(user_role_field->currentIndex()).toInt());

    //creating user object with gui values name and role
    User* user = new User(name, role);
    extern QList<User*> USERS_LIST;

    //appending user to global users list
    USERS_LIST.append(user);

    user_name_field->clear();
}

bool check_for_proper_user_name(QString name)
{
    //extern users list and check if name exist in users list
    bool name_in_USERS_LIST = false;
    extern QList<User*> USERS_LIST;
    for(auto &i: USERS_LIST)
    {
        if(i->get_user_name() == name)
        {
            name_in_USERS_LIST = true;
        }
    }
    return name_in_USERS_LIST;
}

void show_user_error(QString error)
{
    QMessageBox empty_name_messagebox;
    empty_name_messagebox.setText(error);
    empty_name_messagebox.exec();
    return;
}
