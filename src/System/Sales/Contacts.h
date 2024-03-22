// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TContacts
* Content: information to the data of a contact person at the customer  (inherited from Person)
* Date: 22.03.2024 15:39:11,714  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for required header files of base classes
#include "System\Corporate\Person.h"

// necessary additional headers for used datatypes

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

namespace mySales {

// -------------------------------------------------------------------------------------------------
// definition of the system class TContacts for
// - information to the data of a contact person at the customer  (inherited from Person)
// -------------------------------------------------------------------------------------------------
class TContacts: public myCorporate::TPerson {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TContacts;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iContactID;  

            primary_key();
         public:
            explicit primary_key(int pContactID);
            explicit primary_key(TContacts const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TContacts() const;

            // relational operators of the primary type class
            bool operator == (primary_key const& other) const { return _compare(other) == 0; }
            bool operator != (primary_key const& other) const { return _compare(other) != 0; }
            bool operator <  (primary_key const& other) const { return _compare(other) <  0; }
            bool operator <= (primary_key const& other) const { return _compare(other) <= 0; }
            bool operator >  (primary_key const& other) const { return _compare(other) >  0; }
            bool operator >= (primary_key const& other) const { return _compare(other) >= 0; }

            // selectors the primary type class
            int        ContactID() const { return iContactID; }

            // manipulators the primary type class
            int        ContactID(int newVal) { return iContactID = newVal; }

            // method to write elements of the primary key type class to a stream
            std::ostream& write(std::ostream& out) const;

         private:
            int _compare(primary_key const& other) const;
         };

      using container_ty = std::map<primary_key, TContacts>;
      using vector_ty    = std::vector<TContacts>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table Contacts
      // ----------------------------------------------------------------------------------------------
      std::optional<int> iContactID;  
      std::optional<int> iCustID;     
      std::optional<int> iCustLiaison;

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TContacts();
      TContacts(TContacts const&);
      TContacts(TContacts &&) noexcept;
      explicit TContacts(primary_key const&);
      virtual ~TContacts();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TContacts& operator = (TContacts const&);
      TContacts& operator = (TContacts&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TContacts& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TContacts& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const& ContactID() const { return iContactID; }
      std::optional<int> const& CustID() const { return iCustID; }
      std::optional<int> const& CustLiaison() const { return iCustLiaison; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                       _ContactID() const;
      int                       _CustID() const;
      int                       _CustLiaison() const;

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const& ContactID(std::optional<int> const& newVal);
      std::optional<int> const& CustID(std::optional<int> const& newVal);
      std::optional<int> const& CustLiaison(std::optional<int> const& newVal);

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TContacts& rhs) noexcept;
      void _init();
      void _copy(TContacts const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TContacts::_ContactID() const {
   if(iContactID) [[likely]] return iContactID.value();
   else throw std::runtime_error("value for attribute \"ContactID\" in class \"TContacts\" is empty.");;
   }

inline int TContacts::_CustID() const {
   if(iCustID) [[likely]] return iCustID.value();
   else throw std::runtime_error("value for attribute \"CustID\" in class \"TContacts\" is empty.");;
   }

inline int TContacts::_CustLiaison() const {
   if(iCustLiaison) [[likely]] return iCustLiaison.value();
   else throw std::runtime_error("value for attribute \"CustLiaison\" in class \"TContacts\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TContacts::ContactID(std::optional<int> const& newVal) {
   return iContactID = newVal;
   }

inline std::optional<int> const& TContacts::CustID(std::optional<int> const& newVal) {
   return iCustID = newVal;
   }

inline std::optional<int> const& TContacts::CustLiaison(std::optional<int> const& newVal) {
   return iCustLiaison = newVal;
   }

} // end of namespace mySales
