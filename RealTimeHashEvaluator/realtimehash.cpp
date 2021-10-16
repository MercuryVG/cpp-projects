#include "realtimehash.h"
#include "ui_realtimehash.h"


void calculate_hash(Ui::RealTimeHash* ui);
QString hash_calculation(QString data, QCryptographicHash::Algorithm algorithm);


RealTimeHash::RealTimeHash(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::RealTimeHash)
{
    ui->setupUi(this);
    ui->input_field->installEventFilter(this);
}

RealTimeHash::~RealTimeHash()
{
    delete ui;
}


void RealTimeHash::on_exit_button_clicked()
{
    QApplication::exit();
}


void RealTimeHash::on_clear_button_clicked()
{
    ui->input_field->setText("");
    ui->output_field->setText("");
}

bool RealTimeHash::eventFilter(QObject *target, QEvent *event)
{
  if (target == ui->input_field)
  {
    if (event->type() == QEvent::KeyPress)
    {
          QKeyEvent *keyEvent = (QKeyEvent *)event;
          QTextCursor input_field_cursor = ui->input_field->textCursor();
          ui->input_field->moveCursor (QTextCursor::End);
          if(keyEvent->text() == "\b")
          {
              input_field_cursor.deletePreviousChar();
              calculate_hash(ui);

              return true;
          }
          if(keyEvent->text() == "")
          {
              QClipboard *clip = QApplication::clipboard();
              QString tmp = clip->text();
              ui->input_field->insertPlainText (tmp);
              ui->input_field->setTextCursor (input_field_cursor);
              calculate_hash(ui);

              return true;
          }
          if(ui->sha_hash_radio_button->isChecked() || ui->md5_hash_radio_button->isChecked() || ui->keccak_hash_radio_button->isChecked())
          {
              ui->input_field->insertPlainText (keyEvent->text());
              ui->input_field->setTextCursor (input_field_cursor);
              calculate_hash(ui);

              return true;
          }
          QMessageBox message;
          message.setText("You need to choose one of the hash type");
          int ret = message.exec();

          if(ret == QMessageBox::Ok)
          {
              ui->input_field->setText("");
          }
          return true;
    }
  }
  return false;
}

void calculate_hash(Ui::RealTimeHash* ui)
{
    QString data;
    data = ui->input_field->toPlainText();
    if(data.length() == 0)
    {
        return;
    }
    if(ui->sha_hash_radio_button->isChecked())
    {
        QString hash = hash_calculation(data, QCryptographicHash::Sha512);
        ui->output_field->setText("");
        ui->output_field->setText(hash);

        return;
    }
    else if(ui->md5_hash_radio_button->isChecked())
    {
        QString hash = hash_calculation(data, QCryptographicHash::Md5);
        ui->output_field->setText("");
        ui->output_field->setText(hash);

        return;
    }
    else if(ui->keccak_hash_radio_button->isChecked())
    {
        QString hash = hash_calculation(data, QCryptographicHash::Keccak_512);
        ui->output_field->setText("");
        ui->output_field->setText(hash);

        return;
    }
}

QString hash_calculation(QString data, QCryptographicHash::Algorithm algorithm)
{
    QByteArray ba = data.toUtf8();
    QString hash = QCryptographicHash::hash(ba, algorithm).toHex();

    return hash;
}


