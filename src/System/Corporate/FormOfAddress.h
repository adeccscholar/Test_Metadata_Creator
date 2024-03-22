// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TFormOfAddress
* Content: domain with the possible values for form of addresses with additional informations for this
* Date: 22.03.2024 15:39:12,304  file created with adecc Scholar metadata generator
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
// definition of the system class TFormOfAddress for
// - domain with the possible values for form of addresses with additional informations for this
// -------------------------------------------------------------------------------------------------
class TFormOfAddress : virtual public TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TFormOfAddress;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iID;            

            primary_key();
         public:
            explicit primary_key(int pID);
            explicit primary_key(TFormOfAddress const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TFormOfAddress() const;

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

      using container_ty = std::map<primary_key, TFormOfAddress>;
      using vector_ty    = std::vector<TFormOfAddress>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table FormOfAddress
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;            
      std::optional<std::string> strDenotation;  
      std::optional<std::string> strAbbreviation;
      std::optional<std::string> strDescription; 
      std::optional<int>         iTypeSpec;      
      std::optional<std::string> strSalutation;  
      std::optional<std::string> strValediction; 
      std::optional<std::string> strNotes;       
      std::optional<bool>        boUrgentValue;  

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TFormOfAddress();
      TFormOfAddress(TFormOfAddress const&);
      TFormOfAddress(TFormOfAddress &&) noexcept;
      explicit TFormOfAddress(primary_key const&);
      virtual ~TFormOfAddress();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TFormOfAddress& operator = (TFormOfAddress const&);
      TFormOfAddress& operator = (TFormOfAddress&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TFormOfAddress& rhs) noexcept;
      virtual void init() override;
      virtual void copy(TSimplePersonBase const& other) override;

      TFormOfAddress& init(primary_key const&);

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
      std::optional<int> const&         TypeSpec() const { return iTypeSpec; }
      std::optional<std::string> const& Salutation() const { return strSalutation; }
      std::optional<std::string> const& Valediction() const { return strValediction; }
      std::optional<std::string> const& Notes() const { return strNotes; }
      std::optional<bool> const&        UrgentValue() const { return boUrgentValue; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      std::string const&                _Denotation() const;
      std::string const&                _Abbreviation() const;
      std::string const&                _Description() const;
      int                               _TypeSpec() const;
      std::string const&                _Salutation() const;
      std::string const&                _Valediction() const;
      std::string const&                _Notes() const;
      bool                              _UrgentValue() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<std::string> const& Denotation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Abbreviation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Description(std::optional<std::string> const& newVal);
      std::optional<int> const&         TypeSpec(std::optional<int> const& newVal);
      std::optional<std::string> const& Salutation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Valediction(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Notes(std::optional<std::string> const& newVal);
      std::optional<bool> const&        UrgentValue(std::optional<bool> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TFormOfAddress& rhs) noexcept;
      void _init();
      void _copy(TFormOfAddress const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TFormOfAddress::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TFormOfAddress\" is empty.");;
   }

inline std::string const& TFormOfAddress::_Denotation() const {
   if(strDenotation) [[likely]] return strDenotation.value();
   else throw std::runtime_error("value for attribute \"Denotation\" in class \"TFormOfAddress\" is empty.");;
   }

inline std::string const& TFormOfAddress::_Abbreviation() const {
   if(strAbbreviation) [[likely]] return strAbbreviation.value();
   else throw std::runtime_error("value for attribute \"Abbreviation\" in class \"TFormOfAddress\" is empty.");;
   }

inline std::string const& TFormOfAddress::_Description() const {
   if(strDescription) [[likely]] return strDescription.value();
   else throw std::runtime_error("value for attribute \"Description\" in class \"TFormOfAddress\" is empty.");;
   }

inline int TFormOfAddress::_TypeSpec() const {
   if(iTypeSpec) [[likely]] return iTypeSpec.value();
   else throw std::runtime_error("value for attribute \"TypeSpec\" in class \"TFormOfAddress\" is empty.");;
   }

inline std::string const& TFormOfAddress::_Salutation() const {
   if(strSalutation) [[likely]] return strSalutation.value();
   else throw std::runtime_error("value for attribute \"Salutation\" in class \"TFormOfAddress\" is empty.");;
   }

inline std::string const& TFormOfAddress::_Valediction() const {
   if(strValediction) [[likely]] return strValediction.value();
   else throw std::runtime_error("value for attribute \"Valediction\" in class \"TFormOfAddress\" is empty.");;
   }

inline std::string const& TFormOfAddress::_Notes() const {
   if(strNotes) [[likely]] return strNotes.value();
   else throw std::runtime_error("value for attribute \"Notes\" in class \"TFormOfAddress\" is empty.");;
   }

inline bool TFormOfAddress::_UrgentValue() const {
   if(boUrgentValue) [[likely]] return boUrgentValue.value();
   else throw std::runtime_error("value for attribute \"UrgentValue\" in class \"TFormOfAddress\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TFormOfAddress::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TFormOfAddress::Denotation(std::optional<std::string> const& newVal) {
   return strDenotation = newVal;
   }

inline std::optional<std::string> const& TFormOfAddress::Abbreviation(std::optional<std::string> const& newVal) {
   return strAbbreviation = newVal;
   }

inline std::optional<std::string> const& TFormOfAddress::Description(std::optional<std::string> const& newVal) {
   return strDescription = newVal;
   }

inline std::optional<int> const& TFormOfAddress::TypeSpec(std::optional<int> const& newVal) {
   return iTypeSpec = newVal;
   }

inline std::optional<std::string> const& TFormOfAddress::Salutation(std::optional<std::string> const& newVal) {
   return strSalutation = newVal;
   }

inline std::optional<std::string> const& TFormOfAddress::Valediction(std::optional<std::string> const& newVal) {
   return strValediction = newVal;
   }

inline std::optional<std::string> const& TFormOfAddress::Notes(std::optional<std::string> const& newVal) {
   return strNotes = newVal;
   }

inline std::optional<bool> const& TFormOfAddress::UrgentValue(std::optional<bool> const& newVal) {
   return boUrgentValue = newVal;
   }

} // end of namespace myCorporate
