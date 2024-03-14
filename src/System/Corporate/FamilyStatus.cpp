/*
* Project: model with a simple person administration
* Implementation of the data class TFamilyStatus
* Content: domain / range of values for family status, this is used in person to qualifify the actual status, maybe a date needed too
* Date: 14.03.2024 23:56:53,419  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate/FamilyStatus.h"

#include <typeinfo>

namespace myCorporate {

TFamilyStatus::TFamilyStatus() {
   _init();
   }

TFamilyStatus::TFamilyStatus(TFamilyStatus const& other){
   _copy(other);
   }

TFamilyStatus::TFamilyStatus(TFamilyStatus&& other) noexcept {
   _swap(other);
   }

TFamilyStatus::~TFamilyStatus() {   }

TFamilyStatus& TFamilyStatus::operator = (TFamilyStatus const& other) {
   copy(other);
   return *this;
   }

TFamilyStatus& TFamilyStatus::operator = (TFamilyStatus&& other) noexcept {
   swap(other);
   return *this;
   }

void TFamilyStatus::swap(TFamilyStatus& other) noexcept {
   _swap(other);
   }

void TFamilyStatus::init() {
   _init();
   }

void TFamilyStatus::copy(TSimplePersonBase const& other) {
   try {
      TFamilyStatus const& ref = dynamic_cast<TFamilyStatus const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TFamilyStatus& TFamilyStatus::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TFamilyStatus::_swap(TFamilyStatus& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(boCoupled, other.boCoupled);
   std::swap(boNeedDate, other.boNeedDate);
   std::swap(strNotes, other.strNotes);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TFamilyStatus::_init() {
   // initializing own data elements
   iID              = {};
   strDenotation    = {};
   strAbbreviation  = {};
   strDescription   = {};
   boCoupled        = {};
   boNeedDate       = {};
   strNotes         = {};
   boUrgentValue    = {};
   return;
   }

// _copy: internal copy method for the class
void TFamilyStatus::_copy(TFamilyStatus const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   Coupled(other.Coupled());
   NeedDate(other.NeedDate());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myCorporate
