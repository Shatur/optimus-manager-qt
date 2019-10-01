<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="de" sourcelanguage="en">
<context>
    <name>AppSettings</name>
    <message>
        <location filename="../../src/appsettings.cpp" line="75"/>
        <source>Unable to create autorun file from &apos;%1&apos;</source>
        <translation>Konnte keine autorun-Datei erstellen aus %1</translation>
    </message>
</context>
<context>
    <name>DaemonClient</name>
    <message>
        <location filename="../../src/daemonclient.cpp" line="109"/>
        <source>Unable to open startup mode file</source>
        <translation type="unfinished">Konnte Startup-Datei nicht öffnen</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="361"/>
        <location filename="../../src/settingsdialog.cpp" line="128"/>
        <source>Unable to connect to Optimus Manager daemon: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="371"/>
        <source>Unable to send GPU name to switch to Optimus Manager daemon: %1</source>
        <translation type="unfinished">Konnte GPU-Namen für den Wechsel nicht an Optimus-Manager-daemon senden: %1</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="143"/>
        <source>Unable to send configuration file to Optimus Manager daemon: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="152"/>
        <source>Unable to send startup mode to Optimus Manager daemon: %1</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>OptimusManager</name>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="182"/>
        <source>Switch to Intel</source>
        <translation>Wechsel auf Intel</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="183"/>
        <source>Switch to Nvidia</source>
        <translation>Wechsel auf Nvidia</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="60"/>
        <location filename="../../src/optimusmanager.cpp" line="184"/>
        <source>Exit</source>
        <translation>Schließen</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="55"/>
        <location filename="../../src/optimusmanager.cpp" line="56"/>
        <location filename="../../src/optimusmanager.cpp" line="57"/>
        <source>Switch to %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="160"/>
        <location filename="../../src/optimusmanager.cpp" line="170"/>
        <source>The specified icon &apos;%1&apos; for the current GPU is invalid. The default icon will be used.</source>
        <translation>Der angegebene Icon &apos;%1&apos; für die aktuelle GPU ist ungültig. Der Standard-Icon wird nun verwendet.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="197"/>
        <source>You are about to switch GPU.</source>
        <translation>GPU wird nun gewechselt.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="199"/>
        <source>You will be automatically logged out to apply the changes.</source>
        <translation>Sie werden automatisch ausgeloggt um die Änderungen zu aktivieren.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="210"/>
        <source>No power management option is currently enabled</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="211"/>
        <source>Switching between GPUs will work but you will likely experience poor battery life.
If you have already enabled the new Runtime D3 power management inside the Nvidia driver (for Turing+ GPU with Coffee Lake+ CPU), you can safely ignore this warning.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="221"/>
        <source>The Optimus Manager service is not running.</source>
        <translation>Der Optimus-Manager-Service ist nicht aktiv.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="270"/>
        <source>There are %1 other desktop sessions open. The GPU switch will not become effective until you have manually logged out from ALL desktop sessions.
Continue?</source>
        <translation>Es sind %1 andere Desktopsitzungen offen. Der GPU-Wechsel wird erst durchgeführt, wenn alle Desktopsitzungen abgemeldet werden.
Fortfahren?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="284"/>
        <source>Wayland session found.</source>
        <translation>Wayland-Sitzung gefunden.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="285"/>
        <source>Session %1, started by %2, is a Wayland session. Wayland is not supported by Optimus Manager, so GPU switching may fail.
Continue anyway?</source>
        <translation>Sitzung %1, gestartet von %2, ist eine Wayland-Sitzung. Wayland wird von Optimus Manager nicht unterstützt, GPU-Wechsel kann also fehlschlagen.
Trotzdem fortfahren?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="302"/>
        <source>The Bumblebee service (%1) is running.</source>
        <translation>Der Bumblebee-Service (%1) ist aktiv.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="345"/>
        <source>The Xorg driver &apos;%1&apos; is not installed.</source>
        <translation>Der Xorg-Treiber &apos;%1&apos; ist nicht installiert.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="346"/>
        <source>Optimus Manager will use &apos;%1&apos; driver instead. You can change driver in settings or install the &apos;%2&apos; driver from the package &apos;%3&apos;.
