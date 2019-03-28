<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="zh_CN">
<context>
    <name>AppSettings</name>
    <message>
        <location filename="../../src/appsettings.cpp" line="71"/>
        <source>Unable to create autorun file from &apos;%1&apos;</source>
        <translation>无法在&apos;%1&apos;中创建自动启动文件</translation>
    </message>
</context>
<context>
    <name>OptimusManager</name>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="53"/>
        <location filename="../../src/optimusmanager.cpp" line="202"/>
        <source>Switch to Intel</source>
        <translation>切换到 Intel</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="54"/>
        <location filename="../../src/optimusmanager.cpp" line="203"/>
        <source>Switch to Nvidia</source>
        <translation>切换到 Nvidia</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="56"/>
        <location filename="../../src/optimusmanager.cpp" line="204"/>
        <source>Exit</source>
        <translation>退出</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="64"/>
        <location filename="../../src/optimusmanager.cpp" line="199"/>
        <source>Current videocard: </source>
        <translation>目前使用的显卡：</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="119"/>
        <source>The application is already running</source>
        <translation>程序已在运行中</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="180"/>
        <location filename="../../src/optimusmanager.cpp" line="190"/>
        <source>The specified icon &apos;%1&apos; for the current GPU is invalid. The default icon will be used.</source>
        <translation>为当前使用的 GPU 指定的图标 %1 无效。将使用默认图标。</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="217"/>
        <source>You are about to switch GPUs. This will restart the display manager and all your applications will be closed.</source>
        <translation>您将要切换 GPU。这将关闭您所有正在运行的程序并重启显示管理器。</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="219"/>
        <source>You are about to switch GPUs. After applying the settings, you will need to manually restart the login manager to change the video card.</source>
        <translation>您将要切换 GPU。应用此设置之后，您需要手动重启登录管理器以切换显卡。</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="230"/>
        <source>The optimus-manager service is not running. Please enable and start it with:</source>
        <translation>optimus-manager 服务未运行。请按照如下指示启用并启动它：</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="244"/>
        <source>bbswitch is enabled in the configuration file but the bbswitch module does not seem to be available for the current kernel. Power switching will not work.
You can install bbswitch for the default kernel with &quot;sudo pacman -S bbswitch&quot; or for all kernels with &quot;sudo pacman -S bbswitch-dkms&quot;.</source>
        <translation>在配置文件中启用了 bbswitch，但是 bbswitch 模块似乎对当前内核不可用，因此功耗调节功能无法工作。
您可以使用“sudo pacman -S bbswitch”或“sudo pacman -S bbswitch-dkms”安装 bbswitch。</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="257"/>
        <source>The nvidia module does not seem to be available for the current kernel. It is likely the Nvidia driver was not properly installed. GPU switching will probably fail, continue anyway?</source>
        <translation>nvidia 模块似乎对当前内核不可用。nvidia 驱动可能安装不正确。GPU 切换可能会失败，是否继续？</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="275"/>
        <source>Unable to connect to optimus-manager daemon to switch GPU: </source>
        <translation>无法连接到 optimus-manager 后台以切换 GPU：</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="295"/>
        <source>Unable to send GPU to switch to optimus-manager daemon: </source>
        <translation>无法发送将要切换的 GPU 信息到 optimus-manager 后台：</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="301"/>
        <source>Configuration successfully applied. Your GPU will be switched after the login manager is restarted.</source>
        <translation>配置应用成功您。您的 GPU 将在您登录管理器重启后切换。</translation>
    </message>
</context>
<context>
    <name>OptimusSettings</name>
    <message>
        <location filename="../../src/optimussettings.cpp" line="64"/>
        <source>Unable to connect to optimus-manager daemon to send startup mode: </source>
        <translation>无法连接到 optimus-manager 后台以发送启动模式：</translation>
    </message>
    <message>
        <location filename="../../src/optimussettings.cpp" line="70"/>
        <source>Unable to send startup mode to optimus-manager daemon: </source>
        <translation>无法发送启动模式到 optimus-manager-daemon 后台：</translation>
    </message>
    <message>
        <location filename="../../src/optimussettings.cpp" line="79"/>
        <source>Unable to open startup mode file</source>
        <translation>无法打开启动模式文件</translation>
    </message>
    <message>
        <location filename="../../src/optimussettings.cpp" line="94"/>
        <source>Unknown mode in startup file</source>
        <translation>启动文件中存在未知模式</translation>
    </message>
