/* ------------------------------------------------------------------------------------
 * script with statements to prefill the rangevalues for the project simple person model
 * generated at: 25.03.2024 19:08:39,302 with the adecc Scholar metadata generator
 * author:       Volker Hillmann (adecc Scholar)
 * copyright © adecc Systemhaus GmbH 2024, All rights reserved.
 * ----------------------------------------------------------------------------------- */
INSERT INTO AddressTypes (ID, Denotation, Abbreviation, Description, UrgentValue) VALUES
    (1, 'Hauptadresse', 'HA', 'Hauptadresse für die Anwendung', 1), 
    (2, 'Rechnungsadresse', 'RA', 'Rechnungsadresse für die Anwendung', 0), 
    (3, 'Lieferadresse', 'LA', 'Lieferadresse für die Trainingsanwendung', 0), 
    (4, 'Urlaubsadresse', 'UA', 'eine Adresse, in der die Person im Urlaub erreichbar ist', 0);

INSERT INTO BankingTypes (ID, Denotation, Abbreviation, Description, UrgentValue) VALUES
    (1, 'Hauptkonto', 'HK', 'Hauptkonto für die Personen in der Anwendung', 1);

INSERT INTO CorporateForm (ID, Denotation, Abbreviation, Description, IsLegalEntrity, UrgentValue) VALUES
    (1, 'Gesellschaft mit beschränkter Haftung', 'GmbH', 'Eine GmbH ist eine Kapitalgesellschaft, bei der die Haftung der Gesellschafter auf ihre Einlagen beschränkt ist.', 1, 1), 
    (2, 'Aktiengesellschaft', 'AG', 'Eine AG ist eine Kapitalgesellschaft, deren Grundkapital in Aktien zerlegt ist und deren Eigentümer (Aktionäre) beschränkt haften.', 1, 1), 
    (3, 'Unternehmergesellschaft (haftungsbeschränkt)', 'UG', 'Eine UG ist eine haftungsbeschränkte Kapitalgesellschaft, die eine niedrigere Mindesteinlage erfordert als eine GmbH. Sie kann in eine GmbH umgewandelt werden.', 1, 1), 
    (4, 'Offene Handelsgesellschaft', 'OHG', 'Eine OHG ist eine Personengesellschaft, bei der alle Gesellschafter unbeschränkt und persönlich für die Verbindlichkeiten der Gesellschaft haften.', 1, 1), 
    (5, 'Kommanditgesellschaft', 'KG', 'Eine KG ist eine Personengesellschaft, bei der es neben den unbeschränkt haftenden Gesellschaftern (Komplementären) auch beschränkt haftende Gesellschafter gibt.', 1, 1), 
    (6, 'Einzelkaufmann', 'e.K.', 'Ein e.K. ist eine Einzelunternehmung, bei der der Unternehmer allein und unbeschränkt für alle Verbindlichkeiten haftet.', 0, 1), 
    (7, 'Ges. mit beschr. Haftung & Compagnie Kommanditges.', 'GmbH & Co. KG', 'Eine Gesellschaft mit beschränkter Haftung & Compagnie Kommanditgesellschaft ist eine Kommanditgesellschaft, bei der die Komplementärin eine GmbH ist. Dadurch kann eine GmbH als persönlich haftender Gesellschafter fungieren, während die übrigen Gesellschafter beschränkt haften.', 0, 1), 
    (8, 'Gesellschaft bürgerlichen Rechts', 'GbR', 'Eine GbR ist eine Personengesellschaft, bei der mindestens zwei natürliche oder juristische Personen gemeinsam ein bestimmtes Ziel verfolgen und gemeinsam handeln.', 0, 1);

