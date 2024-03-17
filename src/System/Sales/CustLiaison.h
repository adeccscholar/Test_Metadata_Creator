// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TCustLiaison
* Content: doman range with the liaisons to use a contact at a customer
* Date: 17.03.2024 20:08:19,931  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for common  virtual base class
#include "System\Corporate\base.h"

// necessary additional headers for used datatypes
#include <string>

#include <optional>
#include <stdexcept>
#include <map>
#include <vector>
#include <tuple>
#include <memory>

namespace reader {
   class TPersonReader;
   }

namespace mySales {

// -------------------------------------------------------------------------------------------------
// definition of the system class TCustLiaison for
// - doman range with the liaisons to use a contact at a customer
// -------------------------------------------------------------------------------------------------
class TCustLiaison : virtual public myCorporate::TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TCustLiaison;
         private:
            int iID;            

            constexpr primary_key() : iID {} { }
         public:
            constexpr primary_key(int pID) : iID(pID) { }
            primary_key(TCustLiaison const& other) : iID(other._ID()) { }
            constexpr primary_key(primary_key const& other) : iID(other.iID) { }
            constexpr primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }
            constexpr ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TCustLiaison() const {
               TCustLiaison ret;
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
            int        ID() const { return iID; }

            // manipulators the primary type class
            int        ID(int newVal) { return iID = newVal; }

         private:
            int _compare(primary_key const& other) const {
               static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
                  return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
                  };
               if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
               return 0;
               }
         };

      using container_ty = std::map<primary_key, TCustLiaison>;
      using vector_ty    = std::vector<TCustLiaison>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table CustLiaison
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
      TCustLiaison();
      TCustLiaison(TCustLiaison const&);
      TCustLiaison(TCustLiaison &&) noexcept;
      virtual ~TCustLiaison();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TCustLiaison& operator = (TCustLiaison const&);
      TCustLiaison& operator = (TCustLiaison&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TCustLiaison& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TCustLiaison& init(primary_key const&);

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
      void _swap(TCustLiaison& rhs) noexcept;
      void _init();
      void _copy(TCustLiaison const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TCustLiaison::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TCustLiaison\" is empty.");;
   }

inline std::string const& TCustLiaison::_Denotation() const {
   if(strDenotation) [[likely]] return strDenotation.value();
   else throw std::runtime_error("value for attribute \"Denotation\" in class \"TCustLiaison\" is empty.");;
   }

inline std::string const& TCustLiaison::_Abbreviation() const {
   if(strAbbreviation) [[likely]] return strAbbreviation.value();
   else throw std::runtime_error("value for attribute \"Abbreviation\" in class \"TCustLiaison\" is empty.");;
   }

inline std::string const& TCustLiaison::_Description() const {
   if(strDescription) [[likely]] return strDescription.value();
   else throw std::runtime_error("value for attribute \"Description\" in class \"TCustLiaison\" is empty.");;
   }

inline std::string const& TCustLiaison::_Notes() const {
   if(strNotes) [[likely]] return strNotes.value();
   else throw std::runtime_error("value for attribute \"Notes\" in class \"TCustLiaison\" is empty.");;
   }

inline bool TCustLiaison::_UrgentValue() const {
   if(boUrgentValue) [[likely]] return boUrgentValue.value();
   else throw std::runtime_error("value for attribute \"UrgentValue\" in class \"TCustLiaison\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TCustLiaison::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TCustLiaison::Denotation(std::optional<std::string> const& newVal) {
   return strDenotation = newVal;
   }

inline std::optional<std::string> const& TCustLiaison::Abbreviation(std::optional<std::string> const& newVal) {
   return strAbbreviation = newVal;
   }

inline std::optional<std::string> const& TCustLiaison::Description(std::optional<std::string> const& newVal) {
   return strDescription = newVal;
   }

inline std::optional<std::string> const& TCustLiaison::Notes(std::optional<std::string> const& newVal) {
   return strNotes = newVal;
   }

inline std::optional<bool> const& TCustLiaison::UrgentValue(std::optional<bool> const& newVal) {
   return boUrgentValue = newVal;
   }

} // end of namespace mySales
