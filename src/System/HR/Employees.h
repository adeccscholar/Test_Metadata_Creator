// -------------------------------------------------------------------------------------------------
/*
* Project: model with a simple person administration
* Definition of the data class TEmployees
* Content: information about the employees in the company (generalization of a person)
* Date: 22.03.2024 15:39:12,126  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/
// -------------------------------------------------------------------------------------------------

#pragma once


// includes for required header files of base classes
#include "System\Corporate\Person.h"

// includes for required header files for part of relationships
#include "System\HR\WD_NonWorking.h"
#include "System\HR\WorkingTime.h"

// necessary additional headers for used datatypes
#include <chrono>
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
// definition of the system class TEmployees for
// - information about the employees in the company (generalization of a person)
// -------------------------------------------------------------------------------------------------
class TEmployees: public myCorporate::TPerson {
   friend class reader::TPersonReader;
   public:
      // ----------------------------------------------------------------------------------------------
      // public datatypes for this table
      // ----------------------------------------------------------------------------------------------
      class primary_key {
         friend class TEmployees;
         friend std::ostream& operator << (std::ostream& out, primary_key const& data) { return data.write(out); }
         private:
            int iEmployeeID;     

            primary_key();
         public:
            explicit primary_key(int pEmployeeID);
            explicit primary_key(TEmployees const& other);
            primary_key(primary_key const& other);
            primary_key(primary_key&& other) noexcept;
            ~primary_key() { }

            // conversions operator for this element to the encircling class
            operator TEmployees() const;

            // relational operators of the primary type class
            bool operator == (primary_key const& other) const { return _compare(other) == 0; }
            bool operator != (primary_key const& other) const { return _compare(other) != 0; }
            bool operator <  (primary_key const& other) const { return _compare(other) <  0; }
            bool operator <= (primary_key const& other) const { return _compare(other) <= 0; }
            bool operator >  (primary_key const& other) const { return _compare(other) >  0; }
            bool operator >= (primary_key const& other) const { return _compare(other) >= 0; }

            // selectors the primary type class
            int        EmployeeID() const { return iEmployeeID; }

            // manipulators the primary type class
            int        EmployeeID(int newVal) { return iEmployeeID = newVal; }

            // method to write elements of the primary key type class to a stream
            std::ostream& write(std::ostream& out) const;

         private:
            int _compare(primary_key const& other) const;
         };

      using container_ty = std::map<primary_key, TEmployees>;
      using vector_ty    = std::vector<TEmployees>;

      // ----------------------------------------------------------------------------------------------
      // public datatypes for composed tables
      // ----------------------------------------------------------------------------------------------
      using wd_nonworking_ty = std::map<std::chrono::year_month_day, TWD_NonWorking>;
      using workingtime_ty = std::map<std::chrono::system_clock::time_point, TWorkingTime>;

   private:
      // ----------------------------------------------------------------------------------------------
      // private data elements, direct attributes from table Employees
      // ----------------------------------------------------------------------------------------------
      std::optional<int>                         iDummy;          
      std::optional<int>                         iEmployeeID;     
      std::optional<std::string>                 strPersonNumber; 
      std::optional<double>                      flSalary;        
      std::optional<int>                         iSalaryType;     
      std::optional<int>                         iTaxClass;       
      std::optional<std::chrono::year_month_day> daStartOfJob;    
      std::optional<std::chrono::year_month_day> daEndOfJob;      
      std::optional<int>                         iReasonDeparture;
      std::optional<int>                         iJobPosition;    
      std::optional<std::string>                 strJobSpec;      
      std::optional<unsigned int>                uVacationDays;   
      std::optional<int>                         iDepartment;     
      std::optional<std::string>                 strSocialNummer; 
      std::optional<bool>                        boActive;        

      // ----------------------------------------------------------------------------------------------
      // data elements for composed tables
      // ----------------------------------------------------------------------------------------------
      wd_nonworking_ty                           m_WD_NonWorking;
      workingtime_ty                             m_WorkingTime;

   public:
      // ----------------------------------------------------------------------------------------------
      // constructors and destructor
      // ----------------------------------------------------------------------------------------------
      TEmployees();
      TEmployees(TEmployees const&);
      TEmployees(TEmployees &&) noexcept;
      explicit TEmployees(primary_key const&);
      virtual ~TEmployees();

      // ----------------------------------------------------------------------------------------------
      // operators for this class
      // ----------------------------------------------------------------------------------------------
      TEmployees& operator = (TEmployees const&);
      TEmployees& operator = (TEmployees&&) noexcept;

      operator primary_key () const { return GetKey(); }
      // ----------------------------------------------------------------------------------------------
      // public functions for this class (following the framework for this project)
      // ----------------------------------------------------------------------------------------------
      void swap(TEmployees& rhs) noexcept;
      virtual void init() override;
      virtual void copy(myCorporate::TSimplePersonBase const& other) override;

      TEmployees& init(primary_key const&);

      // ----------------------------------------------------------------------------------------------
      // method to extract the key from data
      // ----------------------------------------------------------------------------------------------
      primary_key GetKey() const { return primary_key(*this); };

      // ----------------------------------------------------------------------------------------------
      // selectors for the data access to the direct data elements with std::optional retval
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&                         Dummy() const { return iDummy; }
      std::optional<int> const&                         EmployeeID() const { return iEmployeeID; }
      std::optional<std::string> const&                 PersonNumber() const { return strPersonNumber; }
      std::optional<double> const&                      Salary() const { return flSalary; }
      std::optional<int> const&                         SalaryType() const { return iSalaryType; }
      std::optional<int> const&                         TaxClass() const { return iTaxClass; }
      std::optional<std::chrono::year_month_day> const& StartOfJob() const { return daStartOfJob; }
      std::optional<std::chrono::year_month_day> const& EndOfJob() const { return daEndOfJob; }
      std::optional<int> const&                         ReasonDeparture() const { return iReasonDeparture; }
      std::optional<int> const&                         JobPosition() const { return iJobPosition; }
      std::optional<std::string> const&                 JobSpec() const { return strJobSpec; }
      std::optional<unsigned int> const&                VacationDays() const { return uVacationDays; }
      std::optional<int> const&                         Department() const { return iDepartment; }
      std::optional<std::string> const&                 SocialNummer() const { return strSocialNummer; }
      std::optional<bool> const&                        Active() const { return boActive; }

      // ----------------------------------------------------------------------------------------------
      // public selectors for direct data access to the values inside std::optional (unboxing)
      // ----------------------------------------------------------------------------------------------
      int                                               _Dummy() const;
      int                                               _EmployeeID() const;
      std::string const&                                _PersonNumber() const;
      double const&                                     _Salary() const;
      int                                               _SalaryType() const;
      int                                               _TaxClass() const;
      std::chrono::year_month_day                       _StartOfJob() const;
      std::chrono::year_month_day                       _EndOfJob() const;
      int                                               _ReasonDeparture() const;
      int                                               _JobPosition() const;
      std::string const&                                _JobSpec() const;
      unsigned int                                      _VacationDays() const;
      int                                               _Department() const;
      std::string const&                                _SocialNummer() const;
      bool                                              _Active() const;

      // ----------------------------------------------------------------------------------------------
      // public selectors for container of composed tables
      // ----------------------------------------------------------------------------------------------
      wd_nonworking_ty const& WD_NonWorking() const { return m_WD_NonWorking; }
      workingtime_ty const& WorkingTime() const { return m_WorkingTime; }

      // ----------------------------------------------------------------------------------------------
      // public manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<int> const&                         Dummy(std::optional<int> const& newVal);
      std::optional<int> const&                         EmployeeID(std::optional<int> const& newVal);
      std::optional<std::string> const&                 PersonNumber(std::optional<std::string> const& newVal);
      std::optional<double> const&                      Salary(std::optional<double> const& newVal);
      std::optional<int> const&                         SalaryType(std::optional<int> const& newVal);
      std::optional<int> const&                         TaxClass(std::optional<int> const& newVal);
      std::optional<std::chrono::year_month_day> const& StartOfJob(std::optional<std::chrono::year_month_day> const& newVal);
      std::optional<std::chrono::year_month_day> const& EndOfJob(std::optional<std::chrono::year_month_day> const& newVal);
      std::optional<int> const&                         ReasonDeparture(std::optional<int> const& newVal);
      std::optional<int> const&                         JobPosition(std::optional<int> const& newVal);
      std::optional<std::string> const&                 JobSpec(std::optional<std::string> const& newVal);
      std::optional<unsigned int> const&                VacationDays(std::optional<unsigned int> const& newVal);
      std::optional<int> const&                         Department(std::optional<int> const& newVal);
      std::optional<std::string> const&                 SocialNummer(std::optional<std::string> const& newVal);

      // ----------------------------------------------------------------------------------------------
      // public manipulators for container of composed tables
      // ----------------------------------------------------------------------------------------------
      wd_nonworking_ty& WD_NonWorking()  { return m_WD_NonWorking; }
      workingtime_ty& WorkingTime()  { return m_WorkingTime; }

   private:
      // ----------------------------------------------------------------------------------------------
      // private  manipulators for the class
      // ----------------------------------------------------------------------------------------------
      std::optional<bool> const&                        Active(std::optional<bool> const& newVal);

      // ----------------------------------------------------------------------------------------------
      // internal functions for this class
      // ----------------------------------------------------------------------------------------------
      void _swap(TEmployees& rhs) noexcept;
      void _init();
      void _copy(TEmployees const& other);

   };

// -------------------------------------------------------------------------------------------------
// Implementations of the special selectors for return values instead std::optional
// -------------------------------------------------------------------------------------------------
inline int TEmployees::_Dummy() const {
   if(iDummy) [[likely]] return iDummy.value();
   else throw std::runtime_error("value for attribute \"Dummy\" in class \"TEmployees\" is empty.");;
   }

inline int TEmployees::_EmployeeID() const {
   if(iEmployeeID) [[likely]] return iEmployeeID.value();
   else throw std::runtime_error("value for attribute \"EmployeeID\" in class \"TEmployees\" is empty.");;
   }

inline std::string const& TEmployees::_PersonNumber() const {
   if(strPersonNumber) [[likely]] return strPersonNumber.value();
   else throw std::runtime_error("value for attribute \"PersonNumber\" in class \"TEmployees\" is empty.");;
   }

inline double const& TEmployees::_Salary() const {
   if(flSalary) [[likely]] return flSalary.value();
   else throw std::runtime_error("value for attribute \"Salary\" in class \"TEmployees\" is empty.");;
   }

inline int TEmployees::_SalaryType() const {
   if(iSalaryType) [[likely]] return iSalaryType.value();
   else throw std::runtime_error("value for attribute \"SalaryType\" in class \"TEmployees\" is empty.");;
   }

inline int TEmployees::_TaxClass() const {
   if(iTaxClass) [[likely]] return iTaxClass.value();
   else throw std::runtime_error("value for attribute \"TaxClass\" in class \"TEmployees\" is empty.");;
   }

inline std::chrono::year_month_day TEmployees::_StartOfJob() const {
   if(daStartOfJob) [[likely]] return daStartOfJob.value();
   else throw std::runtime_error("value for attribute \"StartOfJob\" in class \"TEmployees\" is empty.");;
   }

inline std::chrono::year_month_day TEmployees::_EndOfJob() const {
   if(daEndOfJob) [[likely]] return daEndOfJob.value();
   else throw std::runtime_error("value for attribute \"EndOfJob\" in class \"TEmployees\" is empty.");;
   }

inline int TEmployees::_ReasonDeparture() const {
   if(iReasonDeparture) [[likely]] return iReasonDeparture.value();
   else throw std::runtime_error("value for attribute \"ReasonDeparture\" in class \"TEmployees\" is empty.");;
   }

inline int TEmployees::_JobPosition() const {
   if(iJobPosition) [[likely]] return iJobPosition.value();
   else throw std::runtime_error("value for attribute \"JobPosition\" in class \"TEmployees\" is empty.");;
   }

inline std::string const& TEmployees::_JobSpec() const {
   if(strJobSpec) [[likely]] return strJobSpec.value();
   else throw std::runtime_error("value for attribute \"JobSpec\" in class \"TEmployees\" is empty.");;
   }

inline unsigned int TEmployees::_VacationDays() const {
   if(uVacationDays) [[likely]] return uVacationDays.value();
   else throw std::runtime_error("value for attribute \"VacationDays\" in class \"TEmployees\" is empty.");;
   }

inline int TEmployees::_Department() const {
   if(iDepartment) [[likely]] return iDepartment.value();
   else throw std::runtime_error("value for attribute \"Department\" in class \"TEmployees\" is empty.");;
   }

inline std::string const& TEmployees::_SocialNummer() const {
   if(strSocialNummer) [[likely]] return strSocialNummer.value();
   else throw std::runtime_error("value for attribute \"SocialNummer\" in class \"TEmployees\" is empty.");;
   }

inline bool TEmployees::_Active() const {
   if(boActive) [[likely]] return boActive.value();
   else throw std::runtime_error("value for attribute \"Active\" in class \"TEmployees\" is empty.");;
   }


// Implementations of the manipulators
inline std::optional<int> const& TEmployees::Dummy(std::optional<int> const& newVal) {
   return iDummy = newVal;
   }

inline std::optional<int> const& TEmployees::EmployeeID(std::optional<int> const& newVal) {
   return iEmployeeID = newVal;
   }

inline std::optional<std::string> const& TEmployees::PersonNumber(std::optional<std::string> const& newVal) {
   return strPersonNumber = newVal;
   }

inline std::optional<double> const& TEmployees::Salary(std::optional<double> const& newVal) {
   return flSalary = newVal;
   }

inline std::optional<int> const& TEmployees::SalaryType(std::optional<int> const& newVal) {
   return iSalaryType = newVal;
   }

inline std::optional<int> const& TEmployees::TaxClass(std::optional<int> const& newVal) {
   return iTaxClass = newVal;
   }

inline std::optional<std::chrono::year_month_day> const& TEmployees::StartOfJob(std::optional<std::chrono::year_month_day> const& newVal) {
   return daStartOfJob = newVal;
   }

inline std::optional<std::chrono::year_month_day> const& TEmployees::EndOfJob(std::optional<std::chrono::year_month_day> const& newVal) {
   return daEndOfJob = newVal;
   }

inline std::optional<int> const& TEmployees::ReasonDeparture(std::optional<int> const& newVal) {
   return iReasonDeparture = newVal;
   }

inline std::optional<int> const& TEmployees::JobPosition(std::optional<int> const& newVal) {
   return iJobPosition = newVal;
   }

inline std::optional<std::string> const& TEmployees::JobSpec(std::optional<std::string> const& newVal) {
   return strJobSpec = newVal;
   }

inline std::optional<unsigned int> const& TEmployees::VacationDays(std::optional<unsigned int> const& newVal) {
   return uVacationDays = newVal;
   }

inline std::optional<int> const& TEmployees::Department(std::optional<int> const& newVal) {
   return iDepartment = newVal;
   }

inline std::optional<std::string> const& TEmployees::SocialNummer(std::optional<std::string> const& newVal) {
   return strSocialNummer = newVal;
   }

inline std::optional<bool> const& TEmployees::Active(std::optional<bool> const& newVal) {
   return boActive = newVal;
   }

} // end of namespace myHR
