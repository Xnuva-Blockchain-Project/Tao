# TAO Revival consensus preservation manifest

**Authoritative source branch:** `tao-revival`  
**Authoritative source commit:** `74216f33f634f5dde37e96805c72c63c181c52df`

The older TAO legacy source is **not** the authority for this migration.

## Consensus model

TAO Revival is **Proof of Work only**.

No PoS, coinstake, staking reward, stake modifier or PoS block signature machinery is part of the authoritative Revival source.

## Mainnet chain identity

- Genesis block ID: `41de2a4b7018115eae4a3e7e82189b551aaf871af66929fa28a49ee852abb67e`
- Genesis merkle root: `cb8d58accf6e38658164002f3258e6f9123206997d234537aa725898c1fb1c62`
- Genesis timestamp: `Betoota Advocate 21Dec2017 Bloke That Got Caught Up Talking Bitcoin`
- Genesis time: `1513853104`
- Genesis nonce: `1349876`
- Genesis bits: `0x1e0ffff0`
- Genesis version: `1`
- Genesis reward: `50 TAO`
- Message start: `b3 3d dc 92`
- P2P port: `31137`
- RPC port: `31138`
- Signed-message prefix: `TaoCoin Signed Message:\n`

Checkpointed Revival history begins with:
- height 0: `41de2a4b7018115eae4a3e7e82189b551aaf871af66929fa28a49ee852abb67e`
- height 1: `717fc5ef97ded9f7d514fcb1ed558bc76596ce85f09890efa6e668d228c4a57f`

## Hashing and Proof of Work

TAO uses two distinct hashes:

- block identifier: standard serialized double-SHA256 block-header hash;
- Proof-of-Work: Scrypt `1024_1_1_256` over the 80-byte block header.

The modern client must preserve this distinction exactly.

Mainnet PoW limit is the Revival value `~uint256(0) >> 20`, equivalent to a target beginning `00000fff...`.

## Difficulty

- target spacing: `300` seconds;
- target timespan: `600` seconds;
- difficulty interval: `2` blocks;
- adjustment bounded to 1/4x .. 4x actual timespan;
- the Revival first-retarget/full-period walk-back rule must be preserved;
- testnet has the old min-difficulty exception.

This is not Bitcoin Core 31.1's normal two-week difficulty schedule.

## Monetary rules

- `COIN = 100,000,000` atomic units;
- starting subsidy: `50 TAO`;
- subsidy halves every `210,000` blocks;
- Revival `MAX_MONEY = 21,000,000 TAO`;
- coinbase maturity: `20` blocks.

`MAX_MONEY` is a consensus money-range bound and must be preserved independently of theoretical emitted supply.

## Historical validation rules

Revival retains old pre-modern Bitcoin/Litecoin rules that must not be replaced silently:

- maximum serialized block size: 1,000,000 bytes;
- maximum block sigops: `MAX_BLOCK_SIZE / 50`;
- BIP30 overwrite protection enforced;
- P2SH/BIP16 becomes strict by timestamp `1349049600`;
- block timestamps may not exceed adjusted time by more than two hours;
- median-time-past ordering is enforced against the previous block;
- mainnet block version 1 is rejected from height `710,000`;
- from mainnet height `710,000`, version >=2 blocks must begin coinbase scriptSig with serialized block height;
- historical short-term pre-15-Aug-2013 BDB-lock protection remains part of source behavior even though TAO's 2017 genesis means normal mainnet blocks are later than that cutoff.

TAO Revival predates CSV, SegWit, Bech32, Taproot and modern script deployments. The mechanical migration must not activate any of them.

## Mainnet address identity

- P2PKH: `65`
- P2SH: `5`
- WIF/private key: `193` (65 + 128)

Revival has no native Bech32 address format.

## Testnet

Revival defines:
- message start `61 c4 9c 80`;
- P2P `41137`;
- RPC `41138`;
- P2PKH `111`;
- P2SH `196`;
- WIF `239`.

However the Revival source sets the testnet genesis hash/checkpoint to a blank `0x` placeholder. This migration will **not invent a replacement testnet genesis**. Testnet remains explicitly unresolved until separate evidence establishes the intended chain.

## Release invariant

The modern client is not TAO-compatible until it validates the existing Revival/mainnet chain from the original genesis through the live tip with identical block IDs, Scrypt PoW decisions, difficulty transitions, subsidy rules, coinbase maturity, historical script rules, checkpoints and UTXO results.
