;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.2
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv_trm.inc

; BLE
BLE_bless_isr__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
BLE_bless_isr__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
BLE_bless_isr__INTC_MASK EQU 0x1000
BLE_bless_isr__INTC_NUMBER EQU 12
BLE_bless_isr__INTC_PRIOR_MASK EQU 0xC0
BLE_bless_isr__INTC_PRIOR_NUM EQU 3
BLE_bless_isr__INTC_PRIOR_REG EQU CYREG_CM0_IPR3
BLE_bless_isr__INTC_SET_EN_REG EQU CYREG_CM0_ISER
BLE_bless_isr__INTC_SET_PD_REG EQU CYREG_CM0_ISPR
BLE_cy_m0s8_ble__ADC_BUMP1 EQU CYREG_BLE_BLERD_ADC_BUMP1
BLE_cy_m0s8_ble__ADC_BUMP2 EQU CYREG_BLE_BLERD_ADC_BUMP2
BLE_cy_m0s8_ble__ADV_CH_TX_POWER EQU CYREG_BLE_BLELL_ADV_CH_TX_POWER
BLE_cy_m0s8_ble__ADV_CONFIG EQU CYREG_BLE_BLELL_ADV_CONFIG
BLE_cy_m0s8_ble__ADV_INTERVAL_TIMEOUT EQU CYREG_BLE_BLELL_ADV_INTERVAL_TIMEOUT
BLE_cy_m0s8_ble__ADV_INTR EQU CYREG_BLE_BLELL_ADV_INTR
BLE_cy_m0s8_ble__ADV_NEXT_INSTANT EQU CYREG_BLE_BLELL_ADV_NEXT_INSTANT
BLE_cy_m0s8_ble__ADV_PARAMS EQU CYREG_BLE_BLELL_ADV_PARAMS
BLE_cy_m0s8_ble__ADV_SCN_RSP_TX_FIFO EQU CYREG_BLE_BLELL_ADV_SCN_RSP_TX_FIFO
BLE_cy_m0s8_ble__ADV_TX_DATA_FIFO EQU CYREG_BLE_BLELL_ADV_TX_DATA_FIFO
BLE_cy_m0s8_ble__AGC EQU CYREG_BLE_BLERD_AGC
BLE_cy_m0s8_ble__BALUN EQU CYREG_BLE_BLERD_BALUN
BLE_cy_m0s8_ble__BB_BUMP1 EQU CYREG_BLE_BLERD_BB_BUMP1
BLE_cy_m0s8_ble__BB_BUMP2 EQU CYREG_BLE_BLERD_BB_BUMP2
BLE_cy_m0s8_ble__BB_XO EQU CYREG_BLE_BLERD_BB_XO
BLE_cy_m0s8_ble__BB_XO_CAPTRIM EQU CYREG_BLE_BLERD_BB_XO_CAPTRIM
BLE_cy_m0s8_ble__CE_CNFG_STS_REGISTER EQU CYREG_BLE_BLELL_CE_CNFG_STS_REGISTER
BLE_cy_m0s8_ble__CE_LENGTH EQU CYREG_BLE_BLELL_CE_LENGTH
BLE_cy_m0s8_ble__CFG_1_FCAL EQU CYREG_BLE_BLERD_CFG_1_FCAL
BLE_cy_m0s8_ble__CFG_2_FCAL EQU CYREG_BLE_BLERD_CFG_2_FCAL
BLE_cy_m0s8_ble__CFG_3_FCAL EQU CYREG_BLE_BLERD_CFG_3_FCAL
BLE_cy_m0s8_ble__CFG_4_FCAL EQU CYREG_BLE_BLERD_CFG_4_FCAL
BLE_cy_m0s8_ble__CFG_5_FCAL EQU CYREG_BLE_BLERD_CFG_5_FCAL
BLE_cy_m0s8_ble__CFG_6_FCAL EQU CYREG_BLE_BLERD_CFG_6_FCAL
BLE_cy_m0s8_ble__CFG1 EQU CYREG_BLE_BLERD_CFG1
BLE_cy_m0s8_ble__CFG2 EQU CYREG_BLE_BLERD_CFG2
BLE_cy_m0s8_ble__CFGCTRL EQU CYREG_BLE_BLERD_CFGCTRL
BLE_cy_m0s8_ble__CLOCK_CONFIG EQU CYREG_BLE_BLELL_CLOCK_CONFIG
BLE_cy_m0s8_ble__COMMAND_REGISTER EQU CYREG_BLE_BLELL_COMMAND_REGISTER
BLE_cy_m0s8_ble__CONN_CE_COUNTER EQU CYREG_BLE_BLELL_CONN_CE_COUNTER
BLE_cy_m0s8_ble__CONN_CE_INSTANT EQU CYREG_BLE_BLELL_CONN_CE_INSTANT
BLE_cy_m0s8_ble__CONN_CH_TX_POWER EQU CYREG_BLE_BLELL_CONN_CH_TX_POWER
BLE_cy_m0s8_ble__CONN_CONFIG EQU CYREG_BLE_BLELL_CONN_CONFIG
BLE_cy_m0s8_ble__CONN_INDEX EQU CYREG_BLE_BLELL_CONN_INDEX
BLE_cy_m0s8_ble__CONN_INTERVAL EQU CYREG_BLE_BLELL_CONN_INTERVAL
BLE_cy_m0s8_ble__CONN_INTR EQU CYREG_BLE_BLELL_CONN_INTR
BLE_cy_m0s8_ble__CONN_INTR_MASK EQU CYREG_BLE_BLELL_CONN_INTR_MASK
BLE_cy_m0s8_ble__CONN_PARAM1 EQU CYREG_BLE_BLELL_CONN_PARAM1
BLE_cy_m0s8_ble__CONN_PARAM2 EQU CYREG_BLE_BLELL_CONN_PARAM2
BLE_cy_m0s8_ble__CONN_REQ_WORD0 EQU CYREG_BLE_BLELL_CONN_REQ_WORD0
BLE_cy_m0s8_ble__CONN_REQ_WORD1 EQU CYREG_BLE_BLELL_CONN_REQ_WORD1
BLE_cy_m0s8_ble__CONN_REQ_WORD10 EQU CYREG_BLE_BLELL_CONN_REQ_WORD10
BLE_cy_m0s8_ble__CONN_REQ_WORD11 EQU CYREG_BLE_BLELL_CONN_REQ_WORD11
BLE_cy_m0s8_ble__CONN_REQ_WORD2 EQU CYREG_BLE_BLELL_CONN_REQ_WORD2
BLE_cy_m0s8_ble__CONN_REQ_WORD3 EQU CYREG_BLE_BLELL_CONN_REQ_WORD3
BLE_cy_m0s8_ble__CONN_REQ_WORD4 EQU CYREG_BLE_BLELL_CONN_REQ_WORD4
BLE_cy_m0s8_ble__CONN_REQ_WORD5 EQU CYREG_BLE_BLELL_CONN_REQ_WORD5
BLE_cy_m0s8_ble__CONN_REQ_WORD6 EQU CYREG_BLE_BLELL_CONN_REQ_WORD6
BLE_cy_m0s8_ble__CONN_REQ_WORD7 EQU CYREG_BLE_BLELL_CONN_REQ_WORD7
BLE_cy_m0s8_ble__CONN_REQ_WORD8 EQU CYREG_BLE_BLELL_CONN_REQ_WORD8
BLE_cy_m0s8_ble__CONN_REQ_WORD9 EQU CYREG_BLE_BLELL_CONN_REQ_WORD9
BLE_cy_m0s8_ble__CONN_RXMEM_BASE_ADDR EQU CYREG_BLE_BLELL_CONN_RXMEM_BASE_ADDR
BLE_cy_m0s8_ble__CONN_STATUS EQU CYREG_BLE_BLELL_CONN_STATUS
BLE_cy_m0s8_ble__CONN_TXMEM_BASE_ADDR EQU CYREG_BLE_BLELL_CONN_TXMEM_BASE_ADDR
BLE_cy_m0s8_ble__CONN_UPDATE_NEW_INTERVAL EQU CYREG_BLE_BLELL_CONN_UPDATE_NEW_INTERVAL
BLE_cy_m0s8_ble__CONN_UPDATE_NEW_LATENCY EQU CYREG_BLE_BLELL_CONN_UPDATE_NEW_LATENCY
BLE_cy_m0s8_ble__CONN_UPDATE_NEW_SL_INTERVAL EQU CYREG_BLE_BLELL_CONN_UPDATE_NEW_SL_INTERVAL
BLE_cy_m0s8_ble__CONN_UPDATE_NEW_SUP_TO EQU CYREG_BLE_BLELL_CONN_UPDATE_NEW_SUP_TO
BLE_cy_m0s8_ble__CTR1 EQU CYREG_BLE_BLERD_CTR1
BLE_cy_m0s8_ble__DATA_CHANNELS_H0 EQU CYREG_BLE_BLELL_DATA_CHANNELS_H0
BLE_cy_m0s8_ble__DATA_CHANNELS_H1 EQU CYREG_BLE_BLELL_DATA_CHANNELS_H1
BLE_cy_m0s8_ble__DATA_CHANNELS_L0 EQU CYREG_BLE_BLELL_DATA_CHANNELS_L0
BLE_cy_m0s8_ble__DATA_CHANNELS_L1 EQU CYREG_BLE_BLELL_DATA_CHANNELS_L1
BLE_cy_m0s8_ble__DATA_CHANNELS_M0 EQU CYREG_BLE_BLELL_DATA_CHANNELS_M0
BLE_cy_m0s8_ble__DATA_CHANNELS_M1 EQU CYREG_BLE_BLELL_DATA_CHANNELS_M1
BLE_cy_m0s8_ble__DATA_LIST_ACK_UPDATE__STATUS EQU CYREG_BLE_BLELL_DATA_LIST_ACK_UPDATE__STATUS
BLE_cy_m0s8_ble__DATA_LIST_SENT_UPDATE__STATUS EQU CYREG_BLE_BLELL_DATA_LIST_SENT_UPDATE__STATUS
BLE_cy_m0s8_ble__DATA_MEM_DESCRIPTOR0 EQU CYREG_BLE_BLELL_DATA_MEM_DESCRIPTOR0
BLE_cy_m0s8_ble__DATA_MEM_DESCRIPTOR1 EQU CYREG_BLE_BLELL_DATA_MEM_DESCRIPTOR1
BLE_cy_m0s8_ble__DATA_MEM_DESCRIPTOR2 EQU CYREG_BLE_BLELL_DATA_MEM_DESCRIPTOR2
BLE_cy_m0s8_ble__DATA_MEM_DESCRIPTOR3 EQU CYREG_BLE_BLELL_DATA_MEM_DESCRIPTOR3
BLE_cy_m0s8_ble__DATA_MEM_DESCRIPTOR4 EQU CYREG_BLE_BLELL_DATA_MEM_DESCRIPTOR4
BLE_cy_m0s8_ble__DATA0 EQU CYREG_BLE_BLELL_DATA0
BLE_cy_m0s8_ble__DATA1 EQU CYREG_BLE_BLELL_DATA1
BLE_cy_m0s8_ble__DATA10 EQU CYREG_BLE_BLELL_DATA10
BLE_cy_m0s8_ble__DATA11 EQU CYREG_BLE_BLELL_DATA11
BLE_cy_m0s8_ble__DATA12 EQU CYREG_BLE_BLELL_DATA12
BLE_cy_m0s8_ble__DATA13 EQU CYREG_BLE_BLELL_DATA13
BLE_cy_m0s8_ble__DATA2 EQU CYREG_BLE_BLELL_DATA2
BLE_cy_m0s8_ble__DATA3 EQU CYREG_BLE_BLELL_DATA3
BLE_cy_m0s8_ble__DATA4 EQU CYREG_BLE_BLELL_DATA4
BLE_cy_m0s8_ble__DATA5 EQU CYREG_BLE_BLELL_DATA5
BLE_cy_m0s8_ble__DATA6 EQU CYREG_BLE_BLELL_DATA6
BLE_cy_m0s8_ble__DATA7 EQU CYREG_BLE_BLELL_DATA7
BLE_cy_m0s8_ble__DATA8 EQU CYREG_BLE_BLELL_DATA8
BLE_cy_m0s8_ble__DATA9 EQU CYREG_BLE_BLELL_DATA9
BLE_cy_m0s8_ble__DBG_1 EQU CYREG_BLE_BLERD_DBG_1
BLE_cy_m0s8_ble__DBG_2 EQU CYREG_BLE_BLERD_DBG_2
BLE_cy_m0s8_ble__DBG_3 EQU CYREG_BLE_BLERD_DBG_3
BLE_cy_m0s8_ble__DBG_BB EQU CYREG_BLE_BLERD_DBG_BB
BLE_cy_m0s8_ble__DBUS EQU CYREG_BLE_BLERD_DBUS
BLE_cy_m0s8_ble__DC EQU CYREG_BLE_BLERD_DC
BLE_cy_m0s8_ble__DCCAL EQU CYREG_BLE_BLERD_DCCAL
BLE_cy_m0s8_ble__DEV_PUB_ADDR_H EQU CYREG_BLE_BLELL_DEV_PUB_ADDR_H
BLE_cy_m0s8_ble__DEV_PUB_ADDR_L EQU CYREG_BLE_BLELL_DEV_PUB_ADDR_L
BLE_cy_m0s8_ble__DEV_PUB_ADDR_M EQU CYREG_BLE_BLELL_DEV_PUB_ADDR_M
BLE_cy_m0s8_ble__DEVICE_RAND_ADDR_H EQU CYREG_BLE_BLELL_DEVICE_RAND_ADDR_H
BLE_cy_m0s8_ble__DEVICE_RAND_ADDR_L EQU CYREG_BLE_BLELL_DEVICE_RAND_ADDR_L
BLE_cy_m0s8_ble__DEVICE_RAND_ADDR_M EQU CYREG_BLE_BLELL_DEVICE_RAND_ADDR_M
BLE_cy_m0s8_ble__DIAG1 EQU CYREG_BLE_BLERD_DIAG1
BLE_cy_m0s8_ble__DPLL_CONFIG EQU CYREG_BLE_BLELL_DPLL_CONFIG
BLE_cy_m0s8_ble__DSM1 EQU CYREG_BLE_BLERD_DSM1
BLE_cy_m0s8_ble__DSM2 EQU CYREG_BLE_BLERD_DSM2
BLE_cy_m0s8_ble__DSM3 EQU CYREG_BLE_BLERD_DSM3
BLE_cy_m0s8_ble__DSM4 EQU CYREG_BLE_BLERD_DSM4
BLE_cy_m0s8_ble__DSM5 EQU CYREG_BLE_BLERD_DSM5
BLE_cy_m0s8_ble__DSM6 EQU CYREG_BLE_BLERD_DSM6
BLE_cy_m0s8_ble__DTM_RX_PKT_COUNT EQU CYREG_BLE_BLELL_DTM_RX_PKT_COUNT
BLE_cy_m0s8_ble__ENC_CONFIG EQU CYREG_BLE_BLELL_ENC_CONFIG
BLE_cy_m0s8_ble__ENC_INTR EQU CYREG_BLE_BLELL_ENC_INTR
BLE_cy_m0s8_ble__ENC_INTR_EN EQU CYREG_BLE_BLELL_ENC_INTR_EN
BLE_cy_m0s8_ble__ENC_KEY0 EQU CYREG_BLE_BLELL_ENC_KEY0
BLE_cy_m0s8_ble__ENC_KEY1 EQU CYREG_BLE_BLELL_ENC_KEY1
BLE_cy_m0s8_ble__ENC_KEY2 EQU CYREG_BLE_BLELL_ENC_KEY2
BLE_cy_m0s8_ble__ENC_KEY3 EQU CYREG_BLE_BLELL_ENC_KEY3
BLE_cy_m0s8_ble__ENC_KEY4 EQU CYREG_BLE_BLELL_ENC_KEY4
BLE_cy_m0s8_ble__ENC_KEY5 EQU CYREG_BLE_BLELL_ENC_KEY5
BLE_cy_m0s8_ble__ENC_KEY6 EQU CYREG_BLE_BLELL_ENC_KEY6
BLE_cy_m0s8_ble__ENC_KEY7 EQU CYREG_BLE_BLELL_ENC_KEY7
BLE_cy_m0s8_ble__ENC_PARAMS EQU CYREG_BLE_BLELL_ENC_PARAMS
BLE_cy_m0s8_ble__EVENT_ENABLE EQU CYREG_BLE_BLELL_EVENT_ENABLE
BLE_cy_m0s8_ble__EVENT_INTR EQU CYREG_BLE_BLELL_EVENT_INTR
BLE_cy_m0s8_ble__FCAL_TEST EQU CYREG_BLE_BLERD_FCAL_TEST
BLE_cy_m0s8_ble__FPD_TEST EQU CYREG_BLE_BLERD_FPD_TEST
BLE_cy_m0s8_ble__FSM EQU CYREG_BLE_BLERD_FSM
BLE_cy_m0s8_ble__IM EQU CYREG_BLE_BLERD_IM
BLE_cy_m0s8_ble__INIT_CONFIG EQU CYREG_BLE_BLELL_INIT_CONFIG
BLE_cy_m0s8_ble__INIT_INTERVAL EQU CYREG_BLE_BLELL_INIT_INTERVAL
BLE_cy_m0s8_ble__INIT_INTR EQU CYREG_BLE_BLELL_INIT_INTR
BLE_cy_m0s8_ble__INIT_NEXT_INSTANT EQU CYREG_BLE_BLELL_INIT_NEXT_INSTANT
BLE_cy_m0s8_ble__INIT_PARAM EQU CYREG_BLE_BLELL_INIT_PARAM
BLE_cy_m0s8_ble__INIT_SCN_ADV_RX_FIFO EQU CYREG_BLE_BLELL_INIT_SCN_ADV_RX_FIFO
BLE_cy_m0s8_ble__INIT_WINDOW EQU CYREG_BLE_BLELL_INIT_WINDOW
BLE_cy_m0s8_ble__IQMIS EQU CYREG_BLE_BLERD_IQMIS
BLE_cy_m0s8_ble__IV_MASTER0 EQU CYREG_BLE_BLELL_IV_MASTER0
BLE_cy_m0s8_ble__IV_MASTER1 EQU CYREG_BLE_BLELL_IV_MASTER1
BLE_cy_m0s8_ble__IV_SLAVE0 EQU CYREG_BLE_BLELL_IV_SLAVE0
BLE_cy_m0s8_ble__IV_SLAVE1 EQU CYREG_BLE_BLELL_IV_SLAVE1
BLE_cy_m0s8_ble__KVCAL EQU CYREG_BLE_BLERD_KVCAL
BLE_cy_m0s8_ble__LDO EQU CYREG_BLE_BLERD_LDO
BLE_cy_m0s8_ble__LDO_BYPASS EQU CYREG_BLE_BLERD_LDO_BYPASS
BLE_cy_m0s8_ble__LE_PING_TIMER_ADDR EQU CYREG_BLE_BLELL_LE_PING_TIMER_ADDR
BLE_cy_m0s8_ble__LE_PING_TIMER_NEXT_EXP EQU CYREG_BLE_BLELL_LE_PING_TIMER_NEXT_EXP
BLE_cy_m0s8_ble__LE_PING_TIMER_OFFSET EQU CYREG_BLE_BLELL_LE_PING_TIMER_OFFSET
BLE_cy_m0s8_ble__LE_PING_TIMER_WRAP_COUNT EQU CYREG_BLE_BLELL_LE_PING_TIMER_WRAP_COUNT
BLE_cy_m0s8_ble__LE_RF_TEST_MODE EQU CYREG_BLE_BLELL_LE_RF_TEST_MODE
BLE_cy_m0s8_ble__LF_CLK_CTRL EQU CYREG_BLE_BLESS_LF_CLK_CTRL
BLE_cy_m0s8_ble__LL_CLK_EN EQU CYREG_BLE_BLESS_LL_CLK_EN
BLE_cy_m0s8_ble__LL_DSM_CTRL EQU CYREG_BLE_BLESS_LL_DSM_CTRL
BLE_cy_m0s8_ble__LL_DSM_INTR_STAT EQU CYREG_BLE_BLESS_LL_DSM_INTR_STAT
BLE_cy_m0s8_ble__LLH_FEATURE_CONFIG EQU CYREG_BLE_BLELL_LLH_FEATURE_CONFIG
BLE_cy_m0s8_ble__MIC_IN0 EQU CYREG_BLE_BLELL_MIC_IN0
BLE_cy_m0s8_ble__MIC_IN1 EQU CYREG_BLE_BLELL_MIC_IN1
BLE_cy_m0s8_ble__MIC_OUT0 EQU CYREG_BLE_BLELL_MIC_OUT0
BLE_cy_m0s8_ble__MIC_OUT1 EQU CYREG_BLE_BLELL_MIC_OUT1
BLE_cy_m0s8_ble__MODEM EQU CYREG_BLE_BLERD_MODEM
BLE_cy_m0s8_ble__MONI EQU CYREG_BLE_BLERD_MONI
BLE_cy_m0s8_ble__NEXT_CE_INSTANT EQU CYREG_BLE_BLELL_NEXT_CE_INSTANT
BLE_cy_m0s8_ble__NEXT_RESP_TIMER_EXP EQU CYREG_BLE_BLELL_NEXT_RESP_TIMER_EXP
BLE_cy_m0s8_ble__NEXT_SUP_TO EQU CYREG_BLE_BLELL_NEXT_SUP_TO
BLE_cy_m0s8_ble__OFFSET_TO_FIRST_INSTANT EQU CYREG_BLE_BLELL_OFFSET_TO_FIRST_INSTANT
BLE_cy_m0s8_ble__PACKET_COUNTER0 EQU CYREG_BLE_BLELL_PACKET_COUNTER0
BLE_cy_m0s8_ble__PACKET_COUNTER1 EQU CYREG_BLE_BLELL_PACKET_COUNTER1
BLE_cy_m0s8_ble__PACKET_COUNTER2 EQU CYREG_BLE_BLELL_PACKET_COUNTER2
BLE_cy_m0s8_ble__PDU_ACCESS_ADDR_H_REGISTER EQU CYREG_BLE_BLELL_PDU_ACCESS_ADDR_H_REGISTER
BLE_cy_m0s8_ble__PDU_ACCESS_ADDR_L_REGISTER EQU CYREG_BLE_BLELL_PDU_ACCESS_ADDR_L_REGISTER
BLE_cy_m0s8_ble__PDU_RESP_TIMER EQU CYREG_BLE_BLELL_PDU_RESP_TIMER
BLE_cy_m0s8_ble__PEER_ADDR_H EQU CYREG_BLE_BLELL_PEER_ADDR_H
BLE_cy_m0s8_ble__PEER_ADDR_L EQU CYREG_BLE_BLELL_PEER_ADDR_L
BLE_cy_m0s8_ble__PEER_ADDR_M EQU CYREG_BLE_BLELL_PEER_ADDR_M
BLE_cy_m0s8_ble__POC_REG__TIM_CONTROL EQU CYREG_BLE_BLELL_POC_REG__TIM_CONTROL
BLE_cy_m0s8_ble__RCCAL EQU CYREG_BLE_BLERD_RCCAL
BLE_cy_m0s8_ble__READ_IQ_1 EQU CYREG_BLE_BLERD_READ_IQ_1
BLE_cy_m0s8_ble__READ_IQ_2 EQU CYREG_BLE_BLERD_READ_IQ_2
BLE_cy_m0s8_ble__READ_IQ_3 EQU CYREG_BLE_BLERD_READ_IQ_3
BLE_cy_m0s8_ble__READ_IQ_4 EQU CYREG_BLE_BLERD_READ_IQ_4
BLE_cy_m0s8_ble__RECEIVE_TRIG_CTRL EQU CYREG_BLE_BLELL_RECEIVE_TRIG_CTRL
BLE_cy_m0s8_ble__RF_CONFIG EQU CYREG_BLE_BLESS_RF_CONFIG
BLE_cy_m0s8_ble__RMAP EQU CYREG_BLE_BLERD_RMAP
BLE_cy_m0s8_ble__RSSI EQU CYREG_BLE_BLERD_RSSI
BLE_cy_m0s8_ble__RX EQU CYREG_BLE_BLERD_RX
BLE_cy_m0s8_ble__RX_BUMP1 EQU CYREG_BLE_BLERD_RX_BUMP1
BLE_cy_m0s8_ble__RX_BUMP2 EQU CYREG_BLE_BLERD_RX_BUMP2
BLE_cy_m0s8_ble__SCAN_CONFIG EQU CYREG_BLE_BLELL_SCAN_CONFIG
BLE_cy_m0s8_ble__SCAN_INTERVAL EQU CYREG_BLE_BLELL_SCAN_INTERVAL
BLE_cy_m0s8_ble__SCAN_INTR EQU CYREG_BLE_BLELL_SCAN_INTR
BLE_cy_m0s8_ble__SCAN_NEXT_INSTANT EQU CYREG_BLE_BLELL_SCAN_NEXT_INSTANT
BLE_cy_m0s8_ble__SCAN_PARAM EQU CYREG_BLE_BLELL_SCAN_PARAM
BLE_cy_m0s8_ble__SCAN_WINDOW EQU CYREG_BLE_BLELL_SCAN_WINDOW
BLE_cy_m0s8_ble__SL_CONN_INTERVAL EQU CYREG_BLE_BLELL_SL_CONN_INTERVAL
BLE_cy_m0s8_ble__SLAVE_LATENCY EQU CYREG_BLE_BLELL_SLAVE_LATENCY
BLE_cy_m0s8_ble__SLAVE_TIMING_CONTROL EQU CYREG_BLE_BLELL_SLAVE_TIMING_CONTROL
BLE_cy_m0s8_ble__SLV_WIN_ADJ EQU CYREG_BLE_BLELL_SLV_WIN_ADJ
BLE_cy_m0s8_ble__SUP_TIMEOUT EQU CYREG_BLE_BLELL_SUP_TIMEOUT
BLE_cy_m0s8_ble__SY EQU CYREG_BLE_BLERD_SY
BLE_cy_m0s8_ble__SY_BUMP1 EQU CYREG_BLE_BLERD_SY_BUMP1
BLE_cy_m0s8_ble__SY_BUMP2 EQU CYREG_BLE_BLERD_SY_BUMP2
BLE_cy_m0s8_ble__TEST EQU CYREG_BLE_BLERD_TEST
BLE_cy_m0s8_ble__TEST2_SY EQU CYREG_BLE_BLERD_TEST2_SY
BLE_cy_m0s8_ble__THRSHD1 EQU CYREG_BLE_BLERD_THRSHD1
BLE_cy_m0s8_ble__THRSHD2 EQU CYREG_BLE_BLERD_THRSHD2
BLE_cy_m0s8_ble__THRSHD3 EQU CYREG_BLE_BLERD_THRSHD3
BLE_cy_m0s8_ble__THRSHD4 EQU CYREG_BLE_BLERD_THRSHD4
BLE_cy_m0s8_ble__THRSHD5 EQU CYREG_BLE_BLERD_THRSHD5
BLE_cy_m0s8_ble__TIM_COUNTER_L EQU CYREG_BLE_BLELL_TIM_COUNTER_L
BLE_cy_m0s8_ble__TRANSMIT_WINDOW_OFFSET EQU CYREG_BLE_BLELL_TRANSMIT_WINDOW_OFFSET
BLE_cy_m0s8_ble__TRANSMIT_WINDOW_SIZE EQU CYREG_BLE_BLELL_TRANSMIT_WINDOW_SIZE
BLE_cy_m0s8_ble__TX EQU CYREG_BLE_BLERD_TX
BLE_cy_m0s8_ble__TX_BUMP1 EQU CYREG_BLE_BLERD_TX_BUMP1
BLE_cy_m0s8_ble__TX_BUMP2 EQU CYREG_BLE_BLERD_TX_BUMP2
BLE_cy_m0s8_ble__TX_EN_EXT_DELAY EQU CYREG_BLE_BLELL_TX_EN_EXT_DELAY
BLE_cy_m0s8_ble__TX_RX_ON_DELAY EQU CYREG_BLE_BLELL_TX_RX_ON_DELAY
BLE_cy_m0s8_ble__TX_RX_SYNTH_DELAY EQU CYREG_BLE_BLELL_TX_RX_SYNTH_DELAY
BLE_cy_m0s8_ble__TXRX_HOP EQU CYREG_BLE_BLELL_TXRX_HOP
BLE_cy_m0s8_ble__WAKEUP_CONFIG EQU CYREG_BLE_BLELL_WAKEUP_CONFIG
BLE_cy_m0s8_ble__WAKEUP_CONTROL EQU CYREG_BLE_BLELL_WAKEUP_CONTROL
BLE_cy_m0s8_ble__WCO_CONFIG EQU CYREG_BLE_BLESS_WCO_CONFIG
BLE_cy_m0s8_ble__WCO_STATUS EQU CYREG_BLE_BLESS_WCO_STATUS
BLE_cy_m0s8_ble__WCO_TRIM EQU CYREG_BLE_BLESS_WCO_TRIM
BLE_cy_m0s8_ble__WHITELIST_BASE_ADDR EQU CYREG_BLE_BLELL_WHITELIST_BASE_ADDR
BLE_cy_m0s8_ble__WIN_MIN_STEP_SIZE EQU CYREG_BLE_BLELL_WIN_MIN_STEP_SIZE
BLE_cy_m0s8_ble__WINDOW_WIDEN_INTVL EQU CYREG_BLE_BLELL_WINDOW_WIDEN_INTVL
BLE_cy_m0s8_ble__WINDOW_WIDEN_WINOFF EQU CYREG_BLE_BLELL_WINDOW_WIDEN_WINOFF
BLE_cy_m0s8_ble__WL_ADDR_TYPE EQU CYREG_BLE_BLELL_WL_ADDR_TYPE
BLE_cy_m0s8_ble__WL_ENABLE EQU CYREG_BLE_BLELL_WL_ENABLE
BLE_cy_m0s8_ble__XTAL_CLK_DIV_CONFIG EQU CYREG_BLE_BLESS_XTAL_CLK_DIV_CONFIG

