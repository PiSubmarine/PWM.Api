#pragma once

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Hertz.h"
#include "PiSubmarine/NormalizedFraction.h"

namespace PiSubmarine::PWM::Api
{
    class IDriver
    {
    public:
        virtual ~IDriver() = default;

        // Enables or disables output signal generation.
        // When disabled, the latest configured signal is preserved and must be applied on next enable.
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> SetEnabled(bool enabled) = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<bool> IsEnabled() const = 0;

        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<Hertz> GetFrequency() const = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> SetFrequency(Hertz frequency) = 0;

        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<NormalizedFraction> GetDutyCycle() const = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> SetDutyCycle(NormalizedFraction duty) = 0;
        [[nodiscard]] virtual PiSubmarine::Error::Api::Result<void> SetFrequencyAndDuty(
            Hertz frequency,
            NormalizedFraction duty) = 0;
    };
}
