#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_clearEntryButton_clicked();

    void on_allClearButton_clicked();

    void on_oneButton_clicked();

    void on_twoButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_zeroButton_clicked();

    void on_pointerButton_clicked();

    void on_powerButton_clicked();

    void on_modButton_clicked();

    void on_addButton_clicked();

    void on_subButton_clicked();

    void on_mulButton_clicked();

    void on_divButton_clicked();

    void on_eqButton_clicked();

    void on_leftBracketButton_clicked();

    void on_rightBracketButton_clicked();

private:
    Ui::MainWindow *ui;

    void updateLineText(QString input);
};

#endif // MAINWINDOW_H
