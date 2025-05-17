#pragma once

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include "ui_TestMain.h"

#include <adecc_Scholar/MyForm.h>
#include <Persistence/person_reader.h>

#include <functional>

class TestMain : public QMainWindow
{
    Q_OBJECT

public:
    TestMain(QWidget *parent = nullptr);
    ~TestMain();

private:
    TMyForm frm;
    static std::vector<std::string> inline vecActions = {"btnShow"s, "btnSingleMales"s, "btnFemales"s, "btnShowNames"s };
    Ui::TestMainClass ui;
    QLabel* statusLabel;
    std::function<void(std::string const&, std::string const&, std::string const&)> funcErrMessage = nullptr;

    reader::TPersonReader database;
    reader::DataAccess person_read; 
    myCorporate::TFamilyStatus::container_ty  status;
    myCorporate::TFormOfAddress::container_ty salutation;


    void Init();
    void CheckStatus();
    void Connect();
    void Show();
    void ShowSingleMales();
    void ShowFemales();
    void Action();
    void ShowNames();
    void Error();

    bool Display4List1(std::ostream& out, myCorporate::TPerson const& person);
    bool Display4List2(std::ostream& out, myCorporate::TPerson && person);
};