; I2C
I2C_SCB__CTRL EQU CYREG_SCB0_CTRL
I2C_SCB__EZ_DATA0 EQU CYREG_SCB0_EZ_DATA0
I2C_SCB__EZ_DATA1 EQU CYREG_SCB0_EZ_DATA1
I2C_SCB__EZ_DATA10 EQU CYREG_SCB0_EZ_DATA10
I2C_SCB__EZ_DATA11 EQU CYREG_SCB0_EZ_DATA11
I2C_SCB__EZ_DATA12 EQU CYREG_SCB0_EZ_DATA12
I2C_SCB__EZ_DATA13 EQU CYREG_SCB0_EZ_DATA13
I2C_SCB__EZ_DATA14 EQU CYREG_SCB0_EZ_DATA14
I2C_SCB__EZ_DATA15 EQU CYREG_SCB0_EZ_DATA15
I2C_SCB__EZ_DATA16 EQU CYREG_SCB0_EZ_DATA16
I2C_SCB__EZ_DATA17 EQU CYREG_SCB0_EZ_DATA17
I2C_SCB__EZ_DATA18 EQU CYREG_SCB0_EZ_DATA18
I2C_SCB__EZ_DATA19 EQU CYREG_SCB0_EZ_DATA19
I2C_SCB__EZ_DATA2 EQU CYREG_SCB0_EZ_DATA2
I2C_SCB__EZ_DATA20 EQU CYREG_SCB0_EZ_DATA20
I2C_SCB__EZ_DATA21 EQU CYREG_SCB0_EZ_DATA21
I2C_SCB__EZ_DATA22 EQU CYREG_SCB0_EZ_DATA22
I2C_SCB__EZ_DATA23 EQU CYREG_SCB0_EZ_DATA23
I2C_SCB__EZ_DATA24 EQU CYREG_SCB0_EZ_DATA24
I2C_SCB__EZ_DATA25 EQU CYREG_SCB0_EZ_DATA25
I2C_SCB__EZ_DATA26 EQU CYREG_SCB0_EZ_DATA26
I2C_SCB__EZ_DATA27 EQU CYREG_SCB0_EZ_DATA27
I2C_SCB__EZ_DATA28 EQU CYREG_SCB0_EZ_DATA28
I2C_SCB__EZ_DATA29 EQU CYREG_SCB0_EZ_DATA29
I2C_SCB__EZ_DATA3 EQU CYREG_SCB0_EZ_DATA3
I2C_SCB__EZ_DATA30 EQU CYREG_SCB0_EZ_DATA30
I2C_SCB__EZ_DATA31 EQU CYREG_SCB0_EZ_DATA31
I2C_SCB__EZ_DATA4 EQU CYREG_SCB0_EZ_DATA4
I2C_SCB__EZ_DATA5 EQU CYREG_SCB0_EZ_DATA5
I2C_SCB__EZ_DATA6 EQU CYREG_SCB0_EZ_DATA6
I2C_SCB__EZ_DATA7 EQU CYREG_SCB0_EZ_DATA7
I2C_SCB__EZ_DATA8 EQU CYREG_SCB0_EZ_DATA8
I2C_SCB__EZ_DATA9 EQU CYREG_SCB0_EZ_DATA9
I2C_SCB__I2C_CFG EQU CYREG_SCB0_I2C_CFG
I2C_SCB__I2C_CTRL EQU CYREG_SCB0_I2C_CTRL
I2C_SCB__I2C_M_CMD EQU CYREG_SCB0_I2C_M_CMD
I2C_SCB__I2C_S_CMD EQU CYREG_SCB0_I2C_S_CMD
I2C_SCB__I2C_STATUS EQU CYREG_SCB0_I2C_STATUS
I2C_SCB__INTR_CAUSE EQU CYREG_SCB0_INTR_CAUSE
I2C_SCB__INTR_I2C_EC EQU CYREG_SCB0_INTR_I2C_EC
I2C_SCB__INTR_I2C_EC_MASK EQU CYREG_SCB0_INTR_I2C_EC_MASK
I2C_SCB__INTR_I2C_EC_MASKED EQU CYREG_SCB0_INTR_I2C_EC_MASKED
I2C_SCB__INTR_M EQU CYREG_SCB0_INTR_M
I2C_SCB__INTR_M_MASK EQU CYREG_SCB0_INTR_M_MASK
I2C_SCB__INTR_M_MASKED EQU CYREG_SCB0_INTR_M_MASKED
I2C_SCB__INTR_M_SET EQU CYREG_SCB0_INTR_M_SET
I2C_SCB__INTR_RX EQU CYREG_SCB0_INTR_RX
I2C_SCB__INTR_RX_MASK EQU CYREG_SCB0_INTR_RX_MASK
I2C_SCB__INTR_RX_MASKED EQU CYREG_SCB0_INTR_RX_MASKED
I2C_SCB__INTR_RX_SET EQU CYREG_SCB0_INTR_RX_SET
I2C_SCB__INTR_S EQU CYREG_SCB0_INTR_S
I2C_SCB__INTR_S_MASK EQU CYREG_SCB0_INTR_S_MASK
I2C_SCB__INTR_S_MASKED EQU CYREG_SCB0_INTR_S_MASKED
I2C_SCB__INTR_S_SET EQU CYREG_SCB0_INTR_S_SET
I2C_SCB__INTR_SPI_EC EQU CYREG_SCB0_INTR_SPI_EC
I2C_SCB__INTR_SPI_EC_MASK EQU CYREG_SCB0_INTR_SPI_EC_MASK
I2C_SCB__INTR_SPI_EC_MASKED EQU CYREG_SCB0_INTR_SPI_EC_MASKED
I2C_SCB__INTR_TX EQU CYREG_SCB0_INTR_TX
I2C_SCB__INTR_TX_MASK EQU CYREG_SCB0_INTR_TX_MASK
I2C_SCB__INTR_TX_MASKED EQU CYREG_SCB0_INTR_TX_MASKED
I2C_SCB__INTR_TX_SET EQU CYREG_SCB0_INTR_TX_SET
I2C_SCB__RX_CTRL EQU CYREG_SCB0_RX_CTRL
I2C_SCB__RX_FIFO_CTRL EQU CYREG_SCB0_RX_FIFO_CTRL
I2C_SCB__RX_FIFO_RD EQU CYREG_SCB0_RX_FIFO_RD
I2C_SCB__RX_FIFO_RD_SILENT EQU CYREG_SCB0_RX_FIFO_RD_SILENT
I2C_SCB__RX_FIFO_STATUS EQU CYREG_SCB0_RX_FIFO_STATUS
I2C_SCB__RX_MATCH EQU CYREG_SCB0_RX_MATCH
I2C_SCB__SPI_CTRL EQU CYREG_SCB0_SPI_CTRL
I2C_SCB__SPI_STATUS EQU CYREG_SCB0_SPI_STATUS
I2C_SCB__SS0_POSISTION EQU 0
I2C_SCB__SS1_POSISTION EQU 1
I2C_SCB__SS2_POSISTION EQU 2
I2C_SCB__SS3_POSISTION EQU 3
I2C_SCB__STATUS EQU CYREG_SCB0_STATUS
I2C_SCB__TX_CTRL EQU CYREG_SCB0_TX_CTRL
I2C_SCB__TX_FIFO_CTRL EQU CYREG_SCB0_TX_FIFO_CTRL
I2C_SCB__TX_FIFO_STATUS EQU CYREG_SCB0_TX_FIFO_STATUS
I2C_SCB__TX_FIFO_WR EQU CYREG_SCB0_TX_FIFO_WR
I2C_SCB__UART_CTRL EQU CYREG_SCB0_UART_CTRL
I2C_SCB__UART_FLOW_CTRL EQU CYREG_SCB0_UART_FLOW_CTRL
I2C_SCB__UART_RX_CTRL EQU CYREG_SCB0_UART_RX_CTRL
I2C_SCB__UART_RX_STATUS EQU CYREG_SCB0_UART_RX_STATUS
I2C_SCB__UART_TX_CTRL EQU CYREG_SCB0_UART_TX_CTRL
I2C_SCB_IRQ__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
I2C_SCB_IRQ__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
I2C_SCB_IRQ__INTC_MASK EQU 0x200
I2C_SCB_IRQ__INTC_NUMBER EQU 9
I2C_SCB_IRQ__INTC_PRIOR_MASK EQU 0xC000
I2C_SCB_IRQ__INTC_PRIOR_NUM EQU 3
I2C_SCB_IRQ__INTC_PRIOR_REG EQU CYREG_CM0_IPR2
I2C_SCB_IRQ__INTC_SET_EN_REG EQU CYREG_CM0_ISER
I2C_SCB_IRQ__INTC_SET_PD_REG EQU CYREG_CM0_ISPR
I2C_SCBCLK__CTRL_REGISTER EQU CYREG_PERI_PCLK_CTL1
I2C_SCBCLK__DIV_ID EQU 0x00000040
I2C_SCBCLK__DIV_REGISTER EQU CYREG_PERI_DIV_16_CTL0
I2C_SCBCLK__PA_DIV_ID EQU 0x000000FF
I2C_scl__0__DR EQU CYREG_GPIO_PRT1_DR
I2C_scl__0__DR_CLR EQU CYREG_GPIO_PRT1_DR_CLR
I2C_scl__0__DR_INV EQU CYREG_GPIO_PRT1_DR_INV
I2C_scl__0__DR_SET EQU CYREG_GPIO_PRT1_DR_SET
I2C_scl__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
I2C_scl__0__HSIOM_GPIO EQU 0
I2C_scl__0__HSIOM_I2C EQU 14
I2C_scl__0__HSIOM_I2C_SCL EQU 14
I2C_scl__0__HSIOM_MASK EQU 0x00F00000
I2C_scl__0__HSIOM_SHIFT EQU 20
I2C_scl__0__HSIOM_SPI EQU 15
I2C_scl__0__HSIOM_SPI_MISO EQU 15
I2C_scl__0__HSIOM_UART EQU 9
I2C_scl__0__HSIOM_UART_TX EQU 9
I2C_scl__0__INTCFG EQU CYREG_GPIO_PRT1_INTR_CFG
I2C_scl__0__INTR EQU CYREG_GPIO_PRT1_INTR
I2C_scl__0__INTR_CFG EQU CYREG_GPIO_PRT1_INTR_CFG
I2C_scl__0__INTSTAT EQU CYREG_GPIO_PRT1_INTR
I2C_scl__0__MASK EQU 0x20
I2C_scl__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
I2C_scl__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
I2C_scl__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
I2C_scl__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
I2C_scl__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
I2C_scl__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
I2C_scl__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
I2C_scl__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
I2C_scl__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
I2C_scl__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
I2C_scl__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
I2C_scl__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
I2C_scl__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
I2C_scl__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
I2C_scl__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
I2C_scl__0__PC EQU CYREG_GPIO_PRT1_PC
I2C_scl__0__PC2 EQU CYREG_GPIO_PRT1_PC2
I2C_scl__0__PORT EQU 1
I2C_scl__0__PS EQU CYREG_GPIO_PRT1_PS
I2C_scl__0__SHIFT EQU 5
I2C_scl__DR EQU CYREG_GPIO_PRT1_DR
I2C_scl__DR_CLR EQU CYREG_GPIO_PRT1_DR_CLR
I2C_scl__DR_INV EQU CYREG_GPIO_PRT1_DR_INV
I2C_scl__DR_SET EQU CYREG_GPIO_PRT1_DR_SET
I2C_scl__INTCFG EQU CYREG_GPIO_PRT1_INTR_CFG
I2C_scl__INTR EQU CYREG_GPIO_PRT1_INTR
I2C_scl__INTR_CFG EQU CYREG_GPIO_PRT1_INTR_CFG
I2C_scl__INTSTAT EQU CYREG_GPIO_PRT1_INTR
I2C_scl__MASK EQU 0x20
I2C_scl__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
I2C_scl__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
I2C_scl__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
I2C_scl__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
I2C_scl__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
I2C_scl__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
I2C_scl__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
I2C_scl__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
I2C_scl__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
I2C_scl__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
I2C_scl__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
I2C_scl__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
I2C_scl__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
I2C_scl__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
I2C_scl__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
I2C_scl__PC EQU CYREG_GPIO_PRT1_PC
I2C_scl__PC2 EQU CYREG_GPIO_PRT1_PC2
I2C_scl__PORT EQU 1
I2C_scl__PS EQU CYREG_GPIO_PRT1_PS
I2C_scl__SHIFT EQU 5
I2C_sda__0__DR EQU CYREG_GPIO_PRT1_DR
I2C_sda__0__DR_CLR EQU CYREG_GPIO_PRT1_DR_CLR
I2C_sda__0__DR_INV EQU CYREG_GPIO_PRT1_DR_INV
I2C_sda__0__DR_SET EQU CYREG_GPIO_PRT1_DR_SET
I2C_sda__0__HSIOM EQU CYREG_HSIOM_PORT_SEL1
I2C_sda__0__HSIOM_GPIO EQU 0
I2C_sda__0__HSIOM_I2C EQU 14
I2C_sda__0__HSIOM_I2C_SDA EQU 14
I2C_sda__0__HSIOM_MASK EQU 0x000F0000
I2C_sda__0__HSIOM_SHIFT EQU 16
I2C_sda__0__HSIOM_SPI EQU 15
I2C_sda__0__HSIOM_SPI_MOSI EQU 15
I2C_sda__0__HSIOM_UART EQU 9
I2C_sda__0__HSIOM_UART_RX EQU 9
I2C_sda__0__INTCFG EQU CYREG_GPIO_PRT1_INTR_CFG
I2C_sda__0__INTR EQU CYREG_GPIO_PRT1_INTR
I2C_sda__0__INTR_CFG EQU CYREG_GPIO_PRT1_INTR_CFG
I2C_sda__0__INTSTAT EQU CYREG_GPIO_PRT1_INTR
I2C_sda__0__MASK EQU 0x10
I2C_sda__0__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
I2C_sda__0__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
I2C_sda__0__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
I2C_sda__0__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
I2C_sda__0__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
I2C_sda__0__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
I2C_sda__0__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
I2C_sda__0__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
I2C_sda__0__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
I2C_sda__0__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
I2C_sda__0__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
I2C_sda__0__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
I2C_sda__0__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
I2C_sda__0__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
I2C_sda__0__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
I2C_sda__0__PC EQU CYREG_GPIO_PRT1_PC
I2C_sda__0__PC2 EQU CYREG_GPIO_PRT1_PC2
I2C_sda__0__PORT EQU 1
I2C_sda__0__PS EQU CYREG_GPIO_PRT1_PS
I2C_sda__0__SHIFT EQU 4
I2C_sda__DR EQU CYREG_GPIO_PRT1_DR
I2C_sda__DR_CLR EQU CYREG_GPIO_PRT1_DR_CLR
I2C_sda__DR_INV EQU CYREG_GPIO_PRT1_DR_INV
I2C_sda__DR_SET EQU CYREG_GPIO_PRT1_DR_SET
I2C_sda__INTCFG EQU CYREG_GPIO_PRT1_INTR_CFG
I2C_sda__INTR EQU CYREG_GPIO_PRT1_INTR
I2C_sda__INTR_CFG EQU CYREG_GPIO_PRT1_INTR_CFG
I2C_sda__INTSTAT EQU CYREG_GPIO_PRT1_INTR
I2C_sda__MASK EQU 0x10
I2C_sda__PA__CFG0 EQU CYREG_UDB_PA1_CFG0
I2C_sda__PA__CFG1 EQU CYREG_UDB_PA1_CFG1
I2C_sda__PA__CFG10 EQU CYREG_UDB_PA1_CFG10
I2C_sda__PA__CFG11 EQU CYREG_UDB_PA1_CFG11
I2C_sda__PA__CFG12 EQU CYREG_UDB_PA1_CFG12
I2C_sda__PA__CFG13 EQU CYREG_UDB_PA1_CFG13
I2C_sda__PA__CFG14 EQU CYREG_UDB_PA1_CFG14
I2C_sda__PA__CFG2 EQU CYREG_UDB_PA1_CFG2
I2C_sda__PA__CFG3 EQU CYREG_UDB_PA1_CFG3
I2C_sda__PA__CFG4 EQU CYREG_UDB_PA1_CFG4
I2C_sda__PA__CFG5 EQU CYREG_UDB_PA1_CFG5
I2C_sda__PA__CFG6 EQU CYREG_UDB_PA1_CFG6
I2C_sda__PA__CFG7 EQU CYREG_UDB_PA1_CFG7
I2C_sda__PA__CFG8 EQU CYREG_UDB_PA1_CFG8
I2C_sda__PA__CFG9 EQU CYREG_UDB_PA1_CFG9
I2C_sda__PC EQU CYREG_GPIO_PRT1_PC
I2C_sda__PC2 EQU CYREG_GPIO_PRT1_PC2
I2C_sda__PORT EQU 1
I2C_sda__PS EQU CYREG_GPIO_PRT1_PS
I2C_sda__SHIFT EQU 4

