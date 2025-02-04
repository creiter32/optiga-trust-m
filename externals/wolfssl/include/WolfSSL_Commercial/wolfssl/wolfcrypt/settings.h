/* settings.h
 *
 * Copyright (C) 2006-2016 wolfSSL Inc.  All rights reserved.
 *
 * This file is part of wolfSSL.
 *
 * Contact licensing@wolfssl.com with any questions or comments.
 *
 * http://www.wolfssl.com
 */



/* Place OS specific preprocessor flags, defines, includes here, will be
   included into every file because types.h includes it */


#ifndef WOLF_CRYPT_SETTINGS_H
#define WOLF_CRYPT_SETTINGS_H

#ifdef __cplusplus
    extern "C" {
#endif

/* Uncomment next line if using IPHONE */
/* #define IPHONE */

/* Uncomment next line if using ThreadX */
/* #define THREADX */

/* Uncomment next line if using Micrium ucOS */
/* #define MICRIUM */

/* Uncomment next line if using Mbed */
/* #define MBED */

/* Uncomment next line if using Microchip PIC32 ethernet starter kit */
/* #define MICROCHIP_PIC32 */

/* Uncomment next line if using Microchip TCP/IP stack, version 5 */
/* #define MICROCHIP_TCPIP_V5 */

/* Uncomment next line if using Microchip TCP/IP stack, version 6 or later */
/* #define MICROCHIP_TCPIP */

/* Uncomment next line if using PIC32MZ Crypto Engine */
/* #define WOLFSSL_MICROCHIP_PIC32MZ */

/* Uncomment next line if using FreeRTOS */
/* #define FREERTOS */

/* Uncomment next line if using FreeRTOS+ TCP */
/* #define FREERTOS_TCP */

/* Uncomment next line if using FreeRTOS Windows Simulator */
/* #define FREERTOS_WINSIM */

/* Uncomment next line if using RTIP */
/* #define EBSNET */

/* Uncomment next line if using lwip */
/* #define WOLFSSL_LWIP */

/* Uncomment next line if building wolfSSL for a game console */
/* #define WOLFSSL_GAME_BUILD */

/* Uncomment next line if building wolfSSL for LSR */
/* #define WOLFSSL_LSR */

/* Uncomment next line if building for Freescale Classic MQX/RTCS/MFS */
/* #define FREESCALE_MQX */

/* Uncomment next line if building for Freescale KSDK MQX/RTCS/MFS */
/* #define FREESCALE_KSDK_MQX */

/* Uncomment next line if building for Freescale KSDK Bare Metal */
/* #define FREESCALE_KSDK_BM */

/* Uncomment next line if building for Freescale KSDK FreeRTOS (old name FREESCALE_FREE_RTOS) */
/* #define FREESCALE_KSDK_FREERTOS */

/* Uncomment next line if using STM32F2 */
/* #define WOLFSSL_STM32F2 */

/* Uncomment next line if using QL SEP settings */
/* #define WOLFSSL_QL */

/* Uncomment next line if building for EROAD */
/* #define WOLFSSL_EROAD */

/* Uncomment next line if building for IAR EWARM */
/* #define WOLFSSL_IAR_ARM */

/* Uncomment next line if building for Rowley CrossWorks ARM */
/* #define WOLFSSL_ROWLEY_ARM */

/* Uncomment next line if using TI-RTOS settings */
/* #define WOLFSSL_TIRTOS */

/* Uncomment next line if building with PicoTCP */
/* #define WOLFSSL_PICOTCP */

/* Uncomment next line if building for PicoTCP demo bundle */
/* #define WOLFSSL_PICOTCP_DEMO */

/* Uncomment next line if building for uITRON4  */
/* #define WOLFSSL_uITRON4 */

/* Uncomment next line if building for uT-Kernel */
/* #define WOLFSSL_uTKERNEL2 */

/* Uncomment next line if using Max Strength build */
/* #define WOLFSSL_MAX_STRENGTH */

/* Uncomment next line if building for VxWorks */
/* #define WOLFSSL_VXWORKS */

/* Uncomment next line if building for Nordic nRF5x platofrm */
/* #define WOLFSSL_NRF5x */

/* Uncomment next line to enable deprecated less secure static DH suites */
/* #define WOLFSSL_STATIC_DH */

/* Uncomment next line to enable deprecated less secure static RSA suites */
/* #define WOLFSSL_STATIC_RSA */

/* Uncomment next line if building for ARDUINO */
/* Uncomment both lines if building for ARDUINO on INTEL_GALILEO */
/* #define WOLFSSL_ARDUINO */
/* #define INTEL_GALILEO */

/* Uncomment next line to enable asynchronous crypto WC_PENDING_E */
/* #define WOLFSSL_ASYNC_CRYPT */

/* Uncomment next line if building for uTasker */
/* #define WOLFSSL_UTASKER */

/* Uncomment next line if building for embOS */
/* #define WOLFSSL_EMBOS */

/* Uncomment next line if building for RIOT-OS */
/* #define WOLFSSL_RIOT_OS */

#include <wolfssl/wolfcrypt/visibility.h>

#ifdef WOLFSSL_USER_SETTINGS
    #include <user_settings.h>
#endif


/* make sure old RNG name is used with CTaoCrypt FIPS */
#ifdef HAVE_FIPS
    #define WC_RNG RNG
    /* blinding adds API not available yet in FIPS mode */
    #undef WC_RSA_BLINDING
#endif


#ifdef IPHONE
    #define SIZEOF_LONG_LONG 8
#endif

#ifdef THREADX
    #define SIZEOF_LONG_LONG 8
#endif

#ifdef HAVE_NETX
    #include "nx_api.h"
#endif

#if defined(HAVE_LWIP_NATIVE) /* using LwIP native TCP socket */
    #define WOLFSSL_LWIP
    #define NO_WRITEV
    #define SINGLE_THREADED
    #define WOLFSSL_USER_IO
    #define NO_FILESYSTEM
#endif

#if defined(WOLFSSL_IAR_ARM) || defined(WOLFSSL_ROWLEY_ARM)
    #define NO_MAIN_DRIVER
    #define SINGLE_THREADED
    #if !defined(USE_CERT_BUFFERS_2048) && !defined(USE_CERT_BUFFERS_4096)
        #define USE_CERT_BUFFERS_1024
    #endif
    #define BENCH_EMBEDDED
    #define NO_FILESYSTEM
    #define NO_WRITEV
    #define WOLFSSL_USER_IO
    #define BENCH_EMBEDDED
#endif

#ifdef MICROCHIP_PIC32
    /* #define WOLFSSL_MICROCHIP_PIC32MZ */
    #define SIZEOF_LONG_LONG 8
    #define SINGLE_THREADED
    #define WOLFSSL_USER_IO
    #define NO_WRITEV
    #define NO_DEV_RANDOM
    #define NO_FILESYSTEM
    #define USE_FAST_MATH
    #define TFM_TIMING_RESISTANT
    #define NEED_AES_TABLES
    #define WOLFSSL_HAVE_MIN
#endif

#ifdef WOLFSSL_MICROCHIP_PIC32MZ
    #define WOLFSSL_PIC32MZ_CE
    #define WOLFSSL_PIC32MZ_CRYPT
    #define HAVE_AES_ENGINE
    #define WOLFSSL_PIC32MZ_RNG
    /* #define WOLFSSL_PIC32MZ_HASH */
    #define WOLFSSL_AES_COUNTER
    #define HAVE_AESGCM
    #define NO_BIG_INT
#endif

#ifdef MICROCHIP_TCPIP_V5
    /* include timer functions */
    #include "TCPIP Stack/TCPIP.h"
#endif

#ifdef MICROCHIP_TCPIP
    /* include timer, NTP functions */
    #ifdef MICROCHIP_MPLAB_HARMONY
        #include "tcpip/tcpip.h"
    #else
        #include "system/system_services.h"
        #include "tcpip/sntp.h"
    #endif
#endif

#ifdef MBED
    #define WOLFSSL_USER_IO
    #define NO_FILESYSTEM
    #define NO_CERT
    #if !defined(USE_CERT_BUFFERS_2048) && !defined(USE_CERT_BUFFERS_4096)
        #define USE_CERT_BUFFERS_1024
    #endif
    #define NO_WRITEV
    #define NO_DEV_RANDOM
    #define NO_SHA512
    #define NO_DH
    /* Allows use of DH with fixed points if uncommented and NO_DH is removed */
    /* WOLFSSL_DH_CONST */
    #define NO_DSA
    #define NO_HC128
    #define HAVE_ECC
    #define NO_SESSION_CACHE
    #define WOLFSSL_CMSIS_RTOS
#endif


#ifdef WOLFSSL_EROAD
    #define FREESCALE_MQX
    #define FREESCALE_MMCAU
    #define SINGLE_THREADED
    #define NO_STDIO_FILESYSTEM
    #define WOLFSSL_LEANPSK
    #define HAVE_NULL_CIPHER
    #define NO_OLD_TLS
    #define NO_ASN
    #define NO_BIG_INT
    #define NO_RSA
    #define NO_DSA
    #define NO_DH
    /* Allows use of DH with fixed points if uncommented and NO_DH is removed */
    /* WOLFSSL_DH_CONST */
    #define NO_CERTS
    #define NO_PWDBASED
    #define NO_DES3
    #define NO_MD4
    #define NO_RC4
    #define NO_MD5
    #define NO_SESSION_CACHE
    #define NO_MAIN_DRIVER
#endif

#ifdef WOLFSSL_PICOTCP
    #ifndef errno
        #define errno pico_err
    #endif
    #include "pico_defines.h"
    #include "pico_stack.h"
    #include "pico_constants.h"
    #include "pico_protocol.h"
    #define CUSTOM_RAND_GENERATE pico_rand
#endif

#ifdef WOLFSSL_PICOTCP_DEMO
    #define WOLFSSL_STM32
    #define USE_FAST_MATH
    #define TFM_TIMING_RESISTANT
    #define XMALLOC(s, h, type)  PICO_ZALLOC((s))
    #define XFREE(p, h, type)    PICO_FREE((p))
    #define SINGLE_THREADED
    #define NO_WRITEV
    #define WOLFSSL_USER_IO
    #define NO_DEV_RANDOM
    #define NO_FILESYSTEM
#endif

#ifdef FREERTOS_WINSIM
    #define FREERTOS
    #define USE_WINDOWS_API
#endif


#ifdef WOLFSSL_VXWORKS
    /* VxWorks simulator incorrectly detects building for i386 */
    #ifdef VXWORKS_SIM
        #define TFM_NO_ASM
    #endif
    #define WOLFSSL_PTHREADS
    #define WOLFSSL_HAVE_MIN
    #define USE_FAST_MATH
    #define TFM_TIMING_RESISTANT
    #define NO_MAIN_DRIVER
    #define NO_DEV_RANDOM
    #define NO_WRITEV
#endif


#ifdef WOLFSSL_ARDUINO
    #define NO_WRITEV
    #define NO_WOLFSSL_DIR
    #define SINGLE_THREADED
    #define NO_DEV_RANDOM
    #ifndef INTEL_GALILEO /* Galileo has time.h compatibility */
        #define TIME_OVERRIDES /* must define XTIME and XGMTIME externally */
    #endif
    #define WOLFSSL_USER_IO
    #define HAVE_ECC
    #define NO_DH
    #define NO_SESSION_CACHE
    #define USE_SLOW_SHA
    #define NO_WOLFSSL_SERVER
    #define NO_ERROR_STRINGS
#endif


#ifdef WOLFSSL_UTASKER
    /* uTasker configuration - used for fnRandom() */
    #include "config.h"

    #define SINGLE_THREADED
    #define NO_WOLFSSL_DIR
    #define WOLFSSL_HAVE_MIN
    #define NO_WRITEV

    #define HAVE_ECC
    #define ALT_ECC_SIZE
    #define USE_FAST_MATH
    #define TFM_TIMING_RESISTANT
    #define ECC_TIMING_RESISTANT

    /* used in wolfCrypt test */
    #define NO_MAIN_DRIVER
    #define USE_CERT_BUFFERS_2048

    /* uTasker port uses RAW sockets, use I/O callbacks
	 * See wolfSSL uTasker example for sample callbacks */
    #define WOLFSSL_USER_IO

    /* uTasker filesystem not ported  */
    #define NO_FILESYSTEM

    /* uTasker RNG is abstracted, calls HW RNG when available */
    #define CUSTOM_RAND_GENERATE    fnRandom
    #define CUSTOM_RAND_TYPE        unsigned short

    /* user needs to define XTIME to function that provides
     * seconds since Unix epoch */
    #ifndef XTIME
        #error XTIME must be defined in wolfSSL settings.h
        /* #define XTIME fnSecondsSinceEpoch */
    #endif

    /* use uTasker std library replacements where available */
    #define STRING_USER
    #define XMEMCPY(d,s,l)         uMemcpy((d),(s),(l))
    #define XMEMSET(b,c,l)         uMemset((b),(c),(l))
    #define XMEMCMP(s1,s2,n)       uMemcmp((s1),(s2),(n))
    #define XMEMMOVE(d,s,l)        memmove((d),(s),(l))

    #define XSTRLEN(s1)            uStrlen((s1))
    #define XSTRNCPY(s1,s2,n)      strncpy((s1),(s2),(n))
    #define XSTRSTR(s1,s2)         strstr((s1),(s2))
    #define XSTRNSTR(s1,s2,n)      mystrnstr((s1),(s2),(n))
    #define XSTRNCMP(s1,s2,n)      strncmp((s1),(s2),(n))
    #define XSTRNCAT(s1,s2,n)      strncat((s1),(s2),(n))
    #define XSTRNCASECMP(s1,s2,n)  _strnicmp((s1),(s2),(n))
    #if defined(WOLFSSL_CERT_EXT) || defined(HAVE_ALPN)
        #define XSTRTOK            strtok_r
    #endif
#endif

#ifdef WOLFSSL_EMBOS
    #define NO_FILESYSTEM           /* Not ported at this time */
    #define USE_CERT_BUFFERS_2048   /* use when NO_FILESYSTEM */
    #define NO_MAIN_DRIVER
    #define NO_RC4
    #define SINGLE_THREADED         /* Not ported at this time */
#endif

#ifdef WOLFSSL_RIOT_OS
    #define NO_WRITEV
    #define TFM_NO_ASM
    #define USE_FAST_MATH
    #define NO_FILE_SYSTEM
    #define USE_CERT_BUFFERS_2048
    #define HAVE_ECC
#endif

#ifdef WOLFSSL_NRF5x
		#define SIZEOF_LONG 4
		#define SIZEOF_LONG_LONG 8
		#define NO_ASN_TIME
		#define NO_DEV_RANDOM
		#define NO_FILESYSTEM
		#define NO_MAIN_DRIVER
		#define NO_WRITEV
		#define SINGLE_THREADED
		#define USE_FAST_MATH
		#define TFM_TIMING_RESISTANT
		#define USE_WOLFSSL_MEMORY
		#define WOLFSSL_NRF51
		#define WOLFSSL_USER_IO
		#define NO_SESSION_CACHE
#endif

/* Micrium will use Visual Studio for compilation but not the Win32 API */
#if defined(_WIN32) && !defined(MICRIUM) && !defined(FREERTOS) && \
	!defined(FREERTOS_TCP) && !defined(EBSNET) && !defined(WOLFSSL_EROAD) && \
	!defined(WOLFSSL_UTASKER)
    #define USE_WINDOWS_API
#endif

#if defined(WOLFSSL_uITRON4)

#define XMALLOC_USER
#include <stddef.h>
#define ITRON_POOL_SIZE 1024*20
extern int uITRON4_minit(size_t poolsz) ;
extern void *uITRON4_malloc(size_t sz) ;
extern void *uITRON4_realloc(void *p, size_t sz) ;
extern void uITRON4_free(void *p) ;

#define XMALLOC(sz, heap, type)     uITRON4_malloc(sz)
#define XREALLOC(p, sz, heap, type) uITRON4_realloc(p, sz)
#define XFREE(p, heap, type)        uITRON4_free(p)
#endif

#if defined(WOLFSSL_uTKERNEL2)
#define WOLFSSL_CLOSESOCKET
#define XMALLOC_USER
int uTKernel_init_mpool(unsigned int sz) ; /* initializing malloc pool */
void *uTKernel_malloc(unsigned int sz) ;
void *uTKernel_realloc(void *p, unsigned int sz) ;
void   uTKernel_free(void *p) ;
#define XMALLOC(s, h, type) uTKernel_malloc((s))
#define XREALLOC(p, n, h, t)  uTKernel_realloc((p), (n))
#define XFREE(p, h, type)  uTKernel_free((p))

#include <stdio.h>
#include    "tm/tmonitor.h"
static char *fgets(char *buff, int sz, FILE *fp)
/*static char * gets(char *buff)*/
{
    char * p = buff ;
    *p = '\0' ;
    while(1) {
        *p = tm_getchar(-1) ;
        tm_putchar(*p) ;
        if(*p == '\r') {
            tm_putchar('\n') ;
            *p = '\0' ;
            break ;
        }
        p ++ ;
    }
    return buff ;
}

#endif


#if defined(WOLFSSL_LEANPSK) && !defined(XMALLOC_USER)
    #include <stdlib.h>
    #define XMALLOC(s, h, type)  malloc((s))
    #define XFREE(p, h, type)    free((p))
    #define XREALLOC(p, n, h, t) realloc((p), (n))
#endif

#if defined(XMALLOC_USER) && defined(SSN_BUILDING_LIBYASSL)
    #undef  XMALLOC
    #define XMALLOC     yaXMALLOC
    #undef  XFREE
    #define XFREE       yaXFREE
    #undef  XREALLOC
    #define XREALLOC    yaXREALLOC
#endif


#ifdef FREERTOS
    #include "FreeRTOS.h"

    /* FreeRTOS pvPortRealloc() only in AVR32_UC3 port */
    #if !defined(XMALLOC_USER) && !defined(NO_WOLFSSL_MEMORY)
        #define XMALLOC(s, h, type)  pvPortMalloc((s))
        #define XFREE(p, h, type)    vPortFree((p))
    #endif

    #ifndef NO_WRITEV
        #define NO_WRITEV
    #endif
    #ifndef HAVE_SHA512
        #ifndef NO_SHA512
            #define NO_SHA512
        #endif
    #endif
    #ifndef HAVE_DH
        #ifndef NO_DH
            #define NO_DH
        #endif
    #endif
    #ifndef NO_DSA
        #define NO_DSA
    #endif
    #ifndef NO_HC128
        #define NO_HC128
    #endif

    #ifndef SINGLE_THREADED
        #include "semphr.h"
    #endif
#endif

#ifdef FREERTOS_TCP

#if !defined(NO_WOLFSSL_MEMORY) && !defined(XMALLOC_USER)
#define XMALLOC(s, h, type)  pvPortMalloc((s))
#define XFREE(p, h, type)    vPortFree((p))
#endif

#define WOLFSSL_GENSEED_FORTEST

#define NO_WOLFSSL_DIR
#define NO_WRITEV
#define USE_FAST_MATH
#define TFM_TIMING_RESISTANT
#define NO_MAIN_DRIVER

#endif

#ifdef WOLFSSL_TIRTOS
    #define SIZEOF_LONG_LONG 8
    #define NO_WRITEV
    #define NO_WOLFSSL_DIR
    #define USE_FAST_MATH
    #define TFM_TIMING_RESISTANT
    #define NO_DEV_RANDOM
    #define NO_FILESYSTEM
    #define USE_CERT_BUFFERS_2048
    #define NO_ERROR_STRINGS
    #define USER_TIME
    #define HAVE_ECC
    #define HAVE_ALPN
    #define HAVE_TLS_EXTENSIONS
    #define HAVE_AESGCM
    #define HAVE_SUPPORTED_CURVES
    #define ALT_ECC_SIZE

    #ifdef __IAR_SYSTEMS_ICC__
        #pragma diag_suppress=Pa089
    #elif !defined(__GNUC__)
        /* Suppress the sslpro warning */
        #pragma diag_suppress=11
    #endif

    #include <ti/sysbios/hal/Seconds.h>
#endif

#ifdef EBSNET
    #include "rtip.h"

    /* #define DEBUG_WOLFSSL */
    #define NO_WOLFSSL_DIR  /* tbd */

    #if (POLLOS)
        #define SINGLE_THREADED
    #endif

    #if (RTPLATFORM)
        #if (!RTP_LITTLE_ENDIAN)
            #define BIG_ENDIAN_ORDER
        #endif
    #else
        #if (!KS_LITTLE_ENDIAN)
            #define BIG_ENDIAN_ORDER
        #endif
    #endif

    #if (WINMSP3)
        #undef SIZEOF_LONG
        #define SIZEOF_LONG_LONG 8
    #else
        #sslpro: settings.h - please implement SIZEOF_LONG and SIZEOF_LONG_LONG
    #endif

    #define XMALLOC(s, h, type) ((void *)rtp_malloc((s), SSL_PRO_MALLOC))
    #define XFREE(p, h, type) (rtp_free(p))
    #define XREALLOC(p, n, h, t) realloc((p), (n))

#endif /* EBSNET */

#ifdef WOLFSSL_GAME_BUILD
    #define SIZEOF_LONG_LONG 8
    #if defined(__PPU) || defined(__XENON)
        #define BIG_ENDIAN_ORDER
    #endif
#endif

#ifdef WOLFSSL_LSR
    #define HAVE_WEBSERVER
    #define SIZEOF_LONG_LONG 8
    #define WOLFSSL_LOW_MEMORY
    #define NO_WRITEV
    #define NO_SHA512
    #define NO_DH
    /* Allows use of DH with fixed points if uncommented and NO_DH is removed */
    /* WOLFSSL_DH_CONST */
    #define NO_DSA
    #define NO_HC128
    #define NO_DEV_RANDOM
    #define NO_WOLFSSL_DIR
    #define NO_RABBIT
    #ifndef NO_FILESYSTEM
        #define LSR_FS
        #include "inc/hw_types.h"
        #include "fs.h"
    #endif
    #define WOLFSSL_LWIP
    #include <errno.h>  /* for tcp errno */
    #define WOLFSSL_SAFERTOS
    #if defined(__IAR_SYSTEMS_ICC__)
        /* enum uses enum */
        #pragma diag_suppress=Pa089
    #endif
#endif

#ifdef WOLFSSL_SAFERTOS
    #ifndef SINGLE_THREADED
        #include "SafeRTOS/semphr.h"
    #endif

    #include "SafeRTOS/heap.h"
    #define XMALLOC(s, h, type)  pvPortMalloc((s))
    #define XFREE(p, h, type)    vPortFree((p))
    #define XREALLOC(p, n, h, t) pvPortRealloc((p), (n))
#endif

#ifdef WOLFSSL_LOW_MEMORY
    #undef  RSA_LOW_MEM
    #define RSA_LOW_MEM
    #undef  WOLFSSL_SMALL_STACK
    #define WOLFSSL_SMALL_STACK
    #undef  TFM_TIMING_RESISTANT
    #define TFM_TIMING_RESISTANT
#endif

#ifdef FREESCALE_MQX
    #define FREESCALE_COMMON
    #include "mqx.h"
    #ifndef NO_FILESYSTEM
        #include "mfs.h"
        #if MQX_USE_IO_OLD
            #include "fio.h"
        #else
            #include "nio.h"
        #endif
    #endif
    #ifndef SINGLE_THREADED
        #include "mutex.h"
    #endif

    #define XMALLOC(s, h, t)    (void *)_mem_alloc_system((s))
    #define XFREE(p, h, t)      {void* xp = (p); if ((xp)) _mem_free((xp));}
    /* Note: MQX has no realloc, using fastmath above */
#endif

#ifdef FREESCALE_KSDK_MQX
    #define FREESCALE_COMMON
    #include <mqx.h>
    #ifndef NO_FILESYSTEM
        #if MQX_USE_IO_OLD
            #include <fio.h>
        #else
            #include <stdio.h>
            #include <nio.h>
        #endif
    #endif
    #ifndef SINGLE_THREADED
        #include <mutex.h>
    #endif

    #define XMALLOC(s, h, t)    (void *)_mem_alloc_system((s))
    #define XFREE(p, h, t)      {void* xp = (p); if ((xp)) _mem_free((xp));}
    #define XREALLOC(p, n, h, t) _mem_realloc((p), (n)) /* since MQX 4.1.2 */

    #define MQX_FILE_PTR FILE *
    #define IO_SEEK_SET  SEEK_SET
    #define IO_SEEK_END  SEEK_END
#endif /* FREESCALE_KSDK_MQX */

#if defined(FREESCALE_FREE_RTOS) || defined(FREESCALE_KSDK_FREERTOS)
    /* Allows use of DH with fixed points if uncommented and NO_DH is removed */
    /* WOLFSSL_DH_CONST */
    /* Allows use of DH with fixed points if uncommented and NO_DH is removed */
    /* WOLFSSL_DH_CONST */
    /* Allows use of DH with fixed points if uncommented and NO_DH is removed */
    /* WOLFSSL_DH_CONST */
    #define NO_FILESYSTEM
    #define WOLFSSL_CRYPT_HW_MUTEX 1
        
    #if !defined(XMALLOC_USER) && !defined(NO_WOLFSSL_MEMORY)
        #define XMALLOC(s, h, type)  pvPortMalloc((s))
        #define XFREE(p, h, type)    vPortFree((p))
    #endif
    
    //#define USER_TICKS
    /* Allows use of DH with fixed points if uncommented and NO_DH is removed */
    /* WOLFSSL_DH_CONST */
    #define WOLFSSL_LWIP
    #define FREERTOS_TCP

    #define FREESCALE_FREE_RTOS
    #define FREERTOS_SOCKET_ERROR ( -1 )
    #define FREERTOS_EWOULDBLOCK ( -2 )
    #define FREERTOS_EINVAL ( -4 )
    #define FREERTOS_EADDRNOTAVAIL ( -5 )
    #define FREERTOS_EADDRINUSE ( -6 )
    #define FREERTOS_ENOBUFS ( -7 )
    #define FREERTOS_ENOPROTOOPT ( -8 )
#endif /* FREESCALE_FREE_RTOS || FREESCALE_KSDK_FREERTOS */

#ifdef FREESCALE_KSDK_BM
    #define FREESCALE_COMMON
    #define WOLFSSL_USER_IO
    #define SINGLE_THREADED
    #define NO_FILESYSTEM
    #define USER_TICKS
#endif /* FREESCALE_KSDK_BM */

#ifdef FREESCALE_COMMON
    #define SIZEOF_LONG_LONG 8

    /* disable features */
    #undef  NO_WRITEV
    #define NO_WRITEV
    #undef  NO_DEV_RANDOM
    #define NO_DEV_RANDOM
    #undef  NO_RABBIT
    #define NO_RABBIT
    #undef  NO_WOLFSSL_DIR
    #define NO_WOLFSSL_DIR
    #undef  NO_RC4
    #define NO_RC4

    /* enable features */
    #undef  USE_FAST_MATH
    #define USE_FAST_MATH

    #define USE_CERT_BUFFERS_2048
    #define BENCH_EMBEDDED

    #define TFM_TIMING_RESISTANT
    #define ECC_TIMING_RESISTANT

    #undef  HAVE_ECC
    #define HAVE_ECC
    #ifndef NO_AES
        #undef  HAVE_AESCCM
        #define HAVE_AESCCM
        #undef  HAVE_AESGCM
        #define HAVE_AESGCM
        #undef  WOLFSSL_AES_COUNTER
        #define WOLFSSL_AES_COUNTER
        #undef  WOLFSSL_AES_DIRECT
        #define WOLFSSL_AES_DIRECT
    #endif

    #include "fsl_common.h"

    /* random seed */
    #define NO_OLD_RNGNAME
    #if defined(FSL_FEATURE_SOC_TRNG_COUNT) && (FSL_FEATURE_SOC_TRNG_COUNT > 0)
        #define FREESCALE_KSDK_2_0_TRNG
    #elif defined(FSL_FEATURE_SOC_RNG_COUNT) && (FSL_FEATURE_SOC_RNG_COUNT > 0)
        #define FREESCALE_KSDK_2_0_RNGA
    #elif !defined(FREESCALE_KSDK_BM) && !defined(FREESCALE_FREE_RTOS) && !defined(FREESCALE_KSDK_FREERTOS)
        #define FREESCALE_RNGA
        #define RNGA_INSTANCE (0)
        /* defaulting to K70 RNGA, user should change if different */
        /* #define FREESCALE_K53_RNGB */
        #define FREESCALE_K70_RNGA
    #endif

    /* HW crypto */
    /* automatic enable based on Kinetis feature */
    /* if case manual selection is required, for example for benchmarking purposes,
     * just define FREESCALE_USE_MMCAU or FREESCALE_USE_LTC or none of these two macros (for software only)
     * both can be enabled simultaneously as LTC has priority over MMCAU in source code.
     */
    /* #define FSL_HW_CRYPTO_MANUAL_SELECTION */
    #ifndef FSL_HW_CRYPTO_MANUAL_SELECTION
        #if defined(FSL_FEATURE_SOC_MMCAU_COUNT) && FSL_FEATURE_SOC_MMCAU_COUNT
            #define FREESCALE_USE_MMCAU
        #endif

        #if defined(FSL_FEATURE_SOC_LTC_COUNT) && FSL_FEATURE_SOC_LTC_COUNT
            #define FREESCALE_USE_LTC
        #endif
    #else
        /* #define FREESCALE_USE_MMCAU */
        /* #define FREESCALE_USE_LTC */
    #endif
#endif /* FREESCALE_COMMON */

#ifdef FREESCALE_USE_MMCAU
    /* AES and DES */
    #define FREESCALE_MMCAU
    /* MD5, SHA-1 and SHA-256 */
    #define FREESCALE_MMCAU_SHA
#endif /* FREESCALE_USE_MMCAU */

#ifdef FREESCALE_USE_LTC
    #if defined(FSL_FEATURE_SOC_LTC_COUNT) && FSL_FEATURE_SOC_LTC_COUNT
        #define FREESCALE_LTC
        #define LTC_BASE LTC0

        #if defined(FSL_FEATURE_LTC_HAS_DES) && FSL_FEATURE_LTC_HAS_DES
            #define FREESCALE_LTC_DES
        #endif

        #if defined(FSL_FEATURE_LTC_HAS_GCM) && FSL_FEATURE_LTC_HAS_GCM
            #define FREESCALE_LTC_AES_GCM
        #endif
        
        #if defined(FSL_FEATURE_LTC_HAS_SHA) && FSL_FEATURE_LTC_HAS_SHA
            #define FREESCALE_LTC_SHA
        #endif

        #if defined(FSL_FEATURE_LTC_HAS_PKHA) && FSL_FEATURE_LTC_HAS_PKHA
            #define FREESCALE_LTC_ECC
            #define FREESCALE_LTC_TFM

            /* the LTC PKHA hardware limit is 2048 bits (256 bytes) for integer arithmetic.
               the LTC_MAX_INT_BYTES defines the size of local variables that hold big integers. */
            #ifndef LTC_MAX_INT_BYTES
                #define LTC_MAX_INT_BYTES (256)
            #endif

            /* This FREESCALE_LTC_TFM_RSA_4096_ENABLE macro can be defined. 
             * In such a case both software and hardware algorithm
             * for TFM is linked in. The decision for which algorithm is used is determined at runtime
             * from size of inputs. If inputs and result can fit into LTC (see LTC_MAX_INT_BYTES)
             * then we call hardware algorithm, otherwise we call software algorithm.
             * 
             * Chinese reminder theorem is used to break RSA 4096 exponentiations (both public and private key)
             * into several computations with 2048-bit modulus and exponents.
             */
            /* #define FREESCALE_LTC_TFM_RSA_4096_ENABLE */

            /* ECC-384, ECC-256, ECC-224 and ECC-192 have been enabled with LTC PKHA acceleration */
            #ifdef HAVE_ECC
                #undef  ECC_TIMING_RESISTANT
                #define ECC_TIMING_RESISTANT

                /* the LTC PKHA hardware limit is 512 bits (64 bytes) for ECC.
                   the LTC_MAX_ECC_BITS defines the size of local variables that hold ECC parameters 
                   and point coordinates */
                #ifndef LTC_MAX_ECC_BITS
                    #define LTC_MAX_ECC_BITS (384)
                #endif

                /* Enable curves up to 384 bits */
                #if !defined(ECC_USER_CURVES) && !defined(HAVE_ALL_CURVES)
                    #define ECC_USER_CURVES
                    #define HAVE_ECC192
                    #define HAVE_ECC224
                    #undef  NO_ECC256
                    #define HAVE_ECC384
                #endif

                /* enable features */
                #undef  HAVE_CURVE25519
                #define HAVE_CURVE25519
                #undef  HAVE_ED25519
                #define HAVE_ED25519
                #undef  WOLFSSL_SHA512
                #define WOLFSSL_SHA512
            #endif
        #endif
    #endif
#endif /* FREESCALE_USE_LTC */

#ifdef FREESCALE_LTC_TFM_RSA_4096_ENABLE
    #undef  USE_CERT_BUFFERS_2048
    #define USE_CERT_BUFFERS_4096
    #define FP_MAX_BITS (8192)

    #undef  NO_DH
    #define NO_DH
    #undef  NO_DSA
    #define NO_DSA
#endif /* FREESCALE_LTC_TFM_RSA_4096_ENABLE */

/* if LTC has AES engine but doesn't have GCM, use software with LTC AES ECB mode */
#if defined(FREESCALE_USE_LTC) && !defined(FREESCALE_LTC_AES_GCM)
    #define GCM_TABLE
#endif

#ifdef WOLFSSL_STM32F2
    #define SIZEOF_LONG_LONG 8
    #define NO_DEV_RANDOM
    #define NO_WOLFSSL_DIR
    #undef  NO_RABBIT
    #define NO_RABBIT
    #undef  NO_64BIT
    #define NO_64BIT
    #define STM32F2_RNG
    #define STM32F2_CRYPTO
    #if !defined(__GNUC__) && !defined(__ICCARM__)
        #define KEIL_INTRINSICS
    #endif
    #define NO_OLD_RNGNAME
    #ifdef WOLFSSL_STM32_CUBEMX
        #include "stm32f2xx_hal.h"
		#ifndef STM32_HAL_TIMEOUT
        	#define STM32_HAL_TIMEOUT   0xFF
		#endif
    #else
        #include "stm32f2xx.h"
        #include "stm32f2xx_cryp.h"
        #include "stm32f2xx_hash.h"
    #endif /* WOLFSSL_STM32_CUBEMX */
#endif

#ifdef WOLFSSL_STM32F4
    #define SIZEOF_LONG_LONG 8
    #define NO_DEV_RANDOM
    #define NO_WOLFSSL_DIR
    #undef  NO_RABBIT
    #define NO_RABBIT
    #undef  NO_64BIT
    #define NO_64BIT
    #define STM32F4_RNG
    #define STM32F4_CRYPTO
    #define NO_OLD_RNGNAME
    #if !defined(__GNUC__) && !defined(__ICCARM__)
        #define KEIL_INTRINSICS
    #endif
    #ifdef WOLFSSL_STM32_CUBEMX
        #include "stm32f4xx_hal.h"
		#ifndef STM32_HAL_TIMEOUT
        	#define STM32_HAL_TIMEOUT   0xFF
		#endif
    #else
        #include "stm32f4xx.h"
        #include "stm32f4xx_cryp.h"
        #include "stm32f4xx_hash.h"
    #endif /* WOLFSSL_STM32_CUBEMX */
#endif

//IFX Code Changes 
//This setting to be used while using Cyassl on Windows
#ifdef WOLFSSL_WIN32
	#define WOLFSSL_DTLS
	#define HAVE_AESCCM
	#define NO_OLD_TLS
	#define HAVE_SUPPORTED_CURVES
	#define HAVE_TLS_EXTENSIONS	
    #define HAVE_ECC
    #define _CRT_SECURE_NO_WARNINGS
    #define SINGLE_THREADED
    #define WOLFSSL_USER_IO
    #define NO_WOLFSSL_CLIENT
    #define NO_WOLFSSL_SERVER
    #define NO_DES3
    #define NO_DH
    #define NO_ERROR_STRINGS
    #define NO_MD4
    #define NO_HC128
    #define NO_DSA
    #define NO_RABBIT
    #define NO_SHA512
    #define NO_PWDBASED
    #define NO_SESSION_CACHE
    #define NO_DEV_RANDOM
    #define NO_FILESYSTEM
    #define NO_WRITEV
    #define NO_MAINDRIVER
    #define WOLFSSL_ALT_NAMES
    #define WOLFSSL_VALIDATE_ECC_IMPORT
    #define WOLFSSL_VALIDATE_ECC_KEYGEN
    #define WOLFSSL_STATIC_RSA
    #define WOLFSSL_CERT_EXT
    #define WOLFSSL_MISC_INCLUDED
    #define WOLFSSL_KEY_GEN
    #define WOLFSSL_CERT_GEN
#endif

//IFX Code Changes 
#ifdef WOLFSSL_XMC4500
	#define WOLFSSL_DTLS
	#define HAVE_AESCCM
	#define NO_OLD_TLS
	#define HAVE_SUPPORTED_CURVES
	#define HAVE_TLS_EXTENSIONS
	#define WOLFSSL_ALT_NAMES	
    #define HAVE_ECC
    #define _CRT_SECURE_NO_WARNINGS
    #define SINGLE_THREADED
    #define WOLFSSL_USER_IO
	#define USER_TIME
    #define NO_WOLFSSL_CLIENT
    #define NO_WOLFSSL_SERVER
    #define NO_DES3
    #define NO_DH
    #define NO_ERROR_STRINGS
    #define NO_MD4
    #define NO_HC128
    #define NO_DSA
    #define NO_RABBIT
    #define NO_SHA512
    #define NO_PWDBASED
    #define NO_SESSION_CACHE
    #define NO_DEV_RANDOM
    #define NO_FILESYSTEM
    #define NO_WRITEV
    #define NO_MAINDRIVER
    #define WOLFSSL_STATIC_RSA
    #define WOLFSSL_CERT_EXT
    #define WOLFSSL_MISC_INCLUDED
    #define ECC_USER_CURVES
    #define NO_WOLFSSL_DIR
    #define NO_ERROR_STRINGS	
    #define NO_MD5
    #define NO_SHA
    #define NO_INLINE
    #define NO_RSA
    #define FP_MAX_BITS 512
	#define USE_FAST_MATH
#endif
	
#ifdef MICRIUM

    #include "stdlib.h"
    #include "net_cfg.h"
    #include "ssl_cfg.h"
    #include "net_secure_os.h"

    #define WOLFSSL_TYPES

    typedef CPU_INT08U byte;
    typedef CPU_INT16U word16;
    typedef CPU_INT32U word32;

    #if (NET_SECURE_MGR_CFG_WORD_SIZE == CPU_WORD_SIZE_32)
        #define SIZEOF_LONG        4
        #undef  SIZEOF_LONG_LONG
    #else
        #undef  SIZEOF_LONG
        #define SIZEOF_LONG_LONG   8
    #endif

    #define STRING_USER

    #define XSTRLEN(pstr) ((CPU_SIZE_T)Str_Len((CPU_CHAR *)(pstr)))
    #define XSTRNCPY(pstr_dest, pstr_src, len_max) \
                    ((CPU_CHAR *)Str_Copy_N((CPU_CHAR *)(pstr_dest), \
                     (CPU_CHAR *)(pstr_src), (CPU_SIZE_T)(len_max)))
    #define XSTRNCMP(pstr_1, pstr_2, len_max) \
                    ((CPU_INT16S)Str_Cmp_N((CPU_CHAR *)(pstr_1), \
                     (CPU_CHAR *)(pstr_2), (CPU_SIZE_T)(len_max)))
    #define XSTRSTR(pstr, pstr_srch) \
                    ((CPU_CHAR *)Str_Str((CPU_CHAR *)(pstr), \
                     (CPU_CHAR *)(pstr_srch)))
    #define XMEMSET(pmem, data_val, size) \
                    ((void)Mem_Set((void *)(pmem), (CPU_INT08U) (data_val), \
                    (CPU_SIZE_T)(size)))
    #define XMEMCPY(pdest, psrc, size) ((void)Mem_Copy((void *)(pdest), \
                     (void *)(psrc), (CPU_SIZE_T)(size)))
    #define XMEMCMP(pmem_1, pmem_2, size) \
                   (((CPU_BOOLEAN)Mem_Cmp((void *)(pmem_1), (void *)(pmem_2), \
                     (CPU_SIZE_T)(size))) ? DEF_NO : DEF_YES)
    #define XMEMMOVE XMEMCPY

