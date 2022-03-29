#pragma once

#include <SFML/Graphics.hpp>
#include <map>

// Singleton class that stores references of textures.
class TextureHolder {

private:

    std::map<std::string, sf::Texture> _textures;

    static TextureHolder* _instance;

public:

    TextureHolder();

    static sf::Texture & GetTexture(const std::string &filename);

};