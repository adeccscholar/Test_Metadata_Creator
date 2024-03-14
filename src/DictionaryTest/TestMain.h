#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestMain.h"

class TestMain : public QMainWindow
{
    Q_OBJECT

public:
    TestMain(QWidget *parent = nullptr);
    ~TestMain();

private:
    Ui::TestMainClass ui;
};
