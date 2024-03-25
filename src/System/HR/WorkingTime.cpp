/*
* Project: model with a simple person administration
* Implementation of the data class TWorkingTime
* Content: entity with the working times for an employee, as a composition for these.
* Date: 25.03.2024 19:08:41,304  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR\WorkingTime.h"

#include <typeinfo>

namespace myHR {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TWorkingTime
// ---------------------------------------------------------------------------------------
TWorkingTime::primary_key::primary_key() : iID {}, dtStartingTime {} { }

TWorkingTime::primary_key::primary_key(int pID, std::chrono::system_clock::time_point pStartingTime) : iID(pID), dtStartingTime(pStartingTime) { }

TWorkingTime::primary_key::primary_key(TWorkingTime const& other) : iID(other._ID()), dtStartingTime(other._StartingTime()) { }

TWorkingTime::primary_key::primary_key(TWorkingTime::primary_key const& other) : iID(other.iID), dtStartingTime(other.dtStartingTime) { }

TWorkingTime::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)), dtStartingTime(std::move(other.dtStartingTime)) { }

// conversions operator for this element to the encircling class
TWorkingTime::primary_key::operator TWorkingTime() const {
   TWorkingTime ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TWorkingTime::primary_key::write(std::ostream& out) const {
   out << "elements of class TWorkingTime::primary_key:\n";
   out << std::left << std::setw(16) << " - ID" << ":" << iID << '\n';
   out << std::left << std::setw(16) << " - StartingTime" << ":" << dtStartingTime << '\n';
   return out;
   }

int TWorkingTime::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   if(auto ret = comp_help(this->dtStartingTime, other.dtStartingTime); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TWorkingTime
// ---------------------------------------------------------------------------------------
TWorkingTime::TWorkingTime() {
   _init();
   }

TWorkingTime::TWorkingTime(TWorkingTime const& other){
   _copy(other);
   }

TWorkingTime::TWorkingTime(TWorkingTime&& other) noexcept {
   _swap(other);
   }

TWorkingTime::TWorkingTime(primary_key const& other) : iID(other.ID()), dtStartingTime(other.StartingTime()) { }

TWorkingTime::~TWorkingTime() {   }

TWorkingTime& TWorkingTime::operator = (TWorkingTime const& other) {
   copy(other);
   return *this;
   }

TWorkingTime& TWorkingTime::operator = (TWorkingTime&& other) noexcept {
   swap(other);
   return *this;
   }

void TWorkingTime::swap(TWorkingTime& other) noexcept {
   _swap(other);
   }

void TWorkingTime::init() {
   _init();
   }

void TWorkingTime::copy(myCorporate::TSimplePersonBase const& other) {
   try {
      TWorkingTime const& ref = dynamic_cast<TWorkingTime const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TWorkingTime& TWorkingTime::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   StartingTime(key_values.StartingTime());
   return *this;
   }

// _swap: internal swapping method for the class
void TWorkingTime::_swap(TWorkingTime& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(dtStartingTime, other.dtStartingTime);
   std::swap(dtClosingTime, other.dtClosingTime);
   std::swap(boProcessed, other.boProcessed);
   std::swap(dtProcessedAt, other.dtProcessedAt);
   std::swap(daDayOfWork, other.daDayOfWork);
   return;
   }

// _init: internal initialization method for the instance of this class
void TWorkingTime::_init() {
   // initializing own data elements
   iID             = {};
   dtStartingTime  = {};
   dtClosingTime   = { };
   boProcessed     = {};
   dtProcessedAt   = {};
   daDayOfWork     = {};
   return;
   }

// _copy: internal copy method for the class
void TWorkingTime::_copy(TWorkingTime const& other) {
   ID(other.ID());
   StartingTime(other.StartingTime());
   ClosingTime(other.ClosingTime());
   Processed(other.Processed());
   ProcessedAt(other.ProcessedAt());
   DayOfWork(other.DayOfWork());
   return;
   }

} // end of namespace myHR
