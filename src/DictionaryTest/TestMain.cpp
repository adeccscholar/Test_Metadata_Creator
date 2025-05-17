#include "TestMain.h"

#include "MyFileDlg.h"

#include <adecc_Scholar/MyStream.h>
#include <adecc_Database/MyDatabaseExceptions.h>
#include <Base/BaseDefinitions.h>

#include <algorithm>
#include <iterator>
#include <functional>

struct TMyNum : public std::numpunct<char> {
   char_type   do_decimal_point() const { return ','; }
   char_type   do_thousands_sep() const { return '.'; }
   string_type do_truename()      const { return "ja"; }
   string_type do_falsename()     const { return "nein"; }
   std::string do_grouping()      const { return "\3"; }
   };

TMyNum newNumPunct;
std::locale myLoc;

using myWrapper = TStreamWrapper<Narrow>;
using myCaption = tplList<Narrow>;

myWrapper old_cout{ std::cout };
myWrapper old_cerr{ std::cerr };
myWrapper old_clog{ std::clog };

std::vector<std::tuple<std::vector<myCaption>, std::function<bool(myCorporate::TPerson const&)>>> person_lists;

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

std::vector<myCaption> name_list = {
   myCaption{ "fullname",      210, EMyAlignmentType::left }
};


TestMain::TestMain(QWidget *parent) : QMainWindow(parent), person_read(database.GetDatabase())
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

    connect(ui.btnConnect,     &QPushButton::clicked,            this, [this]() { Connect(); });
    connect(ui.btnShow,        &QPushButton::clicked,            this, [this]() { Show(); });
    connect(ui.btnSingleMales, &QPushButton::clicked,            this, [this]() { ShowSingleMales(); });
    connect(ui.btnFemales,     &QPushButton::clicked,            this, [this]() { ShowFemales(); });
    connect(ui.btnShowNames,   &QPushButton::clicked,            this, [this]() { ShowNames(); });
    connect(ui.btnError,       &QPushButton::clicked,            this, [this]() { Error(); });
    connect(ui.tblOutput,      &QTableWidget::itemDoubleClicked, this, [this](QTableWidgetItem*) { Action();   });

    Init();
   }

TestMain::~TestMain()
{}

void TestMain::Init() {
   frm.Set( this, false );

   std::ios_base::sync_with_stdio(false);
   myLoc = std::locale(std::locale("de_DE"), &newNumPunct);
   std::locale::global(myLoc);

   frm.GetAsStream<Narrow, EMyFrameworkType::listview>(old_cout, "tblOutput"s, captions);
   frm.GetAsStream<Narrow, EMyFrameworkType::memo>(old_cerr, "txtError"s);
   frm.GetAsStream<Narrow, EMyFrameworkType::statusbar>(old_clog, "sbMain"s);

   frm.Set<EMyFrameworkType::button, std::string>("btnConnect"s,     "login"s);
   frm.Set<EMyFrameworkType::button, std::string>("btnShow"s,        "show persons"s);
   frm.Set<EMyFrameworkType::button, std::string>("btnSingleMales"s, "show single males"s);
   frm.Set<EMyFrameworkType::button, std::string>("btnFemales"s,     "show all females"s);
   frm.Set<EMyFrameworkType::button, std::string>("btnShowNames"s,   "show name list"s);
   frm.Set<EMyFrameworkType::button, std::string>("btnError"s,       "create error"s);

   for (auto& s : { &std::cout, &std::cerr, &std::clog }) {
      s->imbue(myLoc);
      s->setf(std::ios::fixed);
      }

   CheckStatus();

   std::clog << "Ready.\n";
   }

void TestMain::CheckStatus() {
   bool boConnected = database.IsConnectedToDatabase();
   frm.Set<EMyFrameworkType::button, std::string>("btnConnect"s, boConnected ? "disconnect from database"s : "login into database"s);
   std::ranges::for_each(vecActions, [this, boConnected](auto const& val) { frm.Enable<EMyFrameworkType::button>(val, boConnected); });
   }

