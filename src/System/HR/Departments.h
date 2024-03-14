// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TDepartments
* Content: independent entity with the departments in the company, independent identity
* Date: 14.03.2024 23:56:53,261  file created with adecc Scholar metadata generator
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

namespace myHR {

// -------------------------------------------------------------------------------------------------
// definition of the system class TDepartments for
// - independent entity with the departments in the company, independent identity
// -------------------------------------------------------------------------------------------------
class TDepartments : virtual public myCorporate::TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TDepartments;
         private:
            int iID;            

            constexpr primary_key() : iID {} { }
         public:
            constexpr primary_key(int pID) : iID(pID) { }
            primary_key(TDepartments const& other) : iID(other._ID()) { }
            constexpr primary_key(primary_key const& other) : iID(other.iID) { }
            constexpr primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }
            constexpr ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TDepartments() const {
               TDepartments ret;
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

      using container_ty = std::map<primary_key, TDepartments>;
      using vector_ty    = std::vector<TDepartments>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table Departments
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;            
      std::optional<std::string> strDenotation;  
      std::optional<std::string> strAbbreviation;
      std::optional<std::string> strDescription; 
      std::optional<int>         iOfficer;       
      std::optional<std::string> strNotes;       

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TDepartments();
      TDepartments(TDepartments const&);
      TDepartments(TDepartments &&) noexcept;
      virtual ~TDepartments();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TDepartments& operator = (TDepartments const&);
      TDepartments& operator = (TDepartments&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TDepartments& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TDepartments& init(primary_key const&);

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
      std::optional<int> const&         Officer() const { return iOfficer; }
      std::optional<std::string> const& Notes() const { return strNotes; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      std::string const&                _Denotation() const;
      std::string const&                _Abbreviation() const;
      std::string const&                _Description() const;
      int                               _Officer() const;
      std::string const&                _Notes() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<std::string> const& Denotation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Abbreviation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Description(std::optional<std::string> const& newVal);
      std::optional<int> const&         Officer(std::optional<int> const& newVal);
      std::optional<std::string> const& Notes(std::optional<std::string> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TDepartments& rhs) noexcept;
      void _init();
      void _copy(TDepartments const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TDepartments::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TDepartments\" is empty.");;
   }

inline std::string const& TDepartments::_Denotation() const {
   if(strDenotation) [[likely]] return strDenotation.value();
   else throw std::runtime_error("value for attribute \"Denotation\" in class \"TDepartments\" is empty.");;
   }

inline std::string const& TDepartments::_Abbreviation() const {
   if(strAbbreviation) [[likely]] return strAbbreviation.value();
   else throw std::runtime_error("value for attribute \"Abbreviation\" in class \"TDepartments\" is empty.");;
   }

inline std::string const& TDepartments::_Description() const {
   if(strDescription) [[likely]] return strDescription.value();
   else throw std::runtime_error("value for attribute \"Description\" in class \"TDepartments\" is empty.");;
   }

inline int TDepartments::_Officer() const {
   if(iOfficer) [[likely]] return iOfficer.value();
   else throw std::runtime_error("value for attribute \"Officer\" in class \"TDepartments\" is empty.");;
   }

inline std::string const& TDepartments::_Notes() const {
   if(strNotes) [[likely]] return strNotes.value();
   else throw std::runtime_error("value for attribute \"Notes\" in class \"TDepartments\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TDepartments::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TDepartments::Denotation(std::optional<std::string> const& newVal) {
   return strDenotation = newVal;
   }

inline std::optional<std::string> const& TDepartments::Abbreviation(std::optional<std::string> const& newVal) {
   return strAbbreviation = newVal;
   }

inline std::optional<std::string> const& TDepartments::Description(std::optional<std::string> const& newVal) {
   return strDescription = newVal;
   }

inline std::optional<int> const& TDepartments::Officer(std::optional<int> const& newVal) {
   return iOfficer = newVal;
   }

inline std::optional<std::string> const& TDepartments::Notes(std::optional<std::string> const& newVal) {
   return strNotes = newVal;
   }

} // end of namespace myHR
