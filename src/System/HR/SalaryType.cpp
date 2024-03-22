/*
* Project: model with a simple person administration
* Implementation of the data class TSalaryType
* Content: kind of salary as range value and base for calculations (flix, bonus, hourly, dayly, monthly, ...)
* Date: 22.03.2024 15:39:12,863  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System/HR\SalaryType.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TSalaryType
// ---------------------------------------------------------------------------------------
TSalaryType::primary_key::primary_key() : iID {} { }

TSalaryType::primary_key::primary_key(int pID) : iID(pID) { }

TSalaryType::primary_key::primary_key(TSalaryType const& other) : iID(other._ID()) { }

TSalaryType::primary_key::primary_key(TSalaryType::primary_key const& other) : iID(other.iID) { }

TSalaryType::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TSalaryType::primary_key::operator TSalaryType() const {
   TSalaryType ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TSalaryType::primary_key::write(std::ostream& out) const {
   out << "elements of class TSalaryType::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TSalaryType::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TSalaryType
// ---------------------------------------------------------------------------------------
TSalaryType::TSalaryType() {
   _init();
   }

TSalaryType::TSalaryType(TSalaryType const& other){
   _copy(other);
   }

TSalaryType::TSalaryType(TSalaryType&& other) noexcept {
   _swap(other);
   }

TSalaryType::TSalaryType(primary_key const& other) : iID(other.ID()) { }

TSalaryType::~TSalaryType() {   }

TSalaryType& TSalaryType::operator = (TSalaryType const& other) {
   copy(other);
   return *this;
   }

TSalaryType& TSalaryType::operator = (TSalaryType&& other) noexcept {
   swap(other);
   return *this;
   }

void TSalaryType::swap(TSalaryType& other) noexcept {
   _swap(other);
   }

void TSalaryType::init() {
   _init();
   }

void TSalaryType::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TSalaryType const& ref = dynamic_cast<TSalaryType const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TSalaryType& TSalaryType::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TSalaryType::_swap(TSalaryType& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(iSalaryBase, other.iSalaryBase);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TSalaryType::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   iSalaryBase      = {};
   boUrgentValue    = {};
   return;
   }

// _copy: internal copy method for the class
void TSalaryType::_copy(TSalaryType const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   SalaryBase(other.SalaryBase());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myHR
