/*
* Project: model with a simple person administration
* Implementation of the data class TDepartments
* Content: independent entity with the departments in the company, independent identity
* Date: 25.03.2024 19:08:40,206  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\Departments.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TDepartments
// ---------------------------------------------------------------------------------------
TDepartments::primary_key::primary_key() : iID {} { }

TDepartments::primary_key::primary_key(int pID) : iID(pID) { }

TDepartments::primary_key::primary_key(TDepartments const& other) : iID(other._ID()) { }

TDepartments::primary_key::primary_key(TDepartments::primary_key const& other) : iID(other.iID) { }

TDepartments::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TDepartments::primary_key::operator TDepartments() const {
   TDepartments ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TDepartments::primary_key::write(std::ostream& out) const {
   out << "elements of class TDepartments::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TDepartments::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TDepartments
// ---------------------------------------------------------------------------------------
TDepartments::TDepartments() {
   _init();
   }

TDepartments::TDepartments(TDepartments const& other){
   _copy(other);
   }

TDepartments::TDepartments(TDepartments&& other) noexcept {
   _swap(other);
   }

TDepartments::TDepartments(primary_key const& other) : iID(other.ID()) { }

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
