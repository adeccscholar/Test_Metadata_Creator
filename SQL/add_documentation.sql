/* ------------------------------------------------------------------------------------
 * script with statements to add descriptions for the project simple person model
 * generated at: 17.03.2024 20:08:19,245 with the adecc Scholar metadata generator
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
              @value = N'information on the addresses where a person lives, works or has any other relationship with them.', 
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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'attribute as Foreign key from an attribute ID of the person entity to whom the address belongs', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'AddressType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'AddressType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'extension of the key by the address type to manage different addresses for one person', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'AddressType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'Zipcode'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'Zipcode'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'Zip code for the address', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'Zipcode'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'City'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'City'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'name of the city/county (possibly with district) for this address', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'City'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'Street'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'Street'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'name of the street belonging to this address', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'Street'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'StreetNumber'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'StreetNumber'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'house number with addition for this address', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'StreetNumber'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Address',
                                                N'column', 'Country'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Address',
                                   @level2type = N'COLUMN', @level2name = N'Country'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'ID of the country for the address, key attribute from the Countries entity', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Address', @level2type = N'COLUMN', @level2name = N'Country'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in this domain with address types', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'AddressTypes',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'AddressTypes',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique description of an entry in the domain, display in selections, comboboxes, … (key canditate)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'AddressTypes',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'AddressTypes',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'non-representative abbreviation that can be used for a short advertisement for this address', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'AddressTypes',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'AddressTypes',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'detailed description of these address types, what is associated with them. Self documentation, possible use as hint', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'AddressTypes',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'AddressTypes',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for this AddressType, not used in application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'AddressTypes',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'AddressTypes',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of address type to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'AddressTypes', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'attribute as foreign key from an attribute ID of a person entity to which these account details belong', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'BankingType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'BankingType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'extension of the account details key in order to be able to save several / different bank details in a standardized way', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'BankingType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'BankName'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'BankName'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'name of the bank that manages this account (not necessarily required)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'BankName'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'IBAN'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'IBAN'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'IBAN number (account identification) for this bank account (required)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'IBAN'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'BIC'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'BIC'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'BIC number of the bank that manages this account (not necessarily required for transactions inside europe)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'BIC'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'BankOwner'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'BankOwner'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'optionally the name of the owner of the bank details, if this differs from the assigned person', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'BankOwner'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Banking',
                                                N'column', 'Country'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Banking',
                                   @level2type = N'COLUMN', @level2name = N'Country'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'ID of the country for the banking entity, key attribute from the Countries entity', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Banking', @level2type = N'COLUMN', @level2name = N'Country'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in this domain with banking types', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'BankingTypes',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'BankingTypes',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique description of an banking type entity in the domain, used in selections, comboboxes, … (key canditate)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'BankingTypes',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'BankingTypes',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'non-representative abbreviation that can be used for a short advertisement for this banking type', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'BankingTypes',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'BankingTypes',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'detailed description of these banking type,this is a self documentation, possible use as hint or to information in the programm', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'BankingTypes',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'BankingTypes',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for this type of banking, not used in application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'BankingTypes',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'BankingTypes',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of banking type to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'BankingTypes', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'internal id for this contact, attribute as foreign key from an attribute ID of a person entity ', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Contacts', @level2type = N'COLUMN', @level2name = N'ContactID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Contacts',
                                                N'column', 'CustID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Contacts',
                                   @level2type = N'COLUMN', @level2name = N'CustID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'Customer identification number of the contact associated customer.', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Contacts', @level2type = N'COLUMN', @level2name = N'CustID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Contacts',
                                                N'column', 'CustLiaison'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Contacts',
                                   @level2type = N'COLUMN', @level2name = N'CustLiaison'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'liaision for this contact person as range value (from table CustLiasion)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Contacts', @level2type = N'COLUMN', @level2name = N'CustLiaison'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in the table Countries', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique, official designation of the country, key candidate', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'abbreviation of the country for the program (iso code 3166 - alpha 3)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'text field for the description of the country. can be used by the program to provide additional information, for example in the status bar or a hint', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'CountryDialing'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'CountryDialing'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'international country code for telephone for this country (not unique)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'CountryDialing'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'ISO_Code'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'ISO_Code'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique, official international code (ISO code 3166 - alpha 2) for the country in the communication', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'ISO_Code'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'IsEU'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'IsEU'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value which is true when the country part of the european union', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'IsEU'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Capital'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Capital'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'name of the capital of this country ', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Capital'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Currency'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Currency'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'currency in this country', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Currency'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for this country, not used in application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Countries',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Countries',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of country to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Countries', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number / id of this classification of a customer', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustClassification',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustClassification',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique denotation of this classification of a customer', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustClassification',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustClassification',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'abbreviation of this classification of a customer, used in the application for a compact display', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustClassification',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustClassification',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'description as long text of this classification of a customer, used in the application for detailed informations', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustClassification',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustClassification',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information of this classification of a customer, not used in the application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustClassification',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustClassification',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of this classification of a customer to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustClassification', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number / id of this liaison to use a contact in a customer', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustLiaison',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustLiaison',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique denotation of this liaison to use a contact in a customer', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustLiaison',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustLiaison',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'abbreviation of this liaison to use a contact in a customer, used in the application for a compact display', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustLiaison',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustLiaison',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'description as long text of this liaison to use a contact in a customer, used in the application for detailed informations', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustLiaison',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustLiaison',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information of this  liaison to use a contact in a customer, not used in the application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'CustLiaison',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'CustLiaison',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of this liaison to use a contact in a customer to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'CustLiaison', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'internal id for this client, attribute as foreign key from an attribute ID of a person entity to which these account details belong', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Customers', @level2type = N'COLUMN', @level2name = N'CustID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Customers',
                                                N'column', 'ServiceAgent'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Customers',
                                   @level2type = N'COLUMN', @level2name = N'ServiceAgent'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'employee is  responsible for this client (association with the employys entity)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Customers', @level2type = N'COLUMN', @level2name = N'ServiceAgent'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Customers',
                                                N'column', 'CustClassification'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Customers',
                                   @level2type = N'COLUMN', @level2name = N'CustClassification'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'classification of this customer as range value ', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Customers', @level2type = N'COLUMN', @level2name = N'CustClassification'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identifications number of the department. primary key and used for assoziations', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Departments',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Departments',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'distinct name of the department in the company. used to identify this and use in application for select', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Departments',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Departments',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'used abbreviation of the department for list and such', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Departments',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Departments',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'description for this department, is used in the program, for example as hint ', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Departments',
                                                N'column', 'Officer'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Departments',
                                   @level2type = N'COLUMN', @level2name = N'Officer'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'person responsible / head of this department (association with the employys entity)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'Officer'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Departments',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Departments',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'free notes to record information that is not used in the program', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Departments', @level2type = N'COLUMN', @level2name = N'Notes'

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
                                                N'column', 'Dummy'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'Dummy'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'dummy field to test the generator', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'Dummy'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'EmployeeID'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'EmployeeID'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'attribute as foreign key from an attribute ID of a person entity to which these account details belong', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'EmployeeID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'PersonNumber'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'PersonNumber'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique HR number of the employee in the company, assigned by the HR department', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'PersonNumber'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'Salary'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'Salary'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'salary / income that the employee currently receives, dependant by the SalaryBase', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'Salary'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'SalaryType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'SalaryType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'range for SalaryType with the kind of Salary and determine the SalaryBase for the calculation', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'SalaryType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'TaxClass'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'TaxClass'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'Tax class currently held by the employee', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'TaxClass'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'StartOfJob'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'StartOfJob'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'starting date of the employee in the company (can be extended later for the start of the current position)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'StartOfJob'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'EndOfJob'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'EndOfJob'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'end date of the employee in the company, all dates without time history', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'EndOfJob'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'ReasonDeparture'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'ReasonDeparture'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'reason of departture when the person separated and the emplyment finished (NULL if active)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'ReasonDeparture'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'JobPosition'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'JobPosition'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'current position / activity of the employee within the company', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'JobPosition'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'JobSpec'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'JobSpec'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'specification of the job as free text to concretize this', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'JobSpec'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'VacationDays'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'VacationDays'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'Entitlement to annual vacations for this employee', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'VacationDays'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'Department'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'Department'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'id of the department where the employee currently work', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'Department'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'SocialNummer'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'SocialNummer'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'social insurance number of the employee', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'SocialNummer'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Employees',
                                                N'column', 'Active'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Employees',
                                   @level2type = N'COLUMN', @level2name = N'Active'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'calculated boolean value indicating whether the person is active in the company', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Employees', @level2type = N'COLUMN', @level2name = N'Active'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in this domain with family status', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique description of a family status entity in the domain, used in selections, comboboxes, … (key canditate)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'non-representative abbreviation that can be used for a short advertisement for this family status', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'detailed description of these family status,this is a self documentation, possible use as hint or to information in the programm', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'Coupled'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'Coupled'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that show if persones with this status are coupled and possibly receive tax relief', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'Coupled'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'NeedDate'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'NeedDate'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value which determine that the date when the person status changed the last time needed. ', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'NeedDate'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for this type of family status, not used in application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyStatus',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyStatus',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of phone type to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyStatus', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in this domain with family types', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique description of a family type entity in the domain, used in selections, comboboxes, … (key canditate)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'non-representative abbreviation that can be used for a short advertisement for this banking type', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'IsNaturalPerson'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'IsNaturalPerson'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean indicator whether this entity is a natural person when true, otherwise ist a legal entity', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'IsNaturalPerson'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'detailed description of these family type,this is a self documentation, possible use as hint or to information in the programm', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for this type of family status, not used in application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FamilyTypes',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FamilyTypes',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of family type to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FamilyTypes', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number of the form of address to use it in relationships', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique description of  this form of address entity in the domain, used in selections, comboboxes, … (key canditate)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'non-representative abbreviation that can be used for a short advertisement for this form of address', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'detailed description of these form of address,this is a self documentation, possible use as hint or to information in the programm', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'TypeSpec'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'TypeSpec'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'value from FamilyTypes who determine the art of persontype (gender, legal form, …)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'TypeSpec'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Salutation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Salutation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'salutation formula to be used in letters and emails for this salutation type and therefore person type', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Salutation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Valediction'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Valediction'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'farewell formula to be used in letters and emails for this salutation type and therefore person type', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Valediction'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for this type of form of address, not used in application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'FormOfAddress',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'FormOfAddress',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of form of address type to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'FormOfAddress', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number of the person to whom the internet connection data belongs (foreign key from person)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Internet', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Internet',
                                                N'column', 'InternetType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Internet',
                                   @level2type = N'COLUMN', @level2name = N'InternetType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'type of internet connection data (value range from InternetType as foreign key, extension to 1:n relationship))', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Internet', @level2type = N'COLUMN', @level2name = N'InternetType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Internet',
                                                N'column', 'Adresse'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Internet',
                                   @level2type = N'COLUMN', @level2name = N'Adresse'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'internet address for this connection, possible to split the protocol to the value table InternetTypes', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Internet', @level2type = N'COLUMN', @level2name = N'Adresse'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in this domain with internet connection types', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique description of an internet connection type entity in the domain, used in selections, comboboxes, … (key canditate)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'non-representative abbreviation that can be used for a short advertisement for this internet connection type', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'detailed description of these internet connection type,this is a self documentation, possible use as hint or to information in the programm', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'Prefix'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'Prefix'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'protocoll prefix which is used for this internet type (smtp:, phone:, https_, ...)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'Prefix'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for this type of internet connection, not used in application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'InternetTypes',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'InternetTypes',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of internet connection type to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'InternetTypes', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in this domain with positions in job', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique denotation for this job position, used in selections, and lists to descripe this position', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'abbreviation for this job position, used in overvies. Can be null and dont need be unique', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'detailed description of these job position, this is a self documentation, possible use as hint or to information in the programm', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'SalaryType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'SalaryType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'prefered salary type for this job positions. may be overridden in emplyee for individual aggreements', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'SalaryType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for this type of job position, not used in application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'JobPositions',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'JobPositions',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of job position to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'JobPositions', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a entity of person', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'Name'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'Name'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'family name of the natural person respectively the name for a legal entity', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'Name'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'Firstname'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'Firstname'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'first name of the natural person respectively a name extenstion for a legal entity', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'Firstname'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'FormOfAddress'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'FormOfAddress'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'form of address for this person. this attribute control the kind of a person too', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'FormOfAddress'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'FamilyStatus'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'FamilyStatus'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'family status for the person', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'FamilyStatus'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'FamilyStatusSince'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'FamilyStatusSince'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'the date from which the current family status applies.', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'FamilyStatusSince'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'Birthday'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'Birthday'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'birthday of a natural person. This attribute is unused for legal entrities', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'Birthday'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for this tperson, not used in application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Person',
                                                N'column', 'FullName'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Person',
                                   @level2type = N'COLUMN', @level2name = N'FullName'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'calculated field for displaying the full name for use in the program, for example, if a person is to be selected', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Person', @level2type = N'COLUMN', @level2name = N'FullName'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number of the person to whom the phone data belongs (foreign key from person)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'PhoneType'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'PhoneType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'type of telephone data (value range from PhoneType as foreign key, extension to 1:n relationship))', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'PhoneType'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'AreaCode'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'AreaCode'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'area code or network code of the telephone connection', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'AreaCode'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'CallNumber'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'CallNumber'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'call number within the local network or the selected cellphone network', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'CallNumber'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'Country'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'Country'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'country id for this data as foreign key in the Countries table. the country code is also located here', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'Country'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'DialingNational'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'DialingNational'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'complete telephone number to be dialed in the national network as computed field', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'DialingNational'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'Phone',
                                                N'column', 'DialingInternational'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'Phone',
                                   @level2type = N'COLUMN', @level2name = N'DialingInternational'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'complete telephone number to be dialed in the international network as computed field', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'Phone', @level2type = N'COLUMN', @level2name = N'DialingInternational'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in this domain with phone types', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'PhoneTypes',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'PhoneTypes',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique description of a phone type entity in the domain, used in selections, comboboxes, … (key canditate)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'PhoneTypes',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'PhoneTypes',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'non-representative abbreviation that can be used for a short advertisement for this phone  type', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'PhoneTypes',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'PhoneTypes',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'detailed description of these phone  type,this is a self documentation, possible use as hint or to information in the programm', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'PhoneTypes',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'PhoneTypes',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for this type of banking, not used in application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'PhoneTypes',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'PhoneTypes',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of phone type to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'PhoneTypes', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'ReasonDeparture', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'ReasonDeparture'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'doman range with the reason of departure of the employee', 
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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number / id of the reason of the departure', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonDeparture',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonDeparture',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique denotation for the reason of the departure', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonDeparture',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonDeparture',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'abbreviation for the reason of the departure, used in the application for a compact display', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonDeparture',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonDeparture',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'description as long text for the reason of the departure, used in the application for detailed informations', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonDeparture',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonDeparture',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for the reason of the departure, not used in the application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonDeparture',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonDeparture',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of reason of departure to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonDeparture', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number / id of the reason of non working times / idle times', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonNonWorking',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonNonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique denotation for the reason of the non working times / idle times', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonNonWorking',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonNonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'abbreviation for the reason of the non working times / idle times, used in the application for a compact display', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonNonWorking',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonNonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'description as long text for the reason of the non working times / idle times, used in the application for detailed informations', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonNonWorking',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonNonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'notes, with additional / free information for the reason of the non working times / idle times, not used in the application', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'Notes'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'ReasonNonWorking',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'ReasonNonWorking',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of reason of departure to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'ReasonNonWorking', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'ID for this Base of Salary (0 = free, 1 = hourly, 2 = dayly, 3 = monthly). Extentable via model, needed for calculations', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryBase', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryBase',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryBase',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique description / donation for this base of salary. The algorithm use the id , the text is for display or select', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryBase', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryBase',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryBase',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique abbreviation for this base of salary. The algorithm use the id , the text is for display or select', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryBase', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryBase',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryBase',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'a longer description for this base to use as hint or for display', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryBase', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryBase',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryBase',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of salary base to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryBase', @level2type = N'COLUMN', @level2name = N'UrgentValue'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'SalaryType', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'SalaryType'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'kind of salary as range value and base for calculations (flix, bonus, hourly, dayly, monthly, ...)', 
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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number / id of the type of salary', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryType',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryType',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique denotation for the type of salary', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryType',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryType',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'abbreviation for thetype of salary, used in the application for a compact display', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryType',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryType',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'description as long text for the type of salary, used in the application for detailed informations', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryType',
                                                N'column', 'SalaryBase'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryType',
                                   @level2type = N'COLUMN', @level2name = N'SalaryBase'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'id of the salary base which is used for this type of salary (foreign key from SalaryBase)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'SalaryBase'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'SalaryType',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'SalaryType',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of salary base to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'SalaryType', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in this domain with tax classes, used as key and attribute for relationships', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'TaxClasses',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'TaxClasses',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in this domain with tax class types, used in the programm to indentify this tax class, as selection in comboboxes and such', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'TaxClasses',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'TaxClasses',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique abbreviation of a tax class entity in the domain, used in overviews and reports', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'TaxClasses',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'TaxClasses',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'description for this tax class, used for the program', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'Description'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'TaxClasses',
                                                N'column', 'Coupled'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'TaxClasses',
                                   @level2type = N'COLUMN', @level2name = N'Coupled'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'Indicator whether this tax class applies to married couples or registered civil partnerships', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'Coupled'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'TaxClasses',
                                                N'column', 'UrgentValue'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'TaxClasses',
                                   @level2type = N'COLUMN', @level2name = N'UrgentValue'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value that makes this entity of tax classes to a system value (cannot be changed as it is used directly by the program)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'TaxClasses', @level2type = N'COLUMN', @level2name = N'UrgentValue'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'calendar day on which the holiday is', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Holidays', @level2type = N'COLUMN', @level2name = N'CalendarDay'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Holidays',
                                                N'column', 'Donation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Holidays',
                                   @level2type = N'COLUMN', @level2name = N'Donation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'specification of the holiday as text', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Holidays', @level2type = N'COLUMN', @level2name = N'Donation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Holidays',
                                                N'column', 'Share'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Holidays',
                                   @level2type = N'COLUMN', @level2name = N'Share'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'share of the holiday (addition for later extension, e.g. holy eve as a half holiday)', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Holidays', @level2type = N'COLUMN', @level2name = N'Share'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Holidays',
                                                N'column', 'Description'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Holidays',
                                   @level2type = N'COLUMN', @level2name = N'Description'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'additional, more detailed description of the holiday. can use as hint in programm or reports', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Holidays', @level2type = N'COLUMN', @level2name = N'Description'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in this domain with monthes for human resources', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Months', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Months',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Months',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique denotation for a record in this domain with months, used in the programm to indentify this month, as selection in comboboxes and such', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Months', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Months',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Months',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique abbreviation of a month in the domain, used in overviews and reports', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Months', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Months',
                                                N'column', 'Quarter'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Months',
                                   @level2type = N'COLUMN', @level2name = N'Quarter'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unsigned value with the number auf the quarter, values in 1 - 4', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Months', @level2type = N'COLUMN', @level2name = N'Quarter'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'attribute as foreign key from an attribute ID of a employee entity to who as idle this time', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_NonWorking', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_NonWorking',
                                                N'column', 'StartAt'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_NonWorking',
                                   @level2type = N'COLUMN', @level2name = N'StartAt'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'date when the non working time starts as foreign key from the wokdays table', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_NonWorking', @level2type = N'COLUMN', @level2name = N'StartAt'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_NonWorking',
                                                N'column', 'ClosingAt'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_NonWorking',
                                   @level2type = N'COLUMN', @level2name = N'ClosingAt'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'date when the non working time finishing. Value must exists in workdays, but isnt in the key. May be open', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_NonWorking', @level2type = N'COLUMN', @level2name = N'ClosingAt'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_NonWorking',
                                                N'column', 'Reason'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_NonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Reason'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'reason of non working time, there exist a table, but values are interpreted through the applications', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_NonWorking', @level2type = N'COLUMN', @level2name = N'Reason'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_NonWorking',
                                                N'column', 'Notes'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_NonWorking',
                                   @level2type = N'COLUMN', @level2name = N'Notes'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'free notices to the non-working time', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_NonWorking', @level2type = N'COLUMN', @level2name = N'Notes'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique identification number for a record in this domain with weekdays for human resources', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Weekdays', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Weekdays',
                                                N'column', 'Denotation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Weekdays',
                                   @level2type = N'COLUMN', @level2name = N'Denotation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique denation for this weekday ', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Weekdays', @level2type = N'COLUMN', @level2name = N'Denotation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Weekdays',
                                                N'column', 'Abbreviation'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Weekdays',
                                   @level2type = N'COLUMN', @level2name = N'Abbreviation'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'unique abbreviation for this weekday ', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Weekdays', @level2type = N'COLUMN', @level2name = N'Abbreviation'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Weekdays',
                                                N'column', 'Workday'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Weekdays',
                                   @level2type = N'COLUMN', @level2name = N'Workday'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value to control the work time, true if this weekday usual a workday', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Weekdays', @level2type = N'COLUMN', @level2name = N'Workday'

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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'calendar day. is used as a key in all day-dependent time accounting tables. it is the basis for the calculated fields that are provided also', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarDay'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarWeekday'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarWeekday'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'day in the calendar week (values between 0 .. 6). The field referencing to the table with weekdays to get rules. set as a data element to avoid calculations, possible server settings and deviations from various standards', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarWeekday'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarWeek'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarWeek'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'calendar week. set as a data element to avoid calculations, possible server settings and deviations from various standards', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarWeek'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarYear'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarYear'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'calculated field for the year of the calendar day', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarYear'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarMonth'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarMonth'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'calculated field for the year of the calendar day, persistent for the relationship to the table WD_Months', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarMonth'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarDayInWeek'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarDayInWeek'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'calculated field for the year of the calendar day', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarDayInWeek'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarDayInYear'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarDayInYear'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'calculated field for the year of the calendar day', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarDayInYear'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'CalendarQuarter'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'CalendarQuarter'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'calculated field, use relationship to WD_Months and the function GetQuarterOfMonth to get the quarter', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'CalendarQuarter'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WD_Workdays',
                                                N'column', 'Workday'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WD_Workdays',
                                   @level2type = N'COLUMN', @level2name = N'Workday'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean value which determin the day as work day, using functions of WD_Weekdays and WD_Holidays', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WD_Workdays', @level2type = N'COLUMN', @level2name = N'Workday'

IF EXISTS (SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', N'dbo', N'table', N'WorkingTime', NULL, NULL))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description', 
                                    @level0type=N'SCHEMA', @level0name = N'dbo', 
                                    @level1type = N'TABLE', @level1name = 'WorkingTime'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', 
              @value = N'entity with the working times for an employee, as a composition for these.', 
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

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'attribute as foreign key from an attribute ID of a employee entity to who as worked these time', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'ID'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WorkingTime',
                                                N'column', 'StartingTime'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WorkingTime',
                                   @level2type = N'COLUMN', @level2name = N'StartingTime'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'date and time at which this work block started as timestamp', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'StartingTime'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WorkingTime',
                                                N'column', 'ClosingTime'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WorkingTime',
                                   @level2type = N'COLUMN', @level2name = N'ClosingTime'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'date and time at which this block of work finished as timestamp', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'ClosingTime'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WorkingTime',
                                                N'column', 'Processed '))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WorkingTime',
                                   @level2type = N'COLUMN', @level2name = N'Processed '
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'boolean indicator that specifies whether this time booking has already been charged', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'Processed '
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WorkingTime',
                                                N'column', 'ProcessedAt'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WorkingTime',
                                   @level2type = N'COLUMN', @level2name = N'ProcessedAt'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'time at which this data record was settled and posted', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'ProcessedAt'
IF EXISTS(SELECT 1 FROM fn_listextendedproperty(N'MS_Description', N'schema', 'dbo',
                                                N'table', 'WorkingTime',
                                                N'column', 'DayOfWork'))
BEGIN
   EXEC sys.sp_dropextendedproperty @name = N'MS_Description',
                                   @level0type=N'SCHEMA', @level0name = N'dbo',
                                   @level1type = N'TABLE', @level1name = 'WorkingTime',
                                   @level2type = N'COLUMN', @level2name = N'DayOfWork'
END

EXEC sys.sp_addextendedproperty @name = N'MS_Description', @value = N'calculated day to the timepoint where work started', @level0type=N'SCHEMA', @level0name = N'dbo', @level1type = N'TABLE', @level1name = 'WorkingTime', @level2type = N'COLUMN', @level2name = N'DayOfWork'

