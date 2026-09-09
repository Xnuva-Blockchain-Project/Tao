// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-present The Bitcoin Core developers
// TAO migration draft: UNTESTED / DO NOT RELEASE
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <primitives/block.h>

#include <hash.h>
#include <streams.h>
#include <tinyformat.h>
#include <tao/crypto/scrypt.h>

#include <cassert>
#include <memory>
#include <span>
#include <sstream>

uint256 CBlockHeader::GetHash() const
{
    // TAO CONSENSUS: block IDs remain standard serialized double-SHA256.
    return (HashWriter{} << *this).GetHash();
}

uint256 CBlockHeader::GetPoWHash() const
{
    // TAO CONSENSUS: PoW uses Scrypt over the canonical 80-byte header.
    DataStream stream;
    stream << *this;
    assert(stream.size() == 80);

    uint256 out;
    tao::Scrypt1024_1_1_256(stream.data(), out.data());
    return out;
}

std::string CBlock::ToString() const
{
    std::stringstream s;
    s << strprintf("CBlock(hash=%s, ver=0x%08x, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, vtx=%u)\n",
        GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nBits, nNonce,
        vtx.size());
    for (const auto& tx : vtx) {
        s << "  " << tx->ToString() << "\n";
    }
    return s.str();
}
