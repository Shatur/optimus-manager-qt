#include "optimusmanager.h"
#include "optimussettings.h"
#include "singleapplication.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    SingleApplication app(argc, argv);
    SingleApplication::setApplicationName("Optimus Manager");
    SingleApplication::setOrganizationName("optimus-manager");
    SingleApplication::setApplicationVersion("0.0.1");

    OptimusManager manager;

    return app.exec();
}
