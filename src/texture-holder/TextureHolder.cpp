#include "TextureHolder.h"

#include <iostream>

TextureHolder* TextureHolder::_instance = nullptr;

TextureHolder::TextureHolder() {
    if (_instance != nullptr) {
        std::cerr << "Object of TextureHolder already created but it is a singleton class\n";
        exit(1);
    }

    _instance = this;
}

sf::Texture & TextureHolder::GetTexture(const std::string &filename) {
    if (_instance == nullptr) {
        std::cerr << "TextureHolder instance not created\n";
        exit(1);
    }

    std::map<std::string, sf::Texture> &texture_map = _instance->_textures;

    auto key_value_pair = texture_map.find(filename);

    if (key_value_pair != texture_map.end()) {
        return key_value_pair->second;
    }
    else {
        auto &texture = texture_map[filename];

        if (!texture.loadFromFile(filename)) {
            std::cerr << "Texture file not found\n";
            exit(1);
        }

        return texture;
    }
}