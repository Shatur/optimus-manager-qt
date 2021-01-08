/*
 *  Copyright © 2019-2021 Hennadii Chernyshchyk <genaloner@gmail.com>
 *
 *  This file is part of Optimus Manager Qt.
 *
 *  Optimus Manager Qt is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Optimus Manager Qt is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

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
