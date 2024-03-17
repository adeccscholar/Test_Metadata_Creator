/*
* Project: model with a simple person administration
* Implementation of the data class TDepartments
* Content: independent entity with the departments in the company, independent identity
* Date: 17.03.2024 20:08:20,052  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\Departments.h"

#include <typeinfo>

namespace myHR {

TDepartments::TDepartments() {
   _init();
   }

TDepartments::TDepartments(TDepartments const& other){
   _copy(other);
   }

TDepartments::TDepartments(TDepartments&& other) noexcept {
   _swap(other);
   }

TDepartments::~TDepartments() {   }

TDepartments& TDepartments::operator = (TDepartments const& other) {
   copy(other);
   return *this;
   }

TDepartments& TDepartments::operator = (TDepartments&& other) noexcept {
   swap(other);
   return *this;
   }

void TDepartments::swap(TDepartments& other) noexcept {
   _swap(other);
   }

void TDepartments::init() {
   _init();
   }

void TDepartments::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TDepartments const& ref = dynamic_cast<TDepartments const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TDepartments& TDepartments::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TDepartments::_swap(TDepartments& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(iOfficer, other.iOfficer);
   std::swap(strNotes, other.strNotes);
   return;
   }

// _init: internal initialization method for the instance of this class
void TDepartments::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   iOfficer         = {};
   strNotes         = {};
   return;
   }

// _copy: internal copy method for the class
void TDepartments::_copy(TDepartments const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Officer(other.Officer());
   Notes(other.Notes());
   return;
   }

} // end of namespace myHR
