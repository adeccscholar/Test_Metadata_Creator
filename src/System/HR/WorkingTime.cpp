/*
* Project: model with a simple person administration
* Implementation of the data class TWorkingTime
* Content: entity with the working times for an employee, as a composition for these.
* Date: 14.03.2024 23:56:54,410  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR/WorkingTime.h"

#include <typeinfo>

namespace myHR {

TWorkingTime::TWorkingTime() {
   _init();
   }

TWorkingTime::TWorkingTime(TWorkingTime const& other){
   _copy(other);
   }

TWorkingTime::TWorkingTime(TWorkingTime&& other) noexcept {
   _swap(other);
   }

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
