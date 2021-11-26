#include "deletefilewindow.h"

DeleteFileWindow::DeleteFileWindow()
{
    set_up_window();
    connect(exit_button, SIGNAL( clicked() ), this, SLOT(on_exit_button_clicked()));
    connect(delete_button, SIGNAL( clicked() ), this, SLOT(on_delete_button_clicked()));
}

DeleteFileWindow::~DeleteFileWindow()
{
    QLayoutItem* child;
    //deleting layout content
    while((child = layout->takeAt(0)) != 0)
    {
        delete child;
    }
    delete layout;
}

void DeleteFileWindow::set_up_window()
{
    //calling destructor on close
    this->setAttribute(Qt::WA_DeleteOnClose);

    //initial settings
    this->setFixedSize(350, 150);
    this->setWindowTitle("Delete file");

    exit_button = new QPushButton;
    delete_button = new QPushButton;
    label = new QLabel;
    layout = new QVBoxLayout(this);
    file_field = new QLineEdit;

    exit_button->setText("Exit");
    delete_button->setText("Delete file");
    label->setText("File to delete");

    layout->addWidget(label);
    layout->addWidget(file_field);
    layout->addSpacing(200);
    layout->addWidget(delete_button);
    layout->addWidget(exit_button);

    this->show();
}

void DeleteFileWindow::on_exit_button_clicked()
{
    this->close();
}

void DeleteFileWindow::on_delete_button_clicked()
{
    QString file_name = file_field->text();
    if(file_name.isEmpty())
    {
        QMessageBox error;
        error.setText("File field is empty");
        error.exec();
        return;
    }
    extern QList<File*> FILES_LIST;
    bool file_in_FILES_LIST = false;
    QList<File*>::iterator it = FILES_LIST.begin();
    while(it != FILES_LIST.end())
    {
        if((*it)->get_file_name() == file_name)
        {
            //deleting file from List
            file_in_FILES_LIST = true;
            delete (*it);
            it = FILES_LIST.erase(it);
        }
        else
        {
            ++it;
        }
    }
    if(file_in_FILES_LIST)
    {
        QVector<QString> files;
        QFile file("Files.txt");
        if(!file.open(QIODevice::OpenModeFlag::ReadOnly))
        {
            return;
        }
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList file_data = line.split(" ");
            if(file_name == file_data[0])
            {
                continue;
            }
            files.append(line);
        }
        file.close();
        file.setFileName("Files.txt");
        if(!file.open(QIODevice::OpenModeFlag::WriteOnly))
        {
            return;
        }
        file.resize(0);
        file.seek(0);
        for(auto &i : files)
        {
            in << i << '\n';
        }
        file.close();
    }
    else
    {
        QMessageBox error;
        error.setText("No such file if database");
        error.exec();
    }
    file_field->clear();
}
