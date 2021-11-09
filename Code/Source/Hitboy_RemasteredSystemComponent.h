
#pragma once

#include <AzCore/Component/Component.h>

#include <Hitboy_Remastered/Hitboy_RemasteredBus.h>

namespace Hitboy_Remastered
{
    class Hitboy_RemasteredSystemComponent
        : public AZ::Component
        , protected Hitboy_RemasteredRequestBus::Handler
    {
    public:
        AZ_COMPONENT(Hitboy_RemasteredSystemComponent, "{5656bb2e-3579-42dd-944d-c875691f5a1c}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        Hitboy_RemasteredSystemComponent();
        ~Hitboy_RemasteredSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // Hitboy_RemasteredRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
