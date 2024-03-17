/*
* Project: model with a simple person administration
* Implementation of the data class TContacts
* Content: information to the data of a contact person at the customer  (inherited from Person)
* Date: 17.03.2024 20:08:19,748  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Sales\Contacts.h"

#include <typeinfo>

namespace mySales {

TContacts::TContacts() : myCorporate::TPerson() {
   _init();
   }

TContacts::TContacts(TContacts const& other) : myCorporate::TPerson(other){
   _copy(other);
   }

TContacts::TContacts(TContacts&& other) noexcept : myCorporate::TPerson(std::move(other)) {
   _swap(other);
   }

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
