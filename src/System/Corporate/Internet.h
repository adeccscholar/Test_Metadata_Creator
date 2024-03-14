﻿// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TInternet
* Content: connections for different kinds of communications about the internet as part of persons (part of relationship)
* Date: 14.03.2024 23:56:53,612  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for common  virtual base class
#include "System\Corporate\base.h"

// necessary additional headers for used datatypes
#include <string>

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
// definition of the system class TInternet for
// - connections for different kinds of communications about the internet as part of persons (part of relationship)
// -------------------------------------------------------------------------------------------------
class TInternet : virtual public TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TInternet;
         private:
            int iID;          
            int iInternetType;

            constexpr primary_key() : iID {}, iInternetType {} { }
         public:
            constexpr primary_key(int pID, int pInternetType) : iID(pID), iInternetType(pInternetType) { }
            primary_key(TInternet const& other) : iID(other._ID()), iInternetType(other._InternetType()) { }
            constexpr primary_key(primary_key const& other) : iID(other.iID), iInternetType(other.iInternetType) { }
            constexpr primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)), iInternetType(std::move(other.iInternetType)) { }
            constexpr ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TInternet() const {
               TInternet ret;
               return ret.init(*this);
               }

            // relational operators of the primary type class
            bool operator == (primary_key const& other) const { return _compare(other) == 0; }
            bool operator != (primary_key const& other) const { return _compare(other) != 0; }
            bool operator <  (primary_key const& other) const { return _compare(other) <  0; }
            bool operator <= (primary_key const& other) const { return _compare(other) <= 0; }
            bool operator >  (primary_key const& other) const { return _compare(other) >  0; }
            bool operator >= (primary_key const& other) const { return _compare(other) >= 0; }

            // selectors the primary type class
            int        ID() const { return iID; }
            int        InternetType() const { return iInternetType; }

            // manipulators the primary type class
            int        ID(int newVal) { return iID = newVal; }
            int        InternetType(int newVal) { return iInternetType = newVal; }

         private:
            int _compare(primary_key const& other) const {
               static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
                  return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
                  };
               if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
               if(auto ret = comp_help(this->iInternetType, other.iInternetType); ret != 0) return ret;
               return 0;
               }
         };

      using container_ty = std::map<primary_key, TInternet>;
      using vector_ty    = std::vector<TInternet>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table Internet
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;          
      std::optional<int>         iInternetType;
      std::optional<std::string> strAdresse;   

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TInternet();
      TInternet(TInternet const&);
      TInternet(TInternet &&) noexcept;
      virtual ~TInternet();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TInternet& operator = (TInternet const&);
      TInternet& operator = (TInternet&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TInternet& rhs) noexcept;
      virtual void init() override;
      virtual void copy(TSimplePersonBase const& other) override;

      TInternet& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID() const { return iID; }
      std::optional<int> const&         InternetType() const { return iInternetType; }
      std::optional<std::string> const& Adresse() const { return strAdresse; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      int                               _InternetType() const;
      std::string const&                _Adresse() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<int> const&         InternetType(std::optional<int> const& newVal);
      std::optional<std::string> const& Adresse(std::optional<std::string> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TInternet& rhs) noexcept;
      void _init();
      void _copy(TInternet const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TInternet::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TInternet\" is empty.");;
   }

inline int TInternet::_InternetType() const {
   if(iInternetType) [[likely]] return iInternetType.value();
   else throw std::runtime_error("value for attribute \"InternetType\" in class \"TInternet\" is empty.");;
   }

inline std::string const& TInternet::_Adresse() const {
   if(strAdresse) [[likely]] return strAdresse.value();
   else throw std::runtime_error("value for attribute \"Adresse\" in class \"TInternet\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TInternet::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<int> const& TInternet::InternetType(std::optional<int> const& newVal) {
   return iInternetType = newVal;
   }

inline std::optional<std::string> const& TInternet::Adresse(std::optional<std::string> const& newVal) {
   return strAdresse = newVal;
   }

} // end of namespace myCorporate
