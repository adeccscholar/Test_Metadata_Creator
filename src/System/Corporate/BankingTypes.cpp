/*
* Project: model with a simple person administration
* Implementation of the data class TBankingTypes
* Content: domain / range of values for banking types, this is an extension of the relationship between persons and banking accounts.
* Date: 25.03.2024 19:08:39,808  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\BankingTypes.h"

#include <typeinfo>

namespace myCorporate {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TBankingTypes
// ---------------------------------------------------------------------------------------
TBankingTypes::primary_key::primary_key() : iID {} { }

TBankingTypes::primary_key::primary_key(int pID) : iID(pID) { }

TBankingTypes::primary_key::primary_key(TBankingTypes const& other) : iID(other._ID()) { }

TBankingTypes::primary_key::primary_key(TBankingTypes::primary_key const& other) : iID(other.iID) { }

TBankingTypes::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TBankingTypes::primary_key::operator TBankingTypes() const {
   TBankingTypes ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TBankingTypes::primary_key::write(std::ostream& out) const {
   out << "elements of class TBankingTypes::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TBankingTypes::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TBankingTypes
// ---------------------------------------------------------------------------------------
TBankingTypes::TBankingTypes() {
   _init();
   }

TBankingTypes::TBankingTypes(TBankingTypes const& other){
   _copy(other);
   }

TBankingTypes::TBankingTypes(TBankingTypes&& other) noexcept {
   _swap(other);
   }

TBankingTypes::TBankingTypes(primary_key const& other) : iID(other.ID()) { }

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
