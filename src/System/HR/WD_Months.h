// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TWD_Months
* Content: domain with months for human resources, actually used for working time, later for processes too. This range make it possible additional informations to adding later. This isn't a typical range value.
* Date: 22.03.2024 15:39:12,991  file created with adecc Scholar metadata generator
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

namespace myHR {

// -------------------------------------------------------------------------------------------------
// definition of the system class TWD_Months for
// - domain with months for human resources, actually used for working time, later for processes too. This range make it possible additional informations to adding later. This isn't a typical range value.
// -------------------------------------------------------------------------------------------------
class TWD_Months : virtual public myCorporate::TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TWD_Months;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iID;            

            primary_key();
         public:
            explicit primary_key(int pID);
            explicit primary_key(TWD_Months const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TWD_Months() const;

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

      using container_ty = std::map<primary_key, TWD_Months>;
      using vector_ty    = std::vector<TWD_Months>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table WD_Months
      // ----------------------------------------------------------------------------------------------
      std::optional<int>          iID;            
      std::optional<std::string>  strDenotation;  
      std::optional<std::string>  strAbbreviation;
      std::optional<unsigned int> uQuarter;       

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TWD_Months();
      TWD_Months(TWD_Months const&);
      TWD_Months(TWD_Months &&) noexcept;
      explicit TWD_Months(primary_key const&);
      virtual ~TWD_Months();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TWD_Months& operator = (TWD_Months const&);
      TWD_Months& operator = (TWD_Months&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TWD_Months& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TWD_Months& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&          ID() const { return iID; }
      std::optional<std::string> const&  Denotation() const { return strDenotation; }
      std::optional<std::string> const&  Abbreviation() const { return strAbbreviation; }
      std::optional<unsigned int> const& Quarter() const { return uQuarter; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                                _ID() const;
      std::string const&                 _Denotation() const;
      std::string const&                 _Abbreviation() const;
      unsigned int                       _Quarter() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&          ID(std::optional<int> const& newVal);
      std::optional<std::string> const&  Denotation(std::optional<std::string> const& newVal);
      std::optional<std::string> const&  Abbreviation(std::optional<std::string> const& newVal);
      std::optional<unsigned int> const& Quarter(std::optional<unsigned int> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TWD_Months& rhs) noexcept;
      void _init();
      void _copy(TWD_Months const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TWD_Months::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TWD_Months\" is empty.");;
   }

inline std::string const& TWD_Months::_Denotation() const {
   if(strDenotation) [[likely]] return strDenotation.value();
   else throw std::runtime_error("value for attribute \"Denotation\" in class \"TWD_Months\" is empty.");;
   }

inline std::string const& TWD_Months::_Abbreviation() const {
   if(strAbbreviation) [[likely]] return strAbbreviation.value();
   else throw std::runtime_error("value for attribute \"Abbreviation\" in class \"TWD_Months\" is empty.");;
   }

inline unsigned int TWD_Months::_Quarter() const {
   if(uQuarter) [[likely]] return uQuarter.value();
   else throw std::runtime_error("value for attribute \"Quarter\" in class \"TWD_Months\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TWD_Months::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TWD_Months::Denotation(std::optional<std::string> const& newVal) {
   return strDenotation = newVal;
   }

inline std::optional<std::string> const& TWD_Months::Abbreviation(std::optional<std::string> const& newVal) {
   return strAbbreviation = newVal;
   }

inline std::optional<unsigned int> const& TWD_Months::Quarter(std::optional<unsigned int> const& newVal) {
   return uQuarter = newVal;
   }

} // end of namespace myHR
