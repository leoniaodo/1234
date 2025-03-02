#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_zeroButton_clicked();
    void on_oneButton_clicked(); // 声明槽函数
    void on_twoButton_clicked();
    void on_threeButton_clicked();
    void on_fourButton_clicked();
    void on_fiveButton_clicked();
    void on_sixButton_clicked();
    void on_sevenButton_clicked();
    void on_eightButton_clicked();
    void on_nineButton_clicked();
    void on_jiaButton_clicked();
    void on_jianButton_clicked();
    void on_chengButton_clicked();
    void on_dianButton_clicked();
    void on_chuButton_clicked();
    void on_wei0_clicked();
    void on_delete_2_clicked();
    void on_deng_clicked();

private:
    Ui::Widget *ui;
    QString expression; // 用于存储表达式的字符串

private:
    double evaluateExpression(const QString &expr);
    int precedence(QChar op);
    void applyOperation(QStack<double> &numbers, QChar op);
};

#endif // WIDGET_H