Continue anyway?</source>
        <translation>Optimus Manager wird den &apos;%1&apos;-Treiber stattdessen verwenden. Der Treiber kann in den Einstellungen geändert werden oder der &apos;%2&apos;-Treiber aus dem Paket &apos;%3&apos; installiert werden.
Trotzdem fortfahren?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="317"/>
        <source>If you did not create it yourself, it was likely generated by your distribution or by an Nvidia utility.
This file may contain hard-coded GPU configuration that could interfere with Optimus Manager, so it is recommended that you delete it before proceeding.
Ignore this warning and proceed with GPU switching?</source>
        <translation>Wenn Sie es nicht selbst erstellt haben, wurde es wahrscheinlich von ihrer Distribution oder einem Nvidia-Utility automatisch generiert.
Die Datei könnte fest eingebaute GPU-Konfigurationen enthalten, die mit Optimus-Manager in Konflikt stehen könnten. Darum wird empfohlen sie vor dem Fortfahren zu löschen.
Warnung ignorieren und mit GPU-Wechsel fortfahren?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="331"/>
        <source>This file was auto-generated by the Manjaro driver utility (MHWD). This will likely interfere with GPU switching, so Optimus Manager will delete this file automatically if you proceded with GPU switching.
Proceed?</source>
        <translation>Diese Datei wurde vom Manjaro driver utility (MHWD) automatisch generiert. Sie wird wahrscheinlich einen Konflikt mit dem GPU-Wechsel auslösen, Optimus Manager wird die Datei also löschen, falls sie mit dem GPU-Wechsel fortfahren.
Fortfahren?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="201"/>
        <source>After applying the settings, you will need to manually re-login to change the video card.</source>
        <translation>Nach dem Ändern der Einstellungen muss manuell ein neuer Login durchgeführt werden um die GPU zu wechseln.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="68"/>
        <location filename="../../src/optimusmanager.cpp" line="179"/>
        <source>Current videocard: %1</source>
        <translation>Aktuelle GPU: %1</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="222"/>
        <source>Please enable and start it with:
&apos;%1&apos;
&apos;%2&apos;</source>
        <translation>Bitte aktivieren und starten mit:
&apos;%1&apos;
&apos;%2&apos;</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="232"/>
        <location filename="../../src/optimusmanager.cpp" line="244"/>
        <source>The %1 module does not seem to be available for the current kernel.</source>
        <translation>Das Modul %1 scheint für den aktuellen Kernel nicht verfügbar zu sein.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="233"/>
        <source>Power switching will not work.
You can set &apos;%1&apos; for GPU switching in settings or install bbswitch forthe default kernel with &apos;%2&apos; or for all kernels with &apos;%3&apos;.</source>
        <translation>Power switching wird nicht funktionieren.
Sie können &apos;%1&apos; für GPU switching in den Einstellungen setzen oder bbswitch für den Default-Kernel mit &apos;%2&apos; oder für alle Kernel mit &apos;%3&apos; installieren.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="245"/>
        <source>It is likely the Nvidia driver was not properly installed. GPU switching will probably fail, continue anyway?</source>
        <translation>Der Nvidia-Treiber ist wahrscheinlich nicht installiert. Der GPU-Wechsel wird wahrscheinlich fehlschlagen, trotzdem fortfahren?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="255"/>
        <source>Looks like you&apos;re using a non-patched version of the Gnome Display Manager (GDM).</source>
        <translation>Es wirkt als wäre eine nicht gepatchte Version des Gnome Display Managers (GDM) installiert.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="256"/>
        <source>GDM need to be patched for Prime switching. Follow &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;this&lt;/a&gt; instructions to install a patched version. Without a patched GDM version, GPU switching will likely fail.
