# TAO Bitcoin Core 31.1 modernisation status

**Branch:** `modernisation/bitcoin-core-31.1-experimental-do-not-release`  
**Authoritative TAO source:** `tao-revival` @ `74216f33f634f5dde37e96805c72c63c181c52df`  
**Consensus:** Proof of Work only  
**Release status:** **UNTESTED / DO NOT RELEASE**

## Completed

- Explicitly rejected the older TAO legacy tree as authority for this port.
- Audited the Revival source for chain identity, Scrypt PoW, difficulty, subsidy, ports, addresses and historical validation rules.
- Confirmed no PoS/staking consensus path is present.
- Pinned Bitcoin Core v31.1 at `9be056a8a72b624dae9623b2f7bded92c2a21c91`.
- Added the full pinned v31.1 tree as `modern-core`.
- Recorded the Revival consensus-preservation manifest.
- Kept live/default and authoritative Revival code out of the experimental overlay.
- Snapshotted Revival consensus/network/wallet source under `migration/legacy-consensus-snapshot/`.
- Began the actual Bitcoin Core 31.1 overlay under `migration/modern-tao-draft/`.
- Drafted modern block primitives preserving standard block IDs plus Scrypt PoW.
- Ported the Revival 300s/600s two-block retarget algorithm.
- Preserved 50 TAO subsidy, 210,000-block halvings, 21m money range and 20-block coinbase maturity.
- Preserved the Revival 1 MB serialized-block limit.
- Drafted original mainnet genesis, message magic, 31137 P2P, 31138 RPC and Base58 identities.
- Disabled CSV, SegWit, Taproot, BIP65 and BIP66 in the TAO mainnet mapping.
- Replaced Bitcoin 31.1's default P2SH+Witness+Taproot script flags with Revival P2SH-only validation.
- Preserved height-710,000 version/coinbase-height behavior and the height-1 Revival checkpoint.
- Kept modern wallet destination output Base58-only during the migration.
- Added CMake wiring and a deterministic source-tree materialiser.

## Mechanical port sequence

1. Freeze the Revival consensus-critical source.
2. Preserve normal SHA256 block IDs plus Scrypt PoW.
3. Preserve the two-block TAO retarget algorithm.
4. Preserve 50 TAO subsidy / 210,000-block halvings / 21m money range / maturity 20.
5. Preserve old BIP16/BIP30/version/coinbase-height rules.
6. Keep CSV, SegWit and Taproot inactive.
7. Preserve TAO Base58 key/address formats.
8. Port modern Chainstate/network/RPC/wallet/mining infrastructure around those rules.
9. Build.
10. Reindex the existing live TAO chain from Revival genesis to current tip.
11. Release only after historical compatibility is proven.

## Known unresolved item

Revival's testnet genesis/checkpoint is a blank placeholder. Do not synthesize a new testnet during the mechanical migration.