</context>
<context>
    <name>SettingsDialog</name>
    <message>
        <location filename="../../src/settingsdialog.ui" line="14"/>
        <location filename="../../src/optimusmanager.cpp" line="51"/>
        <location filename="../../src/optimusmanager.cpp" line="201"/>
        <source>Settings</source>
        <translation>设置</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="59"/>
        <location filename="../../src/settingsdialog.ui" line="109"/>
        <source>General</source>
        <translation>常规</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="95"/>
        <source>About</source>
        <translation>关于</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="123"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Application language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;应用程序语言&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="126"/>
        <source>Language:</source>
        <translation>语言：</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="134"/>
        <source>&lt;System language&gt;</source>
        <translation>&lt;系统语言&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="157"/>
        <source>Simplified Chinese</source>
        <translation>简体中文</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="184"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart will be used&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;将会使用 ~/.config/autostart&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="187"/>
        <source>Launch at startup</source>
        <translation>系统启动时启动</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="194"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Show confirmation dialog when switching GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;切换 GPU 时显示确认对话框&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="197"/>
        <source>Confirm switching</source>
        <translatorcomment>意译</translatorcomment>
        <translation>切换时确认</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="207"/>
        <source>Tray icons</source>
        <translation>托盘图标</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="213"/>
        <source>Intel icon:</source>
        <translation>Intel 图标：</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="226"/>
        <source>Nvidia icon:</source>
        <translation>Nvidia 图标：</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="233"/>
        <location filename="../../src/settingsdialog.ui" line="240"/>
        <source>Choose icon</source>
        <translation>选择图标</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="275"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Specify which GPU will be used by default when the system boots&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;指定系统启动时使用的 GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="278"/>
        <source>Startup mode:</source>
        <translation>启动模式：</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="304"/>
        <source>Nvidia (one boot)</source>
        <translation>Nvidia（仅一次）</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="333"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Module used for power switching&lt;/p&gt;&lt;p&gt;If you select &amp;quot;None&amp;quot;, no power switching will be done at all (the Nvidia GPU will stay powered at all times)&lt;/p&gt;&lt;p&gt;If you use bbswitch, you will not be able to use video outputs attached to your Nvidia GPU in Intel mode&lt;/p&gt;&lt;p&gt;To use the bbswitch mode, the bbswitch module must be installed for your current kernel&lt;/p&gt;&lt;p&gt;You can install it for the default kernel with &amp;quot;pacman -S bbswitch&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;功耗切换时使用的模块&lt;/p&gt;&lt;p&gt;如果您选择&amp;quot;无&amp;quot;则不会进行任何的功耗切换（Nvidia 显卡会一直保持启动）&lt;/p&gt;&lt;p&gt;如果您使用 bbswitch，则在 Intel 模式下，您将无法使用连接到 Nvidia GPU 的视频输出&lt;/p&gt;&lt;p&gt;若要使用 bbswitch 模式，您必须为当前内核安装 bbswitch 模块&lt;/p&gt;&lt;p&gt;您可以使用&amp;quot;pacman -S bbswitch&amp;quot;为默认内核安装 bbswitch 模块&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="336"/>
        <source>Switching backend:</source>
        <translation>切换后端：</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="344"/>
        <source>None</source>
        <translation>无</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="377"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not restart login manager when switching GPUs&lt;/p&gt;&lt;p&gt;If disabled, the GPU switch is not applied until you have restarted it manually&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;是否在切换 GPU 时重启登录管理器&lt;/p&gt;&lt;p&gt;如果禁用该选项，直到您手动重启登录管理器前 GPU 切换都不会生效&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="380"/>
        <source>Login manager control</source>
        <translation>控制登录管理器</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="387"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable PCI power management in Intel mode&lt;/p&gt;&lt;p&gt;If you do not enable this option, you may see a higher power comsumption&lt;/p&gt;&lt;p&gt;This option is incompatible with bbswitch and will be ignored if it is enabled&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;为 Intel 模式启用 PCI 功耗控制&lt;/p&gt;&lt;p&gt;如果您没有启用该选项，则有可能遇到更高的功耗&lt;/p&gt;&lt;p&gt;该选项与 bbswitch 不兼容，并且 bbswitch 模式启用时会自动忽略该选项&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="390"/>
        <source>PCI power control</source>
        <translation>PCI 功耗控制</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="397"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Reset the Nvidia PCI device when switching&lt;/p&gt;&lt;p&gt;Avoids driver conflicts, especially when switching from Nvidia mode to Intel Mode&lt;/p&gt;&lt;p&gt;This option is incompatible with bbswitch and will be ignored if it is enabled&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;切换时重置 Nvidia PCI 设备&lt;/p&gt;&lt;p&gt;避免驱动冲突，特别是当从 Nvidia 模式切换至 Intel 模式时&lt;/p&gt;&lt;p&gt;该选项与 bbswitch 不兼容，并且 bbswitch 模式启用时会自动忽略该选项&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="400"/>
        <source>PCI reset</source>
        <translation>重置 PCI</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="407"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to manually terminate logind sessions when switching GPUs&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;是否在切换 GPU 时手动结束 logind 会话&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="410"/>
        <source>Terminate sessions</source>
        <translation>结束会话</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="417"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to manually kill X11 servers when switching GPUs&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;是否在切换 GPU 时手动结束 X11 服务端&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="420"/>
        <source>Kill X11</source>
        <translation>结束 X11</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="427"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to manually kill logind when switching GPUs&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;是否在切换 GPU 时手动结束 logind&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="430"/>
        <source>Kill logind</source>
        <translation>结束 logind</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="465"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Driver to use for the Intel GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;为 Intel GPU 使用的驱动&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="468"/>
        <source>Driver:</source>
        <translation>驱动：</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="506"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable AccelMethod option in the Xorg configuration&lt;br/&gt;&lt;br/&gt;This option compatible only with the Intel driver and will be ignored if it is not selected&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;在 Xorg 配置中启用 AccelMethod 选项&lt;br/&gt;&lt;br/&gt;仅与 Intel 驱动兼容，并且在不使用 Intel 驱动时自动忽略该选项&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="509"/>
        <source>Acceleration method:</source>
        <translation>加速方式：</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="520"/>
        <location filename="../../src/settingsdialog.ui" line="569"/>
        <source>Default</source>
        <translation>默认</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="555"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable TearFree option in the Xorg configuration&lt;br/&gt;&lt;br/&gt;This option compatible only with the Intel driver and will be ignored if it is not selected&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;在 Xorg 配置中启用 TearFree 选项&lt;br/&gt;&lt;br/&gt;仅与 Intel 驱动兼容，并且在不使用 Intel 驱动时自动忽略该选项&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="574"/>
        <source>Yes</source>
        <translation>是</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="579"/>
        <source>No</source>
        <translation>否</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="604"/>
        <location filename="../../src/settingsdialog.ui" line="681"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;DRI version&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;DRI 版本&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="643"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable modesetting for the nouveau driver&lt;/p&gt;&lt;p&gt;Does not affect modesetting for the Intel GPU driver&lt;/p&gt;&lt;p&gt;This option is incompatible with bbswitch and will be ignored if it is enabled&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;是否为 nouveau 驱动启用 modesetting&lt;/p&gt;&lt;p&gt;不会影响 Intel GPU 的 modesetting&lt;/p&gt;&lt;p&gt;该选项与 bbswitch 不兼容，并且 bbswitch 模式启用时会自动忽略该选项&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="722"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;This will be set using the Xsetup script passed to your login manager&lt;br/&gt;It will run the command&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Leave 0 for the default&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;这将使用会传给您的登录管理器的 Xsetup 脚本&lt;br/&gt;它会运行如下命令：&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;填 0 则表示使用默认值&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="754"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable modesetting&lt;/p&gt;&lt;p&gt;Required for PRIME Synchronization&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;是否启用 modesetting&lt;/p&gt;&lt;p&gt;PRIME Synchronization 要求启用该选项&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="764"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable the NVreg_UsePageAttributeTable option in the Nvidia driver &lt;span style=&quot; font-style:italic;&quot;&gt;Recommended&lt;/span&gt;, can cause poor CPU performance otherwise&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;时是否在 Nvidia 驱动中启用 NVreg_UsePageAttributeTable 选项。&lt;span style=&quot; font-style:italic;&quot;&gt;建议开启&lt;/span&gt;，否则可能会造成 CPU 性能下降&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="774"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable CoolBits in the Xorg configuration and unlock clocking options in the Nvidia control panel&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;在 Xorg 配置中启用 CoolBits，并且解锁 Nvidia 设置中的 clocking 选项&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="777"/>
        <source>Overclocking options</source>
        <translation>超频选项</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="784"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable triple buffering&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;启用三倍缓存&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="787"/>
        <source>Triple buffer</source>
        <translation>三倍缓存</translation>
    </message>
    <message>
        <source>Tripple buffer</source>
        <translation type="vanished">三倍缓存</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="844"/>
        <location filename="../../src/settingsdialog.ui" line="975"/>
        <source>Version:</source>
        <translation>版本：</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="858"/>
        <location filename="../../src/settingsdialog.ui" line="952"/>
        <source>Autor:</source>
        <translation>作者：</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="865"/>
        <location filename="../../src/settingsdialog.ui" line="989"/>
        <source>License:</source>
        <translation>许可证：</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="223"/>
        <source>Select icon</source>
        <translation>选择图标</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="224"/>
        <source>Images (*.png *.jpg *.bmp);;All files(*)</source>
        <translation></translation>
    </message>
</context>
</TS>
