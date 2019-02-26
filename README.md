# Optimus Manager Qt

**Optimus Manager Qt** is an interface for **Optimus Manager** that allows to configure and switch GPUs on Optimus laptops using the tray menu.

**Note:** Please send all non-interface related issues to [Optimus Manager](https://github.com/Askannz/optimus-manager) repository.

## Content

-   [Screenshots](#screenshots)
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

## Third-party

### Libraries

This project uses [SingleApplication](https://github.com/itay-grudev/SingleApplication) - a simple single instance application for Qt.

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

You can install [optimus-manager-qt-git](https://aur.archlinux.org/packages/optimus-manager-qt-git) from AUR.

### Manual building

You can build **Optimus Manager Qt** by using the following commands:

```bash
qmake
make
make clean
```

You will then get a binary named `optimus-manager`.
