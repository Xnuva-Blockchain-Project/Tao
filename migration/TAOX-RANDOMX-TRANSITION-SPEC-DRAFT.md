# Denzuve (DZUV) RandomX Transition — Experimental Specification

> Naming update: Denzuve (DZUV) is the selected future public identity of TAO Revival, inspired by the Roman denarius. Historical TaoX/TAOX/TOAX source paths, identifiers and evidence remain valid. Formal clearance and release qualification pending; no live activation.

Status: DRAFT — NOT APPROVED FOR MAINNET
Principle: Reliability first, release second.

## 1. Purpose

Define the requirements for a deterministic transition
from historical TAO Scrypt PoW to modular RandomX V2.

This document does not activate RandomX.

## 2. Verified Historical Baseline

- Historical fixture: 637 blocks, heights 0 through 636.
- Height 636 nBits: 0x1e04d8b0.
- Height 636 block proof: 3,461,763.
- Cumulative chainwork: 6,801,755,197.
- Target spacing: 300 seconds.
- Target timespan: 600 seconds.
- Difficulty adjustment interval: 2 blocks.
- Existing PoW algorithm: Scrypt.
- Historical block IDs use SHA256d.
- Existing compact-target decoding accepts some
  noncanonical encodings.
- Historical replay and invalid-Scrypt-block
  rejection passed in isolated tests.

These results describe the tested historical fixture,
not an unrestricted proof of network-wide correctness.

## 3. Experimental Reference Only

Illustrative transition height: 637.
Illustrative initial RandomX nBits: 0x1e0fffff.
Illustrative first RandomX block proof: 1,048,577.
Illustrative cumulative work: 6,802,803,774.

These values are NOT approved consensus parameters.

The initial RandomX target must be justified separately.

## 4. Mandatory Historical Compatibility

- Preserve all historical block IDs.
- Preserve all historical Scrypt PoW verification.
- Preserve historical difficulty rules.
- Preserve existing balances and chain data.
- Reject any retrospective reinterpretation of blocks.
- Require identical interpretation across all nodes.
- Do not enable a transition on mainnet until qualified.

## 5. Activation Requirements

OPEN: Choose and justify an activation mechanism.

Required behaviour:

- Pre-activation: historical Scrypt remains mandatory.
- At activation: algorithm choice must be deterministic.
- Post-activation: reject blocks using the wrong algorithm.
- Unknown ancestry: defer context-dependent validation.
- Invalid ancestry: reject.
- Historical block-ID hashing remains unchanged.

OPEN: Choose activation height or another deterministic
consensus-safe activation condition.

## 6. Initial RandomX Difficulty

OPEN: Establish the first RandomX target.

Requirements:

- A valid numerical compact target.
- Explicit treatment of canonical encoding.
- A documented security rationale.
- Deterministic verification by independent nodes.
- No assumption that Scrypt and RandomX hash rates
  are directly comparable.

## 7. Post-Activation Retargeting

OPEN: Define the RandomX retarget algorithm.

Requirements:

- Deterministic arithmetic and rounding.
- Defined timestamp inputs and ancestry rules.
- Explicit activation-boundary exception.
- Defined behaviour for the first adjustment interval.
- Protection against malformed difficulty targets.
- Tests for delayed and rapid blocks.
- Tests for competing branches and reorganisations.
- Avoid unintended reuse of historical Scrypt timing.

The existing two-block interval is a historical fact,
not automatically an approved RandomX policy.

## 8. Cumulative Chainwork

OPEN: Define cross-algorithm block-work accounting.

Requirements:

- Deterministic total ordering of candidate chains.
- Explicit initial-work and subsequent-work rules.
- Consistent fork-choice behaviour across nodes.
- Resistance to manipulation at the transition.
- Recalculation and restart recovery must agree.
- Independent arithmetic test vectors required.

Bitcoin-style work arithmetic alone does not establish
economic comparability across distinct PoW algorithms.

## 9. RandomX Seed Selection

OPEN: Specify deterministic RandomX V2 seed derivation.

Requirements:

- Seed derived only from validated chain context.
- Identical seed for identical validated ancestry.
- Explicit seed epoch and boundary behaviour.
- Correct handling of competing branches and reorgs.
- No dependence on local node state or wall-clock time.
- Shared modular engine must remain version-pinned.

## 10. Validation-Path Integration

Review and eventually qualify:

- Context-free block-header checks.
- Contextual block-header checks.
- P2P header prevalidation.
- Stored block and block-index loading.
- Mining-template generation.
- Block-work accounting.
- Header synchronisation and anti-DoS checks.
- Reorg and restart recovery.

No single successful hash test proves complete
consensus integration.

## 11. Release Qualification

Required before any mainnet consideration:

- Independent historical Scrypt replay.
- Activation-boundary positive and negative tests.
- RandomX V2 hashing vectors.
- Valid and invalid nBits cases.
- Competing-fork and chainwork tests.
- P2P header and block propagation tests.
- Wallet accounting and reward maturity.
- Shutdown, restart and reorganisation recovery.
- Independent node acceptance.
- Sustained operation with monitoring.

## 12. Current Status

Historical regression foundation: VERIFIED IN LAB.
Experimental target validation: VERIFIED IN LAB.
Experimental policy prototype: VERIFIED IN LAB.

Real consensus integration: NOT IMPLEMENTED.
RandomX activation parameters: NOT APPROVED.
RandomX retargeting: UNDEFINED.
Cross-algorithm work policy: UNDEFINED.
Seed selection: UNDEFINED.
Mainnet release qualification: NOT STARTED.

DO NOT RELEASE.
