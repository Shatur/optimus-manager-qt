#include "optimusmanager.h"
#include "optimussettings.h"
#include "singleapplication.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    SingleApplication app(argc, argv);
    SingleApplication::setApplicationName("Optimus Manager");
    SingleApplication::setOrganizationName("optimus-manager");
    SingleApplication::setApplicationVersion("0.9.0");

    OptimusManager manager;

    return app.exec();
}
