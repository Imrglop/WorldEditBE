#pragma once
#include <sstream>
#include "../String/Text.h"

struct NamespacedID {
public:
	Minecraft::Text _namespace;
	Minecraft::Text _id;
public:
	inline std::string get() {
		return std::string(this->_namespace.getText()) + ":" + std::string(this->_id.getText());
	}
	inline bool is(std::string id) {
		return this->get() == id;
	}
	inline bool operator==(std::string right) {
		return this->is(right);
	}
};