// main.cpp — entry point. Wires config and subsystems together.

#include "codexclirotator/settings.h"
#include "codexclirotator/wrapper.h"
#include "codexclirotator/rotator.h"
#include "codexclirotator/keychain.h"
#include <csignal>
#include <memory>

namespace { std::atomic<bool> g_running{true}; void on_signal(int) { g_running.store(false); } }

int main(int argc, char** argv) {
    std::signal(SIGINT, on_signal);
    std::signal(SIGTERM, on_signal);

    codexclirotator::Settings settings = codexclirotator::Settings::load_default();
    codexclirotator::Wrapper wrapper(settings.store_path);
    codexclirotator::Rotator rotator(settings.store_path);
    codexclirotator::Keychain keychain(settings.store_path);
    std::fprintf(stderr, "[codex-cli-rotator] ready\n");

    while (g_running.load()) {
        // main loop: pump subsystems
        break;
    }
    return 0;
}
