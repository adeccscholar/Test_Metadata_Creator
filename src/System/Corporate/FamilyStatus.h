// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TFamilyStatus
* Content: domain / range of values for family status, this is used in person to qualifify the actual status, maybe a date needed too
* Date: 17.03.2024 20:08:20,149  file created with adecc Scholar metadata generator
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

namespace myCorporate {

// -------------------------------------------------------------------------------------------------
// definition of the system class TFamilyStatus for
// - domain / range of values for family status, this is used in person to qualifify the actual status, maybe a date needed too
// -------------------------------------------------------------------------------------------------
class TFamilyStatus : virtual public TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TFamilyStatus;
         private:
            int iID;            

            constexpr primary_key() : iID {} { }
         public:
            constexpr primary_key(int pID) : iID(pID) { }
            primary_key(TFamilyStatus const& other) : iID(other._ID()) { }
            constexpr primary_key(primary_key const& other) : iID(other.iID) { }
            constexpr primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }
            constexpr ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TFamilyStatus() const {
               TFamilyStatus ret;
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

      using container_ty = std::map<primary_key, TFamilyStatus>;
      using vector_ty    = std::vector<TFamilyStatus>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table FamilyStatus
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;            
      std::optional<std::string> strDenotation;  
      std::optional<std::string> strAbbreviation;
      std::optional<std::string> strDescription; 
      std::optional<bool>        boCoupled;      
      std::optional<bool>        boNeedDate;     
      std::optional<std::string> strNotes;       
      std::optional<bool>        boUrgentValue;  

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TFamilyStatus();
      TFamilyStatus(TFamilyStatus const&);
      TFamilyStatus(TFamilyStatus &&) noexcept;
      virtual ~TFamilyStatus();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TFamilyStatus& operator = (TFamilyStatus const&);
      TFamilyStatus& operator = (TFamilyStatus&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TFamilyStatus& rhs) noexcept;
      virtual void init() override;
      virtual void copy(TSimplePersonBase const& other) override;

      TFamilyStatus& init(primary_key const&);

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
      std::optional<bool> const&        NeedDate() const { return boNeedDate; }
      std::optional<std::string> const& Notes() const { return strNotes; }
      std::optional<bool> const&        UrgentValue() const { return boUrgentValue; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      std::string const&                _Denotation() const;
      std::string const&                _Abbreviation() const;
      std::string const&                _Description() const;
      bool                              _Coupled() const;
      bool                              _NeedDate() const;
      std::string const&                _Notes() const;
      bool                              _UrgentValue() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<std::string> const& Denotation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Abbreviation(std::optional<std::string> const& newVal);
      std::optional<std::string> const& Description(std::optional<std::string> const& newVal);
      std::optional<bool> const&        Coupled(std::optional<bool> const& newVal);
      std::optional<bool> const&        NeedDate(std::optional<bool> const& newVal);
      std::optional<std::string> const& Notes(std::optional<std::string> const& newVal);
      std::optional<bool> const&        UrgentValue(std::optional<bool> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TFamilyStatus& rhs) noexcept;
      void _init();
      void _copy(TFamilyStatus const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TFamilyStatus::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TFamilyStatus\" is empty.");;
   }

inline std::string const& TFamilyStatus::_Denotation() const {
   if(strDenotation) [[likely]] return strDenotation.value();
   else throw std::runtime_error("value for attribute \"Denotation\" in class \"TFamilyStatus\" is empty.");;
   }

inline std::string const& TFamilyStatus::_Abbreviation() const {
   if(strAbbreviation) [[likely]] return strAbbreviation.value();
   else throw std::runtime_error("value for attribute \"Abbreviation\" in class \"TFamilyStatus\" is empty.");;
   }

inline std::string const& TFamilyStatus::_Description() const {
   if(strDescription) [[likely]] return strDescription.value();
   else throw std::runtime_error("value for attribute \"Description\" in class \"TFamilyStatus\" is empty.");;
   }

inline bool TFamilyStatus::_Coupled() const {
   if(boCoupled) [[likely]] return boCoupled.value();
   else throw std::runtime_error("value for attribute \"Coupled\" in class \"TFamilyStatus\" is empty.");;
   }

inline bool TFamilyStatus::_NeedDate() const {
   if(boNeedDate) [[likely]] return boNeedDate.value();
   else throw std::runtime_error("value for attribute \"NeedDate\" in class \"TFamilyStatus\" is empty.");;
   }

inline std::string const& TFamilyStatus::_Notes() const {
   if(strNotes) [[likely]] return strNotes.value();
   else throw std::runtime_error("value for attribute \"Notes\" in class \"TFamilyStatus\" is empty.");;
   }

inline bool TFamilyStatus::_UrgentValue() const {
   if(boUrgentValue) [[likely]] return boUrgentValue.value();
   else throw std::runtime_error("value for attribute \"UrgentValue\" in class \"TFamilyStatus\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TFamilyStatus::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TFamilyStatus::Denotation(std::optional<std::string> const& newVal) {
   return strDenotation = newVal;
   }

inline std::optional<std::string> const& TFamilyStatus::Abbreviation(std::optional<std::string> const& newVal) {
   return strAbbreviation = newVal;
   }

inline std::optional<std::string> const& TFamilyStatus::Description(std::optional<std::string> const& newVal) {
   return strDescription = newVal;
   }

inline std::optional<bool> const& TFamilyStatus::Coupled(std::optional<bool> const& newVal) {
   return boCoupled = newVal;
   }

inline std::optional<bool> const& TFamilyStatus::NeedDate(std::optional<bool> const& newVal) {
   return boNeedDate = newVal;
   }

inline std::optional<std::string> const& TFamilyStatus::Notes(std::optional<std::string> const& newVal) {
   return strNotes = newVal;
   }

inline std::optional<bool> const& TFamilyStatus::UrgentValue(std::optional<bool> const& newVal) {
   return boUrgentValue = newVal;
   }

} // end of namespace myCorporate
