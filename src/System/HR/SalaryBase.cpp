/*
* Project: model with a simple person administration
* Implementation of the data class TSalaryBase
* Content: fix domain for the calculation, this value determine the base for the salary, used in table SalaryType
* Date: 22.04.2025 22:26:56,534  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\SalaryBase.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TSalaryBase
// ---------------------------------------------------------------------------------------
TSalaryBase::primary_key::primary_key() : iID {} { }

TSalaryBase::primary_key::primary_key(int pID) : iID(pID) { }

TSalaryBase::primary_key::primary_key(TSalaryBase const& other) : iID(other._ID()) { }

TSalaryBase::primary_key::primary_key(TSalaryBase::primary_key const& other) : iID(other.iID) { }

TSalaryBase::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TSalaryBase::primary_key::operator TSalaryBase() const {
   TSalaryBase ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TSalaryBase::primary_key::write(std::ostream& out) const {
   out << "elements of class TSalaryBase::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TSalaryBase::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TSalaryBase
// ---------------------------------------------------------------------------------------
TSalaryBase::TSalaryBase() {
   _init();
   }

TSalaryBase::TSalaryBase(TSalaryBase const& other){
   _copy(other);
   }

TSalaryBase::TSalaryBase(TSalaryBase&& other) noexcept {
   _swap(other);
   }

TSalaryBase::TSalaryBase(primary_key const& other) : iID(other.ID()) { }

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
