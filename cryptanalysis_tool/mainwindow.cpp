#include "mainwindow.h"
#include "ui_mainwindow.h"

void setup_counter(QVector<Counter>& letter_vector, QVector<char> counter_method);
QVector<Counter> histogram_data_gathering(QString data, Ui::MainWindow* ui, double& sum);
void create_chart(QVector<Counter> statistic, double sum, Ui::MainWindow* ui);

QVector<char> ENGLISH_ALPHABET = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
QVector<char> NUMBERS = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),  ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generation_button_clicked()
{
    QString data = ui->textEdit->toPlainText();
    if(data.length() == 0)
    {
        QMessageBox::warning(this, tr("occurrences analysis"),tr("You need to fill the input field"), QMessageBox::Ok);
        return;
    }
    if(ui->radioButtonNumbers->isChecked())
    {
        double sum = 0;
        QVector<Counter> statistic = histogram_data_gathering(data, ui, sum);
        create_chart(statistic, sum, ui);
    }
    else if(ui->radioButtonLetters->isChecked())
    {
        double sum = 0;
        QVector<Counter> statistic = histogram_data_gathering(data, ui, sum);
        create_chart(statistic, sum, ui);
    }
    else
    {
       QMessageBox::warning(this, tr("occurrences analysis"), tr("You need to choose \ncryptanalysis type"), QMessageBox::Ok);
    }
}


QVector<Counter> histogram_data_gathering(QString data, Ui::MainWindow* ui, double& sum)
{
    int progress_bar_value = 0;
    ui->progressBar->setValue(progress_bar_value);

    bool is_letter = ui->radioButtonLetters->isChecked();

    QVector<Counter> counter_vector;
    if(is_letter)
    {
        setup_counter(counter_vector, ENGLISH_ALPHABET);
    }
    else
    {
        setup_counter(counter_vector, NUMBERS);
    }
    int progress_bar_step = ceil(double(data.length()) / 100);
    int progress_bar_counter = 0;
    for(QChar value: data)
    {
        progress_bar_counter += 1;
        if(progress_bar_counter == progress_bar_step)
        {
            progress_bar_value += 1;
            ui->progressBar->setValue(progress_bar_value);
            progress_bar_counter = 0;
        }
        if(value.isDigit() && !is_letter)
        {
            for(Counter& counter : counter_vector)
            {
                if(value == counter.data)
                {
                    counter.occurrences ++;
                    break;
                }
            }
        }
        else
        {
            for(Counter& counter : counter_vector)
            {
                if(value.toLower() == counter.data)
                {
                    counter.occurrences ++;
                    sum ++;
                    break;
                }
            }
        }
    }
    if(progress_bar_value < 100)
    {
        progress_bar_value += 100 - progress_bar_value;
        ui->progressBar->setValue(progress_bar_value);
    }
    return counter_vector;
}

void setup_counter(QVector<Counter>& letter_vector, QVector<char>counter_method)
{
    for(auto i : counter_method)
    {
        Counter tmp;
        tmp.data = i;
        letter_vector.append(tmp);
    }
}

void create_chart(QVector<Counter> statistic, double sum, Ui::MainWindow* ui)
{
    ui->textBrowser->setText("");
    for(auto i : statistic)
    {
        if(i.occurrences > 0)
        {
            QString tmp = QString(i.data) + " was used " + QString::number(i.occurrences) + " times, that is " + QString::number((i.occurrences / sum) * 100) + " %";
            ui->textBrowser->append(tmp);
        }
        else
        {
            ui->textBrowser->append(QString(i.data) + " was used 0 times, that is 0%");
        }
    }
}





