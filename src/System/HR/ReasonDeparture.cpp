/*
* Project: model with a simple person administration
* Implementation of the data class TReasonDeparture
* Content: doman range with the reason of departure of the employee
* Date: 14.03.2024 23:56:53,964  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR/ReasonDeparture.h"

#include <typeinfo>

namespace myHR {

TReasonDeparture::TReasonDeparture() {
   _init();
   }

TReasonDeparture::TReasonDeparture(TReasonDeparture const& other){
   _copy(other);
   }

TReasonDeparture::TReasonDeparture(TReasonDeparture&& other) noexcept {
   _swap(other);
   }

TReasonDeparture::~TReasonDeparture() {   }

TReasonDeparture& TReasonDeparture::operator = (TReasonDeparture const& other) {
   copy(other);
   return *this;
   }

TReasonDeparture& TReasonDeparture::operator = (TReasonDeparture&& other) noexcept {
   swap(other);
   return *this;
   }

void TReasonDeparture::swap(TReasonDeparture& other) noexcept {
   _swap(other);
   }

void TReasonDeparture::init() {
   _init();
   }

void TReasonDeparture::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TReasonDeparture const& ref = dynamic_cast<TReasonDeparture const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TReasonDeparture& TReasonDeparture::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TReasonDeparture::_swap(TReasonDeparture& other) noexcept {
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
void TReasonDeparture::_init() {
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
void TReasonDeparture::_copy(TReasonDeparture const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myHR
