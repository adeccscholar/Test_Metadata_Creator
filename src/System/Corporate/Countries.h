// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TCountries
* Content: table with the countries and additional values for the countries. Used by others for assoziation.
* Date: 22.04.2025 22:26:55,571  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for common  virtual base class
#include "Base\BaseClass.h"

// necessary additional headers for used datatypes
#include <string>

#include <iostream>
#include <iomanip>
#include <optional>
#include <stdexcept>
#include <functional>
#include <map>
#include <vector>
#include <tuple>
#include <memory>

namespace reader {
   class DataAccess; // helper class, later changing
   class TPersonReader;
   }

namespace myCorporate {

// -------------------------------------------------------------------------------------------------
// definition of the system class TCountries for
// - table with the countries and additional values for the countries. Used by others for assoziation.
// -------------------------------------------------------------------------------------------------
class TCountries : virtual public TSimplePersonBase {
   friend class reader::DataAccess;   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TCountries;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iID;              

            primary_key();
         public:
            /* explicit */primary_key(int pID);
            explicit primary_key(TCountries const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TCountries() const;

            // relational operators of the primary type class
            bool operator == (primary_key const& other) const { return _compare(other) == 0; }
            bool operator != (primary_key const& other) const { return _compare(other) != 0; }
            bool operator <  (primary_key const& other) const { return _compare(other) <  0; }
            bool operator <= (primary_key const& other) const { return _compare(other) <= 0; }
            bool operator >  (primary_key const& other) const { return _compare(other) >  0; }
            bool operator >= (primary_key const& other) const { return _compare(other) >= 0; }

            // selectors the primary type class
            int        ID() const { return iID; }

            // manipulators the primary type class
            int        ID(int newVal) { return iID = newVal; }

            // method to write elements of the primary key type class to a stream
            std::ostream& write(std::ostream& out) const;

         private:
            int _compare(primary_key const& other) const;
         };

      using func_ty = std::function<bool(TCountries&&)>;
      using container_ty = std::map<primary_key, TCountries>;
      using vector_ty    = std::vector<TCountries>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table Countries
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;              
      std::optional<std::string> strDenotation;    
      std::optional<std::string> strAbbreviation;  
      std::optional<std::string> strDescription;   
      std::optional<std::string> strCountryDialing;
      std::optional<std::string> strISO_Code;      
      std::optional<bool>        boIsEU;           
      std::optional<std::string> strCapital;       
      std::optional<std::string> strCurrency;      
      std::optional<std::string> strNotes;         
      std::optional<bool>        boUrgentValue;    

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TCountries();
      TCountries(TCountries const&);
      TCountries(TCountries &&) noexcept;
      explicit TCountries(primary_key const&);
      virtual ~TCountries();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TCountries& operator = (TCountries const&);
      TCountries& operator = (TCountries&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TCountries& rhs) noexcept;
      virtual void init() override;
      virtual void copy(TSimplePersonBase const& other) override;

