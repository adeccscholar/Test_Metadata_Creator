/*
* Project: model with a simple person administration
* Implementation of the data class TPerson
* Content: informations about a person, base for different kinds of special persons in other areas of the company
* Date: 22.04.2025 22:26:56,257  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\Person.h"

#include <typeinfo>

#include "System\Sales\Contacts.h"
#include "System\Sales\Customers.h"
#include "System\HR\Employees.h"

namespace myCorporate {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TPerson
// ---------------------------------------------------------------------------------------
TPerson::primary_key::primary_key() : iID {} { }

TPerson::primary_key::primary_key(int pID) : iID(pID) { }

TPerson::primary_key::primary_key(TPerson const& other) : iID(other._ID()) { }

TPerson::primary_key::primary_key(TPerson::primary_key const& other) : iID(other.iID) { }

TPerson::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

TPerson::primary_key::primary_key(mySales::TContacts const& other) : iID(other._ContactID()) { }

TPerson::primary_key::primary_key(mySales::TCustomers const& other) : iID(other._CustID()) { }

TPerson::primary_key::primary_key(myHR::TEmployees const& other) : iID(other._EmployeeID()) { }

// conversions operator for this element to the encircling class
TPerson::primary_key::operator TPerson() const {
   TPerson ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TPerson::primary_key::write(std::ostream& out) const {
   out << "elements of class TPerson::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TPerson::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TPerson
// ---------------------------------------------------------------------------------------
TPerson::TPerson() {
   _init();
   }

TPerson::TPerson(TPerson const& other){
   _copy(other);
   }

TPerson::TPerson(TPerson&& other) noexcept {
   _swap(other);
   }

TPerson::TPerson(primary_key const& other) : iID(other.ID()) { }

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
   std::swap(strFirstName, other.strFirstName);
   std::swap(strBirthname, other.strBirthname);
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
   strFirstName         = {};
   strBirthname         = {};
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
   FirstName(other.FirstName());
   Birthname(other.Birthname());
   FormOfAddress(other.FormOfAddress());
   FamilyStatus(other.FamilyStatus());
   FamilyStatusSince(other.FamilyStatusSince());
   Birthday(other.Birthday());
   Notes(other.Notes());
   FullName(other.FullName());
   // copying the composed classes
   m_Address   = other.m_Address;
   m_Banking   = other.m_Banking;
   m_Internet  = other.m_Internet;
   m_Phone     = other.m_Phone;
   return;
   }

} // end of namespace myCorporate
