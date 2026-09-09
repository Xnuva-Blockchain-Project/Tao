// TAO Revival subsidy adapter for Bitcoin Core 31.1.
// UNTESTED / DO NOT RELEASE.

#include <tao/subsidy.h>
#include <consensus/params.h>

namespace tao {

CAmount GetBlockSubsidy(const int height, const Consensus::Params& params)
{
    const int halvings = height / params.nSubsidyHalvingInterval;
    if (halvings >= 64) return 0;

    CAmount subsidy = 50 * COIN;
    subsidy >>= halvings;
    return subsidy;
}

} // namespace tao
