#pragma once

#include <gmock/gmock.h>
#include <PiSubmarine/NormalizedFraction.h>
#include "PiSubmarine/PWM/Api/IDriver.h"

namespace PiSubmarine::PWM::Api
{
    class IDriverMock : public IDriver
    {
public:
        MOCK_METHOD(NormalizedFraction, GetDutyCycle, (), (const, override));
        MOCK_METHOD(void, SetDutyCycle, (NormalizedFraction duty), (override));
    };
}

