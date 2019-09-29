<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="pt_BR">
<context>
    <name>AppSettings</name>
    <message>
        <location filename="../../src/appsettings.cpp" line="75"/>
        <source>Unable to create autorun file from &apos;%1&apos;</source>
        <translation>Não foi possível criar o arquivo autorun a partir de &apos;%1&apos;</translation>
    </message>
</context>
<context>
    <name>DaemonClient</name>
    <message>
        <location filename="../../src/daemonclient.cpp" line="109"/>
        <source>Unable to open startup mode file</source>
        <translation>Não foi possível abrir o arquivo do modo de inicialização</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="361"/>
        <location filename="../../src/settingsdialog.cpp" line="117"/>
        <source>Unable to connect to Optimus Manager daemon: %1</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="371"/>
        <source>Unable to send GPU name to switch to Optimus Manager daemon: %1</source>
        <translation type="unfinished">Não foi possível enviar o nome da GPU para troca para o daemon do Optimus Manager: %1</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="127"/>
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
        <translation>Trocar para Intel</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="183"/>
        <source>Switch to Nvidia</source>
        <translation>Trocar para Nvidia</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="60"/>
        <location filename="../../src/optimusmanager.cpp" line="184"/>
        <source>Exit</source>
        <translation>Sair</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="55"/>
        <location filename="../../src/optimusmanager.cpp" line="56"/>
        <location filename="../../src/optimusmanager.cpp" line="57"/>
        <source>Switch to %1</source>
        <translation>Trocar para %1</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="160"/>
        <location filename="../../src/optimusmanager.cpp" line="170"/>
        <source>The specified icon &apos;%1&apos; for the current GPU is invalid. The default icon will be used.</source>
        <translation>O ícone especificado &apos;%1&apos; da GPU atual é inválido. O ícone padrão será usado.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="197"/>
        <source>You are about to switch GPU.</source>
        <translation>Você está prestes a trocar de GPU.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="199"/>
        <source>You will be automatically logged out to apply the changes.</source>
        <translation>Você será automaticamente desconectado para aplicar as alterações.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="210"/>
        <source>No power management option is currently enabled</source>
        <translation>Atualmente, nenhum gerenciador de energia está habilitado</translation>
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
        <translation>O serviço do Optimus Manager não está em execução.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="270"/>
        <source>There are %1 other desktop sessions open. The GPU switch will not become effective until you have manually logged out from ALL desktop sessions.
Continue?</source>
        <translation>Existem %1 outras sessões da área de trabalho abertas. A GPU não será trocada até que você tenha se desconectado manualmente de TODAS as sessões da área de trabalho.
Continuar?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="284"/>
        <source>Wayland session found.</source>
        <translation>Sessão Wayland encontrada.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="285"/>
        <source>Session %1, started by %2, is a Wayland session. Wayland is not supported by Optimus Manager, so GPU switching may fail.
Continue anyway?</source>
        <translation>A sessão %1, iniciada por %2, é uma sessão do Wayland. O Wayland não é suportado pelo Optimus Manager, logo, a troca de GPU pode falhar.
Continuar mesmo assim?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="302"/>
        <source>The Bumblebee service (%1) is running.</source>
        <translation>O serviço do Bumblebee (%1) está em execução.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="345"/>
        <source>The Xorg driver &apos;%1&apos; is not installed.</source>
        <translation>O driver Xorg &apos;%1&apos; não está instalado.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="346"/>
        <source>Optimus Manager will use &apos;%1&apos; driver instead. You can change driver in settings or install the &apos;%2&apos; driver from the package &apos;%3&apos;.
Continue anyway?</source>
        <translation>O Optimus Manager irá usar o driver &apos;%1&apos;. Você pode alterar o driver nas configurações ou instalar o driver &apos;%2&apos; do pacote &apos;%3&apos;.
Continuar mesmo assim?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="317"/>
        <source>If you did not create it yourself, it was likely generated by your distribution or by an Nvidia utility.
This file may contain hard-coded GPU configuration that could interfere with Optimus Manager, so it is recommended that you delete it before proceeding.
Ignore this warning and proceed with GPU switching?</source>
        <translation>Se não foi criado por você, provavelmente foi gerado pela sua distribuição ou por algum utilitário da Nvidia.
