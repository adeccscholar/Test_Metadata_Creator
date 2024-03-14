/*
* Project: model with a simple person administration
* Definition of the persistence class TPersonReader
* Date: 14.03.2024 23:56:54,483  file created with adecc Scholar metadata generator
* copyright (c) adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include <Persistence\person_reader_sql.h>
#include <Persistence\person_reader.h>

#include <System\Corporate\Address.h>
#include <System\Corporate\AddressTypes.h>
#include <System\Corporate\Banking.h>
#include <System\Corporate\BankingTypes.h>
#include <System\Corporate\Countries.h>
#include <System\HR\Departments.h>
#include <System\HR\Employees.h>
#include <System\Corporate\FamilyStatus.h>
#include <System\Corporate\FamilyTypes.h>
#include <System\Corporate\FormOfAddress.h>
#include <System\Corporate\Internet.h>
#include <System\Corporate\InternetTypes.h>
#include <System\HR\JobPositions.h>
#include <System\Corporate\Person.h>
#include <System\Corporate\Phone.h>
#include <System\Corporate\PhonesTypes.h>
#include <System\HR\ReasonDeparture.h>
#include <System\HR\ReasonNonWorking.h>
#include <System\HR\SalaryBase.h>
#include <System\HR\SalaryType.h>
#include <System\HR\TaxClasses.h>
#include <System\HR\WD_Holidays.h>
#include <System\HR\WD_Months.h>
#include <System\HR\WD_NonWorking.h>
#include <System\HR\WD_Weekdays.h>
#include <System\HR\WD_Workdays.h>
#include <System\HR\WorkingTime.h>

namespace reader {

TPersonReader::TPersonReader() : database { TMyMSSQL { "Test_Personen" } } { }

std::pair<std::string, std::string> TPersonReader::GetConnectionInformations(void) const {
   return { database.GetDatabase(), database.ServerType() };
   }

std::string TPersonReader::GetDatabaseInformations(void) const {
   return database.GetInformations();
   }

std::pair<bool, std::string> TPersonReader::LoginToDb(TMyCredential && credentials) {
   try {
      database += std::move(credentials);
      database.Open();
      return { true, database.GetInformations() };
      }
   catch (TMy_Db_Exception& ex) {
      return { false, "error while login to database\n"s + ex.information() };
      }
   catch (std::exception& ex) {
      return { false, "error while login to database\n"s + ex.what() };
      }
   }

void TPersonReader::LogoutFromDb() {
   database.Close();
   }

// access methods for class TAddress
bool TPersonReader::Read(myCorporate::TAddress::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLAddressAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TAddress element;
      element.ID(query.Get<int>("ID", true));
      element.AddressType(query.Get<int>("AddressType", true));
      element.Zipcode(query.Get<std::string>("Zipcode"));
      element.City(query.Get<std::string>("City"));
      element.Street(query.Get<std::string>("Street"));
      element.StreetNumber(query.Get<std::string>("StreetNumber"));
      element.Country(query.Get<int>("Country"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TAddress::primary_key const& key_val, myCorporate::TAddress& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLAddressDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyAddressType", key_val.AddressType());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.AddressType(query.Get<int>("AddressType", true));
      data.Zipcode(query.Get<std::string>("Zipcode"));
      data.City(query.Get<std::string>("City"));
      data.Street(query.Get<std::string>("Street"));
      data.StreetNumber(query.Get<std::string>("StreetNumber"));
      data.Country(query.Get<int>("Country"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TAddressTypes
bool TPersonReader::Read(myCorporate::TAddressTypes::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLAddressTypesAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TAddressTypes element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.Notes(query.Get<std::string>("Notes"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TAddressTypes::primary_key const& key_val, myCorporate::TAddressTypes& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLAddressTypesDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TBanking
bool TPersonReader::Read(myCorporate::TBanking::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLBankingAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TBanking element;
      element.ID(query.Get<int>("ID", true));
      element.BankingType(query.Get<int>("BankingType", true));
      element.BankName(query.Get<std::string>("BankName"));
      element.IBAN(query.Get<std::string>("IBAN"));
      element.BIC(query.Get<std::string>("BIC"));
      element.BankOwner(query.Get<std::string>("BankOwner"));
      element.Country(query.Get<int>("Country"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TBanking::primary_key const& key_val, myCorporate::TBanking& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLBankingDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyBankingType", key_val.BankingType());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.BankingType(query.Get<int>("BankingType", true));
      data.BankName(query.Get<std::string>("BankName"));
      data.IBAN(query.Get<std::string>("IBAN"));
      data.BIC(query.Get<std::string>("BIC"));
      data.BankOwner(query.Get<std::string>("BankOwner"));
      data.Country(query.Get<int>("Country"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TBankingTypes
bool TPersonReader::Read(myCorporate::TBankingTypes::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLBankingTypesAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TBankingTypes element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.Notes(query.Get<std::string>("Notes"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TBankingTypes::primary_key const& key_val, myCorporate::TBankingTypes& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLBankingTypesDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TCountries
bool TPersonReader::Read(myCorporate::TCountries::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLCountriesAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TCountries element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.CountryDialing(query.Get<std::string>("CountryDialing"));
      element.ISO_Code(query.Get<std::string>("ISO_Code"));
      element.IsEU(query.Get<bool>("IsEU"));
      element.Capital(query.Get<std::string>("Capital"));
      element.Currency(query.Get<std::string>("Currency"));
      element.Notes(query.Get<std::string>("Notes"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TCountries::primary_key const& key_val, myCorporate::TCountries& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLCountriesDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.CountryDialing(query.Get<std::string>("CountryDialing"));
      data.ISO_Code(query.Get<std::string>("ISO_Code"));
      data.IsEU(query.Get<bool>("IsEU"));
      data.Capital(query.Get<std::string>("Capital"));
      data.Currency(query.Get<std::string>("Currency"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TDepartments
bool TPersonReader::Read(myHR::TDepartments::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLDepartmentsAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TDepartments element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.Officer(query.Get<int>("Officer"));
      element.Notes(query.Get<std::string>("Notes"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TDepartments::primary_key const& key_val, myHR::TDepartments& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLDepartmentsDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Officer(query.Get<int>("Officer"));
      data.Notes(query.Get<std::string>("Notes"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TEmployees
bool TPersonReader::Read(myHR::TEmployees::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLEmployeesAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TEmployees element;
      element.ID(query.Get<int>("ID", true));
      element.PersonNumber(query.Get<std::string>("PersonNumber"));
      element.Salary(query.Get<double>("Salary"));
      element.SalaryType(query.Get<int>("SalaryType"));
      element.TaxClass(query.Get<int>("TaxClass"));
      element.StartOfJob(query.Get<std::chrono::year_month_day>("StartOfJob"));
      element.EndOfJob(query.Get<std::chrono::year_month_day>("EndOfJob"));
      element.ReasonDeparture(query.Get<int>("ReasonDeparture"));
      element.JobPosition(query.Get<int>("JobPosition"));
      element.JobSpec(query.Get<std::string>("JobSpec"));
      element.VacationDays(query.Get<unsigned int>("VacationDays"));
      element.Department(query.Get<int>("Department"));
      element.SocialNummer(query.Get<std::string>("SocialNummer"));
      element.Active(query.Get<bool>("Active"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TEmployees::primary_key const& key_val, myHR::TEmployees& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLEmployeesDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.PersonNumber(query.Get<std::string>("PersonNumber"));
      data.Salary(query.Get<double>("Salary"));
      data.SalaryType(query.Get<int>("SalaryType"));
      data.TaxClass(query.Get<int>("TaxClass"));
      data.StartOfJob(query.Get<std::chrono::year_month_day>("StartOfJob"));
      data.EndOfJob(query.Get<std::chrono::year_month_day>("EndOfJob"));
      data.ReasonDeparture(query.Get<int>("ReasonDeparture"));
      data.JobPosition(query.Get<int>("JobPosition"));
      data.JobSpec(query.Get<std::string>("JobSpec"));
      data.VacationDays(query.Get<unsigned int>("VacationDays"));
      data.Department(query.Get<int>("Department"));
      data.SocialNummer(query.Get<std::string>("SocialNummer"));
      data.Active(query.Get<bool>("Active"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TFamilyStatus
bool TPersonReader::Read(myCorporate::TFamilyStatus::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLFamilyStatusAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TFamilyStatus element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.Coupled(query.Get<bool>("Coupled"));
      element.NeedDate(query.Get<bool>("NeedDate"));
      element.Notes(query.Get<std::string>("Notes"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TFamilyStatus::primary_key const& key_val, myCorporate::TFamilyStatus& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLFamilyStatusDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Coupled(query.Get<bool>("Coupled"));
      data.NeedDate(query.Get<bool>("NeedDate"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TFamilyTypes
bool TPersonReader::Read(myCorporate::TFamilyTypes::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLFamilyTypesAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TFamilyTypes element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.IsNaturalPerson(query.Get<bool>("IsNaturalPerson"));
      element.Description(query.Get<std::string>("Description"));
      element.Notes(query.Get<std::string>("Notes"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TFamilyTypes::primary_key const& key_val, myCorporate::TFamilyTypes& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLFamilyTypesDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.IsNaturalPerson(query.Get<bool>("IsNaturalPerson"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TFormOfAddress
bool TPersonReader::Read(myCorporate::TFormOfAddress::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLFormOfAddressAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TFormOfAddress element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.TypeSpec(query.Get<int>("TypeSpec"));
      element.Salutation(query.Get<std::string>("Salutation"));
      element.Valediction(query.Get<std::string>("Valediction"));
      element.Notes(query.Get<std::string>("Notes"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TFormOfAddress::primary_key const& key_val, myCorporate::TFormOfAddress& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLFormOfAddressDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.TypeSpec(query.Get<int>("TypeSpec"));
      data.Salutation(query.Get<std::string>("Salutation"));
      data.Valediction(query.Get<std::string>("Valediction"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TInternet
bool TPersonReader::Read(myCorporate::TInternet::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLInternetAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TInternet element;
      element.ID(query.Get<int>("ID", true));
      element.InternetType(query.Get<int>("InternetType", true));
      element.Adresse(query.Get<std::string>("Adresse"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TInternet::primary_key const& key_val, myCorporate::TInternet& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLInternetDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyInternetType", key_val.InternetType());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.InternetType(query.Get<int>("InternetType", true));
      data.Adresse(query.Get<std::string>("Adresse"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TInternetTypes
bool TPersonReader::Read(myCorporate::TInternetTypes::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLInternetTypesAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TInternetTypes element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.Prefix(query.Get<std::string>("Prefix"));
      element.Notes(query.Get<std::string>("Notes"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TInternetTypes::primary_key const& key_val, myCorporate::TInternetTypes& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLInternetTypesDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Prefix(query.Get<std::string>("Prefix"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TJobPositions
bool TPersonReader::Read(myHR::TJobPositions::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLJobPositionsAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TJobPositions element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.SalaryType(query.Get<int>("SalaryType"));
      element.Notes(query.Get<std::string>("Notes"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TJobPositions::primary_key const& key_val, myHR::TJobPositions& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLJobPositionsDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.SalaryType(query.Get<int>("SalaryType"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TPerson
bool TPersonReader::Read(myCorporate::TPerson::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLPersonAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TPerson element;
      element.ID(query.Get<int>("ID", true));
      element.Name(query.Get<std::string>("Name"));
      element.Firstname(query.Get<std::string>("Firstname"));
      element.FormOfAddress(query.Get<int>("FormOfAddress"));
      element.FamilyStatus(query.Get<int>("FamilyStatus"));
      element.FamilyStatusSince(query.Get<std::chrono::year_month_day>("FamilyStatusSince"));
      element.Birthday(query.Get<std::chrono::year_month_day>("Birthday"));
      element.Notes(query.Get<std::string>("Notes"));
      element.FullName(query.Get<std::string>("FullName"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TPerson::primary_key const& key_val, myCorporate::TPerson& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLPersonDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Name(query.Get<std::string>("Name"));
      data.Firstname(query.Get<std::string>("Firstname"));
      data.FormOfAddress(query.Get<int>("FormOfAddress"));
      data.FamilyStatus(query.Get<int>("FamilyStatus"));
      data.FamilyStatusSince(query.Get<std::chrono::year_month_day>("FamilyStatusSince"));
      data.Birthday(query.Get<std::chrono::year_month_day>("Birthday"));
      data.Notes(query.Get<std::string>("Notes"));
      data.FullName(query.Get<std::string>("FullName"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TPhone
bool TPersonReader::Read(myCorporate::TPhone::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLPhoneAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TPhone element;
      element.ID(query.Get<int>("ID", true));
      element.PhoneType(query.Get<int>("PhoneType", true));
      element.AreaCode(query.Get<std::string>("AreaCode"));
      element.CallNumber(query.Get<std::string>("CallNumber"));
      element.Country(query.Get<int>("Country"));
      element.DialingNational(query.Get<std::string>("DialingNational"));
      element.DialingInternational(query.Get<std::string>("DialingInternational"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TPhone::primary_key const& key_val, myCorporate::TPhone& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLPhoneDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyPhoneType", key_val.PhoneType());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.PhoneType(query.Get<int>("PhoneType", true));
      data.AreaCode(query.Get<std::string>("AreaCode"));
      data.CallNumber(query.Get<std::string>("CallNumber"));
      data.Country(query.Get<int>("Country"));
      data.DialingNational(query.Get<std::string>("DialingNational"));
      data.DialingInternational(query.Get<std::string>("DialingInternational"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TPhonesTypes
bool TPersonReader::Read(myCorporate::TPhonesTypes::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLPhonesTypesAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myCorporate::TPhonesTypes element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.Notes(query.Get<std::string>("Notes"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TPhonesTypes::primary_key const& key_val, myCorporate::TPhonesTypes& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLPhonesTypesDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TReasonDeparture
bool TPersonReader::Read(myHR::TReasonDeparture::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLReasonDepartureAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TReasonDeparture element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.Notes(query.Get<std::string>("Notes"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TReasonDeparture::primary_key const& key_val, myHR::TReasonDeparture& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLReasonDepartureDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TReasonNonWorking
bool TPersonReader::Read(myHR::TReasonNonWorking::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLReasonNonWorkingAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TReasonNonWorking element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.Notes(query.Get<std::string>("Notes"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TReasonNonWorking::primary_key const& key_val, myHR::TReasonNonWorking& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLReasonNonWorkingDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TSalaryBase
bool TPersonReader::Read(myHR::TSalaryBase::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLSalaryBaseAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TSalaryBase element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TSalaryBase::primary_key const& key_val, myHR::TSalaryBase& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLSalaryBaseDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TSalaryType
bool TPersonReader::Read(myHR::TSalaryType::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLSalaryTypeAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TSalaryType element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.SalaryBase(query.Get<int>("SalaryBase"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TSalaryType::primary_key const& key_val, myHR::TSalaryType& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLSalaryTypeDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.SalaryBase(query.Get<int>("SalaryBase"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TTaxClasses
bool TPersonReader::Read(myHR::TTaxClasses::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLTaxClassesAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TTaxClasses element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.Coupled(query.Get<bool>("Coupled"));
      element.UrgentValue(query.Get<bool>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TTaxClasses::primary_key const& key_val, myHR::TTaxClasses& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLTaxClassesDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Coupled(query.Get<bool>("Coupled"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TWD_Holidays
bool TPersonReader::Read(myHR::TWD_Holidays::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_HolidaysAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TWD_Holidays element;
      element.CalendarDay(query.Get<std::chrono::year_month_day>("CalendarDay", true));
      element.Donation(query.Get<std::string>("Donation"));
      element.Share(query.Get<int>("Share"));
      element.Description(query.Get<std::string>("Description"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TWD_Holidays::primary_key const& key_val, myHR::TWD_Holidays& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_HolidaysDetail);
   query.Set("keyCalendarDay", key_val.CalendarDay());
   query.Execute();
   if(!query.IsEof()) {
      data.CalendarDay(query.Get<std::chrono::year_month_day>("CalendarDay", true));
      data.Donation(query.Get<std::string>("Donation"));
      data.Share(query.Get<int>("Share"));
      data.Description(query.Get<std::string>("Description"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TWD_Months
bool TPersonReader::Read(myHR::TWD_Months::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_MonthsAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TWD_Months element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Quarter(query.Get<unsigned int>("Quarter"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TWD_Months::primary_key const& key_val, myHR::TWD_Months& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_MonthsDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Quarter(query.Get<unsigned int>("Quarter"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TWD_NonWorking
bool TPersonReader::Read(myHR::TWD_NonWorking::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_NonWorkingAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TWD_NonWorking element;
      element.ID(query.Get<int>("ID", true));
      element.StartAt(query.Get<std::chrono::year_month_day>("StartAt", true));
      element.ClosingAt(query.Get<std::chrono::year_month_day>("ClosingAt"));
      element.Reason(query.Get<int>("Reason"));
      element.Notes(query.Get<std::string>("Notes"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TWD_NonWorking::primary_key const& key_val, myHR::TWD_NonWorking& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_NonWorkingDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyStartAt", key_val.StartAt());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.StartAt(query.Get<std::chrono::year_month_day>("StartAt", true));
      data.ClosingAt(query.Get<std::chrono::year_month_day>("ClosingAt"));
      data.Reason(query.Get<int>("Reason"));
      data.Notes(query.Get<std::string>("Notes"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TWD_Weekdays
bool TPersonReader::Read(myHR::TWD_Weekdays::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_WeekdaysAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TWD_Weekdays element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Workday(query.Get<bool>("Workday"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TWD_Weekdays::primary_key const& key_val, myHR::TWD_Weekdays& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_WeekdaysDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Workday(query.Get<bool>("Workday"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TWD_Workdays
bool TPersonReader::Read(myHR::TWD_Workdays::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_WorkdaysAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TWD_Workdays element;
      element.CalendarDay(query.Get<std::chrono::year_month_day>("CalendarDay", true));
      element.CalendarWeekday(query.Get<int>("CalendarWeekday"));
      element.CalendarWeek(query.Get<int>("CalendarWeek"));
      element.CalendarYear(query.Get<int>("CalendarYear"));
      element.CalendarMonth(query.Get<int>("CalendarMonth"));
      element.CalendarDayInWeek(query.Get<int>("CalendarDayInWeek"));
      element.CalendarDayInYear(query.Get<int>("CalendarDayInYear"));
      element.CalendarQuarter(query.Get<int>("CalendarQuarter"));
      element.Workday(query.Get<bool>("Workday"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TWD_Workdays::primary_key const& key_val, myHR::TWD_Workdays& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_WorkdaysDetail);
   query.Set("keyCalendarDay", key_val.CalendarDay());
   query.Execute();
   if(!query.IsEof()) {
      data.CalendarDay(query.Get<std::chrono::year_month_day>("CalendarDay", true));
      data.CalendarWeekday(query.Get<int>("CalendarWeekday"));
      data.CalendarWeek(query.Get<int>("CalendarWeek"));
      data.CalendarYear(query.Get<int>("CalendarYear"));
      data.CalendarMonth(query.Get<int>("CalendarMonth"));
      data.CalendarDayInWeek(query.Get<int>("CalendarDayInWeek"));
      data.CalendarDayInYear(query.Get<int>("CalendarDayInYear"));
      data.CalendarQuarter(query.Get<int>("CalendarQuarter"));
      data.Workday(query.Get<bool>("Workday"));
      }
   else throw std::runtime_error("...");
   return true;
   }


// access methods for class TWorkingTime
bool TPersonReader::Read(myHR::TWorkingTime::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWorkingTimeAll);
   for(query.Execute();!query.IsEof();query.Next()) {
      myHR::TWorkingTime element;
      element.ID(query.Get<int>("ID", true));
      element.StartingTime(query.Get<std::chrono::system_clock::time_point>("StartingTime", true));
      element.ClosingTime(query.Get<std::chrono::system_clock::time_point>("ClosingTime"));
      element.Processed(query.Get<bool>("Processed"));
      element.ProcessedAt(query.Get<std::chrono::system_clock::time_point>("ProcessedAt"));
      element.DayOfWork(query.Get<std::chrono::year_month_day>("DayOfWork"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myHR::TWorkingTime::primary_key const& key_val, myHR::TWorkingTime& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWorkingTimeDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyStartingTime", key_val.StartingTime());
   query.Execute();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.StartingTime(query.Get<std::chrono::system_clock::time_point>("StartingTime", true));
      data.ClosingTime(query.Get<std::chrono::system_clock::time_point>("ClosingTime"));
      data.Processed(query.Get<bool>("Processed"));
      data.ProcessedAt(query.Get<std::chrono::system_clock::time_point>("ProcessedAt"));
      data.DayOfWork(query.Get<std::chrono::year_month_day>("DayOfWork"));
      }
   else throw std::runtime_error("...");
   return true;
   }



} // close namespace reader
