#include "widget.h"
#include "ui_widget.h"
#include <QDebug> // 添加头文件
#include <QStack>
#include <QChar>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setMaximumSize(280,380);
    this->setMinimumSize(280,380);
    this->setWindowTitle("计算机");
    //改变按钮背景颜色

}

Widget::~Widget()
{
    delete ui;
}
//一下都是输入字
void Widget::on_oneButton_clicked()
{
    expression += "1"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_twoButton_clicked()
{
    expression += "2"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_threeButton_clicked()
{
    expression += "3"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_fourButton_clicked()
{
    expression += "4"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_fiveButton_clicked()
{
    expression += "5"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_sixButton_clicked()
{
    expression += "6"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_sevenButton_clicked()
{
    expression += "7"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_eightButton_clicked()
{
    expression += "8"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_nineButton_clicked()
{
    expression += "9"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_zeroButton_clicked()
{
    expression += "0"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_jiaButton_clicked()
{
    qDebug() << "jiaButton clicked!"; // 调试信息
    expression += "+"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_jianButton_clicked()
{
    expression += "-"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_chengButton_clicked()
{
    expression += "*"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_dianButton_clicked()
{
    expression += "."; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}
void Widget::on_chuButton_clicked()
{
    expression += "/"; // 添加字符 "1"
    ui->lineEdit->setText(expression); // 更新 lineEdit 的文本
}

void Widget::on_wei0_clicked()
{
    expression.clear();
    ui->lineEdit->clear();
}


void Widget::on_delete_2_clicked()
{
    expression.chop(1);
    ui->lineEdit->setText(expression);
}

double Widget::evaluateExpression(const QString &expr)
{
    QStack<double> numbers; // 存储数字
    QStack<QChar> operators; // 存储运算符

    for (int i = 0; i < expr.length(); ++i) {
        QChar ch = expr[i];

        if (ch.isDigit() || ch == '.') {
            // 处理数字
            QString numStr;
            while (i < expr.length() && (expr[i].isDigit() || expr[i] == '.')) {
                numStr += expr[i];
                ++i;
            }
            --i; // 回退一个字符
            numbers.push(numStr.toDouble());
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // 处理运算符
            while (!operators.isEmpty() && precedence(operators.top()) >= precedence(ch)) {
                applyOperation(numbers, operators.pop());
            }
            operators.push(ch);
        }
    }

    // 处理剩余的运算符
    while (!operators.isEmpty()) {
        applyOperation(numbers, operators.pop());
    }

    // 返回最终结果
    return numbers.isEmpty() ? 0 : numbers.pop();
}

int Widget::precedence(QChar op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void Widget::applyOperation(QStack<double> &numbers, QChar op)
{
    if (numbers.size() < 2) return;

    double b = numbers.pop();
    double a = numbers.pop();

    switch (op.toLatin1()) {
    case '+': numbers.push(a + b); break;
    case '-': numbers.push(a - b); break;
    case '*': numbers.push(a * b); break;
    case '/': numbers.push(a / b); break;
    }
}
void Widget::on_deng_clicked()
{
    try {
        double result = evaluateExpression(expression);
        QString resultStr = QString::number(result);
        ui->lineEdit->setText(resultStr);
        expression = resultStr;
    } catch (...) {
        ui->lineEdit->setText("Error");
    }
}
