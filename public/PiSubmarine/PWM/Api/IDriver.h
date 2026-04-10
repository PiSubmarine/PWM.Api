#pragma once

#include <expected>
#include "PiSubmarine/NormalizedFraction.h"
#include "PiSubmarine/Hertz.h"

namespace PiSubmarine::PWM::Api
{
    class IDriver
    {
public:
        enum class Error
        {
            Ok,
            Disabled,
            InvalidArgument,
            ProtocolError,
            UnsupportedParameter,
            Busy,
            IoFailure,
            UnknownError
        };

        virtual ~IDriver() = default;

        // Enables or disables output signal generation.
        // When disabled, the latest configured signal is preserved and must be applied on next enable.
        [[nodiscard]] virtual Error SetEnabled(bool enabled) = 0;
        [[nodiscard]] virtual bool IsEnabled() const = 0;

        [[nodiscard]] virtual std::expected<Hertz, Error> GetFrequency() const = 0;
        [[nodiscard]] virtual Error SetFrequency(Hertz frequency) = 0;

        [[nodiscard]] virtual std::expected<NormalizedFraction, Error> GetDutyCycle() const = 0;
        [[nodiscard]] virtual Error SetDutyCycle(NormalizedFraction duty) = 0;
        [[nodiscard]] virtual Error SetFrequencyAndDuty(Hertz frequency, NormalizedFraction duty) = 0;
    };
}


