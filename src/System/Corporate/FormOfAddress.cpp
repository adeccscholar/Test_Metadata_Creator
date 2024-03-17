/*
* Project: model with a simple person administration
* Implementation of the data class TFormOfAddress
* Content: domain with the possible values for form of addresses with additional informations for this
* Date: 17.03.2024 20:08:20,284  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\FormOfAddress.h"

#include <typeinfo>

namespace myCorporate {

TFormOfAddress::TFormOfAddress() {
   _init();
   }

TFormOfAddress::TFormOfAddress(TFormOfAddress const& other){
   _copy(other);
   }

TFormOfAddress::TFormOfAddress(TFormOfAddress&& other) noexcept {
   _swap(other);
   }

TFormOfAddress::~TFormOfAddress() {   }

TFormOfAddress& TFormOfAddress::operator = (TFormOfAddress const& other) {
   copy(other);
   return *this;
   }

TFormOfAddress& TFormOfAddress::operator = (TFormOfAddress&& other) noexcept {
   swap(other);
   return *this;
   }

void TFormOfAddress::swap(TFormOfAddress& other) noexcept {
   _swap(other);
   }

void TFormOfAddress::init() {
   _init();
   }

void TFormOfAddress::copy(TSimplePersonBase const& other) {
   try {
      TFormOfAddress const& ref = dynamic_cast<TFormOfAddress const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TFormOfAddress& TFormOfAddress::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TFormOfAddress::_swap(TFormOfAddress& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(iTypeSpec, other.iTypeSpec);
   std::swap(strSalutation, other.strSalutation);
   std::swap(strValediction, other.strValediction);
   std::swap(strNotes, other.strNotes);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TFormOfAddress::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   iTypeSpec        = {};
   strSalutation    = {};
   strValediction   = {};
   strNotes         = {};
   boUrgentValue    = {};
   return;
   }

// _copy: internal copy method for the class
void TFormOfAddress::_copy(TFormOfAddress const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   TypeSpec(other.TypeSpec());
   Salutation(other.Salutation());
   Valediction(other.Valediction());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myCorporate
