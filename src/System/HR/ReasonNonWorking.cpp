/*
* Project: model with a simple person administration
* Implementation of the data class TReasonNonWorking
* Content: domain / range with the reasons of non working time / idle time
* Date: 17.03.2024 20:08:25,214  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\ReasonNonWorking.h"

#include <typeinfo>

namespace myHR {

TReasonNonWorking::TReasonNonWorking() {
   _init();
   }

TReasonNonWorking::TReasonNonWorking(TReasonNonWorking const& other){
   _copy(other);
   }

TReasonNonWorking::TReasonNonWorking(TReasonNonWorking&& other) noexcept {
   _swap(other);
   }

TReasonNonWorking::~TReasonNonWorking() {   }

TReasonNonWorking& TReasonNonWorking::operator = (TReasonNonWorking const& other) {
   copy(other);
   return *this;
   }

TReasonNonWorking& TReasonNonWorking::operator = (TReasonNonWorking&& other) noexcept {
   swap(other);
   return *this;
   }

void TReasonNonWorking::swap(TReasonNonWorking& other) noexcept {
   _swap(other);
   }

void TReasonNonWorking::init() {
   _init();
   }

void TReasonNonWorking::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TReasonNonWorking const& ref = dynamic_cast<TReasonNonWorking const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TReasonNonWorking& TReasonNonWorking::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TReasonNonWorking::_swap(TReasonNonWorking& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(strNotes, other.strNotes);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TReasonNonWorking::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   strNotes         = {};
   boUrgentValue    = {};
   return;
   }

// _copy: internal copy method for the class
void TReasonNonWorking::_copy(TReasonNonWorking const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myHR
