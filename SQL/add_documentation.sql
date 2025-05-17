/* ------------------------------------------------------------------------------------
 * script with statements to add descriptions for the project simple person model
 * generated at: 22.04.2025 22:26:54,870 with the adecc Scholar metadata generator
 * author:       Volker Hillmann (adecc Scholar)
 * copyright © adecc Systemhaus GmbH 2024, All rights reserved.
 * ------------------------------------------------------------------------------------ */

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'Address', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'Address'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'information on the addresses where a person lives, works or has any other relationship with them', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'Address'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'AddressType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'AddressType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'AddressType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'Zipcode'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'Zipcode'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'Zipcode'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'City'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'City'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'City'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'Street'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'Street'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'Street'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'StreetNumber'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'StreetNumber'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'StreetNumber'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'Country'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'Country'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'Country'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'AddressTypes', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'AddressTypes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain / range of values for address types, this is an extension of the relationship between persons and addresses.', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'AddressTypes'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'AddressTypes',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'AddressTypes',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'AddressTypes',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'AddressTypes',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'AddressTypes',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'AddressTypes',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'AddressTypes',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'AddressTypes',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'AddressTypes',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'AddressTypes',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'AddressTypes',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'AddressTypes',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'Banking', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'Banking'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'informations about the account details provided by a person and used in a specific context', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'Banking'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'BankingType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'BankingType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'BankingType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'BankName'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'BankName'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'BankName'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'IBAN'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'IBAN'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'IBAN'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'BIC'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'BIC'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'BIC'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'BankOwner'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'BankOwner'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'BankOwner'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'Country'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'Country'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'Country'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'BankingTypes', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'BankingTypes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain / range of values for banking types, this is an extension of the relationship between persons and banking accounts.', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'BankingTypes'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'BankingTypes',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'BankingTypes',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'BankingTypes',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'BankingTypes',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'BankingTypes',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'BankingTypes',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'BankingTypes',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'BankingTypes',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'BankingTypes',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'BankingTypes',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'BankingTypes',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'BankingTypes',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'Contacts', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'Contacts'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'information to the data of a contact person at the customer  (inherited from Person)', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'Contacts'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Contacts',
                                                N'column', 'ContactID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Contacts',
                                   @level2type = N'COLUMN', @level2name = N'ContactID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Contacts', @level2type = N'COLUMN', @level2name = N'ContactID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Contacts',
                                                N'column', 'CustID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Contacts',
                                   @level2type = N'COLUMN', @level2name = N'CustID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Contacts', @level2type = N'COLUMN', @level2name = N'CustID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Contacts',
                                                N'column', 'CustLiaison'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Contacts',
                                   @level2type = N'COLUMN', @level2name = N'CustLiaison'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Contacts', @level2type = N'COLUMN', @level2name = N'CustLiaison'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'CorporateForm', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'CorporateForm'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'This table stores information about various types of legal forms. Each row corresponds to a specific legal form with several informations.', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'CorporateForm'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CorporateForm',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CorporateForm',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CorporateForm', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CorporateForm',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CorporateForm',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CorporateForm', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CorporateForm',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CorporateForm',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CorporateForm', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CorporateForm',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CorporateForm',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CorporateForm', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CorporateForm',
                                                N'column', 'IsLegalEntrity'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CorporateForm',
                                   @level2type = N'COLUMN', @level2name = N'IsLegalEntrity'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CorporateForm', @level2type = N'COLUMN', @level2name = N'IsLegalEntrity'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CorporateForm',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CorporateForm',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CorporateForm', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'Countries', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'Countries'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'table with the countries and additional values for the countries. Used by others for assoziation.', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'Countries'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'CountryDialing'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'CountryDialing'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'CountryDialing'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'ISO_Code'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'ISO_Code'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'ISO_Code'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'IsEU'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'IsEU'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'IsEU'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Capital'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Capital'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Capital'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Currency'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Currency'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Currency'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'CustClassification', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'CustClassification'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain / range with the classifications for customers', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'CustClassification'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustClassification',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustClassification',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustClassification',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustClassification',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustClassification',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustClassification',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustClassification',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustClassification',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustClassification',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustClassification',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustClassification',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustClassification',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'CustLiaison', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'CustLiaison'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'doman range with the liaisons to use a contact at a customer', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'CustLiaison'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustLiaison',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustLiaison',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustLiaison',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustLiaison',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustLiaison',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustLiaison',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustLiaison',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustLiaison',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustLiaison',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustLiaison',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustLiaison',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustLiaison',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'Customers', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'Customers'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'information to the data of a client / customer  (inherited from Person)', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'Customers'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Customers',
                                                N'column', 'CustID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Customers',
                                   @level2type = N'COLUMN', @level2name = N'CustID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Customers', @level2type = N'COLUMN', @level2name = N'CustID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Customers',
                                                N'column', 'ServiceAgent'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Customers',
                                   @level2type = N'COLUMN', @level2name = N'ServiceAgent'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Customers', @level2type = N'COLUMN', @level2name = N'ServiceAgent'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Customers',
                                                N'column', 'CustClassification'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Customers',
                                   @level2type = N'COLUMN', @level2name = N'CustClassification'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Customers', @level2type = N'COLUMN', @level2name = N'CustClassification'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Customers',
                                                N'column', 'LegalForm'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Customers',
                                   @level2type = N'COLUMN', @level2name = N'LegalForm'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Customers', @level2type = N'COLUMN', @level2name = N'LegalForm'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'Departments', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'Departments'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'independent entity with the departments in the company, independent identity', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'Departments'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Departments',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Departments',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Departments',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Departments',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Departments',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Departments',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Departments',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Departments',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Departments',
                                                N'column', 'Officer'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Departments',
                                   @level2type = N'COLUMN', @level2name = N'Officer'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'Officer'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Departments',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Departments',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'Notes'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'Employees', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'Employees'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'information about the employees in the company (generalization of a person)', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'Employees'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'EmployID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'EmployID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'EmployID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'PersonNumber'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'PersonNumber'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'PersonNumber'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'Salary'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'Salary'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'Salary'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'SalaryType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'SalaryType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'SalaryType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'TaxClass'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'TaxClass'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'TaxClass'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'StartOfJob'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'StartOfJob'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'StartOfJob'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'EndOfJob'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'EndOfJob'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'EndOfJob'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'ReasonDeparture'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'ReasonDeparture'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'ReasonDeparture'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'JobPosition'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'JobPosition'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'JobPosition'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'JobSpec'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'JobSpec'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'JobSpec'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'VacationDays'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'VacationDays'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'VacationDays'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'Department'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'Department'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'Department'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'TaxNumber'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'TaxNumber'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'TaxNumber'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'SocialNummer'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'SocialNummer'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'SocialNummer'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'Active'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'Active'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'Active'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'FamilyStatus', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'FamilyStatus'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain / range of values for family status, this is used in person to qualifify the actual status, maybe a date needed too', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'FamilyStatus'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'Coupled'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'Coupled'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'Coupled'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'NeedDate'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'NeedDate'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'NeedDate'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'FamilyTypes', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'FamilyTypes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain / range of values for family types, this is used in form of address to qualifify the person gender', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'FamilyTypes'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'IsNaturalPerson'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'IsNaturalPerson'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'IsNaturalPerson'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'FormOfAddress', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'FormOfAddress'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain with the possible values for form of addresses with additional informations for this', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'FormOfAddress'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'TypeSpec'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'TypeSpec'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'TypeSpec'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Salutation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Salutation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Salutation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Valediction'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Valediction'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Valediction'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'Internet', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'Internet'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'connections for different kinds of communications about the internet as part of persons (part of relationship)', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'Internet'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Internet',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Internet',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Internet', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Internet',
                                                N'column', 'InternetType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Internet',
                                   @level2type = N'COLUMN', @level2name = N'InternetType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Internet', @level2type = N'COLUMN', @level2name = N'InternetType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Internet',
                                                N'column', 'Adresse'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Internet',
                                   @level2type = N'COLUMN', @level2name = N'Adresse'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Internet', @level2type = N'COLUMN', @level2name = N'Adresse'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'InternetTypes', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'InternetTypes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain / range of values for internet connection types, this is an extension of the relationship between persons and internet connections.', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'InternetTypes'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'Prefix'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'Prefix'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'Prefix'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'JobPositions', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'JobPositions'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain or range of values for different positions for the employee. Important as anchor for additional informations', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'JobPositions'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'SalaryType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'SalaryType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'SalaryType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'Person', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'Person'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'informations about a person, base for different kinds of special persons in other areas of the company', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'Person'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'Name'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'Name'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'Name'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'FirstName'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'FirstName'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'FirstName'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'Birthname'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'Birthname'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'Birthname'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'FormOfAddress'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'FormOfAddress'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'FormOfAddress'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'FamilyStatus'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'FamilyStatus'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'FamilyStatus'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'FamilyStatusSince'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'FamilyStatusSince'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'FamilyStatusSince'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'Birthday'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'Birthday'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'Birthday'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'FullName'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'FullName'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'FullName'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'Phone', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'Phone'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'phone connections of persons (part of relationship)', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'Phone'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'PhoneType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'PhoneType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'PhoneType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'AreaCode'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'AreaCode'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'AreaCode'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'CallNumber'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'CallNumber'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'CallNumber'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'Country'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'Country'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'Country'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'DialingNational'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'DialingNational'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'DialingNational'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'DialingInternational'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'DialingInternational'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'DialingInternational'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'PhoneTypes', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'PhoneTypes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain / range of values for phone types, this is an extension of the relationship between persons and phone.', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'PhoneTypes'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'PhoneTypes',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'PhoneTypes',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'PhoneTypes',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'PhoneTypes',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'PhoneTypes',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'PhoneTypes',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'PhoneTypes',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'PhoneTypes',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'PhoneTypes',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'PhoneTypes',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'PhoneTypes',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'PhoneTypes',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'ReasonDeparture', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'ReasonDeparture'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain / range with the reasons of departure of the employee', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'ReasonDeparture'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonDeparture',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonDeparture',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonDeparture',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonDeparture',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonDeparture',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonDeparture',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonDeparture',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonDeparture',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonDeparture',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonDeparture',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonDeparture',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonDeparture',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'ReasonNonWorking', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'ReasonNonWorking'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain / range with the reasons of non working time / idle time', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'ReasonNonWorking'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonNonWorking',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonNonWorking',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonNonWorking',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonNonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonNonWorking',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonNonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonNonWorking',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonNonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonNonWorking',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonNonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonNonWorking',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonNonWorking',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'SalaryBase', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'SalaryBase'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'fix domain for the calculation, this value determine the base for the salary, used in table SalaryType', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'SalaryBase'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryBase',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryBase',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryBase', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryBase',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryBase',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryBase', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryBase',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryBase',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryBase', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryBase',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryBase',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryBase', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryBase',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryBase',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryBase', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'SalaryType', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'SalaryType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'kind of salary as range value and base for calculations (fix, bonus, hourly, dayly, monthly, ...)', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'SalaryType'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryType',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryType',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryType',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryType',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryType',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryType',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryType',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryType',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryType',
                                                N'column', 'SalaryBase'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryType',
                                   @level2type = N'COLUMN', @level2name = N'SalaryBase'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'SalaryBase'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryType',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryType',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'TaxClasses', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'TaxClasses'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'tax class in germany to use it with employees (not a range, but very similar)', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'TaxClasses'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'TaxClasses',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'TaxClasses',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'TaxClasses',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'TaxClasses',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'TaxClasses',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'TaxClasses',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'TaxClasses',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'TaxClasses',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'TaxClasses',
                                                N'column', 'Coupled'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'TaxClasses',
                                   @level2type = N'COLUMN', @level2name = N'Coupled'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'Coupled'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'TaxClasses',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'TaxClasses',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'WD_Holidays', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'WD_Holidays'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'entities with public holidays, in relation to working days table to determine non working days', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'WD_Holidays'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Holidays',
                                                N'column', 'CalendarDay'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Holidays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarDay'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Holidays', @level2type = N'COLUMN', @level2name = N'CalendarDay'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Holidays',
                                                N'column', 'Donation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Holidays',
                                   @level2type = N'COLUMN', @level2name = N'Donation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Holidays', @level2type = N'COLUMN', @level2name = N'Donation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Holidays',
                                                N'column', 'Share'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Holidays',
                                   @level2type = N'COLUMN', @level2name = N'Share'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Holidays', @level2type = N'COLUMN', @level2name = N'Share'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Holidays',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Holidays',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Holidays', @level2type = N'COLUMN', @level2name = N'Description'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'WD_Months', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'WD_Months'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain with months for human resources, actually used for working time, later for processes too. This range make it possible additional informations to adding later. This isnt a typical range value.', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'WD_Months'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Months',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Months',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Months', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Months',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Months',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Months', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Months',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Months',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Months', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Months',
                                                N'column', 'Quarter'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Months',
                                   @level2type = N'COLUMN', @level2name = N'Quarter'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Months', @level2type = N'COLUMN', @level2name = N'Quarter'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'WD_NonWorking', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'WD_NonWorking'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'entity set with non working days. Extensions possible, responsible for this table is HR.', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'WD_NonWorking'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_NonWorking',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_NonWorking',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_NonWorking', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_NonWorking',
                                                N'column', 'StartAt'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_NonWorking',
                                   @level2type = N'COLUMN', @level2name = N'StartAt'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_NonWorking', @level2type = N'COLUMN', @level2name = N'StartAt'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_NonWorking',
                                                N'column', 'ClosingAt'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_NonWorking',
                                   @level2type = N'COLUMN', @level2name = N'ClosingAt'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_NonWorking', @level2type = N'COLUMN', @level2name = N'ClosingAt'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_NonWorking',
                                                N'column', 'Reason'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_NonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Reason'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_NonWorking', @level2type = N'COLUMN', @level2name = N'Reason'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_NonWorking',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_NonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_NonWorking', @level2type = N'COLUMN', @level2name = N'Notes'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'WD_Weekdays', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'WD_Weekdays'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain for days of week, used for table working time. Possible to extent with informations. In area HR only', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'WD_Weekdays'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Weekdays',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Weekdays',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Weekdays', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Weekdays',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Weekdays',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Weekdays', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Weekdays',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Weekdays',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Weekdays', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Weekdays',
                                                N'column', 'Workday'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Weekdays',
                                   @level2type = N'COLUMN', @level2name = N'Workday'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Weekdays', @level2type = N'COLUMN', @level2name = N'Workday'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'WD_Workdays', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'WD_Workdays'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'domain with all days, additional informations and as owner of all recorded working time and non-working times', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'WD_Workdays'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarDay'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarDay'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarDay'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarWeekday'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarWeekday'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarWeekday'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarWeek'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarWeek'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarWeek'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarYear'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarYear'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarYear'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarMonth'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarMonth'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarMonth'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarDayInWeek'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarDayInWeek'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarDayInWeek'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarDayInYear'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarDayInYear'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarDayInYear'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarQuarter'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarQuarter'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarQuarter'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'Workday'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'Workday'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'Workday'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'WorkingTime', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'WorkingTime'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'entity set with working hours performed and booked by employees', 
              @level0type=N'SCHEMA', @level0name = N'dbo', 
              @level1type = N'TABLE', @level1name = 'WorkingTime'

IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WorkingTime',
                                                N'column', 'ID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WorkingTime',
                                   @level2type = N'COLUMN', @level2name = N'ID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WorkingTime',
                                                N'column', 'StartingTime'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WorkingTime',
                                   @level2type = N'COLUMN', @level2name = N'StartingTime'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'StartingTime'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WorkingTime',
                                                N'column', 'ClosingTime'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WorkingTime',
                                   @level2type = N'COLUMN', @level2name = N'ClosingTime'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'ClosingTime'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WorkingTime',
                                                N'column', 'Processed '))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WorkingTime',
                                   @level2type = N'COLUMN', @level2name = N'Processed '
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'Processed '
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WorkingTime',
                                                N'column', 'ProcessedAt'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WorkingTime',
                                   @level2type = N'COLUMN', @level2name = N'ProcessedAt'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'ProcessedAt'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WorkingTime',
                                                N'column', 'DayOfWork'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WorkingTime',
                                   @level2type = N'COLUMN', @level2name = N'DayOfWork'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'DayOfWork'

