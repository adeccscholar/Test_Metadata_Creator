/*
* Project: model with a simple person administration
* Implementation of the data class TInternet
* Content: connections for different kinds of communications about the internet as part of persons (part of relationship)
* Date: 14.03.2024 23:56:53,629  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate/Internet.h"

#include <typeinfo>

namespace myCorporate {

TInternet::TInternet() {
   _init();
   }

TInternet::TInternet(TInternet const& other){
   _copy(other);
   }

TInternet::TInternet(TInternet&& other) noexcept {
   _swap(other);
   }

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
