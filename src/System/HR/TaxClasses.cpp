/*
* Project: model with a simple person administration
* Implementation of the data class TTaxClasses
* Content: tax class in germany to use it with employees (not a range, but very similar)
* Date: 14.03.2024 23:56:54,143  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR/TaxClasses.h"

#include <typeinfo>

namespace myHR {

TTaxClasses::TTaxClasses() {
   _init();
   }

TTaxClasses::TTaxClasses(TTaxClasses const& other){
   _copy(other);
   }

TTaxClasses::TTaxClasses(TTaxClasses&& other) noexcept {
   _swap(other);
   }

TTaxClasses::~TTaxClasses() {   }

TTaxClasses& TTaxClasses::operator = (TTaxClasses const& other) {
   copy(other);
   return *this;
   }

TTaxClasses& TTaxClasses::operator = (TTaxClasses&& other) noexcept {
   swap(other);
   return *this;
   }

void TTaxClasses::swap(TTaxClasses& other) noexcept {
   _swap(other);
   }

void TTaxClasses::init() {
   _init();
   }

void TTaxClasses::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TTaxClasses const& ref = dynamic_cast<TTaxClasses const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TTaxClasses& TTaxClasses::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TTaxClasses::_swap(TTaxClasses& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(boCoupled, other.boCoupled);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TTaxClasses::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   boCoupled        = {};
   boUrgentValue    = {};
   return;
   }

// _copy: internal copy method for the class
void TTaxClasses::_copy(TTaxClasses const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Coupled(other.Coupled());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myHR
