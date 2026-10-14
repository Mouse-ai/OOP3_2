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
    bEdit = new QLineEdit(this);
    bSpinBox = new QSpinBox(this);
    bSlider = new QSlider(Qt::Horizontal, this);
    connect(bEdit, &QLineEdit::editingFinished,
        [this]()
        {
            bool ok;

            int value = bEdit->text().toInt(&ok);

            if (ok)
            {
                model.setB(value);
                if (value != model.getB())
                {
                    bEdit->setText(QString::number(model.getB()));
                }
            }
            else
            {
                updateView();
            }
        });
    connect(bSpinBox, &QSpinBox::valueChanged,
        [this](int value)
        {
            model.setB(value);

            if (bSpinBox->value() != model.getB())
            {
                bSpinBox->setValue(model.getB());
            }
        });
    connect(bSlider, &QSlider::valueChanged,
        [this](int value)
        {
            model.setB(value);

            if (bSlider->value() != model.getB())
            {
                bSlider->setValue(model.getB());
            }
        });
    bSpinBox->setRange(model.getMinValue(), model.getMaxValue());
    bSlider->setRange(model.getMinValue(), model.getMaxValue());
    QHBoxLayout *bLayout = new QHBoxLayout();

    bLayout->addWidget(new QLabel("B:", this));
    bLayout->addWidget(bEdit);
    bLayout->addWidget(bSpinBox);
    bLayout->addWidget(bSlider);

    cEdit = new QLineEdit(this);
    cSpinBox = new QSpinBox(this);
    cSlider = new QSlider(Qt::Horizontal, this);

    connect(cEdit, &QLineEdit::editingFinished,
        [this]()
        {
            bool ok;

            int value = cEdit->text().toInt(&ok);

            if (ok)
            {
                model.setC(value);
            }
            else
            {
                updateView();
            }
        });
    connect(cSpinBox, &QSpinBox::valueChanged,
        [this](int value)
        {
            model.setC(value);

        });

    connect(cSlider, &QSlider::valueChanged,
        [this](int value)
        {
            model.setC(value);

        });
    cSpinBox->setRange(model.getMinValue(), model.getMaxValue());
    cSlider->setRange(model.getMinValue(), model.getMaxValue());
    QHBoxLayout *cLayout = new QHBoxLayout();

    cLayout->addWidget(new QLabel("C:", this));
    cLayout->addWidget(cEdit);
    cLayout->addWidget(cSpinBox);
    cLayout->addWidget(cSlider);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(aLayout);
    mainLayout->addLayout(bLayout);
    mainLayout->addLayout(cLayout);


    model.connectChanged([this]()
   {
       updateView();
   });

    model.initialize();

    resize(600, 150);
}
void MainWindow::updateView()
{
    aEdit->setText(QString::number(model.getA()));
    aSpinBox->setValue(model.getA());
    aSlider->setValue(model.getA());

    bEdit->setText(QString::number(model.getB()));
    bSpinBox->setValue(model.getB());
    bSlider->setValue(model.getB());

    cEdit->setText(QString::number(model.getC()));
    cSpinBox->setValue(model.getC());
    cSlider->setValue(model.getC());
}