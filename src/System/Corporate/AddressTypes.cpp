/*
* Project: model with a simple person administration
* Implementation of the data class TAddressTypes
* Content: domain / range of values for address types, this is an extension of the relationship between persons and addresses.
* Date: 22.04.2025 22:26:55,246  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\AddressTypes.h"

#include <typeinfo>

namespace myCorporate {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TAddressTypes
// ---------------------------------------------------------------------------------------
TAddressTypes::primary_key::primary_key() : iID {} { }

TAddressTypes::primary_key::primary_key(int pID) : iID(pID) { }

TAddressTypes::primary_key::primary_key(TAddressTypes const& other) : iID(other._ID()) { }

TAddressTypes::primary_key::primary_key(TAddressTypes::primary_key const& other) : iID(other.iID) { }

TAddressTypes::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TAddressTypes::primary_key::operator TAddressTypes() const {
   TAddressTypes ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TAddressTypes::primary_key::write(std::ostream& out) const {
   out << "elements of class TAddressTypes::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TAddressTypes::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TAddressTypes
// ---------------------------------------------------------------------------------------
TAddressTypes::TAddressTypes() {
   _init();
   }

TAddressTypes::TAddressTypes(TAddressTypes const& other){
   _copy(other);
   }

TAddressTypes::TAddressTypes(TAddressTypes&& other) noexcept {
   _swap(other);
   }

TAddressTypes::TAddressTypes(primary_key const& other) : iID(other.ID()) { }

TAddressTypes::~TAddressTypes() {   }

TAddressTypes& TAddressTypes::operator = (TAddressTypes const& other) {
   copy(other);
   return *this;
   }

TAddressTypes& TAddressTypes::operator = (TAddressTypes&& other) noexcept {
   swap(other);
   return *this;
   }

void TAddressTypes::swap(TAddressTypes& other) noexcept {
   _swap(other);
   }

void TAddressTypes::init() {
   _init();
   }

void TAddressTypes::copy(TSimplePersonBase const& other) {
   try {
      TAddressTypes const& ref = dynamic_cast<TAddressTypes const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TAddressTypes& TAddressTypes::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TAddressTypes::_swap(TAddressTypes& other) noexcept {
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
void TAddressTypes::_init() {
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
void TAddressTypes::_copy(TAddressTypes const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myCorporate
