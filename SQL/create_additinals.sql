/* ------------------------------------------------------------------------------------
 * script with keys, references and indices for the project simple person model
 * generated at: 22.03.2024 15:39:11,143 with the adecc Scholar metadata generator
 * author:       Volker Hillmann (adecc Scholar)
 * copyright © adecc Systemhaus GmbH 2024, All rights reserved.
 * ----------------------------------------------------------------------------------- */

-- alter tables with calculated columns simple person model
ALTER TABLE dbo.Employees ADD Active AS IIF(EndOfJob IS NULL OR EndOfJob >= GETDATE(), 1, 0);

ALTER TABLE dbo.Phone ADD DialingInternational AS [dbo].[Country_Dialing](Country)+SUBSTRING(AreaCode, 2, LEN(AreaCode))+CallNumber;

ALTER TABLE dbo.WD_Workdays ADD CalendarQuarter AS [dbo].[GetQuarterOfMonth](MONTH(CalendarDay));
ALTER TABLE dbo.WD_Workdays ADD Workday AS IIF(dbo.GetIsWorkday(CalendarWeekday) = 1 AND dbo.GetIsHoliday(CalendarDay) = 0, 1, 0);

ALTER TABLE dbo.WorkingTime ADD DayOfWork AS convert(date, StartingTime) PERSISTED;


GO


-- create primary keys for tables of the dictionary simple person model
ALTER TABLE dbo.Address ADD CONSTRAINT pk_Address PRIMARY KEY (ID, AddressType);

ALTER TABLE dbo.AddressTypes ADD CONSTRAINT pk_AddressTypes PRIMARY KEY (ID);

ALTER TABLE dbo.Banking ADD CONSTRAINT pk_Banking PRIMARY KEY (ID, BankingType);

ALTER TABLE dbo.BankingTypes ADD CONSTRAINT pk_BankingTypes PRIMARY KEY (ID);

ALTER TABLE dbo.Contacts ADD CONSTRAINT pk_Contacts PRIMARY KEY (ContactID);

ALTER TABLE dbo.CorporateForm ADD CONSTRAINT pk_CorporateForm PRIMARY KEY (ID);

ALTER TABLE dbo.Countries ADD CONSTRAINT pk_Countries PRIMARY KEY (ID);

ALTER TABLE dbo.CustClassification ADD CONSTRAINT pk_CustClassification PRIMARY KEY (ID);

ALTER TABLE dbo.CustLiaison ADD CONSTRAINT pk_CustLiaison PRIMARY KEY (ID);

ALTER TABLE dbo.Customers ADD CONSTRAINT pk_Customers PRIMARY KEY (CustID);

ALTER TABLE dbo.Departments ADD CONSTRAINT pk_Departments PRIMARY KEY (ID);

ALTER TABLE dbo.Employees ADD CONSTRAINT pk_Employees PRIMARY KEY (EmployeeID);

ALTER TABLE dbo.FamilyStatus ADD CONSTRAINT pk_FamilyStatus PRIMARY KEY (ID);

ALTER TABLE dbo.FamilyTypes ADD CONSTRAINT pk_FamilyTypes PRIMARY KEY (ID);

ALTER TABLE dbo.FormOfAddress ADD CONSTRAINT pk_FormOfAddress PRIMARY KEY (ID);

ALTER TABLE dbo.Internet ADD CONSTRAINT pk_Internet PRIMARY KEY (ID, InternetType);

ALTER TABLE dbo.InternetTypes ADD CONSTRAINT pk_InternetTypes PRIMARY KEY (ID);

ALTER TABLE dbo.JobPositions ADD CONSTRAINT pk_JobPositions PRIMARY KEY (ID);

ALTER TABLE dbo.Person ADD CONSTRAINT pk_Person PRIMARY KEY (ID);

ALTER TABLE dbo.Phone ADD CONSTRAINT pk_Phone PRIMARY KEY (ID, PhoneType);

ALTER TABLE dbo.PhoneTypes ADD CONSTRAINT pk_PhoneTypes PRIMARY KEY (ID);

ALTER TABLE dbo.ReasonDeparture ADD CONSTRAINT pk_ReasonDeparture PRIMARY KEY (ID);

