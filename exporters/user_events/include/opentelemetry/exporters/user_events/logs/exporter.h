// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#pragma once

#ifdef ENABLE_LOGS_PREVIEW

#  include "opentelemetry/common/spin_lock_mutex.h"
#  include "opentelemetry/sdk/logs/exporter.h"
#  include "exporter_options.h"

#  include <mutex>
#  include <eventheader/EventHeaderDynamic.h>

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter {
namespace user_events {
namespace logs {

/**
 * The user_events logs exporter exports logs data to Geneva
 */
class Exporter final : public opentelemetry::sdk::logs::LogRecordExporter {
public:
  Exporter(const ExporterOptions &options) noexcept;

  /**
   * Exports a span of logs sent from the processor.
   */
  opentelemetry::sdk::common::ExportResult Export(
      const opentelemetry::nostd::span<std::unique_ptr<sdk::logs::Recordable>> &records) noexcept
      override;

  bool ForceFlush(std::chrono::microseconds timeout =
                      (std::chrono::microseconds::max)()) noexcept override;

  bool Shutdown(std::chrono::microseconds timeout =
                    (std::chrono::microseconds::max)()) noexcept override;
  bool isShutdown() const noexcept;


private:
  const ExporterOptions options_;
  bool is_shutdown_ = false;
  mutable opentelemetry::common::SpinLockMutex lock_;

  ehd::Provider provider_{"opentelemetry-logs"};
  std::shared_ptr<const ehd::EventSet> event_set_ = provider_.RegisterSet(event_level_verbose, 1);
};

} // namespace logs
} // namespace userevents
} // namespace exporter
OPENTELEMETRY_END_NAMESPACE

#endif