/*
  To the extent possible under law, Nick Mathewson has waived all copyright and
  related or neighboring rights to libottery-lite, using the creative commons
  "cc0" public domain dedication.  See doc/cc0.txt or
  <http://creativecommons.org/publicdomain/zero/1.0/> for full details.
*/
#ifndef OTTERYLITE_H_INCLUDED_
#define OTTERYLITE_H_INCLUDED_

#ifdef __cplusplus
extern "C" {
#endif

/*
#define OTTERY_STRUCT
*/
#define OTTERY_ENABLE_EGD

#ifndef OTTERY_FUNC_PREFIX
#ifdef OTTERY_STRUCT
#define OTTERY_FUNC_PREFIX ottery_st_
#else
#define OTTERY_FUNC_PREFIX ottery_
#endif
#endif

#ifdef OTTERY_STRUCT
#define OTTERY_STATE_ARG_ONLY struct ottery_state *state
#define OTTERY_STATE_ARG_FIRST STATE_ARG_ONLY ,
struct ottery_state;
#else
#define OTTERY_STATE_ARG_ONLY void
#define OTTERY_STATE_ARG_FIRST
#endif

#ifdef _MSC_VER
#define ottery_u64_t unsigned __int64
#elif defined(__GNUC__XXX)
#define ottery_u64_t unsigned long long
#else
#include <stdint.h>
#define ottery_u64_t uint64_t
#endif

#include <sys/types.h>

#define OTTERY_PASTE__(a,b) a ## b
#define OTTERY_PASTE2__(a,b) OTTERY_PASTE__(a, b)
#define OTTERY_PUBLIC_FN(name) OTTERY_PASTE2__(OTTERY_FUNC_PREFIX, name)

void OTTERY_PUBLIC_FN(teardown)(OTTERY_STATE_ARG_ONLY);
void OTTERY_PUBLIC_FN(need_reseed)(OTTERY_STATE_ARG_ONLY);
unsigned OTTERY_PUBLIC_FN(random)(OTTERY_STATE_ARG_ONLY);
ottery_u64_t OTTERY_PUBLIC_FN(random64)(OTTERY_STATE_ARG_ONLY);
unsigned OTTERY_PUBLIC_FN(random_uniform)(OTTERY_STATE_ARG_FIRST unsigned limit);
ottery_u64_t OTTERY_PUBLIC_FN(random_uniform64)(OTTERY_STATE_ARG_FIRST ottery_u64_t limit);
void OTTERY_PUBLIC_FN(random_bytes)(OTTERY_STATE_ARG_FIRST void *out, size_t n);

#ifdef OTTERY_ENABLE_EGD
struct sockaddr;
int OTTERY_PUBLIC_FN(set_egd_address)(const struct sockaddr *sa, int socklen);
#endif

#ifdef __cplusplus
}
#endif

#endif
