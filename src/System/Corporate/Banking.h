// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TBanking
* Content: informations about the account details provided by a person and used in a specific context
* Date: 14.03.2024 23:56:53,064  file created with adecc Scholar metadata generator
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
// definition of the system class TBanking for
// - informations about the account details provided by a person and used in a specific context
// -------------------------------------------------------------------------------------------------
class TBanking : virtual public TSimplePersonBase {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TBanking;
         private:
            int iID;         
            int iBankingType;

            constexpr primary_key() : iID {}, iBankingType {} { }
         public:
            constexpr primary_key(int pID, int pBankingType) : iID(pID), iBankingType(pBankingType) { }
            primary_key(TBanking const& other) : iID(other._ID()), iBankingType(other._BankingType()) { }
            constexpr primary_key(primary_key const& other) : iID(other.iID), iBankingType(other.iBankingType) { }
            constexpr primary_key(primary_key&& other) noexcept : iID(std::move(other.iID)), iBankingType(std::move(other.iBankingType)) { }
            constexpr ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TBanking() const {
               TBanking ret;
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
            int        BankingType() const { return iBankingType; }

            // manipulators the primary type class
            int        ID(int newVal) { return iID = newVal; }
            int        BankingType(int newVal) { return iBankingType = newVal; }

         private:
            int _compare(primary_key const& other) const {
               static auto constexpr comp_help = [](auto const& lhs, auto const& rhs) -> int {
                  return (lhs < rhs ? -1 : (lhs > rhs ? 1 : 0));
                  };
               if(auto ret = comp_help(this->iID, other.iID); ret != 0) return ret;
               if(auto ret = comp_help(this->iBankingType, other.iBankingType); ret != 0) return ret;
               return 0;
               }
         };

      using container_ty = std::map<primary_key, TBanking>;
      using vector_ty    = std::vector<TBanking>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table Banking
      // ----------------------------------------------------------------------------------------------
      std::optional<int>         iID;         
      std::optional<int>         iBankingType;
      std::optional<std::string> strBankName; 
      std::optional<std::string> strIBAN;     
      std::optional<std::string> strBIC;      
      std::optional<std::string> strBankOwner;
      std::optional<int>         iCountry;    

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TBanking();
      TBanking(TBanking const&);
      TBanking(TBanking &&) noexcept;
      virtual ~TBanking();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TBanking& operator = (TBanking const&);
      TBanking& operator = (TBanking&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TBanking& rhs) noexcept;
      virtual void init() override;
      virtual void copy(TSimplePersonBase const& other) override;

      TBanking& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID() const { return iID; }
      std::optional<int> const&         BankingType() const { return iBankingType; }
      std::optional<std::string> const& BankName() const { return strBankName; }
      std::optional<std::string> const& IBAN() const { return strIBAN; }
      std::optional<std::string> const& BIC() const { return strBIC; }
      std::optional<std::string> const& BankOwner() const { return strBankOwner; }
      std::optional<int> const&         Country() const { return iCountry; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                               _ID() const;
      int                               _BankingType() const;
      std::string const&                _BankName() const;
      std::string const&                _IBAN() const;
      std::string const&                _BIC() const;
      std::string const&                _BankOwner() const;
      int                               _Country() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&         ID(std::optional<int> const& newVal);
      std::optional<int> const&         BankingType(std::optional<int> const& newVal);
      std::optional<std::string> const& BankName(std::optional<std::string> const& newVal);
      std::optional<std::string> const& IBAN(std::optional<std::string> const& newVal);
      std::optional<std::string> const& BIC(std::optional<std::string> const& newVal);
      std::optional<std::string> const& BankOwner(std::optional<std::string> const& newVal);
      std::optional<int> const&         Country(std::optional<int> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TBanking& rhs) noexcept;
      void _init();
      void _copy(TBanking const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TBanking::_ID() const {
   if(iID) [[likely]] return iID.value();
   else throw std::runtime_error("value for attribute \"ID\" in class \"TBanking\" is empty.");;
   }

inline int TBanking::_BankingType() const {
   if(iBankingType) [[likely]] return iBankingType.value();
   else throw std::runtime_error("value for attribute \"BankingType\" in class \"TBanking\" is empty.");;
   }

inline std::string const& TBanking::_BankName() const {
   if(strBankName) [[likely]] return strBankName.value();
   else throw std::runtime_error("value for attribute \"BankName\" in class \"TBanking\" is empty.");;
   }

inline std::string const& TBanking::_IBAN() const {
   if(strIBAN) [[likely]] return strIBAN.value();
   else throw std::runtime_error("value for attribute \"IBAN\" in class \"TBanking\" is empty.");;
   }

inline std::string const& TBanking::_BIC() const {
   if(strBIC) [[likely]] return strBIC.value();
   else throw std::runtime_error("value for attribute \"BIC\" in class \"TBanking\" is empty.");;
   }

inline std::string const& TBanking::_BankOwner() const {
   if(strBankOwner) [[likely]] return strBankOwner.value();
   else throw std::runtime_error("value for attribute \"BankOwner\" in class \"TBanking\" is empty.");;
   }

inline int TBanking::_Country() const {
   if(iCountry) [[likely]] return iCountry.value();
   else throw std::runtime_error("value for attribute \"Country\" in class \"TBanking\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TBanking::ID(std::optional<int> const& newVal) {
   return iID = newVal;
   }

inline std::optional<int> const& TBanking::BankingType(std::optional<int> const& newVal) {
   return iBankingType = newVal;
   }

inline std::optional<std::string> const& TBanking::BankName(std::optional<std::string> const& newVal) {
   return strBankName = newVal;
   }

inline std::optional<std::string> const& TBanking::IBAN(std::optional<std::string> const& newVal) {
   return strIBAN = newVal;
   }

inline std::optional<std::string> const& TBanking::BIC(std::optional<std::string> const& newVal) {
   return strBIC = newVal;
   }

inline std::optional<std::string> const& TBanking::BankOwner(std::optional<std::string> const& newVal) {
   return strBankOwner = newVal;
   }

inline std::optional<int> const& TBanking::Country(std::optional<int> const& newVal) {
   return iCountry = newVal;
   }

} // end of namespace myCorporate
