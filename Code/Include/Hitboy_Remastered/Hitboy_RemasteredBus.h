
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Hitboy_Remastered
{
    class Hitboy_RemasteredRequests
    {
    public:
        AZ_RTTI(Hitboy_RemasteredRequests, "{b72ad598-9f69-4c3a-a601-53d26dcc979d}");
        virtual ~Hitboy_RemasteredRequests() = default;
        // Put your public methods here
    };
    
    class Hitboy_RemasteredBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using Hitboy_RemasteredRequestBus = AZ::EBus<Hitboy_RemasteredRequests, Hitboy_RemasteredBusTraits>;
    using Hitboy_RemasteredInterface = AZ::Interface<Hitboy_RemasteredRequests>;

} // namespace Hitboy_Remastered
