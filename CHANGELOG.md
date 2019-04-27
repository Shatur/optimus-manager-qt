# Changelog

All notable changes to this project will be documented in this file. This project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [Unreleased](https://github.com/Shatur95/optimus-manager-qt/tree/HEAD)

[Full Changelog](https://github.com/Shatur95/optimus-manager-qt/compare/1.1.3...HEAD)

**Changed**

-   Use table layout in the settings.

## [1.1.3](https://github.com/Shatur95/optimus-manager-qt/tree/HEAD)) (2019-04-21)

[Full Changelog](https://github.com/Shatur95/optimus-manager-qt/compare/1.1.2...1.1.3)

**Added**

-   Spanish translation.

**Changed**

-   Remove "The application is already running" message.
-   Use Chinese flag from [FlagKit](https://github.com/madebybowtie/FlagKit).

## [1.1.2](https://github.com/Shatur95/optimus-manager-qt/tree/HEAD)) (2019-04-20)

[Full Changelog](https://github.com/Shatur95/optimus-manager-qt/compare/1.1.1...1.1.2)

**Changed**

-   Fix switching when bbswitch is unavailable.
-   Fix confirm message showing when it's disabled.
-   Fix the closing of the application after exiting the settings.

## [1.1.1](https://github.com/Shatur95/optimus-manager-qt/tree/HEAD)) (2019-03-28)

[Full Changelog](https://github.com/Shatur95/optimus-manager-qt/compare/1.1.0...1.1.1)

**Added**

-   Chinese translation.

**Changed**

-   Specify maximum dpi for Nvidia QSpinBox.
-   Fix typos and improve text for translation.

## [1.1.0](https://github.com/crow-translate/crow-translate/tree/1.1.0) (2019-03-26)

[Full Changelog](https://github.com/crow-translate/crow-translate/compare/1.0.0...1.1.0)

**Added**

-   The ability to set startup mode in settings.
-   Implement 'terminate_sessions', 'kill_x11' and 'kill_logind' options.

**Changed**

-   Show application name in messages.
-   Display an error icon if the mode icon is not found.
-   Fix applying the tray icon after changing settings.
-   Use optimus-manager daemon directly to switch GPU.
-   Remove checking bbswitch module in settings.
-   Show preview of icons for system tray on selection buttons.
-   Plasma: Use KIconDialog.
-   Show notification after switching if login manager control is disabled.
-   Use a more common icon for Nvidia in the settings.
-   Bundle default tray and app icons.
-   Use the bundled icons if the specified icons in the settings are invalid.
-   Enable TearFree and AccelMethod options only with the Intel driver.

## 1.0.0 (2019-02-28)

_Initial release_
