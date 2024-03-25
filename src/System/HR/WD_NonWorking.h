// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TWD_NonWorking
* Content: entity set with non working days. Extensions possible, responsible for this table is HR.
* Date: 25.03.2024 19:08:41,148  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for common  virtual base class
#include "System\Corporate\base.h"

// necessary additional headers for used datatypes
#include <chrono>
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

namespace myHR {

// -------------------------------------------------------------------------------------------------
// definition of the system class TWD_NonWorking for
// - entity set with non working days. Extensions possible, responsible for this table is HR.
// -------------------------------------------------------------------------------------------------
class TWD_NonWorking : virtual public myCorporate::TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TWD_NonWorking;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int                         iID;        
            std::chrono::year_month_day daStartAt;  

            primary_key();
         public:
            primary_key(int pID, std::chrono::year_month_day pStartAt);
            explicit primary_key(TWD_NonWorking const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TWD_NonWorking() const;

            // relational operators of the primary type class
            bool operator == (primary_key const& other) const { return _compare(other) == 0; }
            bool operator != (primary_key const& other) const { return _compare(other) != 0; }
            bool operator <  (primary_key const& other) const { return _compare(other) <  0; }
            bool operator <= (primary_key const& other) const { return _compare(other) <= 0; }
            bool operator >  (primary_key const& other) const { return _compare(other) >  0; }
            bool operator >= (primary_key const& other) const { return _compare(other) >= 0; }

            // selectors the primary type class
            int                                ID() const { return iID; }
            std::chrono::year_month_day        StartAt() const { return daStartAt; }

            // manipulators the primary type class
            int                                ID(int newVal) { return iID = newVal; }
            std::chrono::year_month_day        StartAt(std::chrono::year_month_day newVal) { return daStartAt = newVal; }

            // method to write elements of the primary key type class to a stream
            std::ostream& write(std::ostream& out) const;

         private:
            int _compare(primary_key const& other) const;
         };

      using container_ty = std::map<primary_key, TWD_NonWorking>;
      using vector_ty    = std::vector<TWD_NonWorking>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table WD_NonWorking
      // ----------------------------------------------------------------------------------------------
      std::optional<int>                         iID;        
      std::optional<std::chrono::year_month_day> daStartAt;  
      std::optional<std::chrono::year_month_day> daClosingAt;
      std::optional<int>                         iReason;    
      std::optional<std::string>                 strNotes;   

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TWD_NonWorking();
      TWD_NonWorking(TWD_NonWorking const&);
      TWD_NonWorking(TWD_NonWorking &&) noexcept;
      explicit TWD_NonWorking(primary_key const&);
      virtual ~TWD_NonWorking();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TWD_NonWorking& operator = (TWD_NonWorking const&);
      TWD_NonWorking& operator = (TWD_NonWorking&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TWD_NonWorking& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TWD_NonWorking& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&                         ID() const { return iID; }
      std::optional<std::chrono::year_month_day> const& StartAt() const { return daStartAt; }
      std::optional<std::chrono::year_month_day> const& ClosingAt() const { return daClosingAt; }
      std::optional<int> const&                         Reason() const { return iReason; }
      std::optional<std::string> const&                 Notes() const { return strNotes; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                                               _ID() const;
      std::chrono::year_month_day                       _StartAt() const;
      std::chrono::year_month_day                       _ClosingAt() const;
      int                                               _Reason() const;
      std::string const&                                _Notes() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&                         ID(std::optional<int> const& newVal);
      std::optional<std::chrono::year_month_day> const& StartAt(std::optional<std::chrono::year_month_day> const& newVal);
      std::optional<std::chrono::year_month_day> const& ClosingAt(std::optional<std::chrono::year_month_day> const& newVal);
      std::optional<int> const&                         Reason(std::optional<int> const& newVal);
      std::optional<std::string> const&                 Notes(std::optional<std::string> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TWD_NonWorking& rhs) noexcept;
      void _init();
      void _copy(TWD_NonWorking const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TWD_NonWorking::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TWD_NonWorking\" is empty.");;
   }

inline std::chrono::year_month_day TWD_NonWorking::_StartAt() const {
   if(daStartAt) [[likely]] return daStartAt.value();
   else throw std::runtime_error("value for attribute \"StartAt\" in class \"TWD_NonWorking\" is empty.");;
   }

inline std::chrono::year_month_day TWD_NonWorking::_ClosingAt() const {
   if(daClosingAt) [[likely]] return daClosingAt.value();
   else throw std::runtime_error("value for attribute \"ClosingAt\" in class \"TWD_NonWorking\" is empty.");;
   }

inline int TWD_NonWorking::_Reason() const {
   if(iReason) [[likely]] return iReason.value();
   else throw std::runtime_error("value for attribute \"Reason\" in class \"TWD_NonWorking\" is empty.");;
   }

inline std::string const& TWD_NonWorking::_Notes() const {
   if(strNotes) [[likely]] return strNotes.value();
   else throw std::runtime_error("value for attribute \"Notes\" in class \"TWD_NonWorking\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TWD_NonWorking::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::chrono::year_month_day> const& TWD_NonWorking::StartAt(std::optional<std::chrono::year_month_day> const& newVal) {
   return daStartAt = newVal;
   }

inline std::optional<std::chrono::year_month_day> const& TWD_NonWorking::ClosingAt(std::optional<std::chrono::year_month_day> const& newVal) {
   return daClosingAt = newVal;
   }

inline std::optional<int> const& TWD_NonWorking::Reason(std::optional<int> const& newVal) {
   return iReason = newVal;
   }

inline std::optional<std::string> const& TWD_NonWorking::Notes(std::optional<std::string> const& newVal) {
   return strNotes = newVal;
   }

} // end of namespace myHR
