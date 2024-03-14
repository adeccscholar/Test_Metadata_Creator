// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TWD_Weekdays
* Content: domain for days of week, used for table working time. Possible to extent with informations. In area HR only
* Date: 14.03.2024 23:56:54,303  file created with adecc Scholar metadata generator
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

namespace myHR {

// -------------------------------------------------------------------------------------------------
// definition of the system class TWD_Weekdays for
// - domain for days of week, used for table working time. Possible to extent with informations. In area HR only
// -------------------------------------------------------------------------------------------------
class TWD_Weekdays : virtual public myCorporate::TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TWD_Weekdays;
         private:
            int iID;            

            constexpr primary_key() : iID {} { }
         public:
            constexpr primary_key(int pID) : iID(pID) { }
            primary_key(TWD_Weekdays const& other) : iID(other._ID()) { }
            constexpr primary_key(primary_key const& other) : iID(other.iID) { }
            constexpr primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }
            constexpr ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TWD_Weekdays() const {
               TWD_Weekdays ret;
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

            // manipulators the primary type class
            int        ID(int newVal) { return iID = newVal; }

         private:
            int _compare(primary_key const& other) const {
               static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
                  return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
                  };
               if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
               return 0;
               }
         };

      using container_ty = std::map<primary_key, TWD_Weekdays>;
      using vector_ty    = std::vector<TWD_Weekdays>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table WD_Weekdays
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;            
      std::optional<std::string> strDenotation;  
      std::optional<std::string> strAbbreviation;
      std::optional<bool>        boWorkday;      

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TWD_Weekdays();
      TWD_Weekdays(TWD_Weekdays const&);
      TWD_Weekdays(TWD_Weekdays &&) noexcept;
      virtual ~TWD_Weekdays();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TWD_Weekdays& operator = (TWD_Weekdays const&);
      TWD_Weekdays& operator = (TWD_Weekdays&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TWD_Weekdays& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TWD_Weekdays& init(primary_key const&);

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
      std::optional<bool> const&        Workday() const { return boWorkday; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      std::string const&                _Denotation() const;
      std::string const&                _Abbreviation() const;
      bool                              _Workday() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<std::string> const& Denotation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Abbreviation(std::optional<std::string> const& newVal);
      std::optional<bool> const&        Workday(std::optional<bool> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TWD_Weekdays& rhs) noexcept;
      void _init();
      void _copy(TWD_Weekdays const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TWD_Weekdays::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TWD_Weekdays\" is empty.");;
   }

inline std::string const& TWD_Weekdays::_Denotation() const {
   if(strDenotation) [[likely]] return strDenotation.value();
   else throw std::runtime_error("value for attribute \"Denotation\" in class \"TWD_Weekdays\" is empty.");;
   }

inline std::string const& TWD_Weekdays::_Abbreviation() const {
   if(strAbbreviation) [[likely]] return strAbbreviation.value();
   else throw std::runtime_error("value for attribute \"Abbreviation\" in class \"TWD_Weekdays\" is empty.");;
   }

inline bool TWD_Weekdays::_Workday() const {
   if(boWorkday) [[likely]] return boWorkday.value();
   else throw std::runtime_error("value for attribute \"Workday\" in class \"TWD_Weekdays\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TWD_Weekdays::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TWD_Weekdays::Denotation(std::optional<std::string> const& newVal) {
   return strDenotation = newVal;
   }

inline std::optional<std::string> const& TWD_Weekdays::Abbreviation(std::optional<std::string> const& newVal) {
   return strAbbreviation = newVal;
   }

inline std::optional<bool> const& TWD_Weekdays::Workday(std::optional<bool> const& newVal) {
   return boWorkday = newVal;
   }

} // end of namespace myHR
