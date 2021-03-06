/* SPDX-License-Identifier: BSD-2 */
/*******************************************************************************
 * Copyright 2017-2018, Fraunhofer SIT sponsored by Infineon Technologies AG All
 * rights reserved.
 *******************************************************************************/

#include <stdlib.h>

#include "tss2_esys.h"

#include "esys_iutil.h"
#define LOGMODULE test
#include "util/log.h"

/*
 * This test is intended to test the ESAPI get capability command.
 */

int
test_invoke_esapi(ESYS_CONTEXT * esys_context)
{
    TSS2_RC r;
    TPM2_CAP                       capability = TPM2_CAP_TPM_PROPERTIES;
    UINT32                         property = TPM2_PT_LOCKOUT_COUNTER;
    UINT32                         propertyCount = 1;
    TPMS_CAPABILITY_DATA           *capabilityData;
    TPMI_YES_NO                    moreData;


    r = Esys_GetCapability(esys_context,
                           ESYS_TR_NONE, ESYS_TR_NONE, ESYS_TR_NONE,
                           capability, property, propertyCount,
                           &moreData, &capabilityData);

    goto_if_error(r, "Error esys get capability", error);

    return EXIT_SUCCESS;

 error:
    return EXIT_FAILURE;
}
