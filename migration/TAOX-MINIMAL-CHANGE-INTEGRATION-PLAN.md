# Denzuve (DZUV) — Minimal-Change RandomX Integration Plan

> Naming update: Denzuve (DZUV) is the selected future public identity of TAO Revival, inspired by the Roman denarius. Historical TaoX/TAOX/TOAX source paths, identifiers and evidence remain valid. Formal clearance and release qualification pending; no live activation.

Status: DRAFT — NO MAINNET ACTIVATION
Principle: Reliability first, release second.

## Objective

Modernise the existing TAO blockchain without
creating a new coin, resetting history, changing
balances or unnecessarily redesigning consensus.

RandomX is a forward-only, gated PoW transition.

## Preserve Without Modification

- Original genesis and historical chain identity.
- Historical SHA256d block identifiers.
- Historical Scrypt PoW requirements.
- Historical difficulty and monetary rules.
- Existing balances and wallet compatibility.
- Existing chainwork storage and fork-choice logic,
  unless security tests demonstrate a required change.
- Existing network architecture wherever compatible.

## Essential Integration Areas

1. Consensus algorithm selection:
   derive algorithm from authenticated ancestry
   and a future approved activation rule.

2. PoW hashing:
   preserve Scrypt for historical blocks;
   use the pinned modular RandomX engine only
   for blocks authorised by contextual consensus.

3. Validation paths:
   reconcile context-free header checks,
   contextual header acceptance, P2P processing,
   block storage, replay and reorganisation checks.

4. Mining:
   ensure new templates and submitted blocks
   use the correct authorised PoW algorithm.

5. Activation boundary:
   specify deterministic activation and any
   required initial-difficulty exception.

## Preserve Provisionally

- Five-minute target block spacing.
- Historical two-block adjustment interval.
- Existing nBits target decoding.
- Existing GetBitsProof and nChainWork formulas.
- Existing chain-selection machinery.

These remain subject to security testing.
Preservation is preferred, not pre-approved.

## Unresolved Consensus Decisions

- Exact activation mechanism and height.
- Initial RandomX difficulty.
- Retarget behaviour immediately after activation.
- Cross-algorithm chainwork security.
- RandomX V2 seed derivation and epoch rules.
- Header prevalidation without trusted ancestry.
- Reorganisation, restart and storage consistency.

## Strict Implementation Rules

- No genesis regeneration.
- No historical Scrypt reinterpretation.
- No balances or monetary-rule changes.
- No mainnet activation in experimental work.
- No silent fallback between PoW algorithms.
- No production source changes before review.
- No release based only on laboratory PASS results.

## Release Gates

Require independent historical replay,
boundary and negative-case validation,
actual RandomX PoW acceptance,
competing-chain and reorganisation tests,
wallet and reward accounting,
restart recovery, independent node agreement
and sustained monitored operation.

## Current Decision

Prefer the smallest consensus patch set that
passes all compatibility and security gates.

This document is an engineering plan,
not an approved consensus specification.

DO NOT RELEASE.
