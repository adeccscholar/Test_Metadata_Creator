/*
* Project: model with a simple person administration
* Implementation of the data class TJobPositions
* Content: domain or range of values for different positions for the employee. Important as anchor for additional informations
* Date: 22.03.2024 15:39:12,487  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\JobPositions.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TJobPositions
// ---------------------------------------------------------------------------------------
TJobPositions::primary_key::primary_key() : iID {} { }

TJobPositions::primary_key::primary_key(int pID) : iID(pID) { }

TJobPositions::primary_key::primary_key(TJobPositions const& other) : iID(other._ID()) { }

TJobPositions::primary_key::primary_key(TJobPositions::primary_key const& other) : iID(other.iID) { }

TJobPositions::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TJobPositions::primary_key::operator TJobPositions() const {
   TJobPositions ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TJobPositions::primary_key::write(std::ostream& out) const {
   out << "elements of class TJobPositions::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TJobPositions::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TJobPositions
// ---------------------------------------------------------------------------------------
TJobPositions::TJobPositions() {
   _init();
   }

TJobPositions::TJobPositions(TJobPositions const& other){
   _copy(other);
   }

TJobPositions::TJobPositions(TJobPositions&& other) noexcept {
   _swap(other);
   }

TJobPositions::TJobPositions(primary_key const& other) : iID(other.ID()) { }

TJobPositions::~TJobPositions() {   }

TJobPositions& TJobPositions::operator = (TJobPositions const& other) {
   copy(other);
   return *this;
   }

TJobPositions& TJobPositions::operator = (TJobPositions&& other) noexcept {
   swap(other);
   return *this;
   }

void TJobPositions::swap(TJobPositions& other) noexcept {
   _swap(other);
   }

void TJobPositions::init() {
   _init();
   }

void TJobPositions::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TJobPositions const& ref = dynamic_cast<TJobPositions const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TJobPositions& TJobPositions::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TJobPositions::_swap(TJobPositions& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(iSalaryType, other.iSalaryType);
   std::swap(strNotes, other.strNotes);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TJobPositions::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   iSalaryType      = {};
   strNotes         = {};
   boUrgentValue    = {};
   return;
   }

// _copy: internal copy method for the class
void TJobPositions::_copy(TJobPositions const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   SalaryType(other.SalaryType());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myHR
