/*
* Project: model with a simple person administration
* Definition of the base class TSimplePersonBase
* Date: 14.03.2024 23:56:52,855  file created with adecc Scholar metadata generator
* copyright © adecc Systemhaus GmbH 2024, All rights reserved.
* This project is released under the MIT License.
*/

#pragma once

namespace myCorporate {

class TSimplePersonBase {
   public:
      TSimplePersonBase() = default;
      TSimplePersonBase(TSimplePersonBase const&) = default;
      TSimplePersonBase(TSimplePersonBase&&) noexcept = default;
      virtual ~TSimplePersonBase() = default;

      virtual void init() = 0;
      virtual void copy(TSimplePersonBase const&) = 0;
   };

} // end of namespace myCorporate
