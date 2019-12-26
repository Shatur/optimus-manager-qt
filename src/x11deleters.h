#ifndef X11DELETERS_H
#define X11DELETERS_H

class _XRRProviderResources;
class _XRRScreenResources;
class _XRRProviderInfo;
using XRRProviderResources = _XRRProviderResources;
using XRRScreenResources = _XRRScreenResources;
using XRRProviderInfo = _XRRProviderInfo;

struct ProviderResourcesDeleter
{
    static void cleanup(XRRProviderResources *providerResources);
};

struct ScreenResourcesDeleter
{
    static void cleanup(XRRScreenResources *screenResources);
};

struct ProviderInfoDeleter
{
    static void cleanup(XRRProviderInfo *providerInfo);
};


#endif // X11DELETERS_H
