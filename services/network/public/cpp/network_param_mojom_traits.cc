// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "services/network/public/cpp/network_param_mojom_traits.h"

namespace mojo {

bool StructTraits<network::mojom::HttpVersionDataView, net::HttpVersion>::Read(
    network::mojom::HttpVersionDataView data,
    net::HttpVersion* out) {
  *out = net::HttpVersion(data.major_value(), data.minor_value());
  return true;
}

#if defined(OS_ANDROID)
network::mojom::ApplicationState
EnumTraits<network::mojom::ApplicationState, base::android::ApplicationState>::
    ToMojom(base::android::ApplicationState input) {
  switch (input) {
    case base::android::APPLICATION_STATE_UNKNOWN:
      return network::mojom::ApplicationState::UNKNOWN;
    case base::android::APPLICATION_STATE_HAS_RUNNING_ACTIVITIES:
      return network::mojom::ApplicationState::HAS_RUNNING_ACTIVITIES;
    case base::android::APPLICATION_STATE_HAS_PAUSED_ACTIVITIES:
      return network::mojom::ApplicationState::HAS_PAUSED_ACTIVITIES;
    case base::android::APPLICATION_STATE_HAS_STOPPED_ACTIVITIES:
      return network::mojom::ApplicationState::HAS_STOPPED_ACTIVITIES;
    case base::android::APPLICATION_STATE_HAS_DESTROYED_ACTIVITIES:
      return network::mojom::ApplicationState::HAS_DESTROYED_ACTIVITIES;
  }
  NOTREACHED();
  return static_cast<network::mojom::ApplicationState>(input);
}

bool EnumTraits<network::mojom::ApplicationState,
                base::android::ApplicationState>::
    FromMojom(network::mojom::ApplicationState input,
              base::android::ApplicationState* output) {
  switch (input) {
    case network::mojom::ApplicationState::UNKNOWN:
      *output = base::android::ApplicationState::APPLICATION_STATE_UNKNOWN;
      return true;
    case network::mojom::ApplicationState::HAS_RUNNING_ACTIVITIES:
      *output = base::android::ApplicationState::
          APPLICATION_STATE_HAS_RUNNING_ACTIVITIES;
      return true;
    case network::mojom::ApplicationState::HAS_PAUSED_ACTIVITIES:
      *output = base::android::ApplicationState::
          APPLICATION_STATE_HAS_PAUSED_ACTIVITIES;
      return true;
    case network::mojom::ApplicationState::HAS_STOPPED_ACTIVITIES:
      *output = base::android::ApplicationState::
          APPLICATION_STATE_HAS_STOPPED_ACTIVITIES;
      return true;
    case network::mojom::ApplicationState::HAS_DESTROYED_ACTIVITIES:
      *output = base::android::ApplicationState::
          APPLICATION_STATE_HAS_DESTROYED_ACTIVITIES;
      return true;
  }
  return false;
}
#endif

network::mojom::MemoryPressureLevel
EnumTraits<network::mojom::MemoryPressureLevel,
           base::MemoryPressureListener::MemoryPressureLevel>::
    ToMojom(base::MemoryPressureListener::MemoryPressureLevel input) {
  switch (input) {
    case base::MemoryPressureListener::MEMORY_PRESSURE_LEVEL_NONE:
      return network::mojom::MemoryPressureLevel::NONE;
    case base::MemoryPressureListener::MEMORY_PRESSURE_LEVEL_MODERATE:
      return network::mojom::MemoryPressureLevel::MODERATE;
    case base::MemoryPressureListener::MEMORY_PRESSURE_LEVEL_CRITICAL:
      return network::mojom::MemoryPressureLevel::CRITICAL;
  }
  NOTREACHED();
  return static_cast<network::mojom::MemoryPressureLevel>(input);
}

bool EnumTraits<network::mojom::MemoryPressureLevel,
                base::MemoryPressureListener::MemoryPressureLevel>::
    FromMojom(network::mojom::MemoryPressureLevel input,
              base::MemoryPressureListener::MemoryPressureLevel* output) {
  switch (input) {
    case network::mojom::MemoryPressureLevel::NONE:
      *output = base::MemoryPressureListener::MemoryPressureLevel::
          MEMORY_PRESSURE_LEVEL_NONE;
      return true;
    case network::mojom::MemoryPressureLevel::MODERATE:
      *output = base::MemoryPressureListener::MemoryPressureLevel::
          MEMORY_PRESSURE_LEVEL_MODERATE;
      return true;
    case network::mojom::MemoryPressureLevel::CRITICAL:
      *output = base::MemoryPressureListener::MemoryPressureLevel::
          MEMORY_PRESSURE_LEVEL_CRITICAL;
      return true;
  }
  return false;
}

}  // namespace mojo
