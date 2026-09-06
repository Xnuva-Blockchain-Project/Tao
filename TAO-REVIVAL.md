# TaoCoin Revival

TaoCoin Revival is a successor fork of the preserved TaoCoin legacy codebase.

The original TaoCoin genesis block is preserved unchanged:

41de2a4b7018115eae4a3e7e82189b551aaf871af66929fa28a49ee852abb67e

The historical post-genesis TaoCoin blockchain is not currently known to
survive publicly. TaoCoin Revival therefore creates a new verifiable chain
from the preserved genesis, with its first new block at height 1.

No missing historical blocks or balances are fabricated.

## Canonical Revival fork point

TaoCoin Revival block 1:

    717fc5ef97ded9f7d514fcb1ed558bc76596ce85f09890efa6e668d228c4a57f

This height-1 checkpoint defines the TaoCoin Revival branch. If historical
post-genesis TaoCoin Legacy blocks are recovered in future, they remain part
of TaoCoin Legacy and are not substituted for the Revival height-1 block.


Revival network:

- Mainnet P2P: 31137
- Mainnet RPC: 31138
- Testnet P2P: 41137
- Testnet RPC: 41138
- Mainnet magic: b3 3d dc 92
- Testnet magic: 61 c4 9c 80
- Unix datadir: ~/.taocoin-revival

The obsolete Demomanca legacy DNS seed is not used by TaoCoin Revival.

The original TaoCoin legacy source and genesis remain separately preserved.
