# Denzuve (DZUV) — Context-Aware Proof-of-Work Contract

> Naming update: Denzuve (DZUV) is the selected future public identity of TAO Revival, inspired by the Roman denarius. Historical TaoX/TAOX/TOAX source paths, identifiers and evidence remain valid. Formal clearance and release qualification pending; no live activation.

Status: EXPERIMENTAL / DESIGN ONLY / DO NOT RELEASE

## 1. Historical invariants

- Preserve existing SHA256d block identifiers.
- Preserve historical Scrypt Proof of Work.
- Preserve genesis, historical blocks and balances.
- Preserve existing TAO network consensus.
- Never rewrite historical block data.

## 2. Algorithm selection

The current production-facing experimental selector
returns Scrypt for every valid nonnegative height.

Future RandomX activation requires an explicit,
network-specific consensus specification.

Candidate height alone does not establish ancestry.

The selector must receive context derived from
the candidate's validated predecessor chain.

Unknown or invalid ancestry must fail closed.

## 3. Required validation paths

The transition must cover:

- Context-free header checks.
- Contextual header acceptance.
- P2P header prescreening.
- Block import and replay.
- Indexed and raw-position block reading.
- Reindex and restart recovery.
- Mining and block template generation.
- Alternative branches and reorganisations.

No path may silently bypass Proof-of-Work checks.

## 4. RandomX seed schedule

Not yet specified.

Requirements:

- Deterministic across independent nodes.
- Derived from explicitly defined chain data.
- Correct for alternative branches.
- Correct at epoch boundaries.
- Resistant to manipulation through unverified
  height or ancestry claims.
- Explicit byte-order and serialization rules.

## 5. Difficulty and chainwork

Not yet specified.

Requirements:

- Preserve historical difficulty.
- Define activation-boundary difficulty.
- Specify post-activation retarget behaviour.
- Define comparable cumulative-work accounting.
- Test alternative-chain selection.
- Prevent unearned work from invalid headers.

## 6. Activation authority

No mainnet activation height is authorised.

No live-network consensus changes are authorised.

Laboratory activation height 1000 is fictional
and must never become an implicit mainnet default.

## 7. Release qualification

Required before production activation:

- Historical regression tests.
- Independent RandomX reference verification.
- Positive and negative boundary tests.
- Seed and epoch-boundary tests.
- Difficulty and chainwork tests.
- P2P and reorganisation tests.
- Mining and wallet-credit verification.
- Restart and recovery.
- Independent-node acceptance.
- Sustained operational monitoring.

Reliability first, release second.