#if (NET_SECURE_MGR_CFG_EN == DEF_ENABLED)
    #define MICRIUM_MALLOC
    #define XMALLOC(s, h, type) ((void *)NetSecure_BlkGet((CPU_INT08U)(type), \
                                 (CPU_SIZE_T)(s), (void *)0))
    #define XFREE(p, h, type)   (NetSecure_BlkFree((CPU_INT08U)(type), \
                                 (p), (void *)0))
    #define XREALLOC(p, n, h, t) realloc((p), (n))
#endif

    #if (NET_SECURE_MGR_CFG_FS_EN == DEF_ENABLED)
        #undef  NO_FILESYSTEM
    #else
        #define NO_FILESYSTEM
    #endif

    #if (SSL_CFG_TRACE_LEVEL == WOLFSSL_TRACE_LEVEL_DBG)
        #define DEBUG_WOLFSSL
    #else
        #undef  DEBUG_WOLFSSL
    #endif

    #if (SSL_CFG_OPENSSL_EN == DEF_ENABLED)
        #define OPENSSL_EXTRA
    #else
        #undef  OPENSSL_EXTRA
    #endif

    #if (SSL_CFG_MULTI_THREAD_EN == DEF_ENABLED)
        #undef  SINGLE_THREADED
    #else
        #define SINGLE_THREADED
    #endif

    #if (SSL_CFG_DH_EN == DEF_ENABLED)
        #undef  NO_DH
    #else
        #define NO_DH
    #endif

    #if (SSL_CFG_DSA_EN == DEF_ENABLED)
        #undef  NO_DSA
    #else
        #define NO_DSA
    #endif

    #if (SSL_CFG_PSK_EN == DEF_ENABLED)
        #undef  NO_PSK
    #else
        #define NO_PSK
    #endif

    #if (SSL_CFG_3DES_EN == DEF_ENABLED)
        #undef  NO_DES
    #else
        #define NO_DES
    #endif

    #if (SSL_CFG_AES_EN == DEF_ENABLED)
        #undef  NO_AES
    #else
        #define NO_AES
    #endif

    #if (SSL_CFG_RC4_EN == DEF_ENABLED)
        #undef  NO_RC4
    #else
        #define NO_RC4
    #endif

    #if (SSL_CFG_RABBIT_EN == DEF_ENABLED)
        #undef  NO_RABBIT
    #else
        #define NO_RABBIT
    #endif

    #if (SSL_CFG_HC128_EN == DEF_ENABLED)
        #undef  NO_HC128
    #else
        #define NO_HC128
    #endif

    #if (CPU_CFG_ENDIAN_TYPE == CPU_ENDIAN_TYPE_BIG)
        #define BIG_ENDIAN_ORDER
    #else
        #undef  BIG_ENDIAN_ORDER
        #define LITTLE_ENDIAN_ORDER
    #endif

    #if (SSL_CFG_MD4_EN == DEF_ENABLED)
        #undef  NO_MD4
    #else
        #define NO_MD4
    #endif

    #if (SSL_CFG_WRITEV_EN == DEF_ENABLED)
        #undef  NO_WRITEV
    #else
        #define NO_WRITEV
    #endif

    #if (SSL_CFG_USER_RNG_SEED_EN == DEF_ENABLED)
        #define NO_DEV_RANDOM
    #else
        #undef  NO_DEV_RANDOM
    #endif

    #if (SSL_CFG_USER_IO_EN == DEF_ENABLED)
        #define WOLFSSL_USER_IO
    #else
        #undef  WOLFSSL_USER_IO
    #endif

    #if (SSL_CFG_DYNAMIC_BUFFERS_EN == DEF_ENABLED)
        #undef  LARGE_STATIC_BUFFERS
        #undef  STATIC_CHUNKS_ONLY
    #else
        #define LARGE_STATIC_BUFFERS
        #define STATIC_CHUNKS_ONLY
    #endif

    #if (SSL_CFG_DER_LOAD_EN == DEF_ENABLED)
        #define  WOLFSSL_DER_LOAD
    #else
        #undef   WOLFSSL_DER_LOAD
    #endif

    #if (SSL_CFG_DTLS_EN == DEF_ENABLED)
        #define  WOLFSSL_DTLS
    #else
        #undef   WOLFSSL_DTLS
    #endif

    #if (SSL_CFG_CALLBACKS_EN == DEF_ENABLED)
         #define WOLFSSL_CALLBACKS
    #else
         #undef  WOLFSSL_CALLBACKS
    #endif

    #if (SSL_CFG_FAST_MATH_EN == DEF_ENABLED)
         #define USE_FAST_MATH
    #else
         #undef  USE_FAST_MATH
    #endif

    #if (SSL_CFG_TFM_TIMING_RESISTANT_EN == DEF_ENABLED)
         #define TFM_TIMING_RESISTANT
    #else
         #undef  TFM_TIMING_RESISTANT
    #endif

