#include "miniredis/database.hpp"

namespace miniredis {
	void KeyValueStore::set(
		const std::string& key,
		const std::string& value
		) {
		data_[key] = value;
	}

	std::optional<std::string> KeyValueStore::get(
		const std::string& key) const {
		auto it = data_.find(key);
		if (it == data_.end()) return std::nullopt;
		return it->second;
	}

	bool KeyValueStore::remove(const std::string& key) {
		return data_.erase(key) > 0;
	}

	bool KeyValueStore::exists(const std::string& key) const {
		return data_.contains(key);
	}

	std::size_t KeyValueStore::size() const noexcept {
		return data_.size();
	}

	void KeyValueStore::clear() noexcept {
		data_.clear();
	}
} //namespace miniredis