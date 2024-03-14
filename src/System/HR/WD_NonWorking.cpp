/*
* Project: model with a simple person administration
* Implementation of the data class TWD_NonWorking
* Content: entity set with non working days. Extensions possible, responsible for this table is HR.
* Date: 14.03.2024 23:56:54,272  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR/WD_NonWorking.h"

#include <typeinfo>

namespace myHR {

TWD_NonWorking::TWD_NonWorking() {
   _init();
   }

TWD_NonWorking::TWD_NonWorking(TWD_NonWorking const& other){
   _copy(other);
   }

TWD_NonWorking::TWD_NonWorking(TWD_NonWorking&& other) noexcept {
   _swap(other);
   }

TWD_NonWorking::~TWD_NonWorking() {   }

TWD_NonWorking& TWD_NonWorking::operator = (TWD_NonWorking const& other) {
   copy(other);
   return *this;
   }

TWD_NonWorking& TWD_NonWorking::operator = (TWD_NonWorking&& other) noexcept {
   swap(other);
   return *this;
   }

void TWD_NonWorking::swap(TWD_NonWorking& other) noexcept {
   _swap(other);
   }

void TWD_NonWorking::init() {
   _init();
   }

void TWD_NonWorking::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TWD_NonWorking const& ref = dynamic_cast<TWD_NonWorking const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TWD_NonWorking& TWD_NonWorking::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   StartAt(key_values.StartAt());
   return *this;
   }

// _swap: internal swapping method for the class
void TWD_NonWorking::_swap(TWD_NonWorking& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(daStartAt, other.daStartAt);
   std::swap(daClosingAt, other.daClosingAt);
   std::swap(iReason, other.iReason);
   std::swap(strNotes, other.strNotes);
   return;
   }

// _init: internal initialization method for the instance of this class
void TWD_NonWorking::_init() {
   // initializing own data elements
   iID          = {};
   daStartAt    = {};
   daClosingAt  = {};
   iReason      = {};
   strNotes     = {};
   return;
   }

// _copy: internal copy method for the class
void TWD_NonWorking::_copy(TWD_NonWorking const& other) {
   ID(other.ID());
   StartAt(other.StartAt());
   ClosingAt(other.ClosingAt());
   Reason(other.Reason());
   Notes(other.Notes());
   return;
   }

} // end of namespace myHR
