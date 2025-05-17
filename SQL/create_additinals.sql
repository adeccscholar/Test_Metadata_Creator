/* ------------------------------------------------------------------------------------
 * script with keys, references and indices for the project simple person model
 * generated at: 22.04.2025 22:26:54,820 with the adecc Scholar metadata generator
 * author:       Volker Hillmann (adecc Scholar)
 * copyright © adecc Systemhaus GmbH 2024, All rights reserved.
 * ----------------------------------------------------------------------------------- */

-- alter tables with calculated columns simple person model
ALTER TABLE dbo.Employees ADD Active AS IIF(EndOfJob IS NULL OR EndOfJob >= GETDATE(), 1, 0);

ALTER TABLE dbo.Phone ADD DialingInternational AS [dbo].[Country_Dialing](Country)+SUBSTRING(AreaCode, 2, LEN(AreaCode))+CallNumber;

ALTER TABLE dbo.WD_Workdays ADD CalendarQuarter AS [dbo].[GetQuarterOfMonth](MONTH(CalendarDay));
ALTER TABLE dbo.WD_Workdays ADD Workday AS IIF(dbo.GetIsWorkday(CalendarWeekday) = 1 AND dbo.GetIsHoliday(CalendarDay) = 0, 1, 0);

ALTER TABLE dbo.WorkingTime ADD DayOfWork AS convert(date, StartingTime);


GO


-- create primary keys for tables of the dictionary simple person model
ALTER TABLE dbo.Address ADD CONSTRAINT pkAddress PRIMARY KEY (ID, AddressType);

ALTER TABLE dbo.AddressTypes ADD CONSTRAINT pkAddressTypes PRIMARY KEY (ID);

ALTER TABLE dbo.Banking ADD CONSTRAINT pkBanking PRIMARY KEY (ID, BankingType);

ALTER TABLE dbo.BankingTypes ADD CONSTRAINT pkBankingTypes PRIMARY KEY (ID);

ALTER TABLE dbo.Contacts ADD CONSTRAINT pkContacts PRIMARY KEY (ContactID);

ALTER TABLE dbo.CorporateForm ADD CONSTRAINT pkCorporateForm PRIMARY KEY (ID);

ALTER TABLE dbo.Countries ADD CONSTRAINT pkCountries PRIMARY KEY (ID);

ALTER TABLE dbo.CustClassification ADD CONSTRAINT pkCustClassification PRIMARY KEY (ID);

ALTER TABLE dbo.CustLiaison ADD CONSTRAINT pkCustLiaison PRIMARY KEY (ID);

ALTER TABLE dbo.Customers ADD CONSTRAINT pkCustomers PRIMARY KEY (CustID);

ALTER TABLE dbo.Departments ADD CONSTRAINT pkDepartments PRIMARY KEY (ID);

ALTER TABLE dbo.Employees ADD CONSTRAINT pkEmployees PRIMARY KEY (EmployID);

ALTER TABLE dbo.FamilyStatus ADD CONSTRAINT pkFamilyStatus PRIMARY KEY (ID);

ALTER TABLE dbo.FamilyTypes ADD CONSTRAINT pkFamilyTypes PRIMARY KEY (ID);

ALTER TABLE dbo.FormOfAddress ADD CONSTRAINT pkFormOfAddress PRIMARY KEY (ID);

ALTER TABLE dbo.Internet ADD CONSTRAINT pkInternet PRIMARY KEY (ID, InternetType);

ALTER TABLE dbo.InternetTypes ADD CONSTRAINT pkInternetTypes PRIMARY KEY (ID);

ALTER TABLE dbo.JobPositions ADD CONSTRAINT pkJobPositions PRIMARY KEY (ID);

ALTER TABLE dbo.Person ADD CONSTRAINT pkPerson PRIMARY KEY (ID);

ALTER TABLE dbo.Phone ADD CONSTRAINT pkPhone PRIMARY KEY (ID, PhoneType);

ALTER TABLE dbo.PhoneTypes ADD CONSTRAINT pkPhoneTypes PRIMARY KEY (ID);

ALTER TABLE dbo.ReasonDeparture ADD CONSTRAINT pkReasonDeparture PRIMARY KEY (ID);

ALTER TABLE dbo.ReasonNonWorking ADD CONSTRAINT pkReasonNonWorking PRIMARY KEY (ID);

