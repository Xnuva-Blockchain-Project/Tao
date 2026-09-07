# TaoCoin Revival — Current Maintained Network

**This is the current TAO network and the branch normal users should build and run.**

Official project website: https://europazeus.org

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

See the platform build documentation under `doc/`.

The daemon target is `taocoind`; the GUI target is TaoCoin-Qt.

## License

TaoCoin is released under the MIT license. See `COPYING`.
