#ifndef TAOCOIN_OPENSSL_COMPAT_H
#define TAOCOIN_OPENSSL_COMPAT_H

/*
 * TaoCoin maintained / Revival builds require the opaque OpenSSL APIs
 * introduced with OpenSSL 1.1.0.
 *
 * The preserved TaoCoin Legacy source remains the historical reference
 * for OpenSSL 1.0.x-era builds.
 *
 * Do not silently compile maintained TaoCoin against obsolete 1.0.x
 * headers: doing so can select incompatible crypto structures and APIs.
 */
#include <openssl/opensslv.h>

#if OPENSSL_VERSION_NUMBER < 0x10100000L
#error "TaoCoin maintained/Revival source requires OpenSSL 1.1.0 or newer; OpenSSL 1.0.x is supported only by the preserved Legacy source."
#endif

#endif
