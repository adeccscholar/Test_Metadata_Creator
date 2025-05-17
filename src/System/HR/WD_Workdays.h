// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TWD_Workdays
* Content: domain with all days, additional informations and as owner of all recorded working time and non-working times
* Date: 22.04.2025 22:26:56,878  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for common  virtual base class
#include "Base\BaseClass.h"

// necessary additional headers for used datatypes
#include <chrono>

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
// definition of the system class TWD_Workdays for
// - domain with all days, additional informations and as owner of all recorded working time and non-working times
// -------------------------------------------------------------------------------------------------
class TWD_Workdays : virtual public myCorporate::TSimplePersonBase {
   friend class reader::DataAccess;   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TWD_Workdays;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            std::chrono::year_month_day daCalendarDay;     

            primary_key();
         public:
            /* explicit */primary_key(std::chrono::year_month_day pCalendarDay);
            explicit primary_key(TWD_Workdays const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TWD_Workdays() const;

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

      using func_ty = std::function<bool(TWD_Workdays&&)>;
      using container_ty = std::map<primary_key, TWD_Workdays>;
      using vector_ty    = std::vector<TWD_Workdays>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table WD_Workdays
      // ----------------------------------------------------------------------------------------------
      std::optional<std::chrono::year_month_day> daCalendarDay;     
      std::optional<int>                         iCalendarWeekday;  
      std::optional<int>                         iCalendarWeek;     
      std::optional<int>                         iCalendarYear;     
      std::optional<int>                         iCalendarMonth;    
      std::optional<int>                         iCalendarDayInWeek;
      std::optional<int>                         iCalendarDayInYear;
      std::optional<int>                         iCalendarQuarter;  
      std::optional<bool>                        boWorkday;         

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TWD_Workdays();
      TWD_Workdays(TWD_Workdays const&);
      TWD_Workdays(TWD_Workdays &&) noexcept;
      explicit TWD_Workdays(primary_key const&);
      virtual ~TWD_Workdays();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TWD_Workdays& operator = (TWD_Workdays const&);
      TWD_Workdays& operator = (TWD_Workdays&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TWD_Workdays& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TWD_Workdays& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<std::chrono::year_month_day> const& CalendarDay() const { return daCalendarDay; }
      std::optional<int> const&                         CalendarWeekday() const { return iCalendarWeekday; }
      std::optional<int> const&                         CalendarWeek() const { return iCalendarWeek; }
      std::optional<int> const&                         CalendarYear() const { return iCalendarYear; }
      std::optional<int> const&                         CalendarMonth() const { return iCalendarMonth; }
      std::optional<int> const&                         CalendarDayInWeek() const { return iCalendarDayInWeek; }
      std::optional<int> const&                         CalendarDayInYear() const { return iCalendarDayInYear; }
      std::optional<int> const&                         CalendarQuarter() const { return iCalendarQuarter; }
      std::optional<bool> const&                        Workday() const { return boWorkday; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      std::chrono::year_month_day                       _CalendarDay() const;
      int                                               _CalendarWeekday() const;
      int                                               _CalendarWeek() const;
      int                                               _CalendarYear() const;
      int                                               _CalendarMonth() const;
      int                                               _CalendarDayInWeek() const;
      int                                               _CalendarDayInYear() const;
      int                                               _CalendarQuarter() const;
      bool                                              _Workday() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<std::chrono::year_month_day> const& CalendarDay(std::optional<std::chrono::year_month_day> const& newVal);
      std::optional<int> const&                         CalendarWeekday(std::optional<int> const& newVal);
      std::optional<int> const&                         CalendarWeek(std::optional<int> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // private  manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&                         CalendarYear(std::optional<int> const& newVal);
      std::optional<int> const&                         CalendarMonth(std::optional<int> const& newVal);
      std::optional<int> const&                         CalendarDayInWeek(std::optional<int> const& newVal);
      std::optional<int> const&                         CalendarDayInYear(std::optional<int> const& newVal);
      std::optional<int> const&                         CalendarQuarter(std::optional<int> const& newVal);
      std::optional<bool> const&                        Workday(std::optional<bool> const& newVal);

      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TWD_Workdays& rhs) noexcept;
      void _init();
      void _copy(TWD_Workdays const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline std::chrono::year_month_day TWD_Workdays::_CalendarDay() const {
   if(daCalendarDay) [[likely]] return daCalendarDay.value();
   else throw std::runtime_error("value for attribute \"CalendarDay\" in class \"TWD_Workdays\" is empty.");;
   }

inline int TWD_Workdays::_CalendarWeekday() const {
   if(iCalendarWeekday) [[likely]] return iCalendarWeekday.value();
   else throw std::runtime_error("value for attribute \"CalendarWeekday\" in class \"TWD_Workdays\" is empty.");;
   }

inline int TWD_Workdays::_CalendarWeek() const {
   if(iCalendarWeek) [[likely]] return iCalendarWeek.value();
   else throw std::runtime_error("value for attribute \"CalendarWeek\" in class \"TWD_Workdays\" is empty.");;
   }

inline int TWD_Workdays::_CalendarYear() const {
   if(iCalendarYear) [[likely]] return iCalendarYear.value();
   else throw std::runtime_error("value for attribute \"CalendarYear\" in class \"TWD_Workdays\" is empty.");;
   }

inline int TWD_Workdays::_CalendarMonth() const {
   if(iCalendarMonth) [[likely]] return iCalendarMonth.value();
   else throw std::runtime_error("value for attribute \"CalendarMonth\" in class \"TWD_Workdays\" is empty.");;
   }

inline int TWD_Workdays::_CalendarDayInWeek() const {
   if(iCalendarDayInWeek) [[likely]] return iCalendarDayInWeek.value();
   else throw std::runtime_error("value for attribute \"CalendarDayInWeek\" in class \"TWD_Workdays\" is empty.");;
   }

inline int TWD_Workdays::_CalendarDayInYear() const {
   if(iCalendarDayInYear) [[likely]] return iCalendarDayInYear.value();
   else throw std::runtime_error("value for attribute \"CalendarDayInYear\" in class \"TWD_Workdays\" is empty.");;
   }

inline int TWD_Workdays::_CalendarQuarter() const {
   if(iCalendarQuarter) [[likely]] return iCalendarQuarter.value();
   else throw std::runtime_error("value for attribute \"CalendarQuarter\" in class \"TWD_Workdays\" is empty.");;
   }

inline bool TWD_Workdays::_Workday() const {
   if(boWorkday) [[likely]] return boWorkday.value();
   else throw std::runtime_error("value for attribute \"Workday\" in class \"TWD_Workdays\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<std::chrono::year_month_day> const& TWD_Workdays::CalendarDay(std::optional<std::chrono::year_month_day> const& newVal) {
   return daCalendarDay = newVal;
   }

inline std::optional<int> const& TWD_Workdays::CalendarWeekday(std::optional<int> const& newVal) {
   return iCalendarWeekday = newVal;
   }

inline std::optional<int> const& TWD_Workdays::CalendarWeek(std::optional<int> const& newVal) {
   return iCalendarWeek = newVal;
   }

inline std::optional<int> const& TWD_Workdays::CalendarYear(std::optional<int> const& newVal) {
   return iCalendarYear = newVal;
   }

inline std::optional<int> const& TWD_Workdays::CalendarMonth(std::optional<int> const& newVal) {
   return iCalendarMonth = newVal;
   }

inline std::optional<int> const& TWD_Workdays::CalendarDayInWeek(std::optional<int> const& newVal) {
   return iCalendarDayInWeek = newVal;
   }

inline std::optional<int> const& TWD_Workdays::CalendarDayInYear(std::optional<int> const& newVal) {
   return iCalendarDayInYear = newVal;
   }

inline std::optional<int> const& TWD_Workdays::CalendarQuarter(std::optional<int> const& newVal) {
   return iCalendarQuarter = newVal;
   }

inline std::optional<bool> const& TWD_Workdays::Workday(std::optional<bool> const& newVal) {
   return boWorkday = newVal;
   }

} // end of namespace myHR
