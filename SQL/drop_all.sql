﻿/* ------------------------------------------------------------------------------------
 * script to drop relationships and tables for the project simple person model
 * generated at: 22.04.2025 22:26:54,855 with the adecc Scholar metadata generator
 * author:       Volker Hillmann (adecc Scholar)
 * copyright © adecc Systemhaus GmbH 2024, All rights reserved.
 * ----------------------------------------------------------------------------------- */

 -- drop foreign keys to erase dependencies
ALTER TABLE dbo.Address DROP CONSTRAINT refAddress2Person;
ALTER TABLE dbo.Address DROP CONSTRAINT refAddress2AddressType;
ALTER TABLE dbo.Address DROP CONSTRAINT refAddress2Countries;

ALTER TABLE dbo.Banking DROP CONSTRAINT refBanking2Person;
ALTER TABLE dbo.Banking DROP CONSTRAINT refBanking2Type;
ALTER TABLE dbo.Banking DROP CONSTRAINT refBanking2Countries;

ALTER TABLE dbo.Contacts DROP CONSTRAINT refContacts2Person;
ALTER TABLE dbo.Contacts DROP CONSTRAINT refContacts2Customer;
ALTER TABLE dbo.Contacts DROP CONSTRAINT refContacts2Liaison;

ALTER TABLE dbo.Customers DROP CONSTRAINT refCustomers2Person;
ALTER TABLE dbo.Customers DROP CONSTRAINT refCustomers2Classification;
ALTER TABLE dbo.Customers DROP CONSTRAINT refCustomers2Employees_SA;
ALTER TABLE dbo.Customers DROP CONSTRAINT refCustomers2LegalForms;

ALTER TABLE dbo.Departments DROP CONSTRAINT refDepartments2Employee;

ALTER TABLE dbo.Employees DROP CONSTRAINT refEmployees2Person;
ALTER TABLE dbo.Employees DROP CONSTRAINT refEmployees2SalaryType;
ALTER TABLE dbo.Employees DROP CONSTRAINT refEmployees2TaxClass;
ALTER TABLE dbo.Employees DROP CONSTRAINT refEmployees2ReasonDeparture;
ALTER TABLE dbo.Employees DROP CONSTRAINT refEmployees2JobPositions;
ALTER TABLE dbo.Employees DROP CONSTRAINT refEmployees2Department;

ALTER TABLE dbo.FormOfAddress DROP CONSTRAINT refFormOfAddress2Type;

ALTER TABLE dbo.Internet DROP CONSTRAINT refInternet2Person;
ALTER TABLE dbo.Internet DROP CONSTRAINT refInternet2Type;

ALTER TABLE dbo.JobPositions DROP CONSTRAINT refJobPosition2SalaryType;

ALTER TABLE dbo.Person DROP CONSTRAINT refPerson2FormOfAddress;
ALTER TABLE dbo.Person DROP CONSTRAINT refPerson2FamilyStatus;

ALTER TABLE dbo.Phone DROP CONSTRAINT refPhone2Person;
ALTER TABLE dbo.Phone DROP CONSTRAINT refPhone2Type;
ALTER TABLE dbo.Phone DROP CONSTRAINT refPhone2Countries;

ALTER TABLE dbo.SalaryType DROP CONSTRAINT refSalaryType2SalaryBase;

ALTER TABLE dbo.WD_Holidays DROP CONSTRAINT refWD_Holidays_Workdays;

ALTER TABLE dbo.WD_NonWorking DROP CONSTRAINT refNonWorking2Employee;
ALTER TABLE dbo.WD_NonWorking DROP CONSTRAINT refNonWorking2Workday_Start;
ALTER TABLE dbo.WD_NonWorking DROP CONSTRAINT refNonWorking2Workday_Finishing;
ALTER TABLE dbo.WD_NonWorking DROP CONSTRAINT refNonWorking2Reason;

ALTER TABLE dbo.WD_Workdays DROP CONSTRAINT refWD_Workdays2WeekDay;
ALTER TABLE dbo.WD_Workdays DROP CONSTRAINT refWD_Workdays2Month;

ALTER TABLE dbo.WorkingTime DROP CONSTRAINT refWorkTime2Employee;


-- drop all tables
DROP TABLE dbo.Address;
DROP TABLE dbo.AddressTypes;
DROP TABLE dbo.Banking;
DROP TABLE dbo.BankingTypes;
DROP TABLE dbo.Contacts;
DROP TABLE dbo.CorporateForm;
DROP TABLE dbo.Countries;
DROP TABLE dbo.CustClassification;
DROP TABLE dbo.CustLiaison;
DROP TABLE dbo.Customers;
DROP TABLE dbo.Departments;
DROP TABLE dbo.Employees;
DROP TABLE dbo.FamilyStatus;
DROP TABLE dbo.FamilyTypes;
DROP TABLE dbo.FormOfAddress;
DROP TABLE dbo.Internet;
DROP TABLE dbo.InternetTypes;
DROP TABLE dbo.JobPositions;
DROP TABLE dbo.Person;
DROP TABLE dbo.Phone;
DROP TABLE dbo.PhoneTypes;
DROP TABLE dbo.ReasonDeparture;
DROP TABLE dbo.ReasonNonWorking;
DROP TABLE dbo.SalaryBase;
DROP TABLE dbo.SalaryType;
DROP TABLE dbo.TaxClasses;
DROP TABLE dbo.WD_Holidays;
DROP TABLE dbo.WD_Months;
DROP TABLE dbo.WD_NonWorking;
DROP TABLE dbo.WD_Weekdays;
DROP TABLE dbo.WD_Workdays;
DROP TABLE dbo.WorkingTime;

-- drop all tables

-- run cleanings for added informations
DROP FUNCTION [dbo].[Country_Dialing];

DROP FUNCTION [dbo].[GetIsHoliday];

DROP FUNCTION [dbo].[GetQuarterOfMonth];

DROP FUNCTION [dbo].[GetIsWorkday];