Continue anyway?</source>
        <translation>GDM muss für Prime-switching gepatcht sein. Folgen Sie &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;diesen&lt;/a&gt; Anweisungen um eine gepatchte Version zu installieren. Ohne gepatchte GDM-Version wird ein GPU-Wechsel wahrscheinlich fehlschlagen.
Trotzdem fortfahren?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="269"/>
        <source>Multiple running sessions detected.</source>
        <translation>Mehrere laufende Sitzungen gefunden.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="303"/>
        <source>This can interfere with Optimus Manager. Before attempting a GPU switch, it is recommended that you disable this service with &apos;%1&apos; and reboot your computer.
Ignore this warning and proceed with GPU switching now?</source>
        <translation>Steht eventuell mit Optimus-Manager in Konflikt. Es wird empfohlen vor dem GPU-Wechsel diesen Service mit &apos;%1&apos; zu deaktiviern und den PC neu zu starten.
Warnung ignorieren und mit GPU-Wechsel fortfahren?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="316"/>
        <location filename="../../src/optimusmanager.cpp" line="330"/>
        <source>Found a Xorg config file at &apos;%1&apos;.</source>
        <translation>Xorg-Konfigurationsdatei gefunden: &apos;%1&apos;.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="378"/>
        <source>Configuration successfully applied. Your GPU will be switched after next login.</source>
        <translation>Konfiguration erfolgreich geändert. Die GPU wird beim nächsten Login gewechselt.</translation>
    </message>
