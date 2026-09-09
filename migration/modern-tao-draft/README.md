# Modern TAO Revival draft source

**UNTESTED — DO NOT RELEASE — DO NOT CONNECT TO LIVE TAO**

This directory is the Bitcoin Core 31.1 mechanical migration overlay for the
**existing TAO Revival blockchain**.

Authoritative TAO source:

- branch: `tao-revival`
- commit: `74216f33f634f5dde37e96805c72c63c181c52df`

The older TAO legacy source is not authoritative for this migration.

Pinned modern baseline:

- Bitcoin Core v31.1
- commit: `9be056a8a72b624dae9623b2f7bded92c2a21c91`

## Drafted

- full Bitcoin Core 31.1 source available through `modern-core`;
- authoritative Revival source snapshot;
- standard double-SHA256 TAO block identifiers;
- Scrypt `1024_1_1_256` Proof-of-Work;
- Revival two-block / 5-minute / 10-minute retarget algorithm;
- 50 TAO subsidy with 210,000-block halvings;
- `MAX_MONEY = 21,000,000 TAO`;
- 20-block coinbase maturity;
- Revival 1 MB serialized-block ceiling;
- original TAO mainnet genesis, magic, P2P/RPC ports and Base58 prefixes;
- no PoS/staking machinery;
- BIP30 preservation;
- P2SH-only script verification;
- CSV, SegWit, Taproot, BIP65 and BIP66 disabled;
- version-1 block rejection from height 710,000;
- serialized coinbase-height enforcement from height 710,000 via BIP34-height mapping;
- Revival height-1 checkpoint;
- Base58-only wallet address encoding;
- modern Core validation changed to check Scrypt PoW instead of block ID;
- CMake wiring for TAO Scrypt and subsidy modules.

## Deliberately unresolved

- Revival testnet: the authoritative source contains a blank genesis/checkpoint placeholder;
- regtest definition;
- modern seed conversion / live peer discovery;
- final miner/RPC integration;
- modern descriptor/SQLite wallet migration;
- TAO branding/executable names;
- compile fixes exposed by the first build;
- exact restoration of the old optional `-checkpoints=0` behavior.

## Historical-chain gate

After the source migration is complete, the release candidate must:

1. reproduce the original TAO genesis block;
2. reproduce the original block IDs and Scrypt PoW hashes;
3. validate the height-1 checkpoint;
4. reproduce every historical difficulty transition;
5. enforce 50 TAO / 210,000-block halvings and maturity 20;
6. preserve old P2SH/BIP30/version rules;
7. accept existing TAO Base58 keys and addresses;
8. reindex from genesis to the existing live Revival-chain tip;
9. produce the same UTXO/balance state as the authoritative Revival client.

Failure of any item means the port is not TAO and must not be released.
