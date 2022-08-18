#include "image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Image::Image(std::filesystem::path p) : width(0), height(0), nrChannels(0) {
    //auto path = (std::filesystem::current_path() / p);
    auto str = p.string();
    const char *c = str.c_str();
    //std::cout << c << "." << std::endl;
    stbi_set_flip_vertically_on_load(true);  
    data = stbi_load(c, &width, &height, &nrChannels, 0);
}

Image::~Image() {
    //std::cout << "Freeing image data" << std::endl;
    stbi_image_free(data);
}

bool Image::hasData() {
    return data;
}

int Image::getHeight() {
    return height;
}

int Image::getWidth() {
    return width;
}

int Image::getNrChannels() {
    return nrChannels;
}