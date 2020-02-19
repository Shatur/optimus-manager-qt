<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="tr">
<context>
    <name>AppSettings</name>
    <message>
        <location filename="../../src/appsettings.cpp" line="75"/>
        <source>Unable to create autorun file from &apos;%1&apos;</source>
        <translation>&apos;% 1&apos; den otomatik çalıştırma dosyası oluşturulamıyor</translation>
    </message>
</context>
<context>
    <name>DaemonClient</name>
    <message>
        <location filename="../../src/daemonclient.cpp" line="111"/>
        <source>Unable to open startup mode file</source>
        <translation type="unfinished">Başlangıç modu dosyası açılamıyor</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="354"/>
        <location filename="../../src/settingsdialog.cpp" line="101"/>
        <source>Unable to connect to Optimus Manager daemon: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="364"/>
        <source>Unable to send GPU name to switch to Optimus Manager daemon: %1</source>
        <translation type="unfinished">Optimus Manager arkaplana geçmek için GPU adı gönderilemiyor:% 1</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="129"/>
        <source>Unable to send configuration file to Optimus Manager daemon: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="138"/>
        <source>Unable to send startup mode to Optimus Manager daemon: %1</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>OptimusManager</name>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="174"/>
        <source>Switch to Intel</source>
        <translation>Intel&apos;e Geç</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="175"/>
        <source>Switch to Nvidia</source>
        <translation>Nvidia&apos;ya Geç</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="65"/>
        <location filename="../../src/optimusmanager.cpp" line="176"/>
        <source>Exit</source>
        <translation>Çıkış</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="60"/>
        <location filename="../../src/optimusmanager.cpp" line="61"/>
        <location filename="../../src/optimusmanager.cpp" line="62"/>
        <source>Switch to %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="152"/>
        <location filename="../../src/optimusmanager.cpp" line="161"/>
        <source>The specified icon &apos;%1&apos; for the current GPU is invalid. The default icon will be used.</source>
        <translation>Geçerli GPU için belirtilen &apos;%1 &apos; simgesi geçersiz. Varsayılan simge kullanılacaktır.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="152"/>
        <location filename="../../src/optimusmanager.cpp" line="161"/>
        <source>Invalid icon</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="189"/>
        <source>You are about to switch GPU.</source>
        <translation>GPU’yu değiştirmek üzeresiniz.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="191"/>
        <source>You will be automatically logged out to apply the changes.</source>
        <translation>Değişiklikleri uygulamak için otomatik olarak oturumunuz kapatılacaktır.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="202"/>
        <source>No power management option is currently enabled</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="203"/>
        <source>Switching between GPUs will work but you will likely experience poor battery life.
If you have already enabled the new Runtime D3 power management inside the Nvidia driver (for Turing+ GPU with Coffee Lake+ CPU), you can safely ignore this warning.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="213"/>
        <source>The Optimus Manager service is not running.</source>
        <translation>Optimus Manager hizmeti çalışmıyor.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="262"/>
        <source>There are %1 other desktop sessions open. The GPU switch will not become effective until you have manually logged out from ALL desktop sessions.
Continue?</source>
        <translation>%1 diğer masaüstü oturumları açık. Tüm masaüstü oturumlarından elle çıkana kadar GPU etkili olmaz.
Devam edilsin mi?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="277"/>
        <source>Wayland session found.</source>
        <translation>Wayland oturumu bulundu.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="278"/>
        <source>Session %1, started by %2, is a Wayland session. Wayland is not supported by Optimus Manager, so GPU switching may fail.
Continue anyway?</source>
        <translation>% 1 oturumu,% 2 tarafından başlatılan bir Wayland oturumu. Wayland, Optimus Manager tarafından desteklenmiyor, bu nedenle GPU değişimi başarısız olabilir.
Devam edilsin mi?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="295"/>
        <source>The Bumblebee service (%1) is running.</source>
        <translation>Bumblebee servisi (% 1) çalışıyor.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="338"/>
        <source>The Xorg driver &apos;%1&apos; is not installed.</source>
        <translation>Xorg sürücüsü &apos;%1&apos; yüklü değil.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="339"/>
        <source>Optimus Manager will use &apos;%1&apos; driver instead. You can change driver in settings or install the &apos;%2&apos; driver from the package &apos;%3&apos;.
