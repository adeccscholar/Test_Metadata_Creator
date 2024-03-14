// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TWorkingTime
* Content: entity with the working times for an employee, as a composition for these.
* Date: 14.03.2024 23:56:54,395  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for common  virtual base class
#include "System\Corporate\base.h"

// necessary additional headers for used datatypes
#include <chrono>

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
// definition of the system class TWorkingTime for
// - entity with the working times for an employee, as a composition for these.
// -------------------------------------------------------------------------------------------------
class TWorkingTime : virtual public myCorporate::TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TWorkingTime;
         private:
            int                                   iID;           
            std::chrono::system_clock::time_point dtStartingTime;

            constexpr primary_key() : iID {}, dtStartingTime {} { }
         public:
            constexpr primary_key(int pID, std::chrono::system_clock::time_point pStartingTime) : iID(pID), dtStartingTime(pStartingTime) { }
            primary_key(TWorkingTime const& other) : iID(other._ID()), dtStartingTime(other._StartingTime()) { }
            constexpr primary_key(primary_key const& other) : iID(other.iID), dtStartingTime(other.dtStartingTime) { }
            constexpr primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)), dtStartingTime(std::move(other.dtStartingTime)) { }
            constexpr ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TWorkingTime() const {
               TWorkingTime ret;
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
            int                                          ID() const { return iID; }
            std::chrono::system_clock::time_point        StartingTime() const { return dtStartingTime; }

            // manipulators the primary type class
            int                                          ID(int newVal) { return iID = newVal; }
            std::chrono::system_clock::time_point        StartingTime(std::chrono::system_clock::time_point newVal) { return dtStartingTime = newVal; }

         private:
            int _compare(primary_key const& other) const {
               static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
                  return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
                  };
               if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
               if(auto ret = comp_help(this->dtStartingTime, other.dtStartingTime); ret != 0) return ret;
               return 0;
               }
         };

      using container_ty = std::map<primary_key, TWorkingTime>;
      using vector_ty    = std::vector<TWorkingTime>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table WorkingTime
      // ----------------------------------------------------------------------------------------------
      std::optional<int>                                   iID;           
      std::optional<std::chrono::system_clock::time_point> dtStartingTime;
      std::optional<std::chrono::system_clock::time_point> dtClosingTime; 
      std::optional<bool>                                  boProcessed;   
      std::optional<std::chrono::system_clock::time_point> dtProcessedAt; 
      std::optional<std::chrono::year_month_day>           daDayOfWork;   

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TWorkingTime();
      TWorkingTime(TWorkingTime const&);
      TWorkingTime(TWorkingTime &&) noexcept;
      virtual ~TWorkingTime();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TWorkingTime& operator = (TWorkingTime const&);
      TWorkingTime& operator = (TWorkingTime&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TWorkingTime& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TWorkingTime& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&                                   ID() const { return iID; }
      std::optional<std::chrono::system_clock::time_point> const& StartingTime() const { return dtStartingTime; }
      std::optional<std::chrono::system_clock::time_point> const& ClosingTime() const { return dtClosingTime; }
      std::optional<bool> const&                                  Processed() const { return boProcessed; }
      std::optional<std::chrono::system_clock::time_point> const& ProcessedAt() const { return dtProcessedAt; }
      std::optional<std::chrono::year_month_day> const&           DayOfWork() const { return daDayOfWork; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                                                         _ID() const;
      std::chrono::system_clock::time_point                       _StartingTime() const;
      std::chrono::system_clock::time_point                       _ClosingTime() const;
      bool                                                        _Processed() const;
      std::chrono::system_clock::time_point                       _ProcessedAt() const;
      std::chrono::year_month_day                                 _DayOfWork() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&                                   ID(std::optional<int> const& newVal);
      std::optional<std::chrono::system_clock::time_point> const& StartingTime(std::optional<std::chrono::system_clock::time_point> const& newVal);
      std::optional<std::chrono::system_clock::time_point> const& ClosingTime(std::optional<std::chrono::system_clock::time_point> const& newVal);
      std::optional<bool> const&                                  Processed(std::optional<bool> const& newVal);
      std::optional<std::chrono::system_clock::time_point> const& ProcessedAt(std::optional<std::chrono::system_clock::time_point> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // private  manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<std::chrono::year_month_day> const&           DayOfWork(std::optional<std::chrono::year_month_day> const& newVal);

      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TWorkingTime& rhs) noexcept;
      void _init();
      void _copy(TWorkingTime const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TWorkingTime::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TWorkingTime\" is empty.");;
   }

inline std::chrono::system_clock::time_point TWorkingTime::_StartingTime() const {
   if(dtStartingTime) [[likely]] return dtStartingTime.value();
   else throw std::runtime_error("value for attribute \"StartingTime\" in class \"TWorkingTime\" is empty.");;
   }

inline std::chrono::system_clock::time_point TWorkingTime::_ClosingTime() const {
   if(dtClosingTime) [[likely]] return dtClosingTime.value();
   else throw std::runtime_error("value for attribute \"ClosingTime\" in class \"TWorkingTime\" is empty.");;
   }

inline bool TWorkingTime::_Processed() const {
   if(boProcessed) [[likely]] return boProcessed.value();
   else throw std::runtime_error("value for attribute \"Processed\" in class \"TWorkingTime\" is empty.");;
   }

inline std::chrono::system_clock::time_point TWorkingTime::_ProcessedAt() const {
   if(dtProcessedAt) [[likely]] return dtProcessedAt.value();
   else throw std::runtime_error("value for attribute \"ProcessedAt\" in class \"TWorkingTime\" is empty.");;
   }

inline std::chrono::year_month_day TWorkingTime::_DayOfWork() const {
   if(daDayOfWork) [[likely]] return daDayOfWork.value();
   else throw std::runtime_error("value for attribute \"DayOfWork\" in class \"TWorkingTime\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TWorkingTime::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::chrono::system_clock::time_point> const& TWorkingTime::StartingTime(std::optional<std::chrono::system_clock::time_point> const& newVal) {
   return dtStartingTime = newVal;
   }

inline std::optional<std::chrono::system_clock::time_point> const& TWorkingTime::ClosingTime(std::optional<std::chrono::system_clock::time_point> const& newVal) {
   return dtClosingTime = newVal;
   }

inline std::optional<bool> const& TWorkingTime::Processed(std::optional<bool> const& newVal) {
   return boProcessed = newVal;
   }

inline std::optional<std::chrono::system_clock::time_point> const& TWorkingTime::ProcessedAt(std::optional<std::chrono::system_clock::time_point> const& newVal) {
   return dtProcessedAt = newVal;
   }

inline std::optional<std::chrono::year_month_day> const& TWorkingTime::DayOfWork(std::optional<std::chrono::year_month_day> const& newVal) {
   return daDayOfWork = newVal;
   }

} // end of namespace myHR
