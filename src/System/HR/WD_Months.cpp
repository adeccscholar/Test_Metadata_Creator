/*
* Project: model with a simple person administration
* Implementation of the data class TWD_Months
* Content: domain with months for human resources, actually used for working time, later for processes too. This range make it possible additional informations to adding later. This isn't a typical range value.
* Date: 14.03.2024 23:56:54,223  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR/WD_Months.h"

#include <typeinfo>

namespace myHR {

TWD_Months::TWD_Months() {
   _init();
   }

TWD_Months::TWD_Months(TWD_Months const& other){
   _copy(other);
   }

TWD_Months::TWD_Months(TWD_Months&& other) noexcept {
   _swap(other);
   }

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
