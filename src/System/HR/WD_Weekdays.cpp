/*
* Project: model with a simple person administration
* Implementation of the data class TWD_Weekdays
* Content: domain for days of week, used for table working time. Possible to extent with informations. In area HR only
* Date: 14.03.2024 23:56:54,319  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR/WD_Weekdays.h"

#include <typeinfo>

namespace myHR {

TWD_Weekdays::TWD_Weekdays() {
   _init();
   }

TWD_Weekdays::TWD_Weekdays(TWD_Weekdays const& other){
   _copy(other);
   }

TWD_Weekdays::TWD_Weekdays(TWD_Weekdays&& other) noexcept {
   _swap(other);
   }

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