Continue anyway?</source>
        <translation>Optimus Manager bunun yerine &apos;% 1&apos; sürücüsünü kullanacak. Ayarları değiştirerek sürücüyü değiştirebilir veya &apos;% 2&apos; sürücüsünü &apos;% 3&apos; paketinden yükleyebilirsiniz.
Devam edilsin mi?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="371"/>
        <source>Configuration successfully applied</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="371"/>
        <source>Your GPU will be switched after next login.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="310"/>
        <source>If you did not create it yourself, it was likely generated by your distribution or by an Nvidia utility.
This file may contain hard-coded GPU configuration that could interfere with Optimus Manager, so it is recommended that you delete it before proceeding.
Ignore this warning and proceed with GPU switching?</source>
        <translation>Kendiniz yaratmadıysanız, büyük olasılıkla dağıtımınız veya bir Nvidia hizmet programı tarafından oluşturulmuştur.
Bu dosya Optimus Manager ile etkileşime girebilecek kodlanmış GPU yapılandırması içerebilir, bu yüzden devam etmeden önce silmeniz önerilir.
Bu uyarıyı dikkate almayın ve GPU geçişi ile devam edin.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="324"/>
        <source>This file was auto-generated by the Manjaro driver utility (MHWD). This will likely interfere with GPU switching, so Optimus Manager will delete this file automatically if you proceded with GPU switching.
Proceed?</source>
        <translation>Bu dosya manjaro sürücü yardımcı programı (MHWD) tarafından otomatik olarak oluşturuldu. Bu muhtemelen GPU geçişine müdahale edecektir, bu nedenle GPU geçişine devam ederseniz Optimus Manager bu dosyayı otomatik olarak silecektir.
Devam edilsin mi?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="193"/>
        <source>After applying the settings, you will need to manually re-login to change the video card.</source>
        <translation>Ayarları uyguladıktan sonra, ekran kartını değiştirmek için elle yeniden giriş yapmanız gerekecektir.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="72"/>
        <location filename="../../src/optimusmanager.cpp" line="171"/>
        <source>Current videocard: %1</source>
        <translation>Mevcut ekran kartı:%1</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="214"/>
        <source>Please enable and start it with:
&apos;%1&apos;
&apos;%2&apos;</source>
        <translation>Lütfen etkinleştirin ve başlatın:
&apos;%1&apos;
&apos;%2&apos;</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="224"/>
        <location filename="../../src/optimusmanager.cpp" line="236"/>
        <source>The %1 module does not seem to be available for the current kernel.</source>
        <translation>% 1 modülü geçerli çekirdek için uygun görünmüyor.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="225"/>
        <source>Power switching will not work.
You can set &apos;%1&apos; for GPU switching in settings or install bbswitch forthe default kernel with &apos;%2&apos; or for all kernels with &apos;%3&apos;.</source>
        <translation>Güç değiştirme çalışmaz.
Ayarlarda GPU geçişi için &apos;% 1&apos; değerini ayarlayabilir veya &apos;% 2&apos; ile varsayılan çekirdek için veya &apos;% 3&apos; olan tüm çekirdekler için bbswitch&apos;i kurabilirsiniz.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="237"/>
        <source>It is likely the Nvidia driver was not properly installed. GPU switching will probably fail, continue anyway?</source>
        <translation>Nvidia sürücüsünün doğru bir şekilde kurulmamış olması muhtemeldir. GPU değişimi muhtemelen başarısız olacak, yine de devam edecek misiniz?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="247"/>
        <source>Looks like you&apos;re using a non-patched version of the Gnome Display Manager (GDM).</source>
        <translation>Gnome Ekran Yöneticisi&apos;nin (GDM) yamalı olmayan bir sürümünü kullanıyor gibi görünüyor.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="248"/>
        <source>GDM need to be patched for Prime switching. Follow &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;this&lt;/a&gt; instructions to install a patched version. Without a patched GDM version, GPU switching will likely fail.
Continue anyway?</source>
        <translation>Prime değiştirme için GDM&apos;nin yamalanması gerekir. Yamalı bir sürüm yüklemek için &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;bu&lt;/a&gt; talimatları izleyin. Yamalanmış bir GDM sürümü olmadan, GPU geçişi büyük olasılıkla başarısız olacaktır.
