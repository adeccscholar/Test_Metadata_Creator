/*
* Project: model with a simple person administration
* Implementation of the data class TCustLiaison
* Content: doman range with the liaisons to use a contact at a customer
* Date: 17.03.2024 20:08:19,947  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Sales\CustLiaison.h"

#include <typeinfo>

namespace mySales {

TCustLiaison::TCustLiaison() {
   _init();
   }

TCustLiaison::TCustLiaison(TCustLiaison const& other){
   _copy(other);
   }

TCustLiaison::TCustLiaison(TCustLiaison&& other) noexcept {
   _swap(other);
   }

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