      TCountries& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID() const { return iID; }
      std::optional<std::string> const& Denotation() const { return strDenotation; }
      std::optional<std::string> const& Abbreviation() const { return strAbbreviation; }
      std::optional<std::string> const& Description() const { return strDescription; }
      std::optional<std::string> const& CountryDialing() const { return strCountryDialing; }
      std::optional<std::string> const& ISO_Code() const { return strISO_Code; }
      std::optional<bool> const&        IsEU() const { return boIsEU; }
      std::optional<std::string> const& Capital() const { return strCapital; }
      std::optional<std::string> const& Currency() const { return strCurrency; }
      std::optional<std::string> const& Notes() const { return strNotes; }
      std::optional<bool> const&        UrgentValue() const { return boUrgentValue; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      std::string const&                _Denotation() const;
      std::string const&                _Abbreviation() const;
      std::string const&                _Description() const;
      std::string const&                _CountryDialing() const;
      std::string const&                _ISO_Code() const;
      bool                              _IsEU() const;
      std::string const&                _Capital() const;
      std::string const&                _Currency() const;
      std::string const&                _Notes() const;
      bool                              _UrgentValue() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<std::string> const& Denotation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Abbreviation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Description(std::optional<std::string> const& newVal);
      std::optional<std::string> const& CountryDialing(std::optional<std::string> const& newVal);
      std::optional<std::string> const& ISO_Code(std::optional<std::string> const& newVal);
      std::optional<bool> const&        IsEU(std::optional<bool> const& newVal);
      std::optional<std::string> const& Capital(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Currency(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Notes(std::optional<std::string> const& newVal);
      std::optional<bool> const&        UrgentValue(std::optional<bool> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TCountries& rhs) noexcept;
      void _init();
      void _copy(TCountries const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TCountries::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TCountries\" is empty.");;
   }

inline std::string const& TCountries::_Denotation() const {
   if(strDenotation) [[likely]] return strDenotation.value();
   else throw std::runtime_error("value for attribute \"Denotation\" in class \"TCountries\" is empty.");;
   }

inline std::string const& TCountries::_Abbreviation() const {
   if(strAbbreviation) [[likely]] return strAbbreviation.value();
   else throw std::runtime_error("value for attribute \"Abbreviation\" in class \"TCountries\" is empty.");;
   }

inline std::string const& TCountries::_Description() const {
   if(strDescription) [[likely]] return strDescription.value();
   else throw std::runtime_error("value for attribute \"Description\" in class \"TCountries\" is empty.");;
   }

inline std::string const& TCountries::_CountryDialing() const {
   if(strCountryDialing) [[likely]] return strCountryDialing.value();
   else throw std::runtime_error("value for attribute \"CountryDialing\" in class \"TCountries\" is empty.");;
   }

inline std::string const& TCountries::_ISO_Code() const {
   if(strISO_Code) [[likely]] return strISO_Code.value();
   else throw std::runtime_error("value for attribute \"ISO_Code\" in class \"TCountries\" is empty.");;
   }

inline bool TCountries::_IsEU() const {
   if(boIsEU) [[likely]] return boIsEU.value();
   else throw std::runtime_error("value for attribute \"IsEU\" in class \"TCountries\" is empty.");;
   }

inline std::string const& TCountries::_Capital() const {
   if(strCapital) [[likely]] return strCapital.value();
   else throw std::runtime_error("value for attribute \"Capital\" in class \"TCountries\" is empty.");;
   }

inline std::string const& TCountries::_Currency() const {
   if(strCurrency) [[likely]] return strCurrency.value();
   else throw std::runtime_error("value for attribute \"Currency\" in class \"TCountries\" is empty.");;
   }

inline std::string const& TCountries::_Notes() const {
   if(strNotes) [[likely]] return strNotes.value();
   else throw std::runtime_error("value for attribute \"Notes\" in class \"TCountries\" is empty.");;
   }

inline bool TCountries::_UrgentValue() const {
   if(boUrgentValue) [[likely]] return boUrgentValue.value();
   else throw std::runtime_error("value for attribute \"UrgentValue\" in class \"TCountries\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TCountries::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TCountries::Denotation(std::optional<std::string> const& newVal) {
   return strDenotation = newVal;
   }

inline std::optional<std::string> const& TCountries::Abbreviation(std::optional<std::string> const& newVal) {
   return strAbbreviation = newVal;
   }

inline std::optional<std::string> const& TCountries::Description(std::optional<std::string> const& newVal) {
   return strDescription = newVal;
   }

inline std::optional<std::string> const& TCountries::CountryDialing(std::optional<std::string> const& newVal) {
   return strCountryDialing = newVal;
   }

inline std::optional<std::string> const& TCountries::ISO_Code(std::optional<std::string> const& newVal) {
   return strISO_Code = newVal;
   }

inline std::optional<bool> const& TCountries::IsEU(std::optional<bool> const& newVal) {
   return boIsEU = newVal;
   }

inline std::optional<std::string> const& TCountries::Capital(std::optional<std::string> const& newVal) {
   return strCapital = newVal;
   }

inline std::optional<std::string> const& TCountries::Currency(std::optional<std::string> const& newVal) {
   return strCurrency = newVal;
   }

inline std::optional<std::string> const& TCountries::Notes(std::optional<std::string> const& newVal) {
   return strNotes = newVal;
   }

inline std::optional<bool> const& TCountries::UrgentValue(std::optional<bool> const& newVal) {
   return boUrgentValue = newVal;
   }

} // end of namespace myCorporate