Este arquivo pode conter configurações da GPU que podem interferir com o Optimus Manager, portanto é recomendável que você o exclua antes de continuar.
Ignorar este aviso e continuar com a troca da GPU?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="331"/>
        <source>This file was auto-generated by the Manjaro driver utility (MHWD). This will likely interfere with GPU switching, so Optimus Manager will delete this file automatically if you proceded with GPU switching.
Proceed?</source>
        <translation>Este arquivo foi gerado automaticamente pelo utilitário de driver do Manjaro (MHWD). Isto provavelmente irá interferir com a troca da GPU, portanto o Optimus Manager irá excluir este arquivo se você continuar com a troca da GPU.
Prosseguir?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="201"/>
        <source>After applying the settings, you will need to manually re-login to change the video card.</source>
        <translation>Depois de aplicar as configurações, você precisará fazer login novamente manualmente para alterar a placa de vídeo.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="68"/>
        <location filename="../../src/optimusmanager.cpp" line="179"/>
        <source>Current videocard: %1</source>
        <translation>Placa de vídeo atual: %1</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="222"/>
        <source>Please enable and start it with:
&apos;%1&apos;
&apos;%2&apos;</source>
        <translation>Por favor, habilite e inicie com:
&apos;%1&apos;
&apos;%2&apos;</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="232"/>
        <location filename="../../src/optimusmanager.cpp" line="244"/>
        <source>The %1 module does not seem to be available for the current kernel.</source>
        <translation>O módulo %1 parece não estar disponível para o kernel atual.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="233"/>
        <source>Power switching will not work.
You can set &apos;%1&apos; for GPU switching in settings or install bbswitch forthe default kernel with &apos;%2&apos; or for all kernels with &apos;%3&apos;.</source>
        <translation>A troca por desligamento de energia não funcionará. Você pode definir &apos;%1&apos; para troca de GPU nas configurações ou instalar o bbswitch para o kernel padrão com &apos;%2&apos; ou para todos os kernels com &apos;%3&apos;.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="245"/>
        <source>It is likely the Nvidia driver was not properly installed. GPU switching will probably fail, continue anyway?</source>
        <translation>É provável que o driver da Nvidia não tenha sido instalado corretamente. a troca da GPU provavelmente falhará, continuar mesmo assim?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="255"/>
        <source>Looks like you&apos;re using a non-patched version of the Gnome Display Manager (GDM).</source>
        <translation>Ao que parece, você está usando uma versão non-patched do Gnome Display Manager (GDM).</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="256"/>
        <source>GDM need to be patched for Prime switching. Follow &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;this&lt;/a&gt; instructions to install a patched version. Without a patched GDM version, GPU switching will likely fail.
Continue anyway?</source>
        <translation>O GDM precisa de um patch para uma troca Prime. Siga &lt;a href=&apos;https://github.com/Askannz/optimus-manager&apos;&gt;estas&lt;/a&gt; instruções para instalar uma versão corrigida. Sem uma versão GDM corrigida, a troca da GPU provavelmente falhará. Continuar mesmo assim?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="269"/>
        <source>Multiple running sessions detected.</source>
        <translation>Foram detectadas múltiplas sessões em execução.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="303"/>
        <source>This can interfere with Optimus Manager. Before attempting a GPU switch, it is recommended that you disable this service with &apos;%1&apos; and reboot your computer.
Ignore this warning and proceed with GPU switching now?</source>
        <translation>Isso pode interferir no Optimus Manager. Antes de tentar uma troca de GPU, é recomendável desabilitar este serviço com &apos;%1&apos; e reiniciar seu computador. Ignorar esse aviso e continuar com a troca de GPU agora?</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="316"/>
        <location filename="../../src/optimusmanager.cpp" line="330"/>
        <source>Found a Xorg config file at &apos;%1&apos;.</source>
        <translation>Foi encontrado um arquivo de configuração do Xorg em &apos;%1&apos;.</translation>
    </message>
    <message>
        <location filename="../../src/optimusmanager.cpp" line="378"/>
        <source>Configuration successfully applied. Your GPU will be switched after next login.</source>
        <translation>Configuração aplicada com sucesso. Sua GPU será trocada após o próximo login.</translation>
    </message>
