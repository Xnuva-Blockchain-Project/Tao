TaoCoin — Original 2017 Legacy Chain
====================================

Official maintained project website: https://europazeus.org

This repository maintains the original TaoCoin legacy blockchain released in 2017.

**Important:** this project is not affiliated with, derived from, or intended to represent any later or unrelated project using the name or ticker “TAO”. All maintenance work in this repository applies only to the preserved 2017 TaoCoin chain identified below.

Project status
--------------

TaoCoin is being preserved and modernised for current operating systems while keeping the historical blockchain intact.

Maintenance rules:

- no re-genesis
- no chain reset
- no historical block rewrite
- no balance migration or token swap
- no change to consensus behaviour unless a separately proven defect requires one
- old wallets and private keys must remain usable with the maintained chain
- compatibility changes are qualified against the preserved 2017 source and historical crypto behaviour

Verified chain identity
-----------------------

The preserved source establishes the following TaoCoin mainnet identity:

- Genesis hash: `41de2a4b7018115eae4a3e7e82189b551aaf871af66929fa28a49ee852abb67e`
- Genesis time: 2017-12-21 10:45:04 UTC
- Genesis bits: `1e0ffff0`
- Genesis nonce: `1349876`
- Proof of work: scrypt `1024_1_1_256`
- Target block spacing: 5 minutes
- Difficulty target timespan: 10 minutes
- Retarget interval: 2 blocks
- Initial block subsidy: 50 TAO
- Subsidy halving interval: 210,000 blocks
- Maximum money: 21,000,000 TAO
- Mainnet P2P port: `30137`
- Mainnet message magic: `06 ca cb bb`
- Public-key address prefix: `65`
- Private-key prefix: `193`

The old README text describing 2.5-minute blocks, 840,000-block halvings and approximately 84 million coins was stale legacy documentation and does not match the preserved TaoCoin source.

Preservation
------------

The original source is retained unchanged for historical and compatibility reference:

- branch: `preserved-2017-baseline`
- tag: `preserved-original-2017`
- canonical preservation commit: `4bb48ef74d3581ed3ee9a6c7300b83010e972d4c`

The preserved branch and tag are not used for maintenance edits.

Modernisation
-------------

Current work is focused on reproducible build and dependency modernisation while preserving chain and wallet compatibility.

The maintenance process is intentionally staged:

1. dependency and build compatibility
2. OpenSSL / cryptographic API compatibility with old/new behavioural equivalence testing
3. wallet and blockchain runtime qualification
4. GUI, splash-screen and project-identity refresh
5. maintained release packaging and documentation

The maintained GUI/release work will use the 2026 project identity and https://europazeus.org. Historical third-party or obsolete project links are not authoritative for the maintained project.

Build status
------------

The preserved 2017 source is a historical baseline and is not claimed to build unmodified on current systems.

Modern build instructions will be published only after the current compatibility branch has passed the project build, crypto, wallet and chain-compatibility matrices.

License
-------

TaoCoin is released under the terms of the MIT license. See `COPYING` for the repository license text.

Original third-party copyright and license notices remain in the preserved source where legally required.
