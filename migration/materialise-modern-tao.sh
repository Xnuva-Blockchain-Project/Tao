#!/usr/bin/env bash
set -euo pipefail

# Materialise the current TAO Revival-on-Bitcoin-Core-31.1 draft.
# DEVELOPMENT ONLY — DO NOT CONNECT TO LIVE TAO.

EXPECTED_UPSTREAM="9be056a8a72b624dae9623b2f7bded92c2a21c91"
AUTHORITATIVE_REVIVAL="74216f33f634f5dde37e96805c72c63c181c52df"
DEST="${1:-modern-tao-worktree}"

ROOT="$(git rev-parse --show-toplevel)"
cd "$ROOT"

if [[ -e "$DEST" ]]; then
    echo "STOP: destination already exists: $DEST" >&2
    exit 1
fi

git submodule update --init --recursive modern-core
actual="$(git -C modern-core rev-parse HEAD)"
if [[ "$actual" != "$EXPECTED_UPSTREAM" ]]; then
    echo "STOP: modern-core commit mismatch" >&2
    echo "expected: $EXPECTED_UPSTREAM" >&2
    echo "actual:   $actual" >&2
    exit 1
fi

mkdir -p "$DEST"
cp -a modern-core/. "$DEST"/
cp -a migration/modern-tao-draft/. "$DEST"/

cat <<EOF
TAO Revival modern draft materialised at:
  $DEST

Bitcoin Core baseline:
  $EXPECTED_UPSTREAM

Authoritative TAO Revival source:
  $AUTHORITATIVE_REVIVAL

Status:
  UNTESTED / DO NOT RELEASE / DO NOT CONNECT TO LIVE TAO

This command only creates a source working tree. It does not launch a node,
modify tao-revival, or create a blockchain.
EOF
