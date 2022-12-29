#pragma once

#include <functional>

namespace TG
{
    namespace Scope
    {
        using std::function;

        class OnFailure final
        {
        private:
            function<void()> cleanup{};

        public:
            OnFailure() = default;

            OnFailure(function<void()> const& cleanup_)
                : cleanup(cleanup_)
            {}
            OnFailure(function<void()>&& cleanup_) noexcept
                : cleanup(move(cleanup_))
            {}

            OnFailure(OnFailure const&) = delete;
            OnFailure(OnFailure&& other) noexcept
                : cleanup(move(other.cleanup))
            {
                other.dismiss();
            }

            ~OnFailure() noexcept
            {
                if (cleanup)
                    cleanup();
            }

            void operator = (OnFailure const&) = delete;
            void operator = (OnFailure&& other) noexcept
            {
                if (cleanup)
                    cleanup();

                cleanup = move(other.cleanup);
                other.dismiss();
            }

            void dismiss() noexcept
            {
                cleanup = function<void()>();
            }
        };

        class Finally final
        {
        private:
            function<void()> cleanup{};

        public:
            Finally() = default;

            Finally(function<void()> const& cleanup_)
                : cleanup(cleanup_)
            {}
            Finally(function<void()>&& cleanup_) noexcept
                : cleanup(move(cleanup_))
            {}

            Finally(Finally const&) = delete;
            Finally(Finally&& other) noexcept
                : cleanup(move(other.cleanup))
            {
                other.cleanup = function<void()>();
            }

            ~Finally() noexcept
            {
                if (cleanup)
                    cleanup();
            }

            void operator = (Finally const&) = delete;
            void operator = (Finally&& other) noexcept
            {
                if (cleanup)
                    cleanup();

                cleanup = move(other.cleanup);
                other.cleanup = function<void()>();
            }
        };
    } // namespace Scope
} // namespace TG