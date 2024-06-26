# Netatalk for macOS

![Build Status](https://github.com/dgsga/netatalk/actions/workflows/macos.yml/badge.svg)
[![License: GPL v2](https://img.shields.io/badge/License-GPL%20v2-blue.svg)](https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)

This is a fork of the main branch of the Netatalk repo on GitHub. It has been patched for clean compilation and use on recent versions of macOS only, and enables AFP 2.2 and AFP 3.0 - 3.4 file sharing between modern macs and vintage macs running classic Mac OS. It has been tested on macOS 10.14 (Mojave) to macOS 14.4.1 (Sonoma). All code unused in macOS has been removed so this version of Netatalk will only run on modern Intel or Apple Silicon macs. This fork is regularly updated by cherry-picks from the upstream master.
#### Credits:

[The Netatalk open-source AFP filesever project](https://github.com/Netatalk/netatalk) -
all developers past and present.

**@mabam**, **@rdmark**, **@Synology-andychen**, **@mikeboss** and **@christopherkobayashi** for various recent patches

#### Quick how-to:

1. Install Homebrew:

    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

2. Install Netatalk's dependencies from Homebrew:

    brew install berkeley-db dgsga/netatalk-dbus/dbus-glib docbook-xsl libevent libgcrypt meson mysql pkg-config wolfssl

3. Clone the repo:

    git clone https://github.com/dgsga/netatalk.git

4. cd to the repo then run the following commands:

   meson setup build

   sudo ninja -C build install

5. Set up your afp.conf file and specify AFP shares as needed.

Notes: For afpstats to work *afpstats = yes* must be in the global section of afp.conf, and the Perl module *Net::DBus* must be installed by running the following command:

sudo cpan Net::DBus

The icon folder contains a Mac OS 9 colour icon for the AFP share. The extension folder contains a System Folder extension for enabling Bonjour in Mac OS 9.
