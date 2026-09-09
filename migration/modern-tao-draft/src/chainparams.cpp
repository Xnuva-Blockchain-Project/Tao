// TAO Revival Bitcoin Core 31.1 migration draft.
// UNTESTED / DO NOT RELEASE.

#include <chainparams.h>
#include <chainparamsbase.h>
#include <common/args.h>
#include <util/chaintype.h>

#include <cassert>
#include <memory>
#include <stdexcept>

static std::unique_ptr<const CChainParams> globalChainParams;

const CChainParams& Params()
{
    assert(globalChainParams);
    return *globalChainParams;
}

std::unique_ptr<const CChainParams> CreateChainParams(const ArgsManager&, const ChainType chain)
{
    if (chain == ChainType::MAIN) return CChainParams::Main();
    throw std::runtime_error(
        "TAO Revival migration draft: only authoritative mainnet is enabled");
}

void SelectParams(const ChainType chain)
{
    SelectBaseParams(chain);
    globalChainParams = CreateChainParams(gArgs, chain);
}
