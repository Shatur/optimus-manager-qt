<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="hu" sourcelanguage="en">
  <context>
    <name>AppSettings</name>
    <message>
      <location filename="../../src/appsettings.cpp" line="77"/>
      <source>Unable to create autorun file from &apos;%1&apos;</source>
      <translation>Nem sikerült létrehozni az autorun fájl ebből &apos;%1&apos;</translation>
    </message>
  </context>
  <context>
    <name>DaemonClient</name>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="367"/>
      <location filename="../../src/settingsdialog.cpp" line="101"/>
      <source>Unable to connect to Optimus Manager daemon: %1</source>
      <translation>Sikertelen csatlakozás az Optimus Manager démonhoz: %1</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="377"/>
      <source>Unable to send GPU name to switch to Optimus Manager daemon: %1</source>
      <translation>Nem sikerült továbbítani a GPU nevét, hogy az Optimus Manager démonra váltson: %1</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="129"/>
      <source>Unable to send configuration file to Optimus Manager daemon: %1</source>
      <translation>Nem sikerült továbbítani a konfigurációs fájlt az Optimus Manager démonnak: %1</translation>
    </message>
  </context>
  <context>
    <name>OptimusManager</name>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="75"/>
      <location filename="../../src/optimusmanager.cpp" line="189"/>
      <source>Exit</source>
      <translation>Kilépés</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="70"/>
      <location filename="../../src/optimusmanager.cpp" line="71"/>
      <location filename="../../src/optimusmanager.cpp" line="72"/>
      <location filename="../../src/optimusmanager.cpp" line="185"/>
      <location filename="../../src/optimusmanager.cpp" line="186"/>
      <location filename="../../src/optimusmanager.cpp" line="187"/>
      <source>Switch to %1</source>
      <translation>Váltás erre %1</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="161"/>
      <location filename="../../src/optimusmanager.cpp" line="170"/>
      <source>The specified icon &apos;%1&apos; for the current GPU is invalid. The default icon will be used.</source>
      <translation>A megadott ikon &apos;%1&apos; a jelenlegi eszközre érvénytelen. Az alapértelmezett lesz használva.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="161"/>
      <location filename="../../src/optimusmanager.cpp" line="170"/>
      <source>Invalid icon</source>
      <translation type="unfinished">Invalid icon</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="202"/>
      <source>You are about to switch GPU.</source>
      <translation>Videoeszköz váltása folyamatban.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="204"/>
      <source>You will be automatically logged out to apply the changes.</source>
      <translation>Automatikusan ki lesz jelentkeztetve hogy a változások érvénybe lépjenek.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="215"/>
      <source>No power management option is currently enabled</source>
      <translation>Jelenleg nincs energiagazdálkodási opció engedélyezve</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="216"/>
      <source>Switching between GPUs will work but you will likely experience poor battery life.
If you have already enabled the new Runtime D3 power management inside the Nvidia driver (for Turing+ GPU with Coffee Lake+ CPU), you can safely ignore this warning.</source>
      <translation>A videoeszközök közötti váltás működni fog, viszont valószínű a csökkent üzemidő akkumulátoron.
Ha már engedélyezte az új Runtime D3 energiagazdálkodást az Nvidia illesztőprogramban (a Turing-nál újabb GPU-k és Coffee Lake-nál újabb CPU-k esetében), akkor ezt a figyelmeztetés hagyja figyelmen kívül.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="226"/>
      <source>The Optimus Manager service is not running.</source>
      <translation>Az Optimus Manager szolgáltatás nem fut.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="275"/>
      <source>There are %1 other desktop sessions open. The GPU switch will not become effective until you have manually logged out from ALL desktop sessions.
Continue?</source>
      <translation>További %1 asztali munkamenet van nyitva. A videoeszköz váltás nem lesz effektív, amíg manuálisan nem jelentkezett ki az ÖSSZES asztali munkamenetből
Folytatja?</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="290"/>
      <source>Wayland session found.</source>
      <translation>Wayland munkamenet jelen.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="291"/>
      <source>Session %1, started by %2, is a Wayland session. Wayland is not supported by Optimus Manager, so GPU switching may fail.
