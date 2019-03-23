# Changelog

All notable changes to this project will be documented in this file. This project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [Unreleased](https://github.com/Shatur95/optimus-manager-qt/tree/HEAD)

[Full Changelog](https://github.com/Shatur95/optimus-manager-qt/compare/1.0.0...HEAD)

**Added**

-   Implemented 'terminate_sessions', 'kill_x11' and 'kill_logind' options.
-   The ability to set startup mode in settings.

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

## 1.0.0 (2018-11-17)

_Initial release_
