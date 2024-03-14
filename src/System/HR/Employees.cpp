/*
* Project: model with a simple person administration
* Implementation of the data class TEmployees
* Content: information about the employees in the company (generalization of a person)
* Date: 14.03.2024 23:56:53,351  file created with adecc Scholar metadata generator
* copyright ©  adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#include "System\HR/Employees.h"

#include <typeinfo>

namespace myHR {

TEmployees::TEmployees() : myCorporate::TPerson() {
   _init();
   }

TEmployees::TEmployees(TEmployees const& other) : myCorporate::TPerson(other){
   _copy(other);
   }

TEmployees::TEmployees(TEmployees&& other) noexcept : myCorporate::TPerson(std::move(other)) {
   _swap(other);
   }

TEmployees::~TEmployees() {   }

TEmployees& TEmployees::operator = (TEmployees const& other) {
   copy(other);
   return *this;
   }

TEmployees& TEmployees::operator = (TEmployees&& other) noexcept {
   swap(other);
   return *this;
   }

void TEmployees::swap(TEmployees& other) noexcept {
   myCorporate::TPerson::swap(static_cast<myCorporate::TPerson&>(other));
   _swap(other);
   }

void TEmployees::init() {
   myCorporate::TPerson::init();
   _init();
   }

void TEmployees::copy(myCorporate::TSimplePersonBase const& other) {
   myCorporate::TPerson::copy(other);
   try {
      TEmployees const& ref = dynamic_cast<TEmployees const&>(other);
      _copy(ref);
      }
   catch(std::bad_cast const&) { }
   }

// init(primary_key const&): initialization method for the instance with the primary key attributes
TEmployees& TEmployees::init(primary_key const& key_values) {
   init();
   ID(key_values.ID());
   return *this;
   }

// _swap: internal swapping method for the class
void TEmployees::_swap(TEmployees& other) noexcept {
   // swapping own data elements
   std::swap(iID, other.iID);
   std::swap(strPersonNumber, other.strPersonNumber);
   std::swap(flSalary, other.flSalary);
   std::swap(iSalaryType, other.iSalaryType);
   std::swap(iTaxClass, other.iTaxClass);
   std::swap(daStartOfJob, other.daStartOfJob);
   std::swap(daEndOfJob, other.daEndOfJob);
   std::swap(iReasonDeparture, other.iReasonDeparture);
   std::swap(iJobPosition, other.iJobPosition);
   std::swap(strJobSpec, other.strJobSpec);
   std::swap(uVacationDays, other.uVacationDays);
   std::swap(iDepartment, other.iDepartment);
   std::swap(strSocialNummer, other.strSocialNummer);
   std::swap(boActive, other.boActive);
   // swapping the composed classes
   std::swap(m_WD_NonWorking, other.m_WD_NonWorking);
   std::swap(m_WorkingTime, other.m_WorkingTime);
   return;
   }

// _init: internal initialization method for the instance of this class
void TEmployees::_init() {
   // initializing own data elements
   iID               = {};
   strPersonNumber   = {};
   flSalary          = {};
   iSalaryType       = {};
   iTaxClass         = {};
   daStartOfJob      = {};
   daEndOfJob        = {};
   iReasonDeparture  = {};
   iJobPosition      = {};
   strJobSpec        = {};
   uVacationDays     = {};
   iDepartment       = {};
   strSocialNummer   = {};
   boActive          = {};
   // initializing the composed classes
   m_WD_NonWorking   = { };
   m_WorkingTime     = { };
   return;
   }

// _copy: internal copy method for the class
void TEmployees::_copy(TEmployees const& other) {
   ID(other.ID());
   PersonNumber(other.PersonNumber());
   Salary(other.Salary());
   SalaryType(other.SalaryType());
   TaxClass(other.TaxClass());
   StartOfJob(other.StartOfJob());
   EndOfJob(other.EndOfJob());
   ReasonDeparture(other.ReasonDeparture());
   JobPosition(other.JobPosition());
   JobSpec(other.JobSpec());
   VacationDays(other.VacationDays());
   Department(other.Department());
   SocialNummer(other.SocialNummer());
   Active(other.Active());
   // copying the composed classes
   m_WD_NonWorking  = m_WD_NonWorking;
   m_WorkingTime    = m_WorkingTime;
   return;
   }

} // end of namespace myHR