Continue anyway?</source>
      <translation>%1. munkamenet, amit %2 indított egy Wayland munkamenet. Az Optimus Manager nem támogatja a Wayland-et, ezért a videoeszköz váltása lehet hogy nem fog sikerülni.
Így is folytatja?</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="308"/>
      <source>The Bumblebee service (%1) is running.</source>
      <translation>Bumblebee szolgáltatás (%1) nem fut.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="351"/>
      <source>The Xorg driver &apos;%1&apos; is not installed.</source>
      <translation>Az Xorg illesztőprogram &apos;%1&apos; nincs telepítve.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="352"/>
      <source>Optimus Manager will use &apos;%1&apos; driver instead. You can change driver in settings or install the &apos;%2&apos; driver from the package &apos;%3&apos;.
Continue anyway?</source>
      <translation>Az Optimus Manager az &apos;%1&apos; illesztőprogramot fogja használni. Az illesztőprogramot megváltoztathatja a beállításokban vagy telepítse a &apos;%2&apos; illesztőprogramot a &apos;%3&apos; csomagból.
Így is folytatja?</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="385"/>
      <source>Configuration successfully applied</source>
      <translation type="unfinished">Configuration successfully applied</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="385"/>
      <source>Your GPU will be switched after next login.</source>
      <translation type="unfinished">Your GPU will be switched after next login.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="323"/>
      <source>If you did not create it yourself, it was likely generated by your distribution or by an Nvidia utility.
This file may contain hard-coded GPU configuration that could interfere with Optimus Manager, so it is recommended that you delete it before proceeding.
Ignore this warning and proceed with GPU switching?</source>
      <translation>Ha nem ön hozta létre, akkor valószínűleg a disztribúciója, vagy egy Nvidia segédprogram.
Ez a fájl beégetett videoeszköz konfigurációt tartalmazhat, ami zavarhatja az Optimus Manager működését, ezért ajánlott hogy törölje a fájlt a folytatás előtt.
Figyelmen kívül hagyja ezt a figyelmeztetést és folytatja a videoeszköz váltást?</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="337"/>
      <source>This file was auto-generated by the Manjaro driver utility (MHWD). This will likely interfere with GPU switching, so Optimus Manager will delete this file automatically if you proceded with GPU switching.
Proceed?</source>
      <translation>Ez a fájl automatikusan lett generálva a Manjaro illesztőprogram segédprogram (MHWD) által. Ez valószínűleg zavarni fogja a videoeszköz váltást, ezért az Optimus Manager törölni fogja ezt a fájlt, ha folytatja.
Folytatja?</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="206"/>
      <source>After applying the settings, you will need to manually re-login to change the video card.</source>
      <translation>A beállítások alkalmazása után manuálisan újra be kell jelentkeznie a videoeszköz váltáshoz</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="82"/>
      <location filename="../../src/optimusmanager.cpp" line="180"/>
      <source>Current videocard: %1</source>
      <translation>Jelenlegi videoeszköz: %1</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="227"/>
      <source>Please enable and start it with:
&apos;%1&apos;
&apos;%2&apos;</source>
      <translation>Kérjük engedélyezze, majd indítsa a:
&apos;%1&apos;
&apos;%2&apos;</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="237"/>
      <location filename="../../src/optimusmanager.cpp" line="249"/>
      <source>The %1 module does not seem to be available for the current kernel.</source>
      <translation>A %1 modul nem elérhető a jelenlegi rendszermaghoz.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="238"/>
      <source>Power switching will not work.
You can set &apos;%1&apos; for GPU switching in settings or install bbswitch forthe default kernel with &apos;%2&apos; or for all kernels with &apos;%3&apos;.</source>
      <translation>Az energia váltás nem fog működni.