ALTER TABLE dbo.ReasonNonWorking ADD CONSTRAINT pk_ReasonNonWorking PRIMARY KEY (ID);

ALTER TABLE dbo.SalaryBase ADD CONSTRAINT pk_SalaryBase PRIMARY KEY (ID);

ALTER TABLE dbo.SalaryType ADD CONSTRAINT pk_SalaryType PRIMARY KEY (ID);

ALTER TABLE dbo.TaxClasses ADD CONSTRAINT pk_TaxClasses PRIMARY KEY (ID);

ALTER TABLE dbo.WD_Holidays ADD CONSTRAINT pk_WD_Holidays PRIMARY KEY (CalendarDay);

ALTER TABLE dbo.WD_Months ADD CONSTRAINT pk_WD_Months PRIMARY KEY (ID);

ALTER TABLE dbo.WD_NonWorking ADD CONSTRAINT pk_WD_NonWorking PRIMARY KEY (ID, StartAt);

ALTER TABLE dbo.WD_Weekdays ADD CONSTRAINT pk_WD_Weekdays PRIMARY KEY (ID);

ALTER TABLE dbo.WD_Workdays ADD CONSTRAINT pk_WD_Workdays PRIMARY KEY (CalendarDay);

ALTER TABLE dbo.WorkingTime ADD CONSTRAINT pk_WorkingTime PRIMARY KEY (ID, StartingTime);


GO


-- create unique keys for tables of the dictionary simple person model
ALTER TABLE dbo.AddressTypes ADD CONSTRAINT uk_AddressType_Denotation UNIQUE (Abbreviation);

ALTER TABLE dbo.BankingTypes ADD CONSTRAINT uk_BankingTypes_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.CorporateForm ADD CONSTRAINT uk_CorporateForm_Donation UNIQUE (Denotation);
ALTER TABLE dbo.CorporateForm ADD CONSTRAINT uk_CorporateForm_Abbreviation UNIQUE (ID);

ALTER TABLE dbo.Countries ADD CONSTRAINT uk_Countries_Denotation UNIQUE (Denotation);
ALTER TABLE dbo.Countries ADD CONSTRAINT uk_Countries_ISOCode UNIQUE (ISO_Code);

ALTER TABLE dbo.CustClassification ADD CONSTRAINT uk_CustClass_Donation UNIQUE (Denotation);

ALTER TABLE dbo.CustLiaison ADD CONSTRAINT uk_CustLiaison_Donation UNIQUE (Denotation);

ALTER TABLE dbo.Departments ADD CONSTRAINT uk_Departments_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.Employees ADD CONSTRAINT uk_Employees_PersonNumber UNIQUE (PersonNumber);
ALTER TABLE dbo.Employees ADD CONSTRAINT uk_Employees_SocialNumber UNIQUE (ReasonDeparture);

ALTER TABLE dbo.FamilyStatus ADD CONSTRAINT uk_FamilyStatus_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.FamilyTypes ADD CONSTRAINT uk_FamilyTypes_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.FormOfAddress ADD CONSTRAINT uk_FormOfAddress_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.InternetTypes ADD CONSTRAINT uk_InternetTypes_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.JobPositions ADD CONSTRAINT uk_JobPositions_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.PhoneTypes ADD CONSTRAINT uk_PhonesTypes_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.ReasonDeparture ADD CONSTRAINT uk_ReasonDeparture_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.ReasonNonWorking ADD CONSTRAINT uk_ReasonNonWorking_Denotation UNIQUE (Denotation);

ALTER TABLE dbo.SalaryBase ADD CONSTRAINT uk_SalaryBase_Denotation UNIQUE (Denotation);
ALTER TABLE dbo.SalaryBase ADD CONSTRAINT uk_SalaryBase_Abbreviation UNIQUE (Abbreviation);

ALTER TABLE dbo.TaxClasses ADD CONSTRAINT uk_TaxClasses_Denotation UNIQUE (Denotation);
ALTER TABLE dbo.TaxClasses ADD CONSTRAINT uk_TaxClasses_Abbreviation UNIQUE (Abbreviation);

ALTER TABLE dbo.WD_Months ADD CONSTRAINT uk_WD_Months_Denotation UNIQUE (Denotation);
ALTER TABLE dbo.WD_Months ADD CONSTRAINT uk_WD_Months_Abbreviation UNIQUE (Abbreviation);

