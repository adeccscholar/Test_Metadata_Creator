// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TPhonesTypes
* Content: domain / range of values for phone types, this is an extension of the relationship between persons and phone.
* Date: 22.04.2025 22:26:56,357  file created with adecc Scholar metadata generator
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
// definition of the system class TPhonesTypes for
// - domain / range of values for phone types, this is an extension of the relationship between persons and phone.
// -------------------------------------------------------------------------------------------------
class TPhonesTypes : virtual public TSimplePersonBase {
   friend class reader::DataAccess;   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TPhonesTypes;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iID;            

            primary_key();
         public:
            /* explicit */primary_key(int pID);
            explicit primary_key(TPhonesTypes const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TPhonesTypes() const;

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

      using func_ty = std::function<bool(TPhonesTypes&&)>;
      using container_ty = std::map<primary_key, TPhonesTypes>;
      using vector_ty    = std::vector<TPhonesTypes>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table PhoneTypes
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
      TPhonesTypes();
      TPhonesTypes(TPhonesTypes const&);
      TPhonesTypes(TPhonesTypes &&) noexcept;
      explicit TPhonesTypes(primary_key const&);
      virtual ~TPhonesTypes();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TPhonesTypes& operator = (TPhonesTypes const&);
      TPhonesTypes& operator = (TPhonesTypes&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TPhonesTypes& rhs) noexcept;
      virtual void init() override;
      virtual void copy(TSimplePersonBase const& other) override;

      TPhonesTypes& init(primary_key const&);

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
      void _swap(TPhonesTypes& rhs) noexcept;
      void _init();
      void _copy(TPhonesTypes const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TPhonesTypes::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TPhonesTypes\" is empty.");;
   }

inline std::string const& TPhonesTypes::_Denotation() const {
   if(strDenotation) [[likely]] return strDenotation.value();
   else throw std::runtime_error("value for attribute \"Denotation\" in class \"TPhonesTypes\" is empty.");;
   }

inline std::string const& TPhonesTypes::_Abbreviation() const {
   if(strAbbreviation) [[likely]] return strAbbreviation.value();
   else throw std::runtime_error("value for attribute \"Abbreviation\" in class \"TPhonesTypes\" is empty.");;
   }

inline std::string const& TPhonesTypes::_Description() const {
   if(strDescription) [[likely]] return strDescription.value();
   else throw std::runtime_error("value for attribute \"Description\" in class \"TPhonesTypes\" is empty.");;
   }

inline std::string const& TPhonesTypes::_Notes() const {
   if(strNotes) [[likely]] return strNotes.value();
   else throw std::runtime_error("value for attribute \"Notes\" in class \"TPhonesTypes\" is empty.");;
   }

inline bool TPhonesTypes::_UrgentValue() const {
   if(boUrgentValue) [[likely]] return boUrgentValue.value();
   else throw std::runtime_error("value for attribute \"UrgentValue\" in class \"TPhonesTypes\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TPhonesTypes::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TPhonesTypes::Denotation(std::optional<std::string> const& newVal) {
   return strDenotation = newVal;
   }

inline std::optional<std::string> const& TPhonesTypes::Abbreviation(std::optional<std::string> const& newVal) {
   return strAbbreviation = newVal;
   }

inline std::optional<std::string> const& TPhonesTypes::Description(std::optional<std::string> const& newVal) {
   return strDescription = newVal;
   }

inline std::optional<std::string> const& TPhonesTypes::Notes(std::optional<std::string> const& newVal) {
   return strNotes = newVal;
   }

inline std::optional<bool> const& TPhonesTypes::UrgentValue(std::optional<bool> const& newVal) {
   return boUrgentValue = newVal;
   }

} // end of namespace myCorporate
