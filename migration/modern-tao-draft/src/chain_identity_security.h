#ifndef TAO_CHAIN_IDENTITY_SECURITY_H
#define TAO_CHAIN_IDENTITY_SECURITY_H

#include <string_view>

namespace tao::security {

struct ChainIdentityPolicy {
    int buried_anchor_height;
    std::string_view genesis_hash;
    std::string_view block1_hash;
    std::string_view buried_anchor_hash;
    std::string_view minimum_chainwork;
    bool require_not_ibd;
    bool require_peer;
    bool protect_pow;
    bool protect_pos;
    bool production_block_creation_enabled;
};

inline constexpr ChainIdentityPolicy MAINNET_CHAIN_IDENTITY_POLICY{
    /* buried_anchor_height = */ -1,
    /* genesis_hash = */
    "41de2a4b7018115eae4a3e7e82189b551aaf871af66929fa28a49ee852abb67e",
    /* block1_hash = */
    "717fc5ef97ded9f7d514fcb1ed558bc76596ce85f09890efa6e668d228c4a57f",
    /* buried_anchor_hash = */ "",
    /* minimum_chainwork = */ "",
    /* require_not_ibd = */ true,
    /* require_peer = */ true,
    /* protect_pow = */ true,
    /* protect_pos = */ false,
    /* production_block_creation_enabled = */ false,
};

constexpr bool HasQualifiedBuriedAnchor()
{
    return MAINNET_CHAIN_IDENTITY_POLICY.buried_anchor_height >= 1 &&
           MAINNET_CHAIN_IDENTITY_POLICY.buried_anchor_hash.size() == 64 &&
           MAINNET_CHAIN_IDENTITY_POLICY.minimum_chainwork.size() == 64;
}

constexpr bool ProductionBlockCreationMayBeEnabled()
{
    return MAINNET_CHAIN_IDENTITY_POLICY.production_block_creation_enabled &&
           HasQualifiedBuriedAnchor();
}

} // namespace tao::security

#endif // TAO_CHAIN_IDENTITY_SECURITY_H