Beállíthatja a(z) &apos;%1&apos; -t a videoeszköz váltáshoz a beállításokban, vagy telepítse a bbswitch-et az alapértelmezett rendszermaghoz a &apos;%2&apos; -vel vagy az összes maghoz a &apos;%3&apos; -val.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="250"/>
      <source>It is likely the Nvidia driver was not properly installed. GPU switching will probably fail, continue anyway?</source>
      <translation>Valószínű hogy az Nvidia illesztőprogram nem lett helyesen telepítve. A GPU váltás valószínűleg sikertelen lesz, folytatja?</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="260"/>
      <source>Looks like you&apos;re using a non-patched version of the Gnome Display Manager (GDM).</source>
      <translation>Úgy tűnik hogy foltozatlan Gnome kijelző kezelőt (GDM) használ.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="261"/>
      <source>GDM need to be patched for Prime switching. Follow &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;this&lt;/a&gt; instructions to install a patched version. Without a patched GDM version, GPU switching will likely fail.
Continue anyway?</source>
      <translation>GDM foltozva kell hogy legyen a Prime váltáshoz. További segítésget &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;itt&lt;/a&gt; talál. Foltozatlan GDM verzióval a videoeszköz váltása valószínűleg nem lesz sikeres.
Így is folytatja?</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="274"/>
      <source>Multiple running sessions detected.</source>
      <translation>Több futó munkamenet észlelve.</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="309"/>
      <source>This can interfere with Optimus Manager. Before attempting a GPU switch, it is recommended that you disable this service with &apos;%1&apos; and reboot your computer.
Ignore this warning and proceed with GPU switching now?</source>
      <translation>Ez zavarhatja az Optimus Manager-t. Mielőtt videoeszközt váltana, ajánlott hogy letilltja a &apos;%1&apos; szolgáltatást és újraindítja a számítógépet.
