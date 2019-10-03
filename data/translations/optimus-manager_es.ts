<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="es">
<context>
    <name>AppSettings</name>
    <message>
        <location filename="../../src/appsettings.cpp" line="75"/>
        <source>Unable to create autorun file from &apos;%1&apos;</source>
        <translation>No se puede crear el fichero &apos;autorun&apos; a partir de &apos;%1&apos;</translation>
    </message>
</context>
<context>
    <name>DaemonClient</name>
    <message>
        <location filename="../../src/daemonclient.cpp" line="109"/>
        <source>Unable to open startup mode file</source>
        <translation type="unfinished">No se pudo abrir el fichero de modo de encendido</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="361"/>
        <location filename="../../src/settingsdialog.cpp" line="113"/>
        <source>Unable to connect to Optimus Manager daemon: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="371"/>
        <source>Unable to send GPU name to switch to Optimus Manager daemon: %1</source>
        <translation type="unfinished">No se pudo enviar el nombre de la GPU al demonio de Optimus Manager: %1</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="128"/>
        <source>Unable to send configuration file to Optimus Manager daemon: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="137"/>
        <source>Unable to send startup mode to Optimus Manager daemon: %1</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>OptimusManager</name>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="182"/>
        <source>Switch to Intel</source>
        <translation>Cambiar a Intel</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="183"/>
        <source>Switch to Nvidia</source>
        <translation>Cambiar a Nvidia</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="60"/>
        <location filename="../../src/optimusmanager.cpp" line="184"/>
        <source>Exit</source>
        <translation>Salir</translation>
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
        <translation>El icono especificado &apos;%1&apos; para la GPU no es aceptado. Un icono por defecto se usará en su lugar.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="197"/>
        <source>You are about to switch GPU.</source>
        <translation>Estas a punto de cambiar de GPU.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="199"/>
        <source>You will be automatically logged out to apply the changes.</source>
        <translation>Se te deslogueará automaticamente para aplicar los cambios.</translation>
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
        <translation>El servicio Optimus Manager no se encuentra en ejecución.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="270"/>
        <source>There are %1 other desktop sessions open. The GPU switch will not become effective until you have manually logged out from ALL desktop sessions.
Continue?</source>
        <translation>Hay otras %1 sesiones de escritorio abiertas. El cambio de GPU no se hará efectivo hasta que te desloguees manualmente de TODAS tus sesiones de escritorio.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="284"/>
        <source>Wayland session found.</source>
        <translation>Sesion Wayland encontrada.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="285"/>
        <source>Session %1, started by %2, is a Wayland session. Wayland is not supported by Optimus Manager, so GPU switching may fail.
Continue anyway?</source>
        <translation>La sesión %1, iniciada por %2, es una sesión Wayland. Wayland no está soportado por Optimus Manager, asique el cambio de GPU podría fallar.
Continuar de todas formas?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="302"/>
        <source>The Bumblebee service (%1) is running.</source>
        <translation>El servicio Bumblebee (%1) se encuentra en ejecución.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="345"/>
        <source>The Xorg driver &apos;%1&apos; is not installed.</source>
        <translation>El driver Xorg &apos;%1&apos; no se encuentra instalado.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="346"/>
        <source>Optimus Manager will use &apos;%1&apos; driver instead. You can change driver in settings or install the &apos;%2&apos; driver from the package &apos;%3&apos;.
Continue anyway?</source>
        <translation>Optimus Manager usará el driver &apos;%1&apos; en su lugar. Puedes cambiar de driver en la configuración, o instalar el driver &apos;%2&apos; con el paquete &apos;%3&apos;.
Continuar de todos modos?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="317"/>
        <source>If you did not create it yourself, it was likely generated by your distribution or by an Nvidia utility.
This file may contain hard-coded GPU configuration that could interfere with Optimus Manager, so it is recommended that you delete it before proceeding.
Ignore this warning and proceed with GPU switching?</source>
        <translation>Si no lo has creado tu, seguramente fué generado por tu distribución o por una utilidad de Nvidia.
Este fichero podría contener una configuración que interfiera con Optimus Manager, y se recomienda que lo borres manualmente antes de proceder.
Ignorar esta advertencia y proceder con el cambio de GPU?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="331"/>
        <source>This file was auto-generated by the Manjaro driver utility (MHWD). This will likely interfere with GPU switching, so Optimus Manager will delete this file automatically if you proceded with GPU switching.
Proceed?</source>
        <translation>Este fichero fué autogenerado por Manjaro driver utility (MHWD). Esto podría interferir con el cambio de GPU, así que Optimis Manager borrará este fichero automáticamente si procedes con el cambio de GPU.
