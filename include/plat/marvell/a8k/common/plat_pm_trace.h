/*
 * ***************************************************************************
 * Copyright (C) 2016 Marvell International Ltd.
 * ***************************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of Marvell nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ***************************************************************************
 */

#ifndef __PLAT_PM_TRACE_H
#define __PLAT_PM_TRACE_H


/*
 * PM Trace is for Debug purpose only!!!
 * It should not be enabled during System Run time
 */
#undef PM_TRACE_ENABLE


/* trace entry time */
struct pm_trace_entry {
	/* trace entry time stamp */
	unsigned int timestamp;

	/* trace info
	 * [16-31] - API Trace Id
	 * [00-15] - API Step Id
	 */
	unsigned int trace_info;
};

struct pm_trace_ctrl {
	/* trace pointer - points to next free entry in trace cyclic queue */
	unsigned int trace_pointer;

	/* trace count - number of entries in the queue, clear upon read */
	unsigned int trace_count;
};

/* trace size definition */
#define AP_MSS_ATF_CORE_INFO_SIZE		(256)
#define AP_MSS_ATF_CORE_ENTRY_SIZE		(8)
#define AP_MSS_ATF_TRACE_SIZE_MASK		(0xFF)

/* trace address definition */
#define AP_MSS_TIMER_BASE		(MVEBU_REGS_BASE_MASK + 0x580110)

#define AP_MSS_ATF_CORE_0_CTRL_BASE	(MVEBU_REGS_BASE_MASK + 0x522050)
#define AP_MSS_ATF_CORE_1_CTRL_BASE	(MVEBU_REGS_BASE_MASK + 0x522060)
#define AP_MSS_ATF_CORE_2_CTRL_BASE	(MVEBU_REGS_BASE_MASK + 0x522070)
#define AP_MSS_ATF_CORE_3_CTRL_BASE	(MVEBU_REGS_BASE_MASK + 0x522080)
#define AP_MSS_ATF_CORE_CTRL_BASE	(AP_MSS_ATF_CORE_0_CTRL_BASE)

#define AP_MSS_ATF_CORE_0_INFO_BASE	(MVEBU_REGS_BASE_MASK + 0x5220D0)
#define AP_MSS_ATF_CORE_0_INFO_TRACE	(MVEBU_REGS_BASE_MASK + 0x5220D4)
#define AP_MSS_ATF_CORE_1_INFO_BASE	(MVEBU_REGS_BASE_MASK + 0x5228D0)
#define AP_MSS_ATF_CORE_1_INFO_TRACE	(MVEBU_REGS_BASE_MASK + 0x5228D4)
#define AP_MSS_ATF_CORE_2_INFO_BASE	(MVEBU_REGS_BASE_MASK + 0x5230D0)
#define AP_MSS_ATF_CORE_2_INFO_TRACE	(MVEBU_REGS_BASE_MASK + 0x5230D4)
#define AP_MSS_ATF_CORE_3_INFO_BASE	(MVEBU_REGS_BASE_MASK + 0x5238D0)
#define AP_MSS_ATF_CORE_3_INFO_TRACE	(MVEBU_REGS_BASE_MASK + 0x5238D4)
#define AP_MSS_ATF_CORE_INFO_BASE	(AP_MSS_ATF_CORE_0_INFO_BASE)

/* trace info definition */
#define TRACE_PWR_DOMAIN_OFF			(0x10000)
#define TRACE_PWR_DOMAIN_SUSPEND		(0x20000)
#define TRACE_PWR_DOMAIN_SUSPEND_FINISH		(0x30000)
#define TRACE_PWR_DOMAIN_ON			(0x40000)
#define TRACE_PWR_DOMAIN_ON_FINISH		(0x50000)

#define TRACE_PWR_DOMAIN_ON_MASK		(0xFF)

#if defined(SCP_IMAGE) && defined(PM_TRACE_ENABLE)

/* trace API definition */
void pm_core_0_trace(unsigned int trace);
void pm_core_1_trace(unsigned int trace);
void pm_core_2_trace(unsigned int trace);
void pm_core_3_trace(unsigned int trace);

typedef void (*core_trace_func)(unsigned int);

extern core_trace_func funcTbl[PLATFORM_CORE_COUNT];

#else

#define PM_TRACE(trace, core)

#endif

/*******************************************************************************
 * pm_trace_add
 *
 * DESCRIPTION: Add PM trace
 ******************************************************************************
 */
void pm_trace_add(unsigned int trace, unsigned int core);

#endif /* __PLAT_PM_TRACE_H */
