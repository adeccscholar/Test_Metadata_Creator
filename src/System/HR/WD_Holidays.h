// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TWD_Holidays
* Content: entities with public holidays, in relation to working days table to determine non working days
* Date: 22.04.2025 22:26:56,675  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for common  virtual base class
#include "Base\BaseClass.h"

// necessary additional headers for used datatypes
#include <chrono>
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

namespace myHR {

// -------------------------------------------------------------------------------------------------
// definition of the system class TWD_Holidays for
// - entities with public holidays, in relation to working days table to determine non working days
// -------------------------------------------------------------------------------------------------
class TWD_Holidays : virtual public myCorporate::TSimplePersonBase {
   friend class reader::DataAccess;   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TWD_Holidays;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            std::chrono::year_month_day daCalendarDay; 

            primary_key();
         public:
            /* explicit */primary_key(std::chrono::year_month_day pCalendarDay);
            explicit primary_key(TWD_Holidays const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TWD_Holidays() const;

            // relational operators of the primary type class
            bool operator == (primary_key const& other) const { return _compare(other) == 0; }
            bool operator != (primary_key const& other) const { return _compare(other) != 0; }
            bool operator <  (primary_key const& other) const { return _compare(other) <  0; }
            bool operator <= (primary_key const& other) const { return _compare(other) <= 0; }
            bool operator >  (primary_key const& other) const { return _compare(other) >  0; }
            bool operator >= (primary_key const& other) const { return _compare(other) >= 0; }

            // selectors the primary type class
            std::chrono::year_month_day        CalendarDay() const { return daCalendarDay; }

            // manipulators the primary type class
            std::chrono::year_month_day        CalendarDay(std::chrono::year_month_day newVal) { return daCalendarDay = newVal; }

            // method to write elements of the primary key type class to a stream
            std::ostream& write(std::ostream& out) const;

         private:
            int _compare(primary_key const& other) const;
         };

      using func_ty = std::function<bool(TWD_Holidays&&)>;
      using container_ty = std::map<primary_key, TWD_Holidays>;
      using vector_ty    = std::vector<TWD_Holidays>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table WD_Holidays
      // ----------------------------------------------------------------------------------------------
      std::optional<std::chrono::year_month_day> daCalendarDay; 
      std::optional<std::string>                 strDonation;   
      std::optional<int>                         iShare;        
      std::optional<std::string>                 strDescription;

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TWD_Holidays();
      TWD_Holidays(TWD_Holidays const&);
      TWD_Holidays(TWD_Holidays &&) noexcept;
      explicit TWD_Holidays(primary_key const&);
      virtual ~TWD_Holidays();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TWD_Holidays& operator = (TWD_Holidays const&);
      TWD_Holidays& operator = (TWD_Holidays&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TWD_Holidays& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TWD_Holidays& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<std::chrono::year_month_day> const& CalendarDay() const { return daCalendarDay; }
      std::optional<std::string> const&                 Donation() const { return strDonation; }
      std::optional<int> const&                         Share() const { return iShare; }
      std::optional<std::string> const&                 Description() const { return strDescription; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      std::chrono::year_month_day                       _CalendarDay() const;
      std::string const&                                _Donation() const;
      int                                               _Share() const;
      std::string const&                                _Description() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<std::chrono::year_month_day> const& CalendarDay(std::optional<std::chrono::year_month_day> const& newVal);
      std::optional<std::string> const&                 Donation(std::optional<std::string> const& newVal);
      std::optional<int> const&                         Share(std::optional<int> const& newVal);
      std::optional<std::string> const&                 Description(std::optional<std::string> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TWD_Holidays& rhs) noexcept;
      void _init();
      void _copy(TWD_Holidays const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline std::chrono::year_month_day TWD_Holidays::_CalendarDay() const {
   if(daCalendarDay) [[likely]] return daCalendarDay.value();
   else throw std::runtime_error("value for attribute \"CalendarDay\" in class \"TWD_Holidays\" is empty.");;
   }

inline std::string const& TWD_Holidays::_Donation() const {
   if(strDonation) [[likely]] return strDonation.value();
   else throw std::runtime_error("value for attribute \"Donation\" in class \"TWD_Holidays\" is empty.");;
   }

inline int TWD_Holidays::_Share() const {
   if(iShare) [[likely]] return iShare.value();
   else throw std::runtime_error("value for attribute \"Share\" in class \"TWD_Holidays\" is empty.");;
   }

inline std::string const& TWD_Holidays::_Description() const {
   if(strDescription) [[likely]] return strDescription.value();
   else throw std::runtime_error("value for attribute \"Description\" in class \"TWD_Holidays\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<std::chrono::year_month_day> const& TWD_Holidays::CalendarDay(std::optional<std::chrono::year_month_day> const& newVal) {
   return daCalendarDay = newVal;
   }

inline std::optional<std::string> const& TWD_Holidays::Donation(std::optional<std::string> const& newVal) {
   return strDonation = newVal;
   }

inline std::optional<int> const& TWD_Holidays::Share(std::optional<int> const& newVal) {
   return iShare = newVal;
   }

inline std::optional<std::string> const& TWD_Holidays::Description(std::optional<std::string> const& newVal) {
   return strDescription = newVal;
   }

} // end of namespace myHR
