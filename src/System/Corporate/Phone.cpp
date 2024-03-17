/*
* Project: model with a simple person administration
* Implementation of the data class TPhone
* Content: phone connections of persons (part of relationship)
* Date: 17.03.2024 20:08:25,089  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\Phone.h"

#include <typeinfo>

namespace myCorporate {

TPhone::TPhone() {
   _init();
   }

TPhone::TPhone(TPhone const& other){
   _copy(other);
   }

TPhone::TPhone(TPhone&& other) noexcept {
   _swap(other);
   }

TPhone::~TPhone() {   }

TPhone& TPhone::operator = (TPhone const& other) {
   copy(other);
   return *this;
   }

TPhone& TPhone::operator = (TPhone&& other) noexcept {
   swap(other);
   return *this;
   }

void TPhone::swap(TPhone& other) noexcept {
   _swap(other);
   }

void TPhone::init() {
   _init();
   }

void TPhone::copy(TSimplePersonBase const& other) {
   try {
      TPhone const& ref = dynamic_cast<TPhone const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TPhone& TPhone::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   PhoneType(key_values.PhoneType());
   return *this;
   }

// _swap: internal swapping method for the class
void TPhone::_swap(TPhone& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(iPhoneType, other.iPhoneType);
   std::swap(strAreaCode, other.strAreaCode);
   std::swap(strCallNumber, other.strCallNumber);
   std::swap(iCountry, other.iCountry);
   std::swap(strDialingNational, other.strDialingNational);
   std::swap(strDialingInternational, other.strDialingInternational);
   return;
   }

// _init: internal initialization method for the instance of this class
void TPhone::_init() {
   // initializing own data elements
   iID                      = {};
   iPhoneType               = {};
   strAreaCode              = {};
   strCallNumber            = {};
   iCountry                 = {};
   strDialingNational       = {};
   strDialingInternational  = {};
   return;
   }

// _copy: internal copy method for the class
void TPhone::_copy(TPhone const& other) {
   ID(other.ID());
   PhoneType(other.PhoneType());
   AreaCode(other.AreaCode());
   CallNumber(other.CallNumber());
   Country(other.Country());
   DialingNational(other.DialingNational());
   DialingInternational(other.DialingInternational());
   return;
   }

} // end of namespace myCorporate
