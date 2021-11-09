
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "Hitboy_RemasteredSystemComponent.h"

namespace Hitboy_Remastered
{
    class Hitboy_RemasteredModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(Hitboy_RemasteredModule, "{d2038896-9644-4091-a4c6-3772e3407146}", AZ::Module);
        AZ_CLASS_ALLOCATOR(Hitboy_RemasteredModule, AZ::SystemAllocator, 0);

        Hitboy_RemasteredModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                Hitboy_RemasteredSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<Hitboy_RemasteredSystemComponent>(),
            };
        }
    };
}// namespace Hitboy_Remastered

AZ_DECLARE_MODULE_CLASS(Gem_Hitboy_Remastered, Hitboy_Remastered::Hitboy_RemasteredModule)
