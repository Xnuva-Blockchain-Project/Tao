// Copyright (c) 2009-present The Bitcoin Core developers
// Copyright (c) 2017-present The TaoCoin developers
// TAO Revival migration draft: UNTESTED / DO NOT RELEASE.

#include <kernel/chainparams.h>

#include <consensus/amount.h>
#include <consensus/merkle.h>
#include <consensus/params.h>
#include <primitives/block.h>
#include <primitives/transaction.h>
#include <script/script.h>
#include <uint256.h>
#include <util/chaintype.h>
#include <util/strencodings.h>

#include <algorithm>
#include <cassert>
#include <cstring>
#include <limits>
#include <memory>
#include <ranges>
#include <stdexcept>
#include <vector>

namespace {

static CBlock CreateTAOGenesisBlock()
{
    const char* pszTimestamp =
        "Betoota Advocate 21Dec2017 Bloke That Got Caught Up Talking Bitcoin";
    const CScript genesisOutputScript =
        CScript() << ParseHex("04defb2ebff8d065d863eeb265f549bf0d89a6f21475a117b85380802bf0480bd6ab7685e84aadfa3316b803ec74d251a175b37713232e5ec48ed7b0b486d3e3bc")
                  << OP_CHECKSIG;

    CMutableTransaction txNew;
    txNew.version = 1;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig =
        CScript() << 486604799 << CScriptNum(4)
                  << std::vector<unsigned char>(
                         reinterpret_cast<const unsigned char*>(pszTimestamp),
                         reinterpret_cast<const unsigned char*>(pszTimestamp) + std::strlen(pszTimestamp));
    txNew.vout[0].nValue = 50 * COIN;
    txNew.vout[0].scriptPubKey = genesisOutputScript;

    CBlock genesis;
    genesis.nVersion = 1;
    genesis.nTime = 1513853104;
    genesis.nBits = 0x1e0ffff0;
    genesis.nNonce = 1349876;
    genesis.vtx.push_back(MakeTransactionRef(std::move(txNew)));
    genesis.hashPrevBlock.SetNull();
    genesis.hashMerkleRoot = BlockMerkleRoot(genesis);
    return genesis;
}

static void DisableAllVersionBits(Consensus::Params& consensus)
{
    for (auto& deployment : consensus.vDeployments) {
        deployment.nStartTime = Consensus::BIP9Deployment::NEVER_ACTIVE;
        deployment.nTimeout = Consensus::BIP9Deployment::NO_TIMEOUT;
        deployment.min_activation_height = 0;
        deployment.threshold = 0;
        deployment.period = 0;
    }
}

class CMainParams final : public CChainParams
{
public:
    CMainParams()
    {
        m_chain_type = ChainType::MAIN;
        consensus.signet_blocks = false;
        consensus.signet_challenge.clear();

        consensus.nSubsidyHalvingInterval = 210000;

        // TAO Revival only introduces the serialized-height/version-2 rule
        // at height 710000. Later Bitcoin softforks did not exist in Revival.
        consensus.BIP34Height = 710000;
        consensus.BIP34Hash = uint256{}; // intentionally unknown; keeps BIP30 checks enabled
        consensus.BIP65Height = std::numeric_limits<int>::max();
        consensus.BIP66Height = std::numeric_limits<int>::max();
        consensus.CSVHeight = std::numeric_limits<int>::max();
        consensus.SegwitHeight = std::numeric_limits<int>::max();
        consensus.MinBIP9WarningHeight = std::numeric_limits<int>::max();

        DisableAllVersionBits(consensus);

        consensus.powLimit =
            uint256{"00000fffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"};
        consensus.nPowTargetTimespan = 10 * 60;
        consensus.nPowTargetSpacing = 5 * 60;
        consensus.fPowAllowMinDifficultyBlocks = false;
        consensus.enforce_BIP94 = false;
        consensus.fPowNoRetargeting = false;

        // No assumevalid shortcut until the Revival history has been revalidated.
        consensus.nMinimumChainWork = uint256{};
        consensus.defaultAssumeValid = uint256{};

        pchMessageStart = {0xb3, 0x3d, 0xdc, 0x92};
        nDefaultPort = 31137;
        nPruneAfterHeight = 100000;
        m_assumed_blockchain_size = 1;
        m_assumed_chain_state_size = 1;

        genesis = CreateTAOGenesisBlock();
        consensus.hashGenesisBlock = genesis.GetHash();
        assert(consensus.hashGenesisBlock ==
               uint256{"41de2a4b7018115eae4a3e7e82189b551aaf871af66929fa28a49ee852abb67e"});
        assert(genesis.hashMerkleRoot ==
               uint256{"cb8d58accf6e38658164002f3258e6f9123206997d234537aa725898c1fb1c62"});

        // Revival source has only explicit genesis/height-1 checkpoints and
        // no authoritative modern-format seed set in this migration phase.
        vSeeds.clear();
        vFixedSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = {65};
        base58Prefixes[SCRIPT_ADDRESS] = {5};
        base58Prefixes[SECRET_KEY] = {193};

        // Revival predates HD extended-key and Bech32 formats. These extended
        // key prefixes are temporary modern-wallet plumbing, not historical
        // TAO consensus identity, and are release-gated pending wallet review.
        base58Prefixes[EXT_PUBLIC_KEY] = {0x04, 0x88, 0xB2, 0x1E};
        base58Prefixes[EXT_SECRET_KEY] = {0x04, 0x88, 0xAD, 0xE4};
        bech32_hrp = "tao-disabled";

        fDefaultConsistencyChecks = false;
        m_is_mockable_chain = false;
        m_assumeutxo_data.clear();
        chainTxData = {1513853104, 1, 0.0};

        // Non-consensus header-sync memory tuning; calibrate during testing.
        m_headers_sync_params = {.commitment_period = 673, .redownload_buffer_size = 14460};
    }
};

} // namespace

std::unique_ptr<const CChainParams> CChainParams::Main()
{
    return std::make_unique<const CMainParams>();
}

std::unique_ptr<const CChainParams> CChainParams::TestNet()
{
    throw std::runtime_error(
        "TAO Revival testnet is unresolved: authoritative source contains a blank genesis placeholder");
}

std::unique_ptr<const CChainParams> CChainParams::TestNet4()
{
    throw std::runtime_error("Bitcoin testnet4 is not a TAO Revival network");
}

std::unique_ptr<const CChainParams> CChainParams::SigNet(const SigNetOptions&)
{
    throw std::runtime_error("Signet is not a TAO Revival network");
}

std::unique_ptr<const CChainParams> CChainParams::RegTest(const RegTestOptions&)
{
    throw std::runtime_error("TAO regtest has not yet been defined for the migration workspace");
}

std::vector<int> CChainParams::GetAvailableSnapshotHeights() const
{
    return {};
}

std::optional<ChainType> GetNetworkForMagic(const MessageStartChars& message)
{
    const auto mainnet = CChainParams::Main()->MessageStart();
    if (std::ranges::equal(message, mainnet)) return ChainType::MAIN;
    return std::nullopt;
}
