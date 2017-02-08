#
# Copyright 2013 The Android Open-Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Inherit AOSP device configuration for mako
$(call inherit-product, device/samsung/manta/full_manta.mk)
# Inherit from tuna device
$(call inherit-product, device/samsung/manta/device.mk)

# Inherit from our custom product configuration
$(call inherit-product, vendor/du/config/common_full_phone.mk)
#$(call inherit-product, vendor/du/config/nfc_enhanced.mk)

# Set those variables here to overwrite the inherited values.
PRODUCT_NAME         := du_manta
PRODUCT_DEVICE       := manta
PRODUCT_BRAND        := Google
PRODUCT_MODEL        := Nexus 10
PRODUCT_MANUFACTURER := Samsung

# Build prop fingerprint overrides
PRODUCT_BUILD_PROP_OVERRIDES += \
PRODUCT_NAME="mantaray" \
BUILD_FINGERPRINT="google/mantaray/manta:7.1.1/N4F26Q/3623443:user/release-keys"  \
PRIVATE_BUILD_DESC="mantaray-user 7.1.1 N4F26Q 3623443 release-keys"


