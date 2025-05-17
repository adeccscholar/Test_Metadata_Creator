/*
* Project: model with a simple person administration
* Definition of the persistence class TPersonReader
* Date: 22.04.2025 22:26:57,174  file created with adecc Scholar metadata generator
* copyright (c) adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#pragma once

#include <vector>
#include <map>
#include <typeinfo>

#include <System\Corporate\Address.h>
#include <System\Corporate\AddressTypes.h>
#include <System\Corporate\Banking.h>
#include <System\Corporate\BankingTypes.h>
#include <System\Sales\Contacts.h>
#include <System\Corporate\CorporateForm.h>
#include <System\Corporate\Countries.h>
#include <System\Sales\CustClassification.h>
#include <System\Sales\CustLiaison.h>
#include <System\Sales\Customers.h>
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

#include <adecc_Database/MyDatabase.h>
#include <adecc_Database/MyDatabaseExceptions.h>

#include <Persistence\person_reader_sql.h>
#include "Base\BaseDefinitions.h"
#include <string>
#include <memory>

namespace reader {

template <typename ty>
concept my_dataclasses =
          (std::is_same_v<ty, myCorporate::TAddress> ||
           std::is_same_v<ty, myCorporate::TAddressTypes> ||
           std::is_same_v<ty, myCorporate::TBanking> ||
           std::is_same_v<ty, myCorporate::TBankingTypes> ||
           std::is_same_v<ty, mySales::TContacts> ||
           std::is_same_v<ty, myCorporate::TCorporateForm> ||
           std::is_same_v<ty, myCorporate::TCountries> ||
           std::is_same_v<ty, mySales::TCustClassification> ||
           std::is_same_v<ty, mySales::TCustLiaison> ||
           std::is_same_v<ty, mySales::TCustomers> ||
           std::is_same_v<ty, myHR::TDepartments> ||
           std::is_same_v<ty, myHR::TEmployees> ||
           std::is_same_v<ty, myCorporate::TFamilyStatus> ||
           std::is_same_v<ty, myCorporate::TFamilyTypes> ||
           std::is_same_v<ty, myCorporate::TFormOfAddress> ||
           std::is_same_v<ty, myCorporate::TInternet> ||
           std::is_same_v<ty, myCorporate::TInternetTypes> ||
           std::is_same_v<ty, myHR::TJobPositions> ||
           std::is_same_v<ty, myCorporate::TPerson> ||
           std::is_same_v<ty, myCorporate::TPhone> ||
           std::is_same_v<ty, myCorporate::TPhonesTypes> ||
           std::is_same_v<ty, myHR::TReasonDeparture> ||
           std::is_same_v<ty, myHR::TReasonNonWorking> ||
           std::is_same_v<ty, myHR::TSalaryBase> ||
           std::is_same_v<ty, myHR::TSalaryType> ||
           std::is_same_v<ty, myHR::TTaxClasses> ||
           std::is_same_v<ty, myHR::TWD_Holidays> ||
           std::is_same_v<ty, myHR::TWD_Months> ||
           std::is_same_v<ty, myHR::TWD_NonWorking> ||
           std::is_same_v<ty, myHR::TWD_Weekdays> ||
           std::is_same_v<ty, myHR::TWD_Workdays> ||
           std::is_same_v<ty, myHR::TWorkingTime>) &&
          requires {
               typename ty::primary_key;
               typename ty::container_ty;
               typename ty::vector_ty;
               typename ty::func_ty;
          };

template <typename ty>
concept my_data_primkey =
          std::is_same_v<ty, myCorporate::TAddress::primary_key> ||
          std::is_same_v<ty, myCorporate::TAddressTypes::primary_key> ||
          std::is_same_v<ty, myCorporate::TBanking::primary_key> ||
          std::is_same_v<ty, myCorporate::TBankingTypes::primary_key> ||
          std::is_same_v<ty, mySales::TContacts::primary_key> ||
          std::is_same_v<ty, myCorporate::TCorporateForm::primary_key> ||
          std::is_same_v<ty, myCorporate::TCountries::primary_key> ||
          std::is_same_v<ty, mySales::TCustClassification::primary_key> ||
          std::is_same_v<ty, mySales::TCustLiaison::primary_key> ||
          std::is_same_v<ty, mySales::TCustomers::primary_key> ||
          std::is_same_v<ty, myHR::TDepartments::primary_key> ||
          std::is_same_v<ty, myHR::TEmployees::primary_key> ||
          std::is_same_v<ty, myCorporate::TFamilyStatus::primary_key> ||
          std::is_same_v<ty, myCorporate::TFamilyTypes::primary_key> ||
          std::is_same_v<ty, myCorporate::TFormOfAddress::primary_key> ||
          std::is_same_v<ty, myCorporate::TInternet::primary_key> ||
          std::is_same_v<ty, myCorporate::TInternetTypes::primary_key> ||
          std::is_same_v<ty, myHR::TJobPositions::primary_key> ||
          std::is_same_v<ty, myCorporate::TPerson::primary_key> ||
          std::is_same_v<ty, myCorporate::TPhone::primary_key> ||
          std::is_same_v<ty, myCorporate::TPhonesTypes::primary_key> ||
          std::is_same_v<ty, myHR::TReasonDeparture::primary_key> ||
          std::is_same_v<ty, myHR::TReasonNonWorking::primary_key> ||
          std::is_same_v<ty, myHR::TSalaryBase::primary_key> ||
          std::is_same_v<ty, myHR::TSalaryType::primary_key> ||
          std::is_same_v<ty, myHR::TTaxClasses::primary_key> ||
          std::is_same_v<ty, myHR::TWD_Holidays::primary_key> ||
          std::is_same_v<ty, myHR::TWD_Months::primary_key> ||
          std::is_same_v<ty, myHR::TWD_NonWorking::primary_key> ||
          std::is_same_v<ty, myHR::TWD_Weekdays::primary_key> ||
          std::is_same_v<ty, myHR::TWD_Workdays::primary_key> ||
          std::is_same_v<ty, myHR::TWorkingTime::primary_key>;

template <typename ty>
concept my_datacontainer =
      (own::is_vector_v<ty> && my_dataclasses<typename ty::value_type>) ||
      (own::is_set_v<ty> && my_dataclasses<typename ty::key_type>) ||
      (own::is_map_v<ty> &&
                     my_dataclasses<typename ty::mapped_type> &&
                     std::is_same_v<typename ty::key_type, typename ty::mapped_type::primary_key>);

using concrete_db_server = TMyMSSQL;
using concrete_framework = TMyQtDb<concrete_db_server>;
using concrete_db_connection = TMyDatabase<TMyQtDb, concrete_db_server>;
using concrete_query = TMyQuery<TMyQtDb, concrete_db_server>;

class DataAccess {
   private:
      // member to produce the data access
      concrete_db_connection& database;
      //concrete_query          query;
   public:
      DataAccess() = delete;
      DataAccess(concrete_db_connection& con) : database(con) { }
      DataAccess(DataAccess const&) = delete;

      template <my_dataclasses data_ty>
      data_ty GetTuple(concrete_query& query) const {
         data_ty data;
         if constexpr (std::is_same_v<data_ty, myCorporate::TAddress>) {
            data.ID(query.Get<int>("ID", true));
            data.AddressType(query.Get<int>("AddressType", true));
            data.Zipcode(query.Get<std::string>("Zipcode"));
            data.City(query.Get<std::string>("City"));
            data.Street(query.Get<std::string>("Street"));
            data.StreetNumber(query.Get<std::string>("StreetNumber"));
            data.Country(query.Get<int>("Country"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TAddressTypes>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.Notes(query.Get<std::string>("Notes"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TBanking>) {
            data.ID(query.Get<int>("ID", true));
            data.BankingType(query.Get<int>("BankingType", true));
            data.BankName(query.Get<std::string>("BankName"));
            data.IBAN(query.Get<std::string>("IBAN"));
            data.BIC(query.Get<std::string>("BIC"));
            data.BankOwner(query.Get<std::string>("BankOwner"));
            data.Country(query.Get<int>("Country"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TBankingTypes>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.Notes(query.Get<std::string>("Notes"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, mySales::TContacts>) {
            data.ContactID(query.Get<int>("ContactID", true));
            data.CustID(query.Get<int>("CustID"));
            data.CustLiaison(query.Get<int>("CustLiaison"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TCorporateForm>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.IsLegalEntrity(query.Get<bool>("IsLegalEntrity"));
            data.UrgentValue(query.Get<int>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TCountries>) {
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
         else if constexpr(std::is_same_v<data_ty, mySales::TCustClassification>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.Notes(query.Get<std::string>("Notes"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, mySales::TCustLiaison>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.Notes(query.Get<std::string>("Notes"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, mySales::TCustomers>) {
            data.CustID(query.Get<int>("CustID", true));
            data.ServiceAgent(query.Get<int>("ServiceAgent"));
            data.CustClassification(query.Get<int>("CustClassification"));
            data.LegalForm(query.Get<int>("LegalForm"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TDepartments>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.Officer(query.Get<int>("Officer"));
            data.Notes(query.Get<std::string>("Notes"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TEmployees>) {
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
            data.TaxNumber(query.Get<std::string>("TaxNumber"));
            data.SocialNummer(query.Get<std::string>("SocialNummer"));
            data.Active(query.Get<bool>("Active"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TFamilyStatus>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.Coupled(query.Get<bool>("Coupled"));
            data.NeedDate(query.Get<bool>("NeedDate"));
            data.Notes(query.Get<std::string>("Notes"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TFamilyTypes>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.IsNaturalPerson(query.Get<bool>("IsNaturalPerson"));
            data.Description(query.Get<std::string>("Description"));
            data.Notes(query.Get<std::string>("Notes"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TFormOfAddress>) {
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
         else if constexpr(std::is_same_v<data_ty, myCorporate::TInternet>) {
            data.ID(query.Get<int>("ID", true));
            data.InternetType(query.Get<int>("InternetType", true));
            data.Adresse(query.Get<std::string>("Adresse"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TInternetTypes>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.Prefix(query.Get<std::string>("Prefix"));
            data.Notes(query.Get<std::string>("Notes"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TJobPositions>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.SalaryType(query.Get<int>("SalaryType"));
            data.Notes(query.Get<std::string>("Notes"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TPerson>) {
            data.ID(query.Get<int>("ID", true));
            data.Name(query.Get<std::string>("Name"));
            data.FirstName(query.Get<std::string>("FirstName"));
            data.Birthname(query.Get<std::string>("Birthname"));
            data.FormOfAddress(query.Get<int>("FormOfAddress"));
            data.FamilyStatus(query.Get<int>("FamilyStatus"));
            data.FamilyStatusSince(query.Get<std::chrono::year_month_day>("FamilyStatusSince"));
            data.Birthday(query.Get<std::chrono::year_month_day>("Birthday"));
            data.Notes(query.Get<std::string>("Notes"));
            data.FullName(query.Get<std::string>("FullName"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TPhone>) {
            data.ID(query.Get<int>("ID", true));
            data.PhoneType(query.Get<int>("PhoneType", true));
            data.AreaCode(query.Get<std::string>("AreaCode"));
            data.CallNumber(query.Get<std::string>("CallNumber"));
            data.Country(query.Get<int>("Country"));
            data.DialingNational(query.Get<std::string>("DialingNational"));
            data.DialingInternational(query.Get<std::string>("DialingInternational"));
            }
         else if constexpr(std::is_same_v<data_ty, myCorporate::TPhonesTypes>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.Notes(query.Get<std::string>("Notes"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TReasonDeparture>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.Notes(query.Get<std::string>("Notes"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TReasonNonWorking>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.Notes(query.Get<std::string>("Notes"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TSalaryBase>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TSalaryType>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.SalaryBase(query.Get<int>("SalaryBase"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TTaxClasses>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Description(query.Get<std::string>("Description"));
            data.Coupled(query.Get<bool>("Coupled"));
            data.UrgentValue(query.Get<bool>("UrgentValue"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TWD_Holidays>) {
            data.CalendarDay(query.Get<std::chrono::year_month_day>("CalendarDay", true));
            data.Donation(query.Get<std::string>("Donation"));
            data.Share(query.Get<int>("Share"));
            data.Description(query.Get<std::string>("Description"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TWD_Months>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Quarter(query.Get<unsigned int>("Quarter"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TWD_NonWorking>) {
            data.ID(query.Get<int>("ID", true));
            data.StartAt(query.Get<std::chrono::year_month_day>("StartAt", true));
            data.ClosingAt(query.Get<std::chrono::year_month_day>("ClosingAt"));
            data.Reason(query.Get<int>("Reason"));
            data.Notes(query.Get<std::string>("Notes"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TWD_Weekdays>) {
            data.ID(query.Get<int>("ID", true));
            data.Denotation(query.Get<std::string>("Denotation"));
            data.Abbreviation(query.Get<std::string>("Abbreviation"));
            data.Workday(query.Get<bool>("Workday"));
            }
         else if constexpr(std::is_same_v<data_ty, myHR::TWD_Workdays>) {
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
         else if constexpr(std::is_same_v<data_ty, myHR::TWorkingTime>) {
            data.ID(query.Get<int>("ID", true));
            data.StartingTime(query.Get<std::chrono::system_clock::time_point>("StartingTime", true));
            data.ClosingTime(query.Get<std::chrono::system_clock::time_point>("ClosingTime"));
            data.Processed(query.Get<bool>("Processed"));
            data.ProcessedAt(query.Get<std::chrono::system_clock::time_point>("ProcessedAt"));
            data.DayOfWork(query.Get<std::chrono::year_month_day>("DayOfWork"));
            }
         else static_assert(own::always_false<data_ty>, "unexpected datatype for this class");
         return data;
         }

      template <my_dataclasses data_ty>
      std::optional<data_ty> Read(typename data_ty::primary_key const& key_val) {
            auto query = database.CreateQuery();
            if constexpr (std::is_same_v<data_ty, myCorporate::TAddress>) {
               query.SetSQL(strSQLSelectAddress_Detail);
               query.Set("keyID", key_val.ID());
               query.Set("keyAddressType", key_val.AddressType());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TAddressTypes>) {
               query.SetSQL(strSQLSelectAddressTypes_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TBanking>) {
               query.SetSQL(strSQLSelectBanking_Detail);
               query.Set("keyID", key_val.ID());
               query.Set("keyBankingType", key_val.BankingType());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TBankingTypes>) {
               query.SetSQL(strSQLSelectBankingTypes_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, mySales::TContacts>) {
               query.SetSQL(strSQLSelectContacts_Detail);
               query.Set("keyContactID", key_val.ContactID());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TCorporateForm>) {
               query.SetSQL(strSQLSelectCorporateForm_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TCountries>) {
               query.SetSQL(strSQLSelectCountries_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, mySales::TCustClassification>) {
               query.SetSQL(strSQLSelectCustClassification_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, mySales::TCustLiaison>) {
               query.SetSQL(strSQLSelectCustLiaison_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, mySales::TCustomers>) {
               query.SetSQL(strSQLSelectCustomers_Detail);
               query.Set("keyCustID", key_val.CustID());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TDepartments>) {
               query.SetSQL(strSQLSelectDepartments_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TEmployees>) {
               query.SetSQL(strSQLSelectEmployees_Detail);
               query.Set("keyEmployeeID", key_val.EmployeeID());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TFamilyStatus>) {
               query.SetSQL(strSQLSelectFamilyStatus_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TFamilyTypes>) {
               query.SetSQL(strSQLSelectFamilyTypes_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TFormOfAddress>) {
               query.SetSQL(strSQLSelectFormOfAddress_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TInternet>) {
               query.SetSQL(strSQLSelectInternet_Detail);
               query.Set("keyID", key_val.ID());
               query.Set("keyInternetType", key_val.InternetType());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TInternetTypes>) {
               query.SetSQL(strSQLSelectInternetTypes_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TJobPositions>) {
               query.SetSQL(strSQLSelectJobPositions_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TPerson>) {
               query.SetSQL(strSQLSelectPerson_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TPhone>) {
               query.SetSQL(strSQLSelectPhone_Detail);
               query.Set("keyID", key_val.ID());
               query.Set("keyPhoneType", key_val.PhoneType());
               }
            else if constexpr (std::is_same_v<data_ty, myCorporate::TPhonesTypes>) {
               query.SetSQL(strSQLSelectPhonesTypes_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TReasonDeparture>) {
               query.SetSQL(strSQLSelectReasonDeparture_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TReasonNonWorking>) {
               query.SetSQL(strSQLSelectReasonNonWorking_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TSalaryBase>) {
               query.SetSQL(strSQLSelectSalaryBase_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TSalaryType>) {
               query.SetSQL(strSQLSelectSalaryType_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TTaxClasses>) {
               query.SetSQL(strSQLSelectTaxClasses_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TWD_Holidays>) {
               query.SetSQL(strSQLSelectWD_Holidays_Detail);
               query.Set("keyCalendarDay", key_val.CalendarDay());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TWD_Months>) {
               query.SetSQL(strSQLSelectWD_Months_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TWD_NonWorking>) {
               query.SetSQL(strSQLSelectWD_NonWorking_Detail);
               query.Set("keyID", key_val.ID());
               query.Set("keyStartAt", key_val.StartAt());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TWD_Weekdays>) {
               query.SetSQL(strSQLSelectWD_Weekdays_Detail);
               query.Set("keyID", key_val.ID());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TWD_Workdays>) {
               query.SetSQL(strSQLSelectWD_Workdays_Detail);
               query.Set("keyCalendarDay", key_val.CalendarDay());
               }
            else if constexpr (std::is_same_v<data_ty, myHR::TWorkingTime>) {
               query.SetSQL(strSQLSelectWorkingTime_Detail);
               query.Set("keyID", key_val.ID());
               query.Set("keyStartingTime", key_val.StartingTime());
               }
            else static_assert(own::always_false<data_ty>, "unexpected datatype for this class");

            if(query.Execute(), query.First();!query.IsEof()) [[likely]] {
               auto retval = GetTuple<data_ty>(query);
               if(query.Next(); !query.IsEof()) [[unlikely]] {
                  std::ostringstream os1, os2;
                  os1 << "error while reading data for " << typeid(retval).name();
                  os2 << "couldn't read unique data for primary key element\n";
                  key_val.write(os2);
                  throw TMy_Db_Exception(os1.str(), os2.str(), database.Status(), query.GetSQL());
                  }
               else return retval;
               }
            else return {};
         }

      template <my_datacontainer data_ty>
      data_ty Read() {
         data_ty data;
         using used_type = own::used_type_t<data_ty>;

         auto query = database.CreateQuery();
            if constexpr (std::is_same_v<used_type, myCorporate::TAddress>) {
               query.SetSQL(strSQLSelectAddress_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TAddressTypes>) {
               query.SetSQL(strSQLSelectAddressTypes_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TBanking>) {
               query.SetSQL(strSQLSelectBanking_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TBankingTypes>) {
               query.SetSQL(strSQLSelectBankingTypes_All);
               }
            else if constexpr (std::is_same_v<used_type, mySales::TContacts>) {
               query.SetSQL(strSQLSelectContacts_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TCorporateForm>) {
               query.SetSQL(strSQLSelectCorporateForm_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TCountries>) {
               query.SetSQL(strSQLSelectCountries_All);
               }
            else if constexpr (std::is_same_v<used_type, mySales::TCustClassification>) {
               query.SetSQL(strSQLSelectCustClassification_All);
               }
            else if constexpr (std::is_same_v<used_type, mySales::TCustLiaison>) {
               query.SetSQL(strSQLSelectCustLiaison_All);
               }
            else if constexpr (std::is_same_v<used_type, mySales::TCustomers>) {
               query.SetSQL(strSQLSelectCustomers_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TDepartments>) {
               query.SetSQL(strSQLSelectDepartments_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TEmployees>) {
               query.SetSQL(strSQLSelectEmployees_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TFamilyStatus>) {
               query.SetSQL(strSQLSelectFamilyStatus_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TFamilyTypes>) {
               query.SetSQL(strSQLSelectFamilyTypes_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TFormOfAddress>) {
               query.SetSQL(strSQLSelectFormOfAddress_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TInternet>) {
               query.SetSQL(strSQLSelectInternet_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TInternetTypes>) {
               query.SetSQL(strSQLSelectInternetTypes_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TJobPositions>) {
               query.SetSQL(strSQLSelectJobPositions_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TPerson>) {
               query.SetSQL(strSQLSelectPerson_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TPhone>) {
               query.SetSQL(strSQLSelectPhone_All);
               }
            else if constexpr (std::is_same_v<used_type, myCorporate::TPhonesTypes>) {
               query.SetSQL(strSQLSelectPhonesTypes_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TReasonDeparture>) {
               query.SetSQL(strSQLSelectReasonDeparture_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TReasonNonWorking>) {
               query.SetSQL(strSQLSelectReasonNonWorking_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TSalaryBase>) {
               query.SetSQL(strSQLSelectSalaryBase_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TSalaryType>) {
               query.SetSQL(strSQLSelectSalaryType_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TTaxClasses>) {
               query.SetSQL(strSQLSelectTaxClasses_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TWD_Holidays>) {
               query.SetSQL(strSQLSelectWD_Holidays_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TWD_Months>) {
               query.SetSQL(strSQLSelectWD_Months_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TWD_NonWorking>) {
               query.SetSQL(strSQLSelectWD_NonWorking_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TWD_Weekdays>) {
               query.SetSQL(strSQLSelectWD_Weekdays_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TWD_Workdays>) {
               query.SetSQL(strSQLSelectWD_Workdays_All);
               }
            else if constexpr (std::is_same_v<used_type, myHR::TWorkingTime>) {
               query.SetSQL(strSQLSelectWorkingTime_All);
               }
            else static_assert(own::always_false<used_type>, "unexpected datatype for this class");

            for (query.Execute(), query.First(); !query.IsEof(); query.Next()) {
               auto dataset = GetTuple<used_type>(query);
               if constexpr (own::is_vector<data_ty>::value) {
                  data.emplace_back(std::move(dataset));
                  }
               else  if constexpr (own::is_set<data_ty>::value) {
                  data.emplace(std::move(dataset));
                  }
               else if constexpr (own::is_map<data_ty>::value) {
                  auto keyval = dataset.GetKey();
                  data.emplace(std::move(keyval), std::move(dataset));
                  }
               else {
                  static_assert(own::always_false<data_ty>::value, "unexpected container type");
                  }
               }
            return data;
            }

      template <my_datacontainer data_ty>
      data_ty Read(std::string const& strSQL, my_db_params const& params = {}) {
         data_ty data;
         using used_type = own::used_type_t<data_ty>;

         auto query = database.CreateQuery();
         query.SetSQL(strSQL);
         query.Set(params);

         for (query.Execute(), query.First(); !query.IsEof(); query.Next()) {
            auto dataset = GetTuple<used_type>(query);
            if constexpr (own::is_vector<data_ty>::value) {
               data.emplace_back(std::move(dataset));
               }
            else  if constexpr (own::is_set<data_ty>::value) {
               data.emplace(std::move(dataset));
               }
            else if constexpr (own::is_map<data_ty>::value) {
               auto keyval = dataset.GetKey();
               data.emplace(std::move(keyval), std::move(dataset));
               }
            else {
               static_assert(own::always_false<data_ty>::value, "unexpected container type");
               }
            }
         return data;
         }

      template <my_dataclasses data_ty>
      void Process(data_ty::func_ty func, std::string const& strSQL, my_db_params const& params = {}) {
         auto query = database.CreateQuery();
         query.SetSQL(strSQL);
         query.Set(params);

         for (query.Execute(), query.First(); !query.IsEof(); query.Next()) {
            func(std::move(GetTuple<data_ty>(query)));
            }
         }

   };


// data access class for the model with a simple person administration project.
class TPersonReader {
   private:
      // member to produce the data access
      concrete_db_connection database;

   public:
      TPersonReader();
      TPersonReader(TPersonReader const&) = delete;
      TPersonReader(TPersonReader&&) noexcept = delete;
      ~TPersonReader() = default;

      concrete_db_connection& GetDatabase() { return database; }
      bool IsConnectedToDatabase() const { return database.Connected(); }
      bool GetServerHasIntegratedSecurity(void) const { return database.HasIntegratedSecurity(); }
      std::string GetDatabaseInformations(void) const;
      std::pair<std::string, std::string> GetConnectionInformations(void) const;
      std::pair<bool, std::string> LoginToDb(TMyCredential && credentials);
      void LogoutFromDb(void);

      // access methods for class TAddress
      bool Read(myCorporate::TAddress::container_ty&);
      bool Read(myCorporate::TAddress::primary_key const&, myCorporate::TAddress&);

      // bool Delete(myCorporate::TAddress::primary_key const&);
      // bool Update(myCorporate::TAddress::primary_key const&, myCorporate::TAddress const&, bool = false);

      // access methods for class TAddressTypes
      bool Read(myCorporate::TAddressTypes::container_ty&);
      bool Read(myCorporate::TAddressTypes::primary_key const&, myCorporate::TAddressTypes&);

      // bool Delete(myCorporate::TAddressTypes::primary_key const&);
      // bool Update(myCorporate::TAddressTypes::primary_key const&, myCorporate::TAddressTypes const&, bool = false);

      // access methods for class TBanking
      bool Read(myCorporate::TBanking::container_ty&);
      bool Read(myCorporate::TBanking::primary_key const&, myCorporate::TBanking&);

      // bool Delete(myCorporate::TBanking::primary_key const&);
      // bool Update(myCorporate::TBanking::primary_key const&, myCorporate::TBanking const&, bool = false);

      // access methods for class TBankingTypes
      bool Read(myCorporate::TBankingTypes::container_ty&);
      bool Read(myCorporate::TBankingTypes::primary_key const&, myCorporate::TBankingTypes&);

      // bool Delete(myCorporate::TBankingTypes::primary_key const&);
      // bool Update(myCorporate::TBankingTypes::primary_key const&, myCorporate::TBankingTypes const&, bool = false);

      // access methods for class TContacts
      bool Read(mySales::TContacts::container_ty&);
      bool Read(mySales::TContacts::primary_key const&, mySales::TContacts&);

      // bool Delete(mySales::TContacts::primary_key const&);
      // bool Update(mySales::TContacts::primary_key const&, mySales::TContacts const&, bool = false);

      // access methods for class TCorporateForm
      bool Read(myCorporate::TCorporateForm::container_ty&);
      bool Read(myCorporate::TCorporateForm::primary_key const&, myCorporate::TCorporateForm&);

      // bool Delete(myCorporate::TCorporateForm::primary_key const&);
      // bool Update(myCorporate::TCorporateForm::primary_key const&, myCorporate::TCorporateForm const&, bool = false);

      // access methods for class TCountries
      bool Read(myCorporate::TCountries::container_ty&);
      bool Read(myCorporate::TCountries::primary_key const&, myCorporate::TCountries&);

      // bool Delete(myCorporate::TCountries::primary_key const&);
      // bool Update(myCorporate::TCountries::primary_key const&, myCorporate::TCountries const&, bool = false);

      // access methods for class TCustClassification
      bool Read(mySales::TCustClassification::container_ty&);
      bool Read(mySales::TCustClassification::primary_key const&, mySales::TCustClassification&);

      // bool Delete(mySales::TCustClassification::primary_key const&);
      // bool Update(mySales::TCustClassification::primary_key const&, mySales::TCustClassification const&, bool = false);

      // access methods for class TCustLiaison
      bool Read(mySales::TCustLiaison::container_ty&);
      bool Read(mySales::TCustLiaison::primary_key const&, mySales::TCustLiaison&);

      // bool Delete(mySales::TCustLiaison::primary_key const&);
      // bool Update(mySales::TCustLiaison::primary_key const&, mySales::TCustLiaison const&, bool = false);

      // access methods for class TCustomers
      bool Read(mySales::TCustomers::container_ty&);
      bool Read(mySales::TCustomers::primary_key const&, mySales::TCustomers&);

      // bool Delete(mySales::TCustomers::primary_key const&);
      // bool Update(mySales::TCustomers::primary_key const&, mySales::TCustomers const&, bool = false);

      // access methods for class TDepartments
      bool Read(myHR::TDepartments::container_ty&);
      bool Read(myHR::TDepartments::primary_key const&, myHR::TDepartments&);

      // bool Delete(myHR::TDepartments::primary_key const&);
      // bool Update(myHR::TDepartments::primary_key const&, myHR::TDepartments const&, bool = false);

      // access methods for class TEmployees
      bool Read(myHR::TEmployees::container_ty&);
      bool Read(myHR::TEmployees::primary_key const&, myHR::TEmployees&);

      // bool Delete(myHR::TEmployees::primary_key const&);
      // bool Update(myHR::TEmployees::primary_key const&, myHR::TEmployees const&, bool = false);

      // access methods for class TFamilyStatus
      bool Read(myCorporate::TFamilyStatus::container_ty&);
      bool Read(myCorporate::TFamilyStatus::primary_key const&, myCorporate::TFamilyStatus&);

      // bool Delete(myCorporate::TFamilyStatus::primary_key const&);
      // bool Update(myCorporate::TFamilyStatus::primary_key const&, myCorporate::TFamilyStatus const&, bool = false);

      // access methods for class TFamilyTypes
      bool Read(myCorporate::TFamilyTypes::container_ty&);
      bool Read(myCorporate::TFamilyTypes::primary_key const&, myCorporate::TFamilyTypes&);

      // bool Delete(myCorporate::TFamilyTypes::primary_key const&);
      // bool Update(myCorporate::TFamilyTypes::primary_key const&, myCorporate::TFamilyTypes const&, bool = false);

      // access methods for class TFormOfAddress
      bool Read(myCorporate::TFormOfAddress::container_ty&);
      bool Read(myCorporate::TFormOfAddress::primary_key const&, myCorporate::TFormOfAddress&);

      // bool Delete(myCorporate::TFormOfAddress::primary_key const&);
      // bool Update(myCorporate::TFormOfAddress::primary_key const&, myCorporate::TFormOfAddress const&, bool = false);

      // access methods for class TInternet
      bool Read(myCorporate::TInternet::container_ty&);
      bool Read(myCorporate::TInternet::primary_key const&, myCorporate::TInternet&);

      // bool Delete(myCorporate::TInternet::primary_key const&);
      // bool Update(myCorporate::TInternet::primary_key const&, myCorporate::TInternet const&, bool = false);

      // access methods for class TInternetTypes
      bool Read(myCorporate::TInternetTypes::container_ty&);
      bool Read(myCorporate::TInternetTypes::primary_key const&, myCorporate::TInternetTypes&);

      // bool Delete(myCorporate::TInternetTypes::primary_key const&);
      // bool Update(myCorporate::TInternetTypes::primary_key const&, myCorporate::TInternetTypes const&, bool = false);

      // access methods for class TJobPositions
      bool Read(myHR::TJobPositions::container_ty&);
      bool Read(myHR::TJobPositions::primary_key const&, myHR::TJobPositions&);

      // bool Delete(myHR::TJobPositions::primary_key const&);
      // bool Update(myHR::TJobPositions::primary_key const&, myHR::TJobPositions const&, bool = false);

      // access methods for class TPerson
      bool Read(myCorporate::TPerson::container_ty&);
      bool Read(myCorporate::TPerson::primary_key const&, myCorporate::TPerson&);

      // bool Delete(myCorporate::TPerson::primary_key const&);
      // bool Update(myCorporate::TPerson::primary_key const&, myCorporate::TPerson const&, bool = false);

      // access methods for class TPhone
      bool Read(myCorporate::TPhone::container_ty&);
      bool Read(myCorporate::TPhone::primary_key const&, myCorporate::TPhone&);

      // bool Delete(myCorporate::TPhone::primary_key const&);
      // bool Update(myCorporate::TPhone::primary_key const&, myCorporate::TPhone const&, bool = false);

      // access methods for class TPhonesTypes
      bool Read(myCorporate::TPhonesTypes::container_ty&);
      bool Read(myCorporate::TPhonesTypes::primary_key const&, myCorporate::TPhonesTypes&);

      // bool Delete(myCorporate::TPhonesTypes::primary_key const&);
      // bool Update(myCorporate::TPhonesTypes::primary_key const&, myCorporate::TPhonesTypes const&, bool = false);

      // access methods for class TReasonDeparture
      bool Read(myHR::TReasonDeparture::container_ty&);
      bool Read(myHR::TReasonDeparture::primary_key const&, myHR::TReasonDeparture&);

      // bool Delete(myHR::TReasonDeparture::primary_key const&);
      // bool Update(myHR::TReasonDeparture::primary_key const&, myHR::TReasonDeparture const&, bool = false);

      // access methods for class TReasonNonWorking
      bool Read(myHR::TReasonNonWorking::container_ty&);
      bool Read(myHR::TReasonNonWorking::primary_key const&, myHR::TReasonNonWorking&);

      // bool Delete(myHR::TReasonNonWorking::primary_key const&);
      // bool Update(myHR::TReasonNonWorking::primary_key const&, myHR::TReasonNonWorking const&, bool = false);

      // access methods for class TSalaryBase
      bool Read(myHR::TSalaryBase::container_ty&);
      bool Read(myHR::TSalaryBase::primary_key const&, myHR::TSalaryBase&);

      // bool Delete(myHR::TSalaryBase::primary_key const&);
      // bool Update(myHR::TSalaryBase::primary_key const&, myHR::TSalaryBase const&, bool = false);

      // access methods for class TSalaryType
      bool Read(myHR::TSalaryType::container_ty&);
      bool Read(myHR::TSalaryType::primary_key const&, myHR::TSalaryType&);

      // bool Delete(myHR::TSalaryType::primary_key const&);
      // bool Update(myHR::TSalaryType::primary_key const&, myHR::TSalaryType const&, bool = false);

      // access methods for class TTaxClasses
      bool Read(myHR::TTaxClasses::container_ty&);
      bool Read(myHR::TTaxClasses::primary_key const&, myHR::TTaxClasses&);

      // bool Delete(myHR::TTaxClasses::primary_key const&);
      // bool Update(myHR::TTaxClasses::primary_key const&, myHR::TTaxClasses const&, bool = false);

      // access methods for class TWD_Holidays
      bool Read(myHR::TWD_Holidays::container_ty&);
      bool Read(myHR::TWD_Holidays::primary_key const&, myHR::TWD_Holidays&);

      // bool Delete(myHR::TWD_Holidays::primary_key const&);
      // bool Update(myHR::TWD_Holidays::primary_key const&, myHR::TWD_Holidays const&, bool = false);

      // access methods for class TWD_Months
      bool Read(myHR::TWD_Months::container_ty&);
      bool Read(myHR::TWD_Months::primary_key const&, myHR::TWD_Months&);

      // bool Delete(myHR::TWD_Months::primary_key const&);
      // bool Update(myHR::TWD_Months::primary_key const&, myHR::TWD_Months const&, bool = false);

      // access methods for class TWD_NonWorking
      bool Read(myHR::TWD_NonWorking::container_ty&);
      bool Read(myHR::TWD_NonWorking::primary_key const&, myHR::TWD_NonWorking&);

      // bool Delete(myHR::TWD_NonWorking::primary_key const&);
      // bool Update(myHR::TWD_NonWorking::primary_key const&, myHR::TWD_NonWorking const&, bool = false);

      // access methods for class TWD_Weekdays
      bool Read(myHR::TWD_Weekdays::container_ty&);
      bool Read(myHR::TWD_Weekdays::primary_key const&, myHR::TWD_Weekdays&);

      // bool Delete(myHR::TWD_Weekdays::primary_key const&);
      // bool Update(myHR::TWD_Weekdays::primary_key const&, myHR::TWD_Weekdays const&, bool = false);

      // access methods for class TWD_Workdays
      bool Read(myHR::TWD_Workdays::container_ty&);
      bool Read(myHR::TWD_Workdays::primary_key const&, myHR::TWD_Workdays&);

      // bool Delete(myHR::TWD_Workdays::primary_key const&);
      // bool Update(myHR::TWD_Workdays::primary_key const&, myHR::TWD_Workdays const&, bool = false);

      // access methods for class TWorkingTime
      bool Read(myHR::TWorkingTime::container_ty&);
      bool Read(myHR::TWorkingTime::primary_key const&, myHR::TWorkingTime&);

      // bool Delete(myHR::TWorkingTime::primary_key const&);
      // bool Update(myHR::TWorkingTime::primary_key const&, myHR::TWorkingTime const&, bool = false);

   };

} // close namespace reader