; LED1
LED1__0__DR EQU CYREG_GPIO_PRT3_DR
LED1__0__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
LED1__0__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
LED1__0__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
LED1__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
LED1__0__HSIOM_MASK EQU 0x000F0000
LED1__0__HSIOM_SHIFT EQU 16
LED1__0__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
LED1__0__INTR EQU CYREG_GPIO_PRT3_INTR
LED1__0__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
LED1__0__INTSTAT EQU CYREG_GPIO_PRT3_INTR
LED1__0__MASK EQU 0x10
LED1__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
LED1__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
LED1__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
LED1__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
LED1__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
LED1__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
LED1__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
LED1__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
LED1__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
LED1__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
LED1__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
LED1__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
LED1__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
LED1__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
LED1__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
LED1__0__PC EQU CYREG_GPIO_PRT3_PC
LED1__0__PC2 EQU CYREG_GPIO_PRT3_PC2
LED1__0__PORT EQU 3
LED1__0__PS EQU CYREG_GPIO_PRT3_PS
LED1__0__SHIFT EQU 4
LED1__DR EQU CYREG_GPIO_PRT3_DR
LED1__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
LED1__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
LED1__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
LED1__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
LED1__INTR EQU CYREG_GPIO_PRT3_INTR
LED1__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
LED1__INTSTAT EQU CYREG_GPIO_PRT3_INTR
LED1__MASK EQU 0x10
LED1__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
LED1__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
LED1__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
LED1__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
LED1__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
LED1__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
LED1__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
LED1__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
LED1__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
LED1__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
LED1__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
LED1__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
LED1__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
LED1__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
LED1__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
LED1__PC EQU CYREG_GPIO_PRT3_PC
LED1__PC2 EQU CYREG_GPIO_PRT3_PC2
LED1__PORT EQU 3
LED1__PS EQU CYREG_GPIO_PRT3_PS
LED1__SHIFT EQU 4

