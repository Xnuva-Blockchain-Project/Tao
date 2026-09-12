# TAO Revival chain-identity security contract

This document is part of the Bitcoin Core 31.1 modernisation branch and is a **release gate**.

## Purpose

Prevent a repeat of the Europa failure class: a node loses, resets, replaces, or starts with the wrong blockchain state and then mines a valid-looking alternative history from the same genesis.

TAO Revival is Proof of Work only. The modern TAO block-production path must therefore refuse **all mainnet block-template creation and mining** unless the active chain is proven to be the canonical Revival chain.

## Known immutable identity

- Authoritative chain: TAO Revival
- Genesis: `41de2a4b7018115eae4a3e7e82189b551aaf871af66929fa28a49ee852abb67e`
- Canonical block 1: `717fc5ef97ded9f7d514fcb1ed558bc76596ce85f09890efa6e668d228c4a57f`

The height-1 fingerprint is useful but is **not** sufficient as the permanent production anchor. A well-buried live-chain anchor must be qualified independently before release.

## Mandatory mainnet production guard

Before the modern code can create a mainnet block template or begin PoW work, the central block-production path must fail closed unless all of the following are true:

1. the security policy is explicitly configured for production;
2. the active chain has reached the configured buried anchor height;
3. the active-chain block at that height exactly matches the configured canonical hash;
4. the active tip chainwork is at least the configured canonical minimum;
5. the node is not in initial block download / synchronisation state;
6. at least one peer connection is present;
7. the block-1 fingerprint remains the canonical Revival block 1.

The guard belongs in the **central block-building path**, not only in a launcher or one RPC entry point, so every mining surface inherits it.

## Fail-closed configuration rule

`migration/modern-tao-draft/src/chain_identity_security.h` deliberately leaves the buried anchor and minimum-chainwork values unset and `production_block_creation_enabled = false`.

Those values must not be guessed. They are to be populated only after the live Revival chain is interrogated and the chosen anchor is independently verified.

Until then, the modernised branch remains **DO NOT RELEASE / DO NOT MINE MAINNET**.

## Qualification required before release

Negative test: present a disposable wrong/truncated/alternate TAO chain and prove that block production is refused and the tip does not change.

Positive test: present a disposable copy of the genuine TAO chain, prove the anchor and minimum work, and create a valid next-block template without doing PoW or submitting a block.

Only after both paths pass may `production_block_creation_enabled` be set true and the modernised TAO code be considered for release.
