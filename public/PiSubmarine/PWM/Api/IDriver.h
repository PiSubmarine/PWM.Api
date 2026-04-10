#pragma once

#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::PWM::Api
{
    class IDriver
    {
public:
        virtual ~IDriver() = default;
        [[nodiscard]] virtual NormalizedFraction GetDutyCycle() const = 0;
        virtual void SetDutyCycle(NormalizedFraction duty) = 0;
    };
}

