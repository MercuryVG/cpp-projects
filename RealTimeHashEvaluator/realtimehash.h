#ifndef REALTIMEHASH_H
#define REALTIMEHASH_H

#include <QMainWindow>
#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QTextCursor>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QClipboard>




QT_BEGIN_NAMESPACE
namespace Ui { class RealTimeHash; }

class RealTimeHash : public QMainWindow
QT_END_NAMESPACE
{
    Q_OBJECT

public:
    RealTimeHash(QWidget *parent = nullptr);
    ~RealTimeHash();

private slots:
    void on_exit_button_clicked();

    void on_clear_button_clicked();

protected:
    bool eventFilter(QObject *target, QEvent *event) override;

private:
    Ui::RealTimeHash *ui;
};
#endif // REALTIMEHASH_H
