/*
* Project: model with a simple person administration
* Implementation of the data class TWD_NonWorking
* Content: entity set with non working days. Extensions possible, responsible for this table is HR.
* Date: 22.04.2025 22:26:56,796  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\WD_NonWorking.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TWD_NonWorking
// ---------------------------------------------------------------------------------------
TWD_NonWorking::primary_key::primary_key() : iID {}, daStartAt {} { }

TWD_NonWorking::primary_key::primary_key(int pID, std::chrono::year_month_day pStartAt) : iID(pID), daStartAt(pStartAt) { }

TWD_NonWorking::primary_key::primary_key(TWD_NonWorking const& other) : iID(other._ID()), daStartAt(other._StartAt()) { }

TWD_NonWorking::primary_key::primary_key(TWD_NonWorking::primary_key const& other) : iID(other.iID), daStartAt(other.daStartAt) { }

TWD_NonWorking::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)), daStartAt(std::move(other.daStartAt)) { }

// conversions operator for this element to the encircling class
TWD_NonWorking::primary_key::operator TWD_NonWorking() const {
   TWD_NonWorking ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TWD_NonWorking::primary_key::write(std::ostream& out) const {
   out << "elements of class TWD_NonWorking::primary_key:\n";
   out << std::left << std::setw(11) << " - ID" << ":" << iID << '\n';
   out << std::left << std::setw(11) << " - StartAt" << ":" << daStartAt << '\n';
   return out;
   }

int TWD_NonWorking::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   if(auto ret = comp_help(this->daStartAt, other.daStartAt); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TWD_NonWorking
// ---------------------------------------------------------------------------------------
TWD_NonWorking::TWD_NonWorking() {
   _init();
   }

TWD_NonWorking::TWD_NonWorking(TWD_NonWorking const& other){
   _copy(other);
   }

TWD_NonWorking::TWD_NonWorking(TWD_NonWorking&& other) noexcept {
   _swap(other);
   }

TWD_NonWorking::TWD_NonWorking(primary_key const& other) : iID(other.ID()), daStartAt(other.StartAt()) { }

TWD_NonWorking::~TWD_NonWorking() {   }

TWD_NonWorking& TWD_NonWorking::operator = (TWD_NonWorking const& other) {
   copy(other);
   return *this;
   }

TWD_NonWorking& TWD_NonWorking::operator = (TWD_NonWorking&& other) noexcept {
   swap(other);
   return *this;
   }

void TWD_NonWorking::swap(TWD_NonWorking& other) noexcept {
   _swap(other);
   }

void TWD_NonWorking::init() {
   _init();
   }

void TWD_NonWorking::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TWD_NonWorking const& ref = dynamic_cast<TWD_NonWorking const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TWD_NonWorking& TWD_NonWorking::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   StartAt(key_values.StartAt());
   return *this;
   }

// _swap: internal swapping method for the class
void TWD_NonWorking::_swap(TWD_NonWorking& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(daStartAt, other.daStartAt);
   std::swap(daClosingAt, other.daClosingAt);
   std::swap(iReason, other.iReason);
   std::swap(strNotes, other.strNotes);
   return;
   }

// _init: internal initialization method for the instance of this class
void TWD_NonWorking::_init() {
   // initializing own data elements
   iID          = {};
   daStartAt    = {};
   daClosingAt  = {};
   iReason      = {};
   strNotes     = {};
   return;
   }

// _copy: internal copy method for the class
void TWD_NonWorking::_copy(TWD_NonWorking const& other) {
   ID(other.ID());
   StartAt(other.StartAt());
   ClosingAt(other.ClosingAt());
   Reason(other.Reason());
   Notes(other.Notes());
   return;
   }

} // end of namespace myHR