#endif /* MICRIUM */


#ifdef WOLFSSL_QL
    #ifndef WOLFSSL_SEP
        #define WOLFSSL_SEP
    #endif
    #ifndef OPENSSL_EXTRA
        #define OPENSSL_EXTRA
    #endif
    #ifndef SESSION_CERTS
        #define SESSION_CERTS
    #endif
    #ifndef HAVE_AESCCM
        #define HAVE_AESCCM
    #endif
    #ifndef ATOMIC_USER
        #define ATOMIC_USER
    #endif
    #ifndef WOLFSSL_DER_LOAD
        #define WOLFSSL_DER_LOAD
    #endif
    #ifndef KEEP_PEER_CERT
        #define KEEP_PEER_CERT
    #endif
    #ifndef HAVE_ECC
        #define HAVE_ECC
    #endif
    #ifndef SESSION_INDEX
        #define SESSION_INDEX
    #endif
#endif /* WOLFSSL_QL */


#if !defined(XMALLOC_USER) && !defined(MICRIUM_MALLOC) && \
    !defined(WOLFSSL_LEANPSK) && !defined(NO_WOLFSSL_MEMORY)
    #define USE_WOLFSSL_MEMORY
#endif


#if defined(OPENSSL_EXTRA) && !defined(NO_CERTS)
    #undef  KEEP_PEER_CERT
    #define KEEP_PEER_CERT
