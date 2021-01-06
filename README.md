# Optimus Manager Qt

[![GitHub (pre-)release](https://img.shields.io/github/release/Shatur95/optimus-manager-qt/all.svg)](https://github.com/Shatur95/optimus-manager-qt/releases)
[![Codacy grade](https://img.shields.io/codacy/grade/5cd6782b094743eaa6fe35bc20650914.svg)](https://app.codacy.com/project/Shatur95/optimus-manager-qt/dashboard)

**Optimus Manager Qt** is an interface for **Optimus Manager** that allows to configure and switch GPUs on Optimus laptops using the tray menu.

**Note:** Please send all non-interface related issues to [Optimus Manager](https://github.com/Askannz/optimus-manager) repository.

## Content

-   [Screenshots](#screenshots)
-   [Features](#features)
-   [Third-party](#third-party)
-   [Installation](#installation)
-   [Localization](#localization)

## Screenshots

<p align="center">
  <img src="https://raw.githubusercontent.com/Shatur95/optimus-manager-qt/master/screenshots/tray.png" alt="Tray screenshot"/>
  <img src="https://raw.githubusercontent.com/Shatur95/optimus-manager-qt/master/screenshots/tray-menu.png" alt="Tray menu screenshot"/>
</p>
<p align="center">
  <img src="https://raw.githubusercontent.com/Shatur95/optimus-manager-qt/master/screenshots/settings-general.png" width="392px" height="300px" alt="General settings screenshot"/>
  <img src="https://raw.githubusercontent.com/Shatur95/optimus-manager-qt/master/screenshots/settings-optimus.png" width="392px" height="300px" alt="Optimus settings screenshot"/>
</p>

## Features

-   Display the current video card in the system tray
-   Graphic menu for Optimus Manager configuration
-   Switching video cards using the context menu
-   Customizable tray icon
-   Optional extended Plasma support (you can compile it with or without Plasma dependencies, see below)

## Third-party

### Libraries

This project uses [SingleApplication](https://github.com/itay-grudev/SingleApplication).

Therefore, if you want to clone this project, you need to use the `--recursive` option:

```bash
git clone --recursive git@github.com:Shatur95/optimus-manager-qt.git
```

or you can initialize these modules later:

```bash
git clone git@github.com:Shatur95/optimus-manager-qt.git
git submodule init
git submodule update
```

### Icons

[FlagKit](https://github.com/madebybowtie/FlagKit "Beautiful flag icons for usage in apps and on the web") icons are used for languages flags.

Nvidia icon from the [Masalla icon theme](https://github.com/masalla-art/masalla-icon-theme "Icon theme for UNIX-like OS") is used for the application icon.

## Installation

### Arch Linux and derivatives

You can install [optimus-manager-qt](https://aur.archlinux.org/packages/optimus-manager-qt) or [optimus-manager-qt-git](https://aur.archlinux.org/packages/optimus-manager-qt-git) from AUR.

**Note:** If you are using Plasma, it is recommended to replace in the PKGBUILD `_plasma=false` with `_plasma=true` to use additional KDE API feautures (this also adds additional dependencies).

### Manual building

You can build **Optimus Manager Qt** by using the following commands:

```bash
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=Release ..
cmake --build .
```

If you want to build with extended Plasma support you need to define `WITH_PLASMA` (the same as `_plasma=true` in the PKGBUILD):

```bash
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=Release -D WITH_PLASMA ..
cmake --build .
```

You will then get a binary named `optimus-manager-qt`.

## Localization

To help with localization you can use [Crowdin](https://crowdin.com/project/optimus-manager-qt) or translate files in `data/translations` with [Qt Linguist](https://doc.qt.io/Qt-5/linguist-translators.html) directly. To add a new language, write me on the Crowdin project page or copy `data/translations/optimus-manager.ts` to `data/translations/optimus-manager_<ISO 639-1 language code>_<ISO 3166-1 alpha-2 language code>.ts`, translate it and send a pull request.
