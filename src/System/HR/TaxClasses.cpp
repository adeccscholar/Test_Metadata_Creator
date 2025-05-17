/*
* Project: model with a simple person administration
* Implementation of the data class TTaxClasses
* Content: tax class in germany to use it with employees (not a range, but very similar)
* Date: 22.04.2025 22:26:56,643  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\TaxClasses.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TTaxClasses
// ---------------------------------------------------------------------------------------
TTaxClasses::primary_key::primary_key() : iID {} { }

TTaxClasses::primary_key::primary_key(int pID) : iID(pID) { }

TTaxClasses::primary_key::primary_key(TTaxClasses const& other) : iID(other._ID()) { }

TTaxClasses::primary_key::primary_key(TTaxClasses::primary_key const& other) : iID(other.iID) { }

TTaxClasses::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TTaxClasses::primary_key::operator TTaxClasses() const {
   TTaxClasses ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TTaxClasses::primary_key::write(std::ostream& out) const {
   out << "elements of class TTaxClasses::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TTaxClasses::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TTaxClasses
// ---------------------------------------------------------------------------------------
TTaxClasses::TTaxClasses() {
   _init();
   }

TTaxClasses::TTaxClasses(TTaxClasses const& other){
   _copy(other);
   }

TTaxClasses::TTaxClasses(TTaxClasses&& other) noexcept {
   _swap(other);
   }

TTaxClasses::TTaxClasses(primary_key const& other) : iID(other.ID()) { }

TTaxClasses::~TTaxClasses() {   }

TTaxClasses& TTaxClasses::operator = (TTaxClasses const& other) {
   copy(other);
   return *this;
   }

TTaxClasses& TTaxClasses::operator = (TTaxClasses&& other) noexcept {
   swap(other);
   return *this;
   }

void TTaxClasses::swap(TTaxClasses& other) noexcept {
   _swap(other);
   }

void TTaxClasses::init() {
   _init();
   }

void TTaxClasses::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TTaxClasses const& ref = dynamic_cast<TTaxClasses const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TTaxClasses& TTaxClasses::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TTaxClasses::_swap(TTaxClasses& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(boCoupled, other.boCoupled);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TTaxClasses::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   boCoupled        = {};
   boUrgentValue    = {};
   return;
   }

// _copy: internal copy method for the class
void TTaxClasses::_copy(TTaxClasses const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Coupled(other.Coupled());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myHR