#endif


/* stream ciphers except arc4 need 32bit alignment, intel ok without */
#ifndef XSTREAM_ALIGN
    #if defined(__x86_64__) || defined(__ia64__) || defined(__i386__)
        #define NO_XSTREAM_ALIGN
    #else
        #define XSTREAM_ALIGN
    #endif
#endif

#ifdef WOLFSSL_SGX
    #define WOLFCRYPT_ONLY   /* limitation until IO resolved */
    #define SINGLE_THREADED
    #define NO_ASN_TIME /* can not use headers such as windows.h */

    /* options used in created example */
    #define HAVE_AESGCM
    #define USE_CERT_BUFFERS_2048
    #define USE_FAST_MATH
    #define NO_RC4
    #define NO_DES3
    #define NO_SHA
    #define NO_MD5
#endif /* WOLFSSL_SGX */

/* FreeScale MMCAU hardware crypto has 4 byte alignment.
   However, fsl_mmcau.h gives API with no alignment requirements (4 byte alignment is managed internally by fsl_mmcau.c) */
#ifdef FREESCALE_MMCAU
    #define WOLFSSL_MMCAU_ALIGNMENT 0
#endif

/* if using hardware crypto and have alignment requirements, specify the
   requirement here.  The record header of SSL/TLS will prevent easy alignment.
   This hint tries to help as much as possible.  */
