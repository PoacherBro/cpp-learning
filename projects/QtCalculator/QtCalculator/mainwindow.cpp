#include "mainwindow.h"
#include "calculator.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindowClass)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_clearEntryButton_clicked()
{
	QString input = ui->lineEdit->text();
	if (input.length() == 1) {
		ui->lineEdit->setText("0");
	}
	else {
		input = input.left(input.length() - 1);
		ui->lineEdit->setText(input);
	}
}

void MainWindow::on_allClearButton_clicked()
{
	ui->lineEdit->setText("0");
}

void MainWindow::on_oneButton_clicked()
{
	updateLineText("1");
}

void MainWindow::on_twoButton_clicked()
{
	updateLineText("2");
}

void MainWindow::on_threeButton_clicked()
{
	updateLineText("3");
}

void MainWindow::on_fourButton_clicked()
{
	updateLineText("4");
}

void MainWindow::on_fiveButton_clicked()
{
	updateLineText("5");
}

void MainWindow::on_sixButton_clicked()
{
	updateLineText("6");
}

void MainWindow::on_sevenButton_clicked()
{
	updateLineText("7");
}

void MainWindow::on_eightButton_clicked()
{
	updateLineText("8");
}

void MainWindow::on_nineButton_clicked()
{
	updateLineText("9");
}

void MainWindow::on_zeroButton_clicked()
{
	updateLineText("0");
}

void MainWindow::on_pointerButton_clicked()
{
	QString input = ui->lineEdit->text();
	QChar lastChar = input.at(input.length() - 1);

	if (lastChar.isNumber()) {
		input += ".";
		ui->lineEdit->setText(input);
	}
}

void MainWindow::on_powerButton_clicked()
{
	QString input = ui->lineEdit->text();
	QChar lastChar = input.at(input.length() - 1);
	if (lastChar.isNumber()) {
		input += "^";
		ui->lineEdit->setText(input);
	}
}

void MainWindow::on_modButton_clicked()
{
	QString input = ui->lineEdit->text();
	QChar lastChar = input.at(input.length() - 1);
	if (lastChar.isNumber()) {
		input += "%";
		ui->lineEdit->setText(input);
	}
}

void MainWindow::on_addButton_clicked()
{
	QString input = ui->lineEdit->text();
	QChar lastChar = input.at(input.length() - 1);
	if (lastChar.isNumber() || lastChar == ')') {
		input += "+";
		ui->lineEdit->setText(input);
	}

}

void MainWindow::on_subButton_clicked()
{
	QString input = ui->lineEdit->text();
	QChar lastChar = input.at(input.length() - 1);
	if (lastChar.isNumber() || lastChar == ')') {
		input += "-";
		ui->lineEdit->setText(input);
	}
}

void MainWindow::on_mulButton_clicked()
{
	QString input = ui->lineEdit->text();
	QChar lastChar = input.at(input.length() - 1);
	if (lastChar.isNumber() || lastChar == ')') {
		input += "x";
		ui->lineEdit->setText(input);
	}
}

void MainWindow::on_divButton_clicked()
{
	QString input = ui->lineEdit->text();
	QChar lastChar = input.at(input.length() - 1);
	if (lastChar.isNumber() || lastChar == ')') {
		input += "/";
		ui->lineEdit->setText(input);
	}
}

void MainWindow::on_eqButton_clicked()
{
	QString input = ui->lineEdit->text();
	Calculator cal;
	// QString postfixExpr = cal.calculate(input);
}

void MainWindow::on_leftBracketButton_clicked()
{
	QString input = ui->lineEdit->text();
	if (input == "0") {
		ui->lineEdit->setText("(");
	}
	else {
		QChar lastChar = input.at(input.length() - 1);
		if (!lastChar.isNumber() && '.' != lastChar && '(' != lastChar && ')' != lastChar) {
			input += "(";
			ui->lineEdit->setText(input);
		}
	}
}

void MainWindow::on_rightBracketButton_clicked()
{
	QString input = ui->lineEdit->text();
	if (input == "0") {
		ui->lineEdit->setText("0");
	}
	else {
		QChar lastChar = input.at(input.length() - 1);
		if (lastChar.isNumber()) {
			input += ")";
			ui->lineEdit->setText(input);
		}
	}
}

void MainWindow::updateLineText(QString input)
{
	QString lineText = ui->lineEdit->text();
	if (lineText == "0") {
		lineText = input;
	}
	else {
		lineText += input;
	}
	ui->lineEdit->setText(lineText);
}
