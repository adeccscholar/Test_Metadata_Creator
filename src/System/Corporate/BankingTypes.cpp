/*
* Project: model with a simple person administration
* Implementation of the data class TBankingTypes
* Content: domain / range of values for banking types, this is an extension of the relationship between persons and banking accounts.
* Date: 17.03.2024 20:08:19,701  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\BankingTypes.h"

#include <typeinfo>

namespace myCorporate {

TBankingTypes::TBankingTypes() {
   _init();
   }

TBankingTypes::TBankingTypes(TBankingTypes const& other){
   _copy(other);
   }

TBankingTypes::TBankingTypes(TBankingTypes&& other) noexcept {
   _swap(other);
   }

TBankingTypes::~TBankingTypes() {   }

TBankingTypes& TBankingTypes::operator = (TBankingTypes const& other) {
   copy(other);
   return *this;
   }

TBankingTypes& TBankingTypes::operator = (TBankingTypes&& other) noexcept {
   swap(other);
   return *this;
   }

void TBankingTypes::swap(TBankingTypes& other) noexcept {
   _swap(other);
   }

void TBankingTypes::init() {
   _init();
   }

void TBankingTypes::copy(TSimplePersonBase const& other) {
   try {
      TBankingTypes const& ref = dynamic_cast<TBankingTypes const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TBankingTypes& TBankingTypes::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TBankingTypes::_swap(TBankingTypes& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(strNotes, other.strNotes);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TBankingTypes::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   strNotes         = {};
   boUrgentValue    = {};
   return;
   }

// _copy: internal copy method for the class
void TBankingTypes::_copy(TBankingTypes const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myCorporate
