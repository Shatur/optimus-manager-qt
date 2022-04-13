/*
 *  Copyright © 2019-2022 Hennadii Chernyshchyk <genaloner@gmail.com>
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
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "appsettings.h"
#include "cmake.h"
#include "optimusmanager.h"
#include "singleapplication.h"

int main(int argc, char *argv[])
{
    SingleApplication app(argc, argv);
    QCoreApplication::setApplicationName(QStringLiteral(APPLICATION_NAME));
    QCoreApplication::setOrganizationName(QStringLiteral(ORGANIZATION_NAME));
    QCoreApplication::setApplicationVersion(QStringLiteral("%1.%2.%3").arg(VERSION_MAJOR).arg(VERSION_MINOR).arg(VERSION_PATCH));
    QGuiApplication::setDesktopFileName(QStringLiteral(DESKTOP_FILE));
    QGuiApplication::setQuitOnLastWindowClosed(false);

    // Tray menu
    OptimusManager manager;

    return QCoreApplication::exec();
}