Figyelmen kívűl hagyja és folytatja a videoeszköz váltást?</translation>
    </message>
    <message>
      <location filename="../../src/optimusmanager.cpp" line="322"/>
      <location filename="../../src/optimusmanager.cpp" line="336"/>
      <source>Found a Xorg config file at &apos;%1&apos;.</source>
      <translation>Xorg konfigurációs fájl megtalálva itt &apos;%1&apos;</translation>
    </message>
  </context>
  <context>
    <name>SettingsDialog</name>
    <message>
      <location filename="../../src/settingsdialog.ui" line="14"/>
      <location filename="../../src/optimusmanager.cpp" line="66"/>
      <location filename="../../src/optimusmanager.cpp" line="182"/>
      <source>Settings</source>
      <translation>Beállítások</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="59"/>
      <location filename="../../src/settingsdialog.ui" line="118"/>
      <source>General</source>
      <translation>Általános</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="104"/>
      <source>About</source>
      <translation>Névjegy</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="137"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Application language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Alkalmazás nyelve&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="140"/>
      <source>Language:</source>
      <translation>Nyelv:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="47"/>
      <source>&lt;System language&gt;</source>
      <translation>&lt;System language&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="163"/>
      <source>Launch at startup</source>
      <translation>Indítás indításkor</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="170"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Show confirmation dialog when switching GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Kérjen visszaigazolást videoeszköz váltáskor&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="173"/>
      <source>Confirm switching</source>
      <translation>Váltás megerősítése</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="224"/>
      <source>Nvidia icon:</source>
      <translation>Nvidia ikon:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="210"/>
      <source>Intel icon:</source>
      <translation>Intel ikon:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="506"/>
      <source>ACPI call</source>
      <translation>ACPI hívás</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="440"/>
      <source>Automatic logout</source>
      <translation>Automatikus kiléptetés</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="830"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable modesetting for the nouveau driver&lt;/p&gt;&lt;p&gt;Does not affect modesetting for the Intel GPU driver&lt;/p&gt;&lt;p&gt;This option is incompatible with Bbswitch and will be ignored if it is enabled&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Engedélyezi-e a modesetting-et a nouveau illesztőprogramnak&lt;/p&gt;&lt;p&gt;Nem befolyásolja az Intel illesztőprogram modesetting beállítását&lt;/p&gt;&lt;p&gt;Ez az opció inkompatibilis a Bbswitch-el és figyelmen kívül lesz hagyva ha engedélyezve marad&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="866"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;This will be set using the Xsetup script passed to your login manager&lt;br/&gt;It will run the command&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Leave 0 for the default&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Az Xsetup szkript amit a beléptető menedszernek átad&lt;br/&gt;Futtatja a parancsot&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Hagyja 0 -án az alapértelmezéshez&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="883"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable the NVreg_UsePageAttributeTable option in the Nvidia driver &lt;span style=&quot; font-style:italic;&quot;&gt;Recommended&lt;/span&gt;, can cause poor CPU performance otherwise&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Engedélyezi-e az NVreg_UsePageAttributeTable opciót az Nvidia illesztőprogramban&lt;span style=&quot; font-style:italic;&quot;&gt;Ajánlott&lt;/span&gt;, mert másképp rossz processzorteljesítmény léphet fel&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="896"/>
      <source>Overclocking options</source>
      <translation>Túlhajtási beállítások</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="160"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart will be used&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart lesz használva&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="183"/>
      <source>Tray icons</source>
      <translation>Tálca ikonok</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="189"/>
      <location filename="../../src/settingsdialog.ui" line="196"/>
      <source>Choose icon</source>
      <translation>Válasszon ikont</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="491"/>
      <source>None</source>
      <translation>Semmi</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="124"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Interface language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Felület nyelve&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="203"/>
      <location filename="../../src/settingsdialog.ui" line="217"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Path to the icon or icon name from theme&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Útvonal az ikonhoz vagy a témából való ikon neve&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="582"/>
      <source>Startup mode:</source>
      <translation type="unfinished">Startup mode:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="672"/>
      <source>External power startup mode:</source>
      <translation type="unfinished">External power startup mode:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="705"/>
      <source>Driver:</source>
      <translation>Illesztőprogram:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="746"/>
      <source>Acceleration method:</source>
      <translation>Gyorsítási eljárás:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="767"/>
      <location filename="../../src/settingsdialog.ui" line="799"/>
      <source>Default</source>
      <translation>Alapértelmezett</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="772"/>
      <source>Yes</source>
      <translation>Igen</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="419"/>
      <location filename="../../src/settingsdialog.ui" line="777"/>
      <source>No</source>
      <translation>Nem</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="447"/>
      <source>PCI reset:</source>
      <translation>PCI visszaállítás:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="415"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Reset the Nvidia card at the PCI level before reloading the nvidia module&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;No&lt;/span&gt;: does not perform any reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Function level&lt;/span&gt;: perform a light &amp;quot;function-level&amp;quot; reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Hot reset&lt;/span&gt;: perform a &amp;quot;hot reset&amp;quot; of the PCI bridge (this method messes with the hardware directly and will perform a PCI remove even if it disabled, please read the online documentation of Optimus Manager before using it)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Állítsa alaphelyzetbe az Nvidia kártyát PCI szintent mielőtt újratöltené az nvidia modult&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nem&lt;/span&gt;: nem hajt végre visszaállítást&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Funkció szintű&lt;/span&gt;: végezzen könnyű, &amp;quot;function-level&amp;quot; visszaállítást&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Forró visszaállítás&lt;/span&gt;: végezzen &amp;quot;hot reset&amp;quot; -et a PCI hídon (ez a módszer közvetlenül a hardvert kezeli, és PCI eltávolítást végez, még ha kikapcsolja is, kérjük, olvassa el az Optimus Manager online dokumentációját, mielőtt használja)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="424"/>
      <source>Function level</source>
      <translation>Funkció szint</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="429"/>
      <source>Hot reset</source>
      <translation>Meleg újraindítás</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="470"/>
      <source>PCI remove</source>
      <translation>PCI leválasztás</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="712"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;DRI version&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;DRI verzió&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="480"/>
      <source>PCI power control</source>
      <translation>PCI energia vezérlés</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="231"/>
      <source>Hybrid icon:</source>
      <translation>Hibrid ikon:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="477"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable PCI power management in Intel mode&lt;/p&gt;&lt;p&gt;This option is incompatible with ACPI call and Bbswitch switching methods, so it will be ignored in those cases&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;PCI energiagazdálkodás engedélyezése Intel módban&lt;/p&gt;&lt;p&gt;Ez az opció inkompatibilis az ACPI hívással és a Bbswitch váltási módokkal, ezekben az esetekben figyelmen kívül lesz hagyva&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="519"/>
      <source>Switching method:</source>
      <translation>Váltási mód:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="68"/>
      <source>Configuration files</source>
      <translation>Beállítás fájlok</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="529"/>
      <source>Startup</source>
      <translation>Indítás</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="264"/>
      <source>Optimus Manager config</source>
      <translation>Optimus Manager beállítás</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="333"/>
      <source>Type:</source>
      <translation>Típus:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="273"/>
      <source>Path:</source>
      <translation>Útvonal:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="299"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Type of the configuration&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Permanent&lt;/span&gt;: configuration file that will be used every time it starts&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Temporary&lt;/span&gt;: configuration file that will be used only once at the next boot&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Konfiguráció típusa&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Állandó&lt;/span&gt;: konfigurációs fájl ami minden indításnál használva van&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Ideiglenes&lt;/span&gt;: konfigurációs fájl ami csak az elkövetkező indításnál lesz érvényes&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="303"/>
      <source>Permanent</source>
      <translation>Állandó</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="308"/>
      <source>Temporary</source>
      <translation>Ideiglenes</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="283"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Path to configuration file that will be loaded&lt;/p&gt;&lt;p&gt;If such a file does not exist, then it will be created automatically&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Konfigurációs fájl útvonala, ami be lesz töltve&lt;/p&gt;&lt;p&gt;Ha ilyen fájl nem létezik, akkor automatikusan létre lesz hozva&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="286"/>
      <source>Path to configuration file</source>
      <translation>Beállítás fájl útvonala</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="319"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Browse configuration file&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Beállítás fájl böngészése&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="322"/>
      <source>Browse</source>
      <translation>Böngészés</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="348"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Import Optimus Manager settings from file&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Optimus Manager beállítások importálása fájlból&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="351"/>
      <source>Import</source>
      <translation>Importálás</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="364"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Export current settings to file&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Jelenlegi beállítások exportálása fájlba&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="367"/>
      <source>Export</source>
      <translation>Exportálás</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="437"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Automatically log out the current desktop session when switching GPUs&lt;/p&gt;&lt;p&gt;This feature is currently supported for Gnome, KDE Plasma, LXDE, Deepin, Xfce, i3, Sway, Openbox, AwesomeWM and bspwm&lt;/p&gt;&lt;p&gt;If this options is disabled or you use a different desktop environment, GPU switching only becomes effective at the next graphical session login&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation type="unfinished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Automatically log out the current desktop session when switching GPUs&lt;/p&gt;&lt;p&gt;This feature is currently supported for Gnome, KDE Plasma, LXDE, Deepin, Xfce, i3, Sway, Openbox, AwesomeWM and bspwm&lt;/p&gt;&lt;p&gt;If this options is disabled or you use a different desktop environment, GPU switching only becomes effective at the next graphical session login&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="467"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Remove the Nvidia card from the PCI bus&lt;/p&gt;&lt;p&gt;May prevent crashes caused by power switching&lt;/p&gt;&lt;p&gt;Ignored if switching method is Nouveau or Bbswitch&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Távolítsa el az Nvidia kártyás a PCI busz-ról&lt;/p&gt;&lt;p&gt;Megakadályozhatja a energiakapcsolás okozta összeomlásokat&lt;/p&gt;&lt;p&gt;Figyelmen kívül van hagyva ha a váltási mód Nouveau vagy Bbswitch &lt;/p&gt;&lt;/body&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="487"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Method to power switch the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;None&lt;/span&gt;: do not use an external module for power management (for some laptop models it&apos;s preferable to use this option in combination with PCI power control)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nouveau&lt;/span&gt;: load the nouveau module on the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Bbswitch&lt;/span&gt;: power off the card using the bbswitch module (requires the &amp;quot;bbswitch&amp;quot;dependency)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;ACPI call&lt;/span&gt;: try various ACPI method calls to power the card on and off (requires the &amp;quot;acpi_call&amp;quot; dependency)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Custom&lt;/span&gt;: use custom scripts at &lt;span style=&quot; font-style:italic;&quot;&gt;/etc/optimus-manager/nvidia-enable.sh&lt;/span&gt; and &lt;span style=&quot; font-style:italic;&quot;&gt;/etc/optimus-manager/nvidia-disable.sh&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation type="unfinished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Method to power switch the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;None&lt;/span&gt;: do not use an external module for power management (for some laptop models it&apos;s preferable to use this option in combination with PCI power control)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nouveau&lt;/span&gt;: load the nouveau module on the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Bbswitch&lt;/span&gt;: power off the card using the bbswitch module (requires the &amp;quot;bbswitch&amp;quot;dependency)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;ACPI call&lt;/span&gt;: try various ACPI method calls to power the card on and off (requires the &amp;quot;acpi_call&amp;quot; dependency)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Custom&lt;/span&gt;: use custom scripts at &lt;span style=&quot; font-style:italic;&quot;&gt;/etc/optimus-manager/nvidia-enable.sh&lt;/span&gt; and &lt;span style=&quot; font-style:italic;&quot;&gt;/etc/optimus-manager/nvidia-disable.sh&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="511"/>
      <source>Custom</source>
      <translation type="unfinished">Custom</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="538"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU mode to select when &lt;span style=&quot; font-style:italic;&quot;&gt;Startup mode&lt;/span&gt; is &lt;span style=&quot; font-style:italic;&quot;&gt;Auto&lt;/span&gt; and the computer is running on battery&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation type="unfinished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU mode to select when &lt;span style=&quot; font-style:italic;&quot;&gt;Startup mode&lt;/span&gt; is &lt;span style=&quot; font-style:italic;&quot;&gt;Auto&lt;/span&gt; and the computer is running on battery&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="575"/>
      <source>Battery startup mode:</source>
      <translation type="unfinished">Battery startup mode:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="592"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU mode to select when &lt;span style=&quot; font-style:italic;&quot;&gt;Startup mode&lt;/span&gt; is &lt;span style=&quot; font-style:italic;&quot;&gt;Auto&lt;/span&gt; and the computer is running on external power&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation type="unfinished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU mode to select when &lt;span style=&quot; font-style:italic;&quot;&gt;Startup mode&lt;/span&gt; is &lt;span style=&quot; font-style:italic;&quot;&gt;Auto&lt;/span&gt; and the computer is running on external power&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="626"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU mode to use at computer startup&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Auto&lt;/span&gt; is a special mode that auto-detects if the computer is running on battery and selects a proper GPU mode&lt;/p&gt;&lt;p&gt;See the other options below for details&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation type="unfinished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU mode to use at computer startup&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Auto&lt;/span&gt; is a special mode that auto-detects if the computer is running on battery and selects a proper GPU mode&lt;/p&gt;&lt;p&gt;See the other options below for details&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="657"/>
      <source>Auto</source>
      <translation type="unfinished">Auto</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="729"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Driver to use for the Intel GPU&lt;br/&gt;&lt;br/&gt;To use the Intel driver, you need to install the package &amp;quot;xf86-video-intel&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Intel illesztőprogram&lt;br/&gt;&lt;br/&gt;Az Intel illesztőprogramra szükség van, telepítse a &amp;quot;xf86-video-intel&amp;quot; csomagot&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="763"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable TearFree option in the Xorg configuration&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Szakadásmentesítés engedélyezése az Xorg konfigurációban&lt;/p&gt;&lt;p&gt;Csak az Intel illesztőprogramra érvényes&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="795"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Acceleration method (corresponds to AccelMethod in the Xorg configuration)&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Gyorsítási módszer (megfelel az AccelMethod-nak az Xorg-konfigurációban)&lt;/p&gt;&lt;p&gt;Csak az Intel illesztőprogramra vonatkozik&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="936"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable modesetting&lt;/p&gt;&lt;p&gt;Required for PRIME Synchronization (which prevents tearing)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Modesetting engedélyezése&lt;/p&gt;&lt;p&gt;Szükséges a PRIME szinkronizáláshoz (amely megakadályozza a képernyőszakadást)</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="946"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Use Optimus Manager with external Nvidia GPUs (experimental)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation type="unfinished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Use Optimus Manager with external Nvidia GPUs (experimental)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="926"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;If you&apos;re running an updated version of xorg-server (let&apos;s say to get PRIME Render offload enabled), the Nvidia driver may not load because of an ABI version mismatch&lt;/p&gt;&lt;p&gt;Enabling this option will allow loading the Nvidia driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation type="unfinished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;If you&apos;re running an updated version of xorg-server (let&apos;s say to get PRIME Render offload enabled), the Nvidia driver may not load because of an ABI version mismatch&lt;/p&gt;&lt;p&gt;Enabling this option will allow loading the Nvidia driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="903"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable triple buffering&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Tripla pufferezés engedélyezése&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="906"/>
      <source>Triple buffer</source>
      <translation>Tripla puffer</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="893"/>
      <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable CoolBits in the Xorg configuration, which unlocks clocking options in the Nvidia control panel&lt;/p&gt;&lt;p&gt;Note: does not work in Hybrid mode&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
      <translation type="unfinished">&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable CoolBits in the Xorg configuration, which unlocks clocking options in the Nvidia control panel&lt;/p&gt;&lt;p&gt;Note: does not work in Hybrid mode&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="929"/>
      <source>Ignore ABI</source>
      <translation type="unfinished">Ignore ABI</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="949"/>
      <source>Allow external GPUs</source>
      <translation type="unfinished">Allow external GPUs</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="1006"/>
      <location filename="../../src/settingsdialog.ui" line="1137"/>
      <source>Version:</source>
      <translation>Verzió:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="1020"/>
      <location filename="../../src/settingsdialog.ui" line="1114"/>
      <source>Author:</source>
      <translation>Szerző:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.ui" line="1027"/>
      <location filename="../../src/settingsdialog.ui" line="1151"/>
      <source>License:</source>
      <translation>Licensz:</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="82"/>
      <source>Optimus Manager temporary configuration file path cannot be empty</source>
      <translation>Az Optimus Manager ideiglenes konfigurációs fájl útvonala nem lehet üres</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="89"/>
      <source>Optimus Manager temporary configuration file path cannot be a permanent configuration file path</source>
      <translation>Az Optimus Manager ideiglenes konfigurációs fájl útvonala nem lehet állandó konfigurációs fájl útvonal</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="111"/>
      <source>Unable to read data from generated configuration</source>
      <translation type="unfinished">Unable to read data from generated configuration</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="250"/>
      <source>Select temporary configuration file</source>
      <translation>Átmeneti beállítás fájl kiváltasztása</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="251"/>
      <location filename="../../src/settingsdialog.cpp" line="263"/>
      <location filename="../../src/settingsdialog.cpp" line="276"/>
      <source>Config files (*.conf);;All files(*)</source>
      <translation>Beállítás fájlok (*.conf);;Összes fájl(*)</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="262"/>
      <source>Export Optimus Manager settings</source>
      <translation>Optimus Manager beállítások exportálása</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="275"/>
      <source>Import Optimus Manager settings</source>
      <translation>Optimus Manager beállítások importálása</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="439"/>
      <source>Select icon</source>
      <translation>Válasszon ikont</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="440"/>
      <source>Images (*.png *.jpg *.bmp);;All files(*)</source>
      <translation>Képek (*.png *.jpg *.bmp);;Összes fájl(*)</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="471"/>
      <source>Unable to find Optimus Manager daemon.</source>
      <translation>Optimus Manager démon nem található.</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="472"/>
      <source>Please check the integrity of the package that provides Optimus Manager.</source>
      <translation>Kérem ellenőrizze a csomag sértetlenségét amellyel beszerezte az Optimus Manager-t.</translation>
    </message>
    <message>
      <location filename="../../src/settingsdialog.cpp" line="474"/>
      <source>Not found!</source>
      <translation>Nem található!</translation>
    </message>
  </context>
</TS>
