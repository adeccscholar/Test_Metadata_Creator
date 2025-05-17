/*
* Project: model with a simple person administration
* Definition of sql statement for access with class TPersonReader
* Date: 22.04.2025 22:26:56,981  file created with adecc Scholar metadata generator
* copyright (c) adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#pragma once

#include <string>

namespace reader {

// sql statements for table dbo.Address
extern const std::string strSQLSelectAddress_All;
extern const std::string strSQLSelectAddress_Detail;
extern const std::string strSQLSelectAddress_IdxAddress_City_Street;
extern const std::string strSQLSelectAddress_RefAddress2Person;
extern const std::string strSQLSelectPerson_RevRefAddress2Person;
extern const std::string strSQLSelectAddress_RefAddress2AddressType;
extern const std::string strSQLSelectAddressTypes_RevRefAddress2AddressType;
extern const std::string strSQLSelectAddress_RefAddress2Countries;
extern const std::string strSQLSelectCountries_RevRefAddress2Countries;
extern const std::string strSQLInsertAddress;
extern const std::string strSQLUpdateAddress_WithPrim;
extern const std::string strSQLUpdateAddress_WithoutPrim;
extern const std::string strSQLDeleteAddress_All;
extern const std::string strSQLDeleteAddress_Detail;

// sql statements for table dbo.AddressTypes
extern const std::string strSQLSelectAddressTypes_All;
extern const std::string strSQLSelectAddressTypes_Detail;
extern const std::string strSQLSelectAddressTypes_UnqAddressType_Denotation;
extern const std::string strSQLInsertAddressTypes;
extern const std::string strSQLUpdateAddressTypes_WithPrim;
extern const std::string strSQLUpdateAddressTypes_WithoutPrim;
extern const std::string strSQLDeleteAddressTypes_All;
extern const std::string strSQLDeleteAddressTypes_Detail;

// sql statements for table dbo.Banking
extern const std::string strSQLSelectBanking_All;
extern const std::string strSQLSelectBanking_Detail;
extern const std::string strSQLSelectBanking_IdxBanking_IBAN;
extern const std::string strSQLSelectBanking_IdxBanking_BIC;
extern const std::string strSQLSelectBanking_RefBanking2Person;
extern const std::string strSQLSelectPerson_RevRefBanking2Person;
extern const std::string strSQLSelectBanking_RefBanking2Type;
extern const std::string strSQLSelectBankingTypes_RevRefBanking2Type;
extern const std::string strSQLSelectBanking_RefBanking2Countries;
extern const std::string strSQLSelectCountries_RevRefBanking2Countries;
extern const std::string strSQLInsertBanking;
extern const std::string strSQLUpdateBanking_WithPrim;
extern const std::string strSQLUpdateBanking_WithoutPrim;
extern const std::string strSQLDeleteBanking_All;
extern const std::string strSQLDeleteBanking_Detail;

// sql statements for table dbo.BankingTypes
extern const std::string strSQLSelectBankingTypes_All;
extern const std::string strSQLSelectBankingTypes_Detail;
extern const std::string strSQLSelectBankingTypes_UnqBankingTypes_Denotation;
extern const std::string strSQLInsertBankingTypes;
extern const std::string strSQLUpdateBankingTypes_WithPrim;
extern const std::string strSQLUpdateBankingTypes_WithoutPrim;
extern const std::string strSQLDeleteBankingTypes_All;
extern const std::string strSQLDeleteBankingTypes_Detail;

// sql statements for table dbo.Contacts
extern const std::string strSQLSelectContacts_All;
extern const std::string strSQLSelectContacts_Detail;
extern const std::string strSQLSelectContacts_RefContacts2Person;
extern const std::string strSQLSelectPerson_RevRefContacts2Person;
extern const std::string strSQLSelectContacts_RefContacts2Customer;
extern const std::string strSQLSelectCustomers_RevRefContacts2Customer;
extern const std::string strSQLSelectContacts_RefContacts2Liaison;
extern const std::string strSQLSelectCustLiaison_RevRefContacts2Liaison;
extern const std::string strSQLInsertContacts;
extern const std::string strSQLUpdateContacts_WithPrim;
extern const std::string strSQLUpdateContacts_WithoutPrim;
extern const std::string strSQLDeleteContacts_All;
extern const std::string strSQLDeleteContacts_Detail;

// sql statements for table dbo.CorporateForm
extern const std::string strSQLSelectCorporateForm_All;
extern const std::string strSQLSelectCorporateForm_Detail;
extern const std::string strSQLSelectCorporateForm_UnqCorporateForm_Donation;
extern const std::string strSQLSelectCorporateForm_UnqCorporateForm_Abbreviation;
extern const std::string strSQLInsertCorporateForm;
extern const std::string strSQLUpdateCorporateForm_WithPrim;
extern const std::string strSQLUpdateCorporateForm_WithoutPrim;
extern const std::string strSQLDeleteCorporateForm_All;
extern const std::string strSQLDeleteCorporateForm_Detail;

// sql statements for table dbo.Countries
extern const std::string strSQLSelectCountries_All;
extern const std::string strSQLSelectCountries_Detail;
extern const std::string strSQLSelectCountries_UnqCountries_Denotation;
extern const std::string strSQLSelectCountries_UnqCountries_ISOCode;
extern const std::string strSQLInsertCountries;
extern const std::string strSQLUpdateCountries_WithPrim;
extern const std::string strSQLUpdateCountries_WithoutPrim;
extern const std::string strSQLDeleteCountries_All;
extern const std::string strSQLDeleteCountries_Detail;

// sql statements for table dbo.CustClassification
extern const std::string strSQLSelectCustClassification_All;
extern const std::string strSQLSelectCustClassification_Detail;
extern const std::string strSQLSelectCustClassification_UnqCustClass_Donation;
extern const std::string strSQLInsertCustClassification;
extern const std::string strSQLUpdateCustClassification_WithPrim;
extern const std::string strSQLUpdateCustClassification_WithoutPrim;
extern const std::string strSQLDeleteCustClassification_All;
extern const std::string strSQLDeleteCustClassification_Detail;

// sql statements for table dbo.CustLiaison
extern const std::string strSQLSelectCustLiaison_All;
extern const std::string strSQLSelectCustLiaison_Detail;
extern const std::string strSQLSelectCustLiaison_UnqCustLiaison_Donation;
extern const std::string strSQLInsertCustLiaison;
extern const std::string strSQLUpdateCustLiaison_WithPrim;
extern const std::string strSQLUpdateCustLiaison_WithoutPrim;
extern const std::string strSQLDeleteCustLiaison_All;
extern const std::string strSQLDeleteCustLiaison_Detail;

// sql statements for table dbo.Customers
extern const std::string strSQLSelectCustomers_All;
extern const std::string strSQLSelectCustomers_Detail;
extern const std::string strSQLSelectCustomers_RefCustomers2Person;
extern const std::string strSQLSelectPerson_RevRefCustomers2Person;
extern const std::string strSQLSelectCustomers_RefCustomers2Classification;
extern const std::string strSQLSelectCustClassification_RevRefCustomers2Classification;
extern const std::string strSQLSelectCustomers_RefCustomers2Employees_SA;
extern const std::string strSQLSelectEmployees_RevRefCustomers2Employees_SA;
extern const std::string strSQLSelectCustomers_RefCustomers2LegalForms;
extern const std::string strSQLSelectCorporateForm_RevRefCustomers2LegalForms;
extern const std::string strSQLInsertCustomers;
extern const std::string strSQLUpdateCustomers_WithPrim;
extern const std::string strSQLUpdateCustomers_WithoutPrim;
extern const std::string strSQLDeleteCustomers_All;
extern const std::string strSQLDeleteCustomers_Detail;

// sql statements for table dbo.Departments
extern const std::string strSQLSelectDepartments_All;
extern const std::string strSQLSelectDepartments_Detail;
extern const std::string strSQLSelectDepartments_UnqDepartments_Denotation;
extern const std::string strSQLSelectDepartments_IdxDepartments_Abbr;
extern const std::string strSQLSelectDepartments_RefDepartments2Employee;
extern const std::string strSQLSelectEmployees_RevRefDepartments2Employee;
extern const std::string strSQLInsertDepartments;
extern const std::string strSQLUpdateDepartments_WithPrim;
extern const std::string strSQLUpdateDepartments_WithoutPrim;
extern const std::string strSQLDeleteDepartments_All;
extern const std::string strSQLDeleteDepartments_Detail;

// sql statements for table dbo.Employees
extern const std::string strSQLSelectEmployees_All;
extern const std::string strSQLSelectEmployees_Detail;
extern const std::string strSQLSelectEmployees_UnqEmployees_PersonNumber;
extern const std::string strSQLSelectEmployees_UnqEmployees_SocialNumber;
extern const std::string strSQLSelectEmployees_IdxEmployees_JobSpec;
extern const std::string strSQLSelectEmployees_IdxEmployees_Active;
extern const std::string strSQLSelectEmployees_RefEmployees2Person;
extern const std::string strSQLSelectPerson_RevRefEmployees2Person;
extern const std::string strSQLSelectEmployees_RefEmployees2SalaryType;
extern const std::string strSQLSelectSalaryType_RevRefEmployees2SalaryType;
extern const std::string strSQLSelectEmployees_RefEmployees2TaxClass;
extern const std::string strSQLSelectTaxClasses_RevRefEmployees2TaxClass;
extern const std::string strSQLSelectEmployees_RefEmployees2ReasonDeparture;
extern const std::string strSQLSelectReasonDeparture_RevRefEmployees2ReasonDeparture;
extern const std::string strSQLSelectEmployees_RefEmployees2JobPositions;
extern const std::string strSQLSelectJobPositions_RevRefEmployees2JobPositions;
extern const std::string strSQLSelectEmployees_RefEmployees2Department;
extern const std::string strSQLSelectDepartments_RevRefEmployees2Department;
extern const std::string strSQLInsertEmployees;
extern const std::string strSQLUpdateEmployees_WithPrim;
extern const std::string strSQLUpdateEmployees_WithoutPrim;
extern const std::string strSQLDeleteEmployees_All;
extern const std::string strSQLDeleteEmployees_Detail;

// sql statements for table dbo.FamilyStatus
extern const std::string strSQLSelectFamilyStatus_All;
extern const std::string strSQLSelectFamilyStatus_Detail;
extern const std::string strSQLSelectFamilyStatus_UnqFamilyStatus_Denotation;
extern const std::string strSQLInsertFamilyStatus;
extern const std::string strSQLUpdateFamilyStatus_WithPrim;
extern const std::string strSQLUpdateFamilyStatus_WithoutPrim;
extern const std::string strSQLDeleteFamilyStatus_All;
extern const std::string strSQLDeleteFamilyStatus_Detail;

// sql statements for table dbo.FamilyTypes
extern const std::string strSQLSelectFamilyTypes_All;
extern const std::string strSQLSelectFamilyTypes_Detail;
extern const std::string strSQLSelectFamilyTypes_UnqFamilyTypes_Denotation;
extern const std::string strSQLInsertFamilyTypes;
extern const std::string strSQLUpdateFamilyTypes_WithPrim;
extern const std::string strSQLUpdateFamilyTypes_WithoutPrim;
extern const std::string strSQLDeleteFamilyTypes_All;
extern const std::string strSQLDeleteFamilyTypes_Detail;

// sql statements for table dbo.FormOfAddress
extern const std::string strSQLSelectFormOfAddress_All;
extern const std::string strSQLSelectFormOfAddress_Detail;
extern const std::string strSQLSelectFormOfAddress_UnqFormOfAddress_Denotation;
extern const std::string strSQLSelectFormOfAddress_RefFormOfAddress2Type;
extern const std::string strSQLSelectFamilyTypes_RevRefFormOfAddress2Type;
extern const std::string strSQLInsertFormOfAddress;
extern const std::string strSQLUpdateFormOfAddress_WithPrim;
extern const std::string strSQLUpdateFormOfAddress_WithoutPrim;
extern const std::string strSQLDeleteFormOfAddress_All;
extern const std::string strSQLDeleteFormOfAddress_Detail;

// sql statements for table dbo.Internet
extern const std::string strSQLSelectInternet_All;
extern const std::string strSQLSelectInternet_Detail;
extern const std::string strSQLSelectInternet_IdxInternet_Address;
extern const std::string strSQLSelectInternet_RefInternet2Person;
extern const std::string strSQLSelectPerson_RevRefInternet2Person;
extern const std::string strSQLSelectInternet_RefInternet2Type;
extern const std::string strSQLSelectInternetTypes_RevRefInternet2Type;
extern const std::string strSQLInsertInternet;
extern const std::string strSQLUpdateInternet_WithPrim;
extern const std::string strSQLUpdateInternet_WithoutPrim;
extern const std::string strSQLDeleteInternet_All;
extern const std::string strSQLDeleteInternet_Detail;

// sql statements for table dbo.InternetTypes
extern const std::string strSQLSelectInternetTypes_All;
extern const std::string strSQLSelectInternetTypes_Detail;
extern const std::string strSQLSelectInternetTypes_UnqInternetTypes_Denotation;
extern const std::string strSQLInsertInternetTypes;
extern const std::string strSQLUpdateInternetTypes_WithPrim;
extern const std::string strSQLUpdateInternetTypes_WithoutPrim;
extern const std::string strSQLDeleteInternetTypes_All;
extern const std::string strSQLDeleteInternetTypes_Detail;

// sql statements for table dbo.JobPositions
extern const std::string strSQLSelectJobPositions_All;
extern const std::string strSQLSelectJobPositions_Detail;
extern const std::string strSQLSelectJobPositions_UnqJobPositions_Denotation;
extern const std::string strSQLSelectJobPositions_RefJobPosition2SalaryType;
extern const std::string strSQLSelectSalaryType_RevRefJobPosition2SalaryType;
extern const std::string strSQLInsertJobPositions;
extern const std::string strSQLUpdateJobPositions_WithPrim;
extern const std::string strSQLUpdateJobPositions_WithoutPrim;
extern const std::string strSQLDeleteJobPositions_All;
extern const std::string strSQLDeleteJobPositions_Detail;

// sql statements for table dbo.Person
extern const std::string strSQLSelectPerson_All;
extern const std::string strSQLSelectPerson_Detail;
extern const std::string strSQLSelectPerson_IdxPerson_Name_Firstname;
extern const std::string strSQLSelectPerson_RefPerson2FormOfAddress;
extern const std::string strSQLSelectFormOfAddress_RevRefPerson2FormOfAddress;
extern const std::string strSQLSelectPerson_RefPerson2FamilyStatus;
extern const std::string strSQLSelectFamilyStatus_RevRefPerson2FamilyStatus;
extern const std::string strSQLInsertPerson;
extern const std::string strSQLUpdatePerson_WithPrim;
extern const std::string strSQLUpdatePerson_WithoutPrim;
extern const std::string strSQLDeletePerson_All;
extern const std::string strSQLDeletePerson_Detail;

// sql statements for table dbo.Phone
extern const std::string strSQLSelectPhone_All;
extern const std::string strSQLSelectPhone_Detail;
extern const std::string strSQLSelectPhone_IdxPhone_Number;
extern const std::string strSQLSelectPhone_RefPhone2Person;
extern const std::string strSQLSelectPerson_RevRefPhone2Person;
extern const std::string strSQLSelectPhone_RefPhone2Type;
extern const std::string strSQLSelectPhonesTypes_RevRefPhone2Type;
extern const std::string strSQLSelectPhone_RefPhone2Countries;
extern const std::string strSQLSelectCountries_RevRefPhone2Countries;
extern const std::string strSQLInsertPhone;
extern const std::string strSQLUpdatePhone_WithPrim;
extern const std::string strSQLUpdatePhone_WithoutPrim;
extern const std::string strSQLDeletePhone_All;
extern const std::string strSQLDeletePhone_Detail;

// sql statements for table dbo.PhoneTypes
extern const std::string strSQLSelectPhonesTypes_All;
extern const std::string strSQLSelectPhonesTypes_Detail;
extern const std::string strSQLSelectPhonesTypes_UnqPhonesTypes_Denotation;
extern const std::string strSQLInsertPhonesTypes;
extern const std::string strSQLUpdatePhonesTypes_WithPrim;
extern const std::string strSQLUpdatePhonesTypes_WithoutPrim;
extern const std::string strSQLDeletePhonesTypes_All;
extern const std::string strSQLDeletePhonesTypes_Detail;

// sql statements for table dbo.ReasonDeparture
extern const std::string strSQLSelectReasonDeparture_All;
extern const std::string strSQLSelectReasonDeparture_Detail;
extern const std::string strSQLSelectReasonDeparture_UnqReasonDeparture_Denotation;
extern const std::string strSQLInsertReasonDeparture;
extern const std::string strSQLUpdateReasonDeparture_WithPrim;
extern const std::string strSQLUpdateReasonDeparture_WithoutPrim;
extern const std::string strSQLDeleteReasonDeparture_All;
extern const std::string strSQLDeleteReasonDeparture_Detail;

// sql statements for table dbo.ReasonNonWorking
extern const std::string strSQLSelectReasonNonWorking_All;
extern const std::string strSQLSelectReasonNonWorking_Detail;
extern const std::string strSQLSelectReasonNonWorking_UnqReasonNonWorking_Denotation;
extern const std::string strSQLInsertReasonNonWorking;
extern const std::string strSQLUpdateReasonNonWorking_WithPrim;
extern const std::string strSQLUpdateReasonNonWorking_WithoutPrim;
extern const std::string strSQLDeleteReasonNonWorking_All;
extern const std::string strSQLDeleteReasonNonWorking_Detail;

// sql statements for table dbo.SalaryBase
extern const std::string strSQLSelectSalaryBase_All;
extern const std::string strSQLSelectSalaryBase_Detail;
extern const std::string strSQLSelectSalaryBase_UnqSalaryBase_Denotation;
extern const std::string strSQLSelectSalaryBase_UnqSalaryBase_Abbreviation;
extern const std::string strSQLInsertSalaryBase;
extern const std::string strSQLUpdateSalaryBase_WithPrim;
extern const std::string strSQLUpdateSalaryBase_WithoutPrim;
extern const std::string strSQLDeleteSalaryBase_All;
extern const std::string strSQLDeleteSalaryBase_Detail;

// sql statements for table dbo.SalaryType
extern const std::string strSQLSelectSalaryType_All;
extern const std::string strSQLSelectSalaryType_Detail;
extern const std::string strSQLSelectSalaryType_RefSalaryType2SalaryBase;
extern const std::string strSQLSelectSalaryBase_RevRefSalaryType2SalaryBase;
extern const std::string strSQLInsertSalaryType;
extern const std::string strSQLUpdateSalaryType_WithPrim;
extern const std::string strSQLUpdateSalaryType_WithoutPrim;
extern const std::string strSQLDeleteSalaryType_All;
extern const std::string strSQLDeleteSalaryType_Detail;

// sql statements for table dbo.TaxClasses
extern const std::string strSQLSelectTaxClasses_All;
extern const std::string strSQLSelectTaxClasses_Detail;
extern const std::string strSQLSelectTaxClasses_UnqTaxClasses_Denotation;
extern const std::string strSQLSelectTaxClasses_UnqTaxClasses_Abbreviation;
extern const std::string strSQLInsertTaxClasses;
extern const std::string strSQLUpdateTaxClasses_WithPrim;
extern const std::string strSQLUpdateTaxClasses_WithoutPrim;
extern const std::string strSQLDeleteTaxClasses_All;
extern const std::string strSQLDeleteTaxClasses_Detail;

// sql statements for table dbo.WD_Holidays
extern const std::string strSQLSelectWD_Holidays_All;
extern const std::string strSQLSelectWD_Holidays_Detail;
extern const std::string strSQLSelectWD_Holidays_RefWD_Holidays_Workdays;
extern const std::string strSQLSelectWD_Workdays_RevRefWD_Holidays_Workdays;
extern const std::string strSQLInsertWD_Holidays;
extern const std::string strSQLUpdateWD_Holidays_WithPrim;
extern const std::string strSQLUpdateWD_Holidays_WithoutPrim;
extern const std::string strSQLDeleteWD_Holidays_All;
extern const std::string strSQLDeleteWD_Holidays_Detail;

// sql statements for table dbo.WD_Months
extern const std::string strSQLSelectWD_Months_All;
extern const std::string strSQLSelectWD_Months_Detail;
extern const std::string strSQLSelectWD_Months_UnqWD_Months_Denotation;
extern const std::string strSQLSelectWD_Months_UnqWD_Months_Abbreviation;
extern const std::string strSQLInsertWD_Months;
extern const std::string strSQLUpdateWD_Months_WithPrim;
extern const std::string strSQLUpdateWD_Months_WithoutPrim;
extern const std::string strSQLDeleteWD_Months_All;
extern const std::string strSQLDeleteWD_Months_Detail;

// sql statements for table dbo.WD_NonWorking
extern const std::string strSQLSelectWD_NonWorking_All;
extern const std::string strSQLSelectWD_NonWorking_Detail;
extern const std::string strSQLSelectWD_NonWorking_RefNonWorking2Employee;
extern const std::string strSQLSelectEmployees_RevRefNonWorking2Employee;
extern const std::string strSQLSelectWD_NonWorking_RefNonWorking2Workday_Start;
extern const std::string strSQLSelectWD_Workdays_RevRefNonWorking2Workday_Start;
extern const std::string strSQLSelectWD_NonWorking_RefNonWorking2Workday_Finishing;
extern const std::string strSQLSelectWD_Workdays_RevRefNonWorking2Workday_Finishing;
extern const std::string strSQLSelectWD_NonWorking_RefNonWorking2Reason;
extern const std::string strSQLSelectReasonNonWorking_RevRefNonWorking2Reason;
extern const std::string strSQLInsertWD_NonWorking;
extern const std::string strSQLUpdateWD_NonWorking_WithPrim;
extern const std::string strSQLUpdateWD_NonWorking_WithoutPrim;
extern const std::string strSQLDeleteWD_NonWorking_All;
extern const std::string strSQLDeleteWD_NonWorking_Detail;

// sql statements for table dbo.WD_Weekdays
extern const std::string strSQLSelectWD_Weekdays_All;
extern const std::string strSQLSelectWD_Weekdays_Detail;
extern const std::string strSQLSelectWD_Weekdays_UnqWD_Weekdays_Denotation;
extern const std::string strSQLSelectWD_Weekdays_UnqWD_Weekdays_Abbreviation;
extern const std::string strSQLInsertWD_Weekdays;
extern const std::string strSQLUpdateWD_Weekdays_WithPrim;
extern const std::string strSQLUpdateWD_Weekdays_WithoutPrim;
extern const std::string strSQLDeleteWD_Weekdays_All;
extern const std::string strSQLDeleteWD_Weekdays_Detail;

// sql statements for table dbo.WD_Workdays
extern const std::string strSQLSelectWD_Workdays_All;
extern const std::string strSQLSelectWD_Workdays_Detail;
extern const std::string strSQLSelectWD_Workdays_IdxWD_Workdays_Years_Month;
extern const std::string strSQLSelectWD_Workdays_RefWD_Workdays2WeekDay;
extern const std::string strSQLSelectWD_Weekdays_RevRefWD_Workdays2WeekDay;
extern const std::string strSQLSelectWD_Workdays_RefWD_Workdays2Month;
extern const std::string strSQLSelectWD_Months_RevRefWD_Workdays2Month;
extern const std::string strSQLInsertWD_Workdays;
extern const std::string strSQLUpdateWD_Workdays_WithPrim;
extern const std::string strSQLUpdateWD_Workdays_WithoutPrim;
extern const std::string strSQLDeleteWD_Workdays_All;
extern const std::string strSQLDeleteWD_Workdays_Detail;

// sql statements for table dbo.WorkingTime
extern const std::string strSQLSelectWorkingTime_All;
extern const std::string strSQLSelectWorkingTime_Detail;
extern const std::string strSQLSelectWorkingTime_RefWorkTime2Employee;
extern const std::string strSQLSelectEmployees_RevRefWorkTime2Employee;
extern const std::string strSQLInsertWorkingTime;
extern const std::string strSQLUpdateWorkingTime_WithPrim;
extern const std::string strSQLUpdateWorkingTime_WithoutPrim;
extern const std::string strSQLDeleteWorkingTime_All;
extern const std::string strSQLDeleteWorkingTime_Detail;

} // close namespace reader
