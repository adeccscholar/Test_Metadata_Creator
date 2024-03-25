// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TPhone
* Content: phone connections of persons (part of relationship)
* Date: 25.03.2024 19:08:40,702  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for common  virtual base class
#include "System\Corporate\base.h"

// necessary additional headers for used datatypes
#include <string>

#include <iostream>
#include <iomanip>
#include <optional>
#include <stdexcept>
#include <map>
#include <vector>
#include <tuple>
#include <memory>

namespace reader {
   class TPersonReader;
   }

namespace myCorporate {

// -------------------------------------------------------------------------------------------------
// definition of the system class TPhone for
// - phone connections of persons (part of relationship)
// -------------------------------------------------------------------------------------------------
class TPhone : virtual public TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TPhone;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iID;                    
            int iPhoneType;             

            primary_key();
         public:
            primary_key(int pID, int pPhoneType);
            explicit primary_key(TPhone const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TPhone() const;

            // relational operators of the primary type class
            bool operator == (primary_key const& other) const { return _compare(other) == 0; }
            bool operator != (primary_key const& other) const { return _compare(other) != 0; }
            bool operator <  (primary_key const& other) const { return _compare(other) <  0; }
            bool operator <= (primary_key const& other) const { return _compare(other) <= 0; }
            bool operator >  (primary_key const& other) const { return _compare(other) >  0; }
            bool operator >= (primary_key const& other) const { return _compare(other) >= 0; }

            // selectors the primary type class
            int        ID() const { return iID; }
            int        PhoneType() const { return iPhoneType; }

            // manipulators the primary type class
            int        ID(int newVal) { return iID = newVal; }
            int        PhoneType(int newVal) { return iPhoneType = newVal; }

            // method to write elements of the primary key type class to a stream
            std::ostream& write(std::ostream& out) const;

         private:
            int _compare(primary_key const& other) const;
         };

      using container_ty = std::map<primary_key, TPhone>;
      using vector_ty    = std::vector<TPhone>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table Phone
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;                    
      std::optional<int>         iPhoneType;             
      std::optional<std::string> strAreaCode;            
      std::optional<std::string> strCallNumber;          
      std::optional<int>         iCountry;               
      std::optional<std::string> strDialingNational;     
      std::optional<std::string> strDialingInternational;

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TPhone();
      TPhone(TPhone const&);
      TPhone(TPhone &&) noexcept;
      explicit TPhone(primary_key const&);
      virtual ~TPhone();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TPhone& operator = (TPhone const&);
      TPhone& operator = (TPhone&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TPhone& rhs) noexcept;
      virtual void init() override;
      virtual void copy(TSimplePersonBase const& other) override;

      TPhone& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID() const { return iID; }
      std::optional<int> const&         PhoneType() const { return iPhoneType; }
      std::optional<std::string> const& AreaCode() const { return strAreaCode; }
      std::optional<std::string> const& CallNumber() const { return strCallNumber; }
      std::optional<int> const&         Country() const { return iCountry; }
      std::optional<std::string> const& DialingNational() const { return strDialingNational; }
      std::optional<std::string> const& DialingInternational() const { return strDialingInternational; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      int                               _PhoneType() const;
      std::string const&                _AreaCode() const;
      std::string const&                _CallNumber() const;
      int                               _Country() const;
      std::string const&                _DialingNational() const;
      std::string const&                _DialingInternational() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<int> const&         PhoneType(std::optional<int> const& newVal);
      std::optional<std::string> const& AreaCode(std::optional<std::string> const& newVal);
      std::optional<std::string> const& CallNumber(std::optional<std::string> const& newVal);
      std::optional<int> const&         Country(std::optional<int> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // private  manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<std::string> const& DialingNational(std::optional<std::string> const& newVal);
      std::optional<std::string> const& DialingInternational(std::optional<std::string> const& newVal);

      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TPhone& rhs) noexcept;
      void _init();
      void _copy(TPhone const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TPhone::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TPhone\" is empty.");;
   }

inline int TPhone::_PhoneType() const {
   if(iPhoneType) [[likely]] return iPhoneType.value();
   else throw std::runtime_error("value for attribute \"PhoneType\" in class \"TPhone\" is empty.");;
   }

inline std::string const& TPhone::_AreaCode() const {
   if(strAreaCode) [[likely]] return strAreaCode.value();
   else throw std::runtime_error("value for attribute \"AreaCode\" in class \"TPhone\" is empty.");;
   }

inline std::string const& TPhone::_CallNumber() const {
   if(strCallNumber) [[likely]] return strCallNumber.value();
   else throw std::runtime_error("value for attribute \"CallNumber\" in class \"TPhone\" is empty.");;
   }

inline int TPhone::_Country() const {
   if(iCountry) [[likely]] return iCountry.value();
   else throw std::runtime_error("value for attribute \"Country\" in class \"TPhone\" is empty.");;
   }

inline std::string const& TPhone::_DialingNational() const {
   if(strDialingNational) [[likely]] return strDialingNational.value();
   else throw std::runtime_error("value for attribute \"DialingNational\" in class \"TPhone\" is empty.");;
   }

inline std::string const& TPhone::_DialingInternational() const {
   if(strDialingInternational) [[likely]] return strDialingInternational.value();
   else throw std::runtime_error("value for attribute \"DialingInternational\" in class \"TPhone\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TPhone::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<int> const& TPhone::PhoneType(std::optional<int> const& newVal) {
   return iPhoneType = newVal;
   }

inline std::optional<std::string> const& TPhone::AreaCode(std::optional<std::string> const& newVal) {
   return strAreaCode = newVal;
   }

inline std::optional<std::string> const& TPhone::CallNumber(std::optional<std::string> const& newVal) {
   return strCallNumber = newVal;
   }

inline std::optional<int> const& TPhone::Country(std::optional<int> const& newVal) {
   return iCountry = newVal;
   }

inline std::optional<std::string> const& TPhone::DialingNational(std::optional<std::string> const& newVal) {
   return strDialingNational = newVal;
   }

inline std::optional<std::string> const& TPhone::DialingInternational(std::optional<std::string> const& newVal) {
   return strDialingInternational = newVal;
   }

} // end of namespace myCorporate
