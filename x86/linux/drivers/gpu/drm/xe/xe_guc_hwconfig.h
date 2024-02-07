/* SPDX-License-Identifier: MIT */
/*
 * Copyright © 2022 Intel Corporation
 */

#ifndef _XE_GUC_HWCONFIG_H_
#define _XE_GUC_HWCONFIG_H_

#include <linux/types.h>

struct xe_guc;

int xe_guc_hwconfig_init(struct xe_guc *guc);
u32 xe_guc_hwconfig_size(struct xe_guc *guc);
void xe_guc_hwconfig_copy(struct xe_guc *guc, void *dst);

#endif
