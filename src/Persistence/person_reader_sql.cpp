/*
* Project: model with a simple person administration
* Implementation of sql statement for access with class TPersonReader
* Date: 22.04.2025 22:26:57,003  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include <Persistence\person_reader_sql.h>

namespace reader {

// --------------------------------------------------------------------
//   Statements for table / view: Address
// --------------------------------------------------------------------
const std::string strSQLSelectAddress_All =
     "SELECT ID,AddressType,Zipcode,City,Street,StreetNumber,Country\n"
     "FROM dbo.Address";

const std::string strSQLSelectAddress_Detail =
     "SELECT ID,AddressType,Zipcode,City,Street,StreetNumber,Country\n"
     "FROM dbo.Address\n"
     "WHERE ID          = :keyID AND\n"
     "      AddressType = :keyAddressType";

const std::string strSQLSelectAddress_IdxAddress_City_Street =
     "SELECT ID,AddressType,Zipcode,City,Street,StreetNumber,Country\n"
     "FROM dbo.Address\n"
     "WHERE City   LIKE :keyCity AND\n"
     "      Street LIKE :keyStreet";

const std::string strSQLSelectAddress_RefAddress2Person =
     "SELECT ID, AddressType, Zipcode, City, Street, StreetNumber, Country\n"
     "FROM dbo.Address\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectPerson_RevRefAddress2Person =
     "SELECT ID, Name, FirstName, Birthname, FormOfAddress, FamilyStatus, \n"
     "       FamilyStatusSince, Birthday, Notes, FullName\n"
     "FROM dbo.Person\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectAddress_RefAddress2AddressType =
     "SELECT ID, AddressType, Zipcode, City, Street, StreetNumber, Country\n"
     "FROM dbo.Address\n"
     "WHERE AddressType = :keyID";

const std::string strSQLSelectAddressTypes_RevRefAddress2AddressType =
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.AddressTypes\n"
     "WHERE ID = :keyAddressType";

const std::string strSQLSelectAddress_RefAddress2Countries =
     "SELECT ID, AddressType, Zipcode, City, Street, StreetNumber, Country\n"
     "FROM dbo.Address\n"
     "WHERE Country = :keyID";

const std::string strSQLSelectCountries_RevRefAddress2Countries =
     "SELECT ID, Denotation, Abbreviation, Description, CountryDialing, \n"
     "       ISO_Code, IsEU, Capital, Currency, Notes, UrgentValue\n"
     "FROM dbo.Countries\n"
     "WHERE ID = :keyCountry";

const std::string strSQLInsertAddress =
     "INSERT INTO dbo.Address \n"
     "       (ID,AddressType,Zipcode,City,Street,StreetNumber,Country)\n"
     "VALUES (:ID,:AddressType,:Zipcode,:City,:Street,:StreetNumber,\n"
     "        :Country)";

const std::string strSQLUpdateAddress_WithPrim =
     "UPDATE dbo.Address\n"
     "SET   ID           = :ID,\n"
     "      AddressType  = :AddressType,\n"
     "      Zipcode      = :Zipcode,\n"
     "      City         = :City,\n"
     "      Street       = :Street,\n"
     "      StreetNumber = :StreetNumber,\n"
     "      Country      = :Country\n"
     "WHERE ID          = :keyID AND\n"
     "      AddressType = :keyAddressType)";

const std::string strSQLUpdateAddress_WithoutPrim =
     "UPDATE dbo.Address\n"
     "SET   Zipcode      = :Zipcode,\n"
     "      City         = :City,\n"
     "      Street       = :Street,\n"
     "      StreetNumber = :StreetNumber,\n"
     "      Country      = :Country\n"
     "WHERE ID          = :keyID AND\n"
     "      AddressType = :keyAddressType)";

const std::string strSQLDeleteAddress_All =
     "DELETE FROM dbo.Address";

const std::string strSQLDeleteAddress_Detail =
     "DELETE FROM dbo.Address\n"
     "WHERE ID          = :keyID AND\n"
     "      AddressType = :keyAddressType";


// --------------------------------------------------------------------
//   Statements for table / view: AddressTypes
// --------------------------------------------------------------------
const std::string strSQLSelectAddressTypes_All =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.AddressTypes";

const std::string strSQLSelectAddressTypes_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.AddressTypes\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectAddressTypes_UnqAddressType_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.AddressTypes\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLInsertAddressTypes =
     "INSERT INTO dbo.AddressTypes \n"
     "       (ID,Denotation,Abbreviation,Description,Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:Notes,:UrgentValue)";

const std::string strSQLUpdateAddressTypes_WithPrim =
     "UPDATE dbo.AddressTypes\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateAddressTypes_WithoutPrim =
     "UPDATE dbo.AddressTypes\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteAddressTypes_All =
     "DELETE FROM dbo.AddressTypes";

const std::string strSQLDeleteAddressTypes_Detail =
     "DELETE FROM dbo.AddressTypes\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Banking
// --------------------------------------------------------------------
const std::string strSQLSelectBanking_All =
     "SELECT ID,BankingType,BankName,IBAN,BIC,BankOwner,Country\n"
     "FROM dbo.Banking";

const std::string strSQLSelectBanking_Detail =
     "SELECT ID,BankingType,BankName,IBAN,BIC,BankOwner,Country\n"
     "FROM dbo.Banking\n"
     "WHERE ID          = :keyID AND\n"
     "      BankingType = :keyBankingType";

const std::string strSQLSelectBanking_IdxBanking_IBAN =
     "SELECT ID,BankingType,BankName,IBAN,BIC,BankOwner,Country\n"
     "FROM dbo.Banking\n"
     "WHERE IBAN LIKE :keyIBAN";

const std::string strSQLSelectBanking_IdxBanking_BIC =
     "SELECT ID,BankingType,BankName,IBAN,BIC,BankOwner,Country\n"
     "FROM dbo.Banking\n"
     "WHERE BIC LIKE :keyBIC";

const std::string strSQLSelectBanking_RefBanking2Person =
     "SELECT ID, BankingType, BankName, IBAN, BIC, BankOwner, Country\n"
     "FROM dbo.Banking\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectPerson_RevRefBanking2Person =
     "SELECT ID, Name, FirstName, Birthname, FormOfAddress, FamilyStatus, \n"
     "       FamilyStatusSince, Birthday, Notes, FullName\n"
     "FROM dbo.Person\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectBanking_RefBanking2Type =
     "SELECT ID, BankingType, BankName, IBAN, BIC, BankOwner, Country\n"
     "FROM dbo.Banking\n"
     "WHERE BankingType = :keyID";

const std::string strSQLSelectBankingTypes_RevRefBanking2Type =
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.BankingTypes\n"
     "WHERE ID = :keyBankingType";

const std::string strSQLSelectBanking_RefBanking2Countries =
     "SELECT ID, BankingType, BankName, IBAN, BIC, BankOwner, Country\n"
     "FROM dbo.Banking\n"
     "WHERE Country = :keyID";

const std::string strSQLSelectCountries_RevRefBanking2Countries =
     "SELECT ID, Denotation, Abbreviation, Description, CountryDialing, \n"
     "       ISO_Code, IsEU, Capital, Currency, Notes, UrgentValue\n"
     "FROM dbo.Countries\n"
     "WHERE ID = :keyCountry";

const std::string strSQLInsertBanking =
     "INSERT INTO dbo.Banking \n"
     "       (ID,BankingType,BankName,IBAN,BIC,BankOwner,Country)\n"
     "VALUES (:ID,:BankingType,:BankName,:IBAN,:BIC,:BankOwner,:Country)";

const std::string strSQLUpdateBanking_WithPrim =
     "UPDATE dbo.Banking\n"
     "SET   ID          = :ID,\n"
     "      BankingType = :BankingType,\n"
     "      BankName    = :BankName,\n"
     "      IBAN        = :IBAN,\n"
     "      BIC         = :BIC,\n"
     "      BankOwner   = :BankOwner,\n"
     "      Country     = :Country\n"
     "WHERE ID          = :keyID AND\n"
     "      BankingType = :keyBankingType)";

const std::string strSQLUpdateBanking_WithoutPrim =
     "UPDATE dbo.Banking\n"
     "SET   BankName  = :BankName,\n"
     "      IBAN      = :IBAN,\n"
     "      BIC       = :BIC,\n"
     "      BankOwner = :BankOwner,\n"
     "      Country   = :Country\n"
     "WHERE ID          = :keyID AND\n"
     "      BankingType = :keyBankingType)";

const std::string strSQLDeleteBanking_All =
     "DELETE FROM dbo.Banking";

const std::string strSQLDeleteBanking_Detail =
     "DELETE FROM dbo.Banking\n"
     "WHERE ID          = :keyID AND\n"
     "      BankingType = :keyBankingType";


// --------------------------------------------------------------------
//   Statements for table / view: BankingTypes
// --------------------------------------------------------------------
const std::string strSQLSelectBankingTypes_All =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.BankingTypes";

const std::string strSQLSelectBankingTypes_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.BankingTypes\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectBankingTypes_UnqBankingTypes_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.BankingTypes\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLInsertBankingTypes =
     "INSERT INTO dbo.BankingTypes \n"
     "       (ID,Denotation,Abbreviation,Description,Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:Notes,:UrgentValue)";

const std::string strSQLUpdateBankingTypes_WithPrim =
     "UPDATE dbo.BankingTypes\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateBankingTypes_WithoutPrim =
     "UPDATE dbo.BankingTypes\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteBankingTypes_All =
     "DELETE FROM dbo.BankingTypes";

const std::string strSQLDeleteBankingTypes_Detail =
     "DELETE FROM dbo.BankingTypes\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Contacts
// --------------------------------------------------------------------
const std::string strSQLSelectContacts_All =
     "SELECT ContactID,CustID,CustLiaison\n"
     "FROM dbo.Contacts";

const std::string strSQLSelectContacts_Detail =
     "SELECT ContactID,CustID,CustLiaison\n"
     "FROM dbo.Contacts\n"
     "WHERE ContactID = :keyContactID";

const std::string strSQLSelectContacts_RefContacts2Person =
     "SELECT ContactID, CustID, CustLiaison\n"
     "FROM dbo.Contacts\n"
     "WHERE ContactID = :keyID";

const std::string strSQLSelectPerson_RevRefContacts2Person =
     "SELECT ID, Name, FirstName, Birthname, FormOfAddress, FamilyStatus, \n"
     "       FamilyStatusSince, Birthday, Notes, FullName\n"
     "FROM dbo.Person\n"
     "WHERE ID = :keyContactID";

const std::string strSQLSelectContacts_RefContacts2Customer =
     "SELECT ContactID, CustID, CustLiaison\n"
     "FROM dbo.Contacts\n"
     "WHERE CustID = :keyCustID";

const std::string strSQLSelectCustomers_RevRefContacts2Customer =
     "SELECT CustID, ServiceAgent, CustClassification, LegalForm\n"
     "FROM dbo.Customers\n"
     "WHERE CustID = :keyCustID";

const std::string strSQLSelectContacts_RefContacts2Liaison =
     "SELECT ContactID, CustID, CustLiaison\n"
     "FROM dbo.Contacts\n"
     "WHERE CustLiaison = :keyID";

const std::string strSQLSelectCustLiaison_RevRefContacts2Liaison =
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.CustLiaison\n"
     "WHERE ID = :keyCustLiaison";

const std::string strSQLInsertContacts =
     "INSERT INTO dbo.Contacts \n"
     "       (ContactID,CustID,CustLiaison)\n"
     "VALUES (:ContactID,:CustID,:CustLiaison)";

const std::string strSQLUpdateContacts_WithPrim =
     "UPDATE dbo.Contacts\n"
     "SET   ContactID   = :ContactID,\n"
     "      CustID      = :CustID,\n"
     "      CustLiaison = :CustLiaison\n"
     "WHERE ContactID = :keyContactID";

const std::string strSQLUpdateContacts_WithoutPrim =
     "UPDATE dbo.Contacts\n"
     "SET   CustID      = :CustID,\n"
     "      CustLiaison = :CustLiaison\n"
     "WHERE ContactID = :keyContactID";

const std::string strSQLDeleteContacts_All =
     "DELETE FROM dbo.Contacts";

const std::string strSQLDeleteContacts_Detail =
     "DELETE FROM dbo.Contacts\n"
     "WHERE ContactID = :keyContactID";


// --------------------------------------------------------------------
//   Statements for table / view: CorporateForm
// --------------------------------------------------------------------
const std::string strSQLSelectCorporateForm_All =
     "SELECT ID,Denotation,Abbreviation,Description,IsLegalEntrity,UrgentValue\n"
     "FROM dbo.CorporateForm";

const std::string strSQLSelectCorporateForm_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,IsLegalEntrity,UrgentValue\n"
     "FROM dbo.CorporateForm\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectCorporateForm_UnqCorporateForm_Donation =
     "SELECT ID,Denotation,Abbreviation,Description,IsLegalEntrity,UrgentValue\n"
     "FROM dbo.CorporateForm\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLSelectCorporateForm_UnqCorporateForm_Abbreviation =
     "SELECT ID,Denotation,Abbreviation,Description,IsLegalEntrity,UrgentValue\n"
     "FROM dbo.CorporateForm\n"
     "WHERE ID = :keyID";

const std::string strSQLInsertCorporateForm =
     "INSERT INTO dbo.CorporateForm \n"
     "       (ID,Denotation,Abbreviation,Description,IsLegalEntrity,\n"
     "        UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:IsLegalEntrity,\n"
     "        :UrgentValue)";

const std::string strSQLUpdateCorporateForm_WithPrim =
     "UPDATE dbo.CorporateForm\n"
     "SET   ID             = :ID,\n"
     "      Denotation     = :Denotation,\n"
     "      Abbreviation   = :Abbreviation,\n"
     "      Description    = :Description,\n"
     "      IsLegalEntrity = :IsLegalEntrity,\n"
     "      UrgentValue    = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateCorporateForm_WithoutPrim =
     "UPDATE dbo.CorporateForm\n"
     "SET   Denotation     = :Denotation,\n"
     "      Abbreviation   = :Abbreviation,\n"
     "      Description    = :Description,\n"
     "      IsLegalEntrity = :IsLegalEntrity,\n"
     "      UrgentValue    = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteCorporateForm_All =
     "DELETE FROM dbo.CorporateForm";

const std::string strSQLDeleteCorporateForm_Detail =
     "DELETE FROM dbo.CorporateForm\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Countries
// --------------------------------------------------------------------
const std::string strSQLSelectCountries_All =
     "SELECT ID,Denotation,Abbreviation,Description,CountryDialing,ISO_Code,\n"
     "       IsEU,Capital,Currency,Notes,UrgentValue\n"
     "FROM dbo.Countries";

const std::string strSQLSelectCountries_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,CountryDialing,ISO_Code,\n"
     "       IsEU,Capital,Currency,Notes,UrgentValue\n"
     "FROM dbo.Countries\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectCountries_UnqCountries_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,CountryDialing,ISO_Code,\n"
     "       IsEU,Capital,Currency,Notes,UrgentValue\n"
     "FROM dbo.Countries\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLSelectCountries_UnqCountries_ISOCode =
     "SELECT ID,Denotation,Abbreviation,Description,CountryDialing,ISO_Code,\n"
     "       IsEU,Capital,Currency,Notes,UrgentValue\n"
     "FROM dbo.Countries\n"
     "WHERE ISO_Code = :keyISO_Code";

const std::string strSQLInsertCountries =
     "INSERT INTO dbo.Countries \n"
     "       (ID,Denotation,Abbreviation,Description,CountryDialing,\n"
     "        ISO_Code,IsEU,Capital,Currency,Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:CountryDialing,\n"
     "        :ISO_Code,:IsEU,:Capital,:Currency,:Notes,:UrgentValue)";

const std::string strSQLUpdateCountries_WithPrim =
     "UPDATE dbo.Countries\n"
     "SET   ID             = :ID,\n"
     "      Denotation     = :Denotation,\n"
     "      Abbreviation   = :Abbreviation,\n"
     "      Description    = :Description,\n"
     "      CountryDialing = :CountryDialing,\n"
     "      ISO_Code       = :ISO_Code,\n"
     "      IsEU           = :IsEU,\n"
     "      Capital        = :Capital,\n"
     "      Currency       = :Currency,\n"
     "      Notes          = :Notes,\n"
     "      UrgentValue    = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateCountries_WithoutPrim =
     "UPDATE dbo.Countries\n"
     "SET   Denotation     = :Denotation,\n"
     "      Abbreviation   = :Abbreviation,\n"
     "      Description    = :Description,\n"
     "      CountryDialing = :CountryDialing,\n"
     "      ISO_Code       = :ISO_Code,\n"
     "      IsEU           = :IsEU,\n"
     "      Capital        = :Capital,\n"
     "      Currency       = :Currency,\n"
     "      Notes          = :Notes,\n"
     "      UrgentValue    = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteCountries_All =
     "DELETE FROM dbo.Countries";

const std::string strSQLDeleteCountries_Detail =
     "DELETE FROM dbo.Countries\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: CustClassification
// --------------------------------------------------------------------
const std::string strSQLSelectCustClassification_All =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.CustClassification";

const std::string strSQLSelectCustClassification_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.CustClassification\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectCustClassification_UnqCustClass_Donation =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.CustClassification\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLInsertCustClassification =
     "INSERT INTO dbo.CustClassification \n"
     "       (ID,Denotation,Abbreviation,Description,Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:Notes,:UrgentValue)";

const std::string strSQLUpdateCustClassification_WithPrim =
     "UPDATE dbo.CustClassification\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateCustClassification_WithoutPrim =
     "UPDATE dbo.CustClassification\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteCustClassification_All =
     "DELETE FROM dbo.CustClassification";

const std::string strSQLDeleteCustClassification_Detail =
     "DELETE FROM dbo.CustClassification\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: CustLiaison
// --------------------------------------------------------------------
const std::string strSQLSelectCustLiaison_All =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.CustLiaison";

const std::string strSQLSelectCustLiaison_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.CustLiaison\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectCustLiaison_UnqCustLiaison_Donation =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.CustLiaison\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLInsertCustLiaison =
     "INSERT INTO dbo.CustLiaison \n"
     "       (ID,Denotation,Abbreviation,Description,Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:Notes,:UrgentValue)";

const std::string strSQLUpdateCustLiaison_WithPrim =
     "UPDATE dbo.CustLiaison\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateCustLiaison_WithoutPrim =
     "UPDATE dbo.CustLiaison\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteCustLiaison_All =
     "DELETE FROM dbo.CustLiaison";

const std::string strSQLDeleteCustLiaison_Detail =
     "DELETE FROM dbo.CustLiaison\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Customers
// --------------------------------------------------------------------
const std::string strSQLSelectCustomers_All =
     "SELECT CustID,ServiceAgent,CustClassification,LegalForm\n"
     "FROM dbo.Customers";

const std::string strSQLSelectCustomers_Detail =
     "SELECT CustID,ServiceAgent,CustClassification,LegalForm\n"
     "FROM dbo.Customers\n"
     "WHERE CustID = :keyCustID";

const std::string strSQLSelectCustomers_RefCustomers2Person =
     "SELECT CustID, ServiceAgent, CustClassification, LegalForm\n"
     "FROM dbo.Customers\n"
     "WHERE CustID = :keyID";

const std::string strSQLSelectPerson_RevRefCustomers2Person =
     "SELECT ID, Name, FirstName, Birthname, FormOfAddress, FamilyStatus, \n"
     "       FamilyStatusSince, Birthday, Notes, FullName\n"
     "FROM dbo.Person\n"
     "WHERE ID = :keyCustID";

const std::string strSQLSelectCustomers_RefCustomers2Classification =
     "SELECT CustID, ServiceAgent, CustClassification, LegalForm\n"
     "FROM dbo.Customers\n"
     "WHERE CustClassification = :keyID";

const std::string strSQLSelectCustClassification_RevRefCustomers2Classification =
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.CustClassification\n"
     "WHERE ID = :keyCustClassification";

const std::string strSQLSelectCustomers_RefCustomers2Employees_SA =
     "SELECT CustID, ServiceAgent, CustClassification, LegalForm\n"
     "FROM dbo.Customers\n"
     "WHERE ServiceAgent = :keyEmployID";

const std::string strSQLSelectEmployees_RevRefCustomers2Employees_SA =
     "SELECT EmployID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, \n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, \n"
     "       Department, TaxNumber, SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE EmployID = :keyServiceAgent";

const std::string strSQLSelectCustomers_RefCustomers2LegalForms =
     "SELECT CustID, ServiceAgent, CustClassification, LegalForm\n"
     "FROM dbo.Customers\n"
     "WHERE LegalForm = :keyID";

const std::string strSQLSelectCorporateForm_RevRefCustomers2LegalForms =
     "SELECT ID, Denotation, Abbreviation, Description, IsLegalEntrity, \n"
     "       UrgentValue\n"
     "FROM dbo.CorporateForm\n"
     "WHERE ID = :keyLegalForm";

const std::string strSQLInsertCustomers =
     "INSERT INTO dbo.Customers \n"
     "       (CustID,ServiceAgent,CustClassification,LegalForm)\n"
     "VALUES (:CustID,:ServiceAgent,:CustClassification,:LegalForm)";

const std::string strSQLUpdateCustomers_WithPrim =
     "UPDATE dbo.Customers\n"
     "SET   CustID             = :CustID,\n"
     "      ServiceAgent       = :ServiceAgent,\n"
     "      CustClassification = :CustClassification,\n"
     "      LegalForm          = :LegalForm\n"
     "WHERE CustID = :keyCustID";

const std::string strSQLUpdateCustomers_WithoutPrim =
     "UPDATE dbo.Customers\n"
     "SET   ServiceAgent       = :ServiceAgent,\n"
     "      CustClassification = :CustClassification,\n"
     "      LegalForm          = :LegalForm\n"
     "WHERE CustID = :keyCustID";

const std::string strSQLDeleteCustomers_All =
     "DELETE FROM dbo.Customers";

const std::string strSQLDeleteCustomers_Detail =
     "DELETE FROM dbo.Customers\n"
     "WHERE CustID = :keyCustID";


// --------------------------------------------------------------------
//   Statements for table / view: Departments
// --------------------------------------------------------------------
const std::string strSQLSelectDepartments_All =
     "SELECT ID,Denotation,Abbreviation,Description,Officer,Notes\n"
     "FROM dbo.Departments";

const std::string strSQLSelectDepartments_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,Officer,Notes\n"
     "FROM dbo.Departments\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectDepartments_UnqDepartments_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,Officer,Notes\n"
     "FROM dbo.Departments\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLSelectDepartments_IdxDepartments_Abbr =
     "SELECT ID,Denotation,Abbreviation,Description,Officer,Notes\n"
     "FROM dbo.Departments\n"
     "WHERE Abbreviation LIKE :keyAbbreviation";

const std::string strSQLSelectDepartments_RefDepartments2Employee =
     "SELECT ID, Denotation, Abbreviation, Description, Officer, Notes\n"
     "FROM dbo.Departments\n"
     "WHERE Officer = :keyEmployID";

const std::string strSQLSelectEmployees_RevRefDepartments2Employee =
     "SELECT EmployID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, \n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, \n"
     "       Department, TaxNumber, SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE EmployID = :keyOfficer";

const std::string strSQLInsertDepartments =
     "INSERT INTO dbo.Departments \n"
     "       (ID,Denotation,Abbreviation,Description,Officer,Notes)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:Officer,:Notes)";

const std::string strSQLUpdateDepartments_WithPrim =
     "UPDATE dbo.Departments\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Officer      = :Officer,\n"
     "      Notes        = :Notes\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateDepartments_WithoutPrim =
     "UPDATE dbo.Departments\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Officer      = :Officer,\n"
     "      Notes        = :Notes\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteDepartments_All =
     "DELETE FROM dbo.Departments";

const std::string strSQLDeleteDepartments_Detail =
     "DELETE FROM dbo.Departments\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Employees
// --------------------------------------------------------------------
const std::string strSQLSelectEmployees_All =
     "SELECT EmployID,PersonNumber,Salary,SalaryType,TaxClass,StartOfJob,\n"
     "       EndOfJob,ReasonDeparture,JobPosition,JobSpec,VacationDays,\n"
     "       Department,TaxNumber,SocialNummer,Active\n"
     "FROM dbo.Employees";

const std::string strSQLSelectEmployees_Detail =
     "SELECT EmployID,PersonNumber,Salary,SalaryType,TaxClass,StartOfJob,\n"
     "       EndOfJob,ReasonDeparture,JobPosition,JobSpec,VacationDays,\n"
     "       Department,TaxNumber,SocialNummer,Active\n"
     "FROM dbo.Employees\n"
     "WHERE EmployID = :keyEmployID";

const std::string strSQLSelectEmployees_UnqEmployees_PersonNumber =
     "SELECT EmployID,PersonNumber,Salary,SalaryType,TaxClass,StartOfJob,\n"
     "       EndOfJob,ReasonDeparture,JobPosition,JobSpec,VacationDays,\n"
     "       Department,TaxNumber,SocialNummer,Active\n"
     "FROM dbo.Employees\n"
     "WHERE PersonNumber = :keyPersonNumber";

const std::string strSQLSelectEmployees_UnqEmployees_SocialNumber =
     "SELECT EmployID,PersonNumber,Salary,SalaryType,TaxClass,StartOfJob,\n"
     "       EndOfJob,ReasonDeparture,JobPosition,JobSpec,VacationDays,\n"
     "       Department,TaxNumber,SocialNummer,Active\n"
     "FROM dbo.Employees\n"
     "WHERE TaxNumber = :keyTaxNumber";

const std::string strSQLSelectEmployees_IdxEmployees_JobSpec =
     "SELECT EmployID,PersonNumber,Salary,SalaryType,TaxClass,StartOfJob,\n"
     "       EndOfJob,ReasonDeparture,JobPosition,JobSpec,VacationDays,\n"
     "       Department,TaxNumber,SocialNummer,Active\n"
     "FROM dbo.Employees\n"
     "WHERE JobSpec LIKE :keyJobSpec";

const std::string strSQLSelectEmployees_IdxEmployees_Active =
     "SELECT EmployID,PersonNumber,Salary,SalaryType,TaxClass,StartOfJob,\n"
     "       EndOfJob,ReasonDeparture,JobPosition,JobSpec,VacationDays,\n"
     "       Department,TaxNumber,SocialNummer,Active\n"
     "FROM dbo.Employees\n"
     "WHERE SocialNummer LIKE :keySocialNummer";

const std::string strSQLSelectEmployees_RefEmployees2Person =
     "SELECT EmployID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, \n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, \n"
     "       Department, TaxNumber, SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE EmployID = :keyID";

const std::string strSQLSelectPerson_RevRefEmployees2Person =
     "SELECT ID, Name, FirstName, Birthname, FormOfAddress, FamilyStatus, \n"
     "       FamilyStatusSince, Birthday, Notes, FullName\n"
     "FROM dbo.Person\n"
     "WHERE ID = :keyEmployID";

const std::string strSQLSelectEmployees_RefEmployees2SalaryType =
     "SELECT EmployID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, \n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, \n"
     "       Department, TaxNumber, SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE SalaryType = :keyID";

const std::string strSQLSelectSalaryType_RevRefEmployees2SalaryType =
     "SELECT ID, Denotation, Abbreviation, Description, SalaryBase, UrgentValue\n"
     "FROM dbo.SalaryType\n"
     "WHERE ID = :keySalaryType";

const std::string strSQLSelectEmployees_RefEmployees2TaxClass =
     "SELECT EmployID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, \n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, \n"
     "       Department, TaxNumber, SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE TaxClass = :keyID";

const std::string strSQLSelectTaxClasses_RevRefEmployees2TaxClass =
     "SELECT ID, Denotation, Abbreviation, Description, Coupled, UrgentValue\n"
     "FROM dbo.TaxClasses\n"
     "WHERE ID = :keyTaxClass";

const std::string strSQLSelectEmployees_RefEmployees2ReasonDeparture =
     "SELECT EmployID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, \n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, \n"
     "       Department, TaxNumber, SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE ReasonDeparture = :keyID";

const std::string strSQLSelectReasonDeparture_RevRefEmployees2ReasonDeparture =
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.ReasonDeparture\n"
     "WHERE ID = :keyReasonDeparture";

const std::string strSQLSelectEmployees_RefEmployees2JobPositions =
     "SELECT EmployID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, \n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, \n"
     "       Department, TaxNumber, SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE JobPosition = :keyID";

const std::string strSQLSelectJobPositions_RevRefEmployees2JobPositions =
     "SELECT ID, Denotation, Abbreviation, Description, SalaryType, Notes, \n"
     "       UrgentValue\n"
     "FROM dbo.JobPositions\n"
     "WHERE ID = :keyJobPosition";

const std::string strSQLSelectEmployees_RefEmployees2Department =
     "SELECT EmployID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, \n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, \n"
     "       Department, TaxNumber, SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE Department = :keyID";

const std::string strSQLSelectDepartments_RevRefEmployees2Department =
     "SELECT ID, Denotation, Abbreviation, Description, Officer, Notes\n"
     "FROM dbo.Departments\n"
     "WHERE ID = :keyDepartment";

const std::string strSQLInsertEmployees =
     "INSERT INTO dbo.Employees \n"
     "       (EmployID,PersonNumber,Salary,SalaryType,TaxClass,StartOfJob,\n"
     "        EndOfJob,ReasonDeparture,JobPosition,JobSpec,VacationDays,\n"
     "        Department,TaxNumber,SocialNummer)\n"
     "VALUES (:EmployID,:PersonNumber,:Salary,:SalaryType,:TaxClass,\n"
     "        :StartOfJob,:EndOfJob,:ReasonDeparture,:JobPosition,:JobSpec,\n"
     "        :VacationDays,:Department,:TaxNumber,:SocialNummer)";

const std::string strSQLUpdateEmployees_WithPrim =
     "UPDATE dbo.Employees\n"
     "SET   EmployID        = :EmployID,\n"
     "      PersonNumber    = :PersonNumber,\n"
     "      Salary          = :Salary,\n"
     "      SalaryType      = :SalaryType,\n"
     "      TaxClass        = :TaxClass,\n"
     "      StartOfJob      = :StartOfJob,\n"
     "      EndOfJob        = :EndOfJob,\n"
     "      ReasonDeparture = :ReasonDeparture,\n"
     "      JobPosition     = :JobPosition,\n"
     "      JobSpec         = :JobSpec,\n"
     "      VacationDays    = :VacationDays,\n"
     "      Department      = :Department,\n"
     "      TaxNumber       = :TaxNumber,\n"
     "      SocialNummer    = :SocialNummer\n"
     "WHERE EmployID = :keyEmployID";

const std::string strSQLUpdateEmployees_WithoutPrim =
     "UPDATE dbo.Employees\n"
     "SET   PersonNumber    = :PersonNumber,\n"
     "      Salary          = :Salary,\n"
     "      SalaryType      = :SalaryType,\n"
     "      TaxClass        = :TaxClass,\n"
     "      StartOfJob      = :StartOfJob,\n"
     "      EndOfJob        = :EndOfJob,\n"
     "      ReasonDeparture = :ReasonDeparture,\n"
     "      JobPosition     = :JobPosition,\n"
     "      JobSpec         = :JobSpec,\n"
     "      VacationDays    = :VacationDays,\n"
     "      Department      = :Department,\n"
     "      TaxNumber       = :TaxNumber,\n"
     "      SocialNummer    = :SocialNummer\n"
     "WHERE EmployID = :keyEmployID";

const std::string strSQLDeleteEmployees_All =
     "DELETE FROM dbo.Employees";

const std::string strSQLDeleteEmployees_Detail =
     "DELETE FROM dbo.Employees\n"
     "WHERE EmployID = :keyEmployID";


// --------------------------------------------------------------------
//   Statements for table / view: FamilyStatus
// --------------------------------------------------------------------
const std::string strSQLSelectFamilyStatus_All =
     "SELECT ID,Denotation,Abbreviation,Description,Coupled,NeedDate,\n"
     "       Notes,UrgentValue\n"
     "FROM dbo.FamilyStatus";

const std::string strSQLSelectFamilyStatus_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,Coupled,NeedDate,\n"
     "       Notes,UrgentValue\n"
     "FROM dbo.FamilyStatus\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectFamilyStatus_UnqFamilyStatus_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,Coupled,NeedDate,\n"
     "       Notes,UrgentValue\n"
     "FROM dbo.FamilyStatus\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLInsertFamilyStatus =
     "INSERT INTO dbo.FamilyStatus \n"
     "       (ID,Denotation,Abbreviation,Description,Coupled,NeedDate,\n"
     "        Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:Coupled,:NeedDate,\n"
     "        :Notes,:UrgentValue)";

const std::string strSQLUpdateFamilyStatus_WithPrim =
     "UPDATE dbo.FamilyStatus\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Coupled      = :Coupled,\n"
     "      NeedDate     = :NeedDate,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateFamilyStatus_WithoutPrim =
     "UPDATE dbo.FamilyStatus\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Coupled      = :Coupled,\n"
     "      NeedDate     = :NeedDate,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteFamilyStatus_All =
     "DELETE FROM dbo.FamilyStatus";

const std::string strSQLDeleteFamilyStatus_Detail =
     "DELETE FROM dbo.FamilyStatus\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: FamilyTypes
// --------------------------------------------------------------------
const std::string strSQLSelectFamilyTypes_All =
     "SELECT ID,Denotation,Abbreviation,IsNaturalPerson,Description,\n"
     "       Notes,UrgentValue\n"
     "FROM dbo.FamilyTypes";

const std::string strSQLSelectFamilyTypes_Detail =
     "SELECT ID,Denotation,Abbreviation,IsNaturalPerson,Description,\n"
     "       Notes,UrgentValue\n"
     "FROM dbo.FamilyTypes\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectFamilyTypes_UnqFamilyTypes_Denotation =
     "SELECT ID,Denotation,Abbreviation,IsNaturalPerson,Description,\n"
     "       Notes,UrgentValue\n"
     "FROM dbo.FamilyTypes\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLInsertFamilyTypes =
     "INSERT INTO dbo.FamilyTypes \n"
     "       (ID,Denotation,Abbreviation,IsNaturalPerson,Description,\n"
     "        Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:IsNaturalPerson,:Description,\n"
     "        :Notes,:UrgentValue)";

const std::string strSQLUpdateFamilyTypes_WithPrim =
     "UPDATE dbo.FamilyTypes\n"
     "SET   ID              = :ID,\n"
     "      Denotation      = :Denotation,\n"
     "      Abbreviation    = :Abbreviation,\n"
     "      IsNaturalPerson = :IsNaturalPerson,\n"
     "      Description     = :Description,\n"
     "      Notes           = :Notes,\n"
     "      UrgentValue     = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateFamilyTypes_WithoutPrim =
     "UPDATE dbo.FamilyTypes\n"
     "SET   Denotation      = :Denotation,\n"
     "      Abbreviation    = :Abbreviation,\n"
     "      IsNaturalPerson = :IsNaturalPerson,\n"
     "      Description     = :Description,\n"
     "      Notes           = :Notes,\n"
     "      UrgentValue     = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteFamilyTypes_All =
     "DELETE FROM dbo.FamilyTypes";

const std::string strSQLDeleteFamilyTypes_Detail =
     "DELETE FROM dbo.FamilyTypes\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: FormOfAddress
// --------------------------------------------------------------------
const std::string strSQLSelectFormOfAddress_All =
     "SELECT ID,Denotation,Abbreviation,Description,TypeSpec,Salutation,\n"
     "       Valediction,Notes,UrgentValue\n"
     "FROM dbo.FormOfAddress";

const std::string strSQLSelectFormOfAddress_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,TypeSpec,Salutation,\n"
     "       Valediction,Notes,UrgentValue\n"
     "FROM dbo.FormOfAddress\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectFormOfAddress_UnqFormOfAddress_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,TypeSpec,Salutation,\n"
     "       Valediction,Notes,UrgentValue\n"
     "FROM dbo.FormOfAddress\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLSelectFormOfAddress_RefFormOfAddress2Type =
     "SELECT ID, Denotation, Abbreviation, Description, TypeSpec, Salutation, \n"
     "       Valediction, Notes, UrgentValue\n"
     "FROM dbo.FormOfAddress\n"
     "WHERE TypeSpec = :keyID";

const std::string strSQLSelectFamilyTypes_RevRefFormOfAddress2Type =
     "SELECT ID, Denotation, Abbreviation, IsNaturalPerson, Description, \n"
     "       Notes, UrgentValue\n"
     "FROM dbo.FamilyTypes\n"
     "WHERE ID = :keyTypeSpec";

const std::string strSQLInsertFormOfAddress =
     "INSERT INTO dbo.FormOfAddress \n"
     "       (ID,Denotation,Abbreviation,Description,TypeSpec,Salutation,\n"
     "        Valediction,Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:TypeSpec,:Salutation,\n"
     "        :Valediction,:Notes,:UrgentValue)";

const std::string strSQLUpdateFormOfAddress_WithPrim =
     "UPDATE dbo.FormOfAddress\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      TypeSpec     = :TypeSpec,\n"
     "      Salutation   = :Salutation,\n"
     "      Valediction  = :Valediction,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateFormOfAddress_WithoutPrim =
     "UPDATE dbo.FormOfAddress\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      TypeSpec     = :TypeSpec,\n"
     "      Salutation   = :Salutation,\n"
     "      Valediction  = :Valediction,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteFormOfAddress_All =
     "DELETE FROM dbo.FormOfAddress";

const std::string strSQLDeleteFormOfAddress_Detail =
     "DELETE FROM dbo.FormOfAddress\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Internet
// --------------------------------------------------------------------
const std::string strSQLSelectInternet_All =
     "SELECT ID,InternetType,Adresse\n"
     "FROM dbo.Internet";

const std::string strSQLSelectInternet_Detail =
     "SELECT ID,InternetType,Adresse\n"
     "FROM dbo.Internet\n"
     "WHERE ID           = :keyID AND\n"
     "      InternetType = :keyInternetType";

const std::string strSQLSelectInternet_IdxInternet_Address =
     "SELECT ID,InternetType,Adresse\n"
     "FROM dbo.Internet\n"
     "WHERE Adresse LIKE :keyAdresse";

const std::string strSQLSelectInternet_RefInternet2Person =
     "SELECT ID, InternetType, Adresse\n"
     "FROM dbo.Internet\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectPerson_RevRefInternet2Person =
     "SELECT ID, Name, FirstName, Birthname, FormOfAddress, FamilyStatus, \n"
     "       FamilyStatusSince, Birthday, Notes, FullName\n"
     "FROM dbo.Person\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectInternet_RefInternet2Type =
     "SELECT ID, InternetType, Adresse\n"
     "FROM dbo.Internet\n"
     "WHERE InternetType = :keyID";

const std::string strSQLSelectInternetTypes_RevRefInternet2Type =
     "SELECT ID, Denotation, Abbreviation, Description, Prefix, Notes, \n"
     "       UrgentValue\n"
     "FROM dbo.InternetTypes\n"
     "WHERE ID = :keyInternetType";

const std::string strSQLInsertInternet =
     "INSERT INTO dbo.Internet \n"
     "       (ID,InternetType,Adresse)\n"
     "VALUES (:ID,:InternetType,:Adresse)";

const std::string strSQLUpdateInternet_WithPrim =
     "UPDATE dbo.Internet\n"
     "SET   ID           = :ID,\n"
     "      InternetType = :InternetType,\n"
     "      Adresse      = :Adresse\n"
     "WHERE ID           = :keyID AND\n"
     "      InternetType = :keyInternetType)";

const std::string strSQLUpdateInternet_WithoutPrim =
     "UPDATE dbo.Internet\n"
     "SET   Adresse = :Adresse\n"
     "WHERE ID           = :keyID AND\n"
     "      InternetType = :keyInternetType)";

const std::string strSQLDeleteInternet_All =
     "DELETE FROM dbo.Internet";

const std::string strSQLDeleteInternet_Detail =
     "DELETE FROM dbo.Internet\n"
     "WHERE ID           = :keyID AND\n"
     "      InternetType = :keyInternetType";


// --------------------------------------------------------------------
//   Statements for table / view: InternetTypes
// --------------------------------------------------------------------
const std::string strSQLSelectInternetTypes_All =
     "SELECT ID,Denotation,Abbreviation,Description,Prefix,Notes,UrgentValue\n"
     "FROM dbo.InternetTypes";

const std::string strSQLSelectInternetTypes_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,Prefix,Notes,UrgentValue\n"
     "FROM dbo.InternetTypes\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectInternetTypes_UnqInternetTypes_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,Prefix,Notes,UrgentValue\n"
     "FROM dbo.InternetTypes\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLInsertInternetTypes =
     "INSERT INTO dbo.InternetTypes \n"
     "       (ID,Denotation,Abbreviation,Description,Prefix,Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:Prefix,:Notes,\n"
     "        :UrgentValue)";

const std::string strSQLUpdateInternetTypes_WithPrim =
     "UPDATE dbo.InternetTypes\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Prefix       = :Prefix,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateInternetTypes_WithoutPrim =
     "UPDATE dbo.InternetTypes\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Prefix       = :Prefix,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteInternetTypes_All =
     "DELETE FROM dbo.InternetTypes";

const std::string strSQLDeleteInternetTypes_Detail =
     "DELETE FROM dbo.InternetTypes\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: JobPositions
// --------------------------------------------------------------------
const std::string strSQLSelectJobPositions_All =
     "SELECT ID,Denotation,Abbreviation,Description,SalaryType,Notes,\n"
     "       UrgentValue\n"
     "FROM dbo.JobPositions";

const std::string strSQLSelectJobPositions_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,SalaryType,Notes,\n"
     "       UrgentValue\n"
     "FROM dbo.JobPositions\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectJobPositions_UnqJobPositions_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,SalaryType,Notes,\n"
     "       UrgentValue\n"
     "FROM dbo.JobPositions\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLSelectJobPositions_RefJobPosition2SalaryType =
     "SELECT ID, Denotation, Abbreviation, Description, SalaryType, Notes, \n"
     "       UrgentValue\n"
     "FROM dbo.JobPositions\n"
     "WHERE SalaryType = :keyID";

const std::string strSQLSelectSalaryType_RevRefJobPosition2SalaryType =
     "SELECT ID, Denotation, Abbreviation, Description, SalaryBase, UrgentValue\n"
     "FROM dbo.SalaryType\n"
     "WHERE ID = :keySalaryType";

const std::string strSQLInsertJobPositions =
     "INSERT INTO dbo.JobPositions \n"
     "       (ID,Denotation,Abbreviation,Description,SalaryType,Notes,\n"
     "        UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:SalaryType,\n"
     "        :Notes,:UrgentValue)";

const std::string strSQLUpdateJobPositions_WithPrim =
     "UPDATE dbo.JobPositions\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      SalaryType   = :SalaryType,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateJobPositions_WithoutPrim =
     "UPDATE dbo.JobPositions\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      SalaryType   = :SalaryType,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteJobPositions_All =
     "DELETE FROM dbo.JobPositions";

const std::string strSQLDeleteJobPositions_Detail =
     "DELETE FROM dbo.JobPositions\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Person
// --------------------------------------------------------------------
const std::string strSQLSelectPerson_All =
     "SELECT ID,Name,FirstName,Birthname,FormOfAddress,FamilyStatus,\n"
     "       FamilyStatusSince,Birthday,Notes,FullName\n"
     "FROM dbo.Person";

const std::string strSQLSelectPerson_Detail =
     "SELECT ID,Name,FirstName,Birthname,FormOfAddress,FamilyStatus,\n"
     "       FamilyStatusSince,Birthday,Notes,FullName\n"
     "FROM dbo.Person\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectPerson_IdxPerson_Name_Firstname =
     "SELECT ID,Name,FirstName,Birthname,FormOfAddress,FamilyStatus,\n"
     "       FamilyStatusSince,Birthday,Notes,FullName\n"
     "FROM dbo.Person\n"
     "WHERE Name      LIKE :keyName AND\n"
     "      FirstName LIKE :keyFirstName";

const std::string strSQLSelectPerson_RefPerson2FormOfAddress =
     "SELECT ID, Name, FirstName, Birthname, FormOfAddress, FamilyStatus, \n"
     "       FamilyStatusSince, Birthday, Notes, FullName\n"
     "FROM dbo.Person\n"
     "WHERE FormOfAddress = :keyID";

const std::string strSQLSelectFormOfAddress_RevRefPerson2FormOfAddress =
     "SELECT ID, Denotation, Abbreviation, Description, TypeSpec, Salutation, \n"
     "       Valediction, Notes, UrgentValue\n"
     "FROM dbo.FormOfAddress\n"
     "WHERE ID = :keyFormOfAddress";

const std::string strSQLSelectPerson_RefPerson2FamilyStatus =
     "SELECT ID, Name, FirstName, Birthname, FormOfAddress, FamilyStatus, \n"
     "       FamilyStatusSince, Birthday, Notes, FullName\n"
     "FROM dbo.Person\n"
     "WHERE FamilyStatus = :keyID";

const std::string strSQLSelectFamilyStatus_RevRefPerson2FamilyStatus =
     "SELECT ID, Denotation, Abbreviation, Description, Coupled, NeedDate, \n"
     "       Notes, UrgentValue\n"
     "FROM dbo.FamilyStatus\n"
     "WHERE ID = :keyFamilyStatus";

const std::string strSQLInsertPerson =
     "INSERT INTO dbo.Person \n"
     "       (ID,Name,FirstName,Birthname,FormOfAddress,FamilyStatus,\n"
     "        FamilyStatusSince,Birthday,Notes)\n"
     "VALUES (:ID,:Name,:FirstName,:Birthname,:FormOfAddress,:FamilyStatus,\n"
     "        :FamilyStatusSince,:Birthday,:Notes)";

const std::string strSQLUpdatePerson_WithPrim =
     "UPDATE dbo.Person\n"
     "SET   ID                = :ID,\n"
     "      Name              = :Name,\n"
     "      FirstName         = :FirstName,\n"
     "      Birthname         = :Birthname,\n"
     "      FormOfAddress     = :FormOfAddress,\n"
     "      FamilyStatus      = :FamilyStatus,\n"
     "      FamilyStatusSince = :FamilyStatusSince,\n"
     "      Birthday          = :Birthday,\n"
     "      Notes             = :Notes\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdatePerson_WithoutPrim =
     "UPDATE dbo.Person\n"
     "SET   Name              = :Name,\n"
     "      FirstName         = :FirstName,\n"
     "      Birthname         = :Birthname,\n"
     "      FormOfAddress     = :FormOfAddress,\n"
     "      FamilyStatus      = :FamilyStatus,\n"
     "      FamilyStatusSince = :FamilyStatusSince,\n"
     "      Birthday          = :Birthday,\n"
     "      Notes             = :Notes\n"
     "WHERE ID = :keyID";

const std::string strSQLDeletePerson_All =
     "DELETE FROM dbo.Person";

const std::string strSQLDeletePerson_Detail =
     "DELETE FROM dbo.Person\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Phone
// --------------------------------------------------------------------
const std::string strSQLSelectPhone_All =
     "SELECT ID,PhoneType,AreaCode,CallNumber,Country,DialingNational,\n"
     "       DialingInternational\n"
     "FROM dbo.Phone";

const std::string strSQLSelectPhone_Detail =
     "SELECT ID,PhoneType,AreaCode,CallNumber,Country,DialingNational,\n"
     "       DialingInternational\n"
     "FROM dbo.Phone\n"
     "WHERE ID        = :keyID AND\n"
     "      PhoneType = :keyPhoneType";

const std::string strSQLSelectPhone_IdxPhone_Number =
     "SELECT ID,PhoneType,AreaCode,CallNumber,Country,DialingNational,\n"
     "       DialingInternational\n"
     "FROM dbo.Phone\n"
     "WHERE AreaCode   LIKE :keyAreaCode AND\n"
     "      CallNumber LIKE :keyCallNumber";

const std::string strSQLSelectPhone_RefPhone2Person =
     "SELECT ID, PhoneType, AreaCode, CallNumber, Country, DialingNational, \n"
     "       DialingInternational\n"
     "FROM dbo.Phone\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectPerson_RevRefPhone2Person =
     "SELECT ID, Name, FirstName, Birthname, FormOfAddress, FamilyStatus, \n"
     "       FamilyStatusSince, Birthday, Notes, FullName\n"
     "FROM dbo.Person\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectPhone_RefPhone2Type =
     "SELECT ID, PhoneType, AreaCode, CallNumber, Country, DialingNational, \n"
     "       DialingInternational\n"
     "FROM dbo.Phone\n"
     "WHERE PhoneType = :keyID";

const std::string strSQLSelectPhonesTypes_RevRefPhone2Type =
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.PhoneTypes\n"
     "WHERE ID = :keyPhoneType";

const std::string strSQLSelectPhone_RefPhone2Countries =
     "SELECT ID, PhoneType, AreaCode, CallNumber, Country, DialingNational, \n"
     "       DialingInternational\n"
     "FROM dbo.Phone\n"
     "WHERE Country = :keyID";

const std::string strSQLSelectCountries_RevRefPhone2Countries =
     "SELECT ID, Denotation, Abbreviation, Description, CountryDialing, \n"
     "       ISO_Code, IsEU, Capital, Currency, Notes, UrgentValue\n"
     "FROM dbo.Countries\n"
     "WHERE ID = :keyCountry";

const std::string strSQLInsertPhone =
     "INSERT INTO dbo.Phone \n"
     "       (ID,PhoneType,AreaCode,CallNumber,Country)\n"
     "VALUES (:ID,:PhoneType,:AreaCode,:CallNumber,:Country)";

const std::string strSQLUpdatePhone_WithPrim =
     "UPDATE dbo.Phone\n"
     "SET   ID         = :ID,\n"
     "      PhoneType  = :PhoneType,\n"
     "      AreaCode   = :AreaCode,\n"
     "      CallNumber = :CallNumber,\n"
     "      Country    = :Country\n"
     "WHERE ID        = :keyID AND\n"
     "      PhoneType = :keyPhoneType)";

const std::string strSQLUpdatePhone_WithoutPrim =
     "UPDATE dbo.Phone\n"
     "SET   AreaCode   = :AreaCode,\n"
     "      CallNumber = :CallNumber,\n"
     "      Country    = :Country\n"
     "WHERE ID        = :keyID AND\n"
     "      PhoneType = :keyPhoneType)";

const std::string strSQLDeletePhone_All =
     "DELETE FROM dbo.Phone";

const std::string strSQLDeletePhone_Detail =
     "DELETE FROM dbo.Phone\n"
     "WHERE ID        = :keyID AND\n"
     "      PhoneType = :keyPhoneType";


// --------------------------------------------------------------------
//   Statements for table / view: PhonesTypes
// --------------------------------------------------------------------
const std::string strSQLSelectPhonesTypes_All =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.PhoneTypes";

const std::string strSQLSelectPhonesTypes_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.PhoneTypes\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectPhonesTypes_UnqPhonesTypes_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.PhoneTypes\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLInsertPhonesTypes =
     "INSERT INTO dbo.PhoneTypes \n"
     "       (ID,Denotation,Abbreviation,Description,Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:Notes,:UrgentValue)";

const std::string strSQLUpdatePhonesTypes_WithPrim =
     "UPDATE dbo.PhoneTypes\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdatePhonesTypes_WithoutPrim =
     "UPDATE dbo.PhoneTypes\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeletePhonesTypes_All =
     "DELETE FROM dbo.PhoneTypes";

const std::string strSQLDeletePhonesTypes_Detail =
     "DELETE FROM dbo.PhoneTypes\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: ReasonDeparture
// --------------------------------------------------------------------
const std::string strSQLSelectReasonDeparture_All =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.ReasonDeparture";

const std::string strSQLSelectReasonDeparture_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.ReasonDeparture\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectReasonDeparture_UnqReasonDeparture_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.ReasonDeparture\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLInsertReasonDeparture =
     "INSERT INTO dbo.ReasonDeparture \n"
     "       (ID,Denotation,Abbreviation,Description,Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:Notes,:UrgentValue)";

const std::string strSQLUpdateReasonDeparture_WithPrim =
     "UPDATE dbo.ReasonDeparture\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateReasonDeparture_WithoutPrim =
     "UPDATE dbo.ReasonDeparture\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteReasonDeparture_All =
     "DELETE FROM dbo.ReasonDeparture";

const std::string strSQLDeleteReasonDeparture_Detail =
     "DELETE FROM dbo.ReasonDeparture\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: ReasonNonWorking
// --------------------------------------------------------------------
const std::string strSQLSelectReasonNonWorking_All =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.ReasonNonWorking";

const std::string strSQLSelectReasonNonWorking_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.ReasonNonWorking\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectReasonNonWorking_UnqReasonNonWorking_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,Notes,UrgentValue\n"
     "FROM dbo.ReasonNonWorking\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLInsertReasonNonWorking =
     "INSERT INTO dbo.ReasonNonWorking \n"
     "       (ID,Denotation,Abbreviation,Description,Notes,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:Notes,:UrgentValue)";

const std::string strSQLUpdateReasonNonWorking_WithPrim =
     "UPDATE dbo.ReasonNonWorking\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateReasonNonWorking_WithoutPrim =
     "UPDATE dbo.ReasonNonWorking\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Notes        = :Notes,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteReasonNonWorking_All =
     "DELETE FROM dbo.ReasonNonWorking";

const std::string strSQLDeleteReasonNonWorking_Detail =
     "DELETE FROM dbo.ReasonNonWorking\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: SalaryBase
// --------------------------------------------------------------------
const std::string strSQLSelectSalaryBase_All =
     "SELECT ID,Denotation,Abbreviation,Description,UrgentValue\n"
     "FROM dbo.SalaryBase";

const std::string strSQLSelectSalaryBase_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,UrgentValue\n"
     "FROM dbo.SalaryBase\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectSalaryBase_UnqSalaryBase_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,UrgentValue\n"
     "FROM dbo.SalaryBase\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLSelectSalaryBase_UnqSalaryBase_Abbreviation =
     "SELECT ID,Denotation,Abbreviation,Description,UrgentValue\n"
     "FROM dbo.SalaryBase\n"
     "WHERE Abbreviation = :keyAbbreviation";

const std::string strSQLInsertSalaryBase =
     "INSERT INTO dbo.SalaryBase \n"
     "       (ID,Denotation,Abbreviation,Description,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:UrgentValue)";

const std::string strSQLUpdateSalaryBase_WithPrim =
     "UPDATE dbo.SalaryBase\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateSalaryBase_WithoutPrim =
     "UPDATE dbo.SalaryBase\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteSalaryBase_All =
     "DELETE FROM dbo.SalaryBase";

const std::string strSQLDeleteSalaryBase_Detail =
     "DELETE FROM dbo.SalaryBase\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: SalaryType
// --------------------------------------------------------------------
const std::string strSQLSelectSalaryType_All =
     "SELECT ID,Denotation,Abbreviation,Description,SalaryBase,UrgentValue\n"
     "FROM dbo.SalaryType";

const std::string strSQLSelectSalaryType_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,SalaryBase,UrgentValue\n"
     "FROM dbo.SalaryType\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectSalaryType_RefSalaryType2SalaryBase =
     "SELECT ID, Denotation, Abbreviation, Description, SalaryBase, UrgentValue\n"
     "FROM dbo.SalaryType\n"
     "WHERE SalaryBase = :keyID";

const std::string strSQLSelectSalaryBase_RevRefSalaryType2SalaryBase =
     "SELECT ID, Denotation, Abbreviation, Description, UrgentValue\n"
     "FROM dbo.SalaryBase\n"
     "WHERE ID = :keySalaryBase";

const std::string strSQLInsertSalaryType =
     "INSERT INTO dbo.SalaryType \n"
     "       (ID,Denotation,Abbreviation,Description,SalaryBase,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:SalaryBase,\n"
     "        :UrgentValue)";

const std::string strSQLUpdateSalaryType_WithPrim =
     "UPDATE dbo.SalaryType\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      SalaryBase   = :SalaryBase,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateSalaryType_WithoutPrim =
     "UPDATE dbo.SalaryType\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      SalaryBase   = :SalaryBase,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteSalaryType_All =
     "DELETE FROM dbo.SalaryType";

const std::string strSQLDeleteSalaryType_Detail =
     "DELETE FROM dbo.SalaryType\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: TaxClasses
// --------------------------------------------------------------------
const std::string strSQLSelectTaxClasses_All =
     "SELECT ID,Denotation,Abbreviation,Description,Coupled,UrgentValue\n"
     "FROM dbo.TaxClasses";

const std::string strSQLSelectTaxClasses_Detail =
     "SELECT ID,Denotation,Abbreviation,Description,Coupled,UrgentValue\n"
     "FROM dbo.TaxClasses\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectTaxClasses_UnqTaxClasses_Denotation =
     "SELECT ID,Denotation,Abbreviation,Description,Coupled,UrgentValue\n"
     "FROM dbo.TaxClasses\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLSelectTaxClasses_UnqTaxClasses_Abbreviation =
     "SELECT ID,Denotation,Abbreviation,Description,Coupled,UrgentValue\n"
     "FROM dbo.TaxClasses\n"
     "WHERE Abbreviation = :keyAbbreviation";

const std::string strSQLInsertTaxClasses =
     "INSERT INTO dbo.TaxClasses \n"
     "       (ID,Denotation,Abbreviation,Description,Coupled,UrgentValue)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Description,:Coupled,:UrgentValue)";

const std::string strSQLUpdateTaxClasses_WithPrim =
     "UPDATE dbo.TaxClasses\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Coupled      = :Coupled,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateTaxClasses_WithoutPrim =
     "UPDATE dbo.TaxClasses\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Description  = :Description,\n"
     "      Coupled      = :Coupled,\n"
     "      UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteTaxClasses_All =
     "DELETE FROM dbo.TaxClasses";

const std::string strSQLDeleteTaxClasses_Detail =
     "DELETE FROM dbo.TaxClasses\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Holidays
// --------------------------------------------------------------------
const std::string strSQLSelectWD_Holidays_All =
     "SELECT CalendarDay,Donation,Share,Description\n"
     "FROM dbo.WD_Holidays";

const std::string strSQLSelectWD_Holidays_Detail =
     "SELECT CalendarDay,Donation,Share,Description\n"
     "FROM dbo.WD_Holidays\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLSelectWD_Holidays_RefWD_Holidays_Workdays =
     "SELECT CalendarDay, Donation, Share, Description\n"
     "FROM dbo.WD_Holidays\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLSelectWD_Workdays_RevRefWD_Holidays_Workdays =
     "SELECT CalendarDay, CalendarWeekday, CalendarWeek, CalendarYear, \n"
     "       CalendarMonth, CalendarDayInWeek, CalendarDayInYear, CalendarQuarter, \n"
     "       Workday\n"
     "FROM dbo.WD_Workdays\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLInsertWD_Holidays =
     "INSERT INTO dbo.WD_Holidays \n"
     "       (CalendarDay,Donation,Share,Description)\n"
     "VALUES (:CalendarDay,:Donation,:Share,:Description)";

const std::string strSQLUpdateWD_Holidays_WithPrim =
     "UPDATE dbo.WD_Holidays\n"
     "SET   CalendarDay = :CalendarDay,\n"
     "      Donation    = :Donation,\n"
     "      Share       = :Share,\n"
     "      Description = :Description\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLUpdateWD_Holidays_WithoutPrim =
     "UPDATE dbo.WD_Holidays\n"
     "SET   Donation    = :Donation,\n"
     "      Share       = :Share,\n"
     "      Description = :Description\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLDeleteWD_Holidays_All =
     "DELETE FROM dbo.WD_Holidays";

const std::string strSQLDeleteWD_Holidays_Detail =
     "DELETE FROM dbo.WD_Holidays\n"
     "WHERE CalendarDay = :keyCalendarDay";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Months
// --------------------------------------------------------------------
const std::string strSQLSelectWD_Months_All =
     "SELECT ID,Denotation,Abbreviation,Quarter\n"
     "FROM dbo.WD_Months";

const std::string strSQLSelectWD_Months_Detail =
     "SELECT ID,Denotation,Abbreviation,Quarter\n"
     "FROM dbo.WD_Months\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectWD_Months_UnqWD_Months_Denotation =
     "SELECT ID,Denotation,Abbreviation,Quarter\n"
     "FROM dbo.WD_Months\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLSelectWD_Months_UnqWD_Months_Abbreviation =
     "SELECT ID,Denotation,Abbreviation,Quarter\n"
     "FROM dbo.WD_Months\n"
     "WHERE Abbreviation = :keyAbbreviation";

const std::string strSQLInsertWD_Months =
     "INSERT INTO dbo.WD_Months \n"
     "       (ID,Denotation,Abbreviation,Quarter)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Quarter)";

const std::string strSQLUpdateWD_Months_WithPrim =
     "UPDATE dbo.WD_Months\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Quarter      = :Quarter\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateWD_Months_WithoutPrim =
     "UPDATE dbo.WD_Months\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Quarter      = :Quarter\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteWD_Months_All =
     "DELETE FROM dbo.WD_Months";

const std::string strSQLDeleteWD_Months_Detail =
     "DELETE FROM dbo.WD_Months\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: WD_NonWorking
// --------------------------------------------------------------------
const std::string strSQLSelectWD_NonWorking_All =
     "SELECT ID,StartAt,ClosingAt,Reason,Notes\n"
     "FROM dbo.WD_NonWorking";

const std::string strSQLSelectWD_NonWorking_Detail =
     "SELECT ID,StartAt,ClosingAt,Reason,Notes\n"
     "FROM dbo.WD_NonWorking\n"
     "WHERE ID      = :keyID AND\n"
     "      StartAt = :keyStartAt";

const std::string strSQLSelectWD_NonWorking_RefNonWorking2Employee =
     "SELECT ID, StartAt, ClosingAt, Reason, Notes\n"
     "FROM dbo.WD_NonWorking\n"
     "WHERE ID = :keyEmployID";

const std::string strSQLSelectEmployees_RevRefNonWorking2Employee =
     "SELECT EmployID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, \n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, \n"
     "       Department, TaxNumber, SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE EmployID = :keyID";

const std::string strSQLSelectWD_NonWorking_RefNonWorking2Workday_Start =
     "SELECT ID, StartAt, ClosingAt, Reason, Notes\n"
     "FROM dbo.WD_NonWorking\n"
     "WHERE StartAt = :keyCalendarDay";

const std::string strSQLSelectWD_Workdays_RevRefNonWorking2Workday_Start =
     "SELECT CalendarDay, CalendarWeekday, CalendarWeek, CalendarYear, \n"
     "       CalendarMonth, CalendarDayInWeek, CalendarDayInYear, CalendarQuarter, \n"
     "       Workday\n"
     "FROM dbo.WD_Workdays\n"
     "WHERE CalendarDay = :keyStartAt";

const std::string strSQLSelectWD_NonWorking_RefNonWorking2Workday_Finishing =
     "SELECT ID, StartAt, ClosingAt, Reason, Notes\n"
     "FROM dbo.WD_NonWorking\n"
     "WHERE ClosingAt = :keyCalendarDay";

const std::string strSQLSelectWD_Workdays_RevRefNonWorking2Workday_Finishing =
     "SELECT CalendarDay, CalendarWeekday, CalendarWeek, CalendarYear, \n"
     "       CalendarMonth, CalendarDayInWeek, CalendarDayInYear, CalendarQuarter, \n"
     "       Workday\n"
     "FROM dbo.WD_Workdays\n"
     "WHERE CalendarDay = :keyClosingAt";

const std::string strSQLSelectWD_NonWorking_RefNonWorking2Reason =
     "SELECT ID, StartAt, ClosingAt, Reason, Notes\n"
     "FROM dbo.WD_NonWorking\n"
     "WHERE Reason = :keyID";

const std::string strSQLSelectReasonNonWorking_RevRefNonWorking2Reason =
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.ReasonNonWorking\n"
     "WHERE ID = :keyReason";

const std::string strSQLInsertWD_NonWorking =
     "INSERT INTO dbo.WD_NonWorking \n"
     "       (ID,StartAt,ClosingAt,Reason,Notes)\n"
     "VALUES (:ID,:StartAt,:ClosingAt,:Reason,:Notes)";

const std::string strSQLUpdateWD_NonWorking_WithPrim =
     "UPDATE dbo.WD_NonWorking\n"
     "SET   ID        = :ID,\n"
     "      StartAt   = :StartAt,\n"
     "      ClosingAt = :ClosingAt,\n"
     "      Reason    = :Reason,\n"
     "      Notes     = :Notes\n"
     "WHERE ID      = :keyID AND\n"
     "      StartAt = :keyStartAt)";

const std::string strSQLUpdateWD_NonWorking_WithoutPrim =
     "UPDATE dbo.WD_NonWorking\n"
     "SET   ClosingAt = :ClosingAt,\n"
     "      Reason    = :Reason,\n"
     "      Notes     = :Notes\n"
     "WHERE ID      = :keyID AND\n"
     "      StartAt = :keyStartAt)";

const std::string strSQLDeleteWD_NonWorking_All =
     "DELETE FROM dbo.WD_NonWorking";

const std::string strSQLDeleteWD_NonWorking_Detail =
     "DELETE FROM dbo.WD_NonWorking\n"
     "WHERE ID      = :keyID AND\n"
     "      StartAt = :keyStartAt";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Weekdays
// --------------------------------------------------------------------
const std::string strSQLSelectWD_Weekdays_All =
     "SELECT ID,Denotation,Abbreviation,Workday\n"
     "FROM dbo.WD_Weekdays";

const std::string strSQLSelectWD_Weekdays_Detail =
     "SELECT ID,Denotation,Abbreviation,Workday\n"
     "FROM dbo.WD_Weekdays\n"
     "WHERE ID = :keyID";

const std::string strSQLSelectWD_Weekdays_UnqWD_Weekdays_Denotation =
     "SELECT ID,Denotation,Abbreviation,Workday\n"
     "FROM dbo.WD_Weekdays\n"
     "WHERE Denotation = :keyDenotation";

const std::string strSQLSelectWD_Weekdays_UnqWD_Weekdays_Abbreviation =
     "SELECT ID,Denotation,Abbreviation,Workday\n"
     "FROM dbo.WD_Weekdays\n"
     "WHERE Abbreviation = :keyAbbreviation";

const std::string strSQLInsertWD_Weekdays =
     "INSERT INTO dbo.WD_Weekdays \n"
     "       (ID,Denotation,Abbreviation,Workday)\n"
     "VALUES (:ID,:Denotation,:Abbreviation,:Workday)";

const std::string strSQLUpdateWD_Weekdays_WithPrim =
     "UPDATE dbo.WD_Weekdays\n"
     "SET   ID           = :ID,\n"
     "      Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Workday      = :Workday\n"
     "WHERE ID = :keyID";

const std::string strSQLUpdateWD_Weekdays_WithoutPrim =
     "UPDATE dbo.WD_Weekdays\n"
     "SET   Denotation   = :Denotation,\n"
     "      Abbreviation = :Abbreviation,\n"
     "      Workday      = :Workday\n"
     "WHERE ID = :keyID";

const std::string strSQLDeleteWD_Weekdays_All =
     "DELETE FROM dbo.WD_Weekdays";

const std::string strSQLDeleteWD_Weekdays_Detail =
     "DELETE FROM dbo.WD_Weekdays\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Workdays
// --------------------------------------------------------------------
const std::string strSQLSelectWD_Workdays_All =
     "SELECT CalendarDay,CalendarWeekday,CalendarWeek,CalendarYear,CalendarMonth,\n"
     "       CalendarDayInWeek,CalendarDayInYear,CalendarQuarter,Workday\n"
     "FROM dbo.WD_Workdays";

const std::string strSQLSelectWD_Workdays_Detail =
     "SELECT CalendarDay,CalendarWeekday,CalendarWeek,CalendarYear,CalendarMonth,\n"
     "       CalendarDayInWeek,CalendarDayInYear,CalendarQuarter,Workday\n"
     "FROM dbo.WD_Workdays\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLSelectWD_Workdays_IdxWD_Workdays_Years_Month =
     "SELECT CalendarDay,CalendarWeekday,CalendarWeek,CalendarYear,CalendarMonth,\n"
     "       CalendarDayInWeek,CalendarDayInYear,CalendarQuarter,Workday\n"
     "FROM dbo.WD_Workdays\n"
     "WHERE CalendarYear  = :keyCalendarYear AND\n"
     "      CalendarMonth = :keyCalendarMonth";

const std::string strSQLSelectWD_Workdays_RefWD_Workdays2WeekDay =
     "SELECT CalendarDay, CalendarWeekday, CalendarWeek, CalendarYear, \n"
     "       CalendarMonth, CalendarDayInWeek, CalendarDayInYear, CalendarQuarter, \n"
     "       Workday\n"
     "FROM dbo.WD_Workdays\n"
     "WHERE CalendarWeekday = :keyID";

const std::string strSQLSelectWD_Weekdays_RevRefWD_Workdays2WeekDay =
     "SELECT ID, Denotation, Abbreviation, Workday\n"
     "FROM dbo.WD_Weekdays\n"
     "WHERE ID = :keyCalendarWeekday";

const std::string strSQLSelectWD_Workdays_RefWD_Workdays2Month =
     "SELECT CalendarDay, CalendarWeekday, CalendarWeek, CalendarYear, \n"
     "       CalendarMonth, CalendarDayInWeek, CalendarDayInYear, CalendarQuarter, \n"
     "       Workday\n"
     "FROM dbo.WD_Workdays\n"
     "WHERE CalendarMonth = :keyID";

const std::string strSQLSelectWD_Months_RevRefWD_Workdays2Month =
     "SELECT ID, Denotation, Abbreviation, Quarter\n"
     "FROM dbo.WD_Months\n"
     "WHERE ID = :keyCalendarMonth";

const std::string strSQLInsertWD_Workdays =
     "INSERT INTO dbo.WD_Workdays \n"
     "       (CalendarDay,CalendarWeekday,CalendarWeek)\n"
     "VALUES (:CalendarDay,:CalendarWeekday,:CalendarWeek)";

const std::string strSQLUpdateWD_Workdays_WithPrim =
     "UPDATE dbo.WD_Workdays\n"
     "SET   CalendarDay     = :CalendarDay,\n"
     "      CalendarWeekday = :CalendarWeekday,\n"
     "      CalendarWeek    = :CalendarWeek\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLUpdateWD_Workdays_WithoutPrim =
     "UPDATE dbo.WD_Workdays\n"
     "SET   CalendarWeekday = :CalendarWeekday,\n"
     "      CalendarWeek    = :CalendarWeek\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLDeleteWD_Workdays_All =
     "DELETE FROM dbo.WD_Workdays";

const std::string strSQLDeleteWD_Workdays_Detail =
     "DELETE FROM dbo.WD_Workdays\n"
     "WHERE CalendarDay = :keyCalendarDay";


// --------------------------------------------------------------------
//   Statements for table / view: WorkingTime
// --------------------------------------------------------------------
const std::string strSQLSelectWorkingTime_All =
     "SELECT ID,StartingTime,ClosingTime,Processed ,ProcessedAt,DayOfWork\n"
     "FROM dbo.WorkingTime";

const std::string strSQLSelectWorkingTime_Detail =
     "SELECT ID,StartingTime,ClosingTime,Processed ,ProcessedAt,DayOfWork\n"
     "FROM dbo.WorkingTime\n"
     "WHERE ID           = :keyID AND\n"
     "      StartingTime = :keyStartingTime";

const std::string strSQLSelectWorkingTime_RefWorkTime2Employee =
     "SELECT ID, StartingTime, ClosingTime, Processed , ProcessedAt, \n"
     "       DayOfWork\n"
     "FROM dbo.WorkingTime\n"
     "WHERE ID = :keyEmployID";

const std::string strSQLSelectEmployees_RevRefWorkTime2Employee =
     "SELECT EmployID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, \n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, \n"
     "       Department, TaxNumber, SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE EmployID = :keyID";

const std::string strSQLInsertWorkingTime =
     "INSERT INTO dbo.WorkingTime \n"
     "       (ID,StartingTime,ClosingTime,Processed ,ProcessedAt)\n"
     "VALUES (:ID,:StartingTime,:ClosingTime,:Processed ,:ProcessedAt)";

const std::string strSQLUpdateWorkingTime_WithPrim =
     "UPDATE dbo.WorkingTime\n"
     "SET   ID           = :ID,\n"
     "      StartingTime = :StartingTime,\n"
     "      ClosingTime  = :ClosingTime,\n"
     "      Processed    = :Processed ,\n"
     "      ProcessedAt  = :ProcessedAt\n"
     "WHERE ID           = :keyID AND\n"
     "      StartingTime = :keyStartingTime)";

const std::string strSQLUpdateWorkingTime_WithoutPrim =
     "UPDATE dbo.WorkingTime\n"
     "SET   ClosingTime = :ClosingTime,\n"
     "      Processed   = :Processed ,\n"
     "      ProcessedAt = :ProcessedAt\n"
     "WHERE ID           = :keyID AND\n"
     "      StartingTime = :keyStartingTime)";

const std::string strSQLDeleteWorkingTime_All =
     "DELETE FROM dbo.WorkingTime";

const std::string strSQLDeleteWorkingTime_Detail =
     "DELETE FROM dbo.WorkingTime\n"
     "WHERE ID           = :keyID AND\n"
     "      StartingTime = :keyStartingTime";



} // close namespace reader
