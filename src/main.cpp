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
