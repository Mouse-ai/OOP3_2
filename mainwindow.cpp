//
// Created by alexei on 14.10.2026.
//

#include "mainwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    aEdit = new QLineEdit(this);
    connect(aEdit, &QLineEdit::editingFinished,
        [this]()
        {
            bool ok;

            int value = aEdit->text().toInt(&ok);

            if (ok)
            {
                model.setA(value);
            }
            else
            {
                updateView();
            }
        });
    aSpinBox = new QSpinBox(this);
    connect(aSpinBox, &QSpinBox::valueChanged,
        [this](int value)
        {
            model.setA(value);
        });

    aSlider = new QSlider(Qt::Horizontal, this);
    connect(aSlider, &QSlider::valueChanged,
        [this](int value)
        {
            model.setA(value);
        });

    aSpinBox->setRange(model.getMinValue(), model.getMaxValue());
    aSlider->setRange(model.getMinValue(), model.getMaxValue());
    QHBoxLayout *aLayout = new QHBoxLayout();

    aLayout->addWidget(new QLabel("A:", this));
    aLayout->addWidget(aEdit);
    aLayout->addWidget(aSpinBox);
    aLayout->addWidget(aSlider);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(aLayout);

    model.connectChanged([this]()
   {
       updateView();
   });

    updateView();

    resize(600, 150);
}
void MainWindow::updateView()
{
    aEdit->setText(QString::number(model.getA()));
    aSpinBox->setValue(model.getA());
    aSlider->setValue(model.getA());
}