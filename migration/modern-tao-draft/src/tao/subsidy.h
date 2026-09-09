// TAO Revival subsidy adapter for Bitcoin Core 31.1.
// UNTESTED / DO NOT RELEASE.
#ifndef TAO_SUBSIDY_H
#define TAO_SUBSIDY_H

#include <consensus/amount.h>

namespace Consensus { struct Params; }

namespace tao {
CAmount GetBlockSubsidy(int height, const Consensus::Params& params);
} // namespace tao

#endif // TAO_SUBSIDY_H
