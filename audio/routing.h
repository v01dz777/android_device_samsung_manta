/*
 * Copyright (C) 2013 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _ROUTING_H_
#define _ROUTING_H_

#include <eS305VoiceProcessing.h>

enum {
    OUT_DEVICE_SPEAKER,
    OUT_DEVICE_HEADSET,
    OUT_DEVICE_HEADPHONES,
    OUT_DEVICE_BT_SCO,
    OUT_DEVICE_SPEAKER_AND_HEADSET,
    OUT_DEVICE_TAB_SIZE,           /* number of rows in route_configs[][] */
    OUT_DEVICE_NONE,
    OUT_DEVICE_CNT
};

enum {
    IN_SOURCE_MIC,
    IN_SOURCE_CAMCORDER,
    IN_SOURCE_VOICE_RECOGNITION,
    IN_SOURCE_VOICE_COMMUNICATION,
    IN_SOURCE_TAB_SIZE,            /* number of lines in route_configs[][] */
    IN_SOURCE_NONE,
    IN_SOURCE_CNT
};

enum {
    ES305_MODE_DEFAULT,
    ES305_MODE_LEVEL,
    ES305_NUM_MODES,
};

struct route_config {
    const char * const output_route;
    const char * const input_route;
    int es305_preset[ES305_NUM_MODES]; // es305 preset for this route.
                                       // -1 means es305 bypass
};

const struct route_config media_speaker = {
    "media-speaker",
    "media-main-mic",
    { ES305_PRESET_OFF,
      ES305_PRESET_OFF }
};

const struct route_config media_headphones = {
    "media-headphones",
    "media-main-mic",
    { ES305_PRESET_OFF,
      ES305_PRESET_OFF }
};

const struct route_config media_headset = {
    "media-headphones",
    "media-headset-mic",
    { ES305_PRESET_OFF,
      ES305_PRESET_OFF }
};

const struct route_config camcorder_speaker = {
    "media-speaker",
    "media-second-mic",
    { ES305_PRESET_CAMCORDER,
      ES305_PRESET_CAMCORDER }
};

const struct route_config camcorder_headphones = {
    "media-headphones",
    "media-second-mic",
    { ES305_PRESET_CAMCORDER,
      ES305_PRESET_CAMCORDER }
};

const struct route_config voice_rec_speaker = {
    "voice-rec-speaker",
    "voice-rec-main-mic",
    { ES305_PRESET_ASRA_HANDHELD,
      ES305_PRESET_ASRA_DESKTOP }
};

const struct route_config voice_rec_headphones = {
    "voice-rec-headphones",
    "voice-rec-main-mic",
    { ES305_PRESET_ASRA_HANDHELD,
      ES305_PRESET_ASRA_DESKTOP }
};

const struct route_config voice_rec_headset = {
    "voice-rec-headphones",
    "voice-rec-headset-mic",
    { ES305_PRESET_ASRA_HEADSET,
      ES305_PRESET_ASRA_HEADSET }
};

const struct route_config communication_speaker = {
    "communication-speaker",
    "communication-main-mic",
    { ES305_PRESET_VOIP_HANDHELD,
      ES305_PRESET_VOIP_DESKTOP }
};

const struct route_config communication_headphones = {
    "communication-headphones",
    "communication-main-mic",
    { ES305_PRESET_VOIP_HEADPHONES,
      ES305_PRESET_VOIP_HP_DESKTOP}
};

const struct route_config communication_headset = {
    "communication-headphones",
    "communication-headset-mic",
    { ES305_PRESET_VOIP_HEADSET,
      ES305_PRESET_VOIP_HEADSET }
};

const struct route_config speaker_and_headphones = {
    "speaker-and-headphones",
    "main-mic",
    { ES305_PRESET_CURRENT,
      ES305_PRESET_CURRENT }
};

const struct route_config bluetooth_sco = {
    "bt-sco-headset",
    "bt-sco-mic",
    { ES305_PRESET_OFF,
      ES305_PRESET_OFF }
};

const struct route_config * const route_configs[IN_SOURCE_TAB_SIZE]
                                               [OUT_DEVICE_TAB_SIZE] = {
    {   /* IN_SOURCE_MIC */
        &media_speaker,             /* OUT_DEVICE_SPEAKER */
        &media_headset,             /* OUT_DEVICE_HEADSET */
        &media_headphones,          /* OUT_DEVICE_HEADPHONES */
        &bluetooth_sco,             /* OUT_DEVICE_BT_SCO */
        &speaker_and_headphones     /* OUT_DEVICE_SPEAKER_AND_HEADSET */
    },
    {   /* IN_SOURCE_CAMCORDER */
        &camcorder_speaker,         /* OUT_DEVICE_SPEAKER */
        &camcorder_headphones,      /* OUT_DEVICE_HEADSET */
        &camcorder_headphones,      /* OUT_DEVICE_HEADPHONES */
        &bluetooth_sco,             /* OUT_DEVICE_BT_SCO */
        &speaker_and_headphones     /* OUT_DEVICE_SPEAKER_AND_HEADSET */
    },
    {   /* IN_SOURCE_VOICE_RECOGNITION */
        &voice_rec_speaker,         /* OUT_DEVICE_SPEAKER */
        &voice_rec_headset,         /* OUT_DEVICE_HEADSET */
        &voice_rec_headphones,      /* OUT_DEVICE_HEADPHONES */
        &bluetooth_sco,             /* OUT_DEVICE_BT_SCO */
        &speaker_and_headphones     /* OUT_DEVICE_SPEAKER_AND_HEADSET */
    },
    {   /* IN_SOURCE_VOICE_COMMUNICATION */
        &communication_speaker,     /* OUT_DEVICE_SPEAKER */
        &communication_headset,     /* OUT_DEVICE_HEADSET */
        &communication_headphones,  /* OUT_DEVICE_HEADPHONES */
        &bluetooth_sco,             /* OUT_DEVICE_BT_SCO */
        &speaker_and_headphones     /* OUT_DEVICE_SPEAKER_AND_HEADSET */
    }
};

#endif
