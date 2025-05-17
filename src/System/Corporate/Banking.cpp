/*
* Project: model with a simple person administration
* Implementation of the data class TBanking
* Content: informations about the account details provided by a person and used in a specific context
* Date: 22.04.2025 22:26:55,326  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\Banking.h"

#include <typeinfo>

namespace myCorporate {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TBanking
// ---------------------------------------------------------------------------------------
TBanking::primary_key::primary_key() : iID {}, iBankingType {} { }

TBanking::primary_key::primary_key(int pID, int pBankingType) : iID(pID), iBankingType(pBankingType) { }

TBanking::primary_key::primary_key(TBanking const& other) : iID(other._ID()), iBankingType(other._BankingType()) { }

TBanking::primary_key::primary_key(TBanking::primary_key const& other) : iID(other.iID), iBankingType(other.iBankingType) { }

TBanking::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)), iBankingType(std::move(other.iBankingType)) { }

// conversions operator for this element to the encircling class
TBanking::primary_key::operator TBanking() const {
   TBanking ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TBanking::primary_key::write(std::ostream& out) const {
   out << "elements of class TBanking::primary_key:\n";
   out << std::left << std::setw(15) << " - ID" << ":" << iID << '\n';
   out << std::left << std::setw(15) << " - BankingType" << ":" << iBankingType << '\n';
   return out;
   }

int TBanking::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   if(auto ret = comp_help(this->iBankingType, other.iBankingType); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TBanking
// ---------------------------------------------------------------------------------------
TBanking::TBanking() {
   _init();
   }

TBanking::TBanking(TBanking const& other){
   _copy(other);
   }

TBanking::TBanking(TBanking&& other) noexcept {
   _swap(other);
   }

TBanking::TBanking(primary_key const& other) : iID(other.ID()), iBankingType(other.BankingType()) { }

TBanking::~TBanking() {   }

TBanking& TBanking::operator = (TBanking const& other) {
   copy(other);
   return *this;
   }

TBanking& TBanking::operator = (TBanking&& other) noexcept {
   swap(other);
   return *this;
   }

void TBanking::swap(TBanking& other) noexcept {
   _swap(other);
   }

void TBanking::init() {
   _init();
   }

void TBanking::copy(TSimplePersonBase const& other) {
   try {
      TBanking const& ref = dynamic_cast<TBanking const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TBanking& TBanking::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   BankingType(key_values.BankingType());
   return *this;
   }

// _swap: internal swapping method for the class
void TBanking::_swap(TBanking& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(iBankingType, other.iBankingType);
   std::swap(strBankName, other.strBankName);
   std::swap(strIBAN, other.strIBAN);
   std::swap(strBIC, other.strBIC);
   std::swap(strBankOwner, other.strBankOwner);
   std::swap(iCountry, other.iCountry);
   return;
   }

// _init: internal initialization method for the instance of this class
void TBanking::_init() {
   // initializing own data elements
   iID           = {};
   iBankingType  = {};
   strBankName   = {};
   strIBAN       = {};
   strBIC        = {};
   strBankOwner  = {};
   iCountry      = {};
   return;
   }

// _copy: internal copy method for the class
void TBanking::_copy(TBanking const& other) {
   ID(other.ID());
   BankingType(other.BankingType());
   BankName(other.BankName());
   IBAN(other.IBAN());
   BIC(other.BIC());
   BankOwner(other.BankOwner());
   Country(other.Country());
   return;
   }

} // end of namespace myCorporate
