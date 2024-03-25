/*
* Project: model with a simple person administration
* Implementation of the data class TWD_Weekdays
* Content: domain for days of week, used for table working time. Possible to extent with informations. In area HR only
* Date: 25.03.2024 19:08:41,211  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\WD_Weekdays.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TWD_Weekdays
// ---------------------------------------------------------------------------------------
TWD_Weekdays::primary_key::primary_key() : iID {} { }

TWD_Weekdays::primary_key::primary_key(int pID) : iID(pID) { }

TWD_Weekdays::primary_key::primary_key(TWD_Weekdays const& other) : iID(other._ID()) { }

TWD_Weekdays::primary_key::primary_key(TWD_Weekdays::primary_key const& other) : iID(other.iID) { }

TWD_Weekdays::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TWD_Weekdays::primary_key::operator TWD_Weekdays() const {
   TWD_Weekdays ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TWD_Weekdays::primary_key::write(std::ostream& out) const {
   out << "elements of class TWD_Weekdays::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TWD_Weekdays::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TWD_Weekdays
// ---------------------------------------------------------------------------------------
TWD_Weekdays::TWD_Weekdays() {
   _init();
   }

TWD_Weekdays::TWD_Weekdays(TWD_Weekdays const& other){
   _copy(other);
   }

TWD_Weekdays::TWD_Weekdays(TWD_Weekdays&& other) noexcept {
   _swap(other);
   }

TWD_Weekdays::TWD_Weekdays(primary_key const& other) : iID(other.ID()) { }

TWD_Weekdays::~TWD_Weekdays() {   }

TWD_Weekdays& TWD_Weekdays::operator = (TWD_Weekdays const& other) {
   copy(other);
   return *this;
   }

TWD_Weekdays& TWD_Weekdays::operator = (TWD_Weekdays&& other) noexcept {
   swap(other);
   return *this;
   }

void TWD_Weekdays::swap(TWD_Weekdays& other) noexcept {
   _swap(other);
   }

void TWD_Weekdays::init() {
   _init();
   }

void TWD_Weekdays::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TWD_Weekdays const& ref = dynamic_cast<TWD_Weekdays const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TWD_Weekdays& TWD_Weekdays::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TWD_Weekdays::_swap(TWD_Weekdays& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(boWorkday, other.boWorkday);
   return;
   }

// _init: internal initialization method for the instance of this class
void TWD_Weekdays::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   boWorkday        = {};
   return;
   }

// _copy: internal copy method for the class
void TWD_Weekdays::_copy(TWD_Weekdays const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Workday(other.Workday());
   return;
   }

} // end of namespace myHR
