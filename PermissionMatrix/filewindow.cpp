#include "filewindow.h"

void show_file_error(QString error);
bool check_for_proper_file_name(QString name);

FileWindow::FileWindow()
{
    setup_file_window();
    //connecting buttons on click to functions
    connect(exit_button, SIGNAL( clicked() ), this, SLOT(on_exit_button_clicked()));
    connect(generate_button, SIGNAL( clicked() ), this, SLOT(on_generate_button_clicked()));
    connect(reset_button, SIGNAL( clicked() ), this, SLOT(on_reset_button_clicked()));
    connect(role_combobox, SIGNAL( currentIndexChanged(int) ), this, SLOT( on_role_combobox_changed(int)));
    connect(permissions_combobox, SIGNAL( currentIndexChanged(int) ), this, SLOT( on_permissions_combobox_changed(int)));
    //
}

FileWindow::~FileWindow()
{

    QLayoutItem* child;
    //deleting internal left layout content
    while((child = internal_left_layout->takeAt(0)) != 0)
    {
        delete child;
    }
    //deleting left layout content
    while((child = left_layout->takeAt(0)) != 0)
    {
        delete child;
    }
    //deleting right layout content
    while((child = right_layout->takeAt(0)) != 0)
    {
        delete child;
    }
    //deleting initial layout content
    while((child = initial_layout->takeAt(0)) != 0)
    {
        delete child;
    }
    //deleting intitial layout
    delete initial_layout;

}

void FileWindow::setup_file_window()
{
    //calling destructor on close
    this->setAttribute(Qt::WA_DeleteOnClose);

    //making initial window settings
    this->setFixedSize(300, 250);
    this->setWindowTitle("create file");

    //creating window layouts / buttons / labels / comboboxes
    initial_layout = new QHBoxLayout(this);
    left_layout = new QVBoxLayout;
    right_layout = new QVBoxLayout;
    internal_left_layout = new QHBoxLayout;
    filename_label = new QLabel;
    filename_field = new QLineEdit;
    role_label = new QLabel;
    role_combobox = new QComboBox;
    permission_label = new QLabel;
    permissions_combobox = new QComboBox;
    generate_button = new QPushButton;
    exit_button = new QPushButton;
    reset_button = new QPushButton;

    //setting names for widgets and variants for combobox
    filename_label->setText("filename");
    role_label->setText("role");
    permission_label->setText("permission");
    role_combobox->addItem("Admin", 0);
    role_combobox->addItem("Engineer", 1);
    role_combobox->addItem("Staff", 2);
    role_combobox->addItem("Department head", 3);
    role_combobox->addItem("Director", 4);
    role_combobox->addItem("Standard user", 5);
    role_combobox->addItem("Guest", 6);
    permissions_combobox->addItem("none", 0);
    permissions_combobox->addItem("r", 1);
    permissions_combobox->addItem("w", 2);
    permissions_combobox->addItem("e", 3);
    permissions_combobox->addItem("rw", 4);
    permissions_combobox->addItem("re", 5);
    permissions_combobox->addItem("we", 6);
    permissions_combobox->addItem("rwe", 7);
    generate_button->setText("Generate");
    exit_button->setText("Exit");
    reset_button->setText("Reset");

    //adding widgets in left layout
    left_layout->addWidget(filename_label);
    left_layout->addWidget(filename_field);
    left_layout->addSpacing(220);

    //adding widgets in left internal layout
    internal_left_layout->addWidget(generate_button);
    internal_left_layout->addWidget(exit_button);

    //adding left internal layout into left layout
    left_layout->addLayout(internal_left_layout);

    //adding widgets in right layout
    right_layout->addWidget(role_label);
    right_layout->addWidget(role_combobox);
    right_layout->addWidget(permission_label);
    right_layout->addWidget(permissions_combobox);
    right_layout->addSpacing(200);
    right_layout->addWidget(reset_button);

    //adding layout's in initial layout
    initial_layout->addLayout(left_layout);
    initial_layout->addLayout(right_layout);

    working_file = new File;
    this->show();
}

void FileWindow::on_exit_button_clicked()
{
    this->close();
}

void FileWindow::on_generate_button_clicked()
{
    QString name = filename_field->text();
    if(name.isEmpty())
    {
        show_file_error("File name must be bigger than 1 letter");
        return;
    }
    if(check_for_proper_file_name(name))
    {
        show_file_error("File name already exists");
        return;
    }

    //get global list of files and append it with generated one
    extern QList<File*> FILES_LIST;
    QFile file("Files.txt");
    if(!file.open(QIODevice::OpenModeFlag::Append))
    {
        show_file_error("Not able to write to file database");
        return;
    }
    working_file->set_file_name(name);
    QTextStream in(&file);
    in << working_file->get_file_name() + " " + QString::number(working_file->get_permission_for_role(0)) + " " + QString::number(working_file->get_permission_for_role(1)) + " " + QString::number(working_file->get_permission_for_role(2)) + " " +
          QString::number(working_file->get_permission_for_role(3)) + " " + QString::number(working_file->get_permission_for_role(4)) + " " + QString::number(working_file->get_permission_for_role(5)) + " " + QString::number(working_file->get_permission_for_role(6)) + " " +
          QString::number(working_file->get_permission_for_role(7)) << '\n';
    file.close();
    FILES_LIST.append(this->working_file);
    filename_field->clear();

    this->working_file = new File;
    permissions_combobox->setCurrentIndex(0);
    role_combobox->setCurrentIndex(0);

    //creating new working file after appending int
}

void FileWindow::on_reset_button_clicked()
{
    working_file->reset_all_permissions();
    //when role stay on 0 index after reset changes permissions to none
    if(role_combobox->currentIndex() == 0)
    {
        permissions_combobox->setCurrentIndex(0);
    }
    role_combobox->setCurrentIndex(0);
}

void FileWindow::on_role_combobox_changed(int index)
{
    //get info about file permission in file and set it in gui after change
    int permission = working_file->get_permission_for_role(index);
    permissions_combobox->setCurrentIndex(permission);
}

void FileWindow::on_permissions_combobox_changed(int index)
{
    //get info about file role in file and set it in gui after change
    int role = role_combobox->currentIndex();
    working_file->update_permission_for_role(role, index);
}

bool check_for_proper_file_name(QString name)
{
    //extern global list of file to check for name collission
    extern QList<File*> FILES_LIST;
    bool name_in_FILES_LIST = false;
    for(auto &i: FILES_LIST)
    {
        if(i->get_file_name() == name)
        {
            //user name in list
            name_in_FILES_LIST = true;
        }
    }
    return name_in_FILES_LIST;
}

void show_file_error(QString error)
{
    QMessageBox empty_name_messagebox;
    empty_name_messagebox.setText(error);
    empty_name_messagebox.exec();
    return;
}

