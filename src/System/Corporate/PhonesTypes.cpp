/*
* Project: model with a simple person administration
* Implementation of the data class TPhonesTypes
* Content: domain / range of values for phone types, this is an extension of the relationship between persons and phone.
* Date: 25.03.2024 19:08:40,781  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\PhonesTypes.h"

#include <typeinfo>

namespace myCorporate {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TPhonesTypes
// ---------------------------------------------------------------------------------------
TPhonesTypes::primary_key::primary_key() : iID {} { }

TPhonesTypes::primary_key::primary_key(int pID) : iID(pID) { }

TPhonesTypes::primary_key::primary_key(TPhonesTypes const& other) : iID(other._ID()) { }

TPhonesTypes::primary_key::primary_key(TPhonesTypes::primary_key const& other) : iID(other.iID) { }

TPhonesTypes::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TPhonesTypes::primary_key::operator TPhonesTypes() const {
   TPhonesTypes ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TPhonesTypes::primary_key::write(std::ostream& out) const {
   out << "elements of class TPhonesTypes::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TPhonesTypes::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TPhonesTypes
// ---------------------------------------------------------------------------------------
TPhonesTypes::TPhonesTypes() {
   _init();
   }

TPhonesTypes::TPhonesTypes(TPhonesTypes const& other){
   _copy(other);
   }

TPhonesTypes::TPhonesTypes(TPhonesTypes&& other) noexcept {
   _swap(other);
   }

TPhonesTypes::TPhonesTypes(primary_key const& other) : iID(other.ID()) { }

TPhonesTypes::~TPhonesTypes() {   }

TPhonesTypes& TPhonesTypes::operator = (TPhonesTypes const& other) {
   copy(other);
   return *this;
   }

TPhonesTypes& TPhonesTypes::operator = (TPhonesTypes&& other) noexcept {
   swap(other);
   return *this;
   }

void TPhonesTypes::swap(TPhonesTypes& other) noexcept {
   _swap(other);
   }

void TPhonesTypes::init() {
   _init();
   }

void TPhonesTypes::copy(TSimplePersonBase const& other) {
   try {
      TPhonesTypes const& ref = dynamic_cast<TPhonesTypes const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TPhonesTypes& TPhonesTypes::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TPhonesTypes::_swap(TPhonesTypes& other) noexcept {
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
void TPhonesTypes::_init() {
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
void TPhonesTypes::_copy(TPhonesTypes const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myCorporate
