// Copyright (c) 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_THIRD_PARTY_QUIC_CORE_FRAMES_QUIC_PATH_RESPONSE_FRAME_H_
#define NET_THIRD_PARTY_QUIC_CORE_FRAMES_QUIC_PATH_RESPONSE_FRAME_H_

#include <memory>
#include <ostream>

#include "net/third_party/quic/core/quic_types.h"

namespace quic {

// Size of the entire IETF Quic Path Response frame.
const size_t kQuicPathResponseFrameSize = kQuicPathFrameBufferSize;

struct QUIC_EXPORT_PRIVATE QuicPathResponseFrame {
  QuicPathResponseFrame();
  QuicPathResponseFrame(QuicControlFrameId control_frame_id,
                        const QuicPathFrameBuffer& data_buff);
  ~QuicPathResponseFrame();

  friend QUIC_EXPORT_PRIVATE std::ostream& operator<<(
      std::ostream& os,
      const QuicPathResponseFrame& frame);

  // A unique identifier of this control frame. 0 when this frame is received,
  // and non-zero when sent.
  QuicControlFrameId control_frame_id;

  QuicPathFrameBuffer data_buffer;
};
}  // namespace quic

#endif  // NET_THIRD_PARTY_QUIC_CORE_FRAMES_QUIC_PATH_RESPONSE_FRAME_H_
