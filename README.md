# ⚠️ TaoCoin Legacy Preservation — NOT the Current Network

**Do not use this branch for normal TAO wallets, nodes or mining.**

The current maintained TAO network is **TaoCoin Revival**. Use the repository default branch (`main`) after the migration, or the `tao-revival` branch.

Current Revival network:

- Mainnet P2P: `31137`
- Mainnet RPC: `31138`
- Unix datadir: `~/.taocoin-revival`
- Mainnet message magic: `b3 3d dc 92`

This branch is retained only to preserve the legacy TaoCoin code and chain identity for historical and compatibility reference.

---

# TaoCoin — Original 2017 Legacy Chain

Official maintained project website: https://europazeus.org

This branch contains the original TaoCoin legacy blockchain code released in 2017.

## Legacy chain identity

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
- Legacy mainnet P2P port: `30137`
- Legacy mainnet message magic: `06 ca cb bb`
- Public-key address prefix: `65`
- Private-key prefix: `193`

## Preservation

The original source is also retained in:

- branch: `preserved-2017-baseline`
- tag: `preserved-original-2017`
- canonical preservation commit: `4bb48ef74d3581ed3ee9a6c7300b83010e972d4c`

No historical source is being discarded. This branch exists so the legacy implementation remains independently inspectable.

## License

TaoCoin is released under the MIT license. See `COPYING`.
