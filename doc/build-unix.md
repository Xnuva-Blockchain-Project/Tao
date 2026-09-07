# TaoCoin Revival — Unix/Linux Build Guide

This guide applies to the **current TaoCoin Revival network**.

For normal use, clone the repository default branch (`main`). The legacy preservation branches are not the current network.

## Network identity

- Mainnet P2P: `31137`
- Mainnet RPC: `31138`
- Unix datadir: `~/.taocoin-revival`
- Mainnet message magic: `b3 3d dc 92`

## Headless node build

The headless server/node executable is `taocoind`.

### Ubuntu 22.04 / Debian-family prerequisites

TaoCoin Revival uses several system libraries that are **not copied into this repository**. Install the development packages before compiling:

```bash
sudo apt update
sudo apt install -y \
  build-essential \
  libboost-all-dev \
  libssl-dev \
  libdb++-dev \
  zlib1g-dev
```

What these provide:

| Package | Required for |
| --- | --- |
| `build-essential` | GCC/G++, make and standard build tools |
| `libboost-all-dev` | Boost system, filesystem, program-options, thread and chrono libraries |
| `libssl-dev` | OpenSSL cryptographic headers and libraries |
| `libdb++-dev` | Berkeley DB C++ header `db_cxx.h` and library |
| `zlib1g-dev` | zlib compression library |

The repository contains its own LevelDB source and builds it automatically.

UPnP support is disabled in the default `makefile.unix` configuration, so `libminiupnpc-dev` is not required for the standard headless build.

### Build

From the repository root:

```bash
cd src
make -f makefile.unix -j"$(nproc)"
```

A successful build produces:

```text
src/taocoind
```

Verify it exists:

```bash
ls -lh taocoind
```

### Install the daemon

For a system-wide manual installation:

```bash
sudo install -m 0755 taocoind /usr/local/bin/taocoind
```

Or copy it to the location used by your own service layout.

## OpenSSL 3 warnings

On modern Linux distributions such as Ubuntu 22.04, the compiler may print warnings similar to:

```text
SHA256_Update ... is deprecated: Since OpenSSL 3.0
SHA256_Final ... is deprecated: Since OpenSSL 3.0
```

These are **compiler warnings**, not build failures. A real build failure will be reported with `error:`, `fatal error:`, or a non-zero `make` exit status.

The Revival source retains compatibility code while OpenSSL modernization is qualified separately.

## Berkeley DB note

TaoCoin source includes:

```cpp
#include <db_cxx.h>
```

The file `db_cxx.h` belongs to Berkeley DB and therefore is supplied by the operating system development package rather than copied into this repository.

On Ubuntu/Debian:

```bash
sudo apt install libdb++-dev
```

After installation, the header is normally available at:

```text
/usr/include/db_cxx.h
```

Bundling only that header in TaoCoin would be incorrect because it must match the Berkeley DB C++ library against which the daemon links.

## Optional UPnP

The default headless build disables UPnP:

```make
USE_UPNP:=-
```

If a developer intentionally enables UPnP, install the matching miniupnpc development package and build with the appropriate `USE_UPNP` setting.

## GUI build

The T620/server-style installation does not require the Qt GUI.

For desktop TaoCoin-Qt development, see `readme-qt.rst` and the platform-specific Qt documentation under `doc/`.

## Troubleshooting

### `db_cxx.h: No such file or directory`

Install:

```bash
sudo apt install libdb++-dev
```

### `opening dependency file obj/...: No such file or directory`

Current TaoCoin Revival `makefile.unix` creates its required object directories automatically. If this occurs, make sure the clone is current:

```bash
git pull --ff-only
```

### Confirm you are building Revival

From the repository root:

```bash
git branch --show-current
grep -n '31137' src/init.cpp | head
grep -n '0xb3, 0x3d, 0xdc, 0x92' src/main.cpp
```

A normal clone should be on `main` and show the Revival port and message magic above.

## License

TaoCoin is released under the MIT license. See `COPYING`.

Historical third-party copyright and license notices remain applicable where required.
