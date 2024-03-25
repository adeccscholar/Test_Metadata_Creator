/*
* Project: model with a simple person administration
* Implementation of the data class TAddress
* Content: information on the addresses where a person lives, works or has any other relationship with them.
* Date: 25.03.2024 19:08:39,585  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\Address.h"

#include <typeinfo>

namespace myCorporate {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TAddress
// ---------------------------------------------------------------------------------------
TAddress::primary_key::primary_key() : iID {}, iAddressType {} { }

TAddress::primary_key::primary_key(int pID, int pAddressType) : iID(pID), iAddressType(pAddressType) { }

TAddress::primary_key::primary_key(TAddress const& other) : iID(other._ID()), iAddressType(other._AddressType()) { }

TAddress::primary_key::primary_key(TAddress::primary_key const& other) : iID(other.iID), iAddressType(other.iAddressType) { }

TAddress::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)), iAddressType(std::move(other.iAddressType)) { }

// conversions operator for this element to the encircling class
TAddress::primary_key::operator TAddress() const {
   TAddress ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TAddress::primary_key::write(std::ostream& out) const {
   out << "elements of class TAddress::primary_key:\n";
   out << std::left << std::setw(15) << " - ID" << ":" << iID << '\n';
   out << std::left << std::setw(15) << " - AddressType" << ":" << iAddressType << '\n';
   return out;
   }

int TAddress::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   if(auto ret = comp_help(this->iAddressType, other.iAddressType); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TAddress
// ---------------------------------------------------------------------------------------
TAddress::TAddress() {
   _init();
   }

TAddress::TAddress(TAddress const& other){
   _copy(other);
   }

TAddress::TAddress(TAddress&& other) noexcept {
   _swap(other);
   }

TAddress::TAddress(primary_key const& other) : iID(other.ID()), iAddressType(other.AddressType()) { }

TAddress::~TAddress() {   }

TAddress& TAddress::operator = (TAddress const& other) {
   copy(other);
   return *this;
   }

TAddress& TAddress::operator = (TAddress&& other) noexcept {
   swap(other);
   return *this;
   }

void TAddress::swap(TAddress& other) noexcept {
   _swap(other);
   }

void TAddress::init() {
   _init();
   }

void TAddress::copy(TSimplePersonBase const& other) {
   try {
      TAddress const& ref = dynamic_cast<TAddress const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TAddress& TAddress::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   AddressType(key_values.AddressType());
   return *this;
   }

// _swap: internal swapping method for the class
void TAddress::_swap(TAddress& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(iAddressType, other.iAddressType);
   std::swap(strZipcode, other.strZipcode);
   std::swap(strCity, other.strCity);
   std::swap(strStreet, other.strStreet);
   std::swap(strStreetNumber, other.strStreetNumber);
   std::swap(iCountry, other.iCountry);
   return;
   }

// _init: internal initialization method for the instance of this class
void TAddress::_init() {
   // initializing own data elements
   iID              = {};
   iAddressType     = {};
   strZipcode       = {};
   strCity          = {};
   strStreet        = {};
   strStreetNumber  = {};
   iCountry         = {};
   return;
   }

// _copy: internal copy method for the class
void TAddress::_copy(TAddress const& other) {
   ID(other.ID());
   AddressType(other.AddressType());
   Zipcode(other.Zipcode());
   City(other.City());
   Street(other.Street());
   StreetNumber(other.StreetNumber());
   Country(other.Country());
   return;
   }

} // end of namespace myCorporate
