# Engineering Continuity Standard — TaoX / Golden Standard

> Naming update: Denzuve (DZUV) is the selected future public identity of TAO Revival, inspired by the Roman denarius. Historical TaoX/TAOX/TOAX source paths, identifiers and evidence remain valid. Formal clearance and release qualification pending; no live activation.

Status: **development process documentation** (22 November 2026). This document is not an approval to activate RandomX or release a node.

## Source of truth

1. **Git/GitHub commits and reviewed source** are authoritative for *what code exists*.
2. **Checkpoint records with complete commands, outputs, hashes and test environment** are authoritative for *what was actually tested*.
3. **Golden Standard Cryptocurrency Modernisation Handbook (GSH)** records cross-coin policies and release gates. When its canonical location is confirmed, cross-reference it rather than maintaining contradictory copies.
4. Chat memory, previous assistant summaries and new-chat handovers are **navigation aids**, not proof of correctness. Reconcile them against Git and evidence.

## Before beginning any new chat/session

1. Read the latest `CURRENT_STATUS.md`, the latest signed-off checkpoint, open blockers and the relevant historical checkpoint evidence.
2. Confirm repository, branch, exact commit, upstream/foundation pin, worktree state and isolated build paths. Do a **targeted** verification; do not repeat a passed wide audit without a clear new risk.
3. Split work into **Verified / Experimental / Unverified / Blocked**. A successful compile is not a successful network test.
4. Identify the *single next unanswered question* and state the bounded read-only or development-only checkpoint needed to answer it.
5. Preserve rollback, provenance and known-good builds. Work in an isolated candidate; never patch a known-good laboratory source in place.
6. Ask for new terminal output only when necessary to distinguish alternatives or validate a new change. Do not rerun previous tests simply to generate another PASS.
7. Record new evidence, changed files, resulting commit SHA, limitations and the next checkpoint **before** another chat handover.

## Checkpoint record template

```markdown
# <Project> — CP <ID> — <short title>
Date (UTC):
Repo / branch / commit:
Environment (development/test/mainnet):
Objective / reason this checkpoint is needed:
Safety boundaries (read-only / isolated modification / node operation):
Preconditions and evidence already accepted (links + hashes):
Exact commands or changes:
Observed outputs (verbatim or retained log link):
Result: VERIFIED / EXPERIMENTAL / FAILED / UNVERIFIED
Meaning and limitations:
Rollback / backups:
Open issues:
Next bounded checkpoint:
```

## Mandatory handover format

- Exact last checkpoint and verified Git SHA.
- Source and build paths, plus relevant pinned dependency SHAs and binary hashes.
- Distinguish *completed / currently blocked / not started*.
- Key consensus invariants and production safety rules.
- One next checkpoint with specific acceptance criteria.
- Links to authoritative evidence, not a speculative percentage of progress.
- Mark anything inferred from a chat or transcription as **unverified** until independently checked.

## Golden Standard release gates

**Reliability first; release second.** Do not call a release complete solely on a PASS from a self-test, build, or synthetic harness. Depending on applicable network functionality, require:

- Historical consensus, identity and balance invariants;
- Algorithm-specific header/full-block PoW and difficulty validation;
- Network admission, anti-DoS, chainwork and reorganisation testing;
- Independently accepted mined blocks and correct wallet/reward maturity;
- Treasury/game integration where applicable;
- Restart, reindex, recovery and sustained independent-node agreement;
- Reproducible sources/builds, recorded provenance and accurate communications.

## Safety constraints specific to TaoX

- Existing TAO Revival mainnet remains on historical Scrypt rules; no RandomX activation height or seed parameters have been approved.
- Preserve SHA256d block identity, historical Scrypt PoW, chain data and wallet balances.
- Do not execute/restart/connect to production nodes as part of the isolated RandomX development work.
- An engine linked into a daemon is not proof that consensus will use it; a self-test PASS is not proof of network readiness.

## Keeping this document current

On each completed checkpoint, update `CURRENT_STATUS.md` in the **same reviewed documentation branch** as its evidence or linked code commit. Never silently edit the published live branch; promote with review and explicitly record the promotion SHA.
