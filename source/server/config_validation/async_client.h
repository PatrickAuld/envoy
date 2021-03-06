#pragma once

#include <chrono>

#include "envoy/http/async_client.h"
#include "envoy/http/message.h"

#include "common/common/assert.h"

namespace Envoy {
namespace Http {

/**
 * Config-validation-only implementation of AsyncClient. Both methods on AsyncClient are allowed to
 * return nullptr if the request can't be created, so that's what the ValidationAsyncClient does in
 * all cases.
 */
class ValidationAsyncClient : public AsyncClient {
public:
  // Http::AsyncClient
  AsyncClient::Request* send(MessagePtr&& request, Callbacks& callbacks,
                             const Optional<std::chrono::milliseconds>& timeout) override;
  AsyncClient::Stream* start(StreamCallbacks& callbacks,
                             const Optional<std::chrono::milliseconds>& timeout,
                             bool buffer_body_for_retry) override;
  Event::Dispatcher& dispatcher() override { NOT_IMPLEMENTED; }
};

} // namespace Http
} // namespace Envoy
