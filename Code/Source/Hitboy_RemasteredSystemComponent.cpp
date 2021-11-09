
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "Hitboy_RemasteredSystemComponent.h"

namespace Hitboy_Remastered
{
    void Hitboy_RemasteredSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<Hitboy_RemasteredSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<Hitboy_RemasteredSystemComponent>("Hitboy_Remastered", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void Hitboy_RemasteredSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("Hitboy_RemasteredService"));
    }

    void Hitboy_RemasteredSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("Hitboy_RemasteredService"));
    }

    void Hitboy_RemasteredSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void Hitboy_RemasteredSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    Hitboy_RemasteredSystemComponent::Hitboy_RemasteredSystemComponent()
    {
        if (Hitboy_RemasteredInterface::Get() == nullptr)
        {
            Hitboy_RemasteredInterface::Register(this);
        }
    }

    Hitboy_RemasteredSystemComponent::~Hitboy_RemasteredSystemComponent()
    {
        if (Hitboy_RemasteredInterface::Get() == this)
        {
            Hitboy_RemasteredInterface::Unregister(this);
        }
    }

    void Hitboy_RemasteredSystemComponent::Init()
    {
    }

    void Hitboy_RemasteredSystemComponent::Activate()
    {
        Hitboy_RemasteredRequestBus::Handler::BusConnect();
    }

    void Hitboy_RemasteredSystemComponent::Deactivate()
    {
        Hitboy_RemasteredRequestBus::Handler::BusDisconnect();
    }
}
