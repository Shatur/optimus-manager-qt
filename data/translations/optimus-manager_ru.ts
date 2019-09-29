<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="ru">
<context>
    <name>AppSettings</name>
    <message>
        <location filename="../../src/appsettings.cpp" line="75"/>
        <source>Unable to create autorun file from &apos;%1&apos;</source>
        <translation>Не удается создать файл автозапуска из &apos;%1&apos;</translation>
    </message>
</context>
<context>
    <name>DaemonClient</name>
    <message>
        <location filename="../../src/daemonclient.cpp" line="109"/>
        <source>Unable to open startup mode file</source>
        <translation>Не удается открыть файл режима запуска</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="361"/>
        <location filename="../../src/settingsdialog.cpp" line="117"/>
        <source>Unable to connect to Optimus Manager daemon: %1</source>
        <translation>Не удается подключиться к демону Optimus Manager: %1</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="371"/>
        <source>Unable to send GPU name to switch to Optimus Manager daemon: %1</source>
        <translation>Не удается отправить имя GPU для переключения демону Optimus Manager: %1</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="127"/>
        <source>Unable to send configuration file to Optimus Manager daemon: %1</source>
        <translation>Не удается отправить файл конфигурации демону Optimus Manager: %1</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="137"/>
        <source>Unable to send startup mode to Optimus Manager daemon: %1</source>
        <translation>Не удается отправить режим запуска демону Optimus Manager: %1</translation>
    </message>
</context>
<context>
    <name>OptimusManager</name>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="182"/>
        <source>Switch to Intel</source>
        <translation>Переключить на Intel</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="183"/>
        <source>Switch to Nvidia</source>
        <translation>Переключить на Nvidia</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="60"/>
        <location filename="../../src/optimusmanager.cpp" line="184"/>
        <source>Exit</source>
        <translation>Выход</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="55"/>
        <location filename="../../src/optimusmanager.cpp" line="56"/>
        <location filename="../../src/optimusmanager.cpp" line="57"/>
        <source>Switch to %1</source>
        <translation>Переключить на %1</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="160"/>
        <location filename="../../src/optimusmanager.cpp" line="170"/>
        <source>The specified icon &apos;%1&apos; for the current GPU is invalid. The default icon will be used.</source>
        <translation>Выбранный значок &apos;%1&apos; для текущего GPU недействителен. Будет использован значок по умолчанию.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="197"/>
        <source>You are about to switch GPU.</source>
        <translation>Вы собираетесь переключить GPU.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="199"/>
        <source>You will be automatically logged out to apply the changes.</source>
        <translation>Будет осуществлен автоматический выход из системы для применения изменений.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="210"/>
        <source>No power management option is currently enabled</source>
        <translation>В настоящее время опция управления питанием не включена</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="211"/>
        <source>Switching between GPUs will work but you will likely experience poor battery life.
If you have already enabled the new Runtime D3 power management inside the Nvidia driver (for Turing+ GPU with Coffee Lake+ CPU), you can safely ignore this warning.</source>
        <translation>Переключение между GPU будет работать, но у вас, вероятно, будет плохое время автономной работы.
Если вы уже включили новое управление питанием Runtime D3 в драйвере Nvidia (для Turing+ GPU с Coffee Lake+ CPU), вы можете смело игнорировать это предупреждение.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="221"/>
        <source>The Optimus Manager service is not running.</source>
        <translation>Служба Optimus Manager не запущена.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="270"/>
        <source>There are %1 other desktop sessions open. The GPU switch will not become effective until you have manually logged out from ALL desktop sessions.
Continue?</source>
        <translation>Открыто %1 других сеансов рабочего стола. Переключение GPU не вступит в силу, пока вы не выйдете вручную из ВСЕХ сеансов рабочего стола.
Продолжить?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="284"/>
        <source>Wayland session found.</source>
        <translation>Обнаружена сессия Wayland.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="285"/>
        <source>Session %1, started by %2, is a Wayland session. Wayland is not supported by Optimus Manager, so GPU switching may fail.
Continue anyway?</source>
        <translation>Сессия %1, запущенная пользователем %2, является сессией Wayland. Optimus Manager не поддерживает Wayland, поэтому переключение GPU может завершиться неудачно.
