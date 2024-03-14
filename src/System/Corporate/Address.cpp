/*
* Project: model with a simple person administration
* Implementation of the data class TAddress
* Content: information on the addresses where a person lives, works or has any other relationship with them.
* Date: 14.03.2024 23:56:52,917  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate/Address.h"

#include <typeinfo>

namespace myCorporate {

TAddress::TAddress() {
   _init();
   }

TAddress::TAddress(TAddress const& other){
   _copy(other);
   }

TAddress::TAddress(TAddress&& other) noexcept {
   _swap(other);
   }

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
