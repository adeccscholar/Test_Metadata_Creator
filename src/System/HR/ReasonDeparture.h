// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TReasonDeparture
* Content: domain / range with the reasons of departure of the employee
* Date: 22.04.2025 22:26:56,412  file created with adecc Scholar metadata generator
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

namespace myHR {

// -------------------------------------------------------------------------------------------------
// definition of the system class TReasonDeparture for
// - domain / range with the reasons of departure of the employee
// -------------------------------------------------------------------------------------------------
class TReasonDeparture : virtual public myCorporate::TSimplePersonBase {
   friend class reader::DataAccess;   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TReasonDeparture;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iID;            

            primary_key();
         public:
            /* explicit */primary_key(int pID);
            explicit primary_key(TReasonDeparture const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TReasonDeparture() const;

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

      using func_ty = std::function<bool(TReasonDeparture&&)>;
      using container_ty = std::map<primary_key, TReasonDeparture>;
      using vector_ty    = std::vector<TReasonDeparture>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table ReasonDeparture
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;            
      std::optional<std::string> strDenotation;  
      std::optional<std::string> strAbbreviation;
      std::optional<std::string> strDescription; 
      std::optional<std::string> strNotes;       
      std::optional<bool>        boUrgentValue;  

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TReasonDeparture();
      TReasonDeparture(TReasonDeparture const&);
      TReasonDeparture(TReasonDeparture &&) noexcept;
      explicit TReasonDeparture(primary_key const&);
      virtual ~TReasonDeparture();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TReasonDeparture& operator = (TReasonDeparture const&);
      TReasonDeparture& operator = (TReasonDeparture&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TReasonDeparture& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TReasonDeparture& init(primary_key const&);

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
      std::optional<std::string> const& Notes() const { return strNotes; }
      std::optional<bool> const&        UrgentValue() const { return boUrgentValue; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      std::string const&                _Denotation() const;
      std::string const&                _Abbreviation() const;
      std::string const&                _Description() const;
      std::string const&                _Notes() const;
      bool                              _UrgentValue() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<std::string> const& Denotation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Abbreviation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Description(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Notes(std::optional<std::string> const& newVal);
      std::optional<bool> const&        UrgentValue(std::optional<bool> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TReasonDeparture& rhs) noexcept;
      void _init();
      void _copy(TReasonDeparture const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TReasonDeparture::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TReasonDeparture\" is empty.");;
   }

inline std::string const& TReasonDeparture::_Denotation() const {
   if(strDenotation) [[likely]] return strDenotation.value();
   else throw std::runtime_error("value for attribute \"Denotation\" in class \"TReasonDeparture\" is empty.");;
   }

inline std::string const& TReasonDeparture::_Abbreviation() const {
   if(strAbbreviation) [[likely]] return strAbbreviation.value();
   else throw std::runtime_error("value for attribute \"Abbreviation\" in class \"TReasonDeparture\" is empty.");;
   }

inline std::string const& TReasonDeparture::_Description() const {
   if(strDescription) [[likely]] return strDescription.value();
   else throw std::runtime_error("value for attribute \"Description\" in class \"TReasonDeparture\" is empty.");;
   }

inline std::string const& TReasonDeparture::_Notes() const {
   if(strNotes) [[likely]] return strNotes.value();
   else throw std::runtime_error("value for attribute \"Notes\" in class \"TReasonDeparture\" is empty.");;
   }

inline bool TReasonDeparture::_UrgentValue() const {
   if(boUrgentValue) [[likely]] return boUrgentValue.value();
   else throw std::runtime_error("value for attribute \"UrgentValue\" in class \"TReasonDeparture\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TReasonDeparture::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TReasonDeparture::Denotation(std::optional<std::string> const& newVal) {
   return strDenotation = newVal;
   }

inline std::optional<std::string> const& TReasonDeparture::Abbreviation(std::optional<std::string> const& newVal) {
   return strAbbreviation = newVal;
   }

inline std::optional<std::string> const& TReasonDeparture::Description(std::optional<std::string> const& newVal) {
   return strDescription = newVal;
   }

inline std::optional<std::string> const& TReasonDeparture::Notes(std::optional<std::string> const& newVal) {
   return strNotes = newVal;
   }

inline std::optional<bool> const& TReasonDeparture::UrgentValue(std::optional<bool> const& newVal) {
   return boUrgentValue = newVal;
   }

} // end of namespace myHR
