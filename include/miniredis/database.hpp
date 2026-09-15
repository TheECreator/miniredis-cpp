#pragma once

#include <cstddef>
#include <optional>
#include <string>
#include <unordered_map>

namespace miniredis {
	class KeyValueStore {
	public:
		void set(const std::string& key, const std::string& value);

		[[nodiscard]]
		std::optional<std::string> get(const std::string& key) const;

		bool remove(const std::string& key);

		[[nodiscard]]
		bool exists(const std::string& key) const;

		[[nodiscard]]
		std::size_t size() const noexcept;

		void clear() noexcept;

	private:
		std::unordered_map<std::string, std::string> data_;
	};
} //namespace miniredis