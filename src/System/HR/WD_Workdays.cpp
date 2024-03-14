/*
* Project: model with a simple person administration
* Implementation of the data class TWD_Workdays
* Content: domain with all days, additional informations and as owner of all recorded working time and non-working times
* Date: 14.03.2024 23:56:54,362  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR/WD_Workdays.h"

#include <typeinfo>

namespace myHR {

TWD_Workdays::TWD_Workdays() {
   _init();
   }

TWD_Workdays::TWD_Workdays(TWD_Workdays const& other){
   _copy(other);
   }

TWD_Workdays::TWD_Workdays(TWD_Workdays&& other) noexcept {
   _swap(other);
   }

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