Все равно продолжить?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="302"/>
        <source>The Bumblebee service (%1) is running.</source>
        <translation>Служба Bumblebee (%1) запущена.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="345"/>
        <source>The Xorg driver &apos;%1&apos; is not installed.</source>
        <translation>Xorg драйвер &apos;%1&apos; не установлен.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="346"/>
        <source>Optimus Manager will use &apos;%1&apos; driver instead. You can change driver in settings or install the &apos;%2&apos; driver from the package &apos;%3&apos;.
Continue anyway?</source>
        <translation>Вместо этого Optimus Manager будет использовать драйвер &apos;%1&apos;. Вы можете изменить драйвер в настройках или установить драйвер &apos;%2&apos; из пакета &apos;%3&apos;.
Все равно продолжить?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="317"/>
        <source>If you did not create it yourself, it was likely generated by your distribution or by an Nvidia utility.
This file may contain hard-coded GPU configuration that could interfere with Optimus Manager, so it is recommended that you delete it before proceeding.
Ignore this warning and proceed with GPU switching?</source>
        <translation>Если вы не создавали его самостоятельно, скорее всего, он был создан вашим дистрибутивом или утилитой Nvidia.
Этот файл может содержать захардкоженную конфигурацию GPU, которая может помешать работе Optimus Manager, поэтому рекомендуется удалить его, прежде чем продолжить.
Проигнорировать это предупреждение и продолжить переключение GPU?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="331"/>
        <source>This file was auto-generated by the Manjaro driver utility (MHWD). This will likely interfere with GPU switching, so Optimus Manager will delete this file automatically if you proceded with GPU switching.
Proceed?</source>
        <translation>Этот файл был автоматически сгенерирован менеджером драйверов Manjaro (MHWD). Это может помешать переключению GPU, поэтому Optimus Manager автоматически удалит этот файл, если вы продолжите переключение GPU.
Продолжить?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="201"/>
        <source>After applying the settings, you will need to manually re-login to change the video card.</source>
        <translation>После применения настроек вам нужно будет заново войти в систему, чтобы сменить видеокарту.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="68"/>
        <location filename="../../src/optimusmanager.cpp" line="179"/>
        <source>Current videocard: %1</source>
        <translation>Текущая видеокарта: %1</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="222"/>
        <source>Please enable and start it with:
&apos;%1&apos;
&apos;%2&apos;</source>
        <translation>Пожалуйста, включите и запустите его с:
&apos;%1&apos;
&apos;%2&apos;</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="232"/>
        <location filename="../../src/optimusmanager.cpp" line="244"/>
        <source>The %1 module does not seem to be available for the current kernel.</source>
        <translation>Модуль %1 не доступен для текущего ядра.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="233"/>
        <source>Power switching will not work.
You can set &apos;%1&apos; for GPU switching in settings or install bbswitch forthe default kernel with &apos;%2&apos; or for all kernels with &apos;%3&apos;.</source>
        <translation>Переключение питания не будет работать.
Вы можете выбрать &apos;%1&apos; для переключения GPU в настройках или установить bbswitch для ядра по умолчанию с &apos;%2&apos; или для всех ядер с &apos;%3&apos;.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="245"/>
        <source>It is likely the Nvidia driver was not properly installed. GPU switching will probably fail, continue anyway?</source>
        <translation>Вероятно, драйвер Nvidia был установлен неправильно. Переключение GPU, скорее всего, не удастся, все равно продолжить?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="255"/>
        <source>Looks like you&apos;re using a non-patched version of the Gnome Display Manager (GDM).</source>
        <translation>Похоже, вы используете непропатченную версию Gnome Display Manager (GDM).</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="256"/>
        <source>GDM need to be patched for Prime switching. Follow &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;this&lt;/a&gt; instructions to install a patched version. Without a patched GDM version, GPU switching will likely fail.
Continue anyway?</source>
        <translation>GDM должен быть пропатчен для переключения видеокарт. Следуйте &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;этой инструкции&lt;/a&gt;, чтобы установить исправленную версию. Без пропатченной версии GDM переключение GPU, скорее всего, не удастся.
Все равно продолжить?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="269"/>
        <source>Multiple running sessions detected.</source>
        <translation>Обнаружено несколько запущенных сессий.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="303"/>
        <source>This can interfere with Optimus Manager. Before attempting a GPU switch, it is recommended that you disable this service with &apos;%1&apos; and reboot your computer.
Ignore this warning and proceed with GPU switching now?</source>
        <translation>Это может помешать работе Optimus Manager. Перед попыткой переключения GPU рекомендуется отключить эту службу с помощью &apos;%1&apos; и перезагрузить компьютер.
