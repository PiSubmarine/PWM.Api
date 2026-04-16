#pragma once

#include <gmock/gmock.h>

#include <PiSubmarine/NormalizedFraction.h>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/PWM/Api/IDriver.h"

namespace PiSubmarine::PWM::Api
{
    class IDriverMock : public IDriver
    {
    public:
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), SetEnabled, (bool enabled), (override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<bool>), IsEnabled, (), (const, override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<Hertz>), GetFrequency, (), (const, override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), SetFrequency, (Hertz frequency), (override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<NormalizedFraction>), GetDutyCycle, (), (const, override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), SetDutyCycle, (NormalizedFraction duty), (override));
        MOCK_METHOD((PiSubmarine::Error::Api::Result<void>), SetFrequencyAndDuty, (Hertz frequency, NormalizedFraction duty), (override));
    };
}
