// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TCustomers
* Content: information to the data of a client / customer  (inherited from Person)
* Date: 22.03.2024 15:39:12,000  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for required header files of base classes
#include "System\Corporate\Person.h"

// includes for required header files for part of relationships
#include "System\Sales\Contacts.h"

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
// definition of the system class TCustomers for
// - information to the data of a client / customer  (inherited from Person)
// -------------------------------------------------------------------------------------------------
class TCustomers: public myCorporate::TPerson {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TCustomers;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iCustID;            

            primary_key();
         public:
            explicit primary_key(int pCustID);
            explicit primary_key(TCustomers const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TCustomers() const;

            // relational operators of the primary type class
            bool operator == (primary_key const& other) const { return _compare(other) == 0; }
            bool operator != (primary_key const& other) const { return _compare(other) != 0; }
            bool operator <  (primary_key const& other) const { return _compare(other) <  0; }
            bool operator <= (primary_key const& other) const { return _compare(other) <= 0; }
            bool operator >  (primary_key const& other) const { return _compare(other) >  0; }
            bool operator >= (primary_key const& other) const { return _compare(other) >= 0; }

            // selectors the primary type class
            int        CustID() const { return iCustID; }

            // manipulators the primary type class
            int        CustID(int newVal) { return iCustID = newVal; }

            // method to write elements of the primary key type class to a stream
            std::ostream& write(std::ostream& out) const;

         private:
            int _compare(primary_key const& other) const;
         };

      using container_ty = std::map<primary_key, TCustomers>;
      using vector_ty    = std::vector<TCustomers>;

      // ----------------------------------------------------------------------------------------------
      // public datatypes for composed tables
      // ----------------------------------------------------------------------------------------------
      using contacts_ty = std::map<int, TContacts>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table Customers
      // ----------------------------------------------------------------------------------------------
      std::optional<int> iCustID;            
      std::optional<int> iServiceAgent;      
      std::optional<int> iCustClassification;
      std::optional<int> iLegalForm;         

      // ----------------------------------------------------------------------------------------------
      // data elements for composed tables
      // ----------------------------------------------------------------------------------------------
      contacts_ty        m_Contacts;

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TCustomers();
      TCustomers(TCustomers const&);
      TCustomers(TCustomers &&) noexcept;
      explicit TCustomers(primary_key const&);
      virtual ~TCustomers();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TCustomers& operator = (TCustomers const&);
      TCustomers& operator = (TCustomers&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TCustomers& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TCustomers& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const& CustID() const { return iCustID; }
      std::optional<int> const& ServiceAgent() const { return iServiceAgent; }
      std::optional<int> const& CustClassification() const { return iCustClassification; }
      std::optional<int> const& LegalForm() const { return iLegalForm; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                       _CustID() const;
      int                       _ServiceAgent() const;
      int                       _CustClassification() const;
      int                       _LegalForm() const;

      // ----------------------------------------------------------------------------------------------
      // public selectors for container of composed tables
      // ----------------------------------------------------------------------------------------------
      contacts_ty const& Contacts() const { return m_Contacts; }

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const& CustID(std::optional<int> const& newVal);
      std::optional<int> const& ServiceAgent(std::optional<int> const& newVal);
      std::optional<int> const& CustClassification(std::optional<int> const& newVal);
      std::optional<int> const& LegalForm(std::optional<int> const& newVal);

      // ----------------------------------------------------------------------------------------------
      // public manipulators for container of composed tables
      // ----------------------------------------------------------------------------------------------
      contacts_ty& Contacts()  { return m_Contacts; }

   private:
      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TCustomers& rhs) noexcept;
      void _init();
      void _copy(TCustomers const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TCustomers::_CustID() const {
   if(iCustID) [[likely]] return iCustID.value();
   else throw std::runtime_error("value for attribute \"CustID\" in class \"TCustomers\" is empty.");;
   }

inline int TCustomers::_ServiceAgent() const {
   if(iServiceAgent) [[likely]] return iServiceAgent.value();
   else throw std::runtime_error("value for attribute \"ServiceAgent\" in class \"TCustomers\" is empty.");;
   }

inline int TCustomers::_CustClassification() const {
   if(iCustClassification) [[likely]] return iCustClassification.value();
   else throw std::runtime_error("value for attribute \"CustClassification\" in class \"TCustomers\" is empty.");;
   }

inline int TCustomers::_LegalForm() const {
   if(iLegalForm) [[likely]] return iLegalForm.value();
   else throw std::runtime_error("value for attribute \"LegalForm\" in class \"TCustomers\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TCustomers::CustID(std::optional<int> const& newVal) {
   return iCustID = newVal;
   }

inline std::optional<int> const& TCustomers::ServiceAgent(std::optional<int> const& newVal) {
   return iServiceAgent = newVal;
   }

inline std::optional<int> const& TCustomers::CustClassification(std::optional<int> const& newVal) {
   return iCustClassification = newVal;
   }

inline std::optional<int> const& TCustomers::LegalForm(std::optional<int> const& newVal) {
   return iLegalForm = newVal;
   }

} // end of namespace mySales
