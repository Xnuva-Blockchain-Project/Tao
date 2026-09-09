// TAO Revival Bitcoin Core 31.1 migration draft.
// UNTESTED / DO NOT RELEASE.

#include <chainparamsbase.h>
#include <common/args.h>
#include <util/chaintype.h>

#include <cassert>
#include <memory>
#include <stdexcept>

void SetupChainParamsBaseOptions(ArgsManager& argsman)
{
    argsman.AddArg("-chain=<chain>",
                   "Use TAO main chain. Revival testnet is unresolved in this migration draft.",
                   ArgsManager::ALLOW_ANY, OptionsCategory::CHAINPARAMS);
}

static std::unique_ptr<CBaseChainParams> globalChainBaseParams;

const CBaseChainParams& BaseParams()
{
    assert(globalChainBaseParams);
    return *globalChainBaseParams;
}

std::unique_ptr<CBaseChainParams> CreateBaseChainParams(const ChainType chain)
{
    if (chain == ChainType::MAIN) {
        return std::make_unique<CBaseChainParams>("", 31138);
    }
    throw std::runtime_error("TAO Revival migration draft: only authoritative mainnet is enabled");
}

void SelectBaseParams(const ChainType chain)
{
    globalChainBaseParams = CreateBaseChainParams(chain);
    gArgs.SelectConfigNetwork(ChainTypeToString(chain));
}