ALTER TABLE dbo.SalaryBase ADD CONSTRAINT pkSalaryBase PRIMARY KEY (ID);

ALTER TABLE dbo.SalaryType ADD CONSTRAINT pkSalaryType PRIMARY KEY (ID);

ALTER TABLE dbo.TaxClasses ADD CONSTRAINT pkTaxClasses PRIMARY KEY (ID);

ALTER TABLE dbo.WD_Holidays ADD CONSTRAINT pkWD_Holidays PRIMARY KEY (CalendarDay);

ALTER TABLE dbo.WD_Months ADD CONSTRAINT pkWD_Months PRIMARY KEY (ID);

ALTER TABLE dbo.WD_NonWorking ADD CONSTRAINT pkWD_NonWorking PRIMARY KEY (ID, StartAt);

ALTER TABLE dbo.WD_Weekdays ADD CONSTRAINT pkWD_Weekdays PRIMARY KEY (ID);

ALTER TABLE dbo.WD_Workdays ADD CONSTRAINT pkWD_Workdays PRIMARY KEY (CalendarDay);

ALTER TABLE dbo.WorkingTime ADD CONSTRAINT pkWorkingTime PRIMARY KEY (ID, StartingTime);


GO


-- create unique keys for tables of the dictionary simple person model
ALTER TABLE dbo.AddressTypes ADD CONSTRAINT ukAddressType_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.BankingTypes ADD CONSTRAINT ukBankingTypes_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.CorporateForm ADD CONSTRAINT ukCorporateForm_Donation UNIQUE (Denotation);
ALTER TABLE dbo.CorporateForm ADD CONSTRAINT ukCorporateForm_Abbreviation UNIQUE (ID);

ALTER TABLE dbo.Countries ADD CONSTRAINT ukCountries_Denotation UNIQUE (Denotation);
ALTER TABLE dbo.Countries ADD CONSTRAINT ukCountries_ISOCode UNIQUE (ISO_Code);

ALTER TABLE dbo.CustClassification ADD CONSTRAINT ukCustClass_Donation UNIQUE (Denotation);

ALTER TABLE dbo.CustLiaison ADD CONSTRAINT ukCustLiaison_Donation UNIQUE (Denotation);

ALTER TABLE dbo.Departments ADD CONSTRAINT ukDepartments_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.Employees ADD CONSTRAINT ukEmployees_PersonNumber UNIQUE (PersonNumber);
ALTER TABLE dbo.Employees ADD CONSTRAINT ukEmployees_SocialNumber UNIQUE (TaxNumber);

ALTER TABLE dbo.FamilyStatus ADD CONSTRAINT ukFamilyStatus_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.FamilyTypes ADD CONSTRAINT ukFamilyTypes_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.FormOfAddress ADD CONSTRAINT ukFormOfAddress_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.InternetTypes ADD CONSTRAINT ukInternetTypes_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.JobPositions ADD CONSTRAINT ukJobPositions_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.PhoneTypes ADD CONSTRAINT ukPhonesTypes_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.ReasonDeparture ADD CONSTRAINT ukReasonDeparture_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.ReasonNonWorking ADD CONSTRAINT ukReasonNonWorking_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.SalaryBase ADD CONSTRAINT ukSalaryBase_Denotation UNIQUE (Denotation);
ALTER TABLE dbo.SalaryBase ADD CONSTRAINT ukSalaryBase_Abbreviation UNIQUE (Abbreviation);

ALTER TABLE dbo.TaxClasses ADD CONSTRAINT ukTaxClasses_Denotation UNIQUE (Denotation);
ALTER TABLE dbo.TaxClasses ADD CONSTRAINT ukTaxClasses_Abbreviation UNIQUE (Abbreviation);

ALTER TABLE dbo.WD_Months ADD CONSTRAINT ukWD_Months_Denotation UNIQUE (Denotation);
ALTER TABLE dbo.WD_Months ADD CONSTRAINT ukWD_Months_Abbreviation UNIQUE (Abbreviation);

ALTER TABLE dbo.WD_Weekdays ADD CONSTRAINT ukWD_Weekdays_Denotation UNIQUE (Denotation);
ALTER TABLE dbo.WD_Weekdays ADD CONSTRAINT ukWD_Weekdays_Abbreviation UNIQUE (Abbreviation);


GO