void TestMain::Connect() {
   if(!database.IsConnectedToDatabase()) {
      auto [boLogin, strUser, strPwd, boIntegrated] = 
              TMyFileDlg::UserLoginDlg(database.GetDatabaseInformations(), true, { "volkerh" }, false);
      if (boLogin) {
         auto [boSuccess, strMessage] = database.LoginToDb(TMyCredential{ strUser.value_or(""), strPwd.value_or(""), boIntegrated.value_or(false) });
         if (boSuccess) {
            TMyFileDlg::Message(EMyMessageType::information, "application Simple Person Management",
                                std::format("You connected successfully to the database {}", database.GetDatabaseInformations()));
            status     = std::move(person_read.Read<myCorporate::TFamilyStatus::container_ty>());
            salutation = std::move(person_read.Read<myCorporate::TFormOfAddress::container_ty>());

            std::clog << "connected to : " << database.GetDatabaseInformations() << '\n';
            }
         else {
            if (strPwd) 
               if (size_t pos = strMessage.rfind(*strPwd); pos != std::string::npos) 
                  strMessage.replace(pos, (*strPwd).length(), "*****");
            TMyFileDlg::Message(EMyMessageType::error, "application Simple Person Management", "Error while login to database", strMessage);
            std::clog << "error while connecting to database: " << database.GetDatabaseInformations() << '\n';
            }
         }
      else std::clog << "not connected.\n";
      }
   else {
      database.LogoutFromDb();
      status.clear();
      salutation.clear();
      frm.GetAsStream<Narrow, EMyFrameworkType::listview>(old_cout, "tblOutput", captions, true);
      }
   CheckStatus();
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


bool TestMain::Display4List2(std::ostream& out, myCorporate::TPerson && person) {
   return Display4List1(out, static_cast<myCorporate::TPerson const&>(person));
   }

bool TestMain::Display4List1(std::ostream& out, myCorporate::TPerson const& person) {
   out << person.ID().value_or(0) << '\t'
       << lookup(salutation, person.FormOfAddress()) << '\t'
       << person.Name().value_or("") << '\t'
       << person.FirstName().value_or("") << '\t'
       << person.FullName().value_or("") << '\t'
       << toText(person.Birthday()) << '\t'
       << lookup(status, person.FamilyStatus()) << '\t'
       << toText(person.FamilyStatusSince())
       << '\n';
   return true;
   }

void TestMain::Show() {
   try {
      if(database.IsConnectedToDatabase()) {
         TMyWait wait;
         frm.GetAsStream<Narrow, EMyFrameworkType::listview>(old_cout, "tblOutput", captions, true);
         frm.EnableUpdates<EMyFrameworkType::listview>("tblOutput", false);
         //auto data       = person_read.Read<myCorporate::TPerson::container_ty>();
         auto data       = person_read.Read<myCorporate::TPerson::vector_ty>();

         std::ranges::sort(data, [](auto const& lhs, auto const& rhs) {
                                if(auto ret = lhs.Name() <=> rhs.Name(); ret < 0) return true;
                                else if(ret > 0) return false;
                                if (auto ret = lhs.FirstName() <=> rhs.FirstName(); ret < 0) return true;
                                else if (ret > 0) return false;
                                return false;
                               });

         //std::ranges::for_each(data | own::views::second, [this](auto const& person) {
         std::ranges::for_each(data, std::bind(&TestMain::Display4List1, this, std::ref(std::cout), std::placeholders::_1));
         frm.EnableUpdates<EMyFrameworkType::listview>("tblOutput", true);
         std::clog << "show all persons: " << data.size() <<  " elements\n";
         }
      }
   catch(TMy_Db_Exception& ex) {
      TMyFileDlg::Message(EMyMessageType::error, "application Simple Person Management", "Error while reading person data", ex.information());
      }
   catch(std::exception& ex) {
      TMyFileDlg::Message(EMyMessageType::error, "application Simple Person Management", "Error while reading person data", ex.what());
      }
   }

void TestMain::ShowSingleMales() {
   TMyForm frm{ this, false };
   try {
      if(database.IsConnectedToDatabase()) {
         TMyWait wait;
         frm.GetAsStream<Narrow, EMyFrameworkType::listview>(old_cout, "tblOutput", captions, true);
         frm.EnableUpdates<EMyFrameworkType::listview>("tblOutput", false);
         
         auto data = person_read.Read<myCorporate::TPerson::vector_ty>("SELECT *\n"s +
                                                                       "FROM Person\n"s + 
                                                                       "WHERE FormOfAddress = :FoA AND FamilyStatus = :FamSt"s,
                                                                      { {"FoA", 1, true }, { "FamSt", 1, true } } );

         for(auto const& person : data) {
            Display4List1(std::cout, person);
            }
         frm.EnableUpdates<EMyFrameworkType::listview>("tblOutput", true);
         std::clog << "show all single males: " << data.size() <<  " elements\n";
         }
      }
   catch(TMy_Db_Exception& ex) {
      TMyFileDlg::Message(EMyMessageType::error, "application Simple Person Management", "Error while reading person data", ex.information());
      }
   catch(std::exception& ex) {
      TMyFileDlg::Message(EMyMessageType::error, "application Simple Person Management", "Error while reading person data", ex.what());
      }
   }

void TestMain::ShowFemales() {
   TMyForm frm{ this, false };
   try {
      if (database.IsConnectedToDatabase()) {
         TMyWait wait;
         frm.GetAsStream<Narrow, EMyFrameworkType::listview>(old_cout, "tblOutput", captions, true);
         frm.EnableUpdates<EMyFrameworkType::listview>("tblOutput", false);

         /*
         auto displ_func = [this](auto&& person) -> bool {
            std::cout << person.ID().value_or(0) << '\t'
                      << lookup(salutation, person.FormOfAddress()) << '\t'
                      << person.Name().value_or("") << '\t'
                      << person.Firstname().value_or("") << '\t'
                      << person.FullName().value_or("") << '\t'
                      << toText(person.Birthday()) << '\t'
                      << lookup(status, person.FamilyStatus()) << '\t'
                      << toText(person.FamilyStatusSince())
                      << '\n';
            return true;
            };
            */

         person_read.Process<myCorporate::TPerson>(std::bind(&TestMain::Display4List2, this, std::ref(std::cout), std::placeholders::_1),
                                                   "SELECT *\n"s +
                                                   "FROM Person\n"s +
                                                   "WHERE FormOfAddress = :FoA"s,
                                                   { {"FoA", 2, true } });
         frm.EnableUpdates<EMyFrameworkType::listview>("tblOutput", true);
         std::clog << "show all females:\n";
         }
      }
   catch (TMy_Db_Exception& ex) {
      TMyFileDlg::Message(EMyMessageType::error, "application Simple Person Management", "Error while reading person data", ex.information());
      }
   catch (std::exception& ex) {
      TMyFileDlg::Message(EMyMessageType::error, "application Simple Person Management", "Error while reading person data", ex.what());
      }
   }

void TestMain::Action() {
   TMyForm frm{ this, false };
   try {
      auto rows = frm.GetSelectedRows<EMyFrameworkType::listview>("tblOutput");
      if (rows.size() > 0) {
         std::optional<int> id = frm.GetValue<EMyFrameworkType::listview, int>("tblOutput", rows[0], 0);
         if(id) {
             auto person = person_read.Read<myCorporate::TPerson>(*id);
             auto address = person_read.Read<myCorporate::TAddress>(myCorporate::TAddress::primary_key(*id, 1));
             std::ostringstream os;
             os << (*person).FullName().value_or("") << '\n'  // (*person).Firstname().value_or("") << ' ' << (*person).Name().value_or("") <<  '\n'
                << address->Zipcode().value_or("") << ' ' << address->City().value_or("") << '\n'
                << address->Street().value_or("") << ' ' << address->StreetNumber().value_or("");
             TMyFileDlg::Message(EMyMessageType::information, "simple person management", os.str());
            }
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

void TestMain::ShowNames() {
   try {
      using iter_ty = my_formlist_iterator<EMyFrameworkType::listview, std::string>;
      std::vector<std::string> vecNames;
      std::copy(iter_ty(&frm, "tblOutput", 4), iter_ty{}, std::back_inserter(vecNames));
      std::ranges::sort(vecNames);
      frm.GetAsStream<Narrow, EMyFrameworkType::listview>(old_cout, "tblOutput", name_list, true);
      frm.EnableUpdates<EMyFrameworkType::listview>("tblOutput", false);
      std::copy(vecNames.begin(), vecNames.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
      frm.EnableUpdates<EMyFrameworkType::listview>("tblOutput", true);
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

void TestMain::Error() {
   try {
      auto person = person_read.Read<myCorporate::TPerson>(5000);
      if (!person) throw std::runtime_error("not found");
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