INSERT INTO CustClassification (ID, Denotation, Abbreviation, Description, UrgentValue) VALUES
    (1, 'Neukunde', 'Neu', 'Ein Kunde, der gerade erst begonnen hat, Geschäfte mit dem Unternehmen zu tätigen und möglicherweise noch nicht viel Erfahrung mit den Produkten oder Dienstleistungen des Unternehmens hat.', 1), 
    (2, 'VIP-Kunde', 'VIP', 'Ein Kunde, der aufgrund seines langjährigen Engagements, seines hohen Umsatzes oder seiner anderen besonderen Merkmale einen VIP-Status im Unternehmen hat.', 1), 
    (3, 'Gelegenheitskunde', 'GK', 'Ein Kunde, der nur gelegentlich Geschäfte mit dem Unternehmen tätigt und keine regelmäßigen oder wiederkehrenden Käufe macht.', 1), 
    (4, 'Geschäftskunde', 'B2B', 'Ein Kunde, der ein anderes Unternehmen oder eine Organisation vertritt und Produkte oder Dienstleistungen für geschäftliche Zwecke erwirbt. Diese Kunden haben oft spezifische Anforderungen und erwarten eine professionelle Betreuung.', 1), 
    (5, 'Privatkunde', 'B2C', 'Ein Kunde, der als Einzelperson Produkte oder Dienstleistungen für den persönlichen Gebrauch erwirbt. Diese Kunden können eine Vielzahl von Bedürfnissen haben und erwarten oft eine persönliche und freundliche Betreuung.', 1);

INSERT INTO CustLiaison (ID, Denotation, Abbreviation, Description, UrgentValue) VALUES
    (1, 'Geschäftsführer/in', 'GV', 'Der Geschäftsführer ist die höchste Führungsperson des Kunden und vertritt das Unternehmen. Sie sind für die strategische Ausrichtung, das Management und die langfristige Entwicklung der Geschäftsbeziehung verantwortlich. Der Geschäftsführer trägt die Gesamtverantwortung für den Erfolg des Projekts.', 1), 
    (2, 'Projektmanager/in', 'Projekt', 'Der Projektleiter ist die zentrale Kontaktperson beim Kunden während eines Projekts. Sie sind verantwortlich für die Planung, Organisation und Überwachung des Projekts sowie für die Koordination aller internen und externen Aktivitäten.', 1), 
    (3, 'Technische/r Berater/in', 'Technik', 'Der technische Ansprechpartner ist eine Person beim Kunden, die als direkter Kontaktpunkt für technische Fragen, Unterstützung und Problemlösungen fungiert.', 1), 
    (4, 'Kaufmännische/r Berater/in', 'Finanzen', 'Der kaufmännische Ansprechpartner ist für alle kaufmännischen Belange beim Kunden zuständig. Er ist verantwortlich für die Verwaltung von Verträgen, Preisgestaltung, Budgetierung und anderen finanziellen Fragen.', 1), 
    (5, 'Vertragsmanager/in', 'Vertrag', 'Der Vertragsmanager ist für die Verwaltung und Überwachung aller vertraglichen Angelegenheiten beim Kunden verantwortlich. Sie sind dafür zuständig, Verträge zu erstellen, zu überprüfen und zu verhandeln, Änderungen zu koordinieren und sicherzustellen, dass alle Vertragsbedingungen eingehalten werden.', 1);

INSERT INTO FamilyStatus (ID, Denotation, Abbreviation, Description, Coupled, NeedDate, UrgentValue) VALUES
    (0, 'unbekannt', 'kA', 'unbekannt oder keine Angabe', 0, 0, 1), 
    (1, 'ledig', 'ldg', 'ledige Person', 0, 0, 1), 
    (2, 'verheiratet', 'verh', 'verheiratete Person', 1, 1, 1), 
    (3, 'geschieden', 'gesch', 'geschiedene Person', 0, 1, 1), 
    (4, 'verwitwert', 'verw', 'verwitwerte Person', 0, 1, 1), 
    (5, 'Lebenspartnerschaft', 'LP', 'eingetragene Lebenspartnerschaft', 1, 1, 0);

