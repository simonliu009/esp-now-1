// Copyright 2021 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#ifdef __cplusplus
extern "C" {
#endif /**< _cplusplus */

/**
 * @brief  Register log command.
 */
void register_log();

/**
 * @brief  Register coredump command.
 */
void register_coredump();

/**
 * @brief  Register `command` command.
 */
void register_command();

/**
 * @brief  Register wifi config command.
 */
void register_wifi_config();

/**
 * @brief  Register wifi scan command.
 */
void register_wifi_scan();

/**
 * @brief  Register wifi sniffer command.
 */
void register_wifi_sniffer();

/**
 * @brief  Register sdcard command.
 */
void register_sdcard();

void register_scan();

void register_provisioning();
void register_control();
void register_ota();


void register_espnow_config();
void register_espnow_iperf();

/* register command `ping` */
void register_wifi_ping();

#ifdef __cplusplus
}
#endif /**< _cplusplus */
