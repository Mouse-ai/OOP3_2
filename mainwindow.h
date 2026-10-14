#ifndef OOP3_2_MAINWINDOW_H
#define OOP3_2_MAINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QSlider>
#include <iostream>
#include "model.h"

class MainWindow : public QWidget {
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    Model model;

    QLineEdit *aEdit;
    QSpinBox *aSpinBox;
    QSlider *aSlider;
    QLineEdit *bEdit;
    QSpinBox *bSpinBox;
    QSlider *bSlider;

    QLineEdit *cEdit;
    QSpinBox *cSpinBox;
    QSlider *cSlider;
    void updateView();
    int updateCount = 0;
};


#endif