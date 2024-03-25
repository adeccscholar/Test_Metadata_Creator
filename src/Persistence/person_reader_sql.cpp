/*
* Project: model with a simple person administration
* Implementation of sql statement for access with class TPersonReader
* Date: 25.03.2024 19:08:41,353  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include <Persistence\person_reader_sql.h>

namespace reader {

// --------------------------------------------------------------------
//   Statements for table / view: Address
// --------------------------------------------------------------------
const std::string strSQLAddressSelectAll = 
     "SELECT ID, AddressType, Zipcode, City, Street, StreetNumber, Country\n"
     "FROM dbo.Address";

const std::string strSQLAddressSelectDetail = 
     "SELECT ID, AddressType, Zipcode, City, Street, StreetNumber, Country\n"
     "FROM dbo.Address\n"
     "WHERE ID          = :keyID AND\n"
     "      AddressType = :keyAddressType";

const std::string strSQLAddressUpdateWithPrim = 
     "UPDATE dbo.Address\n"
     "SET ID           = :ID,\n"
     "    AddressType  = :AddressType,\n"
     "    Zipcode      = :Zipcode,\n"
     "    City         = :City,\n"
     "    Street       = :Street,\n"
     "    StreetNumber = :StreetNumber,\n"
     "    Country      = :Country\n"
     "WHERE ID          = :keyID AND\n"
     "      AddressType = :keyAddressType";

const std::string strSQLAddressUpdateWithoutPrim = 
     "UPDATE dbo.Address\n"
     "SET Zipcode      = :Zipcode,\n"
     "    City         = :City,\n"
     "    Street       = :Street,\n"
     "    StreetNumber = :StreetNumber,\n"
     "    Country      = :Country\n"
     "WHERE ID          = :keyID AND\n"
     "      AddressType = :keyAddressType";

const std::string strSQLAddressDeleteAll = 
     "DELETE FROM dbo.Address";

const std::string strSQLAddressDeleteDetail = 
     "DELETE FROM dbo.Address\n"
     "WHERE ID          = :keyID AND\n"
     "      AddressType = :keyAddressType";


// --------------------------------------------------------------------
//   Statements for table / view: AddressTypes
// --------------------------------------------------------------------
const std::string strSQLAddressTypesSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.AddressTypes";

const std::string strSQLAddressTypesSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.AddressTypes\n"
     "WHERE ID = :keyID";

const std::string strSQLAddressTypesUpdateWithPrim = 
     "UPDATE dbo.AddressTypes\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLAddressTypesUpdateWithoutPrim = 
     "UPDATE dbo.AddressTypes\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLAddressTypesDeleteAll = 
     "DELETE FROM dbo.AddressTypes";

const std::string strSQLAddressTypesDeleteDetail = 
     "DELETE FROM dbo.AddressTypes\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Banking
// --------------------------------------------------------------------
const std::string strSQLBankingSelectAll = 
     "SELECT ID, BankingType, BankName, IBAN, BIC, BankOwner, Country\n"
     "FROM dbo.Banking";

const std::string strSQLBankingSelectDetail = 
     "SELECT ID, BankingType, BankName, IBAN, BIC, BankOwner, Country\n"
     "FROM dbo.Banking\n"
     "WHERE ID          = :keyID AND\n"
     "      BankingType = :keyBankingType";

const std::string strSQLBankingUpdateWithPrim = 
     "UPDATE dbo.Banking\n"
     "SET ID          = :ID,\n"
     "    BankingType = :BankingType,\n"
     "    BankName    = :BankName,\n"
     "    IBAN        = :IBAN,\n"
     "    BIC         = :BIC,\n"
     "    BankOwner   = :BankOwner,\n"
     "    Country     = :Country\n"
     "WHERE ID          = :keyID AND\n"
     "      BankingType = :keyBankingType";

const std::string strSQLBankingUpdateWithoutPrim = 
     "UPDATE dbo.Banking\n"
     "SET BankName  = :BankName,\n"
     "    IBAN      = :IBAN,\n"
     "    BIC       = :BIC,\n"
     "    BankOwner = :BankOwner,\n"
     "    Country   = :Country\n"
     "WHERE ID          = :keyID AND\n"
     "      BankingType = :keyBankingType";

const std::string strSQLBankingDeleteAll = 
     "DELETE FROM dbo.Banking";

const std::string strSQLBankingDeleteDetail = 
     "DELETE FROM dbo.Banking\n"
     "WHERE ID          = :keyID AND\n"
     "      BankingType = :keyBankingType";


// --------------------------------------------------------------------
//   Statements for table / view: BankingTypes
// --------------------------------------------------------------------
const std::string strSQLBankingTypesSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.BankingTypes";

const std::string strSQLBankingTypesSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.BankingTypes\n"
     "WHERE ID = :keyID";

const std::string strSQLBankingTypesUpdateWithPrim = 
     "UPDATE dbo.BankingTypes\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLBankingTypesUpdateWithoutPrim = 
     "UPDATE dbo.BankingTypes\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLBankingTypesDeleteAll = 
     "DELETE FROM dbo.BankingTypes";

const std::string strSQLBankingTypesDeleteDetail = 
     "DELETE FROM dbo.BankingTypes\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Contacts
// --------------------------------------------------------------------
const std::string strSQLContactsSelectAll = 
     "SELECT ContactID, CustID, CustLiaison\n"
     "FROM dbo.Contacts";

const std::string strSQLContactsSelectDetail = 
     "SELECT ContactID, CustID, CustLiaison\n"
     "FROM dbo.Contacts\n"
     "WHERE ContactID = :keyContactID";

const std::string strSQLContactsUpdateWithPrim = 
     "UPDATE dbo.Contacts\n"
     "SET ContactID   = :ContactID,\n"
     "    CustID      = :CustID,\n"
     "    CustLiaison = :CustLiaison\n"
     "WHERE ContactID = :keyContactID";

const std::string strSQLContactsUpdateWithoutPrim = 
     "UPDATE dbo.Contacts\n"
     "SET CustID      = :CustID,\n"
     "    CustLiaison = :CustLiaison\n"
     "WHERE ContactID = :keyContactID";

const std::string strSQLContactsDeleteAll = 
     "DELETE FROM dbo.Contacts";

const std::string strSQLContactsDeleteDetail = 
     "DELETE FROM dbo.Contacts\n"
     "WHERE ContactID = :keyContactID";


// --------------------------------------------------------------------
//   Statements for table / view: CorporateForm
// --------------------------------------------------------------------
const std::string strSQLCorporateFormSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, IsLegalEntrity, UrgentValue\n"
     "FROM dbo.CorporateForm";

const std::string strSQLCorporateFormSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, IsLegalEntrity, UrgentValue\n"
     "FROM dbo.CorporateForm\n"
     "WHERE ID = :keyID";

const std::string strSQLCorporateFormUpdateWithPrim = 
     "UPDATE dbo.CorporateForm\n"
     "SET ID             = :ID,\n"
     "    Denotation     = :Denotation,\n"
     "    Abbreviation   = :Abbreviation,\n"
     "    Description    = :Description,\n"
     "    IsLegalEntrity = :IsLegalEntrity,\n"
     "    UrgentValue    = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLCorporateFormUpdateWithoutPrim = 
     "UPDATE dbo.CorporateForm\n"
     "SET Denotation     = :Denotation,\n"
     "    Abbreviation   = :Abbreviation,\n"
     "    Description    = :Description,\n"
     "    IsLegalEntrity = :IsLegalEntrity,\n"
     "    UrgentValue    = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLCorporateFormDeleteAll = 
     "DELETE FROM dbo.CorporateForm";

const std::string strSQLCorporateFormDeleteDetail = 
     "DELETE FROM dbo.CorporateForm\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Countries
// --------------------------------------------------------------------
const std::string strSQLCountriesSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, CountryDialing, ISO_Code, IsEU,\n"
     "       Capital, Currency, Notes, UrgentValue\n"
     "FROM dbo.Countries";

const std::string strSQLCountriesSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, CountryDialing, ISO_Code, IsEU,\n"
     "       Capital, Currency, Notes, UrgentValue\n"
     "FROM dbo.Countries\n"
     "WHERE ID = :keyID";

const std::string strSQLCountriesUpdateWithPrim = 
     "UPDATE dbo.Countries\n"
     "SET ID             = :ID,\n"
     "    Denotation     = :Denotation,\n"
     "    Abbreviation   = :Abbreviation,\n"
     "    Description    = :Description,\n"
     "    CountryDialing = :CountryDialing,\n"
     "    ISO_Code       = :ISO_Code,\n"
     "    IsEU           = :IsEU,\n"
     "    Capital        = :Capital,\n"
     "    Currency       = :Currency,\n"
     "    Notes          = :Notes,\n"
     "    UrgentValue    = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLCountriesUpdateWithoutPrim = 
     "UPDATE dbo.Countries\n"
     "SET Denotation     = :Denotation,\n"
     "    Abbreviation   = :Abbreviation,\n"
     "    Description    = :Description,\n"
     "    CountryDialing = :CountryDialing,\n"
     "    ISO_Code       = :ISO_Code,\n"
     "    IsEU           = :IsEU,\n"
     "    Capital        = :Capital,\n"
     "    Currency       = :Currency,\n"
     "    Notes          = :Notes,\n"
     "    UrgentValue    = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLCountriesDeleteAll = 
     "DELETE FROM dbo.Countries";

const std::string strSQLCountriesDeleteDetail = 
     "DELETE FROM dbo.Countries\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: CustClassification
// --------------------------------------------------------------------
const std::string strSQLCustClassificationSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.CustClassification";

const std::string strSQLCustClassificationSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.CustClassification\n"
     "WHERE ID = :keyID";

const std::string strSQLCustClassificationUpdateWithPrim = 
     "UPDATE dbo.CustClassification\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLCustClassificationUpdateWithoutPrim = 
     "UPDATE dbo.CustClassification\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLCustClassificationDeleteAll = 
     "DELETE FROM dbo.CustClassification";

const std::string strSQLCustClassificationDeleteDetail = 
     "DELETE FROM dbo.CustClassification\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: CustLiaison
// --------------------------------------------------------------------
const std::string strSQLCustLiaisonSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.CustLiaison";

const std::string strSQLCustLiaisonSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.CustLiaison\n"
     "WHERE ID = :keyID";

const std::string strSQLCustLiaisonUpdateWithPrim = 
     "UPDATE dbo.CustLiaison\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLCustLiaisonUpdateWithoutPrim = 
     "UPDATE dbo.CustLiaison\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLCustLiaisonDeleteAll = 
     "DELETE FROM dbo.CustLiaison";

const std::string strSQLCustLiaisonDeleteDetail = 
     "DELETE FROM dbo.CustLiaison\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Customers
// --------------------------------------------------------------------
const std::string strSQLCustomersSelectAll = 
     "SELECT CustID, ServiceAgent, CustClassification, LegalForm\n"
     "FROM dbo.Customers";

const std::string strSQLCustomersSelectDetail = 
     "SELECT CustID, ServiceAgent, CustClassification, LegalForm\n"
     "FROM dbo.Customers\n"
     "WHERE CustID = :keyCustID";

const std::string strSQLCustomersUpdateWithPrim = 
     "UPDATE dbo.Customers\n"
     "SET CustID             = :CustID,\n"
     "    ServiceAgent       = :ServiceAgent,\n"
     "    CustClassification = :CustClassification,\n"
     "    LegalForm          = :LegalForm\n"
     "WHERE CustID = :keyCustID";

const std::string strSQLCustomersUpdateWithoutPrim = 
     "UPDATE dbo.Customers\n"
     "SET ServiceAgent       = :ServiceAgent,\n"
     "    CustClassification = :CustClassification,\n"
     "    LegalForm          = :LegalForm\n"
     "WHERE CustID = :keyCustID";

const std::string strSQLCustomersDeleteAll = 
     "DELETE FROM dbo.Customers";

const std::string strSQLCustomersDeleteDetail = 
     "DELETE FROM dbo.Customers\n"
     "WHERE CustID = :keyCustID";


// --------------------------------------------------------------------
//   Statements for table / view: Departments
// --------------------------------------------------------------------
const std::string strSQLDepartmentsSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Officer, Notes\n"
     "FROM dbo.Departments";

const std::string strSQLDepartmentsSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Officer, Notes\n"
     "FROM dbo.Departments\n"
     "WHERE ID = :keyID";

const std::string strSQLDepartmentsUpdateWithPrim = 
     "UPDATE dbo.Departments\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Officer      = :Officer,\n"
     "    Notes        = :Notes\n"
     "WHERE ID = :keyID";

const std::string strSQLDepartmentsUpdateWithoutPrim = 
     "UPDATE dbo.Departments\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Officer      = :Officer,\n"
     "    Notes        = :Notes\n"
     "WHERE ID = :keyID";

const std::string strSQLDepartmentsDeleteAll = 
     "DELETE FROM dbo.Departments";

const std::string strSQLDepartmentsDeleteDetail = 
     "DELETE FROM dbo.Departments\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Employees
// --------------------------------------------------------------------
const std::string strSQLEmployeesSelectAll = 
     "SELECT Dummy, EmployeeID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob,\n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, Department,\n"
     "       SocialNummer, Active\n"
     "FROM dbo.Employees";

const std::string strSQLEmployeesSelectDetail = 
     "SELECT Dummy, EmployeeID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob,\n"
     "       EndOfJob, ReasonDeparture, JobPosition, JobSpec, VacationDays, Department,\n"
     "       SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE EmployeeID = :keyEmployeeID";

const std::string strSQLEmployeesUpdateWithPrim = 
     "UPDATE dbo.Employees\n"
     "SET Dummy           = :Dummy,\n"
     "    EmployeeID      = :EmployeeID,\n"
     "    PersonNumber    = :PersonNumber,\n"
     "    Salary          = :Salary,\n"
     "    SalaryType      = :SalaryType,\n"
     "    TaxClass        = :TaxClass,\n"
     "    StartOfJob      = :StartOfJob,\n"
     "    EndOfJob        = :EndOfJob,\n"
     "    ReasonDeparture = :ReasonDeparture,\n"
     "    JobPosition     = :JobPosition,\n"
     "    JobSpec         = :JobSpec,\n"
     "    VacationDays    = :VacationDays,\n"
     "    Department      = :Department,\n"
     "    SocialNummer    = :SocialNummer,\n"
     "    Active          = :Active\n"
     "WHERE EmployeeID = :keyEmployeeID";

const std::string strSQLEmployeesUpdateWithoutPrim = 
     "UPDATE dbo.Employees\n"
     "SET Dummy           = :Dummy,\n"
     "    PersonNumber    = :PersonNumber,\n"
     "    Salary          = :Salary,\n"
     "    SalaryType      = :SalaryType,\n"
     "    TaxClass        = :TaxClass,\n"
     "    StartOfJob      = :StartOfJob,\n"
     "    EndOfJob        = :EndOfJob,\n"
     "    ReasonDeparture = :ReasonDeparture,\n"
     "    JobPosition     = :JobPosition,\n"
     "    JobSpec         = :JobSpec,\n"
     "    VacationDays    = :VacationDays,\n"
     "    Department      = :Department,\n"
     "    SocialNummer    = :SocialNummer,\n"
     "    Active          = :Active\n"
     "WHERE EmployeeID = :keyEmployeeID";

const std::string strSQLEmployeesDeleteAll = 
     "DELETE FROM dbo.Employees";

const std::string strSQLEmployeesDeleteDetail = 
     "DELETE FROM dbo.Employees\n"
     "WHERE EmployeeID = :keyEmployeeID";


// --------------------------------------------------------------------
//   Statements for table / view: FamilyStatus
// --------------------------------------------------------------------
const std::string strSQLFamilyStatusSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Coupled, NeedDate, Notes, UrgentValue\n"
     "FROM dbo.FamilyStatus";

const std::string strSQLFamilyStatusSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Coupled, NeedDate, Notes, UrgentValue\n"
     "FROM dbo.FamilyStatus\n"
     "WHERE ID = :keyID";

const std::string strSQLFamilyStatusUpdateWithPrim = 
     "UPDATE dbo.FamilyStatus\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Coupled      = :Coupled,\n"
     "    NeedDate     = :NeedDate,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLFamilyStatusUpdateWithoutPrim = 
     "UPDATE dbo.FamilyStatus\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Coupled      = :Coupled,\n"
     "    NeedDate     = :NeedDate,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLFamilyStatusDeleteAll = 
     "DELETE FROM dbo.FamilyStatus";

const std::string strSQLFamilyStatusDeleteDetail = 
     "DELETE FROM dbo.FamilyStatus\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: FamilyTypes
// --------------------------------------------------------------------
const std::string strSQLFamilyTypesSelectAll = 
     "SELECT ID, Denotation, Abbreviation, IsNaturalPerson, Description, Notes, UrgentValue\n"
     "FROM dbo.FamilyTypes";

const std::string strSQLFamilyTypesSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, IsNaturalPerson, Description, Notes, UrgentValue\n"
     "FROM dbo.FamilyTypes\n"
     "WHERE ID = :keyID";

const std::string strSQLFamilyTypesUpdateWithPrim = 
     "UPDATE dbo.FamilyTypes\n"
     "SET ID              = :ID,\n"
     "    Denotation      = :Denotation,\n"
     "    Abbreviation    = :Abbreviation,\n"
     "    IsNaturalPerson = :IsNaturalPerson,\n"
     "    Description     = :Description,\n"
     "    Notes           = :Notes,\n"
     "    UrgentValue     = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLFamilyTypesUpdateWithoutPrim = 
     "UPDATE dbo.FamilyTypes\n"
     "SET Denotation      = :Denotation,\n"
     "    Abbreviation    = :Abbreviation,\n"
     "    IsNaturalPerson = :IsNaturalPerson,\n"
     "    Description     = :Description,\n"
     "    Notes           = :Notes,\n"
     "    UrgentValue     = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLFamilyTypesDeleteAll = 
     "DELETE FROM dbo.FamilyTypes";

const std::string strSQLFamilyTypesDeleteDetail = 
     "DELETE FROM dbo.FamilyTypes\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: FormOfAddress
// --------------------------------------------------------------------
const std::string strSQLFormOfAddressSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, TypeSpec, Salutation, Valediction,\n"
     "       Notes, UrgentValue\n"
     "FROM dbo.FormOfAddress";

const std::string strSQLFormOfAddressSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, TypeSpec, Salutation, Valediction,\n"
     "       Notes, UrgentValue\n"
     "FROM dbo.FormOfAddress\n"
     "WHERE ID = :keyID";

const std::string strSQLFormOfAddressUpdateWithPrim = 
     "UPDATE dbo.FormOfAddress\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    TypeSpec     = :TypeSpec,\n"
     "    Salutation   = :Salutation,\n"
     "    Valediction  = :Valediction,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLFormOfAddressUpdateWithoutPrim = 
     "UPDATE dbo.FormOfAddress\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    TypeSpec     = :TypeSpec,\n"
     "    Salutation   = :Salutation,\n"
     "    Valediction  = :Valediction,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLFormOfAddressDeleteAll = 
     "DELETE FROM dbo.FormOfAddress";

const std::string strSQLFormOfAddressDeleteDetail = 
     "DELETE FROM dbo.FormOfAddress\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Internet
// --------------------------------------------------------------------
const std::string strSQLInternetSelectAll = 
     "SELECT ID, InternetType, Adresse\n"
     "FROM dbo.Internet";

const std::string strSQLInternetSelectDetail = 
     "SELECT ID, InternetType, Adresse\n"
     "FROM dbo.Internet\n"
     "WHERE ID           = :keyID AND\n"
     "      InternetType = :keyInternetType";

const std::string strSQLInternetUpdateWithPrim = 
     "UPDATE dbo.Internet\n"
     "SET ID           = :ID,\n"
     "    InternetType = :InternetType,\n"
     "    Adresse      = :Adresse\n"
     "WHERE ID           = :keyID AND\n"
     "      InternetType = :keyInternetType";

const std::string strSQLInternetUpdateWithoutPrim = 
     "UPDATE dbo.Internet\n"
     "SET Adresse = :Adresse\n"
     "WHERE ID           = :keyID AND\n"
     "      InternetType = :keyInternetType";

const std::string strSQLInternetDeleteAll = 
     "DELETE FROM dbo.Internet";

const std::string strSQLInternetDeleteDetail = 
     "DELETE FROM dbo.Internet\n"
     "WHERE ID           = :keyID AND\n"
     "      InternetType = :keyInternetType";


// --------------------------------------------------------------------
//   Statements for table / view: InternetTypes
// --------------------------------------------------------------------
const std::string strSQLInternetTypesSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Prefix, Notes, UrgentValue\n"
     "FROM dbo.InternetTypes";

const std::string strSQLInternetTypesSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Prefix, Notes, UrgentValue\n"
     "FROM dbo.InternetTypes\n"
     "WHERE ID = :keyID";

const std::string strSQLInternetTypesUpdateWithPrim = 
     "UPDATE dbo.InternetTypes\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Prefix       = :Prefix,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLInternetTypesUpdateWithoutPrim = 
     "UPDATE dbo.InternetTypes\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Prefix       = :Prefix,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLInternetTypesDeleteAll = 
     "DELETE FROM dbo.InternetTypes";

const std::string strSQLInternetTypesDeleteDetail = 
     "DELETE FROM dbo.InternetTypes\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: JobPositions
// --------------------------------------------------------------------
const std::string strSQLJobPositionsSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, SalaryType, Notes, UrgentValue\n"
     "FROM dbo.JobPositions";

const std::string strSQLJobPositionsSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, SalaryType, Notes, UrgentValue\n"
     "FROM dbo.JobPositions\n"
     "WHERE ID = :keyID";

const std::string strSQLJobPositionsUpdateWithPrim = 
     "UPDATE dbo.JobPositions\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    SalaryType   = :SalaryType,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLJobPositionsUpdateWithoutPrim = 
     "UPDATE dbo.JobPositions\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    SalaryType   = :SalaryType,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLJobPositionsDeleteAll = 
     "DELETE FROM dbo.JobPositions";

const std::string strSQLJobPositionsDeleteDetail = 
     "DELETE FROM dbo.JobPositions\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Person
// --------------------------------------------------------------------
const std::string strSQLPersonSelectAll = 
     "SELECT ID, Name, Firstname, FormOfAddress, FamilyStatus, FamilyStatusSince, Birthday,\n"
     "       Notes, FullName\n"
     "FROM dbo.Person";

const std::string strSQLPersonSelectDetail = 
     "SELECT ID, Name, Firstname, FormOfAddress, FamilyStatus, FamilyStatusSince, Birthday,\n"
     "       Notes, FullName\n"
     "FROM dbo.Person\n"
     "WHERE ID = :keyID";

const std::string strSQLPersonUpdateWithPrim = 
     "UPDATE dbo.Person\n"
     "SET ID                = :ID,\n"
     "    Name              = :Name,\n"
     "    Firstname         = :Firstname,\n"
     "    FormOfAddress     = :FormOfAddress,\n"
     "    FamilyStatus      = :FamilyStatus,\n"
     "    FamilyStatusSince = :FamilyStatusSince,\n"
     "    Birthday          = :Birthday,\n"
     "    Notes             = :Notes,\n"
     "    FullName          = :FullName\n"
     "WHERE ID = :keyID";

const std::string strSQLPersonUpdateWithoutPrim = 
     "UPDATE dbo.Person\n"
     "SET Name              = :Name,\n"
     "    Firstname         = :Firstname,\n"
     "    FormOfAddress     = :FormOfAddress,\n"
     "    FamilyStatus      = :FamilyStatus,\n"
     "    FamilyStatusSince = :FamilyStatusSince,\n"
     "    Birthday          = :Birthday,\n"
     "    Notes             = :Notes,\n"
     "    FullName          = :FullName\n"
     "WHERE ID = :keyID";

const std::string strSQLPersonDeleteAll = 
     "DELETE FROM dbo.Person";

const std::string strSQLPersonDeleteDetail = 
     "DELETE FROM dbo.Person\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Phone
// --------------------------------------------------------------------
const std::string strSQLPhoneSelectAll = 
     "SELECT ID, PhoneType, AreaCode, CallNumber, Country, DialingNational, DialingInternational\n"
     "FROM dbo.Phone";

const std::string strSQLPhoneSelectDetail = 
     "SELECT ID, PhoneType, AreaCode, CallNumber, Country, DialingNational, DialingInternational\n"
     "FROM dbo.Phone\n"
     "WHERE ID        = :keyID AND\n"
     "      PhoneType = :keyPhoneType";

const std::string strSQLPhoneUpdateWithPrim = 
     "UPDATE dbo.Phone\n"
     "SET ID                   = :ID,\n"
     "    PhoneType            = :PhoneType,\n"
     "    AreaCode             = :AreaCode,\n"
     "    CallNumber           = :CallNumber,\n"
     "    Country              = :Country,\n"
     "    DialingNational      = :DialingNational,\n"
     "    DialingInternational = :DialingInternational\n"
     "WHERE ID        = :keyID AND\n"
     "      PhoneType = :keyPhoneType";

const std::string strSQLPhoneUpdateWithoutPrim = 
     "UPDATE dbo.Phone\n"
     "SET AreaCode             = :AreaCode,\n"
     "    CallNumber           = :CallNumber,\n"
     "    Country              = :Country,\n"
     "    DialingNational      = :DialingNational,\n"
     "    DialingInternational = :DialingInternational\n"
     "WHERE ID        = :keyID AND\n"
     "      PhoneType = :keyPhoneType";

const std::string strSQLPhoneDeleteAll = 
     "DELETE FROM dbo.Phone";

const std::string strSQLPhoneDeleteDetail = 
     "DELETE FROM dbo.Phone\n"
     "WHERE ID        = :keyID AND\n"
     "      PhoneType = :keyPhoneType";


// --------------------------------------------------------------------
//   Statements for table / view: PhonesTypes
// --------------------------------------------------------------------
const std::string strSQLPhonesTypesSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.PhoneTypes";

const std::string strSQLPhonesTypesSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.PhoneTypes\n"
     "WHERE ID = :keyID";

const std::string strSQLPhonesTypesUpdateWithPrim = 
     "UPDATE dbo.PhoneTypes\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLPhonesTypesUpdateWithoutPrim = 
     "UPDATE dbo.PhoneTypes\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLPhonesTypesDeleteAll = 
     "DELETE FROM dbo.PhoneTypes";

const std::string strSQLPhonesTypesDeleteDetail = 
     "DELETE FROM dbo.PhoneTypes\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: ReasonDeparture
// --------------------------------------------------------------------
const std::string strSQLReasonDepartureSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.ReasonDeparture";

const std::string strSQLReasonDepartureSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.ReasonDeparture\n"
     "WHERE ID = :keyID";

const std::string strSQLReasonDepartureUpdateWithPrim = 
     "UPDATE dbo.ReasonDeparture\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLReasonDepartureUpdateWithoutPrim = 
     "UPDATE dbo.ReasonDeparture\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLReasonDepartureDeleteAll = 
     "DELETE FROM dbo.ReasonDeparture";

const std::string strSQLReasonDepartureDeleteDetail = 
     "DELETE FROM dbo.ReasonDeparture\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: ReasonNonWorking
// --------------------------------------------------------------------
const std::string strSQLReasonNonWorkingSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.ReasonNonWorking";

const std::string strSQLReasonNonWorkingSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.ReasonNonWorking\n"
     "WHERE ID = :keyID";

const std::string strSQLReasonNonWorkingUpdateWithPrim = 
     "UPDATE dbo.ReasonNonWorking\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLReasonNonWorkingUpdateWithoutPrim = 
     "UPDATE dbo.ReasonNonWorking\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Notes        = :Notes,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLReasonNonWorkingDeleteAll = 
     "DELETE FROM dbo.ReasonNonWorking";

const std::string strSQLReasonNonWorkingDeleteDetail = 
     "DELETE FROM dbo.ReasonNonWorking\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: SalaryBase
// --------------------------------------------------------------------
const std::string strSQLSalaryBaseSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, UrgentValue\n"
     "FROM dbo.SalaryBase";

const std::string strSQLSalaryBaseSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, UrgentValue\n"
     "FROM dbo.SalaryBase\n"
     "WHERE ID = :keyID";

const std::string strSQLSalaryBaseUpdateWithPrim = 
     "UPDATE dbo.SalaryBase\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLSalaryBaseUpdateWithoutPrim = 
     "UPDATE dbo.SalaryBase\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLSalaryBaseDeleteAll = 
     "DELETE FROM dbo.SalaryBase";

const std::string strSQLSalaryBaseDeleteDetail = 
     "DELETE FROM dbo.SalaryBase\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: SalaryType
// --------------------------------------------------------------------
const std::string strSQLSalaryTypeSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, SalaryBase, UrgentValue\n"
     "FROM dbo.SalaryType";

const std::string strSQLSalaryTypeSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, SalaryBase, UrgentValue\n"
     "FROM dbo.SalaryType\n"
     "WHERE ID = :keyID";

const std::string strSQLSalaryTypeUpdateWithPrim = 
     "UPDATE dbo.SalaryType\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    SalaryBase   = :SalaryBase,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLSalaryTypeUpdateWithoutPrim = 
     "UPDATE dbo.SalaryType\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    SalaryBase   = :SalaryBase,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLSalaryTypeDeleteAll = 
     "DELETE FROM dbo.SalaryType";

const std::string strSQLSalaryTypeDeleteDetail = 
     "DELETE FROM dbo.SalaryType\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: TaxClasses
// --------------------------------------------------------------------
const std::string strSQLTaxClassesSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Coupled, UrgentValue\n"
     "FROM dbo.TaxClasses";

const std::string strSQLTaxClassesSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Coupled, UrgentValue\n"
     "FROM dbo.TaxClasses\n"
     "WHERE ID = :keyID";

const std::string strSQLTaxClassesUpdateWithPrim = 
     "UPDATE dbo.TaxClasses\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Coupled      = :Coupled,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLTaxClassesUpdateWithoutPrim = 
     "UPDATE dbo.TaxClasses\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Description  = :Description,\n"
     "    Coupled      = :Coupled,\n"
     "    UrgentValue  = :UrgentValue\n"
     "WHERE ID = :keyID";

const std::string strSQLTaxClassesDeleteAll = 
     "DELETE FROM dbo.TaxClasses";

const std::string strSQLTaxClassesDeleteDetail = 
     "DELETE FROM dbo.TaxClasses\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Holidays
// --------------------------------------------------------------------
const std::string strSQLWD_HolidaysSelectAll = 
     "SELECT CalendarDay, Donation, Share, Description\n"
     "FROM dbo.WD_Holidays";

const std::string strSQLWD_HolidaysSelectDetail = 
     "SELECT CalendarDay, Donation, Share, Description\n"
     "FROM dbo.WD_Holidays\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLWD_HolidaysUpdateWithPrim = 
     "UPDATE dbo.WD_Holidays\n"
     "SET CalendarDay = :CalendarDay,\n"
     "    Donation    = :Donation,\n"
     "    Share       = :Share,\n"
     "    Description = :Description\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLWD_HolidaysUpdateWithoutPrim = 
     "UPDATE dbo.WD_Holidays\n"
     "SET Donation    = :Donation,\n"
     "    Share       = :Share,\n"
     "    Description = :Description\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLWD_HolidaysDeleteAll = 
     "DELETE FROM dbo.WD_Holidays";

const std::string strSQLWD_HolidaysDeleteDetail = 
     "DELETE FROM dbo.WD_Holidays\n"
     "WHERE CalendarDay = :keyCalendarDay";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Months
// --------------------------------------------------------------------
const std::string strSQLWD_MonthsSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Quarter\n"
     "FROM dbo.WD_Months";

const std::string strSQLWD_MonthsSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Quarter\n"
     "FROM dbo.WD_Months\n"
     "WHERE ID = :keyID";

const std::string strSQLWD_MonthsUpdateWithPrim = 
     "UPDATE dbo.WD_Months\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Quarter      = :Quarter\n"
     "WHERE ID = :keyID";

const std::string strSQLWD_MonthsUpdateWithoutPrim = 
     "UPDATE dbo.WD_Months\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Quarter      = :Quarter\n"
     "WHERE ID = :keyID";

const std::string strSQLWD_MonthsDeleteAll = 
     "DELETE FROM dbo.WD_Months";

const std::string strSQLWD_MonthsDeleteDetail = 
     "DELETE FROM dbo.WD_Months\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: WD_NonWorking
// --------------------------------------------------------------------
const std::string strSQLWD_NonWorkingSelectAll = 
     "SELECT ID, StartAt, ClosingAt, Reason, Notes\n"
     "FROM dbo.WD_NonWorking";

const std::string strSQLWD_NonWorkingSelectDetail = 
     "SELECT ID, StartAt, ClosingAt, Reason, Notes\n"
     "FROM dbo.WD_NonWorking\n"
     "WHERE ID      = :keyID AND\n"
     "      StartAt = :keyStartAt";

const std::string strSQLWD_NonWorkingUpdateWithPrim = 
     "UPDATE dbo.WD_NonWorking\n"
     "SET ID        = :ID,\n"
     "    StartAt   = :StartAt,\n"
     "    ClosingAt = :ClosingAt,\n"
     "    Reason    = :Reason,\n"
     "    Notes     = :Notes\n"
     "WHERE ID      = :keyID AND\n"
     "      StartAt = :keyStartAt";

const std::string strSQLWD_NonWorkingUpdateWithoutPrim = 
     "UPDATE dbo.WD_NonWorking\n"
     "SET ClosingAt = :ClosingAt,\n"
     "    Reason    = :Reason,\n"
     "    Notes     = :Notes\n"
     "WHERE ID      = :keyID AND\n"
     "      StartAt = :keyStartAt";

const std::string strSQLWD_NonWorkingDeleteAll = 
     "DELETE FROM dbo.WD_NonWorking";

const std::string strSQLWD_NonWorkingDeleteDetail = 
     "DELETE FROM dbo.WD_NonWorking\n"
     "WHERE ID      = :keyID AND\n"
     "      StartAt = :keyStartAt";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Weekdays
// --------------------------------------------------------------------
const std::string strSQLWD_WeekdaysSelectAll = 
     "SELECT ID, Denotation, Abbreviation, Workday\n"
     "FROM dbo.WD_Weekdays";

const std::string strSQLWD_WeekdaysSelectDetail = 
     "SELECT ID, Denotation, Abbreviation, Workday\n"
     "FROM dbo.WD_Weekdays\n"
     "WHERE ID = :keyID";

const std::string strSQLWD_WeekdaysUpdateWithPrim = 
     "UPDATE dbo.WD_Weekdays\n"
     "SET ID           = :ID,\n"
     "    Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Workday      = :Workday\n"
     "WHERE ID = :keyID";

const std::string strSQLWD_WeekdaysUpdateWithoutPrim = 
     "UPDATE dbo.WD_Weekdays\n"
     "SET Denotation   = :Denotation,\n"
     "    Abbreviation = :Abbreviation,\n"
     "    Workday      = :Workday\n"
     "WHERE ID = :keyID";

const std::string strSQLWD_WeekdaysDeleteAll = 
     "DELETE FROM dbo.WD_Weekdays";

const std::string strSQLWD_WeekdaysDeleteDetail = 
     "DELETE FROM dbo.WD_Weekdays\n"
     "WHERE ID = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Workdays
// --------------------------------------------------------------------
const std::string strSQLWD_WorkdaysSelectAll = 
     "SELECT CalendarDay, CalendarWeekday, CalendarWeek, CalendarYear, CalendarMonth,\n"
     "       CalendarDayInWeek, CalendarDayInYear, CalendarQuarter, Workday\n"
     "FROM dbo.WD_Workdays";

const std::string strSQLWD_WorkdaysSelectDetail = 
     "SELECT CalendarDay, CalendarWeekday, CalendarWeek, CalendarYear, CalendarMonth,\n"
     "       CalendarDayInWeek, CalendarDayInYear, CalendarQuarter, Workday\n"
     "FROM dbo.WD_Workdays\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLWD_WorkdaysUpdateWithPrim = 
     "UPDATE dbo.WD_Workdays\n"
     "SET CalendarDay       = :CalendarDay,\n"
     "    CalendarWeekday   = :CalendarWeekday,\n"
     "    CalendarWeek      = :CalendarWeek,\n"
     "    CalendarYear      = :CalendarYear,\n"
     "    CalendarMonth     = :CalendarMonth,\n"
     "    CalendarDayInWeek = :CalendarDayInWeek,\n"
     "    CalendarDayInYear = :CalendarDayInYear,\n"
     "    CalendarQuarter   = :CalendarQuarter,\n"
     "    Workday           = :Workday\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLWD_WorkdaysUpdateWithoutPrim = 
     "UPDATE dbo.WD_Workdays\n"
     "SET CalendarWeekday   = :CalendarWeekday,\n"
     "    CalendarWeek      = :CalendarWeek,\n"
     "    CalendarYear      = :CalendarYear,\n"
     "    CalendarMonth     = :CalendarMonth,\n"
     "    CalendarDayInWeek = :CalendarDayInWeek,\n"
     "    CalendarDayInYear = :CalendarDayInYear,\n"
     "    CalendarQuarter   = :CalendarQuarter,\n"
     "    Workday           = :Workday\n"
     "WHERE CalendarDay = :keyCalendarDay";

const std::string strSQLWD_WorkdaysDeleteAll = 
     "DELETE FROM dbo.WD_Workdays";

const std::string strSQLWD_WorkdaysDeleteDetail = 
     "DELETE FROM dbo.WD_Workdays\n"
     "WHERE CalendarDay = :keyCalendarDay";


// --------------------------------------------------------------------
//   Statements for table / view: WorkingTime
// --------------------------------------------------------------------
const std::string strSQLWorkingTimeSelectAll = 
     "SELECT ID, StartingTime, ClosingTime, Processed , ProcessedAt, DayOfWork\n"
     "FROM dbo.WorkingTime";

const std::string strSQLWorkingTimeSelectDetail = 
     "SELECT ID, StartingTime, ClosingTime, Processed , ProcessedAt, DayOfWork\n"
     "FROM dbo.WorkingTime\n"
     "WHERE ID           = :keyID AND\n"
     "      StartingTime = :keyStartingTime";

const std::string strSQLWorkingTimeUpdateWithPrim = 
     "UPDATE dbo.WorkingTime\n"
     "SET ID           = :ID,\n"
     "    StartingTime = :StartingTime,\n"
     "    ClosingTime  = :ClosingTime,\n"
     "    Processed    = :Processed ,\n"
     "    ProcessedAt  = :ProcessedAt,\n"
     "    DayOfWork    = :DayOfWork\n"
     "WHERE ID           = :keyID AND\n"
     "      StartingTime = :keyStartingTime";

const std::string strSQLWorkingTimeUpdateWithoutPrim = 
     "UPDATE dbo.WorkingTime\n"
     "SET ClosingTime = :ClosingTime,\n"
     "    Processed   = :Processed ,\n"
     "    ProcessedAt = :ProcessedAt,\n"
     "    DayOfWork   = :DayOfWork\n"
     "WHERE ID           = :keyID AND\n"
     "      StartingTime = :keyStartingTime";

const std::string strSQLWorkingTimeDeleteAll = 
     "DELETE FROM dbo.WorkingTime";

const std::string strSQLWorkingTimeDeleteDetail = 
     "DELETE FROM dbo.WorkingTime\n"
     "WHERE ID           = :keyID AND\n"
     "      StartingTime = :keyStartingTime";



} // close namespace reader
