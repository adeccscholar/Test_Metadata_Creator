#include "TestMain.h"

#include "MyFileDlg.h"

#include <adecc_Scholar/MyForm.h>
#include <adecc_Scholar/MyStream.h>
#include <adecc_Database/MyDatabaseExceptions.h>

struct TMyNum : public std::numpunct<char> {
   char_type   do_decimal_point() const { return ','; }
   char_type   do_thousands_sep() const { return '.'; }
   string_type do_truename()      const { return "ja"; }
   string_type do_falsename()     const { return "nein"; }
   std::string do_grouping()      const { return "\3"; }
   };

TMyNum newNumPunct;
std::locale myLoc;

using myCaption = tplList<Narrow>;

TStreamWrapper<Narrow> old_cout{ std::cout };
TStreamWrapper<Narrow> old_cerr{ std::cerr };
TStreamWrapper<Narrow> old_clog{ std::clog };

std::vector<myCaption> captions = {
   myCaption{ "id",             60, EMyAlignmentType::right },
   myCaption{ "salutation",    100, EMyAlignmentType::left },
   myCaption{ "name",          140, EMyAlignmentType::left },
   myCaption{ "firstname",     140, EMyAlignmentType::left },
   myCaption{ "fullname",      210, EMyAlignmentType::left },
   myCaption{ "birthday",      100, EMyAlignmentType::center },
   myCaption{ "family status", 130, EMyAlignmentType::left },
   myCaption{ "status date",   100, EMyAlignmentType::center }
   };


TestMain::TestMain(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.statusBar->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
    statusLabel = new QLabel(this);
    statusLabel->setObjectName("sbMain");
    statusLabel->setText("sbMain");
    ui.statusBar->addPermanentWidget(statusLabel);

    ui.tblOutput->setAlternatingRowColors(true);
    ui.tblOutput->setStyleSheet("alternate-background-color: lightgray;selection-background-color: red;");

    QHeaderView* header = ui.tblOutput->verticalHeader();
    header->setDefaultSectionSize(12); // 20 px height
    header->sectionResizeMode(QHeaderView::Fixed);

    connect(ui.btnConnect, &QPushButton::clicked,            this, [this]() { Connect(); });
    connect(ui.btnShow,    &QPushButton::clicked,            this, [this]() { Show(); });
    connect(ui.tblOutput,  &QTableWidget::itemDoubleClicked, this, [this](QTableWidgetItem*) { Action();   });

    Init();
   }

TestMain::~TestMain()
{}

void TestMain::Init() {
   TMyForm frm{ this, false };

   std::ios_base::sync_with_stdio(false);
   myLoc = std::locale(std::locale("de_DE"), &newNumPunct);
   std::locale::global(myLoc);

   frm.GetAsStream<Narrow, EMyFrameworkType::listview>(old_cout, "tblOutput", captions);
   frm.GetAsStream<Narrow, EMyFrameworkType::memo>(old_cerr, "txtError");
   frm.GetAsStream<Narrow, EMyFrameworkType::statusbar>(old_clog, "sbMain");

   frm.Set<EMyFrameworkType::button, std::string>("btnConnect", "login");
   frm.Set<EMyFrameworkType::button, std::string>("btnShow",    "show persons");

   for (auto& s : { &std::cout, &std::cerr, &std::clog }) {
      s->imbue(myLoc);
      s->setf(std::ios::fixed);
      }

   std::clog << "Ready.\n";
   }

void TestMain::Connect() {

   auto [boLogin, strUser, strPwd, boIntegrated] = TMyFileDlg::UserLoginDlg(database.GetDatabaseInformations(), true, { "volkerh" }, false);
   if (boLogin) {
      auto [boSuccess, strMessage] = database.LoginToDb(TMyCredential{ strUser.value_or(""), strPwd.value_or(""), boIntegrated.value_or(false) });
      if(boSuccess) std::clog << "connected to : " << database.GetDatabaseInformations() << '\n';
      else {
         if (strPwd) 
            if (size_t pos = strMessage.rfind(*strPwd); pos != std::string::npos) strMessage.replace(pos, (*strPwd).length(), "*****");
         TMyFileDlg::Message(EMyMessageType::error, "application Simple Person Management", "Error while login to database", strMessage);
         std::clog << "error while connecting to database: " << database.GetDatabaseInformations() << '\n';
         }
      }
   else std::clog << "not connected.\n";
   }

std::ostream& operator<<(std::ostream& out, const std::chrono::year_month_day& ymd) {
   out << std::setw(2) << std::setfill('0') << ymd.day()
       << '.' << std::setw(2) << std::setfill('0') << static_cast<unsigned>(ymd.month())
       << '.' << ymd.year();
   return out;
   }

template <typename ty>
std::string lookup(ty const& container, std::optional<int> const& value) {
   if (!value) [[unlikely]] return ""s;
   else {
      auto it = container.find(typename ty::mapped_type::primary_key(*value));
      if (it == container.end()) throw std::runtime_error("broken data.");
      else return it->second.Denotation().value_or("");
      }
   }

template <typename ty>
std::string toText(std::optional<ty> const& value) {
   if (!value) return ""s;
   else {
      std::ostringstream os;
      os << *value;
      return os.str();
      }
   }

void TestMain::Show() {
   try {
      if(database.IsConnectedToDatabase()) {
         TMyWait wait;
         myCorporate::TPerson::container_ty data;
         myCorporate::TFamilyStatus::container_ty status;
         myCorporate::TFormOfAddress::container_ty salutation;
         database.Read(status);
         database.Read(salutation);
         database.Read(data);

         std::ranges::for_each(data, [&status, &salutation](auto const& value) {
              auto const& [_, person] = value;

              std::cout << *std::get<1>(value).ID() << '\t'
                        << lookup(salutation, person.FormOfAddress()) << '\t'
                        << person.Name().value_or("") << '\t'
                        << person.Firstname().value_or("") << '\t'
                        << person.FullName().value_or("") << '\t'
                        << toText(person.Birthday()) << '\t'
                        << lookup(status, person.FamilyStatus()) << '\t'
                        << toText(person.FamilyStatusSince())
                        << '\n';
              });
         std::clog << "show data: " << data.size() <<  " elements\n";
         }
      }
   catch(TMy_Db_Exception& ex) {
      std::cerr << "error while reading all persons:\n"
                << ex.information() << '\n';
      }
   catch(std::exception& ex) {
      std::cerr << "error while reading all persons:\n"
                << ex.what() << '\n';
      }
   }

void TestMain::Action() {
   TMyForm frm{ this, false };
   try {
      auto rows = frm.GetSelectedRows<EMyFrameworkType::listview>("tblOutput");
      if (rows.size() > 0) {
         std::optional<int> id = frm.GetValue<EMyFrameworkType::listview, int>("tblOutput", rows[0], 0);
         myCorporate::TPerson person;
         myCorporate::TAddress address;
         database.Read(myCorporate::TPerson::primary_key(*id), person);
         database.Read(myCorporate::TAddress::primary_key(*id, 1), address);
         std::ostringstream os;
         os << person.FullName().value_or("") << '\n'
            << address.Zipcode().value_or("") << ' ' << address.City().value_or("") << '\n'
            << address.Street().value_or("") << ' ' << address.StreetNumber().value_or("");
         frm.Message(EMyMessageType::information, "test outbout", os.str());
         }
      }
   catch (TMy_Db_Exception& ex) {
      std::cerr << "error while reading a person and address:\n"
                << ex.information() << '\n';
      }
   catch (std::exception& ex) {
      std::cerr << "error while reading all person and address:\n"
                << ex.what() << '\n';
      }
   }