Proceder?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="201"/>
        <source>After applying the settings, you will need to manually re-login to change the video card.</source>
        <translation>Tras aplicar la configuración, tendrás que re-loguear manualmente para cambiar de tarjeta de video.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="68"/>
        <location filename="../../src/optimusmanager.cpp" line="179"/>
        <source>Current videocard: %1</source>
        <translation>GPU Actual: %1</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="222"/>
        <source>Please enable and start it with:
&apos;%1&apos;
&apos;%2&apos;</source>
        <translation>Por favor actívalo e inicialo con:
&apos;%1&apos;
&apos;%2&apos;</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="232"/>
        <location filename="../../src/optimusmanager.cpp" line="244"/>
        <source>The %1 module does not seem to be available for the current kernel.</source>
        <translation>El módulo %1 no parece estar disponible para tu kernel actual.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="233"/>
        <source>Power switching will not work.
You can set &apos;%1&apos; for GPU switching in settings or install bbswitch forthe default kernel with &apos;%2&apos; or for all kernels with &apos;%3&apos;.</source>
        <translation>El cambio de potencia no funcionará.
Puedes definir &apos;%1&apos; para el cambio de GPU en la configuración o instalar bbswitch para tu kernel por defecto con &apos;%2&apos; o para todos los kernels con &apos;%3&apos;.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="245"/>
        <source>It is likely the Nvidia driver was not properly installed. GPU switching will probably fail, continue anyway?</source>
        <translation>Es probable que el driver de Nvidia no se encuentre correctamente instalado. El cambio de GPU podría fallar, continuar de todas formas?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="255"/>
        <source>Looks like you&apos;re using a non-patched version of the Gnome Display Manager (GDM).</source>
        <translation>Parece que estas usando una version no parcheada de Gnome Display Manager (GDM).</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="256"/>
        <source>GDM need to be patched for Prime switching. Follow &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;this&lt;/a&gt; instructions to install a patched version. Without a patched GDM version, GPU switching will likely fail.
Continue anyway?</source>
        <translation>GDM necesita ser parcheado para el cambio Prime. Sigue &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;estas&lt;/a&gt; instrucciones para instalar la versión parcheada. Sin una versión parcheada de GDM, el cambio de GPU probablemente falle.
Continuar de todas formas?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="269"/>
        <source>Multiple running sessions detected.</source>
        <translation>Se han detectado múltiples sesiones simultaneas.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="303"/>
        <source>This can interfere with Optimus Manager. Before attempting a GPU switch, it is recommended that you disable this service with &apos;%1&apos; and reboot your computer.
Ignore this warning and proceed with GPU switching now?</source>
        <translation>Esto puede interferir con Optimus Manager. Antes de intentar un cambio de GPU, es recomendable que deshabilites el servicio con &apos;%1&apos; y reinícies tu equipo.
Quieres ignorar esta advertencia y proceder con el cambio de GPU?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="316"/>
        <location filename="../../src/optimusmanager.cpp" line="330"/>
        <source>Found a Xorg config file at &apos;%1&apos;.</source>
        <translation>Encontrado fichero de configuración de Xorg en &apos;%1&apos;.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="378"/>
        <source>Configuration successfully applied. Your GPU will be switched after next login.</source>
        <translation>Configuración aplicada con éxito. Tu GPU en uso cambiará tras tu próximo login.</translation>
    </message>
