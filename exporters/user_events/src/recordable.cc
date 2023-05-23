/// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#include "opentelemetry/exporters/user_events/logs/recordable.h"

#include <chrono>
#include <map>

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter {
namespace user_events {
namespace logs {

namespace api_logs = opentelemetry::logs;

void Recordable::SetSeverity(api_logs::Severity severity) noexcept {
}

void Recordable::SetBody(const opentelemetry::common::AttributeValue &message) noexcept {
}

void Recordable::SetEventId(int64_t id, nostd::string_view name) noexcept {
}

void Recordable::SetTraceId(const opentelemetry::trace::TraceId &trace_id) noexcept {
}

void Recordable::SetSpanId(const opentelemetry::trace::SpanId &span_id) noexcept {
}

void Recordable::SetAttribute(
    nostd::string_view key,
    const opentelemetry::common::AttributeValue &value) noexcept {
}

void Recordable::SetTimestamp(
    opentelemetry::common::SystemTimestamp timestamp) noexcept {
  // fluentd_common::get_msgpack_eventtimeext(
  //     static_cast<int32_t>(std::chrono::duration_cast<std::chrono::seconds>(
  //                              timestamp.time_since_epoch())
  //                              .count()),
  //     std::chrono::duration_cast<std::chrono::nanoseconds>(
  //         timestamp.time_since_epoch())
  //             .count() %
  //         1000000000);
}

} // namespace logs
} // namespace user_events
} // namespace exporter
OPENTELEMETRY_END_NAMESPACE
