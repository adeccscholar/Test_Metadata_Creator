/*
* Project: model with a simple person administration
* Definition of the persistence class TPersonReader
* Date: 17.03.2024 20:08:25,666  file created with adecc Scholar metadata generator
* copyright (c) adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#pragma once

#include <vector>
#include <map>

#include <System\Corporate\Address.h>
#include <System\Corporate\AddressTypes.h>
#include <System\Corporate\Banking.h>
#include <System\Corporate\BankingTypes.h>
#include <System\Sales\Contacts.h>
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
#include <System/HR\SalaryType.h>
#include <System\HR\TaxClasses.h>
#include <System\HR\WD_Holidays.h>
#include <System\HR\WD_Months.h>
#include <System\HR\WD_NonWorking.h>
#include <System\HR\WD_Weekdays.h>
#include <System\HR\WD_Workdays.h>
#include <System\HR\WorkingTime.h>

#include <adecc_Database/MyDatabase.h>

#include <string>
#include <memory>

namespace reader {

// data access class for the model with a simple person administration project.
class TPersonReader {
   private:
      using concrete_db_server = TMyMSSQL;
      using concrete_framework = TMyQtDb<concrete_db_server>;
      using concrete_db_connection = TMyDatabase<TMyQtDb, concrete_db_server>;
      using concrete_query = TMyQuery<TMyQtDb, concrete_db_server>;

      // member to produce the data access
      concrete_db_connection database;

   public:
      TPersonReader();
      TPersonReader(TPersonReader const&) = delete;
      TPersonReader(TPersonReader&&) noexcept = delete;
      ~TPersonReader() = default;

      bool IsConnectedToDatabase() const { return database.Connected(); }
      bool GetServerHasIntegratedSecurity(void) const { return database.HasIntegratedSecurity(); }
      std::string GetDatabaseInformations(void) const;
      std::pair<std::string, std::string> GetConnectionInformations(void) const;
      std::pair<bool, std::string> LoginToDb(TMyCredential && credentials);
      void LogoutFromDb(void);

      // access methods for class TAddress
      bool Read(myCorporate::TAddress::container_ty&);
      bool Read(myCorporate::TAddress::primary_key const&, myCorporate::TAddress&);

      // access methods for class TAddressTypes
      bool Read(myCorporate::TAddressTypes::container_ty&);
      bool Read(myCorporate::TAddressTypes::primary_key const&, myCorporate::TAddressTypes&);

      // access methods for class TBanking
      bool Read(myCorporate::TBanking::container_ty&);
      bool Read(myCorporate::TBanking::primary_key const&, myCorporate::TBanking&);

      // access methods for class TBankingTypes
      bool Read(myCorporate::TBankingTypes::container_ty&);
      bool Read(myCorporate::TBankingTypes::primary_key const&, myCorporate::TBankingTypes&);

      // access methods for class TContacts
      bool Read(mySales::TContacts::container_ty&);
      bool Read(mySales::TContacts::primary_key const&, mySales::TContacts&);

      // access methods for class TCountries
      bool Read(myCorporate::TCountries::container_ty&);
      bool Read(myCorporate::TCountries::primary_key const&, myCorporate::TCountries&);

      // access methods for class TCustClassification
      bool Read(mySales::TCustClassification::container_ty&);
      bool Read(mySales::TCustClassification::primary_key const&, mySales::TCustClassification&);

      // access methods for class TCustLiaison
      bool Read(mySales::TCustLiaison::container_ty&);
      bool Read(mySales::TCustLiaison::primary_key const&, mySales::TCustLiaison&);

      // access methods for class TCustomers
      bool Read(mySales::TCustomers::container_ty&);
      bool Read(mySales::TCustomers::primary_key const&, mySales::TCustomers&);

      // access methods for class TDepartments
      bool Read(myHR::TDepartments::container_ty&);
      bool Read(myHR::TDepartments::primary_key const&, myHR::TDepartments&);

      // access methods for class TEmployees
      bool Read(myHR::TEmployees::container_ty&);
      bool Read(myHR::TEmployees::primary_key const&, myHR::TEmployees&);

      // access methods for class TFamilyStatus
      bool Read(myCorporate::TFamilyStatus::container_ty&);
      bool Read(myCorporate::TFamilyStatus::primary_key const&, myCorporate::TFamilyStatus&);

      // access methods for class TFamilyTypes
      bool Read(myCorporate::TFamilyTypes::container_ty&);
      bool Read(myCorporate::TFamilyTypes::primary_key const&, myCorporate::TFamilyTypes&);

      // access methods for class TFormOfAddress
      bool Read(myCorporate::TFormOfAddress::container_ty&);
      bool Read(myCorporate::TFormOfAddress::primary_key const&, myCorporate::TFormOfAddress&);

      // access methods for class TInternet
      bool Read(myCorporate::TInternet::container_ty&);
      bool Read(myCorporate::TInternet::primary_key const&, myCorporate::TInternet&);

      // access methods for class TInternetTypes
      bool Read(myCorporate::TInternetTypes::container_ty&);
      bool Read(myCorporate::TInternetTypes::primary_key const&, myCorporate::TInternetTypes&);

      // access methods for class TJobPositions
      bool Read(myHR::TJobPositions::container_ty&);
      bool Read(myHR::TJobPositions::primary_key const&, myHR::TJobPositions&);

      // access methods for class TPerson
      bool Read(myCorporate::TPerson::container_ty&);
      bool Read(myCorporate::TPerson::primary_key const&, myCorporate::TPerson&);

      // access methods for class TPhone
      bool Read(myCorporate::TPhone::container_ty&);
      bool Read(myCorporate::TPhone::primary_key const&, myCorporate::TPhone&);

      // access methods for class TPhonesTypes
      bool Read(myCorporate::TPhonesTypes::container_ty&);
      bool Read(myCorporate::TPhonesTypes::primary_key const&, myCorporate::TPhonesTypes&);

      // access methods for class TReasonDeparture
      bool Read(myHR::TReasonDeparture::container_ty&);
      bool Read(myHR::TReasonDeparture::primary_key const&, myHR::TReasonDeparture&);

      // access methods for class TReasonNonWorking
      bool Read(myHR::TReasonNonWorking::container_ty&);
      bool Read(myHR::TReasonNonWorking::primary_key const&, myHR::TReasonNonWorking&);

      // access methods for class TSalaryBase
      bool Read(myHR::TSalaryBase::container_ty&);
      bool Read(myHR::TSalaryBase::primary_key const&, myHR::TSalaryBase&);

      // access methods for class TSalaryType
      bool Read(myHR::TSalaryType::container_ty&);
      bool Read(myHR::TSalaryType::primary_key const&, myHR::TSalaryType&);

      // access methods for class TTaxClasses
      bool Read(myHR::TTaxClasses::container_ty&);
      bool Read(myHR::TTaxClasses::primary_key const&, myHR::TTaxClasses&);

      // access methods for class TWD_Holidays
      bool Read(myHR::TWD_Holidays::container_ty&);
      bool Read(myHR::TWD_Holidays::primary_key const&, myHR::TWD_Holidays&);

      // access methods for class TWD_Months
      bool Read(myHR::TWD_Months::container_ty&);
      bool Read(myHR::TWD_Months::primary_key const&, myHR::TWD_Months&);

      // access methods for class TWD_NonWorking
      bool Read(myHR::TWD_NonWorking::container_ty&);
      bool Read(myHR::TWD_NonWorking::primary_key const&, myHR::TWD_NonWorking&);

      // access methods for class TWD_Weekdays
      bool Read(myHR::TWD_Weekdays::container_ty&);
      bool Read(myHR::TWD_Weekdays::primary_key const&, myHR::TWD_Weekdays&);

      // access methods for class TWD_Workdays
      bool Read(myHR::TWD_Workdays::container_ty&);
      bool Read(myHR::TWD_Workdays::primary_key const&, myHR::TWD_Workdays&);

      // access methods for class TWorkingTime
      bool Read(myHR::TWorkingTime::container_ty&);
      bool Read(myHR::TWorkingTime::primary_key const&, myHR::TWorkingTime&);

   };

} // close namespace reader
