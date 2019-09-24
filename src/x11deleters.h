#ifndef X11DELETERS_H
#define X11DELETERS_H

#include <X11/extensions/Xrandr.h>

struct ProviderResourcesDeleter
{
    static inline void cleanup(XRRProviderResources *providerResources)
    {
        XRRFreeProviderResources(providerResources);
    }
};

struct ScreenResourcesDeleter
{
    static inline void cleanup(XRRScreenResources *screenResources)
    {
        XRRFreeScreenResources(screenResources);
    }
};

struct ProviderInfoDeleter
{
    static inline void cleanup(XRRProviderInfo *providerInfo)
    {
        XRRFreeProviderInfo(providerInfo);
    }
};


#endif // X11DELETERS_H
