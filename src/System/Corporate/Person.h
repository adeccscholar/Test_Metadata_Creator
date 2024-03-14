// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TPerson
* Content: informations about a person, base for different kinds of special persons in other areas of the company
* Date: 14.03.2024 23:56:53,767  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for common  virtual base class
#include "System\Corporate\base.h"

// includes for required header files for part of relationships
#include "System\Corporate/Address.h"
#include "System\Corporate/Banking.h"
#include "System\Corporate/Internet.h"
#include "System\Corporate/Phone.h"

// necessary additional headers for used datatypes
#include <chrono>
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
// definition of the system class TPerson for
// - informations about a person, base for different kinds of special persons in other areas of the company
// -------------------------------------------------------------------------------------------------
class TPerson : virtual public TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TPerson;
         private:
            int iID;                

            constexpr primary_key() : iID {} { }
         public:
            constexpr primary_key(int pID) : iID(pID) { }
            primary_key(TPerson const& other) : iID(other._ID()) { }
            constexpr primary_key(primary_key const& other) : iID(other.iID) { }
            constexpr primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)) { }
            constexpr ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TPerson() const {
               TPerson ret;
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

      using container_ty = std::map<primary_key, TPerson>;
      using vector_ty    = std::vector<TPerson>;

      // ----------------------------------------------------------------------------------------------
      // public datatypes for composed tables
      // ----------------------------------------------------------------------------------------------
      using address_ty = std::map<int, TAddress>;
      using banking_ty = std::map<int, TBanking>;
      using internet_ty = std::map<int, TInternet>;
      using phone_ty = std::map<int, TPhone>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table Person
      // ----------------------------------------------------------------------------------------------
      std::optional<int>                         iID;                
      std::optional<std::string>                 strName;            
      std::optional<std::string>                 strFirstname;       
      std::optional<int>                         iFormOfAddress;     
      std::optional<int>                         iFamilyStatus;      
      std::optional<std::chrono::year_month_day> daFamilyStatusSince;
      std::optional<std::chrono::year_month_day> daBirthday;         
      std::optional<std::string>                 strNotes;           
      std::optional<std::string>                 strFullName;        

      // ----------------------------------------------------------------------------------------------
      // data elements for composed tables
      // ----------------------------------------------------------------------------------------------
      address_ty                                 m_Address;
      banking_ty                                 m_Banking;
      internet_ty                                m_Internet;
      phone_ty                                   m_Phone;

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TPerson();
      TPerson(TPerson const&);
      TPerson(TPerson &&) noexcept;
      virtual ~TPerson();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TPerson& operator = (TPerson const&);
      TPerson& operator = (TPerson&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TPerson& rhs) noexcept;
      virtual void init() override;
      virtual void copy(TSimplePersonBase const& other) override;

      TPerson& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&                         ID() const { return iID; }
      std::optional<std::string> const&                 Name() const { return strName; }
      std::optional<std::string> const&                 Firstname() const { return strFirstname; }
      std::optional<int> const&                         FormOfAddress() const { return iFormOfAddress; }
      std::optional<int> const&                         FamilyStatus() const { return iFamilyStatus; }
      std::optional<std::chrono::year_month_day> const& FamilyStatusSince() const { return daFamilyStatusSince; }
      std::optional<std::chrono::year_month_day> const& Birthday() const { return daBirthday; }
      std::optional<std::string> const&                 Notes() const { return strNotes; }
      std::optional<std::string> const&                 FullName() const { return strFullName; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                                               _ID() const;
      std::string const&                                _Name() const;
      std::string const&                                _Firstname() const;
      int                                               _FormOfAddress() const;
      int                                               _FamilyStatus() const;
      std::chrono::year_month_day                       _FamilyStatusSince() const;
      std::chrono::year_month_day                       _Birthday() const;
      std::string const&                                _Notes() const;
      std::string const&                                _FullName() const;

      // ----------------------------------------------------------------------------------------------
      // public selectors for container of composed tables
      // ----------------------------------------------------------------------------------------------
      address_ty const& Address() const { return m_Address; }
      banking_ty const& Banking() const { return m_Banking; }
      internet_ty const& Internet() const { return m_Internet; }
      phone_ty const& Phone() const { return m_Phone; }

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&                         ID(std::optional<int> const& newVal);
      std::optional<std::string> const&                 Name(std::optional<std::string> const& newVal);
      std::optional<std::string> const&                 Firstname(std::optional<std::string> const& newVal);
      std::optional<int> const&                         FormOfAddress(std::optional<int> const& newVal);
      std::optional<int> const&                         FamilyStatus(std::optional<int> const& newVal);
      std::optional<std::chrono::year_month_day> const& FamilyStatusSince(std::optional<std::chrono::year_month_day> const& newVal);
      std::optional<std::chrono::year_month_day> const& Birthday(std::optional<std::chrono::year_month_day> const& newVal);
      std::optional<std::string> const&                 Notes(std::optional<std::string> const& newVal);

      // ----------------------------------------------------------------------------------------------
      // public manipulators for container of composed tables
      // ----------------------------------------------------------------------------------------------
      address_ty& Address()  { return m_Address; }
      banking_ty& Banking()  { return m_Banking; }
      internet_ty& Internet()  { return m_Internet; }
      phone_ty& Phone()  { return m_Phone; }

   private:
      // ----------------------------------------------------------------------------------------------
      // private  manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<std::string> const&                 FullName(std::optional<std::string> const& newVal);

      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TPerson& rhs) noexcept;
      void _init();
      void _copy(TPerson const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TPerson::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TPerson\" is empty.");;
   }

