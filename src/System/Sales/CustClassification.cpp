/*
* Project: model with a simple person administration
* Implementation of the data class TCustClassification
* Content: domain / range with the classifications for customers
* Date: 22.04.2025 22:26:55,653  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Sales\CustClassification.h"

#include <typeinfo>

namespace mySales {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TCustClassification
// ---------------------------------------------------------------------------------------
TCustClassification::primary_key::primary_key() : iID {} { }

TCustClassification::primary_key::primary_key(int pID) : iID(pID) { }

TCustClassification::primary_key::primary_key(TCustClassification const& other) : iID(other._ID()) { }

TCustClassification::primary_key::primary_key(TCustClassification::primary_key const& other) : iID(other.iID) { }

TCustClassification::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TCustClassification::primary_key::operator TCustClassification() const {
   TCustClassification ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TCustClassification::primary_key::write(std::ostream& out) const {
   out << "elements of class TCustClassification::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TCustClassification::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TCustClassification
// ---------------------------------------------------------------------------------------
TCustClassification::TCustClassification() {
   _init();
   }

TCustClassification::TCustClassification(TCustClassification const& other){
   _copy(other);
   }

TCustClassification::TCustClassification(TCustClassification&& other) noexcept {
   _swap(other);
   }

TCustClassification::TCustClassification(primary_key const& other) : iID(other.ID()) { }

TCustClassification::~TCustClassification() {   }

TCustClassification& TCustClassification::operator = (TCustClassification const& other) {
   copy(other);
   return *this;
   }

TCustClassification& TCustClassification::operator = (TCustClassification&& other) noexcept {
   swap(other);
   return *this;
   }

void TCustClassification::swap(TCustClassification& other) noexcept {
   _swap(other);
   }

void TCustClassification::init() {
   _init();
   }

void TCustClassification::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TCustClassification const& ref = dynamic_cast<TCustClassification const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TCustClassification& TCustClassification::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TCustClassification::_swap(TCustClassification& other) noexcept {
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
void TCustClassification::_init() {
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
void TCustClassification::_copy(TCustClassification const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace mySales
