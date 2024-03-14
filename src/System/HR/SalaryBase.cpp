/*
* Project: model with a simple person administration
* Implementation of the data class TSalaryBase
* Content: fix domain for the calculation, this value determine the base for the salary, used in table SalaryType
* Date: 14.03.2024 23:56:54,057  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR/SalaryBase.h"

#include <typeinfo>

namespace myHR {

TSalaryBase::TSalaryBase() {
   _init();
   }

TSalaryBase::TSalaryBase(TSalaryBase const& other){
   _copy(other);
   }

TSalaryBase::TSalaryBase(TSalaryBase&& other) noexcept {
   _swap(other);
   }

TSalaryBase::~TSalaryBase() {   }

TSalaryBase& TSalaryBase::operator = (TSalaryBase const& other) {
   copy(other);
   return *this;
   }

TSalaryBase& TSalaryBase::operator = (TSalaryBase&& other) noexcept {
   swap(other);
   return *this;
   }

void TSalaryBase::swap(TSalaryBase& other) noexcept {
   _swap(other);
   }

void TSalaryBase::init() {
   _init();
   }

void TSalaryBase::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TSalaryBase const& ref = dynamic_cast<TSalaryBase const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TSalaryBase& TSalaryBase::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TSalaryBase::_swap(TSalaryBase& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TSalaryBase::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   boUrgentValue    = {};
   return;
   }

// _copy: internal copy method for the class
void TSalaryBase::_copy(TSalaryBase const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myHR