; PIN1
PIN1__0__DR EQU CYREG_GPIO_PRT4_DR
PIN1__0__DR_CLR EQU CYREG_GPIO_PRT4_DR_CLR
PIN1__0__DR_INV EQU CYREG_GPIO_PRT4_DR_INV
PIN1__0__DR_SET EQU CYREG_GPIO_PRT4_DR_SET
PIN1__0__HSIOM EQU CYREG_HSIOM_PORT_SEL4
PIN1__0__HSIOM_MASK EQU 0x000000F0
PIN1__0__HSIOM_SHIFT EQU 4
PIN1__0__INTCFG EQU CYREG_GPIO_PRT4_INTR_CFG
PIN1__0__INTR EQU CYREG_GPIO_PRT4_INTR
PIN1__0__INTR_CFG EQU CYREG_GPIO_PRT4_INTR_CFG
PIN1__0__INTSTAT EQU CYREG_GPIO_PRT4_INTR
PIN1__0__MASK EQU 0x02
PIN1__0__PC EQU CYREG_GPIO_PRT4_PC
PIN1__0__PC2 EQU CYREG_GPIO_PRT4_PC2
PIN1__0__PORT EQU 4
PIN1__0__PS EQU CYREG_GPIO_PRT4_PS
PIN1__0__SHIFT EQU 1
PIN1__DR EQU CYREG_GPIO_PRT4_DR
PIN1__DR_CLR EQU CYREG_GPIO_PRT4_DR_CLR
PIN1__DR_INV EQU CYREG_GPIO_PRT4_DR_INV
PIN1__DR_SET EQU CYREG_GPIO_PRT4_DR_SET
PIN1__INTCFG EQU CYREG_GPIO_PRT4_INTR_CFG
PIN1__INTR EQU CYREG_GPIO_PRT4_INTR
PIN1__INTR_CFG EQU CYREG_GPIO_PRT4_INTR_CFG
PIN1__INTSTAT EQU CYREG_GPIO_PRT4_INTR
PIN1__MASK EQU 0x02
PIN1__PC EQU CYREG_GPIO_PRT4_PC
PIN1__PC2 EQU CYREG_GPIO_PRT4_PC2
PIN1__PORT EQU 4
PIN1__PS EQU CYREG_GPIO_PRT4_PS
PIN1__SHIFT EQU 1
PIN1__SNAP EQU CYREG_GPIO_PRT4_INTR
PIN1_ISR__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
PIN1_ISR__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
PIN1_ISR__INTC_MASK EQU 0x10
PIN1_ISR__INTC_NUMBER EQU 4
PIN1_ISR__INTC_PRIOR_MASK EQU 0xC0
PIN1_ISR__INTC_PRIOR_NUM EQU 3
PIN1_ISR__INTC_PRIOR_REG EQU CYREG_CM0_IPR1
PIN1_ISR__INTC_SET_EN_REG EQU CYREG_CM0_ISER
PIN1_ISR__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; Miscellaneous
CYDEV_BCLK__HFCLK__HZ EQU 8000000
CYDEV_BCLK__HFCLK__KHZ EQU 8000
CYDEV_BCLK__HFCLK__MHZ EQU 8
CYDEV_BCLK__SYSCLK__HZ EQU 8000000
CYDEV_BCLK__SYSCLK__KHZ EQU 8000
CYDEV_BCLK__SYSCLK__MHZ EQU 8
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 18
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x0E50119E
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 18
CYDEV_CHIP_MEMBER_4D EQU 13
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 19
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 17
CYDEV_CHIP_MEMBER_4I EQU 23
CYDEV_CHIP_MEMBER_4J EQU 14
CYDEV_CHIP_MEMBER_4K EQU 15
CYDEV_CHIP_MEMBER_4L EQU 22
CYDEV_CHIP_MEMBER_4M EQU 21
CYDEV_CHIP_MEMBER_4N EQU 10
CYDEV_CHIP_MEMBER_4O EQU 7
CYDEV_CHIP_MEMBER_4P EQU 20
CYDEV_CHIP_MEMBER_4Q EQU 12
CYDEV_CHIP_MEMBER_4R EQU 8
CYDEV_CHIP_MEMBER_4S EQU 11
CYDEV_CHIP_MEMBER_4T EQU 9
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 16
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 24
CYDEV_CHIP_MEMBER_FM3 EQU 28
CYDEV_CHIP_MEMBER_FM4 EQU 29
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 25
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 26
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 27
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4F
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4F_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_Disallowed
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 10
CYDEV_DFT_SELECT_CLK1 EQU 11
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_IMO_TRIMMED_BY_USB EQU 0
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDD_MV EQU 3300
CYDEV_VDDR_MV EQU 3300
CYDEV_WDT_GENERATE_ISR EQU 1
CYIPBLOCK_m0s8bless_VERSION EQU 1
CYIPBLOCK_m0s8cpussv2_VERSION EQU 1
CYIPBLOCK_m0s8csd_VERSION EQU 1
CYIPBLOCK_m0s8ioss_VERSION EQU 1
CYIPBLOCK_m0s8lcd_VERSION EQU 2
CYIPBLOCK_m0s8peri_VERSION EQU 1
CYIPBLOCK_m0s8scb_VERSION EQU 2
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 2
CYIPBLOCK_m0s8udbif_VERSION EQU 1
CYIPBLOCK_s8pass4al_VERSION EQU 1
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END
