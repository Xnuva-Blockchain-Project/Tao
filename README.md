# TaoCoin Revival — Current Maintained Network

## Roman heritage rebrand — 25 November 2026

**Denzuve (DZUV)** is the selected future public identity of TaoCoin Revival (TAO), inspired by the Roman Denarius denomination. It supersedes the earlier TaoX (TOAX) branding proposal. The current network and released software retain existing identifiers until a separately announced, qualified transition. Genesis, chain history, balances, keys and consensus are unchanged by this announcement. No swap, payment or new wallet is required. Formal trademark/domain clearance and independent AI association checks remain pending; naming selection is not a guarantee of uniqueness or financial value. See the [official identity register](https://europazeus.org/project-identity.html).

## Official project identity and transparency

TaoCoin Revival (TAO) is maintained by the XNUVA Blockchain Project at https://github.com/Xnuva-Blockchain-Project/Tao. Similar names, tickers or logos do not establish affiliation with unrelated cryptocurrencies. Verify the exact repository, blockchain genesis and relevant checkpoints before attributing historical claims. Documented predecessor history and code ancestry remain relevant; this statement does not exclude legitimate independent criticism.

**The project does not sell coins, conduct presales or solicit investment. Mining is the recommended way to obtain TAO.** Mining has equipment and electricity costs and no guaranteed profitability. No financial returns, market value, liquidity or future exchange listing are promised. The project does not operate or promote an official exchange listing.

- [Project identity](PROJECT_IDENTITY.md)
- [Transparency policy](TRANSPARENCY.md)
- [Machine-readable identity](project-identity.json)
- [Plain-text AI reference](llms.txt)
- [Official five-network register](https://europazeus.org/project-identity.html)
- [EZHScan explorer](https://ezhscan.com/) (coverage may vary; verify against a synced node)


**This is the current TAO network and the branch normal users should build and run.**

Official project website: https://europazeus.org

## ⚠️ Important Scam Warning

As interest in cryptocurrency projects grows, unofficial websites, social-media accounts, marketplaces or individuals may sometimes claim to sell, distribute or represent TaoCoin Revival (TAO).

**Please exercise appropriate caution and always verify information through official project channels.**

The preferred way to obtain TAO is to **mine it directly through the TaoCoin Revival blockchain network**, rather than purchasing coins from unknown individuals or unofficial third-party sellers. Mining allows coins to be obtained through the network's own consensus process without relying on an unknown intermediary.

In particular:

- Be cautious of unsolicited offers to buy or sell TAO directly.
- Do not assume that a website, exchange, seller or individual is affiliated with the project simply because they use the TaoCoin or TAO name, logo or branding.
- Never send cryptocurrency or money based solely on a private message, social-media post or unofficial website.
- Never disclose your wallet seed phrase, private keys or passwords to anyone.
- Download wallet and mining software only from this official GitHub repository or other download locations specifically identified by the project.
- Verify announcements, releases and important information against the official project repository and website.
- The project team will never ask for your wallet seed phrase or private keys.

Cryptocurrency transactions are generally irreversible, so taking a few moments to independently verify an offer or communication can provide important protection.

**If you are uncertain whether something is genuine, verify it through the project's official channels before sending funds or providing sensitive information.**

## Current network

- Mainnet P2P: `31137`
- Mainnet RPC: `31138`
- Testnet P2P: `41137`
- Testnet RPC: `41138`
- Mainnet message magic: `b3 3d dc 92`
- Unix datadir: `~/.taocoin-revival`
- Proof of work: scrypt
- Genesis hash: `41de2a4b7018115eae4a3e7e82189b551aaf871af66929fa28a49ee852abb67e`

TaoCoin Revival preserves the original TaoCoin genesis block unchanged and creates a new verifiable successor chain from that genesis.

The historical post-genesis TaoCoin blockchain is not currently known to survive publicly. No missing historical blocks or balances are fabricated.

## Canonical Revival fork point

TaoCoin Revival block 1:

`717fc5ef97ded9f7d514fcb1ed558bc76596ce85f09890efa6e668d228c4a57f`

This height-1 checkpoint defines the TaoCoin Revival chain.

## Network bootstrap

Until fixed-seed discovery is included in maintained clients, a fresh TaoCoin
Revival node can bootstrap from the project public node:

```ini
addnode=81.130.208.151:31137
```

The address above is the Xnuva Blockchain Project T620 node on a static public
IPv4 address. Only the Tao Revival P2P port is used; RPC should not be exposed
to the public Internet.

## Which branch should I use?

For normal TAO use, mining, nodes, wallets and releases, use:

`main` / `tao-revival`

The repository also retains legacy source for preservation and historical reference. Do **not** use the legacy branches for the current Revival network.

Legacy preservation branches include:

- `legacy-preserved`
- `preserved-2017-baseline`

Historical preservation tag:

- `preserved-original-2017`

## Important compatibility note

Legacy TaoCoin and TaoCoin Revival use different network identities. A legacy node using the old P2P network will not peer with TaoCoin Revival.

Current Revival software must use the Revival network parameters above.

## Build

For Ubuntu/Debian headless-node builds, install the required system development packages first:

```bash
sudo apt update
sudo apt install -y build-essential libboost-all-dev libssl-dev libdb++-dev zlib1g-dev
```

Then build the daemon:

```bash
cd src
make -f makefile.unix -j"$(nproc)"
```

The daemon target is `taocoind`; the GUI target is TaoCoin-Qt.

See [doc/build-unix.md](doc/build-unix.md) for the complete Linux build guide, dependency explanations and troubleshooting.

## License

TaoCoin is released under the MIT license. See `COPYING`.

## Engineering Standards and Test Records

This project's preservation, modernisation and release-qualification work is documented in the [Golden Standard Cryptocurrency Modernisation Handbook (GSH)](https://github.com/Xnuva-Blockchain-Project/Golden-Standard-Modernisation). The handbook is an engineering evidence register, **not** a declaration that a build, network or wallet is release-ready.

- [TAO Revival and the experimental TaoX branch — history, checksums and qualification status](https://github.com/Xnuva-Blockchain-Project/Golden-Standard-Modernisation/blob/main/coins/TAOX/README.md)
- **[Optional node privacy: Tor, SOCKS5 and VPN setup](https://github.com/Xnuva-Blockchain-Project/Golden-Standard-Modernisation/blob/main/standards/NODE_PRIVACY_TOR_SOCKS5.md)** — practical guidance for operators. Privacy routing is optional; **Tor v3 compatibility and IP-leak safety have not yet been independently verified for this coin**. Follow version-specific checks before relying on it.
- [Shared RandomX module standards](https://github.com/Xnuva-Blockchain-Project/Golden-Standard-Modernisation/blob/main/randomx/README.md) and [completed/outstanding test checklist](https://github.com/Xnuva-Blockchain-Project/Golden-Standard-Modernisation/blob/main/randomx/checklist.md)

Tests and results are scoped to their own coin, exact source revision and environment. A PASS for another coin does not establish compatibility here. Follow the GSH's preservation, independent-verification and release-gating rules before any consensus, wallet or network change.