Devam edilsin mi?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="261"/>
        <source>Multiple running sessions detected.</source>
        <translation>Çoklu oturumlar tespit edildi.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="296"/>
        <source>This can interfere with Optimus Manager. Before attempting a GPU switch, it is recommended that you disable this service with &apos;%1&apos; and reboot your computer.
Ignore this warning and proceed with GPU switching now?</source>
        <translation>Bu, Optimus Manager ile etkileşime girebilir. Bir GPU değişimini denemeden önce, bu hizmeti &apos;% 1&apos; ile devre dışı bırakmanız ve bilgisayarınızı yeniden başlatmanız önerilir.
Bu uyarıyı dikkate almayın ve şimdi GPU geçişi ile devam edin.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="309"/>
        <location filename="../../src/optimusmanager.cpp" line="323"/>
        <source>Found a Xorg config file at &apos;%1&apos;.</source>
        <translation>&apos;%1 &apos; de bir Xorg yapılandırma dosyası bulundu.</translation>
    </message>
</context>
<context>
    <name>SettingsDialog</name>
    <message>
        <location filename="../../src/settingsdialog.ui" line="14"/>
        <location filename="../../src/optimusmanager.cpp" line="56"/>
        <location filename="../../src/optimusmanager.cpp" line="173"/>
        <source>Settings</source>
        <translation>Ayarlar</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="59"/>
        <location filename="../../src/settingsdialog.ui" line="118"/>
        <source>General</source>
        <translation>Genel</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="104"/>
        <source>About</source>
        <translation>Hakkında</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="137"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Application language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Uygulama dili&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="140"/>
        <source>Language:</source>
        <translation>Dil:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="45"/>
        <source>&lt;System language&gt;</source>
        <translation>&lt;System language&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="163"/>
        <source>Launch at startup</source>
        <translation>Başlangıçta başlat</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="170"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Show confirmation dialog when switching GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU’yu değiştirirken onay iletişim kutusunu göster&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="173"/>
        <source>Confirm switching</source>
        <translation>Geçişi Onayla</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="224"/>
        <source>Nvidia icon:</source>
        <translation>Nvidia simgesi:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="210"/>
        <source>Intel icon:</source>
        <translation>Intel simgesi:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="304"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Specify which GPU will be used by default when the system boots&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Sistem önyüklenirken hangi GPU&apos;nun varsayılan olarak kullanılacağını belirtin&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="572"/>
        <source>ACPI call</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="580"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Module used for power switching&lt;/p&gt;&lt;p&gt;If you select &amp;quot;None&amp;quot;, no power switching will be done at all (the Nvidia GPU will stay powered at all times)&lt;/p&gt;&lt;p&gt;If you use bbswitch, you will not be able to use video outputs attached to your Nvidia GPU in Intel mode&lt;/p&gt;&lt;p&gt;To use the bbswitch mode, the bbswitch module must be installed for your current kernel&lt;/p&gt;&lt;p&gt;You can install it for the default kernel with &amp;quot;pacman -S bbswitch&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Güç değişimi için kullanılan modül&lt;/p&gt;&lt;p&gt;Eğer &amp;quot;yok&amp;quot; seçeneğini seçerseniz, hiçbir güç geçişi yapılmaz (Nvidia GPU her zaman güç kalacak)&lt;/p&gt;&lt;p&gt;Eğer bbswitch kullanıyorsanız, Nvidia GPU’nuza bağlı video çıkışlarını Intel modunda kullanamazsınız.&lt;/p&gt;&lt;p&gt;Bbswitch modunu kullanmak için, geçerli çekirdeğiniz için bbswitch modülünün kurulu olması gerekir.&lt;/p&gt;&lt;p&gt;Varsayılan çekirdek için &amp;quot;pacman-s bbswitch&amp;quot; ile yükleyebilirsiniz;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="506"/>
        <source>Automatic logout</source>
        <translation>Otomatik çıkış</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="741"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable modesetting for the nouveau driver&lt;/p&gt;&lt;p&gt;Does not affect modesetting for the Intel GPU driver&lt;/p&gt;&lt;p&gt;This option is incompatible with Bbswitch and will be ignored if it is enabled&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="787"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;This will be set using the Xsetup script passed to your login manager&lt;br/&gt;It will run the command&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Leave 0 for the default&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Bu, oturum açma yöneticinize iletilen Xsetup komut dosyası kullanılarak ayarlanır.&lt;br/&gt;Komutu çalıştırır&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Varsayılan değer için 0 bırakın&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="777"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable the NVreg_UsePageAttributeTable option in the Nvidia driver &lt;span style=&quot; font-style:italic;&quot;&gt;Recommended&lt;/span&gt;, can cause poor CPU performance otherwise&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Nvidia sürücüsündeki NVreg_UsePageAttributeTable seçeneğinin etkinleştirilip etkinleştirilmeyeceği&lt;span style=&quot; font-style:italic;&quot;&gt;Tavsiye &lt;/span&gt;, aksi takdirde düşük CPU performansına neden olabilir.&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="840"/>
        <source>Overclocking options</source>
        <translation>Hızaşırtma seçenekleri</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="160"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart will be used&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart kullanılacak&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="183"/>
        <source>Tray icons</source>
        <translation>Tepsi simgeleri</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="189"/>
        <location filename="../../src/settingsdialog.ui" line="196"/>
        <source>Choose icon</source>
        <translation>Simge seçin</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="307"/>
        <source>Startup mode:</source>
        <translation>Başlangıç modu:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="557"/>
        <source>None</source>
        <translation>Hiçbiri</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="124"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Interface language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Arayüz dili&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="203"/>
        <location filename="../../src/settingsdialog.ui" line="217"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Path to the icon or icon name from theme&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Temadan simge veya simge adına giden yol&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="270"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU that will be used during normal system startup&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Normal sistem başlatma sırasında kullanılacak olan GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="616"/>
        <source>Driver:</source>
        <translation>Sürücü:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="657"/>
        <source>Acceleration method:</source>
        <translation>Hızlanma yöntemi:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="678"/>
        <location filename="../../src/settingsdialog.ui" line="710"/>
        <source>Default</source>
        <translation>Varsayılan</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="683"/>
        <source>Yes</source>
        <translation>Evet</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="485"/>
        <location filename="../../src/settingsdialog.ui" line="688"/>
        <source>No</source>
        <translation>Hayır</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="513"/>
        <source>PCI reset:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="481"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Reset the Nvidia card at the PCI level before reloading the nvidia module&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;No&lt;/span&gt;: does not perform any reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Function level&lt;/span&gt;: perform a light &amp;quot;function-level&amp;quot; reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Hot reset&lt;/span&gt;: perform a &amp;quot;hot reset&amp;quot; of the PCI bridge (this method messes with the hardware directly and will perform a PCI remove even if it disabled, please read the online documentation of Optimus Manager before using it)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="490"/>
        <source>Function level</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="495"/>
        <source>Hot reset</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="536"/>
        <source>PCI remove</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="623"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;DRI version&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;DRI versiyonu&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="546"/>
        <source>PCI power control</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="231"/>
        <source>Hybrid icon:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="553"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Method to power switch the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;None&lt;/span&gt;: do not use an external module for power management (for some laptop models it&apos;s preferable to use this option in combination with PCI power control), you can use the scipts nvidia-enable.sh and nvidia-disable.sh to execute custom commands for power management that will be executed only with this method&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nouveau&lt;/span&gt;: load the nouveau module on the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Bbswitch&lt;/span&gt;: power off the card using the bbswitch module (requires the &amp;quot;bbswitch&amp;quot;dependency)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;ACPI call&lt;/span&gt;: try various ACPI method calls to power the card on and off (requires the &amp;quot;acpi_call&amp;quot; dependency)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="543"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable PCI power management in Intel mode&lt;/p&gt;&lt;p&gt;This option is incompatible with ACPI call and Bbswitch switching methods, so it will be ignored in those cases&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="583"/>
        <source>Switching method:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="503"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Automatically log out the current desktop session when switching GPUs&lt;/p&gt;&lt;p&gt;This feature is currently supported for Gnome, KDE Plasma, Deepin, Xfce, i3, Sway, Openbox, AwesomeWM and bspwm&lt;/p&gt;&lt;p&gt;If this options is disabled or you use a different desktop environment, GPU switching only becomes effective at the next graphical session login&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="68"/>
        <source>Configuration files</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="264"/>
        <source>Startup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="330"/>
        <source>Optimus Manager config</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="399"/>
        <source>Type:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="339"/>
        <source>Path:</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="365"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Type of the configuration&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Permanent&lt;/span&gt;: configuration file that will be used every time it starts&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Temporary&lt;/span&gt;: configuration file that will be used only once at the next boot&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="369"/>
        <source>Permanent</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="374"/>
        <source>Temporary</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="349"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Path to configuration file that will be loaded&lt;/p&gt;&lt;p&gt;If such a file does not exist, then it will be created automatically&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="352"/>
        <source>Path to configuration file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="385"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Browse configuration file&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="388"/>
        <source>Browse</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="414"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Import Optimus Manager settings from file&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="417"/>
        <source>Import</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="430"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Export current settings to file&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="433"/>
        <source>Export</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="533"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Remove the Nvidia card from the PCI bus&lt;/p&gt;&lt;p&gt;May prevent crashes caused by power switching&lt;/p&gt;&lt;p&gt;Ignored if switching method is Nouveau or Bbswitch&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="640"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Driver to use for the Intel GPU&lt;br/&gt;&lt;br/&gt;To use the Intel driver, you need to install the package &amp;quot;xf86-video-intel&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="674"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable TearFree option in the Xorg configuration&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="706"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Acceleration method (corresponds to AccelMethod in the Xorg configuration)&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="820"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable modesetting&lt;/p&gt;&lt;p&gt;Required for PRIME Synchronization (which prevents tearing)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="847"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;If you&apos;re running an updated version of xorg-server (let&apos;s say to get PRIME Render offload enabled), the Nvidia driver may not load because of an ABI version mismatch&lt;/p&gt;&lt;p&gt;Enabling this option will allow loading the Nvidia driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="797"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable triple buffering&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Üçlü arabelleklemeyi etkinleştir&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="800"/>
        <source>Triple buffer</source>
        <translation>Üçlü arabellek</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="837"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable CoolBits in the Xorg configuration, which unlocks clocking options in the Nvidia control panel&lt;/p&gt;&lt;p&gt;Note: does not work in Hybrid mode&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="850"/>
        <source>Ignore ABI</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="907"/>
        <location filename="../../src/settingsdialog.ui" line="1038"/>
        <source>Version:</source>
        <translation>Versiyon:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="921"/>
        <location filename="../../src/settingsdialog.ui" line="1015"/>
        <source>Author:</source>
        <translation>Yazar:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="928"/>
        <location filename="../../src/settingsdialog.ui" line="1052"/>
        <source>License:</source>
        <translation>Lisans:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="82"/>
        <source>Optimus Manager temporary configuration file path cannot be empty</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="89"/>
        <source>Optimus Manager temporary configuration file path cannot be a permanent configuration file path</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="111"/>
        <source>Unable to read data from generated configuration</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="245"/>
        <source>Select temporary configuration file</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="246"/>
        <location filename="../../src/settingsdialog.cpp" line="258"/>
        <location filename="../../src/settingsdialog.cpp" line="271"/>
        <source>Config files (*.conf);;All files(*)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="257"/>
        <source>Export Optimus Manager settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="270"/>
        <source>Import Optimus Manager settings</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="425"/>
        <source>Select icon</source>
        <translation>Simge Seç</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="426"/>
        <source>Images (*.png *.jpg *.bmp);;All files(*)</source>
        <translation>Resimler (*.png *.jpg *.bmp);;Tüm dosyalar(*)</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="457"/>
        <source>Unable to find Optimus Manager daemon.</source>
        <translation>Optimus Manager arkaplanı bulunamadı.</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="458"/>
        <source>Please check the integrity of the package that provides Optimus Manager.</source>
        <translation>Lütfen Optimus Manager&apos;ı sağlayan paketin bütünlüğünü kontrol edin.</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="460"/>
        <source>Not found!</source>
        <translation>Bulunamadı!</translation>
    </message>
</context>
</TS>
