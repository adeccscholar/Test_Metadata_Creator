/*
* Project: model with a simple person administration
* Implementation of the data class TCorporateForm
* Content: This table stores information about various types of legal forms. Each row corresponds to a specific legal form with several informations.
* Date: 25.03.2024 19:08:39,912  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\CorporateForm.h"

#include <typeinfo>

namespace myCorporate {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TCorporateForm
// ---------------------------------------------------------------------------------------
TCorporateForm::primary_key::primary_key() : iID {} { }

TCorporateForm::primary_key::primary_key(int pID) : iID(pID) { }

TCorporateForm::primary_key::primary_key(TCorporateForm const& other) : iID(other._ID()) { }

TCorporateForm::primary_key::primary_key(TCorporateForm::primary_key const& other) : iID(other.iID) { }

TCorporateForm::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TCorporateForm::primary_key::operator TCorporateForm() const {
   TCorporateForm ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TCorporateForm::primary_key::write(std::ostream& out) const {
   out << "elements of class TCorporateForm::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TCorporateForm::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TCorporateForm
// ---------------------------------------------------------------------------------------
TCorporateForm::TCorporateForm() {
   _init();
   }

TCorporateForm::TCorporateForm(TCorporateForm const& other){
   _copy(other);
   }

TCorporateForm::TCorporateForm(TCorporateForm&& other) noexcept {
   _swap(other);
   }

TCorporateForm::TCorporateForm(primary_key const& other) : iID(other.ID()) { }

TCorporateForm::~TCorporateForm() {   }

TCorporateForm& TCorporateForm::operator = (TCorporateForm const& other) {
   copy(other);
   return *this;
   }

TCorporateForm& TCorporateForm::operator = (TCorporateForm&& other) noexcept {
   swap(other);
   return *this;
   }

void TCorporateForm::swap(TCorporateForm& other) noexcept {
   _swap(other);
   }

void TCorporateForm::init() {
   _init();
   }

void TCorporateForm::copy(TSimplePersonBase const& other) {
   try {
      TCorporateForm const& ref = dynamic_cast<TCorporateForm const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TCorporateForm& TCorporateForm::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TCorporateForm::_swap(TCorporateForm& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(boIsLegalEntrity, other.boIsLegalEntrity);
   std::swap(iUrgentValue, other.iUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TCorporateForm::_init() {
   // initializing own data elements
   iID               = {};
   strDenotation     = {};
   strAbbreviation   = {};
   strDescription    = {};
   boIsLegalEntrity  = {};
   iUrgentValue      = {};
   return;
   }

// _copy: internal copy method for the class
void TCorporateForm::_copy(TCorporateForm const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   IsLegalEntrity(other.IsLegalEntrity());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myCorporate