#ifndef WOLFSSL_GENERAL_ALIGNMENT
    #ifdef WOLFSSL_AESNI
        #define WOLFSSL_GENERAL_ALIGNMENT 16
    #elif defined(XSTREAM_ALIGN)
        #define WOLFSSL_GENERAL_ALIGNMENT  4
    #elif defined(FREESCALE_MMCAU)
        #define WOLFSSL_GENERAL_ALIGNMENT  WOLFSSL_MMCAU_ALIGNMENT
    #else
        #define WOLFSSL_GENERAL_ALIGNMENT  0
    #endif
#endif

#if defined(WOLFSSL_GENERAL_ALIGNMENT) && (WOLFSSL_GENERAL_ALIGNMENT > 0)
    #if defined(_MSC_VER)
        #define XGEN_ALIGN __declspec(align(WOLFSSL_GENERAL_ALIGNMENT))
    #elif defined(__GNUC__)
        #define XGEN_ALIGN __attribute__((aligned(WOLFSSL_GENERAL_ALIGNMENT)))
    #else
        #define XGEN_ALIGN
    #endif
#else
    #define XGEN_ALIGN
#endif

#ifdef HAVE_CRL
    /* not widely supported yet */
    #undef NO_SKID
    #define NO_SKID
#endif


#ifdef __INTEL_COMPILER
    #pragma warning(disable:2259) /* explicit casts to smaller sizes, disable */