INSERT INTO FamilyTypes (ID, Denotation, Abbreviation, Description, UrgentValue) VALUES
    (1, 'Mann', 'M', 'Person mit männlichem Geschlecht', 1), 
    (2, 'Frau', 'F', 'Person mit weiblichen Geschlecht', 1), 
    (3, 'Diverse', 'div', 'Eine Identität, die die Vielfalt der Geschlechteridentitäten umfasst und nicht in die traditionellen binären Kategorien männlich oder weiblich passt.', 1), 
    (4, 'Non-Binär', 'non', 'Eine Identität außerhalb der traditionellen binären Geschlechtkategorien männlich und weiblich, die sich jenseits dieser Konzepte befindet.', 1), 
    (5, 'Firma', 'FA', 'Eine rechtliche Einheit, die gegründet wird, um kommerzielle oder geschäftliche Aktivitäten auszuüben, die in der Regel einen oder mehrere Eigentümer haben.', 1), 
    (6, 'Familie', 'Fam', 'Eine soziale Einheit, die aus Eltern und ihren Kindern besteht, die zusammenleben und sich normalerweise gegenseitig unterstützen und emotional miteinander verbunden sind.', 1), 
    (7, 'Gemeinschaft', 'eLG', 'Eine Form des Zusammenlebens von Menschen, die nicht notwendigerweise auf einer romantischen Beziehung basiert, sondern auf gemeinsamen Zielen, Werten oder Lebensweisen beruht, oft in einem gemeinsamen Haushalt.', 1), 
    (8, 'Verein', 'EV', 'Eine rechtliche und organisatorische Struktur, die von einer Gruppe von Personen gegründet wurde, um gemeinsame Interessen oder Ziele zu verfolgen, oft auf gemeinnütziger Basis.', 1);

INSERT INTO FormOfAddress (ID, Denotation, Abbreviation, Description, TypeSpec, Salutation, Valediction, UrgentValue) VALUES
    (1, 'Herr', 'Hr', 'Anredesteuerung für Herr', 1, 'Sehr geehrter Herr', 'Mit freundlichen Grüßen', 1), 
    (2, 'Frau', 'Fr', 'Anredesteuerung für Frauen', 2, 'Sehr geehrte Frau', 'Mit freundlichen Grüßen', 1), 
    (3, 'Firma', 'Fa', 'Anredesteuerung für Firmen', 3, 'Sehr geehrte Damen und Herren', 'Mit freundlichen Grüßen', 0);

INSERT INTO InternetTypes (ID, Denotation, Abbreviation, Description, Prefix, UrgentValue) VALUES
    (1, 'Internet', 'HTTP', 'Die Homepage einer Person', 'http://', 1), 
    (2, 'Email', 'Mail', 'Email- Adresse einer Person', 'mailto:', 1), 
    (3, 'Skype', 'Skype', 'Skype- Name einer Person', 'skype:', 1), 
    (4, 'Telefon', 'VoIP', 'VoIP- Nummer einer Person', 'phone:', 1);

INSERT INTO PhoneTypes (ID, Denotation, Abbreviation, Description, UrgentValue) VALUES
    (1, 'Telefon', 'Tel', 'Telefonnummer zu einer Person', 1), 
    (2, 'Fax', 'Fax', 'Faxnummer zu einer Person', 1), 
    (3, 'Mobil', 'Mbl', 'Mobiltelefonnummer zu einer Person', 1);

INSERT INTO ReasonDeparture (ID, Denotation, Abbreviation, Description, UrgentValue) VALUES
    (1, 'Kündigung', 'Kü', 'Die Person hat freiwillig beschlossen, das Unternehmen zu verlassen (Resignation).', 1), 
    (2, 'Rente', 'Re', 'Die Person verlässt das Unternehmen aufgrund des Erreichens des Rentenalters oder aus Altersgründen (Retirement ).', 1), 
    (3, 'Entlassung', 'En', 'Das Unternehmen hat das Arbeitsverhältnis mit der Person beendet (Dismissal )', 1), 
    (4, 'Restrukturierung', 'St', 'Die Person wird nicht mehr in diesem Programm geführt, da sie in einem anderen Unternehmensteil beschäftigt wird (restructuring).', 1);

INSERT INTO ReasonNonWorking (ID, Denotation, Abbreviation, Description, UrgentValue) VALUES
    (1, 'Urlaub', 'U', 'Die Person hat regulären Urlaub (inklusive eventuelle Tage Resturlaub', 1), 
    (2, 'Sonderurlaub', 'SU', 'Die Person hat Sonderurlaub', 1), 
    (3, 'Krankheit bezahlt', 'K', 'Die Person ist krankgeschrieben', 1), 
    (4, 'Krankheit unbezahlt', 'KU', 'Die Person ist krankgeschrieben, aber die Krankenkasse zahlt.', 1), 
    (5, 'unbezahlt', 'unbez', 'Die Person ist unbezahlt freigestellt', 1);

