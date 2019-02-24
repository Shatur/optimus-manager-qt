#ifndef OPTIMUSMANAGER_H
#define OPTIMUSMANAGER_H

#include <QObject>

class QSystemTrayIcon;
class QMenu;

class OptimusManager : public QObject
{
    Q_OBJECT

public:
    enum Mode {
        Intel,
        Nvidia,
    };

    OptimusManager(QObject *parent = nullptr);
    virtual ~OptimusManager() override;


private slots:
    void switchToIntel();
    void switchToNvidia();
    void openSettings();

private:
    void switchMode(Mode mode);

    static Mode currentMode();

    QSystemTrayIcon *m_trayIcon;
    QMenu *m_contextMenu;
};

#endif // OPTIMUSMANAGER_H
