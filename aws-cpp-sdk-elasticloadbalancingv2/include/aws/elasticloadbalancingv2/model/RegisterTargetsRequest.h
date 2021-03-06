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

#pragma once
#include <aws/elasticloadbalancingv2/ElasticLoadBalancingv2_EXPORTS.h>
#include <aws/elasticloadbalancingv2/ElasticLoadBalancingv2Request.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/elasticloadbalancingv2/model/TargetDescription.h>
#include <utility>

namespace Aws
{
namespace ElasticLoadBalancingv2
{
namespace Model
{

  /**
   */
  class AWS_ELASTICLOADBALANCINGV2_API RegisterTargetsRequest : public ElasticLoadBalancingv2Request
  {
  public:
    RegisterTargetsRequest();
    
    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "RegisterTargets"; }

    Aws::String SerializePayload() const override;

  protected:
    void DumpBodyToUrl(Aws::Http::URI& uri ) const override;

  public:

    /**
     * <p>The Amazon Resource Name (ARN) of the target group.</p>
     */
    inline const Aws::String& GetTargetGroupArn() const{ return m_targetGroupArn; }

    /**
     * <p>The Amazon Resource Name (ARN) of the target group.</p>
     */
    inline void SetTargetGroupArn(const Aws::String& value) { m_targetGroupArnHasBeenSet = true; m_targetGroupArn = value; }

    /**
     * <p>The Amazon Resource Name (ARN) of the target group.</p>
     */
    inline void SetTargetGroupArn(Aws::String&& value) { m_targetGroupArnHasBeenSet = true; m_targetGroupArn = std::move(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the target group.</p>
     */
    inline void SetTargetGroupArn(const char* value) { m_targetGroupArnHasBeenSet = true; m_targetGroupArn.assign(value); }

    /**
     * <p>The Amazon Resource Name (ARN) of the target group.</p>
     */
    inline RegisterTargetsRequest& WithTargetGroupArn(const Aws::String& value) { SetTargetGroupArn(value); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the target group.</p>
     */
    inline RegisterTargetsRequest& WithTargetGroupArn(Aws::String&& value) { SetTargetGroupArn(std::move(value)); return *this;}

    /**
     * <p>The Amazon Resource Name (ARN) of the target group.</p>
     */
    inline RegisterTargetsRequest& WithTargetGroupArn(const char* value) { SetTargetGroupArn(value); return *this;}


    /**
     * <p>The targets.</p> <p>To register a target by instance ID, specify the instance
     * ID. To register a target by IP address, specify the IP address. To register a
     * Lambda function, specify the ARN of the Lambda function.</p>
     */
    inline const Aws::Vector<TargetDescription>& GetTargets() const{ return m_targets; }

    /**
     * <p>The targets.</p> <p>To register a target by instance ID, specify the instance
     * ID. To register a target by IP address, specify the IP address. To register a
     * Lambda function, specify the ARN of the Lambda function.</p>
     */
    inline void SetTargets(const Aws::Vector<TargetDescription>& value) { m_targetsHasBeenSet = true; m_targets = value; }

    /**
     * <p>The targets.</p> <p>To register a target by instance ID, specify the instance
     * ID. To register a target by IP address, specify the IP address. To register a
     * Lambda function, specify the ARN of the Lambda function.</p>
     */
    inline void SetTargets(Aws::Vector<TargetDescription>&& value) { m_targetsHasBeenSet = true; m_targets = std::move(value); }

    /**
     * <p>The targets.</p> <p>To register a target by instance ID, specify the instance
     * ID. To register a target by IP address, specify the IP address. To register a
     * Lambda function, specify the ARN of the Lambda function.</p>
     */
    inline RegisterTargetsRequest& WithTargets(const Aws::Vector<TargetDescription>& value) { SetTargets(value); return *this;}

    /**
     * <p>The targets.</p> <p>To register a target by instance ID, specify the instance
     * ID. To register a target by IP address, specify the IP address. To register a
     * Lambda function, specify the ARN of the Lambda function.</p>
     */
    inline RegisterTargetsRequest& WithTargets(Aws::Vector<TargetDescription>&& value) { SetTargets(std::move(value)); return *this;}

    /**
     * <p>The targets.</p> <p>To register a target by instance ID, specify the instance
     * ID. To register a target by IP address, specify the IP address. To register a
     * Lambda function, specify the ARN of the Lambda function.</p>
     */
    inline RegisterTargetsRequest& AddTargets(const TargetDescription& value) { m_targetsHasBeenSet = true; m_targets.push_back(value); return *this; }

    /**
     * <p>The targets.</p> <p>To register a target by instance ID, specify the instance
     * ID. To register a target by IP address, specify the IP address. To register a
     * Lambda function, specify the ARN of the Lambda function.</p>
     */
    inline RegisterTargetsRequest& AddTargets(TargetDescription&& value) { m_targetsHasBeenSet = true; m_targets.push_back(std::move(value)); return *this; }

  private:

    Aws::String m_targetGroupArn;
    bool m_targetGroupArnHasBeenSet;

    Aws::Vector<TargetDescription> m_targets;
    bool m_targetsHasBeenSet;
  };

} // namespace Model
} // namespace ElasticLoadBalancingv2
} // namespace Aws
