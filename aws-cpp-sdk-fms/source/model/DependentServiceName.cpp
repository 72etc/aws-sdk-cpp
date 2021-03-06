﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/fms/model/DependentServiceName.h>
#include <aws/core/utils/HashingUtils.h>
#include <aws/core/Globals.h>
#include <aws/core/utils/EnumParseOverflowContainer.h>

using namespace Aws::Utils;


namespace Aws
{
  namespace FMS
  {
    namespace Model
    {
      namespace DependentServiceNameMapper
      {

        static const int AWSCONFIG_HASH = HashingUtils::HashString("AWSCONFIG");
        static const int AWSWAF_HASH = HashingUtils::HashString("AWSWAF");


        DependentServiceName GetDependentServiceNameForName(const Aws::String& name)
        {
          int hashCode = HashingUtils::HashString(name.c_str());
          if (hashCode == AWSCONFIG_HASH)
          {
            return DependentServiceName::AWSCONFIG;
          }
          else if (hashCode == AWSWAF_HASH)
          {
            return DependentServiceName::AWSWAF;
          }
          EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
          if(overflowContainer)
          {
            overflowContainer->StoreOverflow(hashCode, name);
            return static_cast<DependentServiceName>(hashCode);
          }

          return DependentServiceName::NOT_SET;
        }

        Aws::String GetNameForDependentServiceName(DependentServiceName enumValue)
        {
          switch(enumValue)
          {
          case DependentServiceName::AWSCONFIG:
            return "AWSCONFIG";
          case DependentServiceName::AWSWAF:
            return "AWSWAF";
          default:
            EnumParseOverflowContainer* overflowContainer = Aws::GetEnumOverflowContainer();
            if(overflowContainer)
            {
              return overflowContainer->RetrieveOverflow(static_cast<int>(enumValue));
            }

            return {};
          }
        }

      } // namespace DependentServiceNameMapper
    } // namespace Model
  } // namespace FMS
} // namespace Aws
