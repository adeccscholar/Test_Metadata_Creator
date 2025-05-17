/*
* Project: model with a simple person administration
* Implementation of the data class TInternet
* Content: connections for different kinds of communications about the internet as part of persons (part of relationship)
* Date: 22.04.2025 22:26:56,099  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\Internet.h"

#include <typeinfo>

namespace myCorporate {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TInternet
// ---------------------------------------------------------------------------------------
TInternet::primary_key::primary_key() : iID {}, iInternetType {} { }

TInternet::primary_key::primary_key(int pID, int pInternetType) : iID(pID), iInternetType(pInternetType) { }

TInternet::primary_key::primary_key(TInternet const& other) : iID(other._ID()), iInternetType(other._InternetType()) { }

TInternet::primary_key::primary_key(TInternet::primary_key const& other) : iID(other.iID), iInternetType(other.iInternetType) { }

TInternet::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)), iInternetType(std::move(other.iInternetType)) { }

// conversions operator for this element to the encircling class
TInternet::primary_key::operator TInternet() const {
   TInternet ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TInternet::primary_key::write(std::ostream& out) const {
   out << "elements of class TInternet::primary_key:\n";
   out << std::left << std::setw(16) << " - ID" << ":" << iID << '\n';
   out << std::left << std::setw(16) << " - InternetType" << ":" << iInternetType << '\n';
   return out;
   }

int TInternet::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   if(auto ret = comp_help(this->iInternetType, other.iInternetType); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TInternet
// ---------------------------------------------------------------------------------------
TInternet::TInternet() {
   _init();
   }

TInternet::TInternet(TInternet const& other){
   _copy(other);
   }

TInternet::TInternet(TInternet&& other) noexcept {
   _swap(other);
   }

TInternet::TInternet(primary_key const& other) : iID(other.ID()), iInternetType(other.InternetType()) { }

TInternet::~TInternet() {   }

TInternet& TInternet::operator = (TInternet const& other) {
   copy(other);
   return *this;
   }

TInternet& TInternet::operator = (TInternet&& other) noexcept {
   swap(other);
   return *this;
   }

void TInternet::swap(TInternet& other) noexcept {
   _swap(other);
   }

void TInternet::init() {
   _init();
   }

void TInternet::copy(TSimplePersonBase const& other) {
   try {
      TInternet const& ref = dynamic_cast<TInternet const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TInternet& TInternet::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   InternetType(key_values.InternetType());
   return *this;
   }

// _swap: internal swapping method for the class
void TInternet::_swap(TInternet& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(iInternetType, other.iInternetType);
   std::swap(strAdresse, other.strAdresse);
   return;
   }

// _init: internal initialization method for the instance of this class
void TInternet::_init() {
   // initializing own data elements
   iID            = {};
   iInternetType  = {};
   strAdresse     = {};
   return;
   }

// _copy: internal copy method for the class
void TInternet::_copy(TInternet const& other) {
   ID(other.ID());
   InternetType(other.InternetType());
   Adresse(other.Adresse());
   return;
   }

} // end of namespace myCorporate
