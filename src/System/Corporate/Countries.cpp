/*
* Project: model with a simple person administration
* Implementation of the data class TCountries
* Content: table with the countries and additional values for the countries. Used by others for assoziation.
* Date: 22.03.2024 15:39:11,855  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\Corporate\Countries.h"

#include <typeinfo>

namespace myCorporate {

// ---------------------------------------------------------------------------------------
// implementation for the primary_key class inside of TCountries
// ---------------------------------------------------------------------------------------
TCountries::primary_key::primary_key() : iID {} { }

TCountries::primary_key::primary_key(int pID) : iID(pID) { }

TCountries::primary_key::primary_key(TCountries const& other) : iID(other._ID()) { }

TCountries::primary_key::primary_key(TCountries::primary_key const& other) : iID(other.iID) { }

TCountries::primary_key::primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }

// conversions operator for this element to the encircling class
TCountries::primary_key::operator TCountries() const {
   TCountries ret;
   return ret.init(*this);
   }

// write method for this primary_key element
std::ostream& TCountries::primary_key::write(std::ostream& out) const {
   out << "elements of class TCountries::primary_key:\n";
   out << std::left << std::setw(6) << " - ID" << ":" << iID << '\n';
   return out;
   }

int TCountries::primary_key::_compare(primary_key const& other) const {
   static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
      return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
      };

   if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
   return 0;
   }

// ---------------------------------------------------------------------------------------
// implementation of the class TCountries
// ---------------------------------------------------------------------------------------
TCountries::TCountries() {
   _init();
   }

TCountries::TCountries(TCountries const& other){
   _copy(other);
   }

TCountries::TCountries(TCountries&& other) noexcept {
   _swap(other);
   }

TCountries::TCountries(primary_key const& other) : iID(other.ID()) { }

TCountries::~TCountries() {   }

TCountries& TCountries::operator = (TCountries const& other) {
   copy(other);
   return *this;
   }

TCountries& TCountries::operator = (TCountries&& other) noexcept {
   swap(other);
   return *this;
   }

void TCountries::swap(TCountries& other) noexcept {
   _swap(other);
   }

void TCountries::init() {
   _init();
   }

void TCountries::copy(TSimplePersonBase const& other) {
   try {
      TCountries const& ref = dynamic_cast<TCountries const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TCountries& TCountries::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TCountries::_swap(TCountries& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strDenotation, other.strDenotation);
   std::swap(strAbbreviation, other.strAbbreviation);
   std::swap(strDescription, other.strDescription);
   std::swap(strCountryDialing, other.strCountryDialing);
   std::swap(strISO_Code, other.strISO_Code);
   std::swap(boIsEU, other.boIsEU);
   std::swap(strCapital, other.strCapital);
   std::swap(strCurrency, other.strCurrency);
   std::swap(strNotes, other.strNotes);
   std::swap(boUrgentValue, other.boUrgentValue);
   return;
   }

// _init: internal initialization method for the instance of this class
void TCountries::_init() {
   // initializing own data elements
   iID                = {};
   strDenotation      = {};
   strAbbreviation    = {};
   strDescription     = {};
   strCountryDialing  = {};
   strISO_Code        = {};
   boIsEU             = {};
   strCapital         = {};
   strCurrency        = {};
   strNotes           = {};
   boUrgentValue      = {};
   return;
   }

// _copy: internal copy method for the class
void TCountries::_copy(TCountries const& other) {
   ID(other.ID());
   Denotation(other.Denotation());
   Abbreviation(other.Abbreviation());
   Description(other.Description());
   CountryDialing(other.CountryDialing());
   ISO_Code(other.ISO_Code());
   IsEU(other.IsEU());
   Capital(other.Capital());
   Currency(other.Currency());
   Notes(other.Notes());
   UrgentValue(other.UrgentValue());
   return;
   }

} // end of namespace myCorporate