Проигнорировать это предупреждение сейчас и перейти к переключению GPU?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="316"/>
        <location filename="../../src/optimusmanager.cpp" line="330"/>
        <source>Found a Xorg config file at &apos;%1&apos;.</source>
        <translation>Найден файл конфигурации Xorg по пути &apos;%1&apos;.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="378"/>
        <source>Configuration successfully applied. Your GPU will be switched after next login.</source>
        <translation>Конфигурация успешно применена. Ваш GPU будет переключен после следующего входа в систему.</translation>
    </message>
</context>
<context>
    <name>SettingsDialog</name>
    <message>
        <location filename="../../src/settingsdialog.ui" line="14"/>
        <location filename="../../src/optimusmanager.cpp" line="51"/>
        <location filename="../../src/optimusmanager.cpp" line="181"/>
        <source>Settings</source>
        <translation>Настройки</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="59"/>
        <location filename="../../src/settingsdialog.ui" line="109"/>
        <source>General</source>
        <translation>Общее</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="95"/>
        <source>About</source>
        <translation>О программе</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="205"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Application language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Язык приложения&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="208"/>
        <source>Language:</source>
        <translation>Язык:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="119"/>
        <source>&lt;System language&gt;</source>
        <translation>&lt;Язык системы&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="231"/>
        <source>Launch at startup</source>
        <translation>Запускать при старте системы</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="238"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Show confirmation dialog when switching GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Показать диалог подтверждения при переключении GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="241"/>
        <source>Confirm switching</source>
        <translation>Подтверждать переключение</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="292"/>
        <source>Nvidia icon:</source>
        <translation>Значок Nvidia:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="278"/>
        <source>Intel icon:</source>
        <translation>Значок Intel:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="338"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Specify which GPU will be used by default when the system boots&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Указать какой GPU будет использоваться по умолчанию при загрузке системы&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="367"/>
        <source>ACPI call</source>
        <translation>ACPI вызов</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="432"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Module used for power switching&lt;/p&gt;&lt;p&gt;If you select &amp;quot;None&amp;quot;, no power switching will be done at all (the Nvidia GPU will stay powered at all times)&lt;/p&gt;&lt;p&gt;If you use bbswitch, you will not be able to use video outputs attached to your Nvidia GPU in Intel mode&lt;/p&gt;&lt;p&gt;To use the bbswitch mode, the bbswitch module must be installed for your current kernel&lt;/p&gt;&lt;p&gt;You can install it for the default kernel with &amp;quot;pacman -S bbswitch&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Модуль, который используется для переключения питания&lt;/p&gt;&lt;p&gt;Если вы выберете &amp;quot;Отсутствует&amp;quot;, питание переключаться не будет (Nvidia GPU будет работать постоянно)&lt;/p&gt;&lt;p&gt;Если вы используете bbswitch, то не сможете использовать видеовыходы, подключенные к Nvidia GPU в режиме Intel&lt;/p&gt;&lt;p&gt;Чтобы использовать режим bbswitch, модуль bbswitch должен быть установлен для вашего текущего ядра&lt;/p&gt;&lt;p&gt;Вы можете установить его для ядра по умолчанию с помощью &amp;quot;pacman -S bbswitch&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="445"/>
        <source>Automatic logout</source>
        <translation>Автоматический выход</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="642"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable modesetting for the nouveau driver&lt;/p&gt;&lt;p&gt;Does not affect modesetting for the Intel GPU driver&lt;/p&gt;&lt;p&gt;This option is incompatible with Bbswitch and will be ignored if it is enabled&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Включение или отключение modesettings для драйвера nouveau&lt;/p&gt;&lt;p&gt;Не влияет на modesetting для драйвера Intel GPU&lt;/p&gt;&lt;p&gt;Эта опция несовместима с Bbswitch и будет игнорироваться, если он включен&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="685"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;This will be set using the Xsetup script passed to your login manager&lt;br/&gt;It will run the command&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Leave 0 for the default&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Это будет установлено с помощью скрипта Xsetup, который передается вашему менеджеру входа&lt;br/&gt;Он запускает команду&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Оставьте 0 для значения по умолчанию&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="718"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable the NVreg_UsePageAttributeTable option in the Nvidia driver &lt;span style=&quot; font-style:italic;&quot;&gt;Recommended&lt;/span&gt;, can cause poor CPU performance otherwise&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Включить или нет параметр NVreg_UsePageAttributeTable в драйвере Nvidia&lt;span style=&quot; font-style:italic;&quot;&gt;Рекомендуется&lt;/span&gt;, в противном случае может привести к снижению производительности процессора&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="728"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable CoolBits in the Xorg configuration, which unlocks clocking options&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Включить CoolBits в конфигурации Xorg, которая разблокирует параметры разгона&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="731"/>
        <source>Overclocking options</source>
        <translation>Опции разгона</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="228"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart will be used&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>Будет использован ~/.config/autostart</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="251"/>
        <source>Tray icons</source>
        <translation>Иконки в трее</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="257"/>
        <location filename="../../src/settingsdialog.ui" line="264"/>
        <source>Choose icon</source>
        <translation>Выбрать значок</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="341"/>
        <source>Startup mode:</source>
        <translation>Режим при загрузке:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="352"/>
        <source>None</source>
        <translation>Отсутствует</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="115"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Interface language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Язык интерфейса&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="271"/>
        <location filename="../../src/settingsdialog.ui" line="285"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Path to the icon or icon name from theme&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Путь к значку или название значка из темы&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="398"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU that will be used during normal system startup&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU, который будет использоваться при обычном запуске системы&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="517"/>
        <source>Driver:</source>
        <translation>Драйвер:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="558"/>
        <source>Acceleration method:</source>
        <translation>Метод графического ускорения:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="579"/>
        <location filename="../../src/settingsdialog.ui" line="611"/>
        <source>Default</source>
        <translation>По умолчанию</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="584"/>
        <source>Yes</source>
        <translation>Да</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="463"/>
        <location filename="../../src/settingsdialog.ui" line="589"/>
        <source>No</source>
        <translation>Нет</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="452"/>
        <source>PCI reset:</source>
        <translation>Сброс PCI:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="459"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Reset the Nvidia card at the PCI level before reloading the nvidia module&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;No&lt;/span&gt;: does not perform any reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Function level&lt;/span&gt;: perform a light &amp;quot;function-level&amp;quot; reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Hot reset&lt;/span&gt;: perform a &amp;quot;hot reset&amp;quot; of the PCI bridge (this method messes with the hardware directly and will perform a PCI remove even if it disabled, please read the online documentation of Optimus Manager before using it)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Сбросьте карту Nvidia на уровене PCI перед перезагрузкой модуля nvidia&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Нет&lt;/span&gt;: не выполнять сброс&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Функциональный уровень&lt;/span&gt;: выполнить легкий сброс на функциональном уровне&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Горячий сброс&lt;/span&gt;: Выполнить гарячий сброс на мосте PCI (этот метод напрямую связан с оборудованием а также выполняет удаление PCI, даже если опция отключена, пожалуйста, прочитайте онлайн-документацию Optimus Manager перед его использованием)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="468"/>
        <source>Function level</source>
        <translation>Функциональный уровень</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="473"/>
        <source>Hot reset</source>
        <translation>Гарячий сброс</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="484"/>
        <source>PCI remove</source>
        <translation>Удаление PCI</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="524"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;DRI version&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Версия DRI&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="378"/>
        <source>PCI power control</source>
        <translation>Управление питанием PCI</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="299"/>
        <source>Hybrid icon:</source>
        <translation>Значок Hybrid:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="348"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Method to power switch the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;None&lt;/span&gt;: do not use an external module for power management (for some laptop models it&apos;s preferable to use this option in combination with PCI power control), you can use the scipts nvidia-enable.sh and nvidia-disable.sh to execute custom commands for power management that will be executed only with this method&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nouveau&lt;/span&gt;: load the nouveau module on the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Bbswitch&lt;/span&gt;: power off the card using the bbswitch module (requires the &amp;quot;bbswitch&amp;quot;dependency)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;ACPI call&lt;/span&gt;: try various ACPI method calls to power the card on and off (requires the &amp;quot;acpi_call&amp;quot; dependency)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Метод для переключения питания видеокарты Nvidia&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Отсутствует&lt;/span&gt;: не использовать внешний модуль для управления питанием (для некоторых моделей ноутбуков предпочтительно использовать эту опцию в сочетании с управлением питанием PCI), вы можете использовать скрипты nvidia-enable.sh и nvidia-disable.sh для выполнения пользовательских команд управления питанием, которые будут выполняться только для этого метода&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nouveau&lt;/span&gt;: загрузить модуль nouveau на видеокарту Nvidia&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Bbswitch&lt;/span&gt;: выключать видеокарту с помощью модуля bbswitch (требуется зависимость &amp;quot;bbswitch&amp;quot;)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;ACPI вызов&lt;/span&gt;: пробовать различные вызовы методов ACPI для включения и выключения видеокарты (требуется зависимость &amp;quot;acpi_call&amp;quot;)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="375"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable PCI power management in Intel mode&lt;/p&gt;&lt;p&gt;This option is incompatible with ACPI call and Bbswitch switching methods, so it will be ignored in those cases&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Включить управление питанием PCI в режиме Intel&lt;/p&gt;&lt;p&gt;Эта опция несовместима с методами переключения ACPI вызов и Bbswitch, поэтому в этих случаях она будет игнорироваться&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="435"/>
        <source>Switching method:</source>
        <translation>Метод переключения:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="442"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Automatically log out the current desktop session when switching GPUs&lt;/p&gt;&lt;p&gt;This feature is currently supported for Gnome, KDE Plasma, Deepin, Xfce, i3, Sway, Openbox, AwesomeWM and bspwm&lt;/p&gt;&lt;p&gt;If this options is disabled or you use a different desktop environment, GPU switching only becomes effective at the next graphical session login&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Автоматически выходить из текущего сеанса рабочего стола при переключении GPU&lt;/p&gt;&lt;p&gt;Эта функция в настоящее время поддерживается для  Gnome, KDE Plasma, Deepin, Xfce, i3, Sway, Openbox, AwesomeWM и bspwm&lt;/p&gt;&lt;p&gt;Если этот параметр отключен или вы используете другую среду рабочего стола, переключение графического процессора вступает в силу только при следующем входе в графическую сессию&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="481"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Remove the Nvidia card from the PCI bus&lt;/p&gt;&lt;p&gt;May prevent crashes caused by power switching&lt;/p&gt;&lt;p&gt;Ignored if switching method is Nouveau or Bbswitch&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Извлечь видеокарту Nvidia из шины PCI&lt;/p&gt;&lt;p&gt;Может предотвратить сбои, вызванные переключением питания&lt;/p&gt;&lt;p&gt;Игнорируется, если используется метод переключения Nouveau или Bbswitch&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="541"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Driver to use for the Intel GPU&lt;br/&gt;&lt;br/&gt;To use the Intel driver, you need to install the package &amp;quot;xf86-video-intel&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Драйвер для использования с Intel GPU&lt;br/&gt;&lt;br/&gt;Чтобы использовать драйвер Intel, вам необходимо установить пакет &amp;quot;xf86-video-intel&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="575"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable TearFree option in the Xorg configuration&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Включить опцию TearFree в конфигурации Xorg&lt;/p&gt;&lt;p&gt;Применяется только к драйверу Intel&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="607"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Acceleration method (corresponds to AccelMethod in the Xorg configuration)&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Метод акселерации (соответствует AccelMethod в конфигурации Xorg)&lt;/p&gt;&lt;p&gt;Применяется только к драйверу Intel&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="708"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable modesetting&lt;/p&gt;&lt;p&gt;Required for PRIME Synchronization (which prevents tearing)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Включить modesetting&lt;/p&gt;&lt;p&gt;Требуется для PRIME Synchronization (которая предотвращает тиринг)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="738"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable triple buffering&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Включить тройную буферизацию&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="741"/>
        <source>Triple buffer</source>
        <translation>Тройная буферизация</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="798"/>
        <location filename="../../src/settingsdialog.ui" line="929"/>
        <source>Version:</source>
        <translation>Версия:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="812"/>
        <location filename="../../src/settingsdialog.ui" line="906"/>
        <source>Author:</source>
        <translation>Автор:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="819"/>
        <location filename="../../src/settingsdialog.ui" line="943"/>
        <source>License:</source>
        <translation>Лицензия:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="261"/>
        <source>Select icon</source>
        <translation>Выбрать иконку</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="262"/>
        <source>Images (*.png *.jpg *.bmp);;All files(*)</source>
        <translation>Изображения (*.png *.jpg *.bmp);;Все файлы(*)</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="281"/>
        <source>Unable to find Optimus Manager daemon.</source>
        <translation>Не удается найти демон Optimus Manager.</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="282"/>
        <source>Please check the integrity of the package that provides Optimus Manager.</source>
        <translation>Пожалуйста, проверьте целостность пакета, который предоставляет Optimus Manager.</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="284"/>
        <source>Not found!</source>
        <translation>Не найден!</translation>
    </message>
</context>
</TS>
