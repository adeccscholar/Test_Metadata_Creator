/*
* Project: model with a simple person administration
* Implementation of the data class TReasonDeparture
* Content: domain / range with the reasons of departure of the employee
* Date: 22.04.2025 22:26:56,431  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\ReasonDeparture.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TReasonDeparture
// ---------------------------------------------------------------------------------------
TReasonDeparture::primary_key::primary_key() : iID {} { }

TReasonDeparture::primary_key::primary_key(int pID) : iID(pID) { }

TReasonDeparture::primary_key::primary_key(TReasonDeparture const& other) : iID(other._ID()) { }

TReasonDeparture::primary_key::primary_key(TReasonDeparture::primary_key const& other) : iID(other.iID) { }

TReasonDeparture::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TReasonDeparture::primary_key::operator TReasonDeparture() const {
   TReasonDeparture ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TReasonDeparture::primary_key::write(std::ostream& out) const {
   out << "elements of class TReasonDeparture::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TReasonDeparture::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TReasonDeparture
// ---------------------------------------------------------------------------------------
TReasonDeparture::TReasonDeparture() {
   _init();
   }

TReasonDeparture::TReasonDeparture(TReasonDeparture const& other){
   _copy(other);
   }

TReasonDeparture::TReasonDeparture(TReasonDeparture&& other) noexcept {
   _swap(other);
   }

TReasonDeparture::TReasonDeparture(primary_key const& other) : iID(other.ID()) { }

TReasonDeparture::~TReasonDeparture() {   }

TReasonDeparture& TReasonDeparture::operator = (TReasonDeparture const& other) {
   copy(other);
   return *this;
   }

TReasonDeparture& TReasonDeparture::operator = (TReasonDeparture&& other) noexcept {
   swap(other);
   return *this;
   }

void TReasonDeparture::swap(TReasonDeparture& other) noexcept {
   _swap(other);
   }

void TReasonDeparture::init() {
   _init();
   }

void TReasonDeparture::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TReasonDeparture const& ref = dynamic_cast<TReasonDeparture const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TReasonDeparture& TReasonDeparture::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TReasonDeparture::_swap(TReasonDeparture& other) noexcept {
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
void TReasonDeparture::_init() {
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
void TReasonDeparture::_copy(TReasonDeparture const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myHR
