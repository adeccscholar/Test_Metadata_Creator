/*
* Project: model with a simple person administration
* Implementation of the data class TWD_Months
* Content: domain with months for human resources, actually used for working time, later for processes too. This range make it possible additional informations to adding later. This isn't a typical range value.
* Date: 25.03.2024 19:08:41,118  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\WD_Months.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TWD_Months
// ---------------------------------------------------------------------------------------
TWD_Months::primary_key::primary_key() : iID {} { }

TWD_Months::primary_key::primary_key(int pID) : iID(pID) { }

TWD_Months::primary_key::primary_key(TWD_Months const& other) : iID(other._ID()) { }

TWD_Months::primary_key::primary_key(TWD_Months::primary_key const& other) : iID(other.iID) { }

TWD_Months::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TWD_Months::primary_key::operator TWD_Months() const {
   TWD_Months ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TWD_Months::primary_key::write(std::ostream& out) const {
   out << "elements of class TWD_Months::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TWD_Months::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TWD_Months
// ---------------------------------------------------------------------------------------
TWD_Months::TWD_Months() {
   _init();
   }

TWD_Months::TWD_Months(TWD_Months const& other){
   _copy(other);
   }

TWD_Months::TWD_Months(TWD_Months&& other) noexcept {
   _swap(other);
   }

TWD_Months::TWD_Months(primary_key const& other) : iID(other.ID()) { }

TWD_Months::~TWD_Months() {   }

TWD_Months& TWD_Months::operator = (TWD_Months const& other) {
   copy(other);
   return *this;
   }

TWD_Months& TWD_Months::operator = (TWD_Months&& other) noexcept {
   swap(other);
   return *this;
   }

void TWD_Months::swap(TWD_Months& other) noexcept {
   _swap(other);
   }

void TWD_Months::init() {
   _init();
   }

void TWD_Months::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TWD_Months const& ref = dynamic_cast<TWD_Months const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TWD_Months& TWD_Months::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TWD_Months::_swap(TWD_Months& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(uQuarter, other.uQuarter);
   return;
   }

// _init: internal initialization method for the instance of this class
void TWD_Months::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   uQuarter         = {};
   return;
   }

// _copy: internal copy method for the class
void TWD_Months::_copy(TWD_Months const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Quarter(other.Quarter());
   return;
   }

} // end of namespace myHR