#endif

/* user can specify what curves they want with ECC_USER_CURVES otherwise
 * all curves are on by default for now */
#ifndef ECC_USER_CURVES
    #ifndef HAVE_ALL_CURVES
        #define HAVE_ALL_CURVES
    #endif
#endif

/* ECC Configs */
#ifdef HAVE_ECC
    /* By default enable Sign, Verify, DHE, Key Import and Key Export unless explicitly disabled */
    #ifndef NO_ECC_SIGN
        #undef HAVE_ECC_SIGN
        #define HAVE_ECC_SIGN
    #endif
    #ifndef NO_ECC_VERIFY
        #undef HAVE_ECC_VERIFY
        #define HAVE_ECC_VERIFY
    #endif
    #ifndef NO_ECC_DHE
        #undef HAVE_ECC_DHE
        #define HAVE_ECC_DHE
    #endif
    #ifndef NO_ECC_KEY_IMPORT
        #undef HAVE_ECC_KEY_IMPORT
        #define HAVE_ECC_KEY_IMPORT
    #endif
    #ifndef NO_ECC_KEY_EXPORT
        #undef HAVE_ECC_KEY_EXPORT
        #define HAVE_ECC_KEY_EXPORT
    #endif
#endif /* HAVE_ECC */

/* Curve255519 Configs */
#ifdef HAVE_CURVE25519
    /* By default enable shared secret, key export and import */
    #ifndef NO_CURVE25519_SHARED_SECRET
        #undef HAVE_CURVE25519_SHARED_SECRET
        #define HAVE_CURVE25519_SHARED_SECRET
    #endif
    #ifndef NO_CURVE25519_KEY_EXPORT
        #undef HAVE_CURVE25519_KEY_EXPORT
        #define HAVE_CURVE25519_KEY_EXPORT
    #endif
    #ifndef NO_CURVE25519_KEY_IMPORT
        #undef HAVE_CURVE25519_KEY_IMPORT
        #define HAVE_CURVE25519_KEY_IMPORT
    #endif
