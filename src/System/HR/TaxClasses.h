// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TTaxClasses
* Content: tax class in germany to use it with employees (not a range, but very similar)
* Date: 22.04.2025 22:26:56,626  file created with adecc Scholar metadata generator
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
// definition of the system class TTaxClasses for
// - tax class in germany to use it with employees (not a range, but very similar)
// -------------------------------------------------------------------------------------------------
class TTaxClasses : virtual public myCorporate::TSimplePersonBase {
   friend class reader::DataAccess;   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TTaxClasses;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iID;            

            primary_key();
         public:
            /* explicit */primary_key(int pID);
            explicit primary_key(TTaxClasses const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TTaxClasses() const;

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

      using func_ty = std::function<bool(TTaxClasses&&)>;
      using container_ty = std::map<primary_key, TTaxClasses>;
      using vector_ty    = std::vector<TTaxClasses>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table TaxClasses
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;            
      std::optional<std::string> strDenotation;  
      std::optional<std::string> strAbbreviation;
      std::optional<std::string> strDescription; 
      std::optional<bool>        boCoupled;      
      std::optional<bool>        boUrgentValue;  

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TTaxClasses();
      TTaxClasses(TTaxClasses const&);
      TTaxClasses(TTaxClasses &&) noexcept;
      explicit TTaxClasses(primary_key const&);
      virtual ~TTaxClasses();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TTaxClasses& operator = (TTaxClasses const&);
      TTaxClasses& operator = (TTaxClasses&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TTaxClasses& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TTaxClasses& init(primary_key const&);

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
      std::optional<bool> const&        Coupled() const { return boCoupled; }
      std::optional<bool> const&        UrgentValue() const { return boUrgentValue; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      std::string const&                _Denotation() const;
      std::string const&                _Abbreviation() const;
      std::string const&                _Description() const;
      bool                              _Coupled() const;
      bool                              _UrgentValue() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<std::string> const& Denotation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Abbreviation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Description(std::optional<std::string> const& newVal);
      std::optional<bool> const&        Coupled(std::optional<bool> const& newVal);
      std::optional<bool> const&        UrgentValue(std::optional<bool> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TTaxClasses& rhs) noexcept;
      void _init();
      void _copy(TTaxClasses const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TTaxClasses::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TTaxClasses\" is empty.");;
   }

inline std::string const& TTaxClasses::_Denotation() const {
   if(strDenotation) [[likely]] return strDenotation.value();
   else throw std::runtime_error("value for attribute \"Denotation\" in class \"TTaxClasses\" is empty.");;
   }

inline std::string const& TTaxClasses::_Abbreviation() const {
   if(strAbbreviation) [[likely]] return strAbbreviation.value();
   else throw std::runtime_error("value for attribute \"Abbreviation\" in class \"TTaxClasses\" is empty.");;
   }

inline std::string const& TTaxClasses::_Description() const {
   if(strDescription) [[likely]] return strDescription.value();
   else throw std::runtime_error("value for attribute \"Description\" in class \"TTaxClasses\" is empty.");;
   }

inline bool TTaxClasses::_Coupled() const {
   if(boCoupled) [[likely]] return boCoupled.value();
   else throw std::runtime_error("value for attribute \"Coupled\" in class \"TTaxClasses\" is empty.");;
   }

inline bool TTaxClasses::_UrgentValue() const {
   if(boUrgentValue) [[likely]] return boUrgentValue.value();
   else throw std::runtime_error("value for attribute \"UrgentValue\" in class \"TTaxClasses\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TTaxClasses::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TTaxClasses::Denotation(std::optional<std::string> const& newVal) {
   return strDenotation = newVal;
   }

inline std::optional<std::string> const& TTaxClasses::Abbreviation(std::optional<std::string> const& newVal) {
   return strAbbreviation = newVal;
   }

inline std::optional<std::string> const& TTaxClasses::Description(std::optional<std::string> const& newVal) {
   return strDescription = newVal;
   }

inline std::optional<bool> const& TTaxClasses::Coupled(std::optional<bool> const& newVal) {
   return boCoupled = newVal;
   }

inline std::optional<bool> const& TTaxClasses::UrgentValue(std::optional<bool> const& newVal) {
   return boUrgentValue = newVal;
   }

} // end of namespace myHR