</context>
<context>
    <name>SettingsDialog</name>
    <message>
        <location filename="../../src/settingsdialog.ui" line="14"/>
        <location filename="../../src/optimusmanager.cpp" line="51"/>
        <location filename="../../src/optimusmanager.cpp" line="181"/>
        <source>Settings</source>
        <translation>Einstellungen</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="59"/>
        <location filename="../../src/settingsdialog.ui" line="118"/>
        <source>General</source>
        <translation>Allgemein</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="104"/>
        <source>About</source>
        <translation>Über</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="214"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Application language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Anwendungs-Sprache&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="217"/>
        <source>Language:</source>
        <translation>Sprache:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="128"/>
        <source>&lt;System language&gt;</source>
        <translation>&lt;Systemstandard&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="240"/>
        <source>Launch at startup</source>
        <translation>Starten beim Systemstart</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="247"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Show confirmation dialog when switching GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Zeige Bestätigungsdialog vor dem GPU-Wechsel&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="250"/>
        <source>Confirm switching</source>
        <translation>Bestätigen vor GPU-Wechsel</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="301"/>
        <source>Nvidia icon:</source>
        <translation>Nvidia Icon:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="287"/>
        <source>Intel icon:</source>
        <translation>Intel Icon:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="381"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Specify which GPU will be used by default when the system boots&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Legt die Standard-GPU für den Systemstart fest&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="600"/>
        <source>ACPI call</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="571"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable PCI power management in Intel mode&lt;/p&gt;&lt;p&gt;This option is incompatible with ACPI call and Bbswitch switching methods, so it will be ignored in those cases&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="608"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Module used for power switching&lt;/p&gt;&lt;p&gt;If you select &amp;quot;None&amp;quot;, no power switching will be done at all (the Nvidia GPU will stay powered at all times)&lt;/p&gt;&lt;p&gt;If you use bbswitch, you will not be able to use video outputs attached to your Nvidia GPU in Intel mode&lt;/p&gt;&lt;p&gt;To use the bbswitch mode, the bbswitch module must be installed for your current kernel&lt;/p&gt;&lt;p&gt;You can install it for the default kernel with &amp;quot;pacman -S bbswitch&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Modul das für Power-Switching verwendet wird&lt;/p&gt;&lt;p&gt;Bei Auswahl von &amp;quot;Keines&amp;quot;, wird kein Power-Switching durchgeführt(Nvidia-GPU bleibt durchgehend mit Strom versorgt)&lt;/p&gt;&lt;p&gt;Wird bbswitch verwendet, können Video-Ausgänge, die mit der Nvidia-GPU verbunden sind, im Intel-Modus nicht verwendet werden&lt;/p&gt;&lt;p&gt;Um bbswitch verwenden zu können muss es für ihren aktuellen Kernel installiert sein&lt;/p&gt;&lt;p&gt;Für den Standard-Kernel kann es mit &amp;quot;pacman -S bbswitch&amp;quot; installiert werden&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="534"/>
        <source>Automatic logout</source>
        <translation>Automatisch ausloggen</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="561"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Remove the Nvidia card from the PCI bus&lt;/p&gt;&lt;p&gt;May prevent crashes caused by power switching&lt;/p&gt;&lt;p&gt;Ignored if switching method is Nouveau or Bbswitch&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="769"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable modesetting for the nouveau driver&lt;/p&gt;&lt;p&gt;Does not affect modesetting for the Intel GPU driver&lt;/p&gt;&lt;p&gt;This option is incompatible with Bbswitch and will be ignored if it is enabled&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="812"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;This will be set using the Xsetup script passed to your login manager&lt;br/&gt;It will run the command&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Leave 0 for the default&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Wird mit dem Xsetup-script gesetzt, das dem Login-Manager übergeben wird&lt;br/&gt;Führt den folgenden Befehl aus:&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;0 für Default&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="845"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable the NVreg_UsePageAttributeTable option in the Nvidia driver &lt;span style=&quot; font-style:italic;&quot;&gt;Recommended&lt;/span&gt;, can cause poor CPU performance otherwise&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Entscheidet über das setzen der Option NVreg_UsePageAttributeTable im Nvidia-Treiber &lt;span style=&quot; font-style:italic;&quot;&gt;Empfohlen&lt;/span&gt;, kann ansonsten zu schlechter Performance führen&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="855"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable CoolBits in the Xorg configuration, which unlocks clocking options&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="858"/>
        <source>Overclocking options</source>
        <translation>Übertaktungsoptionen</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="237"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart will be used&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart wird verwendet&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="260"/>
        <source>Tray icons</source>
        <translation>Taskleistensymbole</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="266"/>
        <location filename="../../src/settingsdialog.ui" line="273"/>
        <source>Choose icon</source>
        <translation>Wähle ein Symbol</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="384"/>
        <source>Startup mode:</source>
        <translation>Modus zum Systemstart:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="585"/>
        <source>None</source>
        <translation>Keines</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="124"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Interface language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Interface-Sprache&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="280"/>
        <location filename="../../src/settingsdialog.ui" line="294"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Path to the icon or icon name from theme&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Pfad zum Icon oder Icon-Name aus dem Theme&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="347"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU that will be used during normal system startup&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU die beim normalen Systemstart verwendet werden soll&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="644"/>
        <source>Driver:</source>
        <translation>Treiber:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="939"/>
        <location filename="../../src/settingsdialog.ui" line="1033"/>
        <source>Author:</source>
        <translation>Autor:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="685"/>
        <source>Acceleration method:</source>
        <translation>Beschleunigungs-Methode:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="308"/>
        <source>Hybrid icon:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="581"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Method to power switch the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;None&lt;/span&gt;: do not use an external module for power management (for some laptop models it&apos;s preferable to use this option in combination with PCI power control), you can use the scipts nvidia-enable.sh and nvidia-disable.sh to execute custom commands for power management that will be executed only with this method&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nouveau&lt;/span&gt;: load the nouveau module on the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Bbswitch&lt;/span&gt;: power off the card using the bbswitch module (requires the &amp;quot;bbswitch&amp;quot;dependency)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;ACPI call&lt;/span&gt;: try various ACPI method calls to power the card on and off (requires the &amp;quot;acpi_call&amp;quot; dependency)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="611"/>
        <source>Switching method:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="531"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Automatically log out the current desktop session when switching GPUs&lt;/p&gt;&lt;p&gt;This feature is currently supported for Gnome, KDE Plasma, Deepin, Xfce, i3, Sway, Openbox, AwesomeWM and bspwm&lt;/p&gt;&lt;p&gt;If this options is disabled or you use a different desktop environment, GPU switching only becomes effective at the next graphical session login&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="541"/>
        <source>PCI reset:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="509"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Reset the Nvidia card at the PCI level before reloading the nvidia module&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;No&lt;/span&gt;: does not perform any reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Function level&lt;/span&gt;: perform a light &amp;quot;function-level&amp;quot; reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Hot reset&lt;/span&gt;: perform a &amp;quot;hot reset&amp;quot; of the PCI bridge (this method messes with the hardware directly and will perform a PCI remove even if it disabled, please read the online documentation of Optimus Manager before using it)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="68"/>
        <source>Configuration files</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="341"/>
        <source>Startup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="407"/>
        <source>Optimus Manager config</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="413"/>
        <source>Type:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="423"/>
        <source>Path:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="436"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Type of the configuration&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Permanent&lt;/span&gt;: configuration file that will be used every time it starts&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Temporary&lt;/span&gt;: configuration file that will be used only once at the next boot&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="440"/>
        <source>Permanent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="445"/>
        <source>Temporary</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="456"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Path to configuration file that will be loaded&lt;/p&gt;&lt;p&gt;If such a file does not exist, then it will be created automatically&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="459"/>
        <source>Path to configuration file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="469"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Browse configuration file&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="472"/>
        <source>Browse</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="518"/>
        <source>Function level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="523"/>
        <source>Hot reset</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="564"/>
        <source>PCI remove</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="668"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Driver to use for the Intel GPU&lt;br/&gt;&lt;br/&gt;To use the Intel driver, you need to install the package &amp;quot;xf86-video-intel&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="702"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable TearFree option in the Xorg configuration&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="706"/>
        <location filename="../../src/settingsdialog.ui" line="738"/>
        <source>Default</source>
        <translation>Standard</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="711"/>
        <source>Yes</source>
        <translation>Ja</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="513"/>
        <location filename="../../src/settingsdialog.ui" line="716"/>
        <source>No</source>
        <translation>Nein</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="651"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;DRI version&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;DRI Version&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="574"/>
        <source>PCI power control</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="734"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Acceleration method (corresponds to AccelMethod in the Xorg configuration)&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="835"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable modesetting&lt;/p&gt;&lt;p&gt;Required for PRIME Synchronization (which prevents tearing)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="865"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable triple buffering&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Dreifachpufferung aktivieren&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="868"/>
        <source>Triple buffer</source>
        <translation>Dreifachpufferung</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="925"/>
        <location filename="../../src/settingsdialog.ui" line="1056"/>
        <source>Version:</source>
        <translation>Version:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="946"/>
        <location filename="../../src/settingsdialog.ui" line="1070"/>
        <source>License:</source>
        <translation>Lizenz:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="311"/>
        <source>Select temporary configuration file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="312"/>
        <source>Config files (*.conf);;All files(*)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="358"/>
        <source>Select icon</source>
        <translation>Wähle ein Symbol</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="359"/>
        <source>Images (*.png *.jpg *.bmp);;All files(*)</source>
        <translation>Bilder (*.png *.jpg *.bmp);;Alle Dateien(*)</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="378"/>
        <source>Unable to find Optimus Manager daemon.</source>
        <translation>Konnte optimus-manager daemon nicht finden.</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="379"/>
        <source>Please check the integrity of the package that provides Optimus Manager.</source>
        <translation>Bitte die Integrität des Pakets, das optimus-manager zur Verfügung stellt, prüfen.</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="381"/>
        <source>Not found!</source>
        <translation>Nicht gefunden!</translation>
    </message>
</context>
</TS>