#endif /* HAVE_CURVE25519 */

/* Ed255519 Configs */
#ifdef HAVE_ED25519
    /* By default enable sign, verify, key export and import */
    #ifndef NO_ED25519_SIGN
        #undef HAVE_ED25519_SIGN
        #define HAVE_ED25519_SIGN
    #endif
    #ifndef NO_ED25519_VERIFY
        #undef HAVE_ED25519_VERIFY
        #define HAVE_ED25519_VERIFY
    #endif
    #ifndef NO_ED25519_KEY_EXPORT
        #undef HAVE_ED25519_KEY_EXPORT
        #define HAVE_ED25519_KEY_EXPORT
    #endif
    #ifndef NO_ED25519_KEY_IMPORT
        #undef HAVE_ED25519_KEY_IMPORT
        #define HAVE_ED25519_KEY_IMPORT
    #endif
#endif /* HAVE_ED25519 */

/* AES Config */
#ifndef NO_AES
    /* By default enable all AES key sizes, decryption and CBC */
    #ifndef AES_MAX_KEY_SIZE
        #undef  AES_MAX_KEY_SIZE
        #define AES_MAX_KEY_SIZE    256
    #endif
    #ifndef NO_AES_DECRYPT
        #undef  HAVE_AES_DECRYPT
        #define HAVE_AES_DECRYPT
    #endif
    #ifndef NO_AES_CBC
        #undef  HAVE_AES_CBC
        #define HAVE_AES_CBC
    #else
        #ifndef WOLFCRYPT_ONLY
            #error "AES CBC is required for TLS and can only be disabled for WOLFCRYPT_ONLY builds"
        #endif
    #endif