inline std::string const& TPerson::_Name() const {
   if(strName) [[likely]] return strName.value();
   else throw std::runtime_error("value for attribute \"Name\" in class \"TPerson\" is empty.");;
   }

inline std::string const& TPerson::_Firstname() const {
   if(strFirstname) [[likely]] return strFirstname.value();
   else throw std::runtime_error("value for attribute \"Firstname\" in class \"TPerson\" is empty.");;
   }

inline int TPerson::_FormOfAddress() const {
   if(iFormOfAddress) [[likely]] return iFormOfAddress.value();
   else throw std::runtime_error("value for attribute \"FormOfAddress\" in class \"TPerson\" is empty.");;
   }

inline int TPerson::_FamilyStatus() const {
   if(iFamilyStatus) [[likely]] return iFamilyStatus.value();
   else throw std::runtime_error("value for attribute \"FamilyStatus\" in class \"TPerson\" is empty.");;
   }

inline std::chrono::year_month_day TPerson::_FamilyStatusSince() const {
   if(daFamilyStatusSince) [[likely]] return daFamilyStatusSince.value();
   else throw std::runtime_error("value for attribute \"FamilyStatusSince\" in class \"TPerson\" is empty.");;
   }

inline std::chrono::year_month_day TPerson::_Birthday() const {
   if(daBirthday) [[likely]] return daBirthday.value();
   else throw std::runtime_error("value for attribute \"Birthday\" in class \"TPerson\" is empty.");;
   }

inline std::string const& TPerson::_Notes() const {
   if(strNotes) [[likely]] return strNotes.value();
   else throw std::runtime_error("value for attribute \"Notes\" in class \"TPerson\" is empty.");;
   }

inline std::string const& TPerson::_FullName() const {
   if(strFullName) [[likely]] return strFullName.value();
   else throw std::runtime_error("value for attribute \"FullName\" in class \"TPerson\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TPerson::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<std::string> const& TPerson::Name(std::optional<std::string> const& newVal) {
   return strName = newVal;
   }

inline std::optional<std::string> const& TPerson::Firstname(std::optional<std::string> const& newVal) {
   return strFirstname = newVal;
   }

inline std::optional<int> const& TPerson::FormOfAddress(std::optional<int> const& newVal) {
   return iFormOfAddress = newVal;
   }

inline std::optional<int> const& TPerson::FamilyStatus(std::optional<int> const& newVal) {
   return iFamilyStatus = newVal;
   }

inline std::optional<std::chrono::year_month_day> const& TPerson::FamilyStatusSince(std::optional<std::chrono::year_month_day> const& newVal) {
   return daFamilyStatusSince = newVal;
   }

inline std::optional<std::chrono::year_month_day> const& TPerson::Birthday(std::optional<std::chrono::year_month_day> const& newVal) {
   return daBirthday = newVal;
   }

inline std::optional<std::string> const& TPerson::Notes(std::optional<std::string> const& newVal) {
   return strNotes = newVal;
   }

inline std::optional<std::string> const& TPerson::FullName(std::optional<std::string> const& newVal) {
   return strFullName = newVal;
   }

} // end of namespace myCorporate