</context>
<context>
    <name>SettingsDialog</name>
    <message>
        <location filename="../../src/settingsdialog.ui" line="14"/>
        <location filename="../../src/optimusmanager.cpp" line="51"/>
        <location filename="../../src/optimusmanager.cpp" line="181"/>
        <source>Settings</source>
        <translation>Configuración</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="59"/>
        <location filename="../../src/settingsdialog.ui" line="118"/>
        <source>General</source>
        <translation>General</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="104"/>
        <source>About</source>
        <translation>Acerca de</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="214"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Application language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Lenguaje de la aplicación.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="217"/>
        <source>Language:</source>
        <translation>Lenguaje:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="128"/>
        <source>&lt;System language&gt;</source>
        <translation>&lt;Idioma del sistema&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="240"/>
        <source>Launch at startup</source>
        <translation>Lanzar al inicio</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="247"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Show confirmation dialog when switching GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Mostrar mensaje de confirmación al cambiar de GPU.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="250"/>
        <source>Confirm switching</source>
        <translation>Confirmar cambio de GPU</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="301"/>
        <source>Nvidia icon:</source>
        <translation>Icono de Nvidia:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="287"/>
        <source>Intel icon:</source>
        <translation>Icono de Intel:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="381"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Specify which GPU will be used by default when the system boots&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Especificar que GPU será usada por defecto cuando el sistema se reinicie.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="649"/>
        <source>ACPI call</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="657"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Module used for power switching&lt;/p&gt;&lt;p&gt;If you select &amp;quot;None&amp;quot;, no power switching will be done at all (the Nvidia GPU will stay powered at all times)&lt;/p&gt;&lt;p&gt;If you use bbswitch, you will not be able to use video outputs attached to your Nvidia GPU in Intel mode&lt;/p&gt;&lt;p&gt;To use the bbswitch mode, the bbswitch module must be installed for your current kernel&lt;/p&gt;&lt;p&gt;You can install it for the default kernel with &amp;quot;pacman -S bbswitch&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Modulo usado para la administración de nergía al cambia de GPU.&lt;/p&gt;&lt;p&gt;Si seleccionas &amp;quot;Ninguno&amp;quot;, No se aplicarán cambios en la gestión de energía (La GPU nvidia permanecerá encendida todo el tiempo)&lt;/p&gt;&lt;p&gt;Si utilizas bbswitch , no podrás usar salidas de video asociadas a tu GPU nvidia en modo Intel.&lt;/p&gt;&lt;p&gt;Para utilizar el modo bbswitch, el modulo bbswitch debe estar instalado en tu kernel.&lt;/p&gt;&lt;p&gt;Puedes instalarlo para el kernel predeterminado con &amp;quot;pacman -S bbswitch&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="583"/>
        <source>Automatic logout</source>
        <translation>Logout automático</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="818"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable modesetting for the nouveau driver&lt;/p&gt;&lt;p&gt;Does not affect modesetting for the Intel GPU driver&lt;/p&gt;&lt;p&gt;This option is incompatible with Bbswitch and will be ignored if it is enabled&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="861"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;This will be set using the Xsetup script passed to your login manager&lt;br/&gt;It will run the command&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Leave 0 for the default&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Será definido utilizando el script Xsetup pasado a tu gestor de inicio de sesión.&lt;br/&gt;Ejecutará el comando&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Deja 0 para usar el valor por defecto.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="894"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable the NVreg_UsePageAttributeTable option in the Nvidia driver &lt;span style=&quot; font-style:italic;&quot;&gt;Recommended&lt;/span&gt;, can cause poor CPU performance otherwise&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Activar, o no, la opción NVreg_UsePageAttributeTable en el driver Nvidia.&lt;span style=&quot; font-style:italic;&quot;&gt;Recomendado&lt;/span&gt;, de lo contrario puede causar bajo rendimiento de CPU.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="904"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable CoolBits in the Xorg configuration, which unlocks clocking options&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="907"/>
        <source>Overclocking options</source>
        <translation>Opciones de overclocking</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="237"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart will be used&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart será utilizado.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="260"/>
        <source>Tray icons</source>
        <translation>Icono de bandeja</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="266"/>
        <location filename="../../src/settingsdialog.ui" line="273"/>
        <source>Choose icon</source>
        <translation>Elegir icono</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="384"/>
        <source>Startup mode:</source>
        <translation>Modo de inicio:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="634"/>
        <source>None</source>
        <translation>Ninguno</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="124"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Interface language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Idioma de la interfaz&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="280"/>
        <location filename="../../src/settingsdialog.ui" line="294"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Path to the icon or icon name from theme&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Ruta al icóno o nombre del icóno del tema&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="347"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU that will be used during normal system startup&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU que será usada durante el inicio normal del sistema&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="693"/>
        <source>Driver:</source>
        <translation>Driver:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="734"/>
        <source>Acceleration method:</source>
        <translation>Método de aceleración:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="755"/>
        <location filename="../../src/settingsdialog.ui" line="787"/>
        <source>Default</source>
        <translation>Predeterminado</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="760"/>
        <source>Yes</source>
        <translation>Si</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="562"/>
        <location filename="../../src/settingsdialog.ui" line="765"/>
        <source>No</source>
        <translation>No</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="590"/>
        <source>PCI reset:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="558"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Reset the Nvidia card at the PCI level before reloading the nvidia module&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;No&lt;/span&gt;: does not perform any reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Function level&lt;/span&gt;: perform a light &amp;quot;function-level&amp;quot; reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Hot reset&lt;/span&gt;: perform a &amp;quot;hot reset&amp;quot; of the PCI bridge (this method messes with the hardware directly and will perform a PCI remove even if it disabled, please read the online documentation of Optimus Manager before using it)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="567"/>
        <source>Function level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="572"/>
        <source>Hot reset</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="613"/>
        <source>PCI remove</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="700"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;DRI version&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Versión DRI&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="623"/>
        <source>PCI power control</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="308"/>
        <source>Hybrid icon:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="630"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Method to power switch the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;None&lt;/span&gt;: do not use an external module for power management (for some laptop models it&apos;s preferable to use this option in combination with PCI power control), you can use the scipts nvidia-enable.sh and nvidia-disable.sh to execute custom commands for power management that will be executed only with this method&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nouveau&lt;/span&gt;: load the nouveau module on the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Bbswitch&lt;/span&gt;: power off the card using the bbswitch module (requires the &amp;quot;bbswitch&amp;quot;dependency)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;ACPI call&lt;/span&gt;: try various ACPI method calls to power the card on and off (requires the &amp;quot;acpi_call&amp;quot; dependency)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="620"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable PCI power management in Intel mode&lt;/p&gt;&lt;p&gt;This option is incompatible with ACPI call and Bbswitch switching methods, so it will be ignored in those cases&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="660"/>
        <source>Switching method:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="580"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Automatically log out the current desktop session when switching GPUs&lt;/p&gt;&lt;p&gt;This feature is currently supported for Gnome, KDE Plasma, Deepin, Xfce, i3, Sway, Openbox, AwesomeWM and bspwm&lt;/p&gt;&lt;p&gt;If this options is disabled or you use a different desktop environment, GPU switching only becomes effective at the next graphical session login&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
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
        <location filename="../../src/settingsdialog.ui" line="476"/>
        <source>Type:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="416"/>
        <source>Path:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="442"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Type of the configuration&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Permanent&lt;/span&gt;: configuration file that will be used every time it starts&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Temporary&lt;/span&gt;: configuration file that will be used only once at the next boot&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="446"/>
        <source>Permanent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="451"/>
        <source>Temporary</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="426"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Path to configuration file that will be loaded&lt;/p&gt;&lt;p&gt;If such a file does not exist, then it will be created automatically&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="429"/>
        <source>Path to configuration file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="462"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Browse configuration file&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="465"/>
        <source>Browse</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="491"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Import Optimus Manager settings from file&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="494"/>
        <source>Import</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="507"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Export current settings to file&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="510"/>
        <source>Export</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="610"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Remove the Nvidia card from the PCI bus&lt;/p&gt;&lt;p&gt;May prevent crashes caused by power switching&lt;/p&gt;&lt;p&gt;Ignored if switching method is Nouveau or Bbswitch&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="717"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Driver to use for the Intel GPU&lt;br/&gt;&lt;br/&gt;To use the Intel driver, you need to install the package &amp;quot;xf86-video-intel&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="751"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable TearFree option in the Xorg configuration&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="783"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Acceleration method (corresponds to AccelMethod in the Xorg configuration)&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="884"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable modesetting&lt;/p&gt;&lt;p&gt;Required for PRIME Synchronization (which prevents tearing)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="914"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable triple buffering&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Activar triple buffer&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="917"/>
        <source>Triple buffer</source>
        <translation>Triple buffer</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="974"/>
        <location filename="../../src/settingsdialog.ui" line="1105"/>
        <source>Version:</source>
        <translation>Versión:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="988"/>
        <location filename="../../src/settingsdialog.ui" line="1082"/>
        <source>Author:</source>
        <translation>Autor:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="995"/>
        <location filename="../../src/settingsdialog.ui" line="1119"/>
        <source>License:</source>
        <translation>Licencia:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="78"/>
        <source>Optimus Manager temporary configuration file path cannot be empty</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="85"/>
        <source>Optimus Manager temporary configuration file path cannot be a permanent configuration file path</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="324"/>
        <source>Select temporary configuration file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="325"/>
        <location filename="../../src/settingsdialog.cpp" line="337"/>
        <location filename="../../src/settingsdialog.cpp" line="350"/>
        <source>Config files (*.conf);;All files(*)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="336"/>
        <source>Export Optimus Manager settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="349"/>
        <source>Import Optimus Manager settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="397"/>
        <source>Select icon</source>
        <translation>Seleccionar icono</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="398"/>
        <source>Images (*.png *.jpg *.bmp);;All files(*)</source>
        <translation>Imágenes (*.png *.jpg *.bmp);;Todos los formatos(*)</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="429"/>
        <source>Unable to find Optimus Manager daemon.</source>
        <translation>No se pudo encontrar el demonio de Optimus Manager.</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="430"/>
        <source>Please check the integrity of the package that provides Optimus Manager.</source>
        <translation>Por favor, compruebe la integridad del paquete que proporciona Optimus Manager.</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="432"/>
        <source>Not found!</source>
        <translation>No encontrado!</translation>
    </message>
</context>
</TS>