#endif

/* if desktop type system and fastmath increase default max bits */
#ifdef WOLFSSL_X86_64_BUILD
    #ifdef USE_FAST_MATH
        #ifndef FP_MAX_BITS
            #define FP_MAX_BITS 8192
        #endif
    #endif
#endif

/* If using the max strength build, ensure OLD TLS is disabled. */
#ifdef WOLFSSL_MAX_STRENGTH
    #undef NO_OLD_TLS
    #define NO_OLD_TLS
#endif

//Ifx code changes
/* If not forcing ARC4 as the DRBG or using custom RNG block gen, enable Hash_DRBG */
/*#undef HAVE_HASHDRBG
#if !defined(WOLFSSL_FORCE_RC4_DRBG) && !defined(CUSTOM_RAND_GENERATE_BLOCK)
    #define HAVE_HASHDRBG
#endif*/


/* sniffer requires:
 * static RSA cipher suites
 * session stats and peak stats
 */
#ifdef WOLFSSL_SNIFFER
    #ifndef WOLFSSL_STATIC_RSA
        #define WOLFSSL_STATIC_RSA
    #endif
    #ifndef WOLFSSL_SESSION_STATS
        #define WOLFSSL_SESSION_STATS
    #endif
    #ifndef WOLFSSL_PEAK_SESSIONS
        #define WOLFSSL_PEAK_SESSIONS
    #endif
#endif

/* Decode Public Key extras on by default, user can turn off with
 * WOLFSSL_NO_DECODE_EXTRA */
#ifndef WOLFSSL_NO_DECODE_EXTRA
    #ifndef RSA_DECODE_EXTRA
        #define RSA_DECODE_EXTRA
    #endif
    #ifndef ECC_DECODE_EXTRA
        #define ECC_DECODE_EXTRA
    #endif
#endif

/* C Sharp wrapper defines */
#ifdef HAVE_CSHARP
    #ifndef WOLFSSL_DTLS
        #define WOLFSSL_DTLS
    #endif
    #undef NO_PSK
    #undef NO_SHA256
    #undef NO_DH
#endif

/* Asynchronous Crypto */
#ifdef WOLFSSL_ASYNC_CRYPT
    /* Make sure wolf events are enabled */
    #undef HAVE_WOLF_EVENT
    #define HAVE_WOLF_EVENT

    #if !defined(HAVE_CAVIUM) && !defined(HAVE_INTEL_QA) && \
        !defined(WOLFSSL_ASYNC_CRYPT_TEST)
        #error No async hardware defined with WOLFSSL_ASYNC_CRYPT!
    #endif
#endif /* WOLFSSL_ASYNC_CRYPT */

/* leantls checks */
#ifdef WOLFSSL_LEANTLS
    #ifndef HAVE_ECC
        #error leantls build needs ECC
    #endif
#endif /* WOLFSSL_LEANTLS*/

/* restriction with static memory */
#ifdef WOLFSSL_STATIC_MEMORY
    #if defined(HAVE_IO_POOL) || defined(XMALLOC_USER) || defined(NO_WOLFSSL_MEMORY)
         #error static memory cannot be used with HAVE_IO_POOL, XMALLOC_USER or NO_WOLFSSL_MEMORY
    #endif
    #if !defined(USE_FAST_MATH) && !defined(NO_BIG_INT)
        #error static memory requires fast math please define USE_FAST_MATH
    #endif
    #ifdef WOLFSSL_SMALL_STACK
        #error static memory does not support small stack please undefine
    #endif
#endif /* WOLFSSL_STATIC_MEMORY */

#ifdef HAVE_AES_KEYWRAP
    #ifndef WOLFSSL_AES_DIRECT
        #error AES key wrap requires AES direct please define WOLFSSL_AES_DIRECT
    #endif
#endif

#ifdef HAVE_PKCS7
    #ifndef HAVE_AES_KEYWRAP
        #error PKCS7 requires AES key wrap please define HAVE_AES_KEYWRAP
    #endif
    #ifndef HAVE_X963_KDF
        #error PKCS7 requires X963 KDF please define HAVE_X963_KDF
    #endif
#endif


/* Place any other flags or defines here */

#if defined(WOLFSSL_MYSQL_COMPATIBLE) && defined(_WIN32) \
                                      && defined(HAVE_GMTIME_R)
    #undef HAVE_GMTIME_R /* don't trust macro with windows */
#endif /* WOLFSSL_MYSQL_COMPATIBLE */


#ifdef __cplusplus
    }   /* extern "C" */
#endif

#endif
