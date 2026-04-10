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
            ProtocolError,
            UnsupportedParameter,
            UnknownError
        };

        virtual ~IDriver() = default;

        [[nodiscard]] virtual std::expected<Hertz, Error> GetFrequency() const = 0;
        [[nodiscard]] virtual Error SetFrequency(Hertz frequency) = 0;

        [[nodiscard]] virtual std::expected<NormalizedFraction, Error> GetDutyCycle() const = 0;
        virtual Error SetDutyCycle(NormalizedFraction duty) = 0;
    };
}

