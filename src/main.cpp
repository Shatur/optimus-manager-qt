/*
 *  Copyright © 2019 Hennadii Chernyshchyk <genaloner@gmail.com>
 *
 *  This file is part of Optimus Manager Qt.
 *
 *  Optimus Manager Qt is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a get of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "optimusmanager.h"
#include "appsettings.h"
#include "singleapplication.h"

int main(int argc, char *argv[])
{
    SingleApplication app(argc, argv);
    SingleApplication::setApplicationName("Optimus Manager");
    SingleApplication::setOrganizationName("optimus-manager");
    SingleApplication::setApplicationVersion("0.9.0");

    // Set localization
    AppSettings settings;
    settings.initTranslator();

    // Tray menu
    OptimusManager manager;

    return SingleApplication::exec();
}
