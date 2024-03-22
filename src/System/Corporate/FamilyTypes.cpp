/*
* Project: model with a simple person administration
* Implementation of the data class TFamilyTypes
* Content: domain / range of values for family types, this is used in form of address to qualifify the person gender
* Date: 22.03.2024 15:39:12,270  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\FamilyTypes.h"

#include <typeinfo>

namespace myCorporate {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TFamilyTypes
// ---------------------------------------------------------------------------------------
TFamilyTypes::primary_key::primary_key() : iID {} { }

TFamilyTypes::primary_key::primary_key(int pID) : iID(pID) { }

TFamilyTypes::primary_key::primary_key(TFamilyTypes const& other) : iID(other._ID()) { }

TFamilyTypes::primary_key::primary_key(TFamilyTypes::primary_key const& other) : iID(other.iID) { }

TFamilyTypes::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TFamilyTypes::primary_key::operator TFamilyTypes() const {
   TFamilyTypes ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TFamilyTypes::primary_key::write(std::ostream& out) const {
   out << "elements of class TFamilyTypes::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TFamilyTypes::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TFamilyTypes
// ---------------------------------------------------------------------------------------
TFamilyTypes::TFamilyTypes() {
   _init();
   }

TFamilyTypes::TFamilyTypes(TFamilyTypes const& other){
   _copy(other);
   }

TFamilyTypes::TFamilyTypes(TFamilyTypes&& other) noexcept {
   _swap(other);
   }

TFamilyTypes::TFamilyTypes(primary_key const& other) : iID(other.ID()) { }

TFamilyTypes::~TFamilyTypes() {   }

TFamilyTypes& TFamilyTypes::operator = (TFamilyTypes const& other) {
   copy(other);
   return *this;
   }

TFamilyTypes& TFamilyTypes::operator = (TFamilyTypes&& other) noexcept {
   swap(other);
   return *this;
   }

void TFamilyTypes::swap(TFamilyTypes& other) noexcept {
   _swap(other);
   }

void TFamilyTypes::init() {
   _init();
   }

void TFamilyTypes::copy(TSimplePersonBase const& other) {
   try {
      TFamilyTypes const& ref = dynamic_cast<TFamilyTypes const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TFamilyTypes& TFamilyTypes::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TFamilyTypes::_swap(TFamilyTypes& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(boIsNaturalPerson, other.boIsNaturalPerson);
   std::swap(strDescription, other.strDescription);
   std::swap(strNotes, other.strNotes);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TFamilyTypes::_init() {
   // initializing own data elements
   iID                = {};
   strDenotation      = {};
   strAbbreviation    = {};
   boIsNaturalPerson  = {};
   strDescription     = {};
   strNotes           = {};
   boUrgentValue      = {};
   return;
   }

// _copy: internal copy method for the class
void TFamilyTypes::_copy(TFamilyTypes const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   IsNaturalPerson(other.IsNaturalPerson());
   Description(other.Description());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myCorporate
