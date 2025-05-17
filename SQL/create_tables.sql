/* ------------------------------------------------------------------------------------
 * script with statements to create tables / views for the project simple person model
 * generated at: 22.04.2025 22:26:54,798 with the adecc Scholar metadata generator
 * author:       Volker Hillmann (adecc Scholar)
 * copyright © adecc Systemhaus GmbH 2024, All rights reserved.
 * ------------------------------------------------------------------------------------ */

-- create tables for the project

-- statement to create the table dbo.Address
CREATE TABLE dbo.Address (
   ID           INT NOT NULL,
   AddressType  INT NOT NULL,
   Zipcode      VARCHAR(10) NOT NULL,
   City         VARCHAR(50) NOT NULL,
   Street       VARCHAR(50) NOT NULL,
   StreetNumber VARCHAR(10),
   Country      INT NOT NULL
   );

-- statement to create the table dbo.AddressTypes
CREATE TABLE dbo.AddressTypes (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   Notes        VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.Banking
CREATE TABLE dbo.Banking (
   ID          INT NOT NULL,
   BankingType INT NOT NULL,
   BankName    VARCHAR(50),
   IBAN        VARCHAR(33) NOT NULL,
   BIC         VARCHAR(12),
   BankOwner   VARCHAR(27),
   Country     INT
   );

-- statement to create the table dbo.BankingTypes
CREATE TABLE dbo.BankingTypes (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   Notes        VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.Contacts
CREATE TABLE dbo.Contacts (
   ContactID   INT NOT NULL,
   CustID      INT NOT NULL,
   CustLiaison INT NOT NULL
   );

-- statement to create the table dbo.CorporateForm
CREATE TABLE dbo.CorporateForm (
   ID             INT NOT NULL,
   Denotation     VARCHAR(50) NOT NULL,
   Abbreviation   VARCHAR(15) NOT NULL,
   Description    VARCHAR(MAX),
   IsLegalEntrity TINYINT NOT NULL CHECK (IsLegalEntrity IN (0, 1)),
   UrgentValue    INT
   );

-- statement to create the table dbo.Countries
CREATE TABLE dbo.Countries (
   ID             INT NOT NULL,
   Denotation     VARCHAR(50) NOT NULL,
   Abbreviation   VARCHAR(10),
   Description    VARCHAR(MAX),
   CountryDialing VARCHAR(10),
   ISO_Code       VARCHAR(5),
   IsEU           TINYINT CHECK (IsEU IN (0, 1)),
   Capital        VARCHAR(50),
   Currency       VARCHAR(50),
   Notes          VARCHAR(MAX),
   UrgentValue    TINYINT CHECK (UrgentValue IN (0, 1))
   );

GO
CREATE FUNCTION [dbo].[Country_Dialing] (@id AS INTEGER) RETURNS VARCHAR(10)
BEGIN
   DECLARE @retval VARCHAR(10);
   SELECT @retval = CountryDialing
   FROM dbo.Countries
   WHERE ID = @id;
   RETURN @retval;
END
GO

-- statement to create the table dbo.CustClassification
CREATE TABLE dbo.CustClassification (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   Notes        VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.CustLiaison
CREATE TABLE dbo.CustLiaison (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   Notes        VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.Customers
CREATE TABLE dbo.Customers (
   CustID             INT NOT NULL,
   ServiceAgent       INT NOT NULL,
   CustClassification INT NOT NULL,
   LegalForm          INT NOT NULL
   );

-- statement to create the table dbo.Departments
CREATE TABLE dbo.Departments (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   Officer      INT,
   Notes        VARCHAR(MAX)
   );

-- statement to create the table dbo.Employees
CREATE TABLE dbo.Employees (
   EmployID        INT NOT NULL,
   PersonNumber    VARCHAR(15) NOT NULL,
   Salary          DECIMAL(10, 2) CHECK (Salary >= 0.0),
   SalaryType      INT,
   TaxClass        INT NOT NULL,
   StartOfJob      DATE NOT NULL,
   EndOfJob        DATE,
   ReasonDeparture INT,
   JobPosition     INT,
   JobSpec         VARCHAR(100),
   VacationDays    INT CHECK (VacationDays >= 0),
   Department      INT NOT NULL,
   TaxNumber       VARCHAR(11),
   SocialNummer    VARCHAR(20) NOT NULL,

   );

-- statement to create the table dbo.FamilyStatus
CREATE TABLE dbo.FamilyStatus (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   Coupled      TINYINT CHECK (Coupled IN (0, 1)),
   NeedDate     TINYINT CHECK (NeedDate IN (0, 1)),
   Notes        VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.FamilyTypes
CREATE TABLE dbo.FamilyTypes (
   ID              INT NOT NULL,
   Denotation      VARCHAR(50) NOT NULL,
   Abbreviation    VARCHAR(10),
   IsNaturalPerson TINYINT CHECK (IsNaturalPerson IN (0, 1)),
   Description     VARCHAR(MAX),
   Notes           VARCHAR(MAX),
   UrgentValue     TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.FormOfAddress
CREATE TABLE dbo.FormOfAddress (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   TypeSpec     INT,
   Salutation   VARCHAR(50),
   Valediction  VARCHAR(50),
   Notes        VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.Internet
CREATE TABLE dbo.Internet (
   ID           INT NOT NULL,
   InternetType INT NOT NULL,
   Adresse      VARCHAR(100) NOT NULL
   );

-- statement to create the table dbo.InternetTypes
CREATE TABLE dbo.InternetTypes (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   Prefix       VARCHAR(10),
   Notes        VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.JobPositions
CREATE TABLE dbo.JobPositions (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   SalaryType   INT,
   Notes        VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.Person
CREATE TABLE dbo.Person (
   ID                INT NOT NULL,
   Name              VARCHAR(30) NOT NULL,
   FirstName         VARCHAR(30),
   Birthname         VARCHAR(30),
   FormOfAddress     INT NOT NULL,
   FamilyStatus      INT NOT NULL,
   FamilyStatusSince DATE,
   Birthday          DATE,
   Notes             VARCHAR(MAX),
   FullName          AS Name + ', ' + FirstName
   );

-- statement to create the table dbo.Phone
CREATE TABLE dbo.Phone (
   ID              INT NOT NULL,
   PhoneType       INT NOT NULL,
   AreaCode        VARCHAR(10) NOT NULL CHECK (AreaCode NOT LIKE '%[^0-9]%'),
   CallNumber      VARCHAR(13) NOT NULL CHECK (CallNumber NOT LIKE '%[^0-9 -]%'),
   Country         INT NOT NULL,
   DialingNational AS AreaCode + REPLACE(REPLACE(CallNumber, ' ', ''), '-', ''),

   );

-- statement to create the table dbo.PhoneTypes
CREATE TABLE dbo.PhoneTypes (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   Notes        VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.ReasonDeparture
CREATE TABLE dbo.ReasonDeparture (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   Notes        VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.ReasonNonWorking
CREATE TABLE dbo.ReasonNonWorking (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   Notes        VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.SalaryBase
CREATE TABLE dbo.SalaryBase (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.SalaryType
CREATE TABLE dbo.SalaryType (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   SalaryBase   INT,
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.TaxClasses
CREATE TABLE dbo.TaxClasses (
   ID           INT NOT NULL,
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10),
   Description  VARCHAR(MAX),
   Coupled      TINYINT NOT NULL CHECK (Coupled IN (0, 1)),
   UrgentValue  TINYINT CHECK (UrgentValue IN (0, 1))
   );

-- statement to create the table dbo.WD_Holidays
CREATE TABLE dbo.WD_Holidays (
   CalendarDay DATE NOT NULL,
   Donation    VARCHAR(50) NOT NULL,
   Share       INT NOT NULL,
   Description VARCHAR(MAX)
   );

GO
CREATE FUNCTION [dbo].[GetIsHoliday](@caldate AS DATE) RETURNS INTEGER
BEGIN
   DECLARE @retval INTEGER;
   SELECT @retval = COUNT(*)
   FROM dbo.WD_Holidays
   WHERE CalendarDay = @caldate;
   RETURN @retval;
END
GO

-- statement to create the table dbo.WD_Months
CREATE TABLE dbo.WD_Months (
   ID           INT NOT NULL CHECK (ID BETWEEN 1 AND 12),
   Denotation   VARCHAR(50) NOT NULL,
   Abbreviation VARCHAR(10) NOT NULL,
   Quarter      INT NOT NULL CHECK (Quarter >= 0 AND Quarter BETWEEN 1 AND 4)
   );

GO
CREATE FUNCTION [dbo].[GetQuarterOfMonth](@id AS INTEGER) RETURNS VARCHAR(10)
BEGIN
   DECLARE @retval VARCHAR(10);
   SELECT @retval = Quarter
   FROM dbo.WD_Months
   WHERE ID = @id;
   RETURN @retval;
END
GO

-- statement to create the table dbo.WD_NonWorking
CREATE TABLE dbo.WD_NonWorking (
   ID        INT NOT NULL,
   StartAt   DATE NOT NULL,
   ClosingAt DATE,
   Reason    INT NOT NULL CHECK (Reason BETWEEN 0 AND 6),
   Notes     VARCHAR(MAX)
   );

-- statement to create the table dbo.WD_Weekdays
CREATE TABLE dbo.WD_Weekdays (
   ID           INT NOT NULL CHECK (ID BETWEEN 0 AND 6),
   Denotation   VARCHAR(20) NOT NULL,
   Abbreviation VARCHAR(5) NOT NULL,
   Workday      TINYINT NOT NULL CHECK (Workday IN (0, 1))
   );

GO
CREATE FUNCTION [dbo].[GetIsWorkday](@id AS INTEGER) RETURNS SMALLINT
BEGIN
   DECLARE @retval SMALLINT;
   SELECT @retval = Workday
   FROM dbo.WD_Weekdays
   WHERE ID = @id;
   RETURN @retval;
END
GO

-- statement to create the table dbo.WD_Workdays
CREATE TABLE dbo.WD_Workdays (
   CalendarDay       DATE NOT NULL,
   CalendarWeekday   INT NOT NULL,
   CalendarWeek      INT NOT NULL,
   CalendarYear      AS YEAR(CalendarDay)  PERSISTED,
   CalendarMonth     AS MONTH(CalendarDay)  PERSISTED,
   CalendarDayInWeek AS DAY(CalendarDay)  PERSISTED,
   CalendarDayInYear AS DATEPART(DAYOFYEAR, CalendarDay),

   );

-- statement to create the table dbo.WorkingTime
CREATE TABLE dbo.WorkingTime (
   ID           INT NOT NULL,
   StartingTime DATE NOT NULL,
   ClosingTime  DATE,
   Processed    TINYINT NOT NULL CHECK (Processed  IN (0, 1)),
   ProcessedAt  DATE,

   );

-- create views for the project

