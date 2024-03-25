/*
* Project: model with a simple person administration
* Implementation of the data class TCustLiaison
* Content: doman range with the liaisons to use a contact at a customer
* Date: 25.03.2024 19:08:40,090  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Sales\CustLiaison.h"

#include <typeinfo>

namespace mySales {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TCustLiaison
// ---------------------------------------------------------------------------------------
TCustLiaison::primary_key::primary_key() : iID {} { }

TCustLiaison::primary_key::primary_key(int pID) : iID(pID) { }

TCustLiaison::primary_key::primary_key(TCustLiaison const& other) : iID(other._ID()) { }

TCustLiaison::primary_key::primary_key(TCustLiaison::primary_key const& other) : iID(other.iID) { }

TCustLiaison::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TCustLiaison::primary_key::operator TCustLiaison() const {
   TCustLiaison ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TCustLiaison::primary_key::write(std::ostream& out) const {
   out << "elements of class TCustLiaison::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TCustLiaison::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TCustLiaison
// ---------------------------------------------------------------------------------------
TCustLiaison::TCustLiaison() {
   _init();
   }

TCustLiaison::TCustLiaison(TCustLiaison const& other){
   _copy(other);
   }

TCustLiaison::TCustLiaison(TCustLiaison&& other) noexcept {
   _swap(other);
   }

TCustLiaison::TCustLiaison(primary_key const& other) : iID(other.ID()) { }

TCustLiaison::~TCustLiaison() {   }

TCustLiaison& TCustLiaison::operator = (TCustLiaison const& other) {
   copy(other);
   return *this;
   }

TCustLiaison& TCustLiaison::operator = (TCustLiaison&& other) noexcept {
   swap(other);
   return *this;
   }

void TCustLiaison::swap(TCustLiaison& other) noexcept {
   _swap(other);
   }

void TCustLiaison::init() {
   _init();
   }

void TCustLiaison::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TCustLiaison const& ref = dynamic_cast<TCustLiaison const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TCustLiaison& TCustLiaison::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TCustLiaison::_swap(TCustLiaison& other) noexcept {
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
void TCustLiaison::_init() {
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
void TCustLiaison::_copy(TCustLiaison const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace mySales
