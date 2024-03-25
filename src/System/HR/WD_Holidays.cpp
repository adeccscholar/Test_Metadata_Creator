/*
* Project: model with a simple person administration
* Implementation of the data class TWD_Holidays
* Content: entities with public holidays, in relation to working days table to determine non working days
* Date: 25.03.2024 19:08:41,072  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\WD_Holidays.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TWD_Holidays
// ---------------------------------------------------------------------------------------
TWD_Holidays::primary_key::primary_key() : daCalendarDay {} { }

TWD_Holidays::primary_key::primary_key(std::chrono::year_month_day pCalendarDay) : daCalendarDay(pCalendarDay) { }

TWD_Holidays::primary_key::primary_key(TWD_Holidays const& other) : daCalendarDay(other._CalendarDay()) { }

TWD_Holidays::primary_key::primary_key(TWD_Holidays::primary_key const& other) : daCalendarDay(other.daCalendarDay) { }

TWD_Holidays::primary_key::primary_key(primary_key&& other) noexcept : daCalendarDay(std::move(other.daCalendarDay)) { }

// conversions operator for this element to the encircling class
TWD_Holidays::primary_key::operator TWD_Holidays() const {
   TWD_Holidays ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TWD_Holidays::primary_key::write(std::ostream& out) const {
   out << "elements of class TWD_Holidays::primary_key:\n";
   out << std::left << std::setw(15) << " - CalendarDay" << ":" << daCalendarDay << '\n';
   return out;
   }

int TWD_Holidays::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->daCalendarDay, other.daCalendarDay); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TWD_Holidays
// ---------------------------------------------------------------------------------------
TWD_Holidays::TWD_Holidays() {
   _init();
   }

TWD_Holidays::TWD_Holidays(TWD_Holidays const& other){
   _copy(other);
   }

TWD_Holidays::TWD_Holidays(TWD_Holidays&& other) noexcept {
   _swap(other);
   }

TWD_Holidays::TWD_Holidays(primary_key const& other) : daCalendarDay(other.CalendarDay()) { }

TWD_Holidays::~TWD_Holidays() {   }

TWD_Holidays& TWD_Holidays::operator = (TWD_Holidays const& other) {
   copy(other);
   return *this;
   }

TWD_Holidays& TWD_Holidays::operator = (TWD_Holidays&& other) noexcept {
   swap(other);
   return *this;
   }

void TWD_Holidays::swap(TWD_Holidays& other) noexcept {
   _swap(other);
   }

void TWD_Holidays::init() {
   _init();
   }

void TWD_Holidays::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TWD_Holidays const& ref = dynamic_cast<TWD_Holidays const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TWD_Holidays& TWD_Holidays::init(primary_key const& key_values) {
   init();
   CalendarDay(key_values.CalendarDay());
   return *this;
   }

// _swap: internal swapping method for the class
void TWD_Holidays::_swap(TWD_Holidays& other) noexcept {
   // swapping own data elements
   std::swap(daCalendarDay, other.daCalendarDay);
   std::swap(strDonation, other.strDonation);
   std::swap(iShare, other.iShare);
   std::swap(strDescription, other.strDescription);
   return;
   }

// _init: internal initialization method for the instance of this class
void TWD_Holidays::_init() {
   // initializing own data elements
   daCalendarDay   = {};
   strDonation     = {};
   iShare          = {};
   strDescription  = {};
   return;
   }

// _copy: internal copy method for the class
void TWD_Holidays::_copy(TWD_Holidays const& other) {
   CalendarDay(other.CalendarDay());
   Donation(other.Donation());
   Share(other.Share());
   Description(other.Description());
   return;
   }

} // end of namespace myHR
