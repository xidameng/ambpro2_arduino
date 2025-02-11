/**
*****************************************************************************************
*     Copyright(c) 2021, Realtek Semiconductor Corporation. All rights reserved.
*****************************************************************************************
  * @file     bt_ipc_dev_trx.h
  * @brief    Source file for bt ipc dev trx.
  * @details  bt ipc dev trx.
  * @author   sherman
  * @date     2021-10-20
  * @version  v1.0
  * *************************************************************************************
  */
#ifndef _BT_IPC_DEV_TRX_H_
#define _BT_IPC_DEV_TRX_H_

/* -------------------------------- Includes -------------------------------- */
#include <stdint.h>
#include "ameba.h"
#include "bt_ipc_profile_config.h"

/* ------------------------------- Data Types ------------------------------- */

/** @brief bt ipc dev trx task private struct */
struct bt_ipc_dev_trx_task_struct {
	void                      *task;	/* I: workqueue thread */
	void                      *wakeup_sema;    /* for internal use only */
	void                      *terminate_sema; /* for internal use only */
	uint32_t                  blocked;          /* for internal use only */
};

typedef struct bt_ipc_dev_tx_message {
    uint32_t    PROFILE_ID;
	uint32_t	TX_EVENT;
	uint32_t	param_buf[30];
	int	        ret[4]; //for multiple return values
	uint8_t     data[1024];//buffer for tx data;
    uint8_t     dummy[48];//add for 64B size alignment
} bt_ipc_dev_tx_message;

/**
 * @brief  to send a ipc message to device and wait result.
 * @param  profile_id[in]: mesh/peripheral/central ...
 * @param  tx_event[in]: BT_DEV_TX_EVENT.
 * @param  param_buf[in]: pointer to tx_event parameter.
 * @param  data[in]: pointer to data.
 * @param  size[in]: data size.
 * @return pointer to result of tx_event.
 */
int *bt_ipc_trx_dev_message_send(uint32_t profile_id, uint32_t tx_event, uint32_t *param_buf, uint32_t buf_len, uint8_t *data, uint32_t size);

/**
 * @brief  to initialize the ipc device for bt api.
 * @param  none.
 * @return none.
 */
void bt_ipc_trx_init_dev(void);

/**
 * @brief  to deinit the ipc device for bt api.
 * @param  none.
 * @return none.
 */
void bt_ipc_trx_deinit_dev(void);

#endif /* _BT_IPC_DEV_TRX_H_ */