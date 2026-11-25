# Denzuve (DZUV) — Ancestry-Aware PoW Integration Boundary

> Naming update: Denzuve (DZUV) is the selected future public identity of TAO Revival, inspired by the Roman denarius. Historical TaoX/TAOX/TOAX source paths, identifiers and evidence remain valid. Formal clearance and release qualification pending; no live activation.

Status: EXPERIMENTAL DESIGN — DO NOT RELEASE

## Objective

Introduce modular RandomX V2 into the existing TAO
blockchain with the smallest safe consensus changes.

Preserve historical Scrypt, SHA256d block identifiers,
balances, monetary rules and network continuity.

## Verified Existing Interfaces

- CBlockIndex::pprev identifies the indexed predecessor.
- CBlockIndex::GetAncestor retrieves branch ancestry.
- CBlockIndex::GetBlockHash retains historical IDs.
- CBlockIndex::IsValid exposes validation status.
- AcceptBlockHeader locates the predecessor after
  its existing context-free Scrypt PoW check.
- ContextualCheckBlockHeader receives the predecessor.
- BlockTreeDB::LoadBlockIndexGuts checks Scrypt while
  reconstructing stored block-index entries.
- Chainwork reconstruction uses GetBlockProof.

## Minimal Proposed Architecture

1. Preserve CBlockHeader::GetHash unchanged.
2. Preserve historical Scrypt hashing.
3. Preserve the existing RandomX V2 adapter.
4. Introduce one context-aware PoW verification
   interface rather than replacing block hashing.
5. Select the authorised algorithm from validated
   branch context and approved consensus parameters.
6. Derive RandomX seeds deterministically from
   consensus-defined, authenticated ancestry.
7. Reject invalid context; defer unknown context
   only where the existing protocol safely allows it.
8. Never silently fall back between algorithms.

## Critical Integration Constraints

### Incoming headers

The existing context-free Scrypt check occurs before
predecessor lookup.

A future implementation must revise that ordering or
verification boundary carefully while preserving
header-spam and anti-DoS protections.

### Startup and block-index reconstruction

Stored block-index entries are currently checked with
Scrypt during loading, before normal reconstructed
ancestry can be relied upon.

A future implementation must establish safe algorithm
and seed selection during startup, including after
restart, reindex and chain reorganisations.

### Historical chain

Historical blocks must continue to validate against
the exact original Scrypt consensus rules.

### Validity levels

An indexed predecessor is not necessarily fully valid.
The required validity level and branch context must
be explicit and tested before PoW verification.

### Seed selection

No RandomX seed schedule is approved yet.
No untrusted peer-supplied seed may control consensus.

### Difficulty and chainwork

Preserve existing rules provisionally.
Any changes require security justification and
independent cross-algorithm verification.

## Required Negative Tests

- Unknown predecessor.
- Invalid predecessor.
- Insufficiently validated predecessor.
- Incorrect RandomX seed.
- Missing RandomX seed.
- Incorrect algorithm at transition boundary.
- Historical Scrypt block presented as RandomX.
- RandomX block presented as Scrypt.
- Startup with mixed-algorithm block index.
- Reindex and reorganisation across activation.
- Untrusted header batch and low-work header spam.

## Implementation Gate

Do not connect this interface to production validation
until activation rules, difficulty, seed derivation
and header anti-DoS behaviour are defined and tested.

No mainnet activation is authorised.

Reliability first, release second.
Minimal changes, maximum compatibility.

DO NOT RELEASE.
