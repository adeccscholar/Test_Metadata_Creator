/*
* Project: model with a simple person administration
* Implementation of the data class TCustomers
* Content: information to the data of a client / customer  (inherited from Person)
* Date: 22.03.2024 15:39:12,025  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Sales\Customers.h"

#include <typeinfo>

namespace mySales {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TCustomers
// ---------------------------------------------------------------------------------------
TCustomers::primary_key::primary_key() : iCustID {} { }

TCustomers::primary_key::primary_key(int pCustID) : iCustID(pCustID) { }

TCustomers::primary_key::primary_key(TCustomers const& other) : iCustID(other._CustID()) { }

TCustomers::primary_key::primary_key(TCustomers::primary_key const& other) : iCustID(other.iCustID) { }

TCustomers::primary_key::primary_key(primary_key&& other) noexcept : iCustID(std::move(other.iCustID)) { }

// conversions operator for this element to the encircling class
TCustomers::primary_key::operator TCustomers() const {
   TCustomers ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TCustomers::primary_key::write(std::ostream& out) const {
   out << "elements of class TCustomers::primary_key:\n";
   out << std::left << std::setw(10) << " - CustID" << ":" << iCustID << '\n';
   return out;
   }

int TCustomers::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iCustID, other.iCustID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TCustomers
// ---------------------------------------------------------------------------------------
TCustomers::TCustomers() : myCorporate::TPerson() {
   _init();
   }

TCustomers::TCustomers(TCustomers const& other) : myCorporate::TPerson(other){
   _copy(other);
   }

TCustomers::TCustomers(TCustomers&& other) noexcept : myCorporate::TPerson(std::move(other)) {
   _swap(other);
   }

TCustomers::TCustomers(primary_key const& other) : iCustID(other.CustID()) { }

TCustomers::~TCustomers() {   }

TCustomers& TCustomers::operator = (TCustomers const& other) {
   copy(other);
   return *this;
   }

TCustomers& TCustomers::operator = (TCustomers&& other) noexcept {
   swap(other);
   return *this;
   }

void TCustomers::swap(TCustomers& other) noexcept {
   myCorporate::TPerson::swap(static_cast<myCorporate::TPerson&>(other));
   _swap(other);
   }

void TCustomers::init() {
   myCorporate::TPerson::init();
   _init();
   }

void TCustomers::copy(myCorporate::TSimplePersonBase const& other) {
   myCorporate::TPerson::copy(other);
   try {
      TCustomers const& ref = dynamic_cast<TCustomers const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TCustomers& TCustomers::init(primary_key const& key_values) {
   init();
   CustID(key_values.CustID());
   return *this;
   }

// _swap: internal swapping method for the class
void TCustomers::_swap(TCustomers& other) noexcept {
   // swapping own data elements
   std::swap(iCustID, other.iCustID);
   std::swap(iServiceAgent, other.iServiceAgent);
   std::swap(iCustClassification, other.iCustClassification);
   std::swap(iLegalForm, other.iLegalForm);
   // swapping the composed classes
   std::swap(m_Contacts, other.m_Contacts);
   return;
   }

// _init: internal initialization method for the instance of this class
void TCustomers::_init() {
   // initializing own data elements
   iCustID              = {};
   iServiceAgent        = {};
   iCustClassification  = {};
   iLegalForm           = {};
   // initializing the composed classes
   m_Contacts           = { };
   return;
   }

// _copy: internal copy method for the class
void TCustomers::_copy(TCustomers const& other) {
   CustID(other.CustID());
   ServiceAgent(other.ServiceAgent());
   CustClassification(other.CustClassification());
   LegalForm(other.LegalForm());
   // copying the composed classes
   m_Contacts  = other.m_Contacts;
   return;
   }

} // end of namespace mySales
