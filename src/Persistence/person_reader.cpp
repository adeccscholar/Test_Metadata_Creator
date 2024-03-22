/*
* Project: model with a simple person administration
* Definition of the persistence class TPersonReader
* Date: 22.03.2024 15:39:13,250  file created with adecc Scholar metadata generator
* copyright (c) adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include <Persistence\person_reader_sql.h>
#include <Persistence\person_reader.h>

#include <adecc_Database\MyDatabaseExceptions.h>

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
   query.SetSQL(strSQLAddressSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLAddressSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyAddressType", key_val.AddressType());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.AddressType(query.Get<int>("AddressType", true));
      data.Zipcode(query.Get<std::string>("Zipcode"));
      data.City(query.Get<std::string>("City"));
      data.Street(query.Get<std::string>("Street"));
      data.StreetNumber(query.Get<std::string>("StreetNumber"));
      data.Country(query.Get<int>("Country"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TAddress";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLAddressSelectDetail);
      }
   return true;
   }


// access methods for class TAddressTypes
bool TPersonReader::Read(myCorporate::TAddressTypes::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLAddressTypesSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLAddressTypesSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TAddressTypes";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLAddressTypesSelectDetail);
      }
   return true;
   }


// access methods for class TBanking
bool TPersonReader::Read(myCorporate::TBanking::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLBankingSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLBankingSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyBankingType", key_val.BankingType());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.BankingType(query.Get<int>("BankingType", true));
      data.BankName(query.Get<std::string>("BankName"));
      data.IBAN(query.Get<std::string>("IBAN"));
      data.BIC(query.Get<std::string>("BIC"));
      data.BankOwner(query.Get<std::string>("BankOwner"));
      data.Country(query.Get<int>("Country"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TBanking";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLBankingSelectDetail);
      }
   return true;
   }


// access methods for class TBankingTypes
bool TPersonReader::Read(myCorporate::TBankingTypes::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLBankingTypesSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLBankingTypesSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TBankingTypes";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLBankingTypesSelectDetail);
      }
   return true;
   }


// access methods for class TContacts
bool TPersonReader::Read(mySales::TContacts::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLContactsSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
      mySales::TContacts element;
      element.ContactID(query.Get<int>("ContactID", true));
      element.CustID(query.Get<int>("CustID"));
      element.CustLiaison(query.Get<int>("CustLiaison"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(mySales::TContacts::primary_key const& key_val, mySales::TContacts& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLContactsSelectDetail);
   query.Set("keyContactID", key_val.ContactID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ContactID(query.Get<int>("ContactID", true));
      data.CustID(query.Get<int>("CustID"));
      data.CustLiaison(query.Get<int>("CustLiaison"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TContacts";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLContactsSelectDetail);
      }
   return true;
   }


// access methods for class TCorporateForm
bool TPersonReader::Read(myCorporate::TCorporateForm::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLCorporateFormSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
      myCorporate::TCorporateForm element;
      element.ID(query.Get<int>("ID", true));
      element.Denotation(query.Get<std::string>("Denotation"));
      element.Abbreviation(query.Get<std::string>("Abbreviation"));
      element.Description(query.Get<std::string>("Description"));
      element.IsLegalEntrity(query.Get<bool>("IsLegalEntrity"));
      element.UrgentValue(query.Get<int>("UrgentValue"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(myCorporate::TCorporateForm::primary_key const& key_val, myCorporate::TCorporateForm& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLCorporateFormSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.IsLegalEntrity(query.Get<bool>("IsLegalEntrity"));
      data.UrgentValue(query.Get<int>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TCorporateForm";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLCorporateFormSelectDetail);
      }
   return true;
   }


// access methods for class TCountries
bool TPersonReader::Read(myCorporate::TCountries::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLCountriesSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLCountriesSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
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
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TCountries";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLCountriesSelectDetail);
      }
   return true;
   }


// access methods for class TCustClassification
bool TPersonReader::Read(mySales::TCustClassification::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLCustClassificationSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
      mySales::TCustClassification element;
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

bool TPersonReader::Read(mySales::TCustClassification::primary_key const& key_val, mySales::TCustClassification& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLCustClassificationSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TCustClassification";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLCustClassificationSelectDetail);
      }
   return true;
   }


// access methods for class TCustLiaison
bool TPersonReader::Read(mySales::TCustLiaison::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLCustLiaisonSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
      mySales::TCustLiaison element;
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

bool TPersonReader::Read(mySales::TCustLiaison::primary_key const& key_val, mySales::TCustLiaison& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLCustLiaisonSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TCustLiaison";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLCustLiaisonSelectDetail);
      }
   return true;
   }


// access methods for class TCustomers
bool TPersonReader::Read(mySales::TCustomers::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLCustomersSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
      mySales::TCustomers element;
      element.CustID(query.Get<int>("CustID", true));
      element.ServiceAgent(query.Get<int>("ServiceAgent"));
      element.CustClassification(query.Get<int>("CustClassification"));
      element.LegalForm(query.Get<int>("LegalForm"));
      data.insert({ element.GetKey(), element });
      }
   return true;
   }

bool TPersonReader::Read(mySales::TCustomers::primary_key const& key_val, mySales::TCustomers& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLCustomersSelectDetail);
   query.Set("keyCustID", key_val.CustID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.CustID(query.Get<int>("CustID", true));
      data.ServiceAgent(query.Get<int>("ServiceAgent"));
      data.CustClassification(query.Get<int>("CustClassification"));
      data.LegalForm(query.Get<int>("LegalForm"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TCustomers";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLCustomersSelectDetail);
      }
   return true;
   }


// access methods for class TDepartments
bool TPersonReader::Read(myHR::TDepartments::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLDepartmentsSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLDepartmentsSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Officer(query.Get<int>("Officer"));
      data.Notes(query.Get<std::string>("Notes"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TDepartments";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLDepartmentsSelectDetail);
      }
   return true;
   }


// access methods for class TEmployees
bool TPersonReader::Read(myHR::TEmployees::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLEmployeesSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
      myHR::TEmployees element;
      element.Dummy(query.Get<int>("Dummy"));
      element.EmployeeID(query.Get<int>("EmployeeID", true));
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
   query.SetSQL(strSQLEmployeesSelectDetail);
   query.Set("keyEmployeeID", key_val.EmployeeID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.Dummy(query.Get<int>("Dummy"));
      data.EmployeeID(query.Get<int>("EmployeeID", true));
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
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TEmployees";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLEmployeesSelectDetail);
      }
   return true;
   }


// access methods for class TFamilyStatus
bool TPersonReader::Read(myCorporate::TFamilyStatus::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLFamilyStatusSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLFamilyStatusSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
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
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TFamilyStatus";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLFamilyStatusSelectDetail);
      }
   return true;
   }


// access methods for class TFamilyTypes
bool TPersonReader::Read(myCorporate::TFamilyTypes::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLFamilyTypesSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLFamilyTypesSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.IsNaturalPerson(query.Get<bool>("IsNaturalPerson"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TFamilyTypes";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLFamilyTypesSelectDetail);
      }
   return true;
   }


// access methods for class TFormOfAddress
bool TPersonReader::Read(myCorporate::TFormOfAddress::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLFormOfAddressSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLFormOfAddressSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
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
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TFormOfAddress";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLFormOfAddressSelectDetail);
      }
   return true;
   }


// access methods for class TInternet
bool TPersonReader::Read(myCorporate::TInternet::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLInternetSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLInternetSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyInternetType", key_val.InternetType());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.InternetType(query.Get<int>("InternetType", true));
      data.Adresse(query.Get<std::string>("Adresse"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TInternet";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLInternetSelectDetail);
      }
   return true;
   }


// access methods for class TInternetTypes
bool TPersonReader::Read(myCorporate::TInternetTypes::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLInternetTypesSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLInternetTypesSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Prefix(query.Get<std::string>("Prefix"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TInternetTypes";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLInternetTypesSelectDetail);
      }
   return true;
   }


// access methods for class TJobPositions
bool TPersonReader::Read(myHR::TJobPositions::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLJobPositionsSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLJobPositionsSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.SalaryType(query.Get<int>("SalaryType"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TJobPositions";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLJobPositionsSelectDetail);
      }
   return true;
   }


// access methods for class TPerson
bool TPersonReader::Read(myCorporate::TPerson::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLPersonSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLPersonSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
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
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TPerson";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLPersonSelectDetail);
      }
   return true;
   }


// access methods for class TPhone
bool TPersonReader::Read(myCorporate::TPhone::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLPhoneSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLPhoneSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyPhoneType", key_val.PhoneType());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.PhoneType(query.Get<int>("PhoneType", true));
      data.AreaCode(query.Get<std::string>("AreaCode"));
      data.CallNumber(query.Get<std::string>("CallNumber"));
      data.Country(query.Get<int>("Country"));
      data.DialingNational(query.Get<std::string>("DialingNational"));
      data.DialingInternational(query.Get<std::string>("DialingInternational"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TPhone";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLPhoneSelectDetail);
      }
   return true;
   }


// access methods for class TPhonesTypes
bool TPersonReader::Read(myCorporate::TPhonesTypes::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLPhonesTypesSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLPhonesTypesSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TPhonesTypes";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLPhonesTypesSelectDetail);
      }
   return true;
   }


// access methods for class TReasonDeparture
bool TPersonReader::Read(myHR::TReasonDeparture::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLReasonDepartureSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLReasonDepartureSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TReasonDeparture";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLReasonDepartureSelectDetail);
      }
   return true;
   }


// access methods for class TReasonNonWorking
bool TPersonReader::Read(myHR::TReasonNonWorking::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLReasonNonWorkingSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLReasonNonWorkingSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Notes(query.Get<std::string>("Notes"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TReasonNonWorking";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLReasonNonWorkingSelectDetail);
      }
   return true;
   }


// access methods for class TSalaryBase
bool TPersonReader::Read(myHR::TSalaryBase::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLSalaryBaseSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLSalaryBaseSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TSalaryBase";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLSalaryBaseSelectDetail);
      }
   return true;
   }


// access methods for class TSalaryType
bool TPersonReader::Read(myHR::TSalaryType::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLSalaryTypeSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLSalaryTypeSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.SalaryBase(query.Get<int>("SalaryBase"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TSalaryType";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLSalaryTypeSelectDetail);
      }
   return true;
   }


// access methods for class TTaxClasses
bool TPersonReader::Read(myHR::TTaxClasses::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLTaxClassesSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLTaxClassesSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Description(query.Get<std::string>("Description"));
      data.Coupled(query.Get<bool>("Coupled"));
      data.UrgentValue(query.Get<bool>("UrgentValue"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TTaxClasses";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLTaxClassesSelectDetail);
      }
   return true;
   }


// access methods for class TWD_Holidays
bool TPersonReader::Read(myHR::TWD_Holidays::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_HolidaysSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLWD_HolidaysSelectDetail);
   query.Set("keyCalendarDay", key_val.CalendarDay());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.CalendarDay(query.Get<std::chrono::year_month_day>("CalendarDay", true));
      data.Donation(query.Get<std::string>("Donation"));
      data.Share(query.Get<int>("Share"));
      data.Description(query.Get<std::string>("Description"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TWD_Holidays";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLWD_HolidaysSelectDetail);
      }
   return true;
   }


// access methods for class TWD_Months
bool TPersonReader::Read(myHR::TWD_Months::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_MonthsSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLWD_MonthsSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Quarter(query.Get<unsigned int>("Quarter"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TWD_Months";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLWD_MonthsSelectDetail);
      }
   return true;
   }


// access methods for class TWD_NonWorking
bool TPersonReader::Read(myHR::TWD_NonWorking::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_NonWorkingSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLWD_NonWorkingSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyStartAt", key_val.StartAt());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.StartAt(query.Get<std::chrono::year_month_day>("StartAt", true));
      data.ClosingAt(query.Get<std::chrono::year_month_day>("ClosingAt"));
      data.Reason(query.Get<int>("Reason"));
      data.Notes(query.Get<std::string>("Notes"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TWD_NonWorking";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLWD_NonWorkingSelectDetail);
      }
   return true;
   }


// access methods for class TWD_Weekdays
bool TPersonReader::Read(myHR::TWD_Weekdays::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_WeekdaysSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLWD_WeekdaysSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.Denotation(query.Get<std::string>("Denotation"));
      data.Abbreviation(query.Get<std::string>("Abbreviation"));
      data.Workday(query.Get<bool>("Workday"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TWD_Weekdays";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLWD_WeekdaysSelectDetail);
      }
   return true;
   }


// access methods for class TWD_Workdays
bool TPersonReader::Read(myHR::TWD_Workdays::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWD_WorkdaysSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLWD_WorkdaysSelectDetail);
   query.Set("keyCalendarDay", key_val.CalendarDay());
   query.Execute();
   query.First();
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
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TWD_Workdays";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLWD_WorkdaysSelectDetail);
      }
   return true;
   }


// access methods for class TWorkingTime
bool TPersonReader::Read(myHR::TWorkingTime::container_ty& data) {
   auto query = database.CreateQuery();
   query.SetSQL(strSQLWorkingTimeSelectAll);
   for(query.Execute(), query.First();!query.IsEof();query.Next()) {
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
   query.SetSQL(strSQLWorkingTimeSelectDetail);
   query.Set("keyID", key_val.ID());
   query.Set("keyStartingTime", key_val.StartingTime());
   query.Execute();
   query.First();
   if(!query.IsEof()) {
      data.ID(query.Get<int>("ID", true));
      data.StartingTime(query.Get<std::chrono::system_clock::time_point>("StartingTime", true));
      data.ClosingTime(query.Get<std::chrono::system_clock::time_point>("ClosingTime"));
      data.Processed(query.Get<bool>("Processed"));
      data.ProcessedAt(query.Get<std::chrono::system_clock::time_point>("ProcessedAt"));
      data.DayOfWork(query.Get<std::chrono::year_month_day>("DayOfWork"));
      }
   else return false;
   if(query.Next(); !query.IsEof()) {
      std::ostringstream os1, os2;
      os1 << "error while reading data for TWorkingTime";
      os2 << "couldn't read unique data for primary key element\n";
      key_val.write(os2);
      throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), strSQLWorkingTimeSelectDetail);
      }
   return true;
   }



} // close namespace reader
