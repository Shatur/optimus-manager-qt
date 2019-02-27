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
  <img src="https://raw.githubusercontent.com/Shatur95/optimus-manager-qt/master/dist/screenshots/tray.png" alt="Tray screenshot"/>
  <img src="https://raw.githubusercontent.com/Shatur95/optimus-manager-qt/master/dist/screenshots/tray-menu.png" alt="Tray menu screenshot"/>
</p>
<p align="center">
  <img src="https://raw.githubusercontent.com/Shatur95/optimus-manager-qt/master/dist/screenshots/settings-general.png" width="250px" height="184px" alt="General settings screenshot"/>
  <img src="https://raw.githubusercontent.com/Shatur95/optimus-manager-qt/master/dist/screenshots/settings-optimus.png" width="250px" height="184px" alt="Optimus settings screenshot"/>
</p>

## Features

-   Display the current video card in the system tray
-   Graphic menu for Optimus Manager configuration
-   Switching video cards using the context menu
-   Customizable tray icon
-   Optional extended KDE tray API support (you can compile it with or without knotifier, see below)

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

## Installation

### Arch Linux and derivatives

You can install [optimus-manager-qt](https://aur.archlinux.org/packages/optimus-manager-qt) or [optimus-manager-qt-git](https://aur.archlinux.org/packages/optimus-manager-qt-git) from AUR.

**Note:** If you are using KDE, it is recommended to replace it PKGBUILD `KDE=false` with `KDE=true` to use KDE API for tray for additional feautures (this also add knotifier dependency).

### Manual building

You can build **Optimus Manager Qt** by using the following commands:

```bash
qmake
make
make clean
```

If you want to build with KDE support you need to define `KDE`:

```bash
qmake "DEFINES += KDE"
make
make clean
```

You will then get a binary named `optimus-manager`.
