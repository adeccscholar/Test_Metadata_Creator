/*
* Project: model with a simple person administration
* Implementation of the data class TPerson
* Content: informations about a person, base for different kinds of special persons in other areas of the company
* Date: 14.03.2024 23:56:53,789  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate/Person.h"

#include <typeinfo>

namespace myCorporate {

TPerson::TPerson() {
   _init();
   }

TPerson::TPerson(TPerson const& other){
   _copy(other);
   }

TPerson::TPerson(TPerson&& other) noexcept {
   _swap(other);
   }

TPerson::~TPerson() {   }

TPerson& TPerson::operator = (TPerson const& other) {
   copy(other);
   return *this;
   }

TPerson& TPerson::operator = (TPerson&& other) noexcept {
   swap(other);
   return *this;
   }

void TPerson::swap(TPerson& other) noexcept {
   _swap(other);
   }

void TPerson::init() {
   _init();
   }

void TPerson::copy(TSimplePersonBase const& other) {
   try {
      TPerson const& ref = dynamic_cast<TPerson const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TPerson& TPerson::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TPerson::_swap(TPerson& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strName, other.strName);
   std::swap(strFirstname, other.strFirstname);
   std::swap(iFormOfAddress, other.iFormOfAddress);
   std::swap(iFamilyStatus, other.iFamilyStatus);
   std::swap(daFamilyStatusSince, other.daFamilyStatusSince);
   std::swap(daBirthday, other.daBirthday);
   std::swap(strNotes, other.strNotes);
   std::swap(strFullName, other.strFullName);
   // swapping the composed classes
   std::swap(m_Address, other.m_Address);
   std::swap(m_Banking, other.m_Banking);
   std::swap(m_Internet, other.m_Internet);
   std::swap(m_Phone, other.m_Phone);
   return;
   }

// _init: internal initialization method for the instance of this class
void TPerson::_init() {
   // initializing own data elements
   iID                  = {};
   strName              = {};
   strFirstname         = {};
   iFormOfAddress       = {};
   iFamilyStatus        = {};
   daFamilyStatusSince  = {};
   daBirthday           = {};
   strNotes             = {};
   strFullName          = {};
   // initializing the composed classes
   m_Address            = { };
   m_Banking            = { };
   m_Internet           = { };
   m_Phone              = { };
   return;
   }

// _copy: internal copy method for the class
void TPerson::_copy(TPerson const& other) {
   ID(other.ID());
   Name(other.Name());
   Firstname(other.Firstname());
   FormOfAddress(other.FormOfAddress());
   FamilyStatus(other.FamilyStatus());
   FamilyStatusSince(other.FamilyStatusSince());
   Birthday(other.Birthday());
   Notes(other.Notes());
   FullName(other.FullName());
   // copying the composed classes
   m_Address   = m_Address;
   m_Banking   = m_Banking;
   m_Internet  = m_Internet;
   m_Phone     = m_Phone;
   return;
   }

} // end of namespace myCorporate