ALTER TABLE dbo.WD_Weekdays ADD CONSTRAINT uk_WD_Weekdays_Denotation UNIQUE (Denotation);
ALTER TABLE dbo.WD_Weekdays ADD CONSTRAINT uk_WD_Weekdays_Abbreviation UNIQUE (Abbreviation);


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
ALTER TABLE dbo.Customers ADD CONSTRAINT refCustomers2Employees_SA FOREIGN KEY (ServiceAgent) REFERENCES dbo.Employees (EmployeeID);
ALTER TABLE dbo.Customers ADD CONSTRAINT refCustomers2LegalForms FOREIGN KEY (LegalForm) REFERENCES dbo.CorporateForm (ID);

ALTER TABLE dbo.Departments ADD CONSTRAINT refDepartments2Employee FOREIGN KEY (Officer) REFERENCES dbo.Employees (EmployeeID);

ALTER TABLE dbo.Employees ADD CONSTRAINT refEmployees2Person FOREIGN KEY (EmployeeID) REFERENCES dbo.Person (ID);
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

ALTER TABLE dbo.WD_NonWorking ADD CONSTRAINT refNonWorking2Employee FOREIGN KEY (ID) REFERENCES dbo.Employees (EmployeeID);
ALTER TABLE dbo.WD_NonWorking ADD CONSTRAINT refNonWorking2Workday_Start FOREIGN KEY (StartAt) REFERENCES dbo.WD_Workdays (CalendarDay);
ALTER TABLE dbo.WD_NonWorking ADD CONSTRAINT refNonWorking2Workday_Finishing FOREIGN KEY (ClosingAt) REFERENCES dbo.WD_Workdays (CalendarDay);
ALTER TABLE dbo.WD_NonWorking ADD CONSTRAINT refNonWorking2Reason FOREIGN KEY (Reason) REFERENCES dbo.ReasonNonWorking (ID);

ALTER TABLE dbo.WD_Workdays ADD CONSTRAINT refWD_Workdays2WeekDay FOREIGN KEY (CalendarWeekday) REFERENCES dbo.WD_Weekdays (ID);
ALTER TABLE dbo.WD_Workdays ADD CONSTRAINT refWD_Workdays2Month FOREIGN KEY (CalendarMonth) REFERENCES dbo.WD_Months (ID);

ALTER TABLE dbo.WorkingTime ADD CONSTRAINT refWorkTime2Employee FOREIGN KEY (ID) REFERENCES dbo.Employees (EmployeeID);


GO


-- create check conditions for tables of the dictionary simple person model
ALTER TABLE dbo.Employees ADD CONSTRAINT ck_Employees_EndOfJob CHECK (EndOfJob IS NULL OR (EndOfJob > StartOfJob));
ALTER TABLE dbo.Employees ADD CONSTRAINT ck_Employees_ReasonDeparture CHECK ((ReasonDeparture IS NULL AND EndOfJob IS NULL) OR  (ReasonDeparture IS NOT NULL AND EndOfJob IS NOT NULL));

ALTER TABLE dbo.WorkingTime ADD CONSTRAINT ck_WorkingTime_ClosingTime CHECK (convert(date, ClosingTime) = DayOfWork and ClosingTime > StartingTime);


GO


-- create indices for tables of the dictionary simple person model
CREATE INDEX idx_Address_City_Street ON dbo.Address (City, Street);

CREATE INDEX idx_Banking_IBAN ON dbo.Banking (IBAN);
CREATE INDEX idx_Banking_BIC ON dbo.Banking (BIC);

CREATE INDEX idx_Departments_Abbr ON dbo.Departments (Abbreviation);

CREATE INDEX idx_Employees_JobSpec ON dbo.Employees (StartOfJob);
CREATE INDEX idx_Employees_Active ON dbo.Employees (JobPosition);

CREATE INDEX idxInternet_Address ON dbo.Internet (Adresse);

CREATE INDEX idx_Person_Name_Firstname ON dbo.Person (Name, Firstname);

CREATE INDEX idx_Phone_Number ON dbo.Phone (AreaCode, CallNumber);

CREATE INDEX idxWD_Workdays_Years_Month ON dbo.WD_Workdays (CalendarYear, CalendarMonth);


GO

