/*
* Project: model with a simple person administration
* Implementation of the data class TWD_Workdays
* Content: domain with all days, additional informations and as owner of all recorded working time and non-working times
* Date: 22.04.2025 22:26:56,896  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\WD_Workdays.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TWD_Workdays
// ---------------------------------------------------------------------------------------
TWD_Workdays::primary_key::primary_key() : daCalendarDay {} { }

TWD_Workdays::primary_key::primary_key(std::chrono::year_month_day pCalendarDay) : daCalendarDay(pCalendarDay) { }

TWD_Workdays::primary_key::primary_key(TWD_Workdays const& other) : daCalendarDay(other._CalendarDay()) { }

TWD_Workdays::primary_key::primary_key(TWD_Workdays::primary_key const& other) : daCalendarDay(other.daCalendarDay) { }

TWD_Workdays::primary_key::primary_key(primary_key&& other) noexcept : daCalendarDay(std::move(other.daCalendarDay)) { }

// conversions operator for this element to the encircling class
TWD_Workdays::primary_key::operator TWD_Workdays() const {
   TWD_Workdays ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TWD_Workdays::primary_key::write(std::ostream& out) const {
   out << "elements of class TWD_Workdays::primary_key:\n";
   out << std::left << std::setw(15) << " - CalendarDay" << ":" << daCalendarDay << '\n';
   return out;
   }

int TWD_Workdays::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->daCalendarDay, other.daCalendarDay); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TWD_Workdays
// ---------------------------------------------------------------------------------------
TWD_Workdays::TWD_Workdays() {
   _init();
   }

TWD_Workdays::TWD_Workdays(TWD_Workdays const& other){
   _copy(other);
   }

TWD_Workdays::TWD_Workdays(TWD_Workdays&& other) noexcept {
   _swap(other);
   }

TWD_Workdays::TWD_Workdays(primary_key const& other) : daCalendarDay(other.CalendarDay()) { }

TWD_Workdays::~TWD_Workdays() {   }

TWD_Workdays& TWD_Workdays::operator = (TWD_Workdays const& other) {
   copy(other);
   return *this;
   }

TWD_Workdays& TWD_Workdays::operator = (TWD_Workdays&& other) noexcept {
   swap(other);
   return *this;
   }

void TWD_Workdays::swap(TWD_Workdays& other) noexcept {
   _swap(other);
   }

void TWD_Workdays::init() {
   _init();
   }

void TWD_Workdays::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TWD_Workdays const& ref = dynamic_cast<TWD_Workdays const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TWD_Workdays& TWD_Workdays::init(primary_key const& key_values) {
   init();
   CalendarDay(key_values.CalendarDay());
   return *this;
   }

// _swap: internal swapping method for the class
void TWD_Workdays::_swap(TWD_Workdays& other) noexcept {
   // swapping own data elements
   std::swap(daCalendarDay, other.daCalendarDay);
   std::swap(iCalendarWeekday, other.iCalendarWeekday);
   std::swap(iCalendarWeek, other.iCalendarWeek);
   std::swap(iCalendarYear, other.iCalendarYear);
   std::swap(iCalendarMonth, other.iCalendarMonth);
   std::swap(iCalendarDayInWeek, other.iCalendarDayInWeek);
   std::swap(iCalendarDayInYear, other.iCalendarDayInYear);
   std::swap(iCalendarQuarter, other.iCalendarQuarter);
   std::swap(boWorkday, other.boWorkday);
   return;
   }

// _init: internal initialization method for the instance of this class
void TWD_Workdays::_init() {
   // initializing own data elements
   daCalendarDay       = {};
   iCalendarWeekday    = {};
   iCalendarWeek       = {};
   iCalendarYear       = {};
   iCalendarMonth      = {};
   iCalendarDayInWeek  = {};
   iCalendarDayInYear  = {};
   iCalendarQuarter    = {};
   boWorkday           = {};
   return;
   }

// _copy: internal copy method for the class
void TWD_Workdays::_copy(TWD_Workdays const& other) {
   CalendarDay(other.CalendarDay());
   CalendarWeekday(other.CalendarWeekday());
   CalendarWeek(other.CalendarWeek());
   CalendarYear(other.CalendarYear());
   CalendarMonth(other.CalendarMonth());
   CalendarDayInWeek(other.CalendarDayInWeek());
   CalendarDayInYear(other.CalendarDayInYear());
   CalendarQuarter(other.CalendarQuarter());
   Workday(other.Workday());
   return;
   }

} // end of namespace myHR
