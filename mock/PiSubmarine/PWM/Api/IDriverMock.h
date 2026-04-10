#pragma once

#include <gmock/gmock.h>
#include <PiSubmarine/NormalizedFraction.h>
#include "PiSubmarine/PWM/Api/IDriver.h"

namespace PiSubmarine::PWM::Api
{
    class IDriverMock : public IDriver
    {
public:
        MOCK_METHOD((std::expected<Hertz, Error>), GetFrequency, (), (const, override));
        MOCK_METHOD(Error, SetFrequency, (Hertz frequency), (override));
        MOCK_METHOD((std::expected<NormalizedFraction, Error>), GetDutyCycle, (), (const, override));
        MOCK_METHOD(Error, SetDutyCycle, (NormalizedFraction duty), (override));
    };
}