</context>
<context>
    <name>SettingsDialog</name>
    <message>
        <location filename="../../src/settingsdialog.ui" line="14"/>
        <location filename="../../src/optimusmanager.cpp" line="51"/>
        <location filename="../../src/optimusmanager.cpp" line="181"/>
        <source>Settings</source>
        <translation>Configurações</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="59"/>
        <location filename="../../src/settingsdialog.ui" line="109"/>
        <source>General</source>
        <translation>Geral</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="95"/>
        <source>About</source>
        <translation>Sobre</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="205"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Application language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Idioma da aplicação&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="208"/>
        <source>Language:</source>
        <translation>Idioma:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="119"/>
        <source>&lt;System language&gt;</source>
        <translation>&lt;Idioma do sistema&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="231"/>
        <source>Launch at startup</source>
        <translation>Iniciar com o sistema</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="238"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Show confirmation dialog when switching GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Exibir caixa de diálogo de confirmação ao trocar de GPU&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="241"/>
        <source>Confirm switching</source>
        <translation>Confirmar troca</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="292"/>
        <source>Nvidia icon:</source>
        <translation>Ícone da Nvidia:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="278"/>
        <source>Intel icon:</source>
        <translation>Ícone da Intel:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="338"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Specify which GPU will be used by default when the system boots&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Especifica qual GPU será usada por padrão quando o sistema for inicializado&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="367"/>
        <source>ACPI call</source>
        <translation>ACPI call</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="432"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Module used for power switching&lt;/p&gt;&lt;p&gt;If you select &amp;quot;None&amp;quot;, no power switching will be done at all (the Nvidia GPU will stay powered at all times)&lt;/p&gt;&lt;p&gt;If you use bbswitch, you will not be able to use video outputs attached to your Nvidia GPU in Intel mode&lt;/p&gt;&lt;p&gt;To use the bbswitch mode, the bbswitch module must be installed for your current kernel&lt;/p&gt;&lt;p&gt;You can install it for the default kernel with &amp;quot;pacman -S bbswitch&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Módulo usado para a troca por desligamento&lt;/p&gt;&lt;p&gt;Se você selecionar &amp;quot;Nenhum&amp;quot;, nenhuma troca por desligamento será feita (a GPU Nvidia permanecerá ligada o tempo todo)&lt;/p&gt;&lt;p&gt;Se você usar bbswitch, você não poderá usar as saídas de vídeo conectadas à sua GPU Nvidia no modo Intel&lt;/p&gt;&lt;p&gt;Para usar o modo bbswitch, o módulo deve ser instalado para o seu kernel atual&lt;/p&gt;&lt;p&gt;Você pode instalar com &amp;quot;pacman -S bbswitch&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="445"/>
        <source>Automatic logout</source>
        <translation>Desconectar automaticamente</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="642"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable modesetting for the nouveau driver&lt;/p&gt;&lt;p&gt;Does not affect modesetting for the Intel GPU driver&lt;/p&gt;&lt;p&gt;This option is incompatible with Bbswitch and will be ignored if it is enabled&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Se deve ou não habilitar o modesetting para o driver nouveau&lt;/p&gt;&lt;p&gt;Não afeta o modesetting para o driver da GPU Intel&lt;/p&gt;&lt;p&gt;Esta opção é incompatível com o Bbswitch e será ignorada se estiver ativada&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="685"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;This will be set using the Xsetup script passed to your login manager&lt;br/&gt;It will run the command&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Leave 0 for the default&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Isso será definido usando o script Xsetup passado para o seu gerenciador de login&lt;br/&gt;Irá executar o comando&lt;/p&gt;&lt;p&gt;xrandr --dpi &amp;lt;dpi value&amp;gt;&lt;/p&gt;&lt;p&gt;Deixe 0 para o padrão&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="718"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Whether or not to enable the NVreg_UsePageAttributeTable option in the Nvidia driver &lt;span style=&quot; font-style:italic;&quot;&gt;Recommended&lt;/span&gt;, can cause poor CPU performance otherwise&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Se deve ou não habilitar a opção NVreg_UsePageAttributeTable no driver da Nvidia&lt;span style=&quot; font-style:italic;&quot;&gt;Recomendado&lt;/span&gt;, pode causar um desempenho ruim da CPU, caso contrário&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="728"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable CoolBits in the Xorg configuration, which unlocks clocking options&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Habilita o CoolBits na configuração do Xorg e desbloqueia as opções de clocking&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="731"/>
        <source>Overclocking options</source>
        <translation>Opções de overclock</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="228"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart will be used&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;~/.config/autostart será usado&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="251"/>
        <source>Tray icons</source>
        <translation>ìcones da bandeja</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="257"/>
        <location filename="../../src/settingsdialog.ui" line="264"/>
        <source>Choose icon</source>
        <translation>Escolha um ícone</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="341"/>
        <source>Startup mode:</source>
        <translation>Modo de inicialização:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="352"/>
        <source>None</source>
        <translation>Nenhum</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="115"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Interface language&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Idioma da interface&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="271"/>
        <location filename="../../src/settingsdialog.ui" line="285"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Path to the icon or icon name from theme&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Caminho do ícone ou o nome do ícone do tema&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="398"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU that will be used during normal system startup&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;GPU que será usada durante o inicialização normal do sistema&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="517"/>
        <source>Driver:</source>
        <translation>Driver:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="558"/>
        <source>Acceleration method:</source>
        <translation>Método de aceleração:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="579"/>
        <location filename="../../src/settingsdialog.ui" line="611"/>
        <source>Default</source>
        <translation>Padrão</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="584"/>
        <source>Yes</source>
        <translation>Sim</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="463"/>
        <location filename="../../src/settingsdialog.ui" line="589"/>
        <source>No</source>
        <translation>Não</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="452"/>
        <source>PCI reset:</source>
        <translation>Reinício da PCI:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="459"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Reset the Nvidia card at the PCI level before reloading the nvidia module&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;No&lt;/span&gt;: does not perform any reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Function level&lt;/span&gt;: perform a light &amp;quot;function-level&amp;quot; reset&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Hot reset&lt;/span&gt;: perform a &amp;quot;hot reset&amp;quot; of the PCI bridge (this method messes with the hardware directly and will perform a PCI remove even if it disabled, please read the online documentation of Optimus Manager before using it)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Reinicia a placa Nvidia, ao nível PCI, antes de recarregar o módulo da Nvidia&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Não&lt;/span&gt;: não faz nenhum tipo de reinício&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nível funcional&lt;/span&gt;: faz um leve reinício de &amp;quot;function-level&amp;quot;&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Reinício agressivo&lt;/span&gt;: faz um &amp;quot;hot reset&amp;quot; da PCI brigde (este método desordena diretamente com o hardware e executa uma remoção da PCI, mesmo se desativada, leia a documentação on-line do Optimus Manager antes de usar)</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="468"/>
        <source>Function level</source>
        <translation>Nível funcional</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="473"/>
        <source>Hot reset</source>
        <translation>Reinício agressivo</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="484"/>
        <source>PCI remove</source>
        <translation>Remoção da PCI</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="524"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;DRI version&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Versão do DRI&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="378"/>
        <source>PCI power control</source>
        <translation>Controle de energia da PCI</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="299"/>
        <source>Hybrid icon:</source>
        <translation>Ícone Híbrido:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="348"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Method to power switch the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;None&lt;/span&gt;: do not use an external module for power management (for some laptop models it&apos;s preferable to use this option in combination with PCI power control), you can use the scipts nvidia-enable.sh and nvidia-disable.sh to execute custom commands for power management that will be executed only with this method&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nouveau&lt;/span&gt;: load the nouveau module on the Nvidia card&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Bbswitch&lt;/span&gt;: power off the card using the bbswitch module (requires the &amp;quot;bbswitch&amp;quot;dependency)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;ACPI call&lt;/span&gt;: try various ACPI method calls to power the card on and off (requires the &amp;quot;acpi_call&amp;quot; dependency)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Método de troca de energia da placa Nvidia&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nenhum&lt;/span&gt;: não utiliza nenhum módulo para o gerenciamento de energia (para alguns modelos de notebooks é preferível que se use esta opção em combinação com o controle de energia da PCI), você pode usar scripts nvidia-enable.sh e nvidia-disable.sh para criar comandos personalizados para o gerenciador de energia que executará apenas neste método&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Nouveau&lt;/span&gt;: carrega o módulo nouveau na placa Nvidia&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;Bbswitch&lt;/span&gt;: desliga a placa usando o módulo bbswitch (requer o pacote &amp;quot;bbswitch&amp;quot; instalado)&lt;/p&gt;&lt;p&gt;&lt;span style=&quot; font-style:italic;&quot;&gt;ACPI call&lt;/span&gt;: tenta vários métodos de chamadas ACPI para ligar e desligar a placa (requer o pacote &amp;quot;acpi_call&amp;quot; instalado)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="375"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable PCI power management in Intel mode&lt;/p&gt;&lt;p&gt;This option is incompatible with ACPI call and Bbswitch switching methods, so it will be ignored in those cases&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Habilita o gerenciamento de energia da PCI no modo Intel&lt;/p&gt;&lt;p&gt;Esta opção é incompatível com os métodos de troca de ACPI call e Bbswitch, portanto será ignorada nestes casos&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="435"/>
        <source>Switching method:</source>
        <translation>Método da troca:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="442"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Automatically log out the current desktop session when switching GPUs&lt;/p&gt;&lt;p&gt;This feature is currently supported for Gnome, KDE Plasma, Deepin, Xfce, i3, Sway, Openbox, AwesomeWM and bspwm&lt;/p&gt;&lt;p&gt;If this options is disabled or you use a different desktop environment, GPU switching only becomes effective at the next graphical session login&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Desconecta-se automaticamente da atual sessão da área de trabalho quando trocar as GPUs&lt;/p&gt;&lt;p&gt;Atualmente, este recurso é compatível com: Gnome, KDE Plasma, Deepin, Xfce, i3, Sway, Openbox, AwesomeWM e bspwm&lt;/p&gt;&lt;p&gt;Se esta opção estiver desativada ou você usar um ambiente de área de trabalho diferente, a troca da GPU só se tornará eficaz no próximo login da sessão gráfica&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="481"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Remove the Nvidia card from the PCI bus&lt;/p&gt;&lt;p&gt;May prevent crashes caused by power switching&lt;/p&gt;&lt;p&gt;Ignored if switching method is Nouveau or Bbswitch&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Remove a placa Nvidia do PCI bus&lt;/p&gt;&lt;p&gt;Pode prevenir crashes causados pela troca de energia&lt;/p&gt;&lt;p&gt;Esta opção é ignorada caso o método de troca seja Nouveau ou Bbswitch&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="541"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Driver to use for the Intel GPU&lt;br/&gt;&lt;br/&gt;To use the Intel driver, you need to install the package &amp;quot;xf86-video-intel&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Driver para o uso da Intel GPU&lt;br/&gt;&lt;br/&gt;Para usar o driver Intel, você precisa instalar o pacote &amp;quot;xf86-video-intel&amp;quot;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="575"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable TearFree option in the Xorg configuration&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Habilita a opção TearFree na configuração do Xorg&lt;/p&gt;&lt;p&gt;Esta opção é compatível apenas com o driver Intel&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="607"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Acceleration method (corresponds to AccelMethod in the Xorg configuration)&lt;/p&gt;&lt;p&gt;Only applies to the Intel driver&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Método de aceleração (corresponde ao AccelMethod na configuração do Xorg)&lt;/p&gt;&lt;p&gt;Esta opção é compatível apenas com o driver Intel&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="708"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable modesetting&lt;/p&gt;&lt;p&gt;Required for PRIME Synchronization (which prevents tearing)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Habilita o modesetting&lt;/p&gt;&lt;p&gt;Requerido para o Sincronização PRIME (que previne tearing)&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="738"/>
        <source>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Enable triple buffering&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</source>
        <translation>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;Habilita o buffer triplo&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="741"/>
        <source>Triple buffer</source>
        <translation>Buffer triplo</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="798"/>
        <location filename="../../src/settingsdialog.ui" line="929"/>
        <source>Version:</source>
        <translation>Versão:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="812"/>
        <location filename="../../src/settingsdialog.ui" line="906"/>
        <source>Author:</source>
        <translation>Autor:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.ui" line="819"/>
        <location filename="../../src/settingsdialog.ui" line="943"/>
        <source>License:</source>
        <translation>Licença:</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="261"/>
        <source>Select icon</source>
        <translation>Selecionar um ícone</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="262"/>
        <source>Images (*.png *.jpg *.bmp);;All files(*)</source>
        <translation>Imagens (*.png *.jpg *.bmp);;Todos os arquivos(*)</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="281"/>
        <source>Unable to find Optimus Manager daemon.</source>
        <translation>Não foi possível encontrar o daemon do Optimus Manager.</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="282"/>
        <source>Please check the integrity of the package that provides Optimus Manager.</source>
        <translation>Por favor, verifique a integridade do pacote que fornece o Optimus Manager.</translation>
    </message>
    <message>
        <location filename="../../src/settingsdialog.cpp" line="284"/>
        <source>Not found!</source>
        <translation>Não encontrado!</translation>
    </message>
</context>
</TS>
