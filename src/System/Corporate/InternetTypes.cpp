/*
* Project: model with a simple person administration
* Implementation of the data class TInternetTypes
* Content: domain / range of values for internet connection types, this is an extension of the relationship between persons and internet connections.
* Date: 25.03.2024 19:08:40,540  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\InternetTypes.h"

#include <typeinfo>

namespace myCorporate {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TInternetTypes
// ---------------------------------------------------------------------------------------
TInternetTypes::primary_key::primary_key() : iID {} { }

TInternetTypes::primary_key::primary_key(int pID) : iID(pID) { }

TInternetTypes::primary_key::primary_key(TInternetTypes const& other) : iID(other._ID()) { }

TInternetTypes::primary_key::primary_key(TInternetTypes::primary_key const& other) : iID(other.iID) { }

TInternetTypes::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TInternetTypes::primary_key::operator TInternetTypes() const {
   TInternetTypes ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TInternetTypes::primary_key::write(std::ostream& out) const {
   out << "elements of class TInternetTypes::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TInternetTypes::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TInternetTypes
// ---------------------------------------------------------------------------------------
TInternetTypes::TInternetTypes() {
   _init();
   }

TInternetTypes::TInternetTypes(TInternetTypes const& other){
   _copy(other);
   }

TInternetTypes::TInternetTypes(TInternetTypes&& other) noexcept {
   _swap(other);
   }

TInternetTypes::TInternetTypes(primary_key const& other) : iID(other.ID()) { }

TInternetTypes::~TInternetTypes() {   }

TInternetTypes& TInternetTypes::operator = (TInternetTypes const& other) {
   copy(other);
   return *this;
   }

TInternetTypes& TInternetTypes::operator = (TInternetTypes&& other) noexcept {
   swap(other);
   return *this;
   }

void TInternetTypes::swap(TInternetTypes& other) noexcept {
   _swap(other);
   }

void TInternetTypes::init() {
   _init();
   }

void TInternetTypes::copy(TSimplePersonBase const& other) {
   try {
      TInternetTypes const& ref = dynamic_cast<TInternetTypes const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TInternetTypes& TInternetTypes::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TInternetTypes::_swap(TInternetTypes& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(strPrefix, other.strPrefix);
   std::swap(strNotes, other.strNotes);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TInternetTypes::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   strPrefix        = {};
   strNotes         = {};
   boUrgentValue    = {};
   return;
   }

// _copy: internal copy method for the class
void TInternetTypes::_copy(TInternetTypes const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Prefix(other.Prefix());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myCorporate
