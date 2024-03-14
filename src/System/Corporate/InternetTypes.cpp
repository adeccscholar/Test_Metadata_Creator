/*
* Project: model with a simple person administration
* Implementation of the data class TInternetTypes
* Content: domain / range of values for internet connection types, this is an extension of the relationship between persons and internet connections.
* Date: 14.03.2024 23:56:53,685  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate/InternetTypes.h"

#include <typeinfo>

namespace myCorporate {

TInternetTypes::TInternetTypes() {
   _init();
   }

TInternetTypes::TInternetTypes(TInternetTypes const& other){
   _copy(other);
   }

TInternetTypes::TInternetTypes(TInternetTypes&& other) noexcept {
   _swap(other);
   }

TInternetTypes::~TInternetTypes() {   }

TInternetTypes& TInternetTypes::operator = (TInternetTypes const& other) {
   copy(other);
   return *this;
   }

TInternetTypes& TInternetTypes::operator = (TInternetTypes&& other) noexcept {
   swap(other);
   return *this;
   }

void TInternetTypes::swap(TInternetTypes& other) noexcept {
   _swap(other);
   }

void TInternetTypes::init() {
   _init();
   }

void TInternetTypes::copy(TSimplePersonBase const& other) {
   try {
      TInternetTypes const& ref = dynamic_cast<TInternetTypes const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TInternetTypes& TInternetTypes::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TInternetTypes::_swap(TInternetTypes& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(strPrefix, other.strPrefix);
   std::swap(strNotes, other.strNotes);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TInternetTypes::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   strPrefix        = {};
   strNotes         = {};
   boUrgentValue    = {};
   return;
   }

// _copy: internal copy method for the class
void TInternetTypes::_copy(TInternetTypes const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Prefix(other.Prefix());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myCorporate
