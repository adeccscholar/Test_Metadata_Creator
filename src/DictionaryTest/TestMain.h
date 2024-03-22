#pragma once

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include "ui_TestMain.h"

#include <Persistence\person_reader.h>

#include <functional>

class TestMain : public QMainWindow
{
    Q_OBJECT

public:
    TestMain(QWidget *parent = nullptr);
    ~TestMain();

private:
    Ui::TestMainClass ui;
    QLabel* statusLabel;
    std::function<void(std::string const&, std::string const&, std::string const&)> funcErrMessage = nullptr;

    reader::TPersonReader database;

    void Init();
    void Connect();
    void Show();
    void Action();
};
