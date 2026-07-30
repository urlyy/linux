/* SPDX-License-Identifier: GPL-2.0 */
#ifndef _LINUX_MD_H
#define _LINUX_MD_H

#include <linux/kconfig.h>
#include <linux/types.h>

struct block_device;

#if IS_BUILTIN(CONFIG_BLK_DEV_MD)
bool md_bdev_is_degraded(struct block_device *bdev);
bool md_bdev_range_is_unavailable(struct block_device *bdev,
				  sector_t sector, sector_t nr_sectors);
u64 md_bdev_availability_generation(struct block_device *bdev);
#else
static inline bool md_bdev_is_degraded(struct block_device *bdev)
{
	return false;
}

static inline bool md_bdev_range_is_unavailable(struct block_device *bdev,
						 sector_t sector,
						 sector_t nr_sectors)
{
	return false;
}

static inline u64 md_bdev_availability_generation(struct block_device *bdev)
{
	return 0;
}
#endif

#endif /* _LINUX_MD_H */