INSERT INTO SalaryBase (ID, Denotation, Abbreviation, Description, UrgentValue) VALUES
    (0, 'ohne', 'f', 'Die Angabe des Gehalts wird ignoriert oder einmalig gezahlt. Kostenloses Praktikum oder Probezeit.', 1), 
    (1, 'stündlich', 'h', 'Die Angabe des Gehalts erfolgt auf Stundenbasis. Entspricht meistens dem Arbeitslohn, eventuell mit Zuschlägen.', 1), 
    (2, 'täglich', 'd', 'Die Angabe des Gehalts erfolgt auf Tagesbasis. Dieses wird oft für Honorare verwendet.', 1), 
    (3, 'monatlich', 'm', 'Die Angabe des Bezugs erfolgt auf Monatsbasis.Das entspricht meistens dem Gehalt bei Angestellten*innen', 1);

INSERT INTO TaxClasses (ID, Denotation, Abbreviation, Description, Coupled, UrgentValue) VALUES
    (1, 'Steuerklasse 1', 'I', 'Dies ist die Standardsteuerklasse für alleinstehende Personen ohne Kinder.', 0, 1), 
    (2, 'Steuerklasse 2', 'II', 'Diese Steuerklasse ist für Alleinerziehende mit mindestens einem Kind gedacht.', 0, 1), 
    (3, 'Steuerklasse 3', 'III', 'Diese Klasse ist für verheiratete oder in einer eingetragenen Lebenspartnerschaft lebende Personen, wenn der Ehe- oder Lebenspartner in Steuerklasse V eingestuft ist oder keine Einkünfte hat.', 1, 1), 
    (4, 'Steuerklasse 4', 'IV', 'Dies ist die Standardsteuerklasse für verheiratete oder in einer eingetragenen Lebenspartnerschaft lebende Personen, wenn beide Partner ein ähnliches Einkommen haben.', 1, 1), 
    (5, 'Steuerklasse 5', 'V', 'Diese Klasse wird für den Ehe- oder Lebenspartner verwendet, wenn der andere Partner in Steuerklasse III eingestuft ist.', 1, 1), 
    (6, 'Steuerklasse 6', 'VI', 'Diese Klasse wird verwendet, wenn eine Person mehrere Jobs hat oder zusätzliche Einkünfte aus einer geringfügigen Beschäftigung hat.', 0, 1), 
    (7, 'Ausland', 'A', 'Person wohnt im Ausland, Steuer individuell bestimmen ', 0, 1), 
    (8, 'unbekannt', '-', 'Steuerklasse noch unbekannt, unbedingt nachfragen, vorläufig als Steuerklasse 6 abrechnen', 0, 1);

INSERT INTO WD_Months (ID, Denotation, Abbreviation, Quarter) VALUES
    (1, 'Januar', 'Jan', 1), 
    (2, 'Februar', 'Feb', 1), 
    (3, 'März', 'Mär', 1), 
    (4, 'April', 'Apr', 2), 
    (5, 'Mai', 'Mai', 2), 
    (6, 'Juni', 'Jun', 2), 
    (7, 'Juli', 'Jul', 3), 
    (8, 'August', 'Aug', 3), 
    (9, 'September', 'Sep', 3), 
    (10, 'Oktober', 'Okt', 4), 
    (11, 'November', 'Nov', 4), 
    (12, 'Dezember', 'Dez', 4);

INSERT INTO WD_Weekdays (ID, Denotation, Abbreviation, Workday) VALUES
    (0, 'Montag', 'Mo', 1), 
    (1, 'Dienstag', 'Di', 1), 
    (2, 'Mittwoch', 'Mi', 1), 
    (3, 'Donnerstag', 'Do', 1), 
    (4, 'Freitag', 'Fr', 1), 
    (5, 'Sonnabend', 'Sa', 0), 
    (6, 'Sonntag', 'So', 0);

