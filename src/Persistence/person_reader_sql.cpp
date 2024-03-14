/*
* Project: model with a simple person administration
* Implementation of sql statement for access with class TPersonReader
* Date: 14.03.2024 23:56:54,451  file created with adecc Scholar metadata generator
* copyright (c) adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include <Persistence\person_reader_sql.h>

namespace reader {

// --------------------------------------------------------------------
//   Statements for table / view: Address
// --------------------------------------------------------------------
const std::string strSQLAddressAll = 
     "SELECT ID, AddressType, Zipcode, City, Street, StreetNumber, Country\n"
     "FROM dbo.Address";

const std::string strSQLAddressDetail = 
     "SELECT ID, AddressType, Zipcode, City, Street, StreetNumber, Country\n"
     "FROM dbo.Address\n"
     "WHERE ID           = :keyID AND\n"
     "      AddressType  = :keyAddressType";


// --------------------------------------------------------------------
//   Statements for table / view: AddressTypes
// --------------------------------------------------------------------
const std::string strSQLAddressTypesAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.AddressTypes";

const std::string strSQLAddressTypesDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.AddressTypes\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Banking
// --------------------------------------------------------------------
const std::string strSQLBankingAll = 
     "SELECT ID, BankingType, BankName, IBAN, BIC, BankOwner, Country\n"
     "FROM dbo.Banking";

const std::string strSQLBankingDetail = 
     "SELECT ID, BankingType, BankName, IBAN, BIC, BankOwner, Country\n"
     "FROM dbo.Banking\n"
     "WHERE ID           = :keyID AND\n"
     "      BankingType  = :keyBankingType";


// --------------------------------------------------------------------
//   Statements for table / view: BankingTypes
// --------------------------------------------------------------------
const std::string strSQLBankingTypesAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.BankingTypes";

const std::string strSQLBankingTypesDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.BankingTypes\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Countries
// --------------------------------------------------------------------
const std::string strSQLCountriesAll = 
     "SELECT ID, Denotation, Abbreviation, Description, CountryDialing, ISO_Code, IsEU,\n"
     "       Capital, Currency, Notes, UrgentValue\n"
     "FROM dbo.Countries";

const std::string strSQLCountriesDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, CountryDialing, ISO_Code, IsEU,\n"
     "       Capital, Currency, Notes, UrgentValue\n"
     "FROM dbo.Countries\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Departments
// --------------------------------------------------------------------
const std::string strSQLDepartmentsAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Officer, Notes\n"
     "FROM dbo.Departments";

const std::string strSQLDepartmentsDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Officer, Notes\n"
     "FROM dbo.Departments\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Employees
// --------------------------------------------------------------------
const std::string strSQLEmployeesAll = 
     "SELECT ID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, EndOfJob, ReasonDeparture,\n"
     "       JobPosition, JobSpec, VacationDays, Department, SocialNummer, Active\n"
     "FROM dbo.Employees";

const std::string strSQLEmployeesDetail = 
     "SELECT ID, PersonNumber, Salary, SalaryType, TaxClass, StartOfJob, EndOfJob, ReasonDeparture,\n"
     "       JobPosition, JobSpec, VacationDays, Department, SocialNummer, Active\n"
     "FROM dbo.Employees\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: FamilyStatus
// --------------------------------------------------------------------
const std::string strSQLFamilyStatusAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Coupled, NeedDate, Notes, UrgentValue\n"
     "FROM dbo.FamilyStatus";

const std::string strSQLFamilyStatusDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Coupled, NeedDate, Notes, UrgentValue\n"
     "FROM dbo.FamilyStatus\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: FamilyTypes
// --------------------------------------------------------------------
const std::string strSQLFamilyTypesAll = 
     "SELECT ID, Denotation, Abbreviation, IsNaturalPerson, Description, Notes, UrgentValue\n"
     "FROM dbo.FamilyTypes";

const std::string strSQLFamilyTypesDetail = 
     "SELECT ID, Denotation, Abbreviation, IsNaturalPerson, Description, Notes, UrgentValue\n"
     "FROM dbo.FamilyTypes\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: FormOfAddress
// --------------------------------------------------------------------
const std::string strSQLFormOfAddressAll = 
     "SELECT ID, Denotation, Abbreviation, Description, TypeSpec, Salutation, Valediction,\n"
     "       Notes, UrgentValue\n"
     "FROM dbo.FormOfAddress";

const std::string strSQLFormOfAddressDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, TypeSpec, Salutation, Valediction,\n"
     "       Notes, UrgentValue\n"
     "FROM dbo.FormOfAddress\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Internet
// --------------------------------------------------------------------
const std::string strSQLInternetAll = 
     "SELECT ID, InternetType, Adresse\n"
     "FROM dbo.Internet";

const std::string strSQLInternetDetail = 
     "SELECT ID, InternetType, Adresse\n"
     "FROM dbo.Internet\n"
     "WHERE ID            = :keyID AND\n"
     "      InternetType  = :keyInternetType";


// --------------------------------------------------------------------
//   Statements for table / view: InternetTypes
// --------------------------------------------------------------------
const std::string strSQLInternetTypesAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Prefix, Notes, UrgentValue\n"
     "FROM dbo.InternetTypes";

const std::string strSQLInternetTypesDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Prefix, Notes, UrgentValue\n"
     "FROM dbo.InternetTypes\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: JobPositions
// --------------------------------------------------------------------
const std::string strSQLJobPositionsAll = 
     "SELECT ID, Denotation, Abbreviation, Description, SalaryType, Notes, UrgentValue\n"
     "FROM dbo.JobPositions";

const std::string strSQLJobPositionsDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, SalaryType, Notes, UrgentValue\n"
     "FROM dbo.JobPositions\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Person
// --------------------------------------------------------------------
const std::string strSQLPersonAll = 
     "SELECT ID, Name, Firstname, FormOfAddress, FamilyStatus, FamilyStatusSince, Birthday,\n"
     "       Notes, FullName\n"
     "FROM dbo.Person";

const std::string strSQLPersonDetail = 
     "SELECT ID, Name, Firstname, FormOfAddress, FamilyStatus, FamilyStatusSince, Birthday,\n"
     "       Notes, FullName\n"
     "FROM dbo.Person\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: Phone
// --------------------------------------------------------------------
const std::string strSQLPhoneAll = 
     "SELECT ID, PhoneType, AreaCode, CallNumber, Country, DialingNational, DialingInternational\n"
     "FROM dbo.Phone";

const std::string strSQLPhoneDetail = 
     "SELECT ID, PhoneType, AreaCode, CallNumber, Country, DialingNational, DialingInternational\n"
     "FROM dbo.Phone\n"
     "WHERE ID         = :keyID AND\n"
     "      PhoneType  = :keyPhoneType";


// --------------------------------------------------------------------
//   Statements for table / view: PhonesTypes
// --------------------------------------------------------------------
const std::string strSQLPhonesTypesAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.PhoneTypes";

const std::string strSQLPhonesTypesDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.PhoneTypes\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: ReasonDeparture
// --------------------------------------------------------------------
const std::string strSQLReasonDepartureAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.ReasonDeparture";

const std::string strSQLReasonDepartureDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.ReasonDeparture\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: ReasonNonWorking
// --------------------------------------------------------------------
const std::string strSQLReasonNonWorkingAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.ReasonNonWorking";

const std::string strSQLReasonNonWorkingDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Notes, UrgentValue\n"
     "FROM dbo.ReasonNonWorking\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: SalaryBase
// --------------------------------------------------------------------
const std::string strSQLSalaryBaseAll = 
     "SELECT ID, Denotation, Abbreviation, Description, UrgentValue\n"
     "FROM dbo.SalaryBase";

const std::string strSQLSalaryBaseDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, UrgentValue\n"
     "FROM dbo.SalaryBase\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: SalaryType
// --------------------------------------------------------------------
const std::string strSQLSalaryTypeAll = 
     "SELECT ID, Denotation, Abbreviation, Description, SalaryBase, UrgentValue\n"
     "FROM dbo.SalaryType";

const std::string strSQLSalaryTypeDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, SalaryBase, UrgentValue\n"
     "FROM dbo.SalaryType\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: TaxClasses
// --------------------------------------------------------------------
const std::string strSQLTaxClassesAll = 
     "SELECT ID, Denotation, Abbreviation, Description, Coupled, UrgentValue\n"
     "FROM dbo.TaxClasses";

const std::string strSQLTaxClassesDetail = 
     "SELECT ID, Denotation, Abbreviation, Description, Coupled, UrgentValue\n"
     "FROM dbo.TaxClasses\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Holidays
// --------------------------------------------------------------------
const std::string strSQLWD_HolidaysAll = 
     "SELECT CalendarDay, Donation, Share, Description\n"
     "FROM dbo.WD_Holidays";

const std::string strSQLWD_HolidaysDetail = 
     "SELECT CalendarDay, Donation, Share, Description\n"
     "FROM dbo.WD_Holidays\n"
     "WHERE CalendarDay  = :keyCalendarDay";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Months
// --------------------------------------------------------------------
const std::string strSQLWD_MonthsAll = 
     "SELECT ID, Denotation, Abbreviation, Quarter\n"
     "FROM dbo.WD_Months";

const std::string strSQLWD_MonthsDetail = 
     "SELECT ID, Denotation, Abbreviation, Quarter\n"
     "FROM dbo.WD_Months\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: WD_NonWorking
// --------------------------------------------------------------------
const std::string strSQLWD_NonWorkingAll = 
     "SELECT ID, StartAt, ClosingAt, Reason, Notes\n"
     "FROM dbo.WD_NonWorking";

const std::string strSQLWD_NonWorkingDetail = 
     "SELECT ID, StartAt, ClosingAt, Reason, Notes\n"
     "FROM dbo.WD_NonWorking\n"
     "WHERE ID       = :keyID AND\n"
     "      StartAt  = :keyStartAt";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Weekdays
// --------------------------------------------------------------------
const std::string strSQLWD_WeekdaysAll = 
     "SELECT ID, Denotation, Abbreviation, Workday\n"
     "FROM dbo.WD_Weekdays";

const std::string strSQLWD_WeekdaysDetail = 
     "SELECT ID, Denotation, Abbreviation, Workday\n"
     "FROM dbo.WD_Weekdays\n"
     "WHERE ID  = :keyID";


// --------------------------------------------------------------------
//   Statements for table / view: WD_Workdays
// --------------------------------------------------------------------
const std::string strSQLWD_WorkdaysAll = 
     "SELECT CalendarDay, CalendarWeekday, CalendarWeek, CalendarYear, CalendarMonth,\n"
     "       CalendarDayInWeek, CalendarDayInYear, CalendarQuarter, Workday\n"
     "FROM dbo.WD_Workdays";

const std::string strSQLWD_WorkdaysDetail = 
     "SELECT CalendarDay, CalendarWeekday, CalendarWeek, CalendarYear, CalendarMonth,\n"
     "       CalendarDayInWeek, CalendarDayInYear, CalendarQuarter, Workday\n"
     "FROM dbo.WD_Workdays\n"
     "WHERE CalendarDay  = :keyCalendarDay";


// --------------------------------------------------------------------
//   Statements for table / view: WorkingTime
// --------------------------------------------------------------------
const std::string strSQLWorkingTimeAll = 
     "SELECT ID, StartingTime, ClosingTime, Processed , ProcessedAt, DayOfWork\n"
     "FROM dbo.WorkingTime";

const std::string strSQLWorkingTimeDetail = 
     "SELECT ID, StartingTime, ClosingTime, Processed , ProcessedAt, DayOfWork\n"
     "FROM dbo.WorkingTime\n"
     "WHERE ID            = :keyID AND\n"
     "      StartingTime  = :keyStartingTime";



} // close namespace reader