-- create foreign keys for tables of the dictionary simple person model
ALTER TABLE dbo.Address ADD CONSTRAINT refAddress2Person FOREIGN KEY (ID) REFERENCES dbo.Person (ID);
ALTER TABLE dbo.Address ADD CONSTRAINT refAddress2AddressType FOREIGN KEY (AddressType) REFERENCES dbo.AddressTypes (ID);
ALTER TABLE dbo.Address ADD CONSTRAINT refAddress2Countries FOREIGN KEY (Country) REFERENCES dbo.Countries (ID);

ALTER TABLE dbo.Banking ADD CONSTRAINT refBanking2Person FOREIGN KEY (ID) REFERENCES dbo.Person (ID);
ALTER TABLE dbo.Banking ADD CONSTRAINT refBanking2Type FOREIGN KEY (BankingType) REFERENCES dbo.BankingTypes (ID);
ALTER TABLE dbo.Banking ADD CONSTRAINT refBanking2Countries FOREIGN KEY (Country) REFERENCES dbo.Countries (ID);

ALTER TABLE dbo.Contacts ADD CONSTRAINT refContacts2Person FOREIGN KEY (ContactID) REFERENCES dbo.Person (ID);
ALTER TABLE dbo.Contacts ADD CONSTRAINT refContacts2Customer FOREIGN KEY (CustID) REFERENCES dbo.Customers (CustID);
ALTER TABLE dbo.Contacts ADD CONSTRAINT refContacts2Liaison FOREIGN KEY (CustLiaison) REFERENCES dbo.CustLiaison (ID);

ALTER TABLE dbo.Customers ADD CONSTRAINT refCustomers2Person FOREIGN KEY (CustID) REFERENCES dbo.Person (ID);
ALTER TABLE dbo.Customers ADD CONSTRAINT refCustomers2Classification FOREIGN KEY (CustClassification) REFERENCES dbo.CustClassification (ID);
ALTER TABLE dbo.Customers ADD CONSTRAINT refCustomers2Employees_SA FOREIGN KEY (ServiceAgent) REFERENCES dbo.Employees (EmployID);
ALTER TABLE dbo.Customers ADD CONSTRAINT refCustomers2LegalForms FOREIGN KEY (LegalForm) REFERENCES dbo.CorporateForm (ID);

ALTER TABLE dbo.Departments ADD CONSTRAINT refDepartments2Employee FOREIGN KEY (Officer) REFERENCES dbo.Employees (EmployID);

ALTER TABLE dbo.Employees ADD CONSTRAINT refEmployees2Person FOREIGN KEY (EmployID) REFERENCES dbo.Person (ID);
ALTER TABLE dbo.Employees ADD CONSTRAINT refEmployees2SalaryType FOREIGN KEY (SalaryType) REFERENCES dbo.SalaryType (ID);
ALTER TABLE dbo.Employees ADD CONSTRAINT refEmployees2TaxClass FOREIGN KEY (TaxClass) REFERENCES dbo.TaxClasses (ID);
ALTER TABLE dbo.Employees ADD CONSTRAINT refEmployees2ReasonDeparture FOREIGN KEY (ReasonDeparture) REFERENCES dbo.ReasonDeparture (ID);
ALTER TABLE dbo.Employees ADD CONSTRAINT refEmployees2JobPositions FOREIGN KEY (JobPosition) REFERENCES dbo.JobPositions (ID);
ALTER TABLE dbo.Employees ADD CONSTRAINT refEmployees2Department FOREIGN KEY (Department) REFERENCES dbo.Departments (ID);

ALTER TABLE dbo.FormOfAddress ADD CONSTRAINT refFormOfAddress2Type FOREIGN KEY (TypeSpec) REFERENCES dbo.FamilyTypes (ID);

ALTER TABLE dbo.Internet ADD CONSTRAINT refInternet2Person FOREIGN KEY (ID) REFERENCES dbo.Person (ID);
ALTER TABLE dbo.Internet ADD CONSTRAINT refInternet2Type FOREIGN KEY (InternetType) REFERENCES dbo.InternetTypes (ID);

ALTER TABLE dbo.JobPositions ADD CONSTRAINT refJobPosition2SalaryType FOREIGN KEY (SalaryType) REFERENCES dbo.SalaryType (ID);

