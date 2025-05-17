/*
* Project: model with a simple person administration
* Implementation of the data class TContacts
* Content: information to the data of a contact person at the customer  (inherited from Person)
* Date: 22.04.2025 22:26:55,465  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Sales\Contacts.h"

#include <typeinfo>

namespace mySales {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TContacts
// ---------------------------------------------------------------------------------------
TContacts::primary_key::primary_key() : iContactID {} { }

TContacts::primary_key::primary_key(int pContactID) : iContactID(pContactID) { }

TContacts::primary_key::primary_key(TContacts const& other) : iContactID(other._ContactID()) { }

TContacts::primary_key::primary_key(TContacts::primary_key const& other) : iContactID(other.iContactID) { }

TContacts::primary_key::primary_key(primary_key&& other) noexcept : iContactID(std::move(other.iContactID)) { }

// conversions operator for this element to the encircling class
TContacts::primary_key::operator TContacts() const {
   TContacts ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TContacts::primary_key::write(std::ostream& out) const {
   out << "elements of class TContacts::primary_key:\n";
   out << std::left << std::setw(13) << " - ContactID" << ":" << iContactID << '\n';
   return out;
   }

int TContacts::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iContactID, other.iContactID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TContacts
// ---------------------------------------------------------------------------------------
TContacts::TContacts() : myCorporate::TPerson() {
   _init();
   }

TContacts::TContacts(TContacts const& other) : myCorporate::TPerson(other){
   _copy(other);
   }

TContacts::TContacts(TContacts&& other) noexcept : myCorporate::TPerson(std::move(other)) {
   _swap(other);
   }

TContacts::TContacts(primary_key const& other) : iContactID(other.ContactID()) { }

TContacts::~TContacts() {   }

TContacts& TContacts::operator = (TContacts const& other) {
   copy(other);
   return *this;
   }

TContacts& TContacts::operator = (TContacts&& other) noexcept {
   swap(other);
   return *this;
   }

void TContacts::swap(TContacts& other) noexcept {
   myCorporate::TPerson::swap(static_cast<myCorporate::TPerson&>(other));
   _swap(other);
   }

void TContacts::init() {
   myCorporate::TPerson::init();
   _init();
   }

void TContacts::copy(myCorporate::TSimplePersonBase const& other) {
   myCorporate::TPerson::copy(other);
   try {
      TContacts const& ref = dynamic_cast<TContacts const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TContacts& TContacts::init(primary_key const& key_values) {
   init();
   ContactID(key_values.ContactID());
   return *this;
   }

// _swap: internal swapping method for the class
void TContacts::_swap(TContacts& other) noexcept {
   // swapping own data elements
   std::swap(iContactID, other.iContactID);
   std::swap(iCustID, other.iCustID);
   std::swap(iCustLiaison, other.iCustLiaison);
   return;
   }

// _init: internal initialization method for the instance of this class
void TContacts::_init() {
   // initializing own data elements
   iContactID    = {};
   iCustID       = {};
   iCustLiaison  = {};
   return;
   }

// _copy: internal copy method for the class
void TContacts::_copy(TContacts const& other) {
   ContactID(other.ContactID());
   CustID(other.CustID());
   CustLiaison(other.CustLiaison());
   return;
   }

} // end of namespace mySales
