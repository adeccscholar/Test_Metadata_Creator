﻿// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TAddress
* Content: information on the addresses where a person lives, works or has any other relationship with them
* Date: 22.04.2025 22:26:55,134  file created with adecc Scholar metadata generator
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
// definition of the system class TAddress for
// - information on the addresses where a person lives, works or has any other relationship with them
// -------------------------------------------------------------------------------------------------
class TAddress : virtual public TSimplePersonBase {
   friend class reader::DataAccess;   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TAddress;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iID;            
            int iAddressType;   

            primary_key();
         public:
            primary_key(int pID, int pAddressType);
            explicit primary_key(TAddress const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TAddress() const;

            // relational operators of the primary type class
            bool operator == (primary_key const& other) const { return _compare(other) == 0; }
            bool operator != (primary_key const& other) const { return _compare(other) != 0; }
            bool operator <  (primary_key const& other) const { return _compare(other) <  0; }
            bool operator <= (primary_key const& other) const { return _compare(other) <= 0; }
            bool operator >  (primary_key const& other) const { return _compare(other) >  0; }
            bool operator >= (primary_key const& other) const { return _compare(other) >= 0; }

            // selectors the primary type class
            int        ID() const { return iID; }
            int        AddressType() const { return iAddressType; }

            // manipulators the primary type class
            int        ID(int newVal) { return iID = newVal; }
            int        AddressType(int newVal) { return iAddressType = newVal; }

            // method to write elements of the primary key type class to a stream
            std::ostream& write(std::ostream& out) const;

         private:
            int _compare(primary_key const& other) const;
         };

      using func_ty = std::function<bool(TAddress&&)>;
      using container_ty = std::map<primary_key, TAddress>;
      using vector_ty    = std::vector<TAddress>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table Address
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;            
      std::optional<int>         iAddressType;   
      std::optional<std::string> strZipcode;     
      std::optional<std::string> strCity;        
      std::optional<std::string> strStreet;      
      std::optional<std::string> strStreetNumber;
      std::optional<int>         iCountry;       

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TAddress();
      TAddress(TAddress const&);
      TAddress(TAddress &&) noexcept;
      explicit TAddress(primary_key const&);
      virtual ~TAddress();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TAddress& operator = (TAddress const&);
      TAddress& operator = (TAddress&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TAddress& rhs) noexcept;
      virtual void init() override;
      virtual void copy(TSimplePersonBase const& other) override;

      TAddress& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID() const { return iID; }
      std::optional<int> const&         AddressType() const { return iAddressType; }
      std::optional<std::string> const& Zipcode() const { return strZipcode; }
      std::optional<std::string> const& City() const { return strCity; }
      std::optional<std::string> const& Street() const { return strStreet; }
      std::optional<std::string> const& StreetNumber() const { return strStreetNumber; }
      std::optional<int> const&         Country() const { return iCountry; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      int                               _AddressType() const;
      std::string const&                _Zipcode() const;
      std::string const&                _City() const;
      std::string const&                _Street() const;
      std::string const&                _StreetNumber() const;
      int                               _Country() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<int> const&         AddressType(std::optional<int> const& newVal);
      std::optional<std::string> const& Zipcode(std::optional<std::string> const& newVal);
      std::optional<std::string> const& City(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Street(std::optional<std::string> const& newVal);
      std::optional<std::string> const& StreetNumber(std::optional<std::string> const& newVal);
      std::optional<int> const&         Country(std::optional<int> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TAddress& rhs) noexcept;
      void _init();
      void _copy(TAddress const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TAddress::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TAddress\" is empty.");;
   }

inline int TAddress::_AddressType() const {
   if(iAddressType) [[likely]] return iAddressType.value();
   else throw std::runtime_error("value for attribute \"AddressType\" in class \"TAddress\" is empty.");;
   }

inline std::string const& TAddress::_Zipcode() const {
   if(strZipcode) [[likely]] return strZipcode.value();
   else throw std::runtime_error("value for attribute \"Zipcode\" in class \"TAddress\" is empty.");;
   }

inline std::string const& TAddress::_City() const {
   if(strCity) [[likely]] return strCity.value();
   else throw std::runtime_error("value for attribute \"City\" in class \"TAddress\" is empty.");;
   }

inline std::string const& TAddress::_Street() const {
   if(strStreet) [[likely]] return strStreet.value();
   else throw std::runtime_error("value for attribute \"Street\" in class \"TAddress\" is empty.");;
   }

inline std::string const& TAddress::_StreetNumber() const {
   if(strStreetNumber) [[likely]] return strStreetNumber.value();
   else throw std::runtime_error("value for attribute \"StreetNumber\" in class \"TAddress\" is empty.");;
   }

inline int TAddress::_Country() const {
   if(iCountry) [[likely]] return iCountry.value();
   else throw std::runtime_error("value for attribute \"Country\" in class \"TAddress\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TAddress::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<int> const& TAddress::AddressType(std::optional<int> const& newVal) {
   return iAddressType = newVal;
   }

inline std::optional<std::string> const& TAddress::Zipcode(std::optional<std::string> const& newVal) {
   return strZipcode = newVal;
   }

inline std::optional<std::string> const& TAddress::City(std::optional<std::string> const& newVal) {
   return strCity = newVal;
   }

inline std::optional<std::string> const& TAddress::Street(std::optional<std::string> const& newVal) {
   return strStreet = newVal;
   }

inline std::optional<std::string> const& TAddress::StreetNumber(std::optional<std::string> const& newVal) {
   return strStreetNumber = newVal;
   }

inline std::optional<int> const& TAddress::Country(std::optional<int> const& newVal) {
   return iCountry = newVal;
   }

} // end of namespace myCorporate