ALTER TABLE dbo.Person ADD CONSTRAINT refPerson2FormOfAddress FOREIGN KEY (FormOfAddress) REFERENCES dbo.FormOfAddress (ID);
ALTER TABLE dbo.Person ADD CONSTRAINT refPerson2FamilyStatus FOREIGN KEY (FamilyStatus) REFERENCES dbo.FamilyStatus (ID);

ALTER TABLE dbo.Phone ADD CONSTRAINT refPhone2Person FOREIGN KEY (ID) REFERENCES dbo.Person (ID);
ALTER TABLE dbo.Phone ADD CONSTRAINT refPhone2Type FOREIGN KEY (PhoneType) REFERENCES dbo.PhoneTypes (ID);
ALTER TABLE dbo.Phone ADD CONSTRAINT refPhone2Countries FOREIGN KEY (Country) REFERENCES dbo.Countries (ID);

ALTER TABLE dbo.SalaryType ADD CONSTRAINT refSalaryType2SalaryBase FOREIGN KEY (SalaryBase) REFERENCES dbo.SalaryBase (ID);

ALTER TABLE dbo.WD_Holidays ADD CONSTRAINT refWD_Holidays_Workdays FOREIGN KEY (CalendarDay) REFERENCES dbo.WD_Workdays (CalendarDay);

ALTER TABLE dbo.WD_NonWorking ADD CONSTRAINT refNonWorking2Employee FOREIGN KEY (ID) REFERENCES dbo.Employees (EmployID);
ALTER TABLE dbo.WD_NonWorking ADD CONSTRAINT refNonWorking2Workday_Start FOREIGN KEY (StartAt) REFERENCES dbo.WD_Workdays (CalendarDay);
ALTER TABLE dbo.WD_NonWorking ADD CONSTRAINT refNonWorking2Workday_Finishing FOREIGN KEY (ClosingAt) REFERENCES dbo.WD_Workdays (CalendarDay);
ALTER TABLE dbo.WD_NonWorking ADD CONSTRAINT refNonWorking2Reason FOREIGN KEY (Reason) REFERENCES dbo.ReasonNonWorking (ID);

ALTER TABLE dbo.WD_Workdays ADD CONSTRAINT refWD_Workdays2WeekDay FOREIGN KEY (CalendarWeekday) REFERENCES dbo.WD_Weekdays (ID);
ALTER TABLE dbo.WD_Workdays ADD CONSTRAINT refWD_Workdays2Month FOREIGN KEY (CalendarMonth) REFERENCES dbo.WD_Months (ID);

ALTER TABLE dbo.WorkingTime ADD CONSTRAINT refWorkTime2Employee FOREIGN KEY (ID) REFERENCES dbo.Employees (EmployID);


GO


-- create check conditions for tables of the dictionary simple person model
ALTER TABLE dbo.Employees ADD CONSTRAINT ck_Employees_EndOfJob CHECK (EndOfJob IS NULL OR (EndOfJob > StartOfJob));
ALTER TABLE dbo.Employees ADD CONSTRAINT ck_Employees_ReasonDeparture CHECK ((ReasonDeparture IS NULL AND EndOfJob IS NULL) OR  (ReasonDeparture IS NOT NULL AND EndOfJob IS NOT NULL));

ALTER TABLE dbo.WorkingTime ADD CONSTRAINT ck_WorkingTime_ClosingTime CHECK (convert(date, ClosingTime) = DayOfWork and ClosingTime > StartingTime);


GO


-- create indices for tables of the dictionary simple person model
CREATE INDEX idxAddress_City_Street ON dbo.Address (City, Street);

CREATE INDEX idxBanking_IBAN ON dbo.Banking (IBAN);
CREATE INDEX idxBanking_BIC ON dbo.Banking (BIC);

CREATE INDEX idxDepartments_Abbr ON dbo.Departments (Abbreviation);

CREATE INDEX idxEmployees_JobSpec ON dbo.Employees (JobSpec);
CREATE INDEX idxEmployees_Active ON dbo.Employees (SocialNummer);

CREATE INDEX idxInternet_Address ON dbo.Internet (Adresse);

CREATE INDEX idxPerson_Name_Firstname ON dbo.Person (Name, FirstName);

CREATE INDEX idxPhone_Number ON dbo.Phone (AreaCode, CallNumber);

CREATE INDEX idxWD_Workdays_Years_Month ON dbo.WD_Workdays (CalendarYear, CalendarMonth);


GO

