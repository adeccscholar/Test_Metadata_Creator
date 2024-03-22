// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TCorporateForm
* Content: This table stores information about various types of legal forms. Each row corresponds to a specific legal form with several informations.
* Date: 22.03.2024 15:39:11,767  file created with adecc Scholar metadata generator
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
// definition of the system class TCorporateForm for
// - This table stores information about various types of legal forms. Each row corresponds to a specific legal form with several informations.
// -------------------------------------------------------------------------------------------------
class TCorporateForm : virtual public TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TCorporateForm;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iID;             

            primary_key();
         public:
            explicit primary_key(int pID);
            explicit primary_key(TCorporateForm const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TCorporateForm() const;

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

      using container_ty = std::map<primary_key, TCorporateForm>;
      using vector_ty    = std::vector<TCorporateForm>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table CorporateForm
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;             
      std::optional<std::string> strDenotation;   
      std::optional<std::string> strAbbreviation; 
      std::optional<std::string> strDescription;  
      std::optional<bool>        boIsLegalEntrity;
      std::optional<int>         iUrgentValue;    

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TCorporateForm();
      TCorporateForm(TCorporateForm const&);
      TCorporateForm(TCorporateForm &&) noexcept;
      explicit TCorporateForm(primary_key const&);
      virtual ~TCorporateForm();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TCorporateForm& operator = (TCorporateForm const&);
      TCorporateForm& operator = (TCorporateForm&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TCorporateForm& rhs) noexcept;
      virtual void init() override;
      virtual void copy(TSimplePersonBase const& other) override;

      TCorporateForm& init(primary_key const&);

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
      std::optional<bool> const&        IsLegalEntrity() const { return boIsLegalEntrity; }
      std::optional<int> const&         UrgentValue() const { return iUrgentValue; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      std::string const&                _Denotation() const;
      std::string const&                _Abbreviation() const;
      std::string const&                _Description() const;
      bool                              _IsLegalEntrity() const;
      int                               _UrgentValue() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<std::string> const& Denotation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Abbreviation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Description(std::optional<std::string> const& newVal);
      std::optional<bool> const&        IsLegalEntrity(std::optional<bool> const& newVal);
      std::optional<int> const&         UrgentValue(std::optional<int> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TCorporateForm& rhs) noexcept;
      void _init();
      void _copy(TCorporateForm const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TCorporateForm::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TCorporateForm\" is empty.");;
   }

inline std::string const& TCorporateForm::_Denotation() const {
   if(strDenotation) [[likely]] return strDenotation.value();
   else throw std::runtime_error("value for attribute \"Denotation\" in class \"TCorporateForm\" is empty.");;
   }

inline std::string const& TCorporateForm::_Abbreviation() const {
   if(strAbbreviation) [[likely]] return strAbbreviation.value();
   else throw std::runtime_error("value for attribute \"Abbreviation\" in class \"TCorporateForm\" is empty.");;
   }

inline std::string const& TCorporateForm::_Description() const {
   if(strDescription) [[likely]] return strDescription.value();
   else throw std::runtime_error("value for attribute \"Description\" in class \"TCorporateForm\" is empty.");;
   }

inline bool TCorporateForm::_IsLegalEntrity() const {
   if(boIsLegalEntrity) [[likely]] return boIsLegalEntrity.value();
   else throw std::runtime_error("value for attribute \"IsLegalEntrity\" in class \"TCorporateForm\" is empty.");;
   }

inline int TCorporateForm::_UrgentValue() const {
   if(iUrgentValue) [[likely]] return iUrgentValue.value();
   else throw std::runtime_error("value for attribute \"UrgentValue\" in class \"TCorporateForm\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TCorporateForm::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TCorporateForm::Denotation(std::optional<std::string> const& newVal) {
   return strDenotation = newVal;
   }

inline std::optional<std::string> const& TCorporateForm::Abbreviation(std::optional<std::string> const& newVal) {
   return strAbbreviation = newVal;
   }

inline std::optional<std::string> const& TCorporateForm::Description(std::optional<std::string> const& newVal) {
   return strDescription = newVal;
   }

inline std::optional<bool> const& TCorporateForm::IsLegalEntrity(std::optional<bool> const& newVal) {
   return boIsLegalEntrity = newVal;
   }

inline std::optional<int> const& TCorporateForm::UrgentValue(std::optional<int> const& newVal) {
   return iUrgentValue = newVal;
   }

} // end of namespace myCorporate
