/*
 *  Copyright © 2019-2020 Hennadii Chernyshchyk <genaloner@gmail.com>
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

#include "appsettings.h"
#include "optimusmanager.h"
#include "singleapplication.h"

int main(int argc, char *argv[])
{
    SingleApplication app(argc, argv);
    SingleApplication::setApplicationName(QStringLiteral("Optimus Manager"));
    SingleApplication::setOrganizationName(QStringLiteral("optimus-manager"));
    SingleApplication::setApplicationVersion(QStringLiteral("1.4.6"));
    SingleApplication::setDesktopFileName(QStringLiteral("io.optimus_manager.OptimusManagerQt.desktop"));
    SingleApplication::setQuitOnLastWindowClosed(false);

    // Tray menu
    OptimusManager manager;

    return SingleApplication::exec();
}
