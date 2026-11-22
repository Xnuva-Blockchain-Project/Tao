# TaoX RandomX Modernisation — Current Engineering Status

**Updated:** 2026-11-22 UTC  
**Status:** experimental; **no mainnet RandomX activation approved; not release-ready**  
**This record is a handover index, not proof that any node has accepted RandomX blocks.**

## Repositories and provenance

- TaoX GitHub repository: `Xnuva-Blockchain-Project/Tao`
- Local project worktree: `~/TaoX-modernisation-2026`
- Development branch verified locally 22 Nov: `modernisation/taox-randomx`
- Verified local branch HEAD: `cda1211630901586616d046101a3a870f876b303`
- Pinned Bitcoin Core 31.1 upstream: `9be056a8a72b624dae9623b2f7bded92c2a21c91`
- Pinned reusable RandomX foundation: `857841056ed939eeea4fd640463b54b6a5cd54af`
- Separate earlier repository/worktree: `~/TAO-modernisation-2026` at `64e30c9e44a9d00afebbd7ba8e38de6089a6c152` (not the current TaoX RandomX HEAD).
- The `cp137jh-source` Git worktree resolves to the pinned Bitcoin Core upstream, not an independent TaoX repository.

## Known-good laboratory locations (preserve unchanged)

- Reconstructed source: `~/taox-build-lab/cp137jfu-full-source` (not a Git worktree).
- Reconstruction manifest: `~/taox-build-lab/cp137jfu-manifest.txt`.
- Scrypt-only complete build: `~/taox-build-lab/cp137jfy-full-build`.
- Experimental RandomX-enabled build: `~/taox-build-lab/cp137jgd-randomx-node`.

| Artifact | SHA-256 verified 2026-11-22 |
|---|---|
| Scrypt `bin/bitcoind` | `50374fa828457be36cb9400d9a1b3db04c778a180e811df220cbd3d8e7a47cbf` |
| Experimental `bin/bitcoind` | `a689a8cf48d527533a25644c478f474752c352ed608767dff6e0221fa5f411cb` |
| RandomX `bin/tao-randomx-selftest` | `9727c5e17b7c9928e0f644f777d07e7722a92660cb89f0ff37e1d96194250301` |

## Evidence already obtained — do not automatically repeat

- **CP 137J-FU–FX:** complete reconstructed source; integrity audit PASS after identifying archive substitution in `src/clientversion.cpp`; 21 modified upstream files and 11 additional TaoX files restored; known-good source retained.
- **CP 137J-FY–GA:** Scrypt node build 320/320 compilation steps PASS; no daemon execution.
- **CP 137J-GD–GE:** experimental RandomX node/self-test build 353/353 steps PASS; two pinned RandomX reference vectors PASS; no daemon execution.
- **Earlier laboratory research:** deterministic synthetic branch/seed testing, missing/altered seed rejection, easy/hard target results, and test-only ancestry resolver/contextual bridge. These are **experimental evidence**, not independent network consensus verification.
- **CP 137J-GF/GG:** symbols exist in standalone RandomX self-test but not the `bitcoind` daemon; daemon link graph does not include experimental RandomX libraries.
- **CP 137J-GH:** audited header validation/presynchronisation, mining, readback, difficulty and chainwork boundaries; no code changes.
- **CP 137J-GI steps 1–4 (22 Nov):** matched all three SHA-256 hashes; located actual main Git worktree and clean tracked state at `cda12116`; confirmed algorithm selection currently stays Scrypt-only, and header prechecks/network admissions assume Scrypt. No source changes or daemon execution.

## Critical boundary findings (source paths in reconstructed tree)

- `src/tao/consensus/pow_algorithm.h`: `SelectPoWAlgorithm(height)` currently selects Scrypt for nonnegative heights.
- `src/tao/consensus/pow_contextual_hash.h`: contextual helper uses parent height and deliberately rejects RandomX.
- `src/tao/consensus/pow_hash_dispatch.h`: modular dispatcher exists.
- Experimental research headers: `pow_transition_policy_experimental.h`, `pow_seed_resolver_experimental.h`, `pow_bridge_experimental.h`. Preserve/review; do **not** rewrite without evidence.
- `src/validation.cpp`: `CheckBlockHeader()` performs context-free Scrypt work before parent resolution; `ContextualCheckBlockHeader()` uses parent and checks difficulty/contextual PoW.
- `src/net_processing.cpp`: `CheckHeadersPoW()` calls Scrypt-assuming `HasValidProofOfWork()` before presynchronisation; anti-DoS admission cannot be weakened.
- `src/node/blockstorage.cpp`: index reload and block readback currently assume Scrypt.
- `src/rpc/mining.cpp`: `GenerateBlock()` nonce search uses `block.GetHash()` where algorithm-specific PoW is required. `GetHash()` remains SHA256d block identity; historical `GetPoWHash()` is Scrypt.
- Difficulty, chainwork, reorg, epoch transitions, seed ancestry, checkpoints and full restart/reindex behaviour still need end-to-end qualification.

## Release blockers

1. RandomX is not yet linked and invoked as a daemon consensus dependency.
2. No approved mainnet activation/seed policy. Experimental rules must remain isolated.
3. Context-free and network Scrypt prechecks would reject future valid RandomX blocks; secure contextual admission design needed before changing them.
4. Mining, block storage/reindex, header presync, difficulty/fork-choice need complete algorithm-aware handling.
5. No independent multi-node RandomX acceptance, wallet rewards, restart or sustained operation proof.

## NEXT: CP 137J-GJ — smallest safe daemon-linkage candidate

**Objective:** use the existing pinned RandomX engine and dispatcher, and inspect the *specific* CMake target/link declarations responsible for its absence from `bitcoind`. Do not repeat the wide six-header dump, repository inventory, or baseline hash checks without a new reason.

**Method and acceptance criteria:**

1. Inspect only the relevant CMake linking definitions and resolved dependency edges in the known-good experimental build. Read-only first.
2. Design one isolated source/build candidate (never edit `cp137jfu-full-source` or previously qualified binaries in place).
3. When justified, make only the minimal test-only linkage change; retain Scrypt mainnet behaviour unchanged.
4. Build and verify actual RandomX symbols/dependencies in the candidate daemon, document exactly what is *not* yet integrated.
5. Run Scrypt-regression and isolated dependency tests appropriate to this change. Record commands, outputs, diff and SHA.
6. Treat contextual verification/network/mining/storage integration as separate later checkpoints, not automatic consequences of linkage.

**Do not claim CP 137J-GJ is complete based on this status file.** No such candidate has yet been built or verified in this record.

## Chat handover discipline

At the next session, read this file and `CONTINUITY_STANDARD.md` before proposing terminal commands. Identify evidence *already verified* and name the one outstanding new question. New claims require exact evidence and Git provenance.

**Reliability first. Release second.**
